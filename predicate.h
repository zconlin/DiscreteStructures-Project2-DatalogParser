//
// Created by zconlin on 2/8/2023.
//

#ifndef CS236PROJECT2_DATALOGPARSER_PREDICATE_H
#define CS236PROJECT2_DATALOGPARSER_PREDICATE_H

#include <string>
#include <vector>
#include "Parameter.h"

using namespace std;

class predicate
{
public:
    predicate(string name) {
        string thisName = name;

        addParameter(parameter p);
            items.push_back(p);
    }
private:
    string name;
    vector<Parameter> items;
};

#endif /* CS236PROJECT2_DATALOGPARSER_PREDICATE_H_ */