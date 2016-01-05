/*Kyle Kung
Justin Huynh*/

#ifndef ANIMALCARD_H_
#define ANIMALCARD_H_

#include <iostream>
#include <memory>

enum class Orientation{
	UP, DOWN
};

enum class EvenOdd{
	EVEN, ODD, DEFAULT
};

class AnimalCard {

	friend std::ostream& operator<< (std::ostream& out, const AnimalCard& AnimalCardToPrint){
		AnimalCardToPrint.printRow(AnimalCardToPrint.getRow());
		return out;
	};

protected:
	Orientation cardOrientation;
	EvenOdd printState;
	char cardValues[2][2];
public:
	AnimalCard();
	AnimalCard(char initalizer[2][2]);
	virtual void setOrientation(Orientation newOrientation);
	virtual void setRow(EvenOdd printState);
	virtual EvenOdd getRow() const;
	virtual void printRow(EvenOdd printState) const;
	virtual ~AnimalCard() = default;
	bool operator==(AnimalCard& other);
	virtual int nextToNumOfAnimals(std::shared_ptr<AnimalCard> top, std::shared_ptr<AnimalCard> left,
						   	   	   	   std::shared_ptr<AnimalCard> right, std::shared_ptr<AnimalCard> bottom);
	bool contain(std::string animal);
};

#endif /* ANIMALCARD_H_ */
