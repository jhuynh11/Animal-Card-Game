/*Kyle Kung
Justin Huynh*/

#include "StartStack.h"


StartStack::StartStack() : pStartCard(new StartCard()){
	cardDeque.push_front(pStartCard);
}

StartStack::~StartStack() {
	//pStartCard is a smart pointer, don't need to delete
}

StartStack& StartStack::operator+= (std::shared_ptr<ActionCard> newCard){
	cardDeque.push_front(newCard);
	return *this;
}

StartStack& StartStack::operator-= (std::shared_ptr<ActionCard> newCard){
	cardDeque.push_back(newCard);
	return *this;
}
std::shared_ptr<StartCard> StartStack::getStartCard(){
	return pStartCard;
}
/*int StartStack::nextToNumOfAnimals(std::shared_ptr<AnimalCard> top, std::shared_ptr<AnimalCard> left,
							std::shared_ptr<AnimalCard> right, std::shared_ptr<AnimalCard> bottom){
	for(int i = 0; i<2 ; ++i){
		for(int j = 0; j<2; ++j){
			cardValues[i][j] = cardDeque.front()->getAnimal();
		}
	}
	//since startstack is an animal card, we can set the cardvalues with the top card's animal
	//and call the implmentation in animal card
	return AnimalCard::nextToNumOfAnimals(top,left,right,bottom);

}*/

