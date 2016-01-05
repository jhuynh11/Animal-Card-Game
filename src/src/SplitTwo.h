/*
 * SplitTwo.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle, Justin
 */

#ifndef SPLITTWO_H_
#define SPLITTWO_H_

#include "AnimalCard.h"

class SplitTwo : public AnimalCard {
public:
	SplitTwo();
	SplitTwo(char initializer[2][2]);
	virtual ~SplitTwo();
};

#endif /* SPLITTWO_H_ */
