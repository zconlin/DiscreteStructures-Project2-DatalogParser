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
    DatalogProgram(){}
    ~DatalogProgram(){}

    vector<Predicate> Schemes;
    vector<Predicate> Facts;
    vector<Predicate> Queries;
    vector<Rule> Rules;
};

#endif //CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
