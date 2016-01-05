/*Kyle Kung
Justin Huynh*/

#include "AnimalCardFactory.h"

AnimalCardFactory::AnimalCardFactory() {
	makeJoker();
	makeNoSplits();
	makeSplitTwos();
	makeSplitThree();
	makeSplitFour();
}

//Shuffle the deck after adding all the cards
Deck<std::shared_ptr<AnimalCard>> AnimalCardFactory::getDeck() {
	std::random_shuffle(deck.begin(), deck.end());
	return deck;
}

//Create and add the joker card
void AnimalCardFactory::makeJoker() {
	char joke[2][2] = { { 'j','j' },
	                    { 'j','j' } };
	std::shared_ptr<AnimalCard>jokeCard = std::make_shared<AnimalCard>(Joker(joke));
	deck.push_back(jokeCard);
}

//Create and add the no splits
void AnimalCardFactory::makeNoSplits() {
	//Create 5 no splits, 1 of each animal	
	for (int i = 0; i < 5; i++) {
		char a = animalTypes[i];
		char d_noSplit[2][2] = { { a,a },
		{ a,a } };
		std::shared_ptr<AnimalCard>card = std::make_shared<AnimalCard>(NoSplit(d_noSplit));
		deck.push_back(card);
	}
}

/*Create 10 SplitTwos , 4 of each ****
Start pointer at beginning of animalTypes array
Each subsequent animal in the array will
be used to create a card with the first pointer.
Will stop when pointer to animalType reaches the
second last elem*/
void AnimalCardFactory::makeSplitTwos() {
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			char a = animalTypes[i], b = animalTypes[j];
			char d_twoSplit[2][2] = { { a,a },
			{ b,b, } };
			std::shared_ptr<AnimalCard>cardTwo = std::make_shared<AnimalCard>(SplitTwo(d_twoSplit));
			deck.push_back(cardTwo);
		}
	}
}

//Hardcode method, 20 split threes
void AnimalCardFactory::makeSplitThree() {
	char a[2][2] = { { 'b','b' },{ 'd','h' } };
	char b[2][2] = { { 'b','b' },{ 'h','d' } };
	char c[2][2] = { { 'b','b' },{ 'm','w' } };
	char d[2][2] = { { 'b','b' },{ 'w','m' } };

	char e[2][2] = { { 'd','d' },{ 'b','h' } };
	char f[2][2] = { { 'd','d' },{ 'h','b' } };
	char g[2][2] = { { 'd','d' },{ 'm','w' } };
	char h[2][2] = { { 'd','d' },{ 'w','m' } };

	char i[2][2] = { { 'h','h' },{ 'b','d' } };
	char j[2][2] = { { 'h','h' },{ 'd','b' } };
	char k[2][2] = { { 'h','h' },{ 'm','w' } };
	char l[2][2] = { { 'h','h' },{ 'w','m' } };

	char m[2][2] = { { 'm','m' },{ 'b','d' } };
	char n[2][2] = { { 'm','m' },{ 'd','b' } };
	char o[2][2] = { { 'm','m' },{ 'm','w' } };
	char p[2][2] = { { 'm','m' },{ 'w','m' } };

	char q[2][2] = { { 'w','w' },{ 'b','d' } };
	char r[2][2] = { { 'w','w' },{ 'd','b' } };
	char s[2][2] = { { 'w','w' },{ 'h','m' } };
	char t[2][2] = { { 'w','w' },{ 'm','h' } };

	//Initialize the splitthree cards
	std::shared_ptr<AnimalCard>threeA = std::make_shared<AnimalCard>(SplitThree(a));
	std::shared_ptr<AnimalCard>threeB = std::make_shared<AnimalCard>(SplitThree(b));
	std::shared_ptr<AnimalCard>threeC = std::make_shared<AnimalCard>(SplitThree(c));
	std::shared_ptr<AnimalCard>threeD = std::make_shared<AnimalCard>(SplitThree(d));
	std::shared_ptr<AnimalCard>threeE = std::make_shared<AnimalCard>(SplitThree(e));
	std::shared_ptr<AnimalCard>threeF = std::make_shared<AnimalCard>(SplitThree(f));
	std::shared_ptr<AnimalCard>threeG = std::make_shared<AnimalCard>(SplitThree(g));
	std::shared_ptr<AnimalCard>threeH = std::make_shared<AnimalCard>(SplitThree(h));
	std::shared_ptr<AnimalCard>threeI = std::make_shared<AnimalCard>(SplitThree(i));
	std::shared_ptr<AnimalCard>threeJ = std::make_shared<AnimalCard>(SplitThree(j));
	std::shared_ptr<AnimalCard>threeK = std::make_shared<AnimalCard>(SplitThree(k));
	std::shared_ptr<AnimalCard>threeL = std::make_shared<AnimalCard>(SplitThree(l));
	std::shared_ptr<AnimalCard>threeM = std::make_shared<AnimalCard>(SplitThree(m));
	std::shared_ptr<AnimalCard>threeN = std::make_shared<AnimalCard>(SplitThree(n));
	std::shared_ptr<AnimalCard>threeO = std::make_shared<AnimalCard>(SplitThree(o));
	std::shared_ptr<AnimalCard>threeP = std::make_shared<AnimalCard>(SplitThree(p));
	std::shared_ptr<AnimalCard>threeQ = std::make_shared<AnimalCard>(SplitThree(q));
	std::shared_ptr<AnimalCard>threeR = std::make_shared<AnimalCard>(SplitThree(r));
	std::shared_ptr<AnimalCard>threeS = std::make_shared<AnimalCard>(SplitThree(s));
	std::shared_ptr<AnimalCard>threeT = std::make_shared<AnimalCard>(SplitThree(t));

	//Add the splitthree cards into the deck
	deck.push_back(threeA);
	deck.push_back(threeB);
	deck.push_back(threeC);
	deck.push_back(threeD);
	deck.push_back(threeE);
	deck.push_back(threeF);
	deck.push_back(threeG);
	deck.push_back(threeH);
	deck.push_back(threeI);
	deck.push_back(threeJ);
	deck.push_back(threeK);
	deck.push_back(threeL);
	deck.push_back(threeM);
	deck.push_back(threeN);
	deck.push_back(threeO);
	deck.push_back(threeP);
	deck.push_back(threeQ);
	deck.push_back(threeR);
	deck.push_back(threeS);
	deck.push_back(threeT);
}

