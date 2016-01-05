/*
 * SplitFour.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle, Justin
 */

#ifndef SPLITFOUR_H_
#define SPLITFOUR_H_

#include "AnimalCard.h"

class SplitFour : public AnimalCard{
public:
	SplitFour(char initializer[2][2]);
	virtual ~SplitFour();
};

#endif /* SPLITFOUR_H_ */
