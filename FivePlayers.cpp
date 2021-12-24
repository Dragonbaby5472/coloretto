#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <limits>
#include "Game.h"
using namespace std;
using namespace std;

int FivePlayers::giveCard() {
	takeTimes++;
	return card[takeTimes - 1];
}

void FivePlayers::frameForFive() {
	cout << "Player 1:\n";
	cout << "Blue  :" << setw(2) << outputNumber[0][0];
	cout << " Orange:" << setw(2) << outputNumber[0][3];
	cout << " Brown :" << setw(2) << outputNumber[0][6] << "\n";
	cout << "Gray  :" << setw(2) << outputNumber[0][1];
	cout << " Yellow:" << setw(2) << outputNumber[0][4];
	cout << " Joker :" << setw(2) << outputNumber[0][7] << "\n";
	cout << "Pink  :" << setw(2) << outputNumber[0][2];
	cout << " Green :" << setw(2) << outputNumber[0][5];
	cout << " +2    :" << setw(2) << outputNumber[0][8] << "\n";
	cout << "Player 2:\n";
	cout << "Blue  :" << setw(2) << outputNumber[1][0];
	cout << " Orange:" << setw(2) << outputNumber[1][3];
	cout << " Brown :" << setw(2) << outputNumber[1][6] << "\n";
	cout << "Gray  :" << setw(2) << outputNumber[1][1];
	cout << " Yellow:" << setw(2) << outputNumber[1][4];
	cout << " Joker :" << setw(2) << outputNumber[1][7] << "\n";
	cout << "Pink  :" << setw(2) << outputNumber[1][2];
	cout << " Green :" << setw(2) << outputNumber[1][5];
	cout << " +2    :" << setw(2) << outputNumber[1][8] << "\n";
	cout << "Player 3:\n";
	cout << "Blue  :" << setw(2) << outputNumber[2][0];
	cout << " Orange:" << setw(2) << outputNumber[2][3];
	cout << " Brown :" << setw(2) << outputNumber[2][6] << "\n";
	cout << "Gray  :" << setw(2) << outputNumber[2][1];
	cout << " Yellow:" << setw(2) << outputNumber[2][4];
	cout << " Joker :" << setw(2) << outputNumber[2][7] << "\n";
	cout << "Pink  :" << setw(2) << outputNumber[2][2];
	cout << " Green :" << setw(2) << outputNumber[2][5];
	cout << " +2    :" << setw(2) << outputNumber[2][8] << "\n";
	cout << "Player 4:\n";
	cout << "Blue  :" << setw(2) << outputNumber[3][0];
	cout << " Orange:" << setw(2) << outputNumber[3][3];
	cout << " Brown :" << setw(2) << outputNumber[3][6] << "\n";
	cout << "Gray  :" << setw(2) << outputNumber[3][1];
	cout << " Yellow:" << setw(2) << outputNumber[3][4];
	cout << " Joker :" << setw(2) << outputNumber[3][7] << "\n";
	cout << "Pink  :" << setw(2) << outputNumber[3][2];
	cout << " Green :" << setw(2) << outputNumber[3][5];
	cout << " +2    :" << setw(2) << outputNumber[3][8] << "\n";
	cout << "You:\n";
	cout << "Blue  :" << setw(2) << outputNumber[4][0];
	cout << " Orange:" << setw(2) << outputNumber[4][3];
	cout << " Brown :" << setw(2) << outputNumber[4][6] << "\n";
	cout << "Gray  :" << setw(2) << outputNumber[4][1];
	cout << " Yellow:" << setw(2) << outputNumber[4][4];
	cout << " Joker :" << setw(2) << outputNumber[4][7] << "\n";
	cout << "Pink  :" << setw(2) << outputNumber[4][2];
	cout << " Green :" << setw(2) << outputNumber[4][5];
	cout << " +2    :" << setw(2) << outputNumber[4][8] << "\n";
	cout << "Next Card: " << nextCard << endl;
	cout << banRow[0] << "Row 1: " << left << setw(6) << row1[0] << "," << setw(6) << row1[1] << ","
		<< setw(6) << row1[2] << "\n";
	cout << banRow[1] << "Row 2: " << left << setw(6) << row2[0] << "," << setw(6) << row2[1] << ","
		<< setw(6) << row2[2] << "\n";
	cout << banRow[2] << "Row 3: " << left << setw(6) << row3[0] << "," << setw(6) << row3[1] << ","
		<< setw(6) << row3[2] << "\n";
	cout << banRow[3] << "Row 4: " << left << setw(6) << row4[0] << "," << setw(6) << row4[1] << ","
		<< setw(6) << row4[2] << "\n";
	cout << banRow[4] << "Row 5: " << left << setw(6) << row5[0] << "," << setw(6) << row5[1] << ","
		<< setw(6) << row5[2] << "\n";
	cout << endl;
}

