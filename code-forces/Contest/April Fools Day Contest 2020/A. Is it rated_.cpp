//https://codeforces.com/contest/1331/problem/A
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    char rated;
    
    cin >> rated;
    
    cout << ('A' <= rated && rated << 'Z') << '\n';
    
    return 0;
}
