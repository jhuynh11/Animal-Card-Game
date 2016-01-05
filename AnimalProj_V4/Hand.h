/*
 * Hand.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle, Justin
 */

#ifndef HAND_H_
#define HAND_H_

#include<memory>
#include<list>
#include<iostream>
#include "AnimalCard.h"
#include<string>
class MissingCardException {};
class Hand {
public:
	std::list<std::shared_ptr<AnimalCard>> d_hand;//List that holds the sequence of cards

	int numCards;

	Hand();
	//adds a pointer to the AnimalCard in the hand
	Hand& operator+= (std::shared_ptr<AnimalCard>);
	//removes a card equivalent to the argument from the hand THROWS MissingCard
	Hand& operator-=(std::shared_ptr<AnimalCard>);
	//returns the AnimalCard at the given index
	std::shared_ptr<AnimalCard> operator[](int);
	int noCards(); //Returns number of cards in the hand
   
    //insertion operator to print Hand on an ostream
	friend std::ostream &operator<< (std::ostream& output, const Hand& h) {
		std::list<std::shared_ptr<AnimalCard>>::const_iterator iterator;
		for (int i = 0; i < h.numCards; i++) {
			output << i << "   "; //Print the column number followed by 3 spaces for animal card columns
		}
		output <<std::endl;
		
		for (iterator = h.d_hand.begin(); iterator != h.d_hand.end(); iterator++) {
			(*iterator)->printRow(EvenOdd::EVEN);
		}
		output <<std::endl;
		for (iterator = h.d_hand.begin(); iterator != h.d_hand.end(); iterator++) {
			(*iterator)->printRow(EvenOdd::ODD);
		}
		return output;
	}
	virtual ~Hand();
};

#endif /* HAND_H_ */
