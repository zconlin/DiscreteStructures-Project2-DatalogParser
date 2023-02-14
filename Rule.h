//
// Created by zconlin on 2/8/2023.
//

#ifndef CS236PROJECT2_DATALOGPARSER_RULE_H
#define CS236PROJECT2_DATALOGPARSER_RULE_H

#include "Predicate.h"

using namespace std;

class Rule
{
public:
    Rule(vector<Predicate> predicateList, Predicate headPredicate) : predicateList(predicateList), headPredicate(headPredicate) {}
    Rule(){}

    Predicate headPredicate;
    vector<Predicate> predicateList;

    void addHead(Predicate a) {
        headPredicate = a;
    }

    void addPredicate(Predicate x) {
        predicateList.push_back(x);
    }

    void addPredicate(vector<Predicate> v) {
        predicateList.insert(predicateList.end(), v.begin(), v.end());
    }

    string toString() {
        string output = headPredicate.toString() + " :- ";
        for(int i = 0; i < predicateList.size()-1; i++) {
            output += predicateList[i].toString() + ",";
        }
        output += predicateList[predicateList.size()-1].toString();

        return output;
    }

private:
    string value;
};

#endif //CS236PROJECT2_DATALOGPARSER_RULE_H
