/**

Filter2.h

**/

#ifndef _FILTER2_H_
#define _FILTER2_H_

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "ReadWords.h"

class Filter2: public ReadWords
{
	public:
		/*
			returns true if word passes condition
		*/
		Filter2(const char *fname):ReadWords(fname)
		{
		}

		bool filter(string word);
};

#endif
