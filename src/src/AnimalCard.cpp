/*
 * AnimalCard.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle
 */

#include "AnimalCard.h"

AnimalCard::AnimalCard(): printState(EvenOdd::EVEN), cardOrientation(Orientation::UP){
}

//constructor that aes an 2d char array as an input
AnimalCard::AnimalCard(char initalizer[2][2]): printState(EvenOdd::EVEN), cardOrientation(Orientation::UP){
	for(int i = 0; i<2; ++i){
		for(int j = 0; j<2; ++j){
			cardValues[i][j] = initalizer[i][j];
		}
	}
}
//sets the orientation of the card
void AnimalCard::setOrientation(Orientation newOrientation){
	if(cardOrientation == newOrientation){
		return;								//if orientation is the same, don't do anything
	}
	cardOrientation = newOrientation;
	char temp;
	temp = cardValues[0][0];
	cardValues[0][0] = cardValues[1][1];
	cardValues[1][1] = temp;
	temp = cardValues[0][1];
	cardValues[0][1] = cardValues[1][0];
	cardValues[1][0] = temp;

}

EvenOdd AnimalCard::getRow() const{
	return printState;
}

void AnimalCard::setRow(EvenOdd printState){
	if(printState != EvenOdd::DEFAULT){
		this->printState = printState;
	}
}

//prints the specified row
void AnimalCard::printRow(EvenOdd printState) const{
	//If input is default, fetch the current printstate stored in the card
	if (printState == EvenOdd::DEFAULT){
		printState = this->printState;
	}
	//Print desired row
	if(printState == EvenOdd::EVEN){
		std::cout << cardValues[0][0] <<" " << cardValues[0][1];
	}else{ //(printState == EvenOdd::ODD)
		std::cout << cardValues[1][0] << " "<< cardValues[1][1];
	}
}

/*check if two animal cards are the same, we assume a card that is upright vs a card that is upside down the same
 * if it's in the case of : a b         vs     		d c
 * 							c d					    b a
 */
bool AnimalCard::operator==(AnimalCard& other){
	return ((cardValues[0][0] == other.cardValues[0][0] && cardValues[0][1] == other.cardValues[0][1]
			&& cardValues[1][0] == other.cardValues[1][0] && cardValues[1][1] == other.cardValues[1][1]) || //check if each cell are identical + orientation
			(cardValues[0][0] == other.cardValues[1][1] && cardValues[0][1] == other.cardValues[1][0]
			&& cardValues[1][0] == other.cardValues[0][1] && cardValues[1][1] == other.cardValues[0][0])); //check if two cards are identical but just in opposite orientation
}

//check if an animal is contained in the card;
bool AnimalCard::contain(std::string animal){
	char firstChar = tolower(animal[0]);		//takes fist char and cast it to lowercase
	return (firstChar == cardValues[0][0] || firstChar == cardValues[0][1] ||
			firstChar == cardValues[1][0] || firstChar == cardValues[1][1]);
}

int AnimalCard::nextToNumOfAnimals(std::shared_ptr<AnimalCard> top, std::shared_ptr<AnimalCard> left,
					   std::shared_ptr<AnimalCard> right, std::shared_ptr<AnimalCard> bottom){
	if (contain("Joker")){
		return 1;
	}
	int counter = 0;
	//checks if each corner has an adjacent card with the same animal or joker
	bool results[2][2] = {false,false,false,false};

	//check top left corner
	if(top && left){
		if(cardValues[0][0] == top->cardValues[1][0] || cardValues[0][0] == left->cardValues[0][1]
		|| top->contain("Joker") || left->contain("Joker")){
			results[0][0] = true;
		}
	}
	//check top right corner
	if(top && right){
		if(cardValues[0][1] == top->cardValues[1][1] || cardValues[0][1] == right->cardValues[0][0]
		|| top->contain("Joker") || right->contain("Joker")){
			results[0][1] = true;
		}
	}
	//check bottom left corner
	if(bottom && left){
		if(cardValues[1][0] == bottom->cardValues[0][0] || cardValues[1][0] == left->cardValues[1][1]
		|| bottom->contain("Joker") || left->contain("Joker")){
			results[1][0] = true;
		}
	}
	//check bottom right corner
	if(bottom && right){
		if(cardValues[1][1] == bottom->cardValues[0][1] || cardValues[1][1] == right->cardValues[1][0]
		|| bottom->contain("Joker") || right->contain("Joker")){
			results[1][1] = true;
		}
	}

	//use these booleans to avoid over counting number of animal seen

	bool seenBear(false), seenDeer(false),seenMoose(false),seenHare(false),seenWolf(false);

	for(int i = 0; i<2; ++i){
		for(int j = 0; j<2; ++j){
			if(results[i][j]){
				switch(cardValues[i][j]){
					case 'b':
						seenBear = true;
						break;
					case 'd':
						seenDeer = true;
						break;
					case 'm':
						seenMoose = true;
						break;
					case 'h':
						seenHare = true;
						break;
					case 'w':
						seenWolf = true;
						break;
				}
			}
		}
	}
	//use boolean to int conversion and add up the counter
	counter += seenBear;
	counter += seenDeer;
	counter += seenMoose;
	counter += seenHare;
	counter += seenWolf;

	return counter;

}



