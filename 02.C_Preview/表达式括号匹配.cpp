#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string expr;
    getline(cin, expr);
 
    size_t endPos = expr.find('#');
    if (endPos != string::npos) {
        expr = expr.substr(0, endPos);
    }
    stack<char> brackets;
    for (int i = 0; i < expr.size(); ++i) {
    char c = expr[i];
    if (c == '(') {
        brackets.push(c);
    } else if (c == ')') {
        if (brackets.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        brackets.pop();
    }
}
    cout << (brackets.empty() ? "YES" : "NO") << endl;
    return 0;
}


