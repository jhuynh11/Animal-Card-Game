/*Kyle Kung
Justin Huynh*/

#include "Hand.h"

Hand::Hand() {
	numCards = 1;
}

Hand& Hand:: operator+= (std::shared_ptr<AnimalCard> card) {
	d_hand.push_back(card); //Place the new card at the end of the list
	numCards++;
	return *this;
}

Hand& Hand:: operator-=(std::shared_ptr<AnimalCard> card) {
	bool found;
	try {
		if (d_hand.empty())
			throw "Empty Deck";//Throw exception of type char*
		
		//Iterate through list and look for the card type, if found remove it from the list
		std::list<std::shared_ptr<AnimalCard>>::iterator iterator;
		for (iterator = d_hand.begin(); iterator != d_hand.end(); ++iterator) {
			if (*card==**iterator) { //****Check if the card classification is equal to the one in the list
				//d_hand.erase(iterator); //Remove the card at the iterators position
				iterator = d_hand.erase(iterator);
				found = true;
				numCards--; 
				return *this;
			}
		}
		throw (new MissingCardException);
	}
	catch (char* strException) {
		std::cerr << "Error: Can't remove from an empty deck" << std::endl;
		return *this;
	}
	catch (MissingCardException& e) {
		std::cerr << "Error: Card not found in hand" << std::endl;
		return *this;
	}
}

std::shared_ptr<AnimalCard> Hand::operator[](int a) {
	try {
		if (a > d_hand.size())
			throw "Out of bounds"; //No card located at that index

		//Iterate through list until position [a] is reached, then return that card
		std::list<std::shared_ptr<AnimalCard>>::iterator iterator = d_hand.begin();
		for (int i = 0; i == a; ++i) {++iterator;}
		std::shared_ptr<AnimalCard> card = *iterator;
		return card;
	}
	catch (char* sizeException) {
		std::cerr << "Error: Hand doesn't have that many cards" << std::endl;
		return nullptr;
	}
}
int Hand:: noCards() {
	return numCards;
}

Hand::~Hand() {

}

