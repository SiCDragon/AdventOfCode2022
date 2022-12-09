#include "Day9.h"

enum Dir {
    right = 'R',
    left = 'L',
    up = 'U',
    down = 'D'
};

class Rope
{
private:
    std::map< std::pair<int, int>, int > positions;
    std::map< std::pair<int, int>, int > tailPositions;
    std::pair<int, int> currentHeadPosition;
    std::pair<int, int> currentTailPosition;
    int totalPositions;
    int totalTailPositions;
    int x, y;
    bool isTailTooFarFromHead;

public:
    Rope()
    {
        x = 0;
        y = 0;
        currentHeadPosition = { x,y };
        currentTailPosition = { x,y };
        totalPositions = 0;
        totalTailPositions = 0;
        positions.insert({ currentHeadPosition, totalPositions++ });
        tailPositions.insert({ currentTailPosition, totalTailPositions++ });
    }

    void setcurrentPosition(int x, int y) { currentHeadPosition = { x,y };; }
    std::pair<int, int> getHeadPosition() { return currentHeadPosition; }
    std::pair<int, int> getTailPosition() { return currentTailPosition; }

    int getTotalPositions() { return totalPositions; }
    int getTotalTailPositions() { return tailPositions.size();}

    int getUniquePositions() { return positions.size(); }

    void move(char direction, int count)
    {
        int i = count;
        while (i > 0) 
        {
            switch (direction)
            {
                case right:
                    x++;
                    positions.insert({ {x, y}, totalPositions++ });
                    if ( ( abs(x - currentTailPosition.first) >= 2 ) || abs(y - currentTailPosition.second) >= 2 )
                    {
                        tailPositions.insert({ currentHeadPosition, totalTailPositions++ });
                        currentTailPosition = currentHeadPosition;
                    }
                    currentHeadPosition = { x, y };
                    break;
                case left:
                    x--;
                    positions.insert({ {x, y}, totalPositions++ });
                    if ( ( abs(x - currentTailPosition.first) >= 2 ) || abs(y - currentTailPosition.second) >= 2 )
                    {
                        tailPositions.insert({ currentHeadPosition, totalTailPositions++ });
                        currentTailPosition = currentHeadPosition;
                    }
                    currentHeadPosition = { x, y };
                    break;
                case up:
                    y++;
                    positions.insert({ {x, y}, totalPositions++ });
                    if ( (abs(x - currentTailPosition.first) >= 2 ) || abs(y - currentTailPosition.second) >= 2 )
                    {
                        tailPositions.insert({ currentHeadPosition, totalTailPositions++ });
                        currentTailPosition = currentHeadPosition;
                    }
                    currentHeadPosition = { x, y };
                    break;
                case down:
                    y--;
                    positions.insert({ {x, y}, totalPositions++ });
                    if ( (abs(x - currentTailPosition.first) >= 2) || abs(y - currentTailPosition.second) >= 2 )
                    {
                        tailPositions.insert({ currentHeadPosition, totalTailPositions++ });
                        currentTailPosition = currentHeadPosition;
                    }
                    currentHeadPosition = { x, y };
                    break;
            }
            i--;
        }
    }
};


void elfTail()
{
    std::ifstream potato{ "Day9/Day9Input.txt" };
    std::string strInput{ "" }, currentPath{ "/" };
    std::string moveDirStr{ "" }, moveAmountStr{ "" };

    int totalBytes{ 0 }, dirLevel{ 0 };
    Rope myRope = Rope();
    int tailMoves{ 0 };

    if (!potato)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }

    while (potato)
    {
        potato >> moveDirStr;
        potato >> moveAmountStr;
        myRope.move(moveDirStr.front(), std::stoi(moveAmountStr));
        std::cout << "(  " << myRope.getHeadPosition().first << "  ,  " << myRope.getHeadPosition().second << " )  ";
        std::cout << "( " << myRope.getTailPosition().first << " ,  " << myRope.getTailPosition().second << " )  " << '\n';
        if (potato.eof()) { break; }
    }
        
    std::cout << "----------------------------------- " << '\n';
    std::cout << " Total moves: " << myRope.getTotalTailPositions() << '\n';
}
    

