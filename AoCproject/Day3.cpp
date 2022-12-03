#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <chrono>


int elfRucksack()
{
    // ifstream is used for reading files
    auto begin = std::chrono::high_resolution_clock::now();

    std::ifstream potato{ "elfItems.txt" };
    std::string storedInput;
    std::string strInput;

    std::string elfItems[2] = {"" , ""};
    int totalValue{ 0 };
    char priorityItem;

    // If we couldn't open the input file stream for reading
    if (!potato)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    while (potato)
    {
        // read stuff from the file into a string and print it

        std::getline(potato, strInput);
        
        elfItems[0] = strInput.substr(0, strInput.length() / 2);
        elfItems[1] = strInput.substr((strInput.length() / 2), strInput.length());

        for (int idx = 0; idx <= elfItems[0].length(); idx++)
        {
            if (elfItems[1].find(elfItems[0][idx]) <= elfItems[0].length())
            {
                priorityItem = elfItems[0][idx];
                break;
            }
        }
        if (int(priorityItem) >= 97 && int(priorityItem) <= 122)
        {
            totalValue += (int(priorityItem) - 96);
        }
        else if (int(priorityItem) >= 65 && int(priorityItem) <= 90)
        {
            totalValue += (int(priorityItem) - 38);
        }
        if (potato.eof()) { break; }
    }

    std::cout << "Total Val: " << totalValue << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "Elapsed time: " << (elapsed.count() * 1e-9) << '\n';

    return totalValue;
}

int elfRucksackPart2()
{
    // ifstream is used for reading files
    auto begin = std::chrono::high_resolution_clock::now();

    std::ifstream potato{ "elfItems.txt" };
    std::string storedInput;
    std::string strInput;

    std::string elfItems[3] = { "", "", ""};
    int totalValue{ 0 };
    int count{ 0 };
    char priorityItem{'a'};

    // If we couldn't open the input file stream for reading
    if (!potato)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    while (potato)
    {
        // read stuff from the file into a string and print it

        std::getline(potato, strInput);
        
        elfItems[count++] = strInput;
        
        if (count > 2)
        {
            count = 0;

            for (int idx = 0; idx <= elfItems[0].length(); idx++)
            {
                if (elfItems[1].find(elfItems[0][idx]) <= elfItems[1].length() && elfItems[2].find(elfItems[0][idx]) <= elfItems[2].length())
                {
                    priorityItem = elfItems[0][idx];
                    break;
                }
            }

        
            if (int(priorityItem) >= 97 && int(priorityItem) <= 122)
            {
                totalValue += (int(priorityItem) - 96);
            }
            else if (int(priorityItem) >= 65 && int(priorityItem) <= 90)
            {
                totalValue += (int(priorityItem) - 38);
            }
        }

        if (potato.eof()) { break; }
    }

    std::cout << "Total Val: " << totalValue << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Elapsed time: " << (elapsed.count()) << '\n';

    return totalValue;
}
