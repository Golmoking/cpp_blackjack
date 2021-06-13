#pragma once
#include<iostream>

#include "CardDeck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

class Game
{
	private:
	CardDeck carddeck;
	Player player;
	Dealer dealer;
	public:
	void Play();
	void StartPhase();
};

void Game::Play()
{
	StartPhase();
}

void Game::StartPhase()
{
	carddeck.initCards();
	
	for(int i = 0; i < 2; i++)
	{
		player.receiveCard(carddeck.drawCard());
		dealer.receiveCard(carddeck.drawCard());
	}
	player.showCards();
	dealer.showCards();
}