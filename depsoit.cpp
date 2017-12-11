#include<iostream>
#include "record.h"
#include "deposit.h"

using namespace std;

Deposit::Deposit()
{
	type="DEPOSIT";
}

Deposit::Deposit(int n, int a)
{
	number=n;
	amount=a;
	timeStamp=getTime();
	type="DEPOSIT";
}

Deposit::~Deposit()
{
	
}
