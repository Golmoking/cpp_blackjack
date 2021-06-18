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
	void PlayingPhase();
};

void Game::Play()
{
	StartPhase();
	PlayingPhase();
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

void Game::PlayingPhase()
{
	int n;
	while(1)
	{
		cout << endl << "===== Player's Turn =====" << endl;
		cout << "Hit or Stay? (Hit : 1 ,Stay : 0)" << endl << "> ";
		cin >> n;
		
		if(n)
		{
			cout << "Hit!" << endl;
			player.receiveCard(carddeck.drawCard());
			player.showCards();
		}
		else
		{
			cout << "Stay!" << endl;
			player.showCards();
		}
		
		cout << endl << "===== Dealer's Turn =====" << endl;
		if(dealer.isDealerCanHit())
		{
			cout << "Dealer chose Hit!" << endl;
			dealer.receiveCard(carddeck.drawCard());
		}
		else
		{
			cout << "Dealer chose Stay!" << endl;
		}
		
		
	}
}