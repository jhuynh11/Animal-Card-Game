/*Kyle Kung
  Justin Huynh*/

#include "HareAction.h"

QueryResult HareAction::query(){
	std::cout << "The hare action card allows a player to move an animal card on the table including the joker to a different location on the table where the card is valid ";
	std::cout << "Please enter the coordinates of the card to be moved";
	int row,col;
	std::cout << "row:";
	std::cin >> row;
	std::cout << "col:";
	std::cin >> col;
	std::cout << "Please enter the coordinates of the new location";
	int newRow, newCol;
	std::cout << "new row:";
	std::cin >> newRow;
	std::cout << "new col:";
	std::cin >> newCol;
	QueryResult result(row,col,newRow,newCol);
	return result;
}

void HareAction::perform(Table& table, Player* player, QueryResult queryResult){
	int row,col;
	queryResult.getOriginalPoint(row,col);
	std::shared_ptr<AnimalCard> movingCard = table.pickAt(10,20);
	if(movingCard){					//if picking the card was successful move the  card to  the new location
		player->hand+= movingCard;
		int newRow, newCol;
		queryResult.getOriginalPoint(newRow,newCol);
		table.addAt(movingCard, newRow, newCol);
	}
}
