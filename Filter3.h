/**

Filter2.h

**/

#ifndef _FILTER3_H_
#define _FILTER3_H_

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "ReadWords.h"

class Filter3: public ReadWords
{
	public:
		/*
            returns true if word passes condition
		*/
		Filter3(const char *fname):ReadWords(fname)
		{
		}

		bool filter(string word);
};

#endif
