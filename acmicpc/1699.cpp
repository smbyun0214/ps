#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int cache[100001];

int squareOfSum(int n, int start) {
    if (n == 0)
        return 1;
    
    int &ret = cache[n];
    if (ret != -1)
        return ret;
    
    ret = INF;
    
    
    for (int add = 0; (start + add) * (start + add) <= n; ++add) {
        int next = start + add;
        
        if (next != 0)
            ret = min(ret, 1 + squareOfSum(n - (next * next), next));
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N;
    cin >> N;
    
    cout << squareOfSum(N, 0) - 1 << '\n';
    
    return 0;
}
