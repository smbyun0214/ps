// https://www.acmicpc.net/problem/1935

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cache[27];

double solve(string& str) {
    stack<double> operands;
    
    for (char c : str) {
        if (c == '+') {
            double op1 = operands.top(); operands.pop();
            double op0 = operands.top(); operands.pop();
            operands.push(op0 + op1);
        }
        else if (c == '-') {
            double op1 = operands.top(); operands.pop();
            double op0 = operands.top(); operands.pop();
            operands.push(op0 - op1);
        }
        else if (c == '*') {
            double op1 = operands.top(); operands.pop();
            double op0 = operands.top(); operands.pop();
            operands.push(op0 * op1);
        }
        else if (c == '/') {
            double op1 = operands.top(); operands.pop();
            double op0 = operands.top(); operands.pop();
            operands.push(op0 / op1);
        }
        else {
            operands.push(cache[c - 'A']);
        }
    }
    
    return operands.top();
}

int main (int argc, char *argv[]) {
    
    int n;
    cin >> n;
    
    string formula;
    cin >> formula;
    
    for (int i = 0; i < n; ++i) {
        cin >> cache[i];
    }
    
    cout.precision(2);
    cout << fixed << solve(formula);
    
    return 0;
}
