/*
 * StartStack.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle, Justin
 */

#ifndef STARTSTACK_H_
#define STARTSTACK_H_

#include <deque>
#include <memory>
#include "AnimalCard.h"
#include "StartCard.h"
#include "ActionCard.h"
class StartCard;
class StartStack : public AnimalCard {
	std::deque<std::shared_ptr<StartCard>> cardDeque;
	std::shared_ptr<StartCard> pStartCard;

public:
	StartStack& operator+= (std::shared_ptr<ActionCard> newCard);
	StartStack& operator-= (std::shared_ptr<ActionCard> newCard);
	std::shared_ptr<StartCard> getStartCard();
	StartStack();
	virtual ~StartStack();
	/*int nextToNumOfAnimals(std::shared_ptr<AnimalCard> top, std::shared_ptr<AnimalCard> left,
							std::shared_ptr<AnimalCard> right, std::shared_ptr<AnimalCard> bottom);*/
};

#endif /* STARTSTACK_H_ */