void FivePlayers::cardOrder() {
	srand((unsigned)time(NULL));
	for (int i = 0; i <= 75; i++) {
		card[i] = rand() % 9 + 1;	//1~9
		if (i < 5) {
			if (card[i] == 8 || card[i] == 9) {
				i--;	//do again
				continue;
			}
			if (i == 1) {
				if (card[i] == card[0]) {
					i--;	//do again
					continue;
				}

			}
			else if (i == 2) {
				if (card[i] == card[1] || card[i] == card[0]) {
					i--;	//do again
					continue;
				}
			}
			else if (i == 3) {
				if (card[i] == card[2] || card[i] == card[1] || card[i] == card[0]) {
					i--;	//do again
					continue;
				}
			}
			else if (i == 4) {
				if (card[i] == card[3] || card[i] == card[2] || card[i] == card[1] || card[i] == card[0]) {
					i--;	//do again
					continue;
				}
			}
			continue;
		}
		if (card[i] == 1 || card[i] == 2 || card[i] == 3 || card[i] == 4 ||
			card[i] == 5 || card[i] == 6 || card[i] == 7) {
			if (howMany(card[i], i) == 10) {
				i--;	//do again
				continue;
			}
		}
		else if (card[i] == 8) {
			if (howMany(card[i], i) == 4) {
				i--;	//do again
				continue;
			}
		}
		else if (card[i] == 9) {
			if (howMany(card[i], i) == 11) {
				i--;	//do again
				continue;
			}
		}
	}
}
int FivePlayers::howMany(int a, int i) {
	int times = 0;
	for (;; i--) {
		if (card[i] == a) {
			times += 1;
		}
		if (i == 0)
			break;
	}
	return times;
}
string FivePlayers::checkcard(int a) {
	if (a == 1) {
		return "Blue";
	}
	else if (a == 2) {
		return "Gray";
	}
	else if (a == 3) {
		return "Pink";
	}
	else if (a == 4) {
		return "Orange";
	}
	else if (a == 5) {
		return "Yellow";
	}
	else if (a == 6) {
		return "Green";
	}
	else if (a == 7) {
		return "Brown";
	}
	else if (a == 8) {
		return "Joker";
	}
	else if (a == 9) {
		return "+2";
	}
	return "Error";
}
void FivePlayers::inputA() {
	printf("What do you want to do?\n");
	printf("Enter \"draw\" to draw the card,\n");
	printf("or enter \"1\", \"2\", \"3\", \"4\" or \"5\" to pick card at that row.\n");
START:
	cin >> choose;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = 0; i < 4; i++) {
		if (choose[0] == '1' || choose[0] == '2' || choose[0] == '3' || choose[0] == '4' || choose[0] == '5')
			break;
		if (checkInput(i, choose[i]) == false) {
			printf("Input error, please enter again.\n");
			goto START;
		}
	}
	printf("You enter:");
	printf("%s\n", choose);
}
bool FivePlayers::checkInput(int a, char b) {
	if (a == 0) {
		if (b == 'd' || b == '1' || b == '2' || b == '3' || b == '4' || b == '5')
			return true;
		return false;
	}
	else if (a == 1) {
		if (b == 'r' || b == ' ')
			return true;
		return false;
	}
	else if (a == 2) {
		if (b == 'a' || b == ' ')
			return true;
		return false;
	}
	else if (a == 3) {
		if (b == 'w' || b == ' ')
			return true;
		return false;
	}
	else
		return true;
}
void FivePlayers::draw() {
	nextCard = checkcard(giveCard());
}
void FivePlayers::inputB() {
	printf("Which row do you want to put?\n");
	printf("Enter \"1\", \"2\", \"3\", \"4\" or \"5\" to put card at that row\n");
START:
	cin >> ch;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = 0; i <= 3; i++) {
		if (ch[0] == '1' || ch[0] == '2' || ch[0] == '3' || ch[0] == '4' || ch[0] == '5')
			break;
		if (checkInput(i, ch[i]) == false) {
			printf("Input error, please enter again.\n");
			goto START;
		}
	}
	putToRow();
}
void FivePlayers::putToRow() {
	if (ch[0] == '1') {
		if (r1 == 3 || banRow[0] == 'x') {
			printf("Input error, please enter again.\n");
			inputB();
			return;
		}
		else {
			row1[r1] = nextCard;
			r1++;
			nextCard = "";
		}
	}
	else if (ch[0] == '2') {
		if (r2 == 3 || banRow[1] == 'x') {
			printf("Input error, please enter again.\n");
			inputB();
			return;
		}
		else {
			row2[r2] = nextCard;
			r2++;
			nextCard = "";
		}
	}
	else if (ch[0] == '3') {
		if (r3 == 3 || banRow[2] == 'x') {
			printf("Input error, please enter again.\n");
			inputB();
			return;
		}
		else {
			row3[r3] = nextCard;
			r3++;
			nextCard = "";
		}
	}
	else if (ch[0] == '4') {
		if (r4 == 3 || banRow[3] == 'x') {
			printf("Input error, please enter again.\n");
			inputB();
			return;
		}
		else {
			row4[r4] = nextCard;
			r4++;
			nextCard = "";
		}
	}
	else if (ch[0] == '5') {
		if (r5 == 3 || banRow[4] == 'x') {
			printf("Input error, please enter again.\n");
			inputB();
			return;
		}
		else {
			row5[r5] = nextCard;
			r5++;
			nextCard = "";
		}
	}
	else {
		printf("Input error! Please enter again.\n");
		inputB();
		return;
	}
}

