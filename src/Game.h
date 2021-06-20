#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

#include "CardDeck.h"
#include "Player.h"
#include "Dealer.h"
#include "Rule.h"

using namespace std;

class Game
{
	private:
	CardDeck carddeck;
	Player player;
	Dealer dealer;
	Rule rule;
	public:
	void Play();
	void MenuPhase();
	void SettingPhase();
	void StartPhase();
	void PlayingPhase();
	void EndPhase();
};

void Game::Play()
{
	MenuPhase();
	//StartPhase();
	//PlayingPhase();
}

void Game::MenuPhase()
{
	int n;
	
	cout << "┌───────────────────┐" << endl;
	cout << "│                   │" << endl;
	cout << "│     B L A C K     │" << endl;
	cout << "│      J A C K      │" << endl;
	cout << "│                   │" << endl;
	cout << "└───────────────────┘" << endl;
	
	cout << "   1. Start Game" << endl;
	cout << "   2. Settings" << endl;
	cout << "   3. Credit" << endl;
	cout << "   4. Quit Game" << endl;
	
	while(1)
	{
		cout << "> ";
		cin >> n;
		if(0 < n && n <= 4) break;
		else
			cout << "Error : Invailed Input" << endl;
	}
	
	switch(n)
	{
		case 1:
			//system("cls");
			StartPhase();
			PlayingPhase();
			break;
		case 2:
			//SettingPhase();
			cout << "Coming Soon..." << endl;
			break;
		case 3:
			//CreditPhase();
			cout << "Developed by GolmokDaeBBang(@golmoking)" << endl;
			break;
		case 4:
			break;
	}
	
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
	
	bool isVaildInput, isPlayerStay, isDealerStay, isEndOfGame = false;
	
	while(!isEndOfGame)
	{
		carddeck.printCards();
		isVaildInput = false;
		cout << endl << "===== Player's Turn =====" << endl;
		player.showCards();
		cout << "Hit or Stay? (Hit : 1 ,Stay : 2, Show Dealer's Card : 3)" << endl;
		
		while(!isVaildInput)
		{
			cout << "> ";
			cin >> n;
			
			switch(n)
			{
			case 1:
				cout << "Hit!" << endl;
				player.receiveCard(carddeck.drawCard());
				isPlayerStay = false;
				isVaildInput = true;
				break;
			case 2:
				cout << "Stay!" << endl;
				isPlayerStay = true;
				isVaildInput = true;
				break;
			case 3:
				dealer.showCards();
				break;
			default:
				cout << "Error : Invailed Value" << endl;	
			}
		}
		
		if(rule.isBurst(player.getPointSum()))
		{
			cout << "Player's Burst! Dealer's Win!" << endl;
			isEndOfGame = true;
			continue;
		}
		
		cout << endl << "===== Dealer's Turn =====" << endl;
		
		if(dealer.isDealerCanHit())
		{
			cout << "Dealer chose Hit!" << endl;
			dealer.receiveCard(carddeck.drawCard());
			isDealerStay = false;
		}
		else
		{
			cout << "Dealer chose Stay!" << endl;
			isDealerStay = true;
		}
		
		if(rule.isBurst(dealer.getPointSum()))
		{
			cout << "Dealer's Burst! Player's Win!" << endl;
			isEndOfGame = true;
			continue;
		}
		
		if(isPlayerStay && isDealerStay)
		{
			isEndOfGame = true;
			EndPhase();
		}
	}
}

void Game::EndPhase()
{
	bool isPlayerBlackjack = rule.isBlackJack(player.getCards()), isDealerBlackjack = rule.isBlackJack(dealer.getCards());
	string winner;
	cout << "\n===== End Game =====" << endl;
			
	player.openCards();
	cout << endl;
	dealer.openCards();
	
	if (isPlayerBlackjack)
	{
		cout << "[♠♥♦♣]PLAYER'S BLACKJACK![♣♦♥♠]" << endl;
		winner = player.getName();
	}
	
	if (isDealerBlackjack)
	{
		cout << "[♠♥♦♣]DEALER'S BLACKJACK![♣♦♥♠]" << endl;
		
		winner = isPlayerBlackjack ? player.getName() : dealer.getName();
	}
	
	if(!isPlayerBlackjack && !isDealerBlackjack)
		winner = rule.getWinner(player.getPointSum(), dealer.getPointSum());
	
	cout << winner << "'s Victory!" << endl;
	
}