#pragma once
#include "Gamer.h"

class Dealer : public Gamer
{
	private:
	public:
	Dealer();
	void showCards() override;
};

Dealer::Dealer() : Gamer() { }

void Dealer::showCards()
{
	list<Card> cds = getCards();
	
	cout << "딜러의 첫번째 카드 : "; 
	cds.begin()->toString();
	cout << " " << endl;
}