void FivePlayers::getRow(char a, int b) {	//a is row, b is player
	if (a == '1') {
		for (int i = 0; i <= 2; i++) {
			if (row1[i] == "Blue")
				outputNumber[b][0] ++;
			else if (row1[i] == "Gray")
				outputNumber[b][1] ++;
			else if (row1[i] == "Pink")
				outputNumber[b][2] ++;
			else if (row1[i] == "Orange")
				outputNumber[b][3] ++;
			else if (row1[i] == "Yellow")
				outputNumber[b][4] ++;
			else if (row1[i] == "Green")
				outputNumber[b][5] ++;
			else if (row1[i] == "Brown")
				outputNumber[b][6] ++;
			else if (row1[i] == "Joker")
				outputNumber[b][7] ++;
			else if (row1[i] == "+2")
				outputNumber[b][8] ++;
			row1[i].clear();
		}
		r1 = 0;
		banRow[0] = 'x';
	}
	else if (a == '2') {
		for (int i = 0; i <= 2; i++) {
			if (row2[i] == "Blue")
				outputNumber[b][0] ++;
			else if (row2[i] == "Gray")
				outputNumber[b][1] ++;
			else if (row2[i] == "Pink")
				outputNumber[b][2] ++;
			else if (row2[i] == "Orange")
				outputNumber[b][3] ++;
			else if (row2[i] == "Yellow")
				outputNumber[b][4] ++;
			else if (row2[i] == "Green")
				outputNumber[b][5] ++;
			else if (row2[i] == "Brown")
				outputNumber[b][6] ++;
			else if (row2[i] == "Joker")
				outputNumber[b][7] ++;
			else if (row2[i] == "+2")
				outputNumber[b][8] ++;
			row2[i].clear();
		}
		r2 = 0;
		banRow[1] = 'x';
	}
	else if (a == '3') {
		for (int i = 0; i <= 2; i++) {
			if (row3[i] == "Blue")
				outputNumber[b][0] ++;
			else if (row3[i] == "Gray")
				outputNumber[b][1] ++;
			else if (row3[i] == "Pink")
				outputNumber[b][2] ++;
			else if (row3[i] == "Orange")
				outputNumber[b][3] ++;
			else if (row3[i] == "Yellow")
				outputNumber[b][4] ++;
			else if (row3[i] == "Green")
				outputNumber[b][5] ++;
			else if (row3[i] == "Brown")
				outputNumber[b][6] ++;
			else if (row3[i] == "Joker")
				outputNumber[b][7] ++;
			else if (row3[i] == "+2")
				outputNumber[b][8] ++;
			row3[i].clear();
		}
		r3 = 0;
		banRow[2] = 'x';
	}
	else if (a == '4') {
		for (int i = 0; i <= 2; i++) {
			if (row4[i] == "Blue")
				outputNumber[b][0] ++;
			else if (row4[i] == "Gray")
				outputNumber[b][1] ++;
			else if (row4[i] == "Pink")
				outputNumber[b][2] ++;
			else if (row4[i] == "Orange")
				outputNumber[b][3] ++;
			else if (row4[i] == "Yellow")
				outputNumber[b][4] ++;
			else if (row4[i] == "Green")
				outputNumber[b][5] ++;
			else if (row4[i] == "Brown")
				outputNumber[b][6] ++;
			else if (row4[i] == "Joker")
				outputNumber[b][7] ++;
			else if (row4[i] == "+2")
				outputNumber[b][8] ++;
			row4[i].clear();
		}
		r4 = 0;
		banRow[3] = 'x';
	}
	if (a == '5') {
		for (int i = 0; i <= 2; i++) {
			if (row5[i] == "Blue")
				outputNumber[b][0] ++;
			else if (row5[i] == "Gray")
				outputNumber[b][1] ++;
			else if (row5[i] == "Pink")
				outputNumber[b][2] ++;
			else if (row5[i] == "Orange")
				outputNumber[b][3] ++;
			else if (row5[i] == "Yellow")
				outputNumber[b][4] ++;
			else if (row5[i] == "Green")
				outputNumber[b][5] ++;
			else if (row5[i] == "Brown")
				outputNumber[b][6] ++;
			else if (row5[i] == "Joker")
				outputNumber[b][7] ++;
			else if (row5[i] == "+2")
				outputNumber[b][8] ++;
			row5[i].clear();
		}
		r5 = 0;
		banRow[4] = 'x';
	}
	stop[b] = 1;
}
void FivePlayers::output(int a, int b) {
	outputNumber[a][b] += 1;
}

