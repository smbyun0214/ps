// https://codeforces.com/contest/1328/problem/B
#include <iostream>

using namespace std;

int psum[100001];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    psum[0] = 0;
    for (int i = 1; i < 100001; ++i) {
        psum[i] = psum[i - 1] + i;
    }
    
    int N;
    
    cin >> N;
    
    int a, b;
    
    while (N--) {
        cin >> a >> b;
        
        int first = -1, second = -1;
        for (first = 0; first < a; ++first) {
            if (b <= psum[first])
                break;
        }
        
        for (second = 0; second < first; ++second) {
            if (psum[first] - b == first - 1 - second)
                break;
        }
        
        for (int i = a - 1; 0 <= i; --i) {
            if (i == first || i == second)
                cout << 'b';
            else
                cout << 'a';
        }
        
        cout << '\n';
    }
    
    return 0;
}
