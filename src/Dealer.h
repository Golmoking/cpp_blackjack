#pragma once
#include "Gamer.h"

class Dealer : public Gamer
{
	private:
	int AVAILABLE_HIT_POINT = 16;
	public:
	Dealer();
	void showCards() override;
	bool isDealerCanHit();
	
};

Dealer::Dealer() : Gamer() { }

void Dealer::showCards()
{
	list<Card> cds = getCards();
	
	cout << "Dealer's First Card : "; 
	cds.begin()->toString();
	cout << " " << endl;
}

bool Dealer::isDealerCanHit()
{
	if(getPointSum() <= AVAILABLE_HIT_POINT)
		return true;
	return false;
}