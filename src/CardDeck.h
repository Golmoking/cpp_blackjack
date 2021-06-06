#include <iostream>
#include <string>
#include <list>

#include "Card.h"

using namespace std;

class CardDeck
{
	private:
	list<Card> cards;
	
	public:
	string getSuitText(int);
	string getValueText(int);
	void initCards();
	void printCards();
	void test();
};

string CardDeck::getSuitText(int id)
{
	string o = " ";
	switch(id)
	{
		case 0:
			o = "♠";
			break;
		case 1:
			o = "♥";
			break;
		case 2:
			o = "♦";
			break;
		case 3:
			o = "♣";
			break;
	}
	
	return o;
}

string CardDeck::getValueText(int id)
{
	string o = " ";
	switch(id)
	{
		case 0:
			o = "A";
			break;
		case 1:
			o = "2";
			break;
		case 2:
			o = "3";
			break;
		case 3:
			o = "4";
			break;
		case 4:
			o = "5";
			break;
		case 5:
			o = "6";
			break;
		case 6:
			o = "7";
			break;
		case 7:
			o = "8";
			break;
		case 8:
			o = "9";
			break;
		case 9:
			o = "10";
			break;
		case 10:
			o = "J";
			break;
		case 11:
			o = "Q";
			break;
		case 12:
			o = "K";
			break;
	}
	
	return o;
}

void CardDeck::initCards()
{
	Card card(" ", " ");
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			card.setSuit(getSuitText(i));
			card.setValue(getValueText(j));
			cards.push_back(card);
		}
	}
}

void CardDeck::printCards()
{
	list<Card>::iterator iter;
	for(iter = cards.begin(); iter != cards.end(); iter++)
	{
		iter->toString();
	}
}

void CardDeck::test()
{
	cout<<"test"<<endl;
}