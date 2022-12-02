#include <fstream>
#include <iostream>
#include <string>
#include <map>

int main()
{
    // ifstream is used for reading files
    std::ifstream potato{ "elves.txt" };
    std::string storedInput = "";
    int elfCalories{ 0 };
    int bigCals{ 0 };

    std::map<int, int> elves{ {1,1} };
    std::map<std::string, int> thiccElves{{"thicc", 0}, {"thiccer", 0}, {"thiccest", 0}};

    int elfNumber{ 1 };

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
            
            elfCalories += std::stoi(strInput);
            
        }
        else
        {
            if (elfCalories > thiccElves["thiccest"])
            {
                thiccElves["thiccer"] = thiccElves["thiccest"];
                thiccElves["thiccest"] = elfCalories;

            }
            else if (elfCalories < thiccElves["thiccest"] && elfCalories > thiccElves["thiccer"])
            {
                thiccElves["thicc"] = thiccElves["thiccer"];
                thiccElves["thiccer"] = elfCalories;
            }
            else if (elfCalories < thiccElves["thiccer"] && elfCalories > thiccElves["thicc"])
            {
                thiccElves["thicc"] = elfCalories;
            }

            //elves.insert(elfNumber, elfCalories);
            elfCalories = 0;
            elfNumber++;
        }

        //storedInput.append(strInput);
        //std::cout << "Elf: " << elf << '\n';
        //std::cout << "Thicc: " << thiccElf << '\n';
        
    }
    bigCals = thiccElves["thicc"] + thiccElves["thiccer"] + thiccElves["thiccest"];
    std::cout << "Thicc: " << thiccElves["thicc"] << '\n';
    std::cout << "Thiccer: " << thiccElves["thiccer"] << '\n';
    std::cout << "Thiccest: " << thiccElves["thiccest"] << '\n';
    std::cout << "Big Calories: " << bigCals << '\n';
    return 0;
}