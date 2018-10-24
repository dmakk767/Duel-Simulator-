// Ch4Num12.cpp : Defines the entry point for the console application.
//

//See ReadMe for description


#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int normalMode ();
int altMode();

int main()
{
	//setup 
	char cont = 'n';
	int mode = 0;
	//make loop to continue program by user input
	do
	{
		//get mode from user
		cout << endl << "Please choose a mode.\n Enter 1 for 'Normal Mode'\n Enter 2 for 'Miss Once Mode'" << endl;
		cin >> mode;
		//determine and run correct mode
		if (mode == 1) {
			normalMode();
		}
		else if (mode == 2) {
			altMode();
		}
		else { break; }
		cout << "enter 'y' to run simulation again." << endl;
		cin >> cont;
		cont = toupper(cont);
	} while (cont == 'Y');
    return 0;

}

int normalMode() {
	//set bool for each player. TRUE = alive, FALSE = dead
	bool aaron = true, bob = true, charlie = true;
	//seed the random num gen with time
	srand(static_cast<unsigned int>(time(0)));
	//set variables
	int aaronWins = 0, bobWins = 0, charlieWins = 0;
	for (int i = 0; i < 10000; i++)
	{
		do {
			int shotFired = 0;
			//see if aaron is alive
			if (aaron)
			{
				//aaron takes a shot at 30% - #2 will be a deadly shot.
				shotFired = rand() % 3 + 1;
				//test // cout << shotFired << "aaron Shot fired" << endl;
				//if shot is hit have aaron take out other player
				if (shotFired == 2) {
					if (charlie) {
						charlie = false;
						//test the progress // cout << "arron killed charlie" << endl;
					}
					else if (bob) {
						bob = false;
						//test the progress // cout << "arron killed bob" << endl;
					}
					else { break; }
				}
			}
			//move to bob with 2 as a hit
			//see if bob is alive
			if (bob)
			{
				shotFired = rand() % 2 + 1;
				//test the progress // cout << shotFired << "bob Shot fired" << endl;
				//make bob hit people
				if (shotFired == 2) {
					if (charlie) {
						charlie = false;
						//test the progress // cout << "bob killed charlie" << endl;
					}
					else if (aaron) {
						aaron = false;
						//test the progress // cout << "bob killed arron" << endl;
					}
					else { break; }
				}
			}
			//move on to charlie's turn
			//see is charlie is alive
			if (charlie)
			{
				if (bob) {
					bob = false;
					//test the progress // cout << "charlie killed bob" << endl;
				}
				else if (aaron) {
					aaron = false;
					//test the progress // cout << "charlie killed aaron" << endl;
				}
				else { break; }
			}
			//test the progress // cout << "aaron is " << aaron << " bob is " << bob << " charlie is " << charlie << endl;
		} while (((aaron) && (bob)) || ((aaron) && (charlie)) || ((bob) && (charlie)));
		//tracks wins 
		if (aaron) { aaronWins++; }
		else if (bob) { bobWins++; }
		else if (charlie) { charlieWins++; }
		/*
		if (aaron) { cout << "Arron is the best puzzle solver of all time." << endl; }
		else if (bob) { cout << "Bob is the best puzzle solver of all time." << endl; }
		else if (charlie) { cout << "Charlie is the best puzzle solver of all time." << endl; }
		else { cout << "ERROR...ERROR" << endl; }
		*/
		//reset lives
		aaron = true, bob = true, charlie = true;
	}

	//print result
	cout << endl << "Aaron won " << aaronWins << "/10,000 duels, or " << (float(aaronWins) / 100.0f) << "% of the time." << endl;
	cout << endl << "Bob won " << bobWins << "/10,000 duels, or " << (float(bobWins) / 100.0f) << "% of the time." << endl;
	cout << endl << "Charlie won " << charlieWins << "/10,000 duels, or " << (float(charlieWins) / 100.0f) << "% of the time." << endl << endl;

	return aaronWins, bobWins, charlieWins;
	//print out winner
	//if (aaron) { cout << "Arron is the best puzzle solver of all time." << endl; }
	//else if (bob) { cout << "Bob is the best puzzle solver of all time." << endl; }
	//else if (charlie) { cout << "Charlie is the best puzzle solver of all time." << endl; }
	//else { cout << "ERROR...ERROR" << endl; }
	
}

