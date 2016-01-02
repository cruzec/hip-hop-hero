  /**************************************************
 * Author: Eric Cruz
 * Date: 12/1/2014
 * Last Modification Date: 
 * File name: main.cpp
 *
 * Overview:	This program is a text-based simulation game of a
 *						rapper. The rapper has attributes such as money,
 *						hitpoints, reputation, and microphone skills. These
 *						attributes can be increased by simulated events such
 *						as selling mixtapes, making music videos, using the 
 *						jacuzzi, or rap battling other rappers. The goal of the
 *						game is to accrue as much reputation, microphone skills,
 *						and money as possible. This game was loosely inspired
 *						by games such as Pokemon and Oregon Trail.
 *
 * Input:  		The user inputs a rapper name and inputs integers to
 *						choose different activities the rapper can do. Upon 
 *						run time, the user can name the save file to record
 *						rapper attributes.
 *
 * Output:		The function outputs the outcomes for each scenario
 *						along with the effect of the scenario on the rapper's
 *						attributes.
 *        
 * **************************************************/
 
 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 #include <string>
 #include <cstring>
 #include <fstream>
 #include <sstream>
 #include "game.h"
 #include "events.h"
 
 using std::cout;
 using std::cin;
 using std::endl;
 using std::string;
 using std::ofstream;
 using std::ios;
 
 //----------------------------------------------------------------------
 //	Requirement #06: Logic, syntax, and run-time errors
 //
 // Logic - errors that occur after the program is running that yield
 //		the wrong results.
 // 
 // Syntax - errors that occur while writing the code when the syntax 
 //   	(grammar rules) of the language is not used correctly. 
 //
 //	Run-time - errors that occur after compiling and running the
 // 	code that cause the program to not work.
 //----------------------------------------------------------------------
 
 //----------------------------------------------------------------------
 //	Requirement #15: Demonstrate command-line argument
 //----------------------------------------------------------------------
 int main(int argc, char *argv[])
 {
	//----------------------------------------------------------------------
	//	Requirement #12: Demonstrate string
	//----------------------------------------------------------------------
	string fileName;
	string saveFile = "filename.txt";
	if(argc == 2)
	{
		fileName = argv[1];
		saveFile = fileName + ".txt";
	}
	
	//----------------------------------------------------------------------
	//	Requirement #23: Demonstrate file IO
	//----------------------------------------------------------------------
	ofstream gameRecord(saveFile.c_str(), ios::app);
 
	int seed;
	seed = time(0);
	srand(seed);
	
	//----------------------------------------------------------------------
	//	Requirement #14: Demonstrate multi-dimension aarray
	//----------------------------------------------------------------------
	string rivalNames[6][5] = {
											{"Shaolin Keith", "Smooch Da Snuggla", "Ol' Slippery Bathtub", "Cool and Motivated Lord", "Thankful Paul"},
											{"Diligent Intern", "Da Reasonable Pontiff", "Rhino Serious", "Really Tall Baller", "Speculation Sam"},
											{"H.U.N.C.H.B.A.C.K.", "Inverted Skroll", "lowercase christ", "Engrossin' Page Turnah","Crumb Factory"},
											{"Grownup Judge", "L.A.N.C.E. The Garbage", "Manny McPhee", "Ghostleg", "Extreme Dog Sitter"},
											{"Lil' Parrot", "Young Diaper", "Novice Weightlifter", "Assertive Interior Designer", "Master Jasper"},
											{"Level 57 Mage", "Favorite Grandchild", "Hip Elderly Man", "Responsible Pet Owner", "xXshyboy92Xx"}
										};
	
	//----------------------------------------------------------------------
	//	Requirement #14: Demonstrate dynamic multi-dimension aarray
	//----------------------------------------------------------------------	
	int **dynArray = new int*[5];
	for(int i = 0; i < 5; i++)
	{
		dynArray[i] = new int[5];
	}
	
	for(int i = 0; i < 5; i++)
	{
		for(int u = 0; u < 5; u++)
		{
			dynArray[i][u] = 1985 + i + u;
		}
	}
	
	int row = rand() % 5;
	int column = rand() % 5;
 
	//----------------------------------------------------------------------
	//	Requirement #16: Demonstrate use of object
	//----------------------------------------------------------------------
	Hero you;
	Events journey;
	string alias;
	//----------------------------------------------------------------------
	//	Requirement #12: Demonstrate C-style string
	//----------------------------------------------------------------------
	char choice[1000];
	int fixedChoice;
	
	//----------------------------------------------------------------------
	//	Requirement #01: Demonstrate simple output
	//----------------------------------------------------------------------
	cout << "Welcome to Hip Hop Hero: The Text Adventure!" << endl << endl;
	cout << "It is the year " << dynArray[row][column] << "." << endl;
	
	for(int i = 0; i < 5; i++)
	{
		delete [] dynArray[i];
	}
	delete [] dynArray;
	
	cout << "After a few years of college, you decide to drop out and become a world-class rapper." << endl;
	cout << "What is your hip hop alias?" << endl;
	
	//----------------------------------------------------------------------
	//	Requirement #25: Demonstrate exceptions
	//----------------------------------------------------------------------
	try
	{
		getline(cin, alias);
		if(alias.length() < 1)
			throw alias;
	}
	
	catch(string)
	{
		cout << "You need a name. Terminating game." << endl;
		return 0;
	}
	
	you.setName(alias);
	cout << endl << "Hello, " << you.getName() << "!" << endl;
	cout << "Which item would you like to bring on your journey?" << endl;
	cout << "1. Sack of money" << endl;
	cout << "2. Gold chain" << endl;
	cout << "3. Bullet-proof vest" << endl;
	cout << "4. Iron microphone " << endl;
	cout << "5. Quit game" << endl;
	
	cin.getline(choice, 1000);
	Cruze::validateChoice(choice, fixedChoice);
	
	switch(fixedChoice)
	{
		case 1: you.setMoney(1000);
					cout << endl << "Your cash money increases!" << endl;
					break;
		case 2: you.setReputation(25);
					cout << endl << "Your reputation increases!" << endl;
					break;
		case 3: you.setHitpoints(200);
					cout << endl << "Your hitpoints increase!" << endl;
					break;
		case 4: you.setMicSkills(50);
					cout << endl << "Your microphone skills increase!" << endl;
					break;
		case 5: cout << "Game over. All the swag you gained is now gone." << endl;
					Cruze::saveGame(gameRecord, you);
					gameRecord.close();
					return 0;
	}
	
	//----------------------------------------------------------------------
	//	Requirement #04: Demonstrate a loop
	//----------------------------------------------------------------------	
	do
	{
		cout << endl;
		cout << "What would you like to do now, " << alias << "?" << endl;
		cout << "1. Sell some fresh mixtapes" << endl;
		cout << "2. Make some dope music videos" << endl;
		cout << "3. Hit the jacuzzi" << endl;
		cout << "4. Get into a rap battle" << endl;
		cout << "5. Quit game" << endl;
		
		cin.getline(choice, 1000);
		Cruze::validateChoice(choice, fixedChoice);
		
		switch(fixedChoice)
		{
			case 1: journey.makeMixtapes(you);
						break;
			case 2: journey.makeMusicVideos(you);
						break;
			case 3: journey.hitJacuzzi(you);
						break;
			case 4: journey.rapBattle(you, rivalNames);
						break;
			case 5: cout << endl << "Game over. All the swag you earned is now gone." << endl;
						Cruze::saveGame(gameRecord, you);
						gameRecord.close();
						return 0;
		}
		
		if((rand() % 10) == 0)
		{
			journey.randomEvent(you);
		}
		
		if(you.getMoney() < 0)
		{
			Cruze::loseGame();
			Cruze::saveGame(gameRecord, you);
			fixedChoice = 5;
		}
		else if(you.getReputation() < 0)
		{
			Cruze::loseGame(you.getReputation());
			Cruze::saveGame(gameRecord, you);
			fixedChoice = 5;
		}
	
	//----------------------------------------------------------------------
	//	Requirement #03: Demonstrate logical operators
	//----------------------------------------------------------------------	
	} while(fixedChoice != 5 && fixedChoice < 5);
	
	gameRecord.close();
	
	return 0;
 }