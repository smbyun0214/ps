#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j)
            cout << '*';
        cout << '\n';
    }
    
    for (int i = N - 1; 0 <= i; --i) {
        for (int j = 0; j < i; ++j)
            cout << '*';
        cout << '\n';
    }
        
    return 0;
}
