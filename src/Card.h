#include <iostream>
#include <string>

using namespace std;

class Card
{
	private:
	string suit;
	string value;
	
	public:
	Card(string, string);
	string getSuit();
	void setSuit(string);
	string getValue();
	void setValue(string);
	void toString();
	
};

Card::Card(string suit, string value) : suit(suit), value(value) { }

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

void Card::toString()
{
	cout << "[" << getSuit() << getValue() << "]";
}