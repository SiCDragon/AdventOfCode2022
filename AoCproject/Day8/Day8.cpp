#include "Day8.h"

void elfTreeHouse()
{
    std::ifstream potato{ "Day8/Day8Input.txt" };
    std::string strInput{ "" };
    bool  loop1{ false }, loop2{ false }, loop3{ false }, loop4{ false };
    int  lookUp{ 0 }, lookDown{ 0 }, lookLeft{ 0 }, lookRight{ 0 };
    std::vector<std::vector<int>> myInput;
    std::vector<int> treeScore;
    int isVisible{ 0 };
    std::vector<int> temp;
    int totalPairs{ 0 }, count{ 0 };

    if (!potato)
    {
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }
    while (potato)
    {
        std::getline(potato, strInput);
        for (int i = 0; i < strInput.length(); i++)
        {
            temp.push_back( int(strInput[i])-48);
        }
        myInput.push_back(temp);
        temp.clear();
        if (potato.eof()) { break; }
    }

    for (int i = 0; i < myInput[0].size(); i++ )
    {
        for (int j = 0; j < myInput.size(); j++)
        {
            if (i == 0 || i == myInput[0].size() - 1 || j == 0 || j == myInput.size() - 1) 
            {
                isVisible++;

            }
            else
            {
                for (int x = i+1; x < myInput[0].size(); x++) 
                {
                    lookRight++;
                    if (myInput[i][j] <= myInput[x][j]) { break; loop1 = false;}
                    if (x == myInput[0].size() - 1) { loop1 = true; }
                }
                for (int x = i - 1; x >=0 ; x--)
                {
                    lookLeft++;
                    if (myInput[i][j] <= myInput[x][j]) { break; loop2 = false;}
                    if (x == 0) { loop2 = true; }
                }
                for (int y = j + 1; y < myInput.size(); y++)
                {
                    lookDown++;
                    if (myInput[i][j] <= myInput[i][y]) { break; loop3 = false;}
                    if (y == myInput.size()-1) { loop3 = true; }
                }
                for (int y = j - 1; y >= 0; y--)
                {
                    lookUp++;
                    if (myInput[i][j] <= myInput[i][y]) { break; loop4 = false;}
                    if (y == 0) { loop4 = true; }
                }

                if (loop1 || loop2 || loop3 || loop4)
                {
                    isVisible++;
                    loop1 = false;
                    loop2 = false;
                    loop3 = false;
                    loop4 = false;
                }
                treeScore.push_back(lookRight * lookDown * lookLeft * lookUp);
                lookRight = 0; 
                lookDown = 0;
                lookLeft = 0; 
                lookUp = 0;
            }
            //std::cout << "i: " << i << " j: " << j << '\n';
            //std::cout << " value: " << myInput[i][j]  << '\n';
        }

    }
    double maxVal = *std::max_element(treeScore.begin(), treeScore.end());
    std::cout << "Visible Trees: " << isVisible << '\n';
    std::cout << "Tree Score: " << maxVal << '\n';
}
