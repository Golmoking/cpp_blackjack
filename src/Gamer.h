#pragma once
#include <iostream>
#include <string>

#include "Card.h"

using namespace std;

class Gamer
{
	private:
	list<Card> cards;
	string name;
	public:
	Gamer();
	string getName();
	void setName(string);
	void resetData();
	list<Card> getCards();
	void receiveCard(Card);
	virtual void showCards() = 0;
	void openCards();
	int getPointSum();
	int checkAceCount();
};

Gamer::Gamer() { }

list<Card> Gamer::getCards()
{
	return cards;
}


string Gamer::getName()
{
	return name;
}

void Gamer::setName(string name)
{
	this->name = name;
}

void Gamer::resetData()
{
	cards.clear();
}

void Gamer::receiveCard(Card card)
{
	cards.push_back(card);
}

void Gamer::openCards()
{
	list<Card>::iterator iter;
	
	cout << name << "\'s Cards : "; 
	
	for(iter = cards.begin(); iter != cards.end(); iter++)
	{
		iter->toString();
		cout << " ";
	}
	
	cout << "\nTotal Point : " << getPointSum() << endl;
}

int Gamer::getPointSum()
{
	int sum = 0;
	list<Card>::iterator iter;
	
	for(iter = cards.begin(); iter != cards.end(); iter++)
	{
		sum += iter->getPoint();
	}
	
	if(checkAceCount() > 0)
	{
		for(int i = 0; i < checkAceCount(); i++)
		{
			if(sum + 10 <= 21) sum += 10;
		}
	}
	
	return sum;
}

int Gamer::checkAceCount()
{
	int o = 0;
	
	list<Card>::iterator iter;
	
	for(iter = cards.begin(); iter != cards.end(); iter++)
		if(iter->getValue() == "A")
			o++;
	
	return o;
	
	
}