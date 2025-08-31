//https://codeforces.com/gym/102556/problem/D
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cout << 100.0 / (i + 1) << '\n';
    }
    
    return 0;
}
