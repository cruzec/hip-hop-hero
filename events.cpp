 /**************************************************
 * Author: Eric Cruz
 * Date: 12/1/2014
 * Last Modification Date: 
 * File name: game.cpp
 *
 * Overview:	This program defines the class used in main.cpp.
 *						The class Events contains the different scenarios
 *						the user's character can do along with the changes
 *						to its attributes.
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
 
 #include "events.h"
 #include "game.h"
 
 using std::cout;
 using std::cin;
 using std::endl;
 using std::string;
 
 //----------------------------------------------------------------------
 //	Requirement #16: Demonstrate use of struct
 //----------------------------------------------------------------------
 struct Items
 {
	int bonusHP;
	double bonusMoney;
	int bonusRep;
	int bonusSkills;
 };
 
 /**************************************************
 *
 * 	Entry:		"person" is the Hero rapper object
 *
 * 	Exit:			adds or subtracts money from the object
 *
 * Purpose:		The purpose of this function is to simulate a rapper
 * 					selling mixtapes from the trunk of a car and either
 *					making money or losing money.
 *        
 * **************************************************/
 //----------------------------------------------------------------------
 //	Requirement #11: Demonstrate pass by reference
 //----------------------------------------------------------------------
 void Events::makeMixtapes(Hero &person)
 {	
	int sales = rand() % 200 + 1;
 
	if((rand() % 2) == 0)
	{
		cout << endl << "You sold the mixtapes at a profit!" << endl;
		cout << "$" << sales << " goes into your pocket" << endl;
		person.addMoney(sales);
	}
	else
	{
		cout << endl << "You sold the mixtapes at a deficit." << endl;
		cout << "$" << sales << " leaves your pocket" << endl;
		person.addMoney((-1) * sales);
	}
	
	person.printAttributes();
 }
 
 /**************************************************
 *
 * 	Entry:		"person" is the Hero rapper object
 *
 * 	Exit:			adds or substracts reputation from the object
 *
 * Purpose:		The purpose of this function is to simulate a rapper
 * 					making music videos and either gaining popularity
 *					or losing popularity.
 *        
 * **************************************************/
 void Events::makeMusicVideos(Hero &person)
 {
	int views = rand() % 10 + 1;
	
	if((rand() % 2) == 0)
	{
		cout << endl << "People are loving your new video!" << endl;
		cout << "Your reputation increases by " << views << endl;
		person.addReputation(views);
	}
	else
	{
		cout << endl << "People are hating on your new video." << endl;
		cout << "Your reputation decreases by " << views << endl;
		person.addReputation((-1) * views);
	}
	
	person.printAttributes();
 }

 /**************************************************
 *
 * 	Entry:		"person" is the Hero rapper object
 *
 * 	Exit:			adds or substracts hitpoints from the object
 *
 * Purpose:		The purpose of this function is to simulate a rapper
 * 					relaxing in a jacuzzi with friends and either gaining
 *					health or losing health.
 *        
 * **************************************************/
 void Events::hitJacuzzi(Hero &person)
 {
	int relaxation = rand() % 30;
	
	if((rand() % 2) == 0)
	{
		cout << endl << "The jacuzzi was enjoyable!" << endl;
		cout << "Your hitpoints increase by " << relaxation << endl;
		person.addHitpoints(relaxation);
	}
	else
	{
		cout << endl << "The jacuzzi was too hot." << endl;
		cout << "Your hitpoints decrease by " << (relaxation / 2) << endl;
		person.addHitpoints((-1) * relaxation / 2);
	}
	
	person.printAttributes();
 }
 
 /**************************************************
 *
 * 	Entry:		"person" is the Hero rapper object
 *
 * 	Exit:			adds or substracts money and/or reputation from 
 *					the object
 *
 * Purpose:		The purpose of this function is to simulate a rapper
 * 					freestyle rapping against another rapper and either
 *					winning money and fame or losing money and fame.
 *        
 * **************************************************/
 void Events::rapBattle(Hero &person, string array[][5])
 {
	int i = rand() % 6;
	int u = rand() % 5;
	string rivalName = array[i][u];
	int repGained = rand() % 4;
	Rival opponent;
	opponent.setName(rivalName);
	
	cout << endl << "You challenge " << rivalName << " to a rap battle!" << endl;
	
	if(opponent.getReputation() > person.getReputation())
	{
		while(opponent.getHitpoints() > 0 && person.getHitpoints() > 0)
		{
			opponent.addHitpoints((-1) * person.getDamage());
			cout << endl;
			person.addHitpoints((-1) * opponent.getDamage());
			cout << endl;
		}
		
		if(opponent.getHitpoints() < 0)
		{
			cout << "You defeated " << rivalName << "!" << endl;
			person.addMoney(opponent.getMoney());
			cout << "You gain $" << opponent.getMoney() << "." << endl;
			person.addReputation(repGained);
			cout << "You gain " << repGained << " reputation." << endl;
		}
		else if(person.getHitpoints() < 0)
		{
			cout << "You have been defeated by " << rivalName << "." << endl;
			person.addReputation(-15);
			cout << "Your reputation decreased by 15" << endl;
		}
	}
	else if(opponent.getReputation() <= person.getReputation())
	{
		cout << array[i][u] << " wants to squash the beef and give you money instead of rap battling." << endl;
		person.addMoney(opponent.getMoney());
		person.setHitpoints(45);
		cout << array[i][u] << " gives you $" << opponent.getMoney() << "!" << endl;
	}
	
	person.printAttributes();
 }
 
 /**************************************************
 *
 * 	Entry:		"person" is the Hero rapper object
 *
 * 	Exit:			adds or substracts from the objects attributes
 *
 * Purpose:		The purpose of this function is to simulate a rapper
 * 					gaining groupies and finding new items to increase
 *					attributes.
 *        
 * **************************************************/
 void Events::randomEvent(Hero &person)
 {
	string bonus[10] = {"Set of Dual-wield Microphones", "Golden Monocle", "Set of Golden Toe Rings", "Golden Anklet", "Satin Top Hat",
								 "Pair of Cool Goggles", "Polka Dot Limo", "Pet Snake", "Pair of Diamond Rollerskates", "Swag Cape"};
							
	int itemNum = rand() % 10;
	Items freebie;
	freebie.bonusHP = rand() % 20 + 1;
	freebie.bonusMoney = rand() % 100 + 1;
	freebie.bonusRep = rand() % 10 + 1;
	freebie.bonusSkills = rand() % 10 + 1;
 
	if((rand() % 2) == 0)
	{
		Groupie pal;
		cout << endl << "You gained a new groupie!" << endl;
		person += pal;
		cout << "Each new groupie increases your stats." << endl;
		person.printAttributes();
	}
	else
	{
		cout << endl << "You found a " << bonus[itemNum] << endl;
		person.addMoney(freebie.bonusMoney);
		person.addHitpoints(freebie.bonusHP);
		person.addReputation(freebie.bonusRep);
		person.addMicSkills(freebie.bonusSkills);
		cout << "Each new item increases your stats." << endl;
		person.printAttributes();
	}
 }