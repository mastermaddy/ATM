#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H
#include "record.h"

class Withdrawal: public Record{
	public:
		Withdrawal();
		Withdrawal(int, int);
		~Withdrawal();
};

#endif
