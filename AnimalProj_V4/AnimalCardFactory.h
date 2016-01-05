/*Kyle Kung
  Justin Huynh*/
#ifndef ANIMAL_CARD_FACTORY
#define ANIMAL_CARD_FACTORY
#include "Deck.h"
#include "NoSplit.h"
#include "SplitTwo.h"
#include "SplitThree.h"
#include "SplitFour.h"
#include "Joker.h"
#include "AnimalCard.h"
#include <algorithm>
class AnimalCardFactory {
	 AnimalCardFactory();
	 void makeJoker();
	 void makeNoSplits();
	 void makeSplitTwos();
	 void makeSplitThree();
	 void makeSplitFour();
	 static AnimalCardFactory* theFactory; //Singleton pattern-the only instance of this class to be created
	 Deck<std::shared_ptr<AnimalCard>> deck;
	 char animalTypes[5] = { 'b','d','h','m','w' }; //Represents the 4 possible animal classes 
public:
	static AnimalCardFactory* getFactory();
	
	Deck<std::shared_ptr<AnimalCard>> getDeck();
	~AnimalCardFactory() = default;

};


#endif
