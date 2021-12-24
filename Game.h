#pragma once
#include <iostream>
#include <string>
using namespace std;
class FourPlayers {
private:
	int card[76];	//card's sequence
	int takeTimes = 0;	//count how many card do we draw
	char choose[100];	//store what player enter to choose
	char ch[100];
	int outputNumber[4][9] = { 0 };//store data to show out
	string nextCard;	//to see what is next card
	/*string of card on row to show on screen*/
	string row1[3];
	string row2[3];
	string row3[3];
	string row4[4];
	/*check numbers of card on each row*/
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;
	int r4 = 0;
	int randN;	//random number
	/*to find out which is the most card player has*/
	int big[3] = { 0,0,0 };
	int bigName[3] = { 0,1,2 };
	string bigNamestr[3];
	int row[4] = { 0,0,0,0 };
	int stop[4] = { 0,0,0,0 };
	char banRow[4] = { ' ',' ',' ',' ' };	//after picking the row, player cannot put card on that row
	int temp = 0;
	int name = 0;

	int howMany(int, int);
	void cardOrder();
	int giveCard();
	string checkcard(int);
	void inputA();
	bool checkInput(int, char);
	void draw();
	void inputB();
	void putToRow();
	void getRow(char, int);
	void frameForFour();
	void output(int, int);
	void computer(int);
	void computerDraw(int);
	void startCard();
	int countScoreAI(int);
	void endRound(int);
	void people();
public:
	void play();
};
class FivePlayers {
private:
	int card[76];	
	int takeTimes = 0;	
	char choose[100];	
	char ch[100];
	int outputNumber[5][9] = { 0 };
	string nextCard;	
	string row1[3];
	string row2[3];
	string row3[3];
	string row4[3];
	string row5[3];
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;
	int r4 = 0;
	int r5 = 0;
	int randN;	//random number
	/*to find out which is the most card player has*/
	int big[3] = { 0,0,0 };
	int bigName[3] = { 0,1,2 };
	string bigNamestr[3];
	int row[5] = { 0,0,0,0,0 };
	int stop[5] = { 0,0,0,0,0 };
	char banRow[5] = { ' ',' ',' ',' ',' ' };	//after picking the row, player cannot put card on that row
	int temp = 0;
	int name = 0;
	void cardOrder();
	int giveCard();
	int howMany(int, int);
	string checkcard(int);
	void inputA();
	bool checkInput(int, char);
	void draw();
	void inputB();
	void putToRow();
	void getRow(char, int);
	void frameForFive();
	void output(int, int);
	void computer(int);
	void computerDraw(int);
	void startCard();
	int countScoreAI(int);
	void endRound(int);
	void people();
public:
	void play();
};
class ThreePlayers {
private:
	int card[67];	
	int takeTimes = 0;	
	char choose[100];	
	char ch[100];
	int outputNumber[3][8] = { 0 };
	string nextCard;	
	string row1[3];
	string row2[3];
	string row3[3];
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;
	int randN;
	int big[3] = { 0,0,0 };
	int bigName[3] = { 0,1,2 };
	string bigNamestr[3];
	int row[3] = { 0,0,0 };
	int stop[3] = { 0,0,0 };
	char banRow[3] = { ' ',' ',' ' };
	int temp = 0;
	int name = 0;
	void cardOrder();
	int giveCard();
	int howMany(int, int);
	string checkcard(int);
	void inputA();
	bool checkInput(int, char);
	void draw();
	void inputB();
	void putToRow();
	void getRow(char, int);
	void FrameForThree();
	void output(int, int);
	void computer(int);
	void computerDraw(int);
	void startCard();
	int countScoreAI(int);
	void endRound(int);
	void people();
public:
	void play();
};