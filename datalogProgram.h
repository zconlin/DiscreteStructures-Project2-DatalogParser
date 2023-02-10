//
// Created by zconlin on 2/8/2023.
//

#ifndef CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
#define CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H

#include <vector>
#include "rule.h"

using namespace std;

class datalogProgram
{
public:
    datalogProgram(){}
    ~datalogProgram(){}

    vector<predicate> Schemes;
    vector<predicate> Facts;
    vector<predicate> Queries;
    vector<rule> Rules;
};

#endif //CS236PROJECT2_DATALOGPARSER_DATALOGPROGRAM_H
