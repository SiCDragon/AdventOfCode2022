#include "Day5.h"

void elfCranes()
{
    std::ifstream potato{ "Day5/Day5Input.txt" };
    std::ifstream tomato{ "Day5/Day5InputStacks.txt" };
    std::string strInput{ "" }, letterInput{ "" }, topOfStacks{ "" };
    std::string topOfStacks2{ "" }, stackToMove{ "" }, tempLetter{ "" };

    std::map<int,  std::deque<std::string> > myStacks;
    std::map<int, std::string > myStacks2;
    int totalPairs{ 0 }, totalOverlap{ 0 }, idx{ 1 };

    struct {
        int moves{ 0 };
        int initStack{ 0 };
        int endStack{ 0 };
    }stackMoves;
    
    if (!tomato)
    {
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }
    while (tomato)
    {
        tomato >> strInput;
        if (strInput != "[0]") 
        {
            letterInput = strInput.substr(strInput.find("[") + 1, strInput.find("]")-1);
            myStacks[idx].push_back(letterInput);
            myStacks2[idx] = letterInput + myStacks2[idx];
        }
        
        idx++;
        if (idx > 9) { idx = 1; }
        if (tomato.eof()) { break; }
    }

    if (!potato)
    {
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }
    while (potato)
    {
        std::getline(potato, strInput);
        stackMoves.moves = std::stoi(strInput.substr(strInput.find("move")+4, strInput.find("from")));
        stackMoves.initStack = std::stoi(strInput.substr(strInput.find("from")+4, strInput.find("to")));
        stackMoves.endStack = std::stoi(strInput.substr(strInput.find("to")+2));

        for(int i = 0; i<stackMoves.moves; i++)
        {
            if (!myStacks[stackMoves.initStack].empty())
            {
                // Part 1
                myStacks[stackMoves.endStack].push_front(myStacks[stackMoves.initStack].front());
                myStacks[stackMoves.initStack].pop_front();
            }
        }

        //Part 2
        stackToMove.clear();
        stackToMove.append(myStacks2[stackMoves.initStack].substr(myStacks2[stackMoves.initStack].length()-stackMoves.moves));

        myStacks2[stackMoves.endStack].append(stackToMove);
        myStacks2[stackMoves.initStack].erase(myStacks2[stackMoves.initStack].length() - stackMoves.moves, stackToMove.length());

        if (potato.eof()) { break; }
    }

    for (int i = 1; i <= 9; i++)
    {
        std::cout << "Stack " << i << " letter " << myStacks[i].front() << '\n';
        topOfStacks.append(myStacks[i].front());
        tempLetter = myStacks2[i].back();
        std::cout << "Stack 2 " << i << " letter " << tempLetter << '\n';
        topOfStacks2.append(tempLetter);
    }
    std::cout << "Top of the Stacks: " << topOfStacks << '\n';
    std::cout << "Top of the Stacks2: " << topOfStacks2 << '\n';
}