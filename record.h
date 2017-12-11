#ifndef RECORD_H
#define RECORD_H
#include <string>
#include "time.h"

using namespace std;

class Record{
	protected:
		int number;
		int amount;
		string timeStamp;
		string type;
	public:
		Record();
		void printRecord();
		void setNumber(int);
		void setAmount(int);
		void setType(string);
		virtual ~Record();
		string getTime()
		{
		    time_t     now = time(0);
		    struct tm  tstruct;
		    char       buf[80];
		    tstruct = *localtime(&now);
		    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
		    return buf;
		}

};

#endif
