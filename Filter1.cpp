/**

Filter1.cpp

**/

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "ReadWords.h"
#include "Filter1.h"
#include <algorithm>

bool Filter1::filter(string word)
{
	/*
	Checks if word has atleast one lower case letter
	if it passes the check then it returns true
	else returns false;
	*/

	bool lowerCase = false;
	bool noLower  = true;
	if(word=="")
    {
        return false;
    }
	else
	{
		for(int a = 0; a < word.length();a++)
		{

			if(islower(word[a]))
			{
				lowerCase = true;
			}
		}

		if (lowerCase&&noLower)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

}
