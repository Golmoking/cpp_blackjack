#include<iostream>

#include "CardDeck.h"

using namespace std;

class Game
{
	public:
	void Play();
};

void Game::Play()
{
	CardDeck carddeck;
	carddeck.initCards();
	carddeck.printCards();
	
}