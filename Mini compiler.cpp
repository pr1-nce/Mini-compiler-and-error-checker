#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    string code;
    cout << "Enter a single line of code: ";
    getline(cin, code);
    regex validInt("int\\s+[a-zA-Z_][a-zA-Z0-9_]*\\s*=?\\s*[-]?[0-9]*\\s*;");
    regex validFloat("float\\s+[a-zA-Z_][a-zA-Z0-9_]*\\s*=?\\s*[-]?[0-9]*\\.?[0-9]*\\s*;");
    regex validChar("char\\s+[a-zA-Z_][a-zA-Z0-9_]*\\s*=?\\s*'.'\\s*;");
    if (code.find(";") == string::npos) {
        cout << "Error: Missing semicolon (;)" << endl;
    }
    else if (regex_match(code, validInt) || regex_match(code, validFloat) || regex_match(code, validChar)) {
        cout << "Code Compiled Successfully!" << endl;
    }
    else if (regex_search(code, regex("[0-9]+[a-zA-Z_]+"))) {
        cout << "Error: Invalid variable name (cannot start with a number)" << endl;
    }
    else {
        cout << "Syntax Error: Invalid statement" << endl;
    }
    return 0;
}
