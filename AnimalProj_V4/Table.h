/*Kyle Kung
Justin Huynh*/

#ifndef TABLE_H_
#define TABLE_H_


#include "ActionCard.h"
#include "Player.h"
#include <iomanip>
#include <memory>
#include <vector>

class IllegalPick{
};
class IllegalPlacement{
};

class StartStack;
class Table {
	std::shared_ptr<AnimalCard> tableTop[103][103];
	std::shared_ptr<StartStack> startStack;
	int BearWinCounter, DeerWinCounter, HareWinCounter, MooseWinCounter, WolfWinCounter;
	void UpdateWinCounter(std::shared_ptr<AnimalCard> cardToAdd);
	std::vector<std::shared_ptr<Player>> players;

public:
	int addAt(std::shared_ptr<AnimalCard> cardToAdd, int row, int col);
	Table& operator+=( std::shared_ptr<ActionCard> newCard);
	Table& operator-=( std::shared_ptr<ActionCard> newCard);
	std::shared_ptr<AnimalCard> pickAt(int row, int col);
	std::shared_ptr<Player> getWinner();
	bool addPlayer(std::shared_ptr<Player> player);
	std::vector<std::shared_ptr<Player>> getListOfPlayer();


	std::shared_ptr<Player> getPlayerWithName(std::string name);
	Table();
	virtual ~Table();


	friend std::ostream &operator<< (std::ostream& output, const Table& tableToPrint) {
		output << "   ";
		for (int i = 0; i <103; ++i) {
			output << std::setw(3)<< i; //Print the column number followed by 3 spaces for animal card columns
		}

		output << std::endl;

		for(int i = 0; i<103 ;++i){
			output << std::setw(3)<< i;
			for (int j = 0; j<103; ++j) {
				if(tableToPrint.tableTop[i][j])
					tableToPrint.tableTop[i][j]->printRow(EvenOdd::EVEN);
				else
					output << "   ";
			}
			output<<std::endl;
			output << "     ";
			for (int j = 0; j<103; ++j) {
				if(tableToPrint.tableTop[i][j])
					tableToPrint.tableTop[i][j]->printRow(EvenOdd::ODD);
			}
			output<<std::endl;
		}
		return output;
	}
};
#include "StartStack.h"

#endif /* TABLE_H_ */
