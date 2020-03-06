#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[31];

int filledTiled(int width) {
    if (width < 0) return 0;
    
    int &ret = cache[width];
    if (ret != -1)
        return ret;
    
    ret = 3 * filledTiled(width - 2);
    
    for (int i = 4; i <= width; i += 2) {
        ret += 2 * filledTiled(width - i);
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, -1, sizeof(cache));
    cache[0] = 1;
    cache[2] = 3;
    
    cin >> N;
    
    cout << filledTiled(N) << '\n';
    
    return 0;
}
