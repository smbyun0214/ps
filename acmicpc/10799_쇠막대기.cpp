#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    queue<char> q;
    
    string str;
    cin >> str;
    
    bool isLaser = true;
    int ret = 0;
    
    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];
        
        if (c == '(') {
            q.push(c);
            isLaser = true;
        }
        else {
            q.pop();
            
            if (isLaser) ret += q.size();
            else ++ret;
            
            isLaser = false;
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
