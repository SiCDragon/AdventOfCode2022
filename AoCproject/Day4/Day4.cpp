#include "Day4.h"

void elfSpacePairs()
{
    std::ifstream potato{ "Day4/spacePairs.txt" };
    std::string strInput{ "" };

    struct {
        std::string elfPair{ "" };
        int start{ 0 };
        int end{ 0 };
    }pair1, pair2;

    int totalPairs{ 0 }, totalOverlap{ 0 };

    if (!potato)
    {
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }
    while (potato)
    {
        std::getline(potato, strInput);
        //+1 in find because those include the delimiter character
        pair1.elfPair = strInput.substr(0, strInput.find(","));
        pair1.start = std::stoi(pair1.elfPair.substr(0, pair1.elfPair.find("-")));
        pair1.end = std::stoi(pair1.elfPair.substr(pair1.elfPair.find("-")+1, pair1.elfPair.length()));
        
        pair2.elfPair = strInput.substr(strInput.find(",")+1, strInput.length());
        pair2.start = std::stoi(pair2.elfPair.substr(0, pair2.elfPair.find("-")));
        pair2.end = std::stoi(pair2.elfPair.substr(pair2.elfPair.find("-")+1, pair2.elfPair.length()));

        //Part 1
        if ((pair1.start <= pair2.start && pair1.end >= pair2.end) || (pair2.start <= pair1.start && pair2.end >= pair1.end))
        {
            totalPairs++;
        }

        //Part 2
        if (!(pair1.end < pair2.start || pair2.end < pair1.start))
        {
            totalOverlap++;
        }

        if (potato.eof()) { break; }
    }

    std::cout << "Total Val: " << totalPairs << '\n'; 
    std::cout << "Total Overlap: " << totalOverlap << '\n';
}
