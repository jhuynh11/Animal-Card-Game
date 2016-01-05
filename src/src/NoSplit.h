/*
 * NoSplit.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle, Justin
 */

#ifndef NOSPLIT_H_
#define NOSPLIT_H_

#include "AnimalCard.h"

class NoSplit : public AnimalCard{
public:
	NoSplit() = default;
	NoSplit(char[2][2]);
	virtual ~NoSplit();
};

#endif /* NOSPLIT_H_ */
