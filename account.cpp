#include "account.h"
#include <iostream>
#include "record.h"
#include "deposit.h"
#include "withdrawal.h"

using namespace std;

Account::Account()
{
	number=-1;//default value to indicate invalid account number
	balance=0;
	card=NULL;
	records=NULL;
	record_no=0;
}

Account::Account(const Account& a)
{
	number=a.number;
	balance=a.balance;
	card=a.card;
	records=a.records;
	record_no=a.record_no;
}


void Account::setCard(Card* c)
{
	card=c;
}

Account::Account(int num)
{
	number=num;
	balance=0;
	card=NULL;
	records=NULL;
	record_no=0;
}

Card*  Account::getCard()
{
	return card;
}


Account::Account(int num, int amount)
{
	number=num;
	balance=amount;
	card=NULL;
	records=NULL;
	record_no=0;
}

void Account::setNumber(int n)
{
	//validate if necessary
	if(number==-1)
	{
		number=n;
	}
	else
	{
		cout<<"Illegal operation.Account number already present.\n";
	}
}

int Account::getNumber()
{
	return number;
}

int Account::getBalance()
{
	return balance;
}

bool Account::makeDeposit(int amount)
{
	if(number!=-1)//checking if account is invalid
	{
		if(amount>=0)
		{
			balance+=amount;
			//cout<<"Deposit Successful\n";
			Deposit d(getRecordNo(),amount);
			addRecord(d);
			return true;
		}
		else
		{
			cout<<"Negative amount can't be deposited.\n";
		}
	}
	else
	{
		cout<<"Deposit failed.Invalid account.\n";
	}
	return false;

}

bool Account::makeWithdrawal(int amount)
{
	if(number!=-1)//checking if account is invalid.
	{
		if(amount<=balance)
		{
			balance-=amount;
			//*************     create a withdrawl record
			//cout<<"Withdrawal Successful\n";
			Withdrawal w(getRecordNo(), amount);
			addRecord(w);
			return true;
		}
		else
		{
			//cout<<"Withdrawal failed.Insufficient funds.\n";
			return false;
		}
	}
	else
	{
		cout<<"Withdrawal failed.Invalid account.\n";
	}
	
}


int Account::getRecordNo()
{
	record_no++;
	return record_no;
}

void Account::addRecord(Record r)
{
	Rlist* ptr;
	Rlist* rptr;
	rptr= new Rlist;
	rptr->R=r;
	rptr->next=NULL;
	ptr=records;
	if(ptr==NULL)
	{
		records=rptr;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=rptr;
	}
}

void Account::printRecords()
{
	Rlist* ptr;
	ptr=records;
	if(ptr==NULL)
	{
		cout<<"\nNo Records found for Account Nubmer: "<<getNumber()<<".\n";
	}
	else
	{
		cout<<"\nRecords for Account Number : "<<getNumber()<<endl;
		while(ptr!=NULL)
		{
			ptr->R.printRecord();
			ptr=ptr->next;

		}
	}
}

void Account::addCard(Card c)
{
	card=&c;
}

Account::~Account()//freeing up heap space.
{

	Rlist* ptr;
	Rlist* temp;
	ptr=records;
	while(ptr!=NULL)
	{
		temp=ptr;
		ptr=ptr->next;
		delete temp;
	}
    card->~Card();

}
