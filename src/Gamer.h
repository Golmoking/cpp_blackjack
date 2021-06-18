#pragma once
#include "Card.h"

using namespace std;

class Gamer
{
	private:
	list<Card> cards;
	public:
	Gamer();
	list<Card> getCards();
	void receiveCard(Card);
	virtual void showCards() = 0;
	int getPointSum();
};

Gamer::Gamer() { }

list<Card> Gamer::getCards()
{
	return cards;
}

void Gamer::receiveCard(Card card)
{
	cards.push_back(card);
}

int Gamer::getPointSum()
{
	int sum = 0;
	list<Card>::iterator iter;
	
	for(iter = cards.begin(); iter != cards.end(); iter++)
	{
		sum += iter->getPoint();
	}
	
	return sum;
}