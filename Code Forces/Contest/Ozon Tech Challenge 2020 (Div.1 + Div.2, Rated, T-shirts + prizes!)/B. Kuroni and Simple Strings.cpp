// https://codeforces.com/contest/1305/problem/B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string s; cin >> s;
    
    int left = 0, right = s.size() - 1;
    vector<int> ret;
    
    while (left < right) {
        if (s[left] != '(') {
            ++left;
            continue;
        }
        
        if (s[left] == '(' && s[right] == ')') {
            ret.push_back(left + 1);
            ret.push_back(right + 1);
            ++left;
            --right;
        }
        else {
            --right;
        }
    }
    
    if (ret.size() == 0)
        cout << 0 << '\n';
    else {
        sort(ret.begin(), ret.end());
        
        cout << 1 << '\n';
        cout << ret.size() << '\n';
        for (int i : ret)
            cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}
