#include "account.h"
#include "card.h"
#include "ATM.h"
#include <iostream>
#include <time.h>

using namespace std;

typedef struct card_tag{
	Card C;
	struct card_tag* next;
} Clist;


int checkInt(string s)
{
	int flag=1;
	int l=s.size();
	for(int i=0;i<l&&flag;i++)
	{
		if(s[i]<'0'||s[i]>'9')
		{
			flag=0;
		}
	}
	return flag;
}

int convtoInt(string s)
{
	int n=0;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		n=(n*10)+(s[i]-'0');
	}
	return n;
}

int main()
{
	int flag=1;
	int choice;
	int n,cn,amount,pin;
	string s;
	string pword;
	int cfound;
	Clist* ptr;
	Clist* nptr;
	Clist* cards;//for storing cards in database
	cards=NULL;
	bool status;
	
	ATM sbi("pk\'s");
	
	//temporary data
	/*
	Account pk(1,0);
	Card a(83,1996);
	pk.addCard(a);
	a.setAccount(&pk);
	
	Account ag(2,0);
	Card b(34,1996);
	ag.addCard(b);
	b.setAccount(&ag);
	
	nptr=new Clist;
	nptr->C=a;
	nptr->next=NULL;
	
	
	cards=nptr;
	
	nptr=new Clist;
	nptr->C=b;
	nptr->next=NULL;
	
	ptr=cards;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=nptr;
	*/
	cout<<"Admin password: admin\n";
	cout<<"Enter some data initially for ATM database.\n";
	cout<<"ATM won't work without entering accounts initially.\n\n";
	
	Account accs[5];
	Card c[5];
	int x,y,temp;
	
	cout<<"Enter number of accounts: ";
	cin>>temp;
	for(int i=0;i<temp;i++)
	{
		cout<<"Enter account number: ";
		cin>>x;
		accs[i].setNumber(x);
		cout<<"Enter card number: ";
		cin>>x;
		cout<<"Enter card pin: ";
		cin>>y;
		c[i]=Card(x,y);
		accs[i].addCard(c[i]);
		c[i].setAccount(&accs[i]);
		
		nptr=new Clist;
		nptr->C=c[i];
		nptr->next=NULL;

		if(cards==NULL)
		{
			cards=nptr;
		}
		else
		{
			ptr=cards;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=nptr;
		}
	}
	
	
	cout<<"\n\t\t --- WELCOME TO "<<sbi.getName()<<" ATM --- \n\n";
	cout<<"1.Check Balance \n";
	cout<<"2.Cash Withdrawal\n";
	cout<<"3.Cash Deposit\n";
	cout<<"4.Get Mini Statement\n";
	cout<<"5.Admin\n";
	cout<<"0.Exit\n";
	cout<<"Enter your choice : ";
	cin>>s;
	cout<<endl;
	while(!checkInt(s))
	{
		cout<<"Enter valid choice : ";
		cin>>s;
	}
	choice=convtoInt(s);
	
	while(choice)
	{
		switch(choice)
		{
			case 1: cout<<"Enter your Card Nubmer :";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid Card Number:";
						cin>>s;
					}
					cn=convtoInt(s);
					cout<<"Enter your PIN: ";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid PIN:";
						cin>>s;
					}
					pin=convtoInt(s);
					ptr=cards;
					cfound=0;
					while(ptr!=NULL&&!cfound)
					{
						if(ptr->C.getNumber()==cn)
						{
							cfound=1;
						}
						else
						{
							ptr=ptr->next;
						}
					}

					if(!cfound)
					{
						cout<<"Card Number not found.Please try again.\n";
					}
					else 
					{
						sbi.checkBalance(ptr->C,pin);
					}
					
					
					break;
					
			case 2: cout<<"Enter your Card Nubmer :";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid Card Number:";
						cin>>s;
					}
					cn=convtoInt(s);
					cout<<"Enter Amount : ";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter Valid Amount:";
						cin>>s;
					}
					amount=convtoInt(s);
					cout<<"Enter your PIN: ";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid PIN:";
						cin>>s;
					}
					pin=convtoInt(s);
					ptr=cards;
					cfound=0;
					while(ptr!=NULL&&!cfound)
					{
						if(ptr->C.getNumber()==cn)
						{
							cfound=1;
						}
						else
						{
							ptr=ptr->next;
						}
					}
					
					if(!cfound)
					{
						cout<<"Card Number not found.Please try again.\n";
					}
					else 
					{
						status=sbi.withdraw(ptr->C, pin, amount);

					}
					break;

			case 3: cout<<"Enter your Card Nubmer :";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid Card Number:";
						cin>>s;
					}
					cn=convtoInt(s);
					cout<<"Enter Amount : ";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid Amount:";
						cin>>s;
					}
					amount=convtoInt(s);
					cout<<"Enter your PIN: ";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid PIN:";
						cin>>s;
					}
					pin=convtoInt(s);
					ptr=cards;
					cfound=0;
					while(ptr!=NULL&&!cfound)
					{
						if(ptr->C.getNumber()==cn)
						{
							cfound=1;
						}
						else
						{
							ptr=ptr->next;
						}
					}

					if(!cfound)
					{
						cout<<"Card Number not found.Please try again.\n";
					}
					else
					{
						status=sbi.deposit(ptr->C, pin, amount);
					}
					break;
					
			case 4: cout<<"Enter your Card Nubmer :";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid Card Number:";
						cin>>s;
					}
					cn=convtoInt(s);
					cout<<"Enter your PIN: ";
					cin>>s;
					while(!checkInt(s))
					{
						cout<<"Enter valid PIN:";
						cin>>s;
					}
					pin=convtoInt(s);
					ptr=cards;
					cfound=0;
					while(ptr!=NULL&&!cfound)
					{
						if(ptr->C.getNumber()==cn)
						{
							cfound=1;
						}
						else
						{
							ptr=ptr->next;
						}
					}
					
					if(!cfound)
					{
						cout<<"Card Number not found.Please try again.\n";
					}
					else
					{
						Account* temp;
						temp=ptr->C.getAccount();
						temp->printRecords();
					}

					break;
					
			case 5: cout<<"Enter Admin password: ";
					cin>>pword;
					if(sbi.validate(pword))
					{
						int a;
						string cpword,npword;
						cout<<"\n\t\t -- ADMIN MODE --\n\n";
						cout<<"1.Print Transactions\n";
						cout<<"2.Change Admin Password\n";
						cout<<"3.Change ATM name\n";
						cout<<"0.Exit\n";
						cout<<"Enter your choice: ";
						cin>>s;
						cout<<endl;
						while(!checkInt(s))
						{
							cout<<"Enter valid choice : ";
							cin>>s;
						}
						a=convtoInt(s);
						
						while(a)
						{
							switch(a)
							{
								case 1: sbi.printTransactions();
										break;

								case 2: cout<<"Enter current password: ";
										cin>>cpword;
										cout<<"Enter new password: ";
										cin>>npword;
										sbi.change_AdminPassword(cpword,npword);
										break;
										
								case 3: cout<<"Enter new name: ";
										cin>>s;
										sbi.setName(s);
										break;
									
								default: cout<<"Enter Valid Option.\n";
										 break;
							}
							cout<<"\n\t\t -- ADMIN MODE --\n\n";
							cout<<"1.Print Transactions\n";
							cout<<"2.Change Admin Password\n";
							cout<<"3.Change ATM name\n";
							cout<<"0.Exit\n";
							cout<<"Enter your choice: ";
							cin>>s;
							cout<<endl;
							while(!checkInt(s))
							{
								cout<<"Enter valid choice : ";
								cin>>s;
							}
							a=convtoInt(s);
						}
					}
					else
					{
						cout<<"Incorrect Password. Please try again.\n";
					}
					break;

			default: cout<<"Enter a valid option.\n";
					 break;
					
				
		}
		
	    cout<<"\n\t\t --- WELCOME TO "<<sbi.getName()<<" ATM --- \n\n";
		cout<<"1.Check Balance \n";
		cout<<"2.Cash Withdrawal\n";
		cout<<"3.Cash Deposit\n";
		cout<<"4.Get Mini Statement\n";
		cout<<"5.Admin\n";
		cout<<"0.Exit\n";
		cout<<"Enter your choice : ";
		cin>>s;
		cout<<endl;
		while(!checkInt(s))
		{
			cout<<"Enter valid choice : ";
			cin>>s;
		}
		choice=convtoInt(s);
	}
	
	//write code for freeing up heap space of clist
	
	return 0;
}
