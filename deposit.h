#ifndef DEPOSIT_H
#define DEPOSIT_H
#include "record.h"

class Deposit: public Record{
	public:
		Deposit();
		Deposit(int, int);
		~Deposit();
};
	
#endif
