 /**************************************************
 * Author: Eric Cruz
 * Date: 12/1/2014
 * Last Modification Date: 
 * File name: game.h
 *
 * Overview:	This is the header file for the classes, functions, and
 *						variables used in game.cpp.
 *
 * Input:  		none
 *
 * Output:		none
 *        
 * **************************************************/
 
 //----------------------------------------------------------------------
 //	Requirement #19: Demonstrate written header file
 //----------------------------------------------------------------------
 #ifndef GAME_H
 #define GAME_H
 
 #include <string>
 #include <fstream>
 
 using std::string;
 using std::ofstream;
 
 //----------------------------------------------------------------------
 //	Requirement #16: Demonstrate use of class
 //----------------------------------------------------------------------
 class Rapper
 {
	protected:
		string name;
		int hitpoints;
		int reputation;
		double money;
		int micSkills;
	
	public:
		Rapper();
		~Rapper();
		void setName(string);
		void setHitpoints(int);
		void setReputation(int);
		void setMicSkills(int);
		void setMoney(double);
		
		string getName();
		int getHitpoints();
		int getReputation();
		int getMicSkills();
		double getMoney();
		
		void addHitpoints(int);
		void addReputation(int);
		void addMicSkills(int);
		void addMoney(double);
		
		int getDamage();
		void printAttributes();
 };
 
 //----------------------------------------------------------------------
 //	Requirement #24: Demonstrate inheritance
 //----------------------------------------------------------------------
 class Hero : public Rapper
 {
	public:
		int getDamage();
		int getSpecialDamage(int);
		Hero& operator+=(Rapper &buddy);
 };
		
 class Groupie : public Rapper
 {
	public:
		Groupie();
		~Groupie();
	
 };
 
 class Rival : public Rapper
 {
	public:
		Rival();
		~Rival();
		Rival(string, int, int, double, int);
 };
 
 namespace Cruze
 {
	void validateChoice(char*, int&);
	void loseGame();
	void loseGame(int);
	void saveGame(ofstream&, Rapper);
 }
 
 #endif