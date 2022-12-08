#include "Day7.h"
//still no answer for this one
class File
{
private:
    int size{};
    std::string name;
    std::string pathToFile;

public:
    File() {}
    File(std::string n, int s, std::string p)
    {
        size = s;
        name = n;
        pathToFile = p;
    }

    void setSize(int s) { size = s; }
    int getSize() { return size; }

    void setName(std::string n) { name = n; }
    std::string getName() { return name; }

    void setPath(std::string p) { pathToFile = p; }
    std::string getPath() { return pathToFile; }
};

class Folder
{
private:
    std::map<int , File> filesInDir;
    std::map<int, std::string> subDirs;
    std::string folderPath;
    std::string dirName;
    int dirSize;
    int dirLevel;
    int fileNum;
    int subDirNum;

public:
    Folder() {}
    Folder(std::string name, int level, std::string pathToFile)
    {
        dirName = name;
        dirLevel = level;
        folderPath = pathToFile;
        fileNum = 0;
        subDirNum = 0;
    }
    
    void addFile(File f) { filesInDir.insert({ fileNum++, f}); }
    void addSubDir(std::string s) { subDirs.insert({ subDirNum++, s }); }
    void setDirName(std::string n) { dirName = n; }
    std::string getDirName() { return dirName; }


    void printFiles() {
        for (auto const& idx : filesInDir) {
            File x = idx.second;
            std::cout << " File num: " << idx.first << '\n';
            std::cout << " Name " << x.getName() << " | size: " << x.getSize() << '\n';
        }
    }

    void printSubDirs() {
        for (auto const& idx : subDirs) {
            std::cout << " sub dirs " << idx.second  << '\n';
        }
    }

    int getFolderSize() {
        int folderSize{ 0 };
        for (auto const& idx : filesInDir) {
            File x = idx.second;
            folderSize += x.getSize();
        }
        return folderSize;
    }

    
};

void elfDir()
{
    std::ifstream potato{ "Day7/Day7Input.txt" };
    std::string strInput{ "" }, currentPath{ "/" };

    int totalBytes{ 0 }, dirLevel{ 0 };

    std::map<std::string, Folder> fileSys;
    fileSys.insert({ currentPath, Folder("/", 0, "0")});


    if (!potato)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }

    while (potato)
    {
        potato >> strInput;
        if (strInput.compare("$") == 0)
        {
            potato >> strInput;
            if (strInput.compare("cd") == 0)
            {
                potato >> strInput;
                if (strInput.compare("/") == 0)
                {
                    dirLevel = 0;
                    currentPath = strInput;
                }
                else if (strInput.compare("..") == 0)
                {
                    dirLevel--;
                    currentPath.erase(currentPath.rfind("/"), (currentPath.length() - currentPath.rfind("/")));

                }
                else
                {
                    dirLevel++;
                    currentPath = currentPath + "/" + strInput;
                    if (fileSys.find(currentPath) == fileSys.end())
                    {
                        fileSys.insert({ currentPath, Folder(strInput, dirLevel, currentPath) });
                    }
                    
                }
            }
            else if(strInput.compare("ls") == 0)
            {
                //do nothing?
            }
        }
        else if (strInput.compare("dir") == 0)
        {
            potato >> strInput;
            if (fileSys.find(currentPath + "/" + strInput) == fileSys.end())
            {
                fileSys.insert({ currentPath + "/" + strInput, Folder(strInput, dirLevel, currentPath + "/" + strInput) });
            }
            fileSys[currentPath].addSubDir(currentPath + "/" + strInput);
        }
        else if (std::isdigit(strInput[0]))
        {
            int fileSize = std::stoi(strInput);
            potato >> strInput;
            fileSys[currentPath].addFile(File(strInput, fileSize, currentPath ));
        }

        if (potato.eof()) { break; }
    }
    std::cout << "----------------------------------- " << '\n';
    for (auto const& idx : fileSys) {
        Folder x = idx.second;
        std::cout << " Folder: " << idx.first << '\n';
        //x.printFiles();
        x.printSubDirs();
        std::cout << " Folder Size: " << x.getFolderSize() << '\n';
        totalBytes += x.getFolderSize();
    }
    std::cout << " Total size: " << totalBytes << '\n';
}

