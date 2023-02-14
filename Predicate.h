//
// Created by zconlin on 2/8/2023.
//

#ifndef CS236PROJECT2_DATALOGPARSER_PREDICATE_H
#define CS236PROJECT2_DATALOGPARSER_PREDICATE_H

#include <string>
#include <vector>
#include "Parameter.h"

using namespace std;

class Predicate
{
public:
    Predicate(string value):value(value) {}
    Predicate() {}

    vector<Parameter> parameterList;

    void addParameter(Parameter param) {
        parameterList.push_back(param);
    }

    void addParameter(vector<Parameter> params) {
        parameterList.insert(parameterList.end(),params.begin(), params.end());
    }

    string toString() {
        string output;
        output = value + "(";
        for(int i = 0; i < parameterList.size()-1; i++) {
            output = output + parameterList[i].value + ",";
        }
        output += parameterList[parameterList.size()-1].value + ")";

        return output;
    }

private:
    string value;
    vector<Parameter> items;
};

#endif /* CS236PROJECT2_DATALOGPARSER_PREDICATE_H_ */