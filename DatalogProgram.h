//
// Created by zconlin on 2/8/2023.
//

#ifndef CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
#define CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H

#include <vector>
#include <set>
#include "Rule.h"

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
        string output;
        output = "DatalogProgram toString";

        return output;
    }
};

#endif //CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
