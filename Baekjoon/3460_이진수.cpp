#include <iostream>

using namespace std;

void printBinaryIndex(int n) {
    int index = 0;
    while (n) {
        if (n & 1)
            cout << index << ' ';
        
        n = n >> 1;
        ++index;
    }
}
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T, n;
    cin >> T;
    
    while (T--) {
        cin >> n;
        printBinaryIndex(n);
        cout << '\n';
    }
    
    return 0;
}
