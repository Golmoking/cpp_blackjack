#pragma once
#include <iostream>
#include <string>

using namespace std;

class Card
{
	private:
	string suit;
	string value;
	int point;
	public:
	Card(string, string, int);
	string getSuit();
	void setSuit(string);
	string getValue();
	void setValue(string);
	int getPoint();
	void setPoint(int);
	void toString();
	
};

Card::Card(string suit, string value, int point) : suit(suit), value(value), point(point) { }

string Card::getSuit()
{
	return suit;
}

void Card::setSuit(string suit)
{
	this->suit = suit;
}

string Card::getValue()
{
	return value;
}

void Card::setValue(string value)
{
	this->value = value;
}

int Card::getPoint()
{
	return point < 11 ? point : 10;
}

void Card::setPoint(int point)
{
	this->point = point;
}

void Card::toString()
{
	cout << "[" << getSuit() << getValue() << "]";
}