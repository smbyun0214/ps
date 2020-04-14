//https://www.acmicpc.net/problem/10164

#include <iostream>
#include <cstring>

using namespace std;

int cache[16][16];

int getPath(int y, int x) {
    if (y == 0 || x == 0) return 1;
    
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    
    ret = getPath(y - 1, x) + getPath(y, x - 1);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    
    int N, M, O;

    cin >> N >> M >> O;
    
    if (O == 0) {
        cout << getPath(N - 1, M - 1) << '\n';
    }
    else {
        int y = (O - 1) / M, x = (O - 1) % M;
        
        cout << getPath(y, x) * getPath((N - 1) - y, (M - 1) - x) << '\n';
    }
    
    return 0;
}
