/*Kyle Kung
Justin Huynh*/
#include "Deck.h"
#include "Player.h"
#include "AnimalCardFactory.h"
#include "Hand.h"
#include "Table.h"
#include "StartStack.h"


int main() {
	//Introduction
	std::cout << "Welcome to Angry Animals Card Game!"<<std::endl;

	//Ask for number of players
	bool playersWithinBounds = false; //Game has to have between 2 and 5 players
    int numPlayers = 0;
	while (playersWithinBounds = false) {
		std::cout << "Please enter the amount of players. Between 2 and 5" << std::endl;
		std::cin >> numPlayers;
		if (numPlayers < 2 || numPlayers>5) {
			playersWithinBounds = false;
			std::cout << "Game can only accept between 2 and 5 players" << std::endl; //Error message
		}
		else playersWithinBounds = true;
	}
	
	//Receiving the names of players
	std::vector<Player> players;
	std::string setAnimals[] = { "Bear","Wolf","Hare","Moose","Deer" };
	for (int i = 0; i < numPlayers; i++) {
		std::string name;
		std::cout << "Please input the name of Player " << i << ":" << std::endl;
		players.push_back(Player(name,setAnimals[i])); //Add a player to the list of players
		std::cout << "The secret animal of Player " << i << " is " << players.at(i).getSecretAnimal() << std::endl;
	}
	
	//Creating the deck of cards
	 AnimalCardFactory* factory = AnimalCardFactory::getFactory();
	 Deck<std::shared_ptr<AnimalCard>> gameDeck = factory->getDeck();

	 //Initialize each player with 3 animalcards
	 for (int i = 0; i < numPlayers; i++) {
		 for (int j = 0; j < 3; j++)
		 players.at(i).hand+=(gameDeck.draw());
	 }
	
	 //While no player has won, display the table
	 Table gameTable;
	 std::shared_ptr<Player> winner;
	 while (!gameTable.getWinner() || !gameDeck.empty()) { 
		 std::cout << gameTable; // Print the table
		 for (int i = 0; i < numPlayers; i++) { //Display player picking up card
			 std::cout << "Player " << i << "'s turn. Picking up card from deck." << std::endl;
			 
			 //add the card to Player's hand and display their hand
			 players.at(i).hand+=(gameDeck.draw());
			 std::cout << "Player " << i << "'s hand. Select a card to play" << std::endl;
			 std::cout << players.at(i).hand;
			 
			 //Player inputs the card that they want to place on the table using operator[]
			 int cardToPlace, row, column;
			 std::cin >> cardToPlace;
			 std::shared_ptr<AnimalCard> ptrCardToPlace = (players[i].hand[cardToPlace]);
			
			 int numOfNeighbour;
			 do {
				 std::cout << "Select where to place the card by inputting the row and column of the table" << std::endl;
				 std::cin >> row >> column;
				 numOfNeighbour = gameTable.addAt(ptrCardToPlace, row, column);
			 } while (!numOfNeighbour); //Keep prompting player to input card until valid placement reached

			 // Player placed card near matching pairs, keep drawing cards for the number of matching pairs
			 for (int j = 1; j<numOfNeighbour; j++) {
				 players[j].hand += (gameDeck.draw()); 
			 }
			
			 //Check if action card
			 if (row == 51 && column == 51) {
				 ActionCard* actionCard = static_cast<ActionCard*> (&*ptrCardToPlace);
				 QueryResult results = actionCard->query();
				 actionCard->perform(gameTable, &players[i], results);
			 }
			 std::cout << gameTable; //Display the game table after each insertion
			 
		 }
	 }
	 winner = gameTable.getWinner(); 
	
	//Display the winner
	 std::cout << winner << " Has won !" << std::endl;
	
}
