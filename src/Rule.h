#pragma once
#include <iostream>
#include <string>

#include "CardDeck.h"
#include "Dealer.h"
#include "Player.h"

using namespace std;

class Rule
{
	private:
	int MAX_POINT = 21;
	public:
	Rule();
	bool isBurst(int);
	string getWinner(int, int);
};

Rule::Rule() { }

bool Rule::isBurst(int point)
{
	return point > MAX_POINT ? true : false;
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