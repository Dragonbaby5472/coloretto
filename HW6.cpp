#include <iostream>
#include <string>
#include <time.h>
#include <limits>
#include "Game.h"
using namespace std;

int checkInput(string &str) {	//check if input string is a positive integer and return that number
	for (char const &c : str) {
		if (!((int)c <= 53 && (int)c >= 51)) {
			printf("Input error, please enter again.\n");
			cin >> str;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return checkInput(str);
		}
	}
	return stoi(str);
}

int main() {
	srand((unsigned)time(NULL));
	ThreePlayers play3;
	FourPlayers play4;
	FivePlayers play5;
	string input;
	printf("Enter \"3\", \"4\" or \"5\" to choose the numbers of players.\n");
	cin >> input;
	int decision = checkInput(input);
	if (decision == 3)
		play3.play();
	else if (decision == 4)
		play4.play();
	else if (decision == 5)
		play5.play();
	else
		printf("ERROR!!");
	return 0;
}