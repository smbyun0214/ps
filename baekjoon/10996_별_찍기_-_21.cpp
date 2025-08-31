#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    for (int i = 1; i <= 2 * N; ++i) {
        if (i % 2 == 1) {
            for (int j = 0; j < (N + 1) / 2; ++j)
                cout << "* ";
        }
        else {
            for (int j = 0; j < N / 2; ++j)
                cout << " *";
        }
        cout << '\n';
    }
    
    return 0;
}
