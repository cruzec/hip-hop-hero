 /**************************************************
 * Author: Eric Cruz
 * Date: 12/1/2014
 * Last Modification Date: 
 * File name: events.h
 *
 * Overview:	This is the header file for the classes, functions, and
 *						variables used in events.cpp.
 *
 * Input:  		none
 *
 * Output:		none
 *        
 * **************************************************/

 #ifndef EVENTS_H
 #define EVENTS_H
 
 #include <string>
 
 #include "game.h"
 
 using std::string;
 
 struct Items;
 
 class Events
 {
	public:
		void makeMixtapes(Hero&);
		void makeMusicVideos(Hero&);
		void hitJacuzzi(Hero&);
		void rapBattle(Hero&, string people[][5]);
		void randomEvent(Hero&);
 };
 
 #endif