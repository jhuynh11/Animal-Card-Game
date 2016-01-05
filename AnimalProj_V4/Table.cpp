/*
 * Table.cpp
 *
 *  Created on: Nov 10, 2015
 *      Author: Kyle
 */

#include "Table.h"

Table::Table() : startStack(new StartStack()), BearWinCounter(0),
DeerWinCounter(0), HareWinCounter(0), MooseWinCounter(0) ,WolfWinCounter(0){
	//intialize table with nullptrs
	for(int i = 0; i<103; ++i){
		for(int j = 0; j<103; ++j){
			tableTop[i][j] = nullptr;
		}
	}
	tableTop[51][51] = startStack;
}

Table::~Table() {
	// TODO Auto-generated destructor stub
}

int Table::addAt(std::shared_ptr<AnimalCard> cardToAdd, int row, int col){

	int num = 0;
	try{
		//if out of bound of the table, throw illegal placement error
		//or if the posotion already has a card
		if(row<0 || row >102 || col<0 || col>102 || tableTop[row][col].get() != nullptr){
			throw IllegalPlacement();
		}

		//num will return how many animals it is next to
		//these check for edge cases on the table
		if(row == 102){
			if (col == 102) 				//trying to insert at the bottom right
				num = cardToAdd->nextToNumOfAnimals(tableTop[row-1][col],tableTop[row][col-1],nullptr,nullptr);
			else if(col == 0)				//trying to insert at the bottom left
				num = cardToAdd->nextToNumOfAnimals(tableTop[row-1][col],nullptr,tableTop[row][col+1],nullptr);
			else							//trying to insert on the bottom row that's not the corner
				num = cardToAdd->nextToNumOfAnimals(tableTop[row-1][col],tableTop[row][col-1],tableTop[row][col+1],nullptr);
		}else if(row == 0){
			if(col == 102)					//trying to insert at top right
				num = cardToAdd->nextToNumOfAnimals(nullptr,tableTop[row][col-1],nullptr,tableTop[row+1][col]);
			else if(col == 0)				//trying to insert at top left
				num = cardToAdd->nextToNumOfAnimals(nullptr,nullptr,tableTop[row][col+1],tableTop[row+1][col]);
			else							//trying to insert on the top row
				num = cardToAdd->nextToNumOfAnimals(nullptr,tableTop[row][col-1],tableTop[row][col+1],tableTop[row+1][col]);
		}else if(row>0 && row <102 && col>0 && col<102)		//if the card is in the center smaller square from 1-101
			num = cardToAdd->nextToNumOfAnimals(tableTop[row-1][col],tableTop[row][col-1],tableTop[row][col+1],tableTop[row+1][col]);

		if(col == 0 && row!= 102 && row != 0)//trying to insert on the left row
			num = cardToAdd->nextToNumOfAnimals(tableTop[row-1][col],nullptr,tableTop[row][col+1],tableTop[row+1][col]);
		if(col ==102 && row!= 102 && row != 0)//trying to insert on the right row
			num = cardToAdd->nextToNumOfAnimals(tableTop[row-1][col],tableTop[row][col-1],nullptr,tableTop[row+1][col]);



		if(col ==0 )
		// if it is next to any animals at all, put the card on the table
		if (num){
			tableTop[row][col] = cardToAdd;
			UpdateWinCounter(cardToAdd);		//update wincounter if add at is successful
		} else{	//if num ==0, not next to anything
			throw IllegalPlacement();
		}
	}catch(IllegalPlacement& i){
		std::cout << "Illegal Placement, please input valid cell for input";
		return 0;
	}

	//Use booleans to help see what animals the card contains

	return num;
}
void Table::UpdateWinCounter(std::shared_ptr<AnimalCard> cardToAdd){
	bool hasBear(false), hasDeer(false), hasHare(false), hasMoose(false), hasWolf(false);

	//check if card contains these animals, used boolean to avoid overcounting an animal multiple times
	hasBear = cardToAdd->contain("Bear");
	hasDeer = cardToAdd->contain("Deer");
	hasHare = cardToAdd->contain("Hare");
	hasMoose = cardToAdd->contain("Moose");
	hasWolf = cardToAdd->contain("Wolf");

	//update  win counters
	BearWinCounter += hasBear;
	DeerWinCounter += hasDeer;
	HareWinCounter += hasHare;
	MooseWinCounter += hasMoose;
	WolfWinCounter += hasWolf;

}
Table& Table::operator-=( std::shared_ptr<ActionCard> newCard){
	*startStack-=newCard;
	return *this;
}
Table& Table::operator+=( std::shared_ptr<ActionCard> newCard){
	*startStack+=newCard;
	return *this;
}
std::shared_ptr<AnimalCard> Table::pickAt(int row, int col){
	try{					//if out of bound, throw illegalPick
		if( (row == 51 && col ==51) || row<0 || col<0 || row>102 || col>102){
			throw IllegalPick();
		}
	}
	catch(IllegalPick& p){
		std::cout << "Illegal Pick, Please input valid coordinates";
		return nullptr;
	}
	//otherwise get the result, and clear the cell on the table
	std::shared_ptr<AnimalCard>result(tableTop[row][col]);
	tableTop[row][col] = nullptr;
	return result;

}
std::shared_ptr<Player> Table::getWinner(){

	//returns the winner if any secret animal has more than 7 counts
	std::string winningAnimal = "None";
	std::shared_ptr<Player> winningPlayer = nullptr;
	if(BearWinCounter>=7)
		winningAnimal = "Bear";
	if(DeerWinCounter>=7)
			winningAnimal = "Deer";
	if(HareWinCounter>=7)
			winningAnimal = "Hare";
	if(MooseWinCounter>=7)
			winningAnimal = "Moose";
	if(WolfWinCounter>=7)
			winningAnimal = "Wolf";

	//if someone won, find the winning player
	if(winningAnimal != "None"){
		for(int i = 0; i<players.size(); ++i){
			if(players[i]->getSecretAnimal() == winningAnimal)
				winningPlayer = players[i];
		}
	}


	return winningPlayer;			//note this will be nullptr if no winning animal or the winning animal does not belong to any player
}

bool Table::addPlayer(std::shared_ptr<Player> player){
	if(players.size() < 5){			//add player if there is less than 5 people
		players.push_back(player);
		return true;
	}
	else{
		return false;
	}
}
std::vector<std::shared_ptr<Player>> Table::getListOfPlayer(){
	return players;
}
//find the player with name
std::shared_ptr<Player> Table::getPlayerWithName(std::string name){
	for(int i = 0; i < players.size(); ++i){
		if(players[i]->getName() == name){
			return players[i];
		}
	}
	return nullptr;
}

