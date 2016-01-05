/*
* Player.cpp
*
*  Created on: Nov 23, 2015
*      Author: Kyle, Justin
*/

#include "Player.h"

Player::Player(std::string _name, std::string secretAnimal) : name(_name) , hand(Hand()), secretAnimal(secretAnimal){

}
Player::Player() : name(), hand(Hand()), secretAnimal(){
}
std::string Player::swapSecretAnimal(std::string& swapAnimal) {
	std::string old = secretAnimal;
	secretAnimal = swapAnimal;
	return old;
}

std::string Player::getName(){
	return name;
}

std::string Player::getSecretAnimal() {
	return secretAnimal;
}
