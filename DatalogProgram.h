//
// Created by zconlin on 2/8/2023.
//

#ifndef CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
#define CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H

#include <vector>
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

//    string toString() {
//        string output;
//        output = value + "(";
//        for(int i = 0; i < parameterList.size()-1; i++) {
//            output = output + parameterList[i].value + ",";
//        }
//        output += parameterList[parameterList.size()-1].value + ")";
//
//        return output;
//    }
};

#endif //CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
