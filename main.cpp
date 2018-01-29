#include <iostream>
#include "Card.h"
#include "Deck.h"
#include <cassert>

int main(){
	Deck d;
	//First, check to see if Deck actually prints
	cout << "Initialized deck that is not shuffled" << endl;
	cout << "-------------------------------------" << endl;
	d.printDeck();
	//Then shuffle the deck and get visual confirmation of this
	d.shuffle();
	cout << endl << endl;
	cout << "Deck that has been shuffled" << endl;
	cout << "-------------------------------------" << endl;
	d.printDeck();
	cout << endl << endl;
	//Next is to see if sortBySuit works
	//The number in the left column should be sorted ascending
	d.sortBySuit();
	cout << "Sort by suit" << endl;
	cout << "-------------------------------------" << endl;
	d.printDeck();
	cout << endl << endl;
	//sortByRank is checked next, the second column should be ascending
	d.sortByRank();
	cout << "Sort by rank" << endl;
	cout << "-------------------------------------" << endl;
	d.printDeck();
	cout << endl << endl;
	cout << "Pick a card, any card";
	cout << "-------------------------------------" << endl;
	//Now to find a card, a 3 of clubs, for example
	cout << d.placement(3, Card::Clubs) << endl;
	//Should be card number 11
	//Looking for a card that doesn't exist returns -1

}