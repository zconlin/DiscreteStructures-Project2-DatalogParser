//
// Created by zconlin on 2/2/2023.
//

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
    // The 'match' function is another important support function that
    // will make the parsing routines simpler and easier to write. The 'match'
    // function is called when parsing a terminal symbol. (This 'match' function
    // has a debug print, to be removed later.) (The debug print is helpful in
    // testing the parsing functions below.)
    void match(TokenType t) {
        cout << "match: " << t << endl; // This is a debug print, remove it later
        // add code for matching token type t

//        The following pseudo-code describes how the 'match' function should work.
//        if the current token type matches t
//        advance to the next token
//        else
//        report a syntax error
        int c = 0;
        if (tokens.at(c).getType() == t) {
            c++;
        }
        else throwError();
    }
};