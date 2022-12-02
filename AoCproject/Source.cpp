#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // ifstream is used for reading files
    std::ifstream potato{ "elves.txt" };
    std::string storedInput = "";
    int elf{ 0 };
    int thiccElf{ 0 };

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
        std::string strInput;
        std::getline(potato, strInput);
        
        if (!strInput.empty()){
            
            elf += std::stoi(strInput);
            
            if (elf > thiccElf)
            {
                thiccElf = elf;
                std::cout << "Thicc: " << thiccElf << '\n';
            }
        }
        else
        {
            elf = 0;
        }

        //storedInput.append(strInput);
        //std::cout << "Elf: " << elf << '\n';
        //std::cout << "Thicc: " << thiccElf << '\n';

    }
    return 0;
}