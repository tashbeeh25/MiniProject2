/**

Module.cpp

**/

#include <string>
#include <map>
#include <stdexcept>
#include "Module.h"
#include <iostream>
#include <iomanip>

using namespace std;

Module::Module(string id, string title, string lecturer, int courseworkWeight)
{

	this->code = id;
	this->name = lecturer;
	this->cwMarks.clear();

}

//returns code
string Module::getCode() const
{
	return this->code;
}

//returns name
string Module::getName() const
{
    return this->name;
}

//returns map of marks
map<string, float> Module::getAllMarks()
{

	return this->cwMarks;
}


// adds the average exam mark for this module, overwriting any previously-stored value
void Module::addExamMark(float mark)
{
    this->exMark = mark;
}

// adds the average mark for a piece of coursework, overwriting any previously-stored value;
// first argument is id of coursework piece
void Module::addCourseworkMark(string id, float mark)
{
    cwMarks[id] = mark;
}

// returns true if module has an exam mark
bool Module::hasExamMark() const
{
    return !(exMark == 0);
}

// returns true if module has at least one coursework mark
bool Module::hasCourseworkMarks() const
{
    return !(cwMarks.empty());
}

// returns exam mark; throw exception if module does not have one
float Module::examMark() const throw (NoMarkException)
{
    if (exMark == 0)
    {
        throw new NoMarkException;
    }
    else
    {
        return exMark;
    }
}

// returns average coursework mark; throw exception if module has no coursework mark
// if module has more than one coursework mark should assume they are equally weighted
float Module::averageCourseworkMark() const throw (NoMarkException)
{

    int count = 0;
    float sum = 0.0;
    if (cwMarks.empty())
    {
        throw new NoMarkException;
    }else
    {
        for (map<string,float>::const_iterator it = this->cwMarks.begin(); it!= this->cwMarks.end(); ++it)
        {
            float value = it->second;
            sum += value;
            count++;

        }

	}
	float average = sum/count;

	return average;
}

// returns avarage mark for piece of coursework whose id is supplied as argument;
// throw exception if there's no such mark
float Module::courseWorkMark(string id) const throw (NoMarkException)
{
    if (cwMarks.empty())
    {
        throw new NoMarkException;
    }else
    {
        for (map<string,float>::const_iterator it = this->cwMarks.begin(); it!= this->cwMarks.end(); ++it)
        {
            if(it->first==id)
            {
                return it->second;
            }
        }
        throw new NoMarkException;
    }
}


// returns overall weighted average mark for module;
// throw exception if module does not have both exam and coursedwork marks
float Module::overallAverageMark() const throw (NoMarkException)
{
    if (cwMarks.empty() && exMark ==0)
    {
        throw new NoMarkException;
    }
    else
    {

        return exMark * (100 - cwWeight) / 100;
        return averageCourseworkMark() * cwWeight;

    }
}

ostream& operator<<(ostream &str, const Module &m)
{
    str << left << setw(32) << m.getCode();
	return str;
}


