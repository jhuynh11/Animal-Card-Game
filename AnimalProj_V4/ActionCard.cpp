/*
 * ActionCard.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle
 */

#include "ActionCard.h"


void ActionCard::printRow(EvenOdd printState) const{
	//If input is default, fetch the current printstate stored in the card
	if (printState == EvenOdd::DEFAULT){
		printState = this->printState;
	}
	//Print desired row
	//TODO: Remember to set the print state of the animal card to the next row after calling this.
	if(printState == EvenOdd::EVEN){
		std::cout << toupper(cardValues[0][0]) <<" " << toupper(cardValues[0][1]);
	}else{ //(printState == EvenOdd::ODD)
		std::cout << toupper(cardValues[1][0]) << " "<< toupper(cardValues[1][1]);
	}
}


