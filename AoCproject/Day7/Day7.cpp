#include "Day7.h"

class File
{
private:
    std::string size;
    std::string name;
    std::string pathToFile;

public:
    File() {}
    File(std::string n, std::string s, std::string p)
    {
        name = n;
        size = s;
        pathToFile = p;
    }

    int getSize() { return std::stoi(size); }

    void setName(std::string n) { name = n; }
    std::string getName() { return name; }
    std::string getDirName() { return size; }


    void setPath(std::string p) { pathToFile = p; }
    std::string getPath() { return pathToFile; }
};

class Folder
{
private:
    std::vector <Folder> foldersInDir;
    std::vector <File> filesInDir;
    std::string folderPath;
    std::string dirName;

public:
    Folder() {}
    Folder(std::string name, std::string p)
    {
        dirName = name;
        folderPath = p;
    }
    
    void addFolder( Folder f) { foldersInDir.push_back({ f }); }
    void addFile(File f) { filesInDir.push_back({f }); }
    
    void setDirName(std::string n) { dirName = n; }
    std::string getDirName() { return dirName; }

    std::vector <Folder> getSubDirs() { return foldersInDir; }

    void printFiles() {
        for (auto &const idx : filesInDir) {
            std::cout << " Name " << idx.getName() << " | size: " << idx.getSize() << '\n';
        }
    }

    void printFolders() {
        for (auto& const idx : foldersInDir) {
            std::cout << " Folder:  " << idx.getDirName()  << '\n';
        }
    }

    int getFolderFileSize() {
        int folderSize{ 0 }; 
        for (auto &const idx :  filesInDir) {
            folderSize += idx.getSize();
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
    fileSys.insert({ currentPath, Folder("/", "0")});


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
                        fileSys.insert({ currentPath, Folder(strInput, currentPath) });
                    }
                    
                }
            }
            else if(strInput.compare("ls") == 0)
            {
                //do nothing
            }
        }
        else if (strInput.compare("dir") == 0)
        {
            potato >> strInput;

            if (fileSys.find(currentPath + "/" + strInput) == fileSys.end())
            {
                fileSys.insert({ currentPath + "/" + strInput, Folder(strInput, currentPath + "/" + strInput) });
            }
            fileSys[currentPath].addFolder(Folder(strInput, currentPath + "/" + strInput));
            
        }
        else if (std::isdigit(strInput[0]))
        {
            std::string fileSize = strInput;
            potato >> strInput;
            fileSys[currentPath].addFile(File(strInput, fileSize, currentPath ));
        }

        if (potato.eof()) { break; }
    }
    std::cout << "----------------------------------- " << '\n';
    
    int fileSystemSize{ 70000000 }, spaceNeeded{ 30000000 }, size2Delete{ 0 }, currentUnusedSpace{ 0 };
    std::vector<int> candidates;

    for (auto const& idx1 : fileSys) 
    {
        int folderSize{ 0 };
        for (auto const& idx2 : fileSys) 
        {
            if (idx2.first.find(idx1.first) != std::string::npos)
            {
                folderSize += fileSys[idx2.first].getFolderFileSize();
            }
        }
        //Part 1
        if (folderSize < 100000) { totalBytes += folderSize; }
        
        //Part 2
        if (idx1.first.compare("/") == 0) { currentUnusedSpace = fileSystemSize - folderSize; }
        if (folderSize + currentUnusedSpace > spaceNeeded) 
        {
            candidates.push_back(folderSize); 
        }
    }
    
    size2Delete = *min_element(candidates.begin(), candidates.end());
    std::cout << " Total size of folders less than 100000: " << totalBytes << '\n';
    std::cout << " Total size of folder to delete: " << size2Delete << '\n';
}

