// https://codeforces.com/contest/1328/problem/C
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T;
    
    cin >> T;
    
    while (T--) {
        
        int size;
        
        cin >> size;
        
        char n;
        
        string ret0 = "", ret1 = "";
        bool flag = false;
        
        for (int i = 0; i < size; ++i) {
            cin >> n;
            if (n == '0') {
                ret0 += '0';
                ret1 += '0';
            }
            else if (n == '1') {
                if (!flag) {
                    ret0 += '1';
                    ret1 += '0';
                    flag = true;
                }
                else {
                    ret0 += '0';
                    ret1 += '1';
                }
            }
            else {
                if (ret0.empty() || !flag) {
                    ret0 += '1';
                    ret1 += '1';
                }
                else {
                    ret0 += '0';
                    ret1 += '2';
                }
            }
        }
        
        cout << ret0 << '\n';
        cout << ret1 << '\n';
    }
    
    return 0;
}
