//
// Created by zconlin on 1/27/2023.
//

#include "scanner.h"
#include "token.h"
#include "parser.h"
#include <iostream>
#include <fstream>

int main() {

    vector<Token> tokens = { //Test idList with valid input
            Token(COMMA,",",2),
            Token(ID,"Ted",2),
            Token(COMMA,",",2),
            Token(ID,"Zed",2),
            Token(RIGHT_PAREN,")",2),
    };

    Parser p = Parser(tokens);
    p.idList();

}

//int main() { //Test idList with valid input
//
//    vector<Token> tokens = {
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

//int main (int argc, char* argv[]) { // Main from Project 1
//    ifstream f;
//    f.open(argv[1]);
//
//    string content((istreambuf_iterator<char>(f)), (istreambuf_iterator<char>()));
//
//    Scanner s = Scanner(content);
//    vector<Token> t = s.scanLoop();
//        for (Token token : t) {
//           cout << token.toString() << endl;
//        }
//    cout << "Total Tokens = " << t.size() << "\n";
//
//    return 0;
//}

