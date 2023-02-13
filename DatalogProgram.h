//
// Created by zconlin on 2/8/2023.
//

#ifndef CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
#define CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H

#include <vector>
#include <set>
#include "Rule.h"
#include "Predicate.h"

using namespace std;

class DatalogProgram
{
public:
    DatalogProgram(vector<Predicate> Schemes, vector<Predicate> Facts, vector<Predicate> Queries, vector<Rule> Rules):
    Schemes(Schemes), Facts(Facts), Queries(Queries), Rules(Rules) {}
    ~DatalogProgram(){}

    vector<Predicate> Schemes;
    vector<Predicate> Facts;
    vector<Predicate> Queries;
    vector<Rule> Rules;
    set<Parameter> Domain;

    string toString() {
//        Predicate::toString();
//        Rule::toString();

//        string schemesString;
//        string factsString;
//        string queriesString;
//        string rulesString;
//        string domainString;
//        string output;

//        schemesString = "Schemes(" + Schemes.size() + "):" << endl;
//        factsString = "Facts(" << Facts.size() << "):" << endl;

//        return output;
    }
};

#endif //CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
