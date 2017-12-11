#include <iostream>
#include "withdrawal.h"
#include "record.h"

using namespace std;

Withdrawal::Withdrawal()
{
	type="WITHDRAWAL";
}

Withdrawal::Withdrawal(int n, int a)
{
	number=n;
	amount=a;
	timeStamp=getTime();
	type="WITHDRAWAL";
}

Withdrawal::~Withdrawal()
{
	
}

