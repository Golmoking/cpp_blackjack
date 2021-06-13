#pragma once
#include "Gamer.h"

class Player : public Gamer
{
	private:
	public:
	Player();
	void showCards() override;
};

Player::Player() : Gamer() { }

void Player::showCards()
{
	list<Card> cds = getCards();
	list<Card>::iterator iter;
	
	cout << "현재 보유한 카드 : "; 
	
	for(iter = cds.begin(); iter != cds.end(); iter++)
	{
		iter->toString();
		cout << " ";
	}
	cout << endl;
}