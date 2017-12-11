#include "card.h"
#include <iostream>

using namespace std;

Card::Card()
{
	number=-1;
	pin=-1;
	account=NULL;
}

Account* Card::getAccount()
{
	return account;
}

int Card::getNumber()
{
	return number;
}

void Card::setAccount(Account* a)
{
	account=a;
}

Card::Card(const Card& c)
{
	number=c.number;
	pin=c.pin;
	account=c.account;
}

Card::Card(int n, int p)//take care of account being passed in constructor
{
	if(n!=-1&&p!=-1)
	{
		number=n;
		pin=p;
	}
	else
	{
		cout<<"Card creation failed.Don't use -1 as card number or pin.\n";

		int flag=1;
		//taking correct input from user
		while(flag)
		{
			cout<<"Enter Card Number and PIN again: ";
			cin>>n>>p;
			if(n!=-1&&p!=-1)
			{
				number=n;
				pin=p;
				flag=0;
			}
			else
			{
				cout<<"Card creation failed.Don't use -1 as card number or pin.\n";
			}
		}
	}
	
}

bool Card::validatePin(int p)
{
	if(number!=-1)
	{
		if(pin==p)
		{
			return true;
		}
	}
	else
	{
		cout<<"Pin validation failed. Invalid Card.\n";
	}
	return false;
}


Card::~Card()//to be implemented if heap memory is used
{
	
}

