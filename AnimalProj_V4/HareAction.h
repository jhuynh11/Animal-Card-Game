/*
 * HareAction.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle, Justin
 */

#ifndef HAREACTION_H_
#define HAREACTION_H_

#include "ActionCard.h"
#include "QueryResult.h"

class HareAction : public ActionCard{
public:
	HareAction() = default;
	~HareAction() = default;
	QueryResult query();
	void perform (Table& table, Player* player, QueryResult result);
};

#endif /* HAREACTION_H_ */
