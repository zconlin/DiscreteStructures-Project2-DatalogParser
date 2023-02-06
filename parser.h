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

    int c = 0;
    void match(TokenType t) {
        cout << "match: " << t << endl; // This is a debug print, remove it later
        if (tokens.at(c).getType() == t) {
            c = c + 1;
        }
        else throwError();
    }

    void idList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            match(ID);
//            idList();
        } else {
            // lambda
            cout << "Done" << endl; //Debug
            throwError();
        }
    }
};