/*Kyle Kung
Justin Huynh*/

#ifndef BEARACTION_H_
#define BEARACTION_H_

#include "ActionCard.h"
#include "QueryResult.h"

class BearAction : public ActionCard{
public:
	BearAction() = default;
	~BearAction() = default;
	QueryResult query();
	void perform (Table& table, Player* player, QueryResult result);
};

#endif /* BEARACTION_H_ */
