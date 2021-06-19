#pragma once
#include "Gamer.h"

class Player : public Gamer
{
	private:
	public:
	Player();
	void showCards() override;
};

Player::Player() : Gamer() 
{
	setName("Player");
}

void Player::showCards()
{
	list<Card> cds = getCards();
	list<Card>::iterator iter;
	
	cout << "Your Cards : "; 
	
	for(iter = cds.begin(); iter != cds.end(); iter++)
	{
		iter->toString();
		cout << " ";
	}
	
	cout << endl << "Current Score : ";
	cout << getPointSum() << endl;
}