void FivePlayers::computer(int player) {
	if (stop[player] == 1) {
		cout << "Player " << player + 1 << " pass.\n";
		return;
	}
	cout << "Player " << player + 1 << "'s turn:\n";
	for (int i = 0; i < 3; i++)
		big[i] = 0;
	for (int i = 0; i < 3; i++)
		bigName[i] = i + 1;
	string bigNamestr[3];
	for (int i = 0; i < 3; i++) {
		big[i] = 0;
	}
	if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && r5 == 0) {
		computerDraw(player);
		frameForFive();
		endRound(player);
		return;
	}
	for (int i = 0; i <= 6; i++) {
		if (outputNumber[player][i] > big[0]) {
			big[0] = outputNumber[player][i];
			bigName[0] = i;
		}
	}
	for (int i = 0; i <= 6; i++) {
		if (outputNumber[player][i] > big[1] && i != bigName[0]) {
			big[1] = outputNumber[player][i];
			bigName[1] = i;
		}
	}
	for (int i = 0; i <= 6; i++) {
		if (outputNumber[player][i] > big[2] && i != bigName[0] && i != bigName[1]) {
			big[2] = outputNumber[player][i];
			bigName[2] = i;
		}
	}
	for (int i = 0; i <= 2; i++) {
		bigNamestr[i] = checkcard(bigName[i]);
	}
	for (int i = 0; i <= 4; i++) {
		row[i] = 0;
	}
	for (int i = 0; i <= 2; i++) {
		if (row1[i] == bigNamestr[0] || row1[i] == bigNamestr[1] || row1[i] == bigNamestr[2])
			row[0]++;
		if (row1[i] == "Joker" || row1[i] == "+2")
			row[0] += 2;
		if (row2[i] == bigNamestr[0] || row2[i] == bigNamestr[1] || row2[i] == bigNamestr[2])
			row[1]++;
		if (row2[i] == "Joker" || row2[i] == "+2")
			row[1] += 2;
		if (row3[i] == bigNamestr[0] || row3[i] == bigNamestr[1] || row3[i] == bigNamestr[2])
			row[2]++;
		if (row3[i] == "Joker" || row3[i] == "+2")
			row[2] += 2;
		if (row4[i] == bigNamestr[0] || row4[i] == bigNamestr[1] || row4[i] == bigNamestr[2])
			row[3]++;
		if (row4[i] == "Joker" || row4[i] == "+2")
			row[3] += 2;
		if (row5[i] == bigNamestr[0] || row5[i] == bigNamestr[1] || row5[i] == bigNamestr[2])
			row[4]++;
		if (row5[i] == "Joker" || row5[i] == "+2")
			row[4] += 2;
	}
	if (row[0] == 0 && row[1] == 0 && row[2] == 0 && row[3] == 0 && row[4] == 0) {
		if ((r1 == 3 || banRow[0] == 'x') && (r2 == 3 || banRow[1] == 'x')
			&& (r3 == 3 || banRow[2] == 'x') && (r4 == 3 || banRow[3] == 'x')
			&& (r5 == 3 || banRow[4] == 'x')) {
			if (banRow[1] != 'x') {
				getRow('2', player);
				cout << "Player " << player + 1 << " take row" << 2 << endl;
			}
			else if (banRow[2] != 'x') {
				getRow('3', player);
				cout << "Player " << player + 1 << " take row" << 3 << endl;
			}
			else if (banRow[3] != 'x') {
				getRow('4', player);
				cout << "Player " << player + 1 << " take row" << 4 << endl;
			}
			else if (banRow[0] != 'x') {
				getRow('1', player);
				cout << "Player " << player + 1 << " take row" << 1 << endl;
			}
			else if (banRow[4] != 'x') {
				getRow('5', player);
				cout << "Player " << player + 1 << " take row" << 5 << endl;
			}
			stop[player] = 1;
			frameForFive();
			endRound(player);
			return;
		}
		else {
			computerDraw(player);
			frameForFive();
			endRound(player);
			return;
		}
	}
	else {
		temp = 0;
		name = 0;
		for (int i = 0; i < 5; i++) {
			if (row[i] > temp) {
				temp = row[i];
				name = i;
			}
		}
		if (name == 0) {
			getRow('1', player);
			cout << "Player " << player + 1 << " take row" << 1 << "." << endl;
			stop[player] = 1;
			frameForFive();
			endRound(player);
			return;
		}
		else if (name == 1) {
			getRow('2', player);
			cout << "Player " << player + 1 << " take row" << 2 << "." << endl;
			stop[player] = 1;
			frameForFive();
			endRound(player);
			return;
		}
		else if (name == 2) {
			getRow('3', player);
			cout << "Player " << player + 1 << " take row" << 3 << "." << endl;
			stop[player] = 1;
			frameForFive();
			endRound(player);
			return;
		}
		else if (name == 3) {
			getRow('4', player);
			cout << "Player " << player + 1 << " take row" << 4 << "." << endl;
			stop[player] = 1;
			frameForFive();
			endRound(player);
			return;
		}
		else if (name == 4) {
			getRow('5', player);
			cout << "Player " << player + 1 << " take row" << 5 << "." << endl;
			stop[player] = 1;
			frameForFive();
			endRound(player);
			return;
		}
		else {
			cout << "ERROR: 2" << endl;
		}
		//computerDraw(player);
		frameForFive();
	}
}
void FivePlayers::computerDraw(int player) {
	draw();
	//cout << "I draw.";
AGAIN:
	//srand((unsigned)time(NULL));
	randN = rand() % 5;
	if (randN == 0) {
		if (r1 == 3 || banRow[0] == 'x') {
			goto AGAIN;
		}
		ch[0] = '1';
	}
	else if (randN == 1) {
		if (r2 == 3 || banRow[1] == 'x') {
			goto AGAIN;
		}
		ch[0] = '2';
	}
	else if (randN == 2) {
		if (r3 == 3 || banRow[2] == 'x') {
			goto AGAIN;
		}
		ch[0] = '3';
	}
	else if (randN == 3) {
		if (r4 == 3 || banRow[3] == 'x') {
			goto AGAIN;
		}
		ch[0] = '4';
	}
	else if (randN == 4) {
		if (r5 == 3 || banRow[4] == 'x') {
			goto AGAIN;
		}
		ch[0] = '5';
	}
	putToRow();
	cout << "Player " << player + 1 << " draw and put to row" << randN + 1 << "." << endl;
	return;
}
void FivePlayers::people() {
	if (stop[4] == 1) {
		cout << "You pass.\n";
		return;
	}
INPUT:
	inputA();
	if (choose[0] == 'd') {
		if ((r1 == 3 || banRow[0] == 'x') && (r2 == 3 || banRow[1] == 'x')
			&& (r3 == 3 || banRow[2] == 'x') && (r4 == 3 || banRow[3] == 'x')
			&& (r5 == 3 || banRow[4] == 'x')) {
			cout << "Input error, please enter again.\n";
			goto INPUT;
		}
		draw();
		frameForFive();
		inputB();
		frameForFive();
		endRound(4);
		return;
	}
	else {
		if (choose[0] == '1') {
			if (r1 == 0 || banRow[0] == 'x') {
				cout << "Input error, please enter again.\n";
				goto INPUT;
			}
		}
		else if (choose[0] == '2') {
			if (r2 == 0 || banRow[1] == 'x') {
				cout << "Input error, please enter again.\n";
				goto INPUT;
			}
		}
		else if (choose[0] == '3') {
			if (r3 == 0 || banRow[2] == 'x') {
				cout << "Input error, please enter again.\n";
				goto INPUT;
			}
		}
		else if (choose[0] == '4') {
			if (r4 == 0 || banRow[3] == 'x') {
				cout << "Input error, please enter again.\n";
				goto INPUT;
			}
		}
		else if (choose[0] == '5') {
			if (r5 == 0 || banRow[4] == 'x') {
				cout << "Input error, please enter again.\n";
				goto INPUT;
			}
		}
		getRow(choose[0], 4);
		frameForFive();
		endRound(4);
		return;
	}
}
void FivePlayers::startCard() {
	for (int i = 0; i <= 4; i++) {
		outputNumber[i][giveCard() - 1] ++;
	}
}
int FivePlayers::countScoreAI(int player) {
	int rank[7];
	int temp = 0;
	for (int i = 0; i <= 6; i++) {
		rank[i] = outputNumber[player][i];
	}
	for (int i = 0; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {	//rank[0] is the biggest.
			if (rank[j] > rank[j - 1]) {
				temp = rank[j];
				rank[j] = rank[j - 1];
				rank[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		while (rank[i] < 6 && outputNumber[player][7] > 0) {
			rank[i] += 1;
			outputNumber[player][7] -= 1;
		}
	}
	int score[7];
	for (int i = 0; i <= 6; i++) {
		switch (rank[i])
		{
		case 0:
			score[i] = 0;
			break;
		case 1:
			score[i] = 1;
			break;
		case 2:
			score[i] = 3;
			break;
		case 3:
			score[i] = 6;
			break;
		case 4:
			score[i] = 10;
			break;
		case 5:
			score[i] = 15;
			break;
		case 6:
			score[i] = 21;
			break;
		case 7:
			score[i] = 21;
			break;
		case 8:
			score[i] = 21;
			break;
		case 9:
			score[i] = 21;
			break;
		default:
			cout << "ERROR: 3" << endl;
			break;
		}
	}
	return score[0] + score[1] + score[2] - score[3] - score[4] - score[5] - score[6]
		+ outputNumber[player][8] * 2;
}
void FivePlayers::endRound(int player) {
	if (stop[0] == 1 && stop[1] == 1 && stop[2] == 1 && stop[3] == 1 && stop[4] == 1) {
		for (int i = 0; i < 5; i++) {
			stop[i] = 0;
			banRow[i] = ' ';
		}
		if (takeTimes >= 61) {
			printf("Game Over!\n");
			int score[5];
			int place[5] = { 0,1,2,3,4 };
			score[0] = countScoreAI(0);
			score[1] = countScoreAI(1);
			score[2] = countScoreAI(2);
			score[3] = countScoreAI(3);
			score[4] = countScoreAI(4);
			int change = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (score[j] < score[j + 1]) {
						change = place[j];
						place[j] = place[j + 1];
						place[j + 1] = change;
						change = score[j];
						score[j] = score[j + 1];
						score[j + 1] = change;
					}
				}
			}
			cout << "First  place : ";
			if (place[0] == 4)
				cout << "You -- " << score[0] << " points\n";
			else
				cout << "Player" << place[0] + 1 << " -- " << score[0] << " points\n";
			cout << "Second place : ";
			if (place[1] == 4)
				cout << "You     -- " << score[1] << " points\n";
			else
				cout << "Player" << place[1] + 1 << " -- " << score[1] << " points\n";
			cout << "Third  place : ";
			if (place[2] == 4)
				cout << "You -- " << score[2] << " points\n";
			else
				cout << "Player" << place[2] + 1 << " -- " << score[2] << " points\n";
			cout << "Forth  place : ";
			if (place[3] == 4)
				cout << "You -- " << score[3] << " points\n";
			else
				cout << "Player" << place[3] + 1 << " -- " << score[3] << " points\n";
			cout << "Fifth  place : ";
			if (place[4] == 4)
				cout << "You -- " << score[4] << " points\n";
			else
				cout << "Player" << place[4] + 1 << " -- " << score[4] << " points\n";
			exit(0);
		}
		if (player != 4) {
			this_thread::sleep_for(chrono::milliseconds(1500));
			computer(player);
		}
		else if (player == 4) {
			this_thread::sleep_for(chrono::milliseconds(1500));
			people();
		}
	}
}
void FivePlayers::play() {
	srand((unsigned)time(NULL));
	cardOrder();
	startCard();
	for (;;) {
		computer(0);
		this_thread::sleep_for(chrono::milliseconds(1500));
		computer(1);
		this_thread::sleep_for(chrono::milliseconds(1500));
		computer(2);
		this_thread::sleep_for(chrono::milliseconds(1500));
		computer(3);
		this_thread::sleep_for(chrono::milliseconds(1500));
		people();
		this_thread::sleep_for(chrono::milliseconds(1500));
	}
}