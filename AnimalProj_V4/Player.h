/*
* Player.h
*
*  Created on: Nov 23, 2015
*      Author: Kyle, Justin
*/

#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"

class Player {
	std::string secretAnimal; 
	std::string name;


public:
	Hand hand;
	Player();
	Player(std::string, std::string secretAnimal);
	std::string swapSecretAnimal(std::string&); 
	std::string getSecretAnimal();
	std::string getName();


	//Insertion operator to print a player on ostream

	friend std::ostream &operator<< (std::ostream &output, const Player &p) {
		output << "Player : " << p.name << "  " << "Secret Animal : " << p.secretAnimal << p.hand;
		return output;
	}
};



#endif /*Player.h*/
