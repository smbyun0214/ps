#include <iostream>
#include <cmath>

using namespace std;

int N, row, column;
int ret = 0;

bool ZPathCount(int size, int y, int x) {
    if (y == row && x == column)
        return true;
    
    if (size == 1) {
        ret += 1;
        return false;
    }

    int step = size / 2;
    
    if (row < (y + step) && column < (x + step) && ZPathCount(step, y, x)) return true;
    ret += step * step;
        
    if (row < (y + step) && column < (x + 2 * step) && ZPathCount(step, y, x + step)) return true;
    ret += step * step;
    
    if (row < (y + 2 * step) && column < (x + step) && ZPathCount(step, y + step, x)) return true;
    ret += step * step;
    
    if (row < (y + 2 * step) && column < (x + 2 * step) && ZPathCount(step, y + step, x + step)) return true;
    ret += step * step;
    
    return false;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N >> row >> column;
    
    ZPathCount(pow(2, N), 0, 0);
    
    cout << ret << '\n';
    
    return 0;
}
