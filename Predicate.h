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
    Predicate(string value, vector<Parameter> parameterList): parameterList(parameterList), name(value) {}
    Predicate() {}

    vector<Parameter> parameterList;
    string name;

//    void addParameter(Parameter param) {
//        parameterList.push_back(param);
//    }
//
//    void addParameter(vector<Parameter> params) {
//        parameterList.insert(parameterList.end(),params.begin(), params.end());
//    }

    string toString() {
        string output;
        output = name + "(";
        for(const auto& i : parameterList) {
            output = output + i.value + ",";
        }
        output += parameterList[parameterList.size()-1].value + ")";

        return output;
    }

};

#endif /* CS236PROJECT2_DATALOGPARSER_PREDICATE_H_ */