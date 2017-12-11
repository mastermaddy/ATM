#ifndef CARD_H
#define CARD_H
#include "account.h"

using namespace std;

class Account;

class Card{
	int number;
	int pin;
	Account* account;//account with the card
	public:
		Card();
		Card(const Card&);
		Card(int, int);
		bool validatePin(int );
		Account* getAccount();
		void setAccount(Account*);
		int getNumber();
		~Card();
};


#endif
