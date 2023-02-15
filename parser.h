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
//    string toString() {
//        stringstream output;
//        int numTokens;
//        output << tokenString() << " (" << numTokens << ") :" << endl;
//
//        return output.str();
//    }

    Parser(const vector<Token>& tokens) : tokens(tokens) {
        if(tokenType() == COMMENT) { //// Call a parse function? Why can't this work?   //You're going to want the parse function to return a DatalogProgram object. You can't return that in a constructor like this.
            advanceToken();
        }
    }

    TokenType tokenType() const { // Returns the type of the current Token
        return tokens.at(0).getType();
    };

//// I believe we made this obsolete with how we coded our stuff later on
//    string tokenString() {
//        return tokens.at(0).getValue();
//    }

    void advanceToken() { // Moves to the next Token
        if(tokens.size() > 1) {
            tokens.erase(tokens.begin());
        }
    }

    void throwError(Token t) { // Is called when the Parser finds an error
        throw t;
        //cout << "Error"; //debug
    }

    Token match(TokenType t) {
        Token token = tokens.at(0);
        if (tokens.at(0).getType() == END) {
            return token;
        }
        if (tokens.at(0).getType() == t) {
            cout << tokens.at(0).getValue(); //debug
            advanceToken();
            return token;
        }
        else {
            throwError(token);
            return {};
        }
    }

    //// DatalogProgram     ----------------------------------------------------------------------------------
    //// datalogProgram	->	SCHEMES COLON scheme schemeList
    ////		        FACTS COLON factList
    ////		        RULES COLON ruleList
    ////		        QUERIES COLON query queryList
    ////    			EOF
    DatalogProgram datalogProgram() {
            match(SCHEMES);
            match(COLON);
            Predicate s = scheme();
            vector<Predicate> schemes = schemeList();
            schemes.insert(schemes.begin(),s);
            match(FACTS);
            match(COLON);
            vector<Predicate> facts = factList();
            match(RULES);
            match(COLON);
            vector<Rule> rules = ruleList();
            match(QUERIES);
            match(COLON);
            Predicate q = query();
            vector<Predicate> queries = queryList();
            queries.insert(queries.begin(),q);
            match(END);
            return DatalogProgram(schemes, facts, queries, rules);
        //// How do I return what I need? It's unhappy about the version above
    }

    //// schemeList	->	scheme schemeList | lambda
    vector<Predicate> schemeList() {
        if(tokenType() == ID) {
            Predicate p = scheme();
            vector<Predicate> schemes = schemeList();
            schemes.insert(schemes.begin(),p);
            return schemes;
        } else {
            // lambda
        }
        return {};
    }

    //// factList	->	fact factList | lambda
    vector<Predicate> factList() {
        if(tokenType() == ID) {
            Predicate p = fact();
            vector<Predicate> facts = factList();
            facts.insert(facts.begin(),p);
            return facts;
        } else {
        // lambda
        }
        return {};
    }

    //// ruleList	->	rule ruleList | lambda
    vector<Rule> ruleList() {
        if(tokenType() != QUERIES) {
//            Rule r = rule();
//            vector<Predicate> rules = ruleList();
//            rules.insert(rules.begin(),r);
//            return rules;
        } else {
        // lambda
        }
        return {};
    }

    //// queryList	->	query queryList | lambda
    vector<Predicate> queryList() {
        if(tokenType() == ID) {
            Predicate p = query();
            vector<Predicate> query = queryList();
            query.insert(query.begin(),p);
            return query;
        } else {
        // lambda
        }
        return {};
    }

    //// SCHEME     ----------------------------------------------------------------------------------
    //// scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
     Predicate scheme() {
        if (tokenType() == ID) {
            Token schemeName = match(ID);
            match(LEFT_PAREN);
            Token firstParam = match(ID);
            Parameter p = Parameter(firstParam.getValue(), true);
            vector<Parameter> ids = idList();
            ids.insert(ids.begin(),p);
            match(RIGHT_PAREN);
            return Predicate(schemeName.getValue(),ids);
        }
        return {};
    }

    //// FACT     ----------------------------------------------------------------------------------
    //// fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    Predicate fact() {
        if (tokenType() == ID) {
            Token schemeName = match(ID);
            match(LEFT_PAREN);
            Token stringContents = match(STRING);
            Parameter p = Parameter(stringContents.getValue(), false);
            vector<Parameter> strings = stringList();
            strings.insert(strings.begin(),p);
            match(RIGHT_PAREN);
            match(PERIOD);
            return Predicate(schemeName.getValue(),strings);
        }
        return {};
    }

    //// RULE     ----------------------------------------------------------------------------------
    //// rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
    Rule rule() {
        if (tokenType() == ID) {
            Predicate ruleName = headPredicate();
            match(COLON_DASH);
            Predicate firstPredicate = predicate();
            vector<Predicate> listOfPredicates = predicateList();
            listOfPredicates.insert(listOfPredicates.begin(), firstPredicate);
            match(PERIOD);
            return Rule(ruleName, listOfPredicates);
        }
        return {};
    }

    //// QUERY     ----------------------------------------------------------------------------------
    //// query	        ->      predicate Q_MARK
    Predicate query() {
        if (tokenType() == ID) {
            Predicate queryName = predicate();
            match(Q_MARK);
            return queryName;
        }
        return {};
    }

    //// headPredicate     ----------------------------------------------------------------------------------
    //// headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
    Predicate headPredicate() {
        Token ruleName = match(ID);
        match(LEFT_PAREN);
        match(ID);
        Parameter p = Parameter(ruleName.getValue(), true);
        vector<Parameter> ids = idList();
        ids.insert(ids.begin(),p);
        match(RIGHT_PAREN);
        return Predicate(ruleName.getValue(),ids);
    }

    //// predicate     ----------------------------------------------------------------------------------
    //// predicate	->	ID LEFT_PAREN Parameter parameterList RIGHT_PAREN
    Predicate predicate() {
        if (tokenType() == ID) {
            Token idName = match(ID);
            match(LEFT_PAREN);
            parameter();
            Parameter p = Parameter(idName.getValue(), true);
            vector<Parameter> parameters = parameterList();
            parameters.insert(parameters.begin(),p);
            match(RIGHT_PAREN);
            return Predicate(idName.getValue(),parameters);
        }
        return {};
    }

    //// predicateList     ----------------------------------------------------------------------------------
    //// predicateList	->	COMMA predicate predicateList | lambda
    vector<Predicate> predicateList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            Predicate p = predicate();
            vector<Predicate> predicates = predicateList();
            predicates.insert(predicates.begin(),p);
            return predicates;
        } else {
            // lambda
        }
        return {};
    }

    //// parameterList     ----------------------------------------------------------------------------------
    //// parameterList	-> 	COMMA parameter parameterList | lambda
    vector<Parameter> parameterList() {
        if (tokenType() == COMMA) {
            match(COMMA);
            Parameter p = parameter();
            vector<Parameter> parameters = parameterList();
            parameters.insert(parameters.begin(),p);
            return parameters;
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
            Token firstString = match(STRING);
            vector<Parameter> strings = stringList();
            Parameter p = Parameter(firstString.getValue(), false);
            strings.insert(strings.begin(),p);
            return strings;
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
            Token idName = match(ID);
            vector<Parameter> ids = idList();
            Parameter p = Parameter(idName.getValue(), true);
            ids.insert(ids.begin(),p);
        return ids;
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