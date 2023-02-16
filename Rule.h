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
    Rule(Predicate headPredicate, vector<Predicate> predicateList)
            : headPredicate(headPredicate), predicateList(predicateList) {}
    Rule(){}

    Predicate headPredicate;
    vector<Predicate> predicateList;

    string toString() {
        string output = headPredicate.toString() + " :- ";
        for(auto i : predicateList) {
            output += i.toString() + ",";
        }
        output += predicateList[predicateList.size()-1].toString();

        return output;
    }

private:
    string value;
};

#endif //CS236PROJECT2_DATALOGPARSER_RULE_H
