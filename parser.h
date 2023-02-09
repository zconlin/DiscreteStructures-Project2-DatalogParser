//
// Created by zconlin on 2/2/2023.
//

// "..\\tests\project2-tests\in21.txt"

// Write parsing functions for the remaining grammar rules.
// Fix error handling in the parser. (Throw an Exception in the 'throwError' function.) (Catch the Exception at the top of the parser and report the error.)
// Write classes for Parameter, Predicate, Rule, and Datalog Program.
// Add code to the parser to create Parameter, Predicate, and Rule objects while parsing, and construct a Datalog Program object that contains lists of Schemes, Facts, Rules, and Queries.

#pragma once

#include "token.h"
#include "scanner.h"
#include <vector>
#include <iostream>

class Parser {
private:
    vector<Token> tokens;
public:
    Parser(const vector<Token>& tokens) : tokens(tokens) { }

    TokenType tokenType() const { // Returns the type of the current Token

        return tokens.at(0).getType();
    }
    void advanceToken() { // Moves to the next Token
        tokens.erase(tokens.begin());
    }
    void throwError() { // Is called when the Parser finds an error
        // This is not complete
        cout << "Error" << endl;

    }

    int c = 0;
    void match(TokenType t) {
        cout << "match: " << t << endl; // This is a debug print, remove it later
        if (tokens.at(c).getType() == t) {
            advanceToken();
        }
        else throwError();
    }

    //// ID         ----------------------------------------------------------------------------------
    //// idList  	-> 	COMMA ID idList | lambda
    void idList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            match(ID);
            idList();
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
            stringList();
            match(RIGHT_PAREN);
            match(PERIOD);
        }
    }

    //// RULE     ----------------------------------------------------------------------------------
    //// rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
    void rule() {
        if (tokenType() == headPredicate()) {
            headPredicate();
            match(COLON_DASH);
            predicate();
            predicateList();
            match(PERIOD);
        }
    }

    //// QUERY     ----------------------------------------------------------------------------------
    //// query	        ->      predicate Q_MARK
//    void query() {
//        if (tokenType() == predicate()) {
//            predicate();
//            match(Q_MARK);
//        }
//    }

    //// headPredicate     ----------------------------------------------------------------------------------
    //// headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    void headPredicate() {
        if (tokenType() == ID) {
            match(ID);
            match(LEFT_PAREN);
            match(ID);
            idList();
            match(RIGHT_PAREN);
        }
    }

    //// predicate     ----------------------------------------------------------------------------------
    //// predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    void predicate() {
        if (tokenType() == ID) {
            match(ID);
            match(LEFT_PAREN);
            parameter();
            parameterList();
            match(RIGHT_PAREN);
        }
    }

    //// predicateList     ----------------------------------------------------------------------------------
    //// predicateList	->	COMMA predicate predicateList | lambda
    void predicateList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            predicate();
            predicateList();
        } else {
            // lambda
        }
    }

    //// parameterList     ----------------------------------------------------------------------------------
    //// parameterList	-> 	COMMA parameter parameterList | lambda
    void parameterList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            parameter();
            parameterList();
        } else {
            // lambda
        }
    }

    //// stringList     ----------------------------------------------------------------------------------
    //// stringList	-> 	COMMA STRING stringList | lambda
    void stringList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            match(STRING);
            stringList();
        } else {
            // lambda
        }
    }

    //// parameter     ----------------------------------------------------------------------------------
    //// parameter	->	STRING | ID
    void parameter() {
        if (tokenType() == STRING) {
            match(STRING);
            match(ID);
        }
    }
};