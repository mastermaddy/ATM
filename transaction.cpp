#include "transaction.h"

Transaction::Transaction()
{
	number=-1;
	Card_number=-1;
	amount=-1;
	status=UNDEFINED;
	type=INVALID;
}


Transaction::Transaction(int n, int cn, int at,Transaction_type tt)
{
	number=n;
	Card_number=cn;
	amount=at;
	type=tt;
	timeStamp=getTime();
}


void Transaction::setStatus(Status s)
{
	status=s;
}

void Transaction::setAmount(int n)
{
	amount=n;
}

void Transaction::setCardNumber(int cn)
{
	Card_number=cn;
}

void Transaction::setNumber(int n)
{
	number=n;
}


void Transaction::printTransaction()
{
	cout<<"Transaction Number :\t"<<number<<endl;
	cout<<"Card Number        :\t"<<Card_number<<endl;
	cout<<"Amount             :\t"<<amount<<endl;
	cout<<"Transaction Type   :\t";
	if(type==0)
	{
		cout<<"WITHDRAWAL"<<endl;
	}
	else
	{
		cout<<"DEPOSIT"<<endl;
	}
	cout<<"Status             :\t";
	if(status==0)
	{
		cout<<"FAILURE"<<endl;
	}
	else
	{
		cout<<"SUCCESS"<<endl;
	}
	cout<<"Time               :\t"<<timeStamp<<endl;
}

Transaction::~Transaction()
{
	
}
