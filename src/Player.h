#pragma once
#include "Gamer.h"

class Player : public Gamer
{
	private:
	public:
	Player();
	void receiveCard(Card);
	void showCards() override;
};

Player::Player() : Gamer() 
{
	setName("Player");
}

void Player::receiveCard(Card card)
{
	Gamer::receiveCard(card);
	cout << "You Get : ";
	card.toString();
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
	
	cout << endl << "Current Score : " << getPointSum() << endl;
}