#include <iostream>
#include <cstring>

#define ull unsigned long long
using namespace std;

ull cache[68];

ull koong(int n) {
    if (n < 2) return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 4;
    
    ull &ret = cache[n];
    if (ret != -1)
        return ret;
    
    ret = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N, n;
    
    cin >> N;
    
    while (N--) {
        cin >> n;
        cout << koong(n) << '\n';
    }
    
    return 0;
}