void AnimalCardFactory::makeSplitFour() {
	//Create 15 SplitFours, 12 of each animal
	char _a[2][2] = { { 'w','d' },{ 'h','m' } };
	char _b[2][2] = { { 'd','w' },{ 'm','h' } };
	char _c[2][2] = { { 'b','w' },{ 'm','h' } };
	char _d[2][2] = { { 'm','w' },{ 'b','h' } };
	char _e[2][2] = { { 'm','b' },{ 'w','h' } };

	char _f[2][2] = { { 'b','d' },{ 'h','m' } };
	char _g[2][2] = { { 'b','h' },{ 'd','m' } };
	char _h[2][2] = { { 'b','m' },{ 'd','h' } };
	char _i[2][2] = { { 'b','d' },{ 'm','h' } };
	char _j[2][2] = { { 'b','h' },{ 'w','d' } };

	char _k[2][2] = { { 'd','b' },{ 'h','w' } };
	char _l[2][2] = { { 'd','b' },{ 'w','h' } };
	char _m[2][2] = { { 'd','w' },{ 'm','b' } };
	char _n[2][2] = { { 'd','w' },{ 'b','m' } };
	char _o[2][2] = { { 'd','m' },{ 'w','h' } };

	//Make the pointers and initialize the SplitFour objects
	std::shared_ptr<AnimalCard>fourA = std::make_shared<AnimalCard>(SplitFour(_a));
	std::shared_ptr<AnimalCard>fourB = std::make_shared<AnimalCard>(SplitFour(_b));
	std::shared_ptr<AnimalCard>fourC = std::make_shared<AnimalCard>(SplitFour(_c));
	std::shared_ptr<AnimalCard>fourD = std::make_shared<AnimalCard>(SplitFour(_d));
	std::shared_ptr<AnimalCard>fourE = std::make_shared<AnimalCard>(SplitFour(_e));
	std::shared_ptr<AnimalCard>fourF = std::make_shared<AnimalCard>(SplitFour(_f));
	std::shared_ptr<AnimalCard>fourG = std::make_shared<AnimalCard>(SplitFour(_g));
	std::shared_ptr<AnimalCard>fourH = std::make_shared<AnimalCard>(SplitFour(_h));
	std::shared_ptr<AnimalCard>fourI = std::make_shared<AnimalCard>(SplitFour(_i));
	std::shared_ptr<AnimalCard>fourJ = std::make_shared<AnimalCard>(SplitFour(_j));
	std::shared_ptr<AnimalCard>fourK = std::make_shared<AnimalCard>(SplitFour(_k));
	std::shared_ptr<AnimalCard>fourL = std::make_shared<AnimalCard>(SplitFour(_l));
	std::shared_ptr<AnimalCard>fourM = std::make_shared<AnimalCard>(SplitFour(_m));
	std::shared_ptr<AnimalCard>fourN = std::make_shared<AnimalCard>(SplitFour(_n));
	std::shared_ptr<AnimalCard>fourO = std::make_shared<AnimalCard>(SplitFour(_o));

	//Add these SplitFour animal card pointers to the deck
	deck.push_back(fourA);
	deck.push_back(fourB);
	deck.push_back(fourC);
	deck.push_back(fourD);
	deck.push_back(fourE);
	deck.push_back(fourF);
	deck.push_back(fourG);
	deck.push_back(fourH);
	deck.push_back(fourI);
	deck.push_back(fourJ);
	deck.push_back(fourK);
	deck.push_back(fourL);
	deck.push_back(fourM);
	deck.push_back(fourN);
	deck.push_back(fourO);
}

 AnimalCardFactory* AnimalCardFactory::getFactory() {//Returns the only instance of the factory
	 if (!theFactory) //If factory doesn't already exist, create a new one
		 theFactory = new AnimalCardFactory();
	return theFactory;
}


