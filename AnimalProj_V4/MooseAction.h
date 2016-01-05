/*
 * MooseAction.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle, Justin
 */

#ifndef MOOSEACTION_H_
#define MOOSEACTION_H_

#include "ActionCard.h"
#include "QueryResult.h"

class MooseAction : public ActionCard {
public:
	MooseAction() = default;
	~MooseAction() = default;
	QueryResult query();
	void perform (Table& table, Player* player, QueryResult result);
};

#endif /* MOOSEACTION_H_ */
