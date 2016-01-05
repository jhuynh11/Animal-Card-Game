/*
 * StartCard.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle, Justin 
 */

#ifndef STARTCARD_H_
#define STARTCARD_H_

#include "NoSplit.h"

class StartCard : public NoSplit{

public:
	StartCard() = default;
	virtual ~StartCard() = default;
	char getAnimal();
};

#endif /* STARTCARD_H_ */
