//
// Created by zconlin on 2/2/2023.
//

// "..\\tests\project2-tests\in21.txt"

// Write parsing functions for the remaining grammar rules.
// Fix error handling in the parser. (Throw an Exception in the 'throwError' function.) (Catch the Exception at the top of the parser and report the error.)
// Write classes for Parameter, Predicate, Rule, and Datalog Program.
// Add code to the parser to create Parameter, Predicate, and Rule objects while parsing, and construct a Datalog Program object that contains lists of Schemes, Facts, Rules, and Queries.

// What should main look like?

#pragma once

#include "token.h"
#include "scanner.h"
#include "Parameter.h"
#include "Predicate.h"
#include "DatalogProgram.h"
#include <vector>
#include <iostream>

class Parser {
private:
    vector<Token> tokens;
public:
    string toString() {
        stringstream output;
        int numTokens;
        output << tokenString() << " (" << numTokens << ") :" << endl;

        return output.str();
    }

    Parser(const vector<Token>& tokens) : tokens(tokens) {
        if(tokenType() == COMMENT) {
            advanceToken();
        }
    }

    TokenType tokenType() const { // Returns the type of the current Token
        return tokens.at(0).getType();
    };

    string tokenString() {
        return tokens.at(0).getValue();
    }

    void advanceToken() { // Moves to the next Token
        tokens.erase(tokens.begin());
    }

    void throwError() { // Is called when the Parser finds an error
//        throw "Error";
//cout << "Error"; //debug
    }

    int c = 0;
    void match(TokenType t) {
        if (tokens.at(c).getType() == END) {

        }
        if (tokens.at(c).getType() == t) {
            cout << tokens.at(c).getValue(); //debug
            advanceToken();
        }
        else {
            throwError();
        }
    }

    //// DatalogProgram     ----------------------------------------------------------------------------------
    //// datalogProgram	->	SCHEMES COLON scheme schemeList
    ////		        FACTS COLON factList
    ////		        RULES COLON ruleList
    ////		        QUERIES COLON query queryList
    ////    			EOF
    DatalogProgram datalogProgram () {
            match(SCHEMES);
            match(COLON);
            scheme();
            schemeList();
            match(FACTS);
            match(COLON);
            factList();
            match(RULES);
            match(COLON);
            ruleList();
            match(QUERIES);
            match(COLON);
            query();
            queryList();
            match(END);
            return datalogProgram();
    }

    //// schemeList	->	scheme schemeList | lambda
    void schemeList() {
        if(tokenType() == ID) {
            scheme();
            schemeList();
        } else {
            // lambda
        }
    }

    //// factList	->	fact factList | lambda
    void factList() {
        if(tokenType() == ID) {
            fact();
            factList();
        } else {
        // lambda
        }
    }

    //// ruleList	->	rule ruleList | lambda
    void ruleList() {
        if(tokenType() != QUERIES) {
            rule();
            ruleList();
        } else {
        // lambda
        }
    }

    //// queryList	->	query queryList | lambda
    void queryList() {
        if(tokenType() == ID) {
            query();
            queryList();
        } else {
        // lambda
        }
    }

    //// SCHEME     ----------------------------------------------------------------------------------
    //// scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
     void scheme() {
        if (tokenType() == ID) {
            match(ID);
            match(LEFT_PAREN);
            match(ID);
            idList();
            match(RIGHT_PAREN);
        }
    }

    //// FACT     ----------------------------------------------------------------------------------
    //// fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    void fact() {
        if (tokenType() == ID) {
            match(ID);
            match(LEFT_PAREN);
            match(STRING);
            // string value to string vector? Not quite but close
            stringList();
            match(RIGHT_PAREN);
            match(PERIOD);
            // push to datalogProgram fact vector
            DatalogProgram::Facts.push_back();
        }
    }

    //// RULE     ----------------------------------------------------------------------------------
    //// rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
    void rule() {
        if (tokenType() == ID) {
            headPredicate();
            match(COLON_DASH);
            predicate();
            predicateList();
            match(PERIOD);
        }
    }

    //// QUERY     ----------------------------------------------------------------------------------
    //// query	        ->      predicate Q_MARK
    Predicate query() {
        if (tokenType() == ID) {
            predicate();
            match(Q_MARK);
            return Predicate(tokenString());
        }
    }

    //// headPredicate     ----------------------------------------------------------------------------------
    //// headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    Predicate headPredicate() {
//        if (TokenType() == ID) {
            match(ID);
            match(LEFT_PAREN);
            match(ID);
            idList();
            match(RIGHT_PAREN);
            return Predicate(tokenString());
//        }
        return Predicate();
    }

    //// predicate     ----------------------------------------------------------------------------------
    //// predicate	->	ID LEFT_PAREN Parameter parameterList RIGHT_PAREN
    Predicate predicate() {
        if (tokenType() == ID) {
            match(ID);
            match(LEFT_PAREN);
            parameter();
            parameterList();
//            vector;
            match(RIGHT_PAREN);
            return Predicate(tokenString());
        }
    }

    //// predicateList     ----------------------------------------------------------------------------------
    //// predicateList	->	COMMA predicate predicateList | lambda
    vector<Parameter> predicateList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            predicate();
            predicateList();
            return vector<Parameter>();
        } else {
            // lambda
        }
        return {};
    }

    //// parameterList     ----------------------------------------------------------------------------------
    //// parameterList	-> 	COMMA Parameter parameterList | lambda
    vector<Parameter> parameterList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            parameter();
            parameterList();
            return vector<Parameter>();
        } else {
            // lambda
        }
        return {};
    }

    //// stringList     ----------------------------------------------------------------------------------
    //// stringList	-> 	COMMA STRING stringList | lambda
    vector<Parameter> stringList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            match(STRING);
            stringList();
            return vector<Parameter>();
        } else {
        // lambda
    }
    return {};
}

    //// ID         ----------------------------------------------------------------------------------
    //// idList  	-> 	COMMA ID idList | lambda
    vector<Parameter> idList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            match(ID);
            idList();
        return vector<Parameter>();
        } else {
            // lambda
        }
        return {};
    }

    //// Parameter     ----------------------------------------------------------------------------------
    //// Parameter	->	STRING | ID
    Parameter parameter() {
        if (tokenType() == STRING) {
            match(STRING);
            return Parameter(tokenString(),false);
        }
        else if (tokenType() == ID) {
            match(ID);
            return Parameter(tokenString(),true);
        }
        return Parameter("", false);
    }
};