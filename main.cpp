//
// Created by zconlin on 1/27/2023.
//

#include "scanner.h"
#include "token.h"
#include "parser.h"
#include <iostream>
#include <fstream>

int main (int argc, char* argv[]) {
    ifstream f;
    f.open(argv[1]);

    string content((istreambuf_iterator<char>(f)), (istreambuf_iterator<char>()));

    Scanner s = Scanner(content);
    vector<Token> t = s.scanLoop();

    Parser p = Parser(t);

    try {
        DatalogProgram parsedObject = p.datalogProgram();
        cout << "Success!" << endl;
        parsedObject.toString();
    }
    catch (Token error) {
        cout << "Failure!" << endl;
        cout << "  " << error.toString() << endl;
    }

    return 0;
}

//int main (int argc, char* argv[]) {
//    ifstream f;
//    f.open(argv[1]);
//
//    string content((istreambuf_iterator<char>(f)), (istreambuf_iterator<char>()));
//
//    Scanner s = Scanner(content);
//    vector<Token> t = s.scanLoop();
//    for (Token token : t) {
//        cout << token.toString() << endl;
//    }
//    cout << "Total Tokens = " << t.size() << "\n";
//
//    return 0;
//}


//int main() { // Test scheme with bad input
//
//    vector<Token> tokens = {
//            Token(ID,"Ned",2),
//            //Token(LEFT_PAREN,"(",2),
//            Token(ID,"Ted",2),
//            Token(COMMA,",",2),
//            Token(ID,"Zed",2),
//            Token(RIGHT_PAREN,")",2),
//    };
//
//    Parser p = Parser(tokens);
//    p.scheme();
//
//}

//int main() { // Test scheme with valid input
//
//    vector<Token> tokens = {
//            Token(ID,"Ned",2),
//            Token(LEFT_PAREN,"(",2),
//            Token(ID,"Ted",2),
//            Token(COMMA,",",2),
//            Token(ID,"Zed",2),
//            Token(RIGHT_PAREN,")",2),
//    };
//
//    Parser p = Parser(tokens);
//    p.scheme();
//
//}

//int main() {
//
//    vector<Token> tokens = { //Test idList with valid input
//            Token(COMMA,",",2),
//            Token(ID,"Ted",2),
//            Token(COMMA,",",2),
//            Token(ID,"Zed",2),
//            Token(RIGHT_PAREN,")",2),
//    };
//
//    Parser p = Parser(tokens);
//    p.idList();
//
//}

//int main() { //Test idList with bad input
//
//    vector<Token> tokens = {
//            Token(COMMA,",",2),
//            //Token(ID,"Ted",2),
//            Token(COMMA,",",2),
//            Token(ID,"Zed",2),
//            Token(RIGHT_PAREN,")",2),
//    };
//
//    Parser p = Parser(tokens);
//    p.idList();
//
//}

//int main() { // Test Match Function
//
//    vector<Token> tokens = {
//            Token(ID,"Zac",2),
//            Token(LEFT_PAREN,"(",2),
//            Token(RIGHT_PAREN,")",2),
//    };
//
//    Parser p = Parser(tokens);
//    p.match(ID);
//    p.match(LEFT_PAREN);
//    p.match(ID);         // intentional error
//    p.match(RIGHT_PAREN);
//
//}

//int main() { // Start of Lab 2
//
//    vector<Token> tokens = {
//            Token(ID,"Zac",2),
//            Token(LEFT_PAREN,"(",2),
//            Token(RIGHT_PAREN,")",2),
//    };
//
//    Parser p = Parser(tokens);
//    cout << p.tokenType() << endl;
//    p.advanceToken();
//    cout << p.tokenType() << endl;
//    p.advanceToken();
//    cout << p.tokenType() << endl;
//    p.throwError();
//
//}


