// https://www.acmicpc.net/problem/1918

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string formula;
    cin >> formula;

    string ret = "";

    stack<char> stk;
    for (char c : formula) {
        if (c == '+' || c == '-') {
            while (!stk.empty() && stk.top() != '(') {
                ret.push_back(stk.top());
                stk.pop();
            }
            stk.push(c);
        }
        else if (c == '*' || c == '/') {
            while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
                ret.push_back(stk.top());
                stk.pop();
            }
            stk.push(c);
        }
        else if (c == '(') {
            stk.push(c);
        }
        else if (c == ')') {
            while (stk.top() != '(') {
                ret.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else {
            ret += c;
        }
    }

    while (!stk.empty()) {
        ret.push_back(stk.top());
        stk.pop();
    }

    cout << ret << '\n';
    
    return 0;
}
