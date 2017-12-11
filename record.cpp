#include "record.h"
#include <iostream>
#include <string>

using namespace std;

Record::Record()
{
	number=-1;
	amount=-1;
	timeStamp="INVALID";
	type="INVALID";
}


void Record::printRecord()
{
	cout<<"\n";
	cout<<"Record no. "<<number<<endl;
	cout<<"Type     : "<<type<<endl;
	cout<<"Amount   : "<<amount<<endl;
	cout<<"Time     : "<<timeStamp<<endl;
	cout<<"\n";
}

void Record::setAmount(int a)
{
	amount=a;
}

void Record::setNumber(int n)
{
	number=n;
}

Record::~Record()
{
	
}
