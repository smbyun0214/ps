#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    for (int i = 0; i <= N - 1; ++i) {
        for (int j = 0; j < i; ++j)
            cout << ' ';
        for (int j = 0; j < (2 * N - 1) - 2 * i; ++j)
            cout << '*';
        cout << '\n';
    }
    
    for (int i = N - 2; 0 <= i; --i) {
        for (int j = 0; j < i; ++j)
            cout << ' ';
        for (int j = 0; j < (2 * N - 1) - 2 * i; ++j)
            cout << '*';
        cout << '\n';
    }
        
    return 0;
}
