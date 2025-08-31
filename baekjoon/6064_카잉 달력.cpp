// https://www.acmicpc.net/problem/6064 

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, M, N, x, y;
    cin >> T;

    while (T--) {
        cin >> M >> N >> x >> y;
        if (M < N) {
            swap(M, N);
            swap(x, y);
        }
        
        //                 *(x)
        // 1 2 3 4 5 6 7 8 9 10 11 12   (M)
        //     ^(m)
        // 1 2 3 4 5 6 7 8 9 10         (N)
        //     *(y)

        bool isExist = false;
        int step = M - N;
        for (int i = 0, m = y; i <= M; ++i) {
            if (m == x) {
                cout << y + N * i << '\n';
                isExist = true;
                break;
            }
            m -= step;
            if (m <= 0) {
                m += M;
            }
        }
        
        if (!isExist) {
            cout << -1 << '\n';
        }
    } 
    
    return 0;
}
