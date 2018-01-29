#include <iostream>
using namespace std;

class Deck{

//For the deck object, I wanted it to contain an array of 53 cards
//to standardize how they are defined.
public:
	Card cards[53];

	//Each time a deck is created, it is initialized to a deck that
	//is ordered both by suit and rank as a default.

	Deck(){
		int enumInt=Card::Diamonds;
		int count=0;
		while(enumInt<4){
			Card::Suit suit = static_cast<Card::Suit>(enumInt);
			for(int i=1+count; i<14+count; i++){
				cards[i].setSuit(suit);
				cards[i].setRank(i-count);
			}
		++enumInt;
		count+=13;
		}
	}

	//Prints out suit and rank as a pair separated by a space
	//Example: 0 1 == "1 of diamonds"
	void printDeck(){
		for(int i=1; i<53; i++){
			cards[i].printSuit();
			cards[i].printRank();
		}
	}

	//For my shuffle function, I am essentially swapping cards from
	//a default deck to make sure both suit and rank are well-
	//distributed. A for loop zips through the default deck and moves
	//cards down the ranks/suits at semi-variable intervals.
	void shuffle(){
		Card temp;
		int count=0;
		int start=1;
		while(count<3){
			for(int i=start; i<39; i+=3){
				temp=cards[i];
				cards[i]=cards[i+14];
				cards[i+14]=temp;
			}
			++count;
			++start;
		}
	}
	//For both sorts, I implemented bubble sort just to keep things
	//simple. A faster algorithm would be to implement merge sort
	//but that would be an even larger time-sink.
	void sortBySuit(){
		int swaps;
		Card temp;
		while(swaps>0){
			swaps=0;
			for(int i=1; i<52; i++){
				if(cards[i].getSuit()>cards[i+1].getSuit()){
					temp=cards[i+1];
					cards[i+1]=cards[i];
					cards[i]=temp;
					++swaps;
				}
			}
		}
	}

	void sortByRank(){
		int swaps;
		Card temp;
		while(swaps>0){
			swaps=0;
			for(int i=1; i<52; i++){
				if(cards[i].getRank()>cards[i+1].getRank()){
					temp=cards[i+1];
					cards[i+1]=cards[i];
					cards[i]=temp;
					++swaps;
				}
			}
		}
	}
	//For the placement function, I just used linear search. If the
	//cards are to be sorted at all times, I would've used binary search
	//but I figured the fun part would be to find a card in a shuffled
	//deck.
	int placement(int r, Card::Suit s){
		for(int i=1; i<53; i++){
			if(cards[i].getRank()==r && cards[i].getSuit()==s)
				return i; 
		}
		return -1;
	}

};