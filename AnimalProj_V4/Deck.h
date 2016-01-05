/*Kyle Kung
Justin Huynh*/

#ifndef DECK_H_
#define DECK_H_

#include<vector>


template <class T>
class Deck : public std::vector<T>{ //Deck is derived from vector
public:
	Deck();
	T draw();
	//void pop_back();
	~Deck();
};

template <class T>
Deck<T>::Deck() {
}


template <class T>
//Where the top card is represented by the
T Deck<T>::draw() {
	T topCard((this->back()));
	pop_back(); //remove the card
	return topCard;
}

/*void pop_back(){
	pop_back();
}*/

template <class T>
Deck<T>::~Deck() {
	this->clear();
}


#endif /* DECK_H_ */
