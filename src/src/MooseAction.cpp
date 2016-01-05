/*
 * MooseAction.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle
 */

#include "MooseAction.h"

QueryResult MooseAction::query(){
	std::cout << "The moose action card triggers a rotation of secret animals form player 1 to player 2, from 2 to 3, etc. in turn. ";
	QueryResult result;
	return result;
}

void MooseAction::perform(Table& table, Player* player, QueryResult queryRsult){
	std::vector<std::shared_ptr<Player>> players = table.getListOfPlayer();
	std::vector<std::string> secretAnimals;
	//store the secret animal of each player
	for(int i = 0; i<players.size();++i){
		secretAnimals[i] = players[i]->getSecretAnimal();
	}
	//swap it with the list of secretanimals
	for(int i = 0; i<players.size(); ++i){
		players[i]->swapSecretAnimal(secretAnimals[(i-1)% players.size()]);
	}
}
