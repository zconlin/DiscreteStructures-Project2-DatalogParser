#include "scanner.h"
#include "token.h"
#include <iostream>
#include <fstream>

int main (int argc, char* argv[]) {
    ifstream f;
    f.open(argv[1]);

    string content((istreambuf_iterator<char>(f)), (istreambuf_iterator<char>()));

    Scanner s = Scanner(content);
    vector<Token> t = s.scanLoop();
        for (Token token : t) {
           cout << token.toString() << endl;
        }
    cout << "Total Tokens = " << t.size() << "\n";

    return 0;
}