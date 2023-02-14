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
    DatalogProgram dp;

public:
    //// You're on the right track, but I wouldn't implement it in this function. Your toString should be self-contained in the DatalogProgram class for later projects
//    string toString() {
//        stringstream output;
//        int numTokens = 0;
//        output << tokenString() << " (" << numTokens << ") :" << endl;
//
//        return output.str();
//    }

    Parser(const vector<Token>& tokens) : tokens(tokens) {
        //// I don't think you need this constructor. You're going to call a parse function later.
//        if(tokenType() == COMMENT) {
//            advanceToken();
//        }
    }

    TokenType tokenType() const { // Returns the type of the current Token
        return tokens.at(0).getType();
    };

    string tokenString() {
        return tokens.at(0).getValue();
    }

    void advanceToken() { // Moves to the next Token
        if(tokens.size() > 1) {
            tokens.erase(tokens.begin());
        }
    }

    //// I made my throwError function follow the signature "void throwError(Token t)" and threw the token, made it easy to print the offending token at the end
    void throwError() { // Is called when the Parser finds an error
//        throw "Error";
//cout << "Error"; //debug
    }

    int c = 0; //// I think this probably can get removed...
    void match(TokenType t) { //// return the Token in the match function
        if (tokens.at(c).getType() == END) {

        }
        if (tokens.at(c).getType() == t) {
            cout << tokens.at(c).getValue(); //debug
            //// save the token before you advance and delete it
            advanceToken();
            //// return the saved token
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
            scheme(); //// Each of these functions should get a value saved.
            schemeList(); //// ^^
            match(FACTS);
            match(COLON);
            factList(); //// ^^
            match(RULES);
            match(COLON);
            ruleList(); //// ^^
            match(QUERIES);
            match(COLON);
            query(); //// ^^
            queryList(); //// ^^
            match(END);
            return {}; //// return the DatalogProgram Object returned by the DatalogProgram() constructor
    }

    //// schemeList	->	scheme schemeList | lambda
    void schemeList() { //// Shouldn't be void but should return vector<Predicate> (a list of all the schemes parsed)
        if(tokenType() == ID) {
            scheme(); //// Each of these functions should get a value saved.
            schemeList(); //// Each of these functions should get a value saved.
            //// return the list of schemes saved out from the parsing
        } else {
            // lambda
            //// return {} (an empty schemes list)
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
        if(tokenType() != QUERIES) { //// I don't think this should be QUERIES... What is the next token when you're in the rules section
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
     void scheme() { //// return a scheme (Predicate)
        if (tokenType() == ID) {
            match(ID); //// Save the token! don't just throw it away
            match(LEFT_PAREN);
            match(ID); //// Save the token
            idList(); //// Save the list of Ids to a variable
            match(RIGHT_PAREN);
            //// return Predicate(NAMETOKEN.value, IDLISTVAR)
        }
    }

    //// FACT     ----------------------------------------------------------------------------------
    //// fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    void fact() { //// return a fact (Predicate)
        if (tokenType() == ID) {
            match(ID); //// save
            match(LEFT_PAREN);
            match(STRING); //// save
            // string value to string vector? Not quite but close
            stringList(); //// save
            match(RIGHT_PAREN);
            match(PERIOD);
            // push to datalogProgram fact vector
//            dp.Facts.push_back();
//            Predicate().addParameter();
            //// Return Predicate(name, strings)
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
        return {};
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
        return {};
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