#include "Day3.h"

int charPoints(char letter)
{
    if (std::islower(letter))
    {
        return (int(letter) - 96);
    }
    else if (std::isupper(letter))
    {
        return (int(letter) - 38);
    }
    else
    {
        return 0;
    }
}

void elfRucksack()
{
    std::ifstream potato{ "Day3/elfItems.txt" };
    std::string strInput, priorityLetter;

    std::string elfItems[2] = { "" , "" };
    int totalValue{ 0 };

    if (!potato)
    {
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }
    while (potato)
    {
        std::getline(potato, strInput);

        elfItems[0] = strInput.substr(0, strInput.length() / 2);
        elfItems[1] = strInput.substr((strInput.length() / 2), strInput.length());
        
        //inputs to set_intersection need to be sorted first
        std::sort(elfItems[0].begin(), elfItems[0].end());
        std::sort(elfItems[1].begin(), elfItems[1].end());
        std::set_intersection(elfItems[0].begin(), elfItems[0].end(),
            elfItems[1].begin(), elfItems[1].end(), std::back_inserter(priorityLetter));
        //back because it appends letters to the string
        totalValue += charPoints(priorityLetter.back());
        if (potato.eof()) { break; }
    }

    std::cout << "Total Val: " << totalValue << '\n';
}

void elfRucksack2()
{
    std::ifstream potato{ "Day3/elfItems.txt" };
    std::string strInput, priorityLetter;

    std::string elfItems[3] = { "" , "", ""};
    int totalValue{ 0 }, count{ 0 };

    if (!potato)
    {
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }
    while (potato)
    {
        std::getline(potato, strInput);
        elfItems[count++] = strInput;
        
        if (count == 3)
        {
            count = 0;

            //inputs to set_intersection need to be sorted first
            std::sort(elfItems[0].begin(), elfItems[0].end());
            std::sort(elfItems[1].begin(), elfItems[1].end());
            std::set_intersection(elfItems[0].begin(), elfItems[0].end(),
                elfItems[1].begin(), elfItems[1].end(), std::back_inserter(priorityLetter));

            std::sort(elfItems[2].begin(), elfItems[2].end());
            std::sort(priorityLetter.begin(), priorityLetter.end());
            std::set_intersection(priorityLetter.begin(), priorityLetter.end(),
                elfItems[2].begin(), elfItems[2].end(), std::back_inserter(priorityLetter));

            //back because it appends letters to the string
            totalValue += charPoints(priorityLetter.back());
            priorityLetter = "";
        }
        if (potato.eof()) { break; }
    }

    std::cout << "Total Val: " << totalValue << '\n';
}


