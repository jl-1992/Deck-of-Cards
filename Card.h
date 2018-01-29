#include <string.h>
using namespace std;

class Card{

//Defined a 'Card' object that contains a suit and rank. I felt
//suits would best be stored in an enum. Ranks are from 1->13
//which is equivalent to Ace->King.
public:
	enum Suit {Diamonds, Hearts, Clubs, Spades};
	//Since this is an enumeration, Diamonds=0, Hearts=1, Clubs=2, Spades=3
	int rank;
	Suit suit;

	Card(){}

	//the only member functions I included were getters, setters, 
	//and printers for simplicity.

	void printSuit(){
		cout << suit << " ";
	}

	void setSuit(Suit s){
		suit=s;
	}

	void setRank(int r){
		rank=r;
	}

	void printRank(){
		cout << rank << endl;
	}

	int getRank(){
		return rank;
	}

	Suit getSuit(){
		return suit;
	}
};