// https://codeforces.com/problemset/problem/4/A
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int w;
    cin >> w;
    
    if (w % 2 == 0 && w > 3)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    
    return 0;
}
