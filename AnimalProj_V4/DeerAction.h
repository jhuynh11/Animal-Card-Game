/*Kyle Kung
Justin Huynh*/

#ifndef DEERACTION_H_
#define DEERACTION_H_

#include "ActionCard.h"
#include "QueryResult.h"

class DeerAction : public ActionCard {
public:
	DeerAction() = default;
	~DeerAction() = default;
	QueryResult query();
	void perform (Table& table, Player* player, QueryResult result);
};

#endif /* DEERACTION_H_ */
