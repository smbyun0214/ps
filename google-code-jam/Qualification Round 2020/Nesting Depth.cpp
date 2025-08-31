#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<string> sameDigitsString(const string &s) {
    vector<string> ret;
    
    string tmp = string(1, s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == tmp[0])
            tmp += s[i];
        else {
            ret.push_back(tmp);
            tmp = string(1, s[i]);
        }
    }
    
    ret.push_back(tmp);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int T; cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        
        stack<char> stk;
        string ret = "";
        vector<string> sameS = sameDigitsString(s);
        
        for (string same : sameS) {
            int depth = same[0] - '0';
            
            while (depth < stk.size()) {
                ret += stk.top();
                stk.pop();
            }
            
            while (stk.size() < depth) {
                ret += '(';
                stk.push(')');
            }
            
            ret += same;
        }
        
        while (!stk.empty()) {
            ret += stk.top();
            stk.pop();
        }
        
        cout << "Case #" << t << ": " << ret << '\n';
    }
    
    return 0;
}
