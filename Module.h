/**

Module.h

**/

#ifndef _MODULE_H_
#define _MODULE_H_

using namespace std;

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

class NoMarkException: public exception {};

class Module
{ public:

    // constructor arguments are values for code, name, lect and cwWeight members;
    // exMark should be initalised to 0; map should be initially empty
    Module(string id, string title, string lecturer, int courseworkWeight);


    //newly added
    string getCode() const;

    string getName() const;

    map<string, float> getAllMarks();

    // add the average exam mark for this module, overwriting any previously-stored value
    void addExamMark(float mark);

    // add the average mark for a piece of coursework, overwriting any previously-stored value;
    // first argument is id of coursework piece
    void addCourseworkMark(string id, float mark);

    // returns true if module has an exam mark
    bool hasExamMark() const;

    // returns true if module has at least one coursework mark
    bool hasCourseworkMarks() const;

    // return exam mark; throw exception if module does not have one
    float examMark() const throw (NoMarkException);

    // return average coursework mark; throw exception if module has no coursework mark
    // if module has more than one coursework mark should assume they are equally weighted
    float averageCourseworkMark() const throw (NoMarkException);

    // return avarage mark for piece of coursework whose id is supplied as argument;
    // throw exception if there's no such mark
    float courseWorkMark(string id) const throw (NoMarkException);

    // return overall weighted average mark for module;
    // throw exception if module does not have both exam and coursedwork marks
    float overallAverageMark() const throw (NoMarkException);

  private:
    string code;  // e.g. "CE221"
    string name;  // could be several words
    string lect;  // essex userid, e.g. "sands"
    int cwWeight;  // stored as a percentage, e.g. 40 would mean 40%
    float exMark;  // average exam mark; 0 should be used to indicate module does not yet have an exam mark
    map<string, float> cwMarks;   // average mark for each piece of coursework
                                  // empty map should be used to indicate module has no coursework marks

  // should output module code name, lecturer name and all marks
  friend ostream& operator<<(ostream& str, const Module &m);
};

#endif
