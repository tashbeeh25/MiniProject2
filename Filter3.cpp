/**

Filter3.cpp

**/

using namespace std;

#include <string>
#include <iostream>
#include <fstream>
#include "ReadWords.h"
#include "Filter3.h"
#include <cctype>
#include <stdio.h>
#include <ctype.h>

bool Filter3::filter(string word)
{
	/*
		Checks if word is not a letter
		if it passes check,it returns true
		else returns false;
	*/

	bool noletters= false;

	if(word=="")
    {
        return false;
    }
	else
	{
		int count = 0;

		for(int a = 0; a < word.length(); a++)
		{
			if (isalpha(word[a])){count++;};
		}
		if(count==0)
		{
		    noletters = true;
        }



		if (noletters)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


}
