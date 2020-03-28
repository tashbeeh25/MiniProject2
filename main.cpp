/**

main.cpp

**/

using namespace std;

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Module.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ostream>

int main()
{
	/*
	attempt to open and read from a text file,
	whose name is supplied by the user.
	Each line of the file will contain the module id,
	the lecturer id,  the coursework weighting and name of a module;
	these are supplied as arguments to the Module constructor to
	create a new module object that is added to a collection of modules.
	This collection is a vector
	*/
	string fileN1;
	string fileN2;
	vector<Module> mod;
	string id;
	string title;
	string lecturer;
	int courseworkw;
	float mark;
	bool failed = true;

	cout << "Enter file name with module details: " << endl;
	cin >> fileN1;
	ifstream firstFile(fileN1.c_str());

	if(!firstFile.is_open())
	{
		cout << "Sorry failed to open the file" <<endl;
        cout << "we are exiting the program" <<endl;
		failed = false;
	}
	else
	{
		vector<Module>::iterator it;
		while (firstFile >> id)
		{
			Module m(id, title, lecturer, courseworkw);
			cout << m << endl;
			mod.push_back(m);
		}

	}

	cout << endl;

	//  attempt to open and read from another text file, whose name is supplied by the user.
	// Each line of this file will contain a module id,
	// an assessment component and the average mark for that component

	if(failed){
		cout << "Enter file name with marks: " << endl;
		cin >> fileN2;

		ifstream secondFile(fileN2.c_str());

		if(!secondFile.is_open())
		{
			cout << "Sorry failed to open the file" <<endl;
			cout << "we are exiting the program" <<endl;
			failed = false;
		}
		else
        {
            vector<Module>::iterator it;
            while (secondFile >> id)
            {
                for (vector<int>::size_type i = 0; i != mod.size(); i++)
                {
                    if (mod[i].getCode()== id)
                    {
                        mod[i].addCourseworkMark(id, mark);

                    }else
                    {
                        cout << "No matching student with code - " << id <<endl;
                    }
                }
            }
        }

	}
}
