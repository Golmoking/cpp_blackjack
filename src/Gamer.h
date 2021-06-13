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