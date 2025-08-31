// https://codeforces.com/contest/1328/problem/A
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    int a, b;
    
    while (N--) {
        cin >> a >> b;
        
        if (a % b > 0)
            cout << (b * ((a / b) + 1)) - a << '\n';
        else if (a % b == 0)
            cout << 0 << '\n';
        else
            cout << b - a << '\n';
    }
    
    return 0;
}
