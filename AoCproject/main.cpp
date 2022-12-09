#include <chrono>
#include "AdventDays.h"


int main()
{
	auto begin = std::chrono::high_resolution_clock::now();
	//Day 1
	//elfCalorieCalculator();

	//Day 2
	//elfRockPaperScissorsGamePart1();
	//elfRockPaperScissorsGamePart2();

	//Day 3
	//elfRucksack();
	//elfRucksack2();

	//Day 4
	//elfSpacePairs();

	//Day 5
	//elfCranes();

	//Day 6
	//elfComms();

	//Day 7
	//elfDir();

	//Day 8
	//elfTreeHouse();

	//Day 9
	elfTail();

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "Elapsed time: " << (elapsed.count()*1e-9) << '\n';
	return 0;
}