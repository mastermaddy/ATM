#include "card.h"
#include "atm.h"
#include "account.h"
#include <iostream>


using namespace std;

ATM::ATM()
{
	comp_transactions=NULL; 
	trans_no=0;
	admin_pword="admin";
}

ATM::ATM(string s)
{
	name=s;
	comp_transactions=NULL;
	trans_no=0;
	admin_pword="admin";
}

void ATM::change_AdminPassword(string curr_pword,string new_pword)
{
	if(curr_pword==admin_pword)
	{
		admin_pword=new_pword;
		cout<<"\nPassword Successfully changed.\n";
	}
	else
	{
		cout<<"\nAdmin Password entered is incorrect. Please try again.\n";
	}
}

int ATM::validate(string pword)
{
	return (pword==admin_pword);
}

void ATM::setName(string n)
{
	name=n;
}

string ATM::getName()
{
	return name;
}

int ATM::getTrans_no()
{
	trans_no++;
	return trans_no;
}

void ATM::addTransaction()
{
	Tlist* tptr;
	Tlist* ptr;
	ptr=comp_transactions;
	tptr=new Tlist;
	tptr->t=curr_transaction;
	tptr->next=NULL;
	if(ptr==NULL)
	{
		comp_transactions=tptr;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=tptr;
	}
	
}


bool ATM::deposit(Card C, int pin, int amount)
{
	bool ret_val;
	startTransaction();
	curr_transaction=Transaction(getTrans_no(),C.getNumber(),amount,DEPOSIT);
	Account *acc=C.getAccount();
	
	if(C.validatePin(pin))
	{
		ret_val=acc->makeDeposit(amount);
		if(ret_val)
		{
			cout<<"\nDeposit Successful"<<endl;
			curr_transaction.setStatus(SUCCESS);
		}
		else
		{
			cout<<"\nDeposit Unsuccessful."<<endl;
			curr_transaction.setStatus(FAILED);
		}
		endTransaction();
		addTransaction();
		return ret_val;
	}
	else
	{
		cout<<"\nIncorrect PIN.Please try again."<<endl;
		curr_transaction.setStatus(FAILED);
		endTransaction();
		addTransaction();
		return false;
	}

}

bool ATM::withdraw(Card C, int pin, int amount)
{
	bool ret_val;
	startTransaction();
	curr_transaction=Transaction(getTrans_no(),C.getNumber(),amount,WITHDRAWAL);
	Account *acc=C.getAccount();
	//cout<<C.getNumber()<<endl;
	if(C.validatePin(pin))
	{
		ret_val=acc->makeWithdrawal(amount);
		if(ret_val==false)
		{
			cout<<"\nInsufficient funds in your account."<<endl;
			curr_transaction.setStatus(FAILED);
		}
		else
		{
			cout<<"\nWithdarwal Successful."<<endl;
			curr_transaction.setStatus(SUCCESS);
		}
		endTransaction();
	    addTransaction();
		return ret_val;
	}
	else
	{
	    cout<<"\nIncorrect PIN.Please try again.\n";
		curr_transaction.setStatus(FAILED);
		endTransaction();
		addTransaction();
		return false;
	}
}

void ATM::checkBalance(Card C,int pin)
{
	//for simplicity, checking balance is not a transaction.
    Account *acc=C.getAccount();
	if(C.validatePin(pin))
	{
		cout<<"\nBalance in Acount No."<<acc->getNumber()<<" is "<<acc->getBalance()<<endl;
	}
	else
	{
		cout<<"\nIncorrect Pin. Please try again."<<endl;
	}
}

void ATM::startTransaction()
{

}

void ATM::endTransaction()
{
	
}

void ATM::printTransactions()
{
	Tlist* ptr;
	ptr=comp_transactions;
	cout<<"\n";
	
	if(ptr==NULL)
	{
		cout<<"No Transactions found.\n";
	}
	else
	{
		cout<<"\nTransactions on this ATM are : \n\n";
		while(ptr!=NULL)
		{

			ptr->t.printTransaction();
			cout<<"\n";
			ptr=ptr->next;
		}
		cout<<"\n";
	}
}

ATM::~ATM()
{

	Tlist* ptr;
	Tlist* temp;
	ptr=comp_transactions;
	while(ptr!=NULL)
	{
		temp=ptr;
		ptr=ptr->next;
		delete temp;
	}
}
