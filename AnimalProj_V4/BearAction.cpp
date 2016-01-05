/*
 * BearAction.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle
 */

#include "BearAction.h"


QueryResult BearAction::query(){
	std::cout << ("The bear action card allows a player to select another player to switch hands.");
	std::cout << "Enter the name of the player you'd like to trade with";
	std::string name;
	std::cin >> name;
	QueryResult result(name);
	return result;
}

void BearAction::perform(Table& table, Player* player, QueryResult queryResult){
	std::shared_ptr<Player> playerToTrade = table.getPlayerWithName(queryResult.getName());
	if(!playerToTrade){					//if no player was found with the name, alert the player and do not perform
		std::cout << "Invalid Player to trade with." << std::endl;
		return;
	}
	//swap the hands
	Hand temp  = player->hand;
	player->hand = playerToTrade->hand;
	playerToTrade->hand = temp;
}
