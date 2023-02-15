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
    Schemes(Schemes), Facts(Facts), Queries(Queries), Rules(Rules) {
        Domain = set<string>();
        for (const Predicate &predicate : Facts) {
            for (const Parameter &parameter : predicate.parameterList) {
                if (!parameter.isID) {
                    Domain.insert(parameter.value);
                }
            }
        }
    }
    DatalogProgram(){}
    ~DatalogProgram(){}

    vector<Predicate> Schemes;
    vector<Predicate> Facts;
    vector<Predicate> Queries;
    vector<Rule> Rules;
    set<string> Domain;




    string toString() {
//        {
//            string output;
//            output = "Schemes(" + intToString(Schemes.size()) + "):\n";
//            for(int i = 0; i < Schemes.size(); i++)
//            {
//                output += "  " + Schemes[i].toString() + "\n";
//            }
//            output += "Facts(" + intToString(Facts.size()) +  "):\n";
//            for(int i = 0; i < Facts.size(); i++)
//            {
//                output += "  " + Facts[i].toString() + ".\n";
//            }
//            output += "Rules(" + intToString(Rules.size()) + "):\n";
//            for(int i = 0; i < Rules.size(); i++)
//            {
//                output += "  " + Rules[i].toString() + ".\n";
//            }
//
//            output += "Queries(" + intToString(Queries.size()) + "):\n";
//            for(int i = 0; i < Queries.size(); i++)
//            {
//                output += "  " + Queries[i].toString() + "?\n";
//            }
//
//            output += "Domain(" + intToString(Domain.size()) + "):\n";
//            for(int i = 0; i < Domain.size(); i++)
//            {
//                output += "  " + Domain[i] + "\n";
//            }
//            return output;
//        }

//        string DatalogProgram::intToString(int x) {
//            stringstream convert;
//            convert << x;
//            string output = convert.str();
//            return output;
//        }
        
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
