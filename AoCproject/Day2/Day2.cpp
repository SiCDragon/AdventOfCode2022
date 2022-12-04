#include "Day2.h"


void elfRockPaperScissorsGamePart1()
{
    std::ifstream potato{ "Day2/RPSGameStrat.txt" };
    std::string storedInput;
    
    std::string oppo;
    std::string myPlay;
    
    std::map<std::string, int> myPoints{ {"X", 1}, {"Y", 2}, {"Z", 3} };
    std::map<std::string, std::string> myWin{ {"X", "C"}, {"Y", "A"}, {"Z", "B"}};
    std::map<std::string, std::string> myLoss{ {"X", "B"}, {"Y", "C"}, {"Z", "A"} };
    std::map<std::string, std::string> draw{ {"X", "A"}, {"Y", "B"}, {"Z", "C"} };
    
    int myTotalPoints{ 0 };
    int gameResult{ 0 };

    // If we couldn't open the input file stream for reading
    if (!potato)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }

    // While there's still stuff left to read
    while (potato)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(potato, strInput);
        
        if (potato.eof()) { break; }

        oppo = strInput.front();
        myPlay = strInput.back();

        //std::cout << oppo << " : " << myPlay << '\n';
        if (oppo.compare(myWin[myPlay]) == 0)
        {
            gameResult = 6; //I won
        }
        else if (oppo.compare(myLoss[myPlay]) == 0)
        {
            gameResult = 0; //I lost
        }
        else if (oppo.compare(draw[myPlay]) == 0)
        {
            gameResult = 3; //I lost
        }
        else
        {
            gameResult = 0;
        }

        myTotalPoints += myPoints[myPlay] + gameResult;
    }
    std::cout <<  " Total Points: " << myTotalPoints << '\n';
}

void elfRockPaperScissorsGamePart2()
{
    std::ifstream potato{ "Day2/RPSGameStrat.txt" };
    std::string storedInput;

    std::string oppo;
    std::string gameResult;

    std::map<std::string, int> gamePoints{ {"X", 0}, {"Y", 3}, {"Z", 6} };

    std::map<std::string, std::string> myWin{ {"A", "Y"}, {"B", "Z"}, {"C", "X"} };
    std::map<std::string, std::string> myLoss{ {"A", "Z"}, {"B", "X"}, {"C", "Y"} };
    std::map<std::string, std::string> draw{ {"A", "X"}, {"B", "Y"}, {"C", "Z"} };

    std::map<std::string, int> myPlayPoints{ {"X", 1}, {"Y", 2}, {"Z", 3} };
    
    int myPoints{ 0 };
    int myTotalPoints{ 0 };

    // If we couldn't open the input file stream for reading
    if (!potato)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }

    // While there's still stuff left to read
    while (potato)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(potato, strInput);

        if (potato.eof()) { break; }

        oppo = strInput.front();
        gameResult = strInput.back();

        if (gameResult.compare("X") == 0)
        {
            myPoints = myPlayPoints[myLoss[oppo]]; //I lost
        }
        else if (gameResult.compare("Y") == 0)
        {
            myPoints = myPlayPoints[draw[oppo]]; //draw
        }
        else if (gameResult.compare("Z") == 0)
        {
            myPoints = myPlayPoints[myWin[oppo]]; //I won
        }
        else
        {
            myPoints = 0;
        }


        myTotalPoints += myPoints + gamePoints[gameResult];
    }

    std::cout << " Total Points: " << myTotalPoints << '\n';
}
