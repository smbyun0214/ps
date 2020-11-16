// https://www.acmicpc.net/problem/15815

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solve(string& formula) {
    stack<int> operands;
    
    for (char c : formula) {
        if (c == '+') {
            int op1 = operands.top(); operands.pop();
            int op0 = operands.top(); operands.pop();
            operands.push(op0 + op1);
        }
        else if (c == '-') {
            int op1 = operands.top(); operands.pop();
            int op0 = operands.top(); operands.pop();
            operands.push(op0 - op1);
        }
        else if (c == '*') {
            int op1 = operands.top(); operands.pop();
            int op0 = operands.top(); operands.pop();
            operands.push(op0 * op1);
        }
        else if (c == '/') {
            int op1 = operands.top(); operands.pop();
            int op0 = operands.top(); operands.pop();
            operands.push(op0 / op1);
        }
        else {
            operands.push(c - '0');
        }
    }
    
    return operands.top();
}

int main (int argc, char *argv[]) {
    
    string formula;
    cin >> formula;
    
    cout << solve(formula);
    
    return 0;
}
