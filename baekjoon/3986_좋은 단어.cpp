// https://www.acmicpc.net/problem/3986

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solve(string& str) {
    stack<char> buffer;
    
    for (char c : str) {
        if (buffer.empty() || c != buffer.top())
            buffer.push(c);
        else if (c == buffer.top())
            buffer.pop();
        else
            return false;
    }
    
    return buffer.empty();
}

int main (int argc, char *argv[]) {
    
    int n;
    cin >> n;
    
    int ret = 0;
    string row;
    while (n--) {
        cin >> row;
        if (solve(row))
            ++ret;
    }
    
    cout << ret;
    
    return 0;
}
