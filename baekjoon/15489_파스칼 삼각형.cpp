// https://www.acmicpc.net/problem/15489

#include <iostream>
#include <cstring>

using namespace std;

int SIZE;
int cache[31][31];

int getPascalNum(int y, int x) {
    if (y < 1 || y < x) return 0;
    if (x == 1) return 1;
    
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    
    return ret = getPascalNum(y - 1, x - 1) + getPascalNum(y - 1, x);
}

int area(int y, int x, int size) {
    if (SIZE < size) return 0;
    
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        ret += getPascalNum(y, x + i);
    }
    
    return ret + area(y + 1, x, size + 1);
}

int main (int argc, char *argv[]) {
    memset(cache, -1, sizeof(cache));
    
    int y, x;
    cin >> y >> x >> SIZE;
    
    cout << area(y, x, 1);
    
    return 0;
}
