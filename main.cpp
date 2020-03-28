/**

main.cpp

**/

#include "ReadWords.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Filter1.h"
#include "Filter2.h"
#include "Filter3.h"
#include <map>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <ctype.h>

#include<conio.h>

using namespace std;

int main()
{

	string fileN;

	int filter;
	bool fail = true;

	//enter the name of file
	cout << "Enter the name of file you would like to open: " << endl;
	cin >> fileN;

	//menu to choose the type of filter
	cout << endl;
	cout << "1. Contains atleast 1 lower-case letter" << endl;
	cout << "2. Contains exactly 3 vowels" << endl;
	cout << "3. Contains no letters" << endl;
	cout << "Enter the number of filter type (1-3): " << endl;

	cin >> filter;
	ReadWords *read;
	cout << endl;


    map<string, int> occ; //map to hold occurrence

    //opens the filter file which the user chose in the menu

    if(filter==1)
    {
		read =  new Filter1(fileN.c_str());
	}
	else if(filter==2)
	{
		read = new Filter2(fileN.c_str());
	}
	else if(filter==3)
	{
		read = new Filter3(fileN.c_str());
    }
	else
	{
		cout << "Sorry! Invalid filter type. Enter numbers 1-3 only " << endl;
		fail = false;
	}


	if(fail)
    {
		int countOne = 0;

		//stores filtered words in a map

		string filtW = read->getNextFilteredWord();
		while(filtW != "")
		{
			occ[filtW] = occ[filtW] + 1;
			countOne++;
			filtW= read->getNextFilteredWord();

		}


		int maxi = 0;
		int mini = numeric_limits<int>::max();

		//iterates through the map and gets the second item (value) to compare against maximum and minimum
		for (map<string,int>::iterator it = occ.begin(); it!= occ.end(); ++it)
		{
			if(it->second > maxi)
			{
				maxi = it->second;
			}
			if(it->second < mini)
			{
				mini = it->second;
			}


		}

		// prints out the number of entries

		cout << "Number of entries found: " << countOne <<endl;
		cout << endl;
		if(mini==1){
			cout << "Minimum occurrences: " << mini << endl;
		}
		else
		{
			cout << "Minimum occurrences: " << mini << endl;
		}


		int countx = 0;
		int county = 0;

		// iterates through map and prints out the first 20 minimum

		for (map<string,int>::iterator it = occ.begin(); it!= occ.end(); ++it)
        {
            if(it->second == mini && countx < 21)
            {
                cout << left << setw(20) << it->first << setw(5) << endl;
                countx++;
            }
            if(countx>20)
            {
                county++;
            }
		}

		if(county>0)
		{
			cout << "and ->" << county << " more words" <<endl;
		}

		cout << endl;

		countx = 0;
		county = 0;

		// iterates through map and prints the first 20 maximum

		if(maxi==1)
		{
			cout << "Maximum occurrences: " << maxi << endl;
		}
		else{
			cout << "Maximum occurrences: " << maxi <<endl;
		}
		for (map<string,int>::iterator it = occ.begin(); it!= occ.end(); ++it)
		{
			if(it->second == maxi && countx < 21)
			{
				cout << left << setw(20) << it->first << setw(5) <<endl;
				countx++;
			}
			if(countx>20)
			{
				county++;
			}
		}
		if(county>0)
        {
            cout << "and ->" << county << " more words" <<endl;
		}

	}

}
