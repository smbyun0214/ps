#include <iostream>
#include <cstring>

using namespace std;

bool cache[101][101];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cache, 0, sizeof(cache));
    
    int leftDownX, leftDownY, rightUpX, rightUpY;
    
    for (int i = 0; i < 4; ++i) {
        cin >> leftDownX >> leftDownY >> rightUpX >> rightUpY;
        
        for (int i = leftDownY; i < rightUpY; ++i) {
            for (int j = leftDownX; j < rightUpX; ++j) {
                cache[i][j] = true;
            }
        }
    }
    
    int ret = 0;
    
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            if (cache[i][j])
                ++ret;
        }
    }
    
    cout << ret << '\n';
    
    return 0;
}
