#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "record.h"
#include "card.h"

using namespace std;

typedef struct record_tag{
	Record R;
	struct record_tag* next;
} Rlist;

class Card;

class Account{

	int number;
	int balance;
	Card* card;
	Rlist* records;
	int record_no;
	public:
		Account();
		Account(const Account&);
		Account(int);
		Account(int, int);
		void setNumber(int);
		int getNumber();
		int getBalance();
		Card* getCard();
		bool makeDeposit(int);
		bool makeWithdrawal(int);
		void setCard(Card *);
		int getRecordNo();
		void addRecord(Record);
		void printRecords();
		void addCard(Card);
		~Account();
};


#endif

