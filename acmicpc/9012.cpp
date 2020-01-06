#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    
    string line;
    while (T-- > 0) {
        cin >> line;
        
        int cache = 0;
        for (char c : line) {
            if (c == '(')
                ++cache;
            else if (cache > 0) {
                --cache;
            }
            else {
                --cache;
                break;
            }
        }
        
        if (cache)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    
    return 0;
}
