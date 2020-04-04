#include <iostream>
#include <cstring>
using namespace std;

int cache[10];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, 0, sizeof(cache));
    
    int N; cin >> N;
    
    do {
        ++cache[N % 10];
        N /= 10;
    } while (N);
    
    int avg69 = (cache[6] + cache[9] + 1) / 2;
    cache[6] = cache[9] = avg69;
    
    bool isEmpty = false;
    int ret = 0;
    
    while (!isEmpty) {
        isEmpty = true;
        
        ++ret;
        
        for (int i = 0; i < 10; ++i) {
            --cache[i];
            if (cache[i] > 0) isEmpty = false;
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
