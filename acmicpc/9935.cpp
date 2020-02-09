#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void stringBomb(const string &str, const string &bomb) {
    string ret = "";
    
    stack<string> remaining;
    
    for (int i = 0; i < str.size(); ++i) {
        
        string s = string(1, str[i]);
        
        if (s == bomb) continue;
        
        if (!remaining.empty() && bomb.find(remaining.top()) != -1) {
            const string j = remaining.top();
            remaining.pop();
            
            if (bomb.find(j + s) == 0) {
                if (bomb != (j + s)) {
                    remaining.push(j + s);
                }
                
                continue;
            }
            
            remaining.push(j);
        }
        
        remaining.push(s);
    }
    
    while (!remaining.empty()) {
        string s = remaining.top();
        reverse(s.begin(), s.end());
        
        ret += s;
        remaining.pop();
    }
    
    reverse(ret.begin(), ret.end());
    
    if (ret.empty())
        cout << "FRULA" << '\n';
    else
        cout << ret << '\n';
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string str, bomb;
    cin >> str >> bomb;
    
    stringBomb(str, bomb);
    
    return 0;
}
