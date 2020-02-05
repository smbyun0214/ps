#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int L, P, n;
    cin >> L >> P;
    
    int people = L * P;
    
    int T = 5;
    while (T--) {
        cin >> n;
        cout << n - people << ' ';
    }
    
    return 0;
}
