/*Kyle Kung
Justin Huynh*/
#ifndef ACTIONCARD_H_
#define ACTIONCARD_H_

#include "StartCard.h"
#include <iostream>
#include "QueryResult.h"

//temp classes
class Player;
class Table;

class ActionCard : public StartCard{
public:
	virtual QueryResult query();
	virtual void perform (Table& table, Player* player, QueryResult result);
	ActionCard() = default;
	virtual ~ActionCard() = default;
	void printRow(EvenOdd printState) const;
};
#include "Table.h"

#endif /* ACTIONCARD_H_ */
