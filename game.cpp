 /**************************************************
 * Author: Eric Cruz
 * Date: 12/1/2014
 * Last Modification Date: 
 * File name: game.cpp
 *
 * Overview:	This program defines the classes and functions used
 *						in main.cpp. This includes classes for the game
 *						characters, functions for input validation, and functions
 *						for quitting the game.
 *
 * Input:  		none
 *
 * Output:		none
 *        
 * **************************************************/
 
 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 #include <string>
 #include <cstring>
 #include <fstream>
 
 #include "game.h"
 
 using std::cout;
 using std::cin;
 using std::endl;
 using std::string;
 using std::ofstream;
 
 //----------------------------------------------------------------------
 //	Requirement #21: Demonstrate default constructor
 //----------------------------------------------------------------------
 // Default constructor for Rapper base class
 Rapper::Rapper()
 {
	hitpoints = 100;
	reputation = 10;
	money = 250.0;
	micSkills = 20;
 }
 
 //----------------------------------------------------------------------
 //	Requirement #21: Demonstrate destructor
 //----------------------------------------------------------------------
 // Destructor
 Rapper::~Rapper()
 {
	// deliberately empty
 }
 
 // Assigns the name
 void Rapper::setName(string n)
 {
	name = n;
 }
 
 // Assigns the hitpoints
 void Rapper::setHitpoints(int h)
 {
	hitpoints = h;
 }
 
 // Assigns the reputation
 void Rapper::setReputation(int r)
 {
	reputation = r;
 }
 
 // Assigns the mic skills
 void Rapper::setMicSkills(int m)
 {
	micSkills = m;
 }
 
 // Assigns the money amount
 void Rapper::setMoney(double dollars)
 {
	money = dollars;
 }
 
 // Returns the name
 string Rapper::getName()
 {
	return name;
 }
 
 // Returns the hitpoints
 int Rapper::getHitpoints()
 {
	return hitpoints;
 }
 
 // Returns the reputation
 int Rapper::getReputation()
 {
	return reputation;
 }
 
 // Returns the mic skills
 int Rapper::getMicSkills()
 {
	return micSkills;
 }
 
 // Returns the money amount
 double Rapper::getMoney()
 {
	return money;
 }
 
 //----------------------------------------------------------------------
 //	Requirement #11: Demonstrate pass by value
 //----------------------------------------------------------------------
 // Increases/decreases hitpoints
 void Rapper::addHitpoints(int hp)
 {
	hitpoints += hp;
 }
 
 // Increases/decreases reputation
 void Rapper::addReputation(int rep)
 {
	reputation += rep;
 }
 
 // Increases/decreases mic skills
 void Rapper::addMicSkills(int skills)
 {
	micSkills += skills;
 }
 
 // Increases/decreases money
 void Rapper::addMoney(double cash)
 {
	money += cash;
 }
 
 /**************************************************
 *
 * 	Entry:		none
 *
 * 	Exit:			Returns the damage inflicted
 *
 * Purpose:		The purpose of this function is to calculate and return
 *					the damage inflicted by the rapper.
 *        
 * **************************************************/
 int Rapper::getDamage()
 {
	int damage = rand() % micSkills + 1;
	cout << name << "\'s rhymes inflicted " << damage << " damage!" << endl;
	return damage;
 }
 
 /**************************************************
 *
 * 	Entry:		none	
 *
 * 	Exit:			prints the rapper's attributes
 *
 * Purpose:		The purpose of this function is to display the current
 *					attributes to the user.
 *        
 * **************************************************/
 void Rapper::printAttributes()
 {
	cout << endl << "----------------------" << endl;
	cout << "Cash money: $" << money << endl;
	cout << "Hitpoints: " << hitpoints << endl;
	cout << "Reputation: " << reputation << endl;
	cout << "Mic Skills: " << micSkills << endl;
	cout << "----------------------" << endl;
 }
 
 /**************************************************
 *
 * 	Entry:		none
 *
 * 	Exit:			returns the damage done by the Hero rapper	
 *
 * Purpose:		The purpose of this function is to calculate and display
 *					the damage inflicted by the Hero rapper.
 *        
 * **************************************************/
 int Hero::getDamage()
 {
	int damage = rand() % micSkills + 1;
	
	if((rand() % 10) == 0)
	{
		cout << name << "\'s signature ultra-diss causes critical damage!" << endl;
		damage = damage;
		int damage2 = getSpecialDamage(micSkills / 4);
		damage += damage2;
		cout << name << "\'s rhymes inflicted a total of " << damage << " damage!" << endl;
		return damage;
	}
	else
	{
		cout << name << "\'s rhymes inflicted " << damage << " damage!" << endl;
		return damage;
	}
 }
 
 /**************************************************
 *
 * 	Entry:		"rhymes" is the mic skills attribute of the Hero rapper
 *
 * 	Exit:			returns the additional damage done by the Hero rapper
 *
 * Purpose:		The purpose of this function is to calculate and display
 *					the Hero rapper's special extra damage.
 *        
 * **************************************************/
 //----------------------------------------------------------------------
 //	Requirement #13: Demonstrate recursion
 //----------------------------------------------------------------------	
 int Hero::getSpecialDamage(int rhymes)
 {
	//----------------------------------------------------------------------
	//	Requirement #10: Demonstrate scope
	//----------------------------------------------------------------------
	
	while(rhymes > 1)
	{
		return (rhymes + getSpecialDamage(rhymes - 1));
	}
	
	if(rhymes == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
 }
 
 
 /**************************************************
 *
 * 	Entry:		"buddy" is the Groupie to be added to the Hero rapper'saveGame
 *					posse
 *
 *	Exit:			adds the Groupie's attributes to the Hero rapper's
 *
 * Purpose:		The purpose of this function is to add the attributes
 *					to the Hero rapper's in the event of Groupie addition
 *        
 * **************************************************/
 //----------------------------------------------------------------------
 //	Requirement #22: Demonstrate overloaded operator
 //----------------------------------------------------------------------
 Hero& Hero::operator+=(Rapper &buddy)
 {
	money += buddy.getMoney();
	reputation += buddy.getReputation();
	hitpoints += buddy.getHitpoints();
	micSkills += buddy.getMicSkills();
	//----------------------------------------------------------------------
	//	Requirement #17: Demonstrate pointer to object
	//----------------------------------------------------------------------
	return *this;
 }
 
 // Default constructor for Groupie derived class
 Groupie::Groupie()
 {
	hitpoints = 50;
	reputation = 5;
	money = 100.0;
	micSkills = 5;
 }
 
 // Destructor
 Groupie::~Groupie()
 {
	// deliberately empty
 }
 
 // Default constructor for Rival derived class
 Rival::Rival()
 {
	hitpoints = rand() % 75 + 1;
	reputation = rand() % 200 + 1;
	money = rand() % 50 + 1;
	micSkills = rand() % 20 + 1;
 }
 
 // Destructor
 Rival::~Rival()
 {
	// deliberately empty
 }
 
 //----------------------------------------------------------------------
 //	Requirement #18: Demonstrate custom namespace
 //----------------------------------------------------------------------
 namespace Cruze
 {
	/**************************************************
	*
	* Entry:			"*gameChoice" is the input from the user, and 
	*					"realChoice" is the integer conversion of the user choice
	*
	* Exit:			converts the user's input to an integer
	*
	* Purpose:		The purpose of this function is to validate the user
	*					input and convert it to an integer for the switch-case
	*					statements
	*        
	* **************************************************/
	//----------------------------------------------------------------------
	//	Requirement #07: Demonstrate error-handling
	//----------------------------------------------------------------------	
	void validateChoice(char *gameChoice, int &realChoice)
	{
		realChoice = atoi(gameChoice);
	 
		while(strlen(gameChoice) != 1 || (realChoice != 1 && realChoice != 2 && realChoice != 3 && realChoice != 4 && realChoice != 5))
		{
			cout << "Invalid input. Please enter the number 1, 2, 3, 4, or 5: ";
			cin.getline(gameChoice, 1000);
			realChoice = atoi(gameChoice);
		}
	}
	
	/**************************************************
	*
	* Entry:			none
	*
	* Exit:			prints that the user lost in the event that the user's
	*					money is 0 or lower
	*
	* Purpose:		The purpose of this function is to print that the user 
	*					lost when he or she has $0 or less.
	*        
	* **************************************************/
	void loseGame()
	{
		cout << endl << "You went bankrupt. Game over." << endl;
	}
	
	/**************************************************
	*
	* Entry:			none
	*
	* Exit:			prints that the user lost in the event that the user's
	*					reputation is 0 or lower
	*
	* Purpose:		The purpose of this function is to print that the user 
	*					lost when he or she has less than 0 reputation
	*        
	* **************************************************/
	//----------------------------------------------------------------------
	//	Requirement #08: Demonstrate a function and overloaded function
	//----------------------------------------------------------------------		
	void loseGame(int)
	{
		cout << endl << "Your street cred has fallen, and it can't get up. Game over." << endl;
	}
	
	/**************************************************
	*
	* Entry:			"record" is the ofstream file, and "your" is the 
	*					Hero rapper object.
	*
	* Exit:			Records the attributes of the user's Hero rapper
	*					at the end of the game
	*
	* Purpose:		The purpose of this function is to save the Hero
	*					rapper's attributes in an output file
	*        
	* **************************************************/
	//----------------------------------------------------------------------
	//	Requirement #09: Demonstrate functional decomposition
	//----------------------------------------------------------------------	 
	void saveGame(ofstream &record, Rapper your)
	{
		cout << endl << "Save stats? (y/n)" << endl;
		string gameSave;
		getline(cin, gameSave);
		
		//----------------------------------------------------------------------
		//	Requirement #02: Demonstrate type casting
		//----------------------------------------------------------------------	 
		double cashMoney = your.getMoney();
		int dollars = (int)cashMoney;
		
		if(gameSave[0] == 'y' || gameSave[0] == 'Y')
		{
			record << endl << "----------------------" << endl;
			record << "Rapper name: " << your.getName() << endl;
			record << "Cash money: $" << dollars << endl;
			record << "Hitpoints: " << your.getHitpoints() << endl;
			record << "Reputation: " << your.getReputation() << endl;
			record << "Mic Skills: " << your.getMicSkills() << endl;
			record << "----------------------" << endl;
		}
	}
 }