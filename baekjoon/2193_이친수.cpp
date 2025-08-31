#include <iostream>
#include <cstring>

using namespace std;

int N;
long long cache[2][91];

void countPinary(int i) {
    if (cache[0][i - 1] == -1 || cache[1][i - 1] == -1)
        countPinary(i - 1);
    
    cache[0][i] = cache[0][i - 1] + cache[1][i - 1];
    cache[1][i] = cache[0][i - 1];
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    cache[0][0] = cache[1][0] = cache[0][1] = 0;
    cache[1][1] = 1;
    
    cin >> N;

    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }

    countPinary(N);
    
    cout << cache[0][N] + cache[1][N] << '\n';
    
    return 0;
}
