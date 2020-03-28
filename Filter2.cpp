/**

Filter2.cpp

**/

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "ReadWords.h"
#include "Filter2.h"

bool Filter2::filter(string word)
{
	/*
	Checks if word contains exactly 3 vowels
	if it passes then it returns true
	else returns false;
	*/

	bool has3vowels= false;

	if(word=="")
    {
        return false;
    }
	else
	{
	    int count = 0;
	    string vowels = "aeiou";
		for(int a = 0; a < word.length();a++)
            for (int i = 0; i < vowels.length(); i++)
            {
                word[a] = tolower(word[a]);
                if(word[a] == vowels[i])
                {
                    count++;
                }
            }

        for (int a = 0; a < word.length(); a++)
        {
            if (count ==3)
            {
                has3vowels = true;
            }
        }

		if (has3vowels)
		{
			return true;
		}
		else
		{
			return false;
		}

	}


}