int altMode() {
	//set bool for each player. TRUE = alive, FALSE = dead
	bool aaron = true, bob = true, charlie = true;
	//seed the random num gen with time
	srand(static_cast<unsigned int>(time(0)));
	//set variables
	int aaronWins = 0, bobWins = 0, charlieWins = 0;
	for (int i = 0; i < 10000; i++)
	{
		do {
			int shotFired = 0;
			//see if aaron is alive
		
			//move to bob instead of aaron with 2 as a hit
			//see if bob is alive
			if (bob)
			{
				shotFired = rand() % 2 + 1;
				//test the progress // cout << shotFired << "bob Shot fired" << endl;
				//make bob hit people
				if (shotFired == 2) {
					if (charlie) {
						charlie = false;
						//test the progress // cout << "bob killed charlie" << endl;
					}
					else if (aaron) {
						aaron = false;
						//test the progress // cout << "bob killed arron" << endl;
					}
					else { break; }
				}
			}
			//move on to charlie's turn
			//see is charlie is alive
			if (charlie)
			{
				if (bob) {
					bob = false;
					//test the progress // cout << "charlie killed bob" << endl;
				}
				else if (aaron) {
					aaron = false;
					//test the progress // cout << "charlie killed aaron" << endl;
				}
				else { break; }
			}
			//now do aaron round if he is alive 
			if (aaron)
			{
				//aaron takes a shot at 30% - #2 will be a deadly shot.
				shotFired = rand() % 3 + 1;
				//test // cout << shotFired << "aaron Shot fired" << endl;
				//if shot is hit have aaron take out other player
				if (shotFired == 2) {
					if (charlie) {
						charlie = false;
						//test the progress // cout << "arron killed charlie" << endl;
					}
					else if (bob) {
						bob = false;
						//test the progress // cout << "arron killed bob" << endl;
					}
					else { break; }
				}
			}
			//test the progress // cout << "aaron is " << aaron << " bob is " << bob << " charlie is " << charlie << endl;
		} while (((aaron) && (bob)) || ((aaron) && (charlie)) || ((bob) && (charlie)));
		//tracks wins 
		if (aaron) { aaronWins++; }
		else if (bob) { bobWins++; }
		else if (charlie) { charlieWins++; }
		/*
		if (aaron) { cout << "Arron is the best puzzle solver of all time." << endl; }
		else if (bob) { cout << "Bob is the best puzzle solver of all time." << endl; }
		else if (charlie) { cout << "Charlie is the best puzzle solver of all time." << endl; }
		else { cout << "ERROR...ERROR" << endl; }
		*/
		//reset lives
		aaron = true, bob = true, charlie = true;
	}

	//print result
	cout << endl << "Aaron won " << aaronWins << "/10,000 duels, or " << (float(aaronWins) / 100.0f) << "% of the time." << endl;
	cout << endl << "Bob won " << bobWins << "/10,000 duels, or " << (float(bobWins) / 100.0f) << "% of the time." << endl;
	cout << endl << "Charlie won " << charlieWins << "/10,000 duels, or " << (float(charlieWins) / 100.0f) << "% of the time." << endl << endl;

	return aaronWins, bobWins, charlieWins;
	//print out winner
	//if (aaron) { cout << "Arron is the best puzzle solver of all time." << endl; }
	//else if (bob) { cout << "Bob is the best puzzle solver of all time." << endl; }
	//else if (charlie) { cout << "Charlie is the best puzzle solver of all time." << endl; }
	//else { cout << "ERROR...ERROR" << endl; }

}

