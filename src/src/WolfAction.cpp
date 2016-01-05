/*
 * WolfAction.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle
 */

#include "WolfAction.h"

QueryResult WolfAction::query(){
	std::cout << "The wolf action card allows a player to pick up a card from the table and place it in the player's hand." <<std::endl;
	std::cout << "Please enter the coordinates of the card to pick up" <<std::endl;
	int row, col;
	std::cout << "row:";
	std::cin >> row;
	std::cout << "col:";
	std::cin >> col;
	QueryResult result(row,col);
	return result;
}

void WolfAction::perform(Table& table, Player* player, QueryResult queryResult){
	int row,col;
	queryResult.getOriginalPoint(row,col);
	std::shared_ptr<AnimalCard> cardToPick = table.pickAt(10,20);
	if(cardToPick){		//if picked a valid card, add it to player's hand
		player->hand+=cardToPick;
	}

}
