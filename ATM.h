#ifndef ATM_H
#define ATM_H
#include "card.h"
#include "transaction.h"


using namespace std;

typedef struct transac_tag{
	Transaction t;
	struct transac_tag* next;
} Tlist;

class ATM{
	string name;
	Tlist* comp_transactions;
	int trans_no;
	Transaction curr_transaction;
	string admin_pword;
	public:
		ATM();
		ATM(string);
		void change_AdminPassword(string, string);
		int validate(string);
		void setName(string);
		string getName();
		bool deposit(Card, int, int);
		bool withdraw(Card, int, int);
		void checkBalance(Card, int);
		int getTrans_no();
		void startTransaction();
		void endTransaction();
		void addTransaction();
		void printTransactions();
		~ATM();
};

#endif
