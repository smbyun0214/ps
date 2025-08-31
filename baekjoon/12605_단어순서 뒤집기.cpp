// https://www.acmicpc.net/problem/12605

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solve(string& str) {
    stack<string> strs;
    
    size_t begin = 0;
    size_t found = 0;
    while ((found = str.find(" ", found + 1)) != string::npos) {
        strs.push(str.substr(begin, found - begin));
        begin = found + 1;
    }
    
    string ret = "";
    while (!strs.empty()) {
        string top = strs.top();
        strs.pop();
        ret += top + " ";
    }
    
    return ret;
}

int main (int argc, char *argv[]) {
    
    int n;
    cin >> n;
    cin.ignore();
    
    string row;
    for (int i = 1; i <= n; ++i) {
        getline(cin, row);
        row += " ";
        cout << "Case #" << i << ": " << solve(row) << '\n';
    }
    
    return 0;
}
