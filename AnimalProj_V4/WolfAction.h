/*
 * WolfAction.h
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle , Justin
 */

#ifndef WOLFACTION_H_
#define WOLFACTION_H_

#include "ActionCard.h"
#include "QueryResult.h"

class WolfAction : public ActionCard{
public:
	WolfAction() = default;
	~WolfAction() = default;
	QueryResult query();
	void perform (Table& table, Player* player, QueryResult result);
};

#endif /* WOLFACTION_H_ */
