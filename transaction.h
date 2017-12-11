#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <time.h>
using namespace std;

//something has to stored in transaction
//to make it more useful

typedef enum Status_tag {
	FAILED,SUCCESS,UNDEFINED
} Status;

typedef enum Transaction_type {
	WITHDRAWAL, DEPOSIT,INVALID
} Transaction_type;


class Transaction{
	int number;
	int Card_number;
	int amount;
	string timeStamp;
	Status status;
	Transaction_type type;
	public:
		   Transaction();
		   Transaction(int, int, int, Transaction_type);
		   void setStatus(Status);
		   void setCardNumber(int);
		   void setAmount(int);
		   void setNumber(int);
		   void printTransaction();
		   ~Transaction();
		   string getTime()
			{
			    time_t     now = time(0);
			    struct tm  tstruct;
			    char       buf[80];
			    tstruct = *localtime(&now);
			    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
			    return buf;
			}

};

#endif
