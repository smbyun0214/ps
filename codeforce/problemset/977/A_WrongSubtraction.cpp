#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    while (k--) {
        switch(n % 10) {
            case 0:
                n /= 10;
                break;
            default:
                --n;
                break;
        }
    }
    
    cout << n << '\n';
    
    return 0;
}
