/**

Filter1.h

**/

#ifndef _FILTER1_H_
#define _FILTER1_H_

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "ReadWords.h"

class Filter1: public ReadWords
{
	public:

	    //returns true if passes condition

		Filter1(const char *fname):ReadWords(fname)
		{
		}

		bool filter(string word);
};

#endif



