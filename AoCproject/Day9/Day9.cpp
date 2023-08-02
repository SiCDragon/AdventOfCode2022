#include "Day9.h"

enum class Dir : char {
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
	std::map<int, std::pair<int, int>> pos, prevpos;
	int totalPositions;
	int totalTailPositions;
	int knots;
	int x, y;

public:
	Rope(int k)
	{
		x = 0;
		y = 0;
		knots = k;
		totalPositions = 0;
		totalTailPositions = 0;
		positions.insert({ { x,y }, totalPositions++ });
		tailPositions.insert({ { x,y }, totalTailPositions++ });
		for (int i = 1; i <= knots; i++) {
			pos[i] = { x, y };
			prevpos[i] = { x, y };
		}
	}

	std::pair<int, int> getHeadPosition() { return pos[1]; }
	std::pair<int, int> getTailPosition() { return pos[knots]; }

	int getTotalPositions() { return totalPositions; }
	int getTotalTailPositions() { return tailPositions.size(); }

	int getUniquePositions() { return positions.size(); }

	void move(char direction, int count)
	{
		for(int ii = 0; ii < count; ii++){
			for (int jj = 1; jj <= knots; jj++){
				//prevpos[jj] = pos[jj];
				if (int(direction) == int(Dir::right)) {
					if (jj == 1) {
						pos[jj].first++;
					}
					else {
						if (pos[jj - 1].first - pos[jj].first >= 2) {
							pos[jj].first++;
						}
					}
				}
				if (int(direction) == int(Dir::left)) { 
					if (jj == 1) {
						pos[jj].first--;
					}
					else {
						if (pos[jj - 1].first - pos[jj].first >= 2) {
							pos[jj].first--;
						}
					}
				}
				if (int(direction) == int(Dir::up)) {
					if (jj == 1) {
						pos[jj].second++;
					}
					else {
						if (pos[jj - 1].second - pos[jj].second >= 2) {
							pos[jj].second++;
						}
					}
				}
				if (int(direction) == int(Dir::down)) {
					if (jj == 1) {
						pos[jj].second--;
					}
					else {
						if (pos[jj - 1].second - pos[jj].second >= 2) {
							pos[jj].second--;
						}
					}
				}
			}
		}
		//std::cout << "(  " << pos[1].first << "  ,  " << pos[1].second << " )  ";
		//std::cout << "(  " << pos[2].first << "  ,  " << pos[2].second << " )  ";
	}
};


void elfTail()
{
	std::ifstream potato{ "Day9/Day9Input.txt" };
	std::string moveDirStr{ "" }, moveAmountStr{ "" };

	int totalBytes{ 0 }, dirLevel{ 0 };
	Rope myRope = Rope(2);
	int tailMoves{ 0 };

	Rope myRope2 = Rope(10);


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
		//myRope2.move(moveDirStr.front(), std::stoi(moveAmountStr));

		std::cout << "(  " << myRope.getHeadPosition().first << "  ,  " << myRope.getHeadPosition().second << " )  ";
		std::cout << "( " << myRope.getTailPosition().first << " ,  " << myRope.getTailPosition().second << " )  " << '\n';

		//std::cout << "(  " << myRope2.getHeadPosition().first << "  ,  " << myRope2.getHeadPosition().second << " )  ";
		//std::cout << "( " << myRope2.getTailPosition().first << " ,  " << myRope2.getTailPosition().second << " )  " << '\n';

		if (potato.eof()) { break; }
	}

	std::cout << "----------------------------------- " << '\n';
	//std::cout << " Total moves: " << myRope.getTotalTailPositions() << '\n';
	std::cout << " Total moves 2: " << myRope2.getTotalTailPositions() << '\n';
}


