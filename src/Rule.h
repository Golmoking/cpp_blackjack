#pragma once
#include <iostream>
#include <string>
#include <list>

#include "CardDeck.h"
#include "Dealer.h"
#include "Player.h"

#define MAX_POINT 21

using namespace std;

class Rule
{
	private:
	public:
	Rule();
	bool isBurst(int);
	bool isBlackJack(list<Card>);
	string getWinner(int, int);
};

Rule::Rule() { }

bool Rule::isBurst(int point)
{
	return point > MAX_POINT ? true : false;
}

bool Rule::isBlackJack(list<Card> cards)
{
	bool isAce = false, isTen = false;
	if(cards.size() > 2) return false;
	
	list<Card>::iterator iter;
	
	for(iter = cards.begin(); iter != cards.end(); iter++)
	{
		if(!isAce && iter->getPoint() == 1) isAce = true;
		if(!isTen && iter->getPoint() == 10) isTen = true;
	}
	
	return isAce && isTen;
}

string Rule::getWinner(int playerPoint, int dealerPoint)
{
	string o;
	
	if(playerPoint > dealerPoint)
		o = "Player";
	else
		o = "Dealer";
	
	return o;
}