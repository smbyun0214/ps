// https://www.acmicpc.net/problem/14891

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

string wheels[4];
bool isUsed[4];
int heads[4];

int leftValue(int here) {
    int size = wheels[here].size();
    int left = (heads[here] - 2 + size) % size;
    return wheels[here][left];
}

int rightValue(int here) {
    int size = wheels[here].size();
    int right = (heads[here] + 2) % size;
    return wheels[here][right];
}

void rotate(int here, int direction) {
    if (here < 0 || 4 <= here || isUsed[here])
        return;
    
    isUsed[here] = true;
    
    int left = here - 1, right = here + 1;
    if (0 <= left && rightValue(left) != leftValue(here))
        rotate(left, -direction);
        
    if (right < 4 && rightValue(here) != leftValue(right))
        rotate(right, -direction);
    
    int size = wheels[here].size();
    heads[here] = (heads[here] - direction + size) % size;
}

int main (int argc, char *argv[]) {
    
    for (int i = 0; i < 4; ++i) {
        cin >> wheels[i];
        heads[i] = 0;
    }
    
    int n;
    cin >> n;
    
    while (n--) {
        memset(isUsed, false, sizeof(isUsed));
        
        int here, direction;
        cin >> here >> direction;
        rotate(here - 1, direction);
    }
    
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        ret += wheels[i][heads[i]] == '1' ? pow(2, i) : 0;
    }
    
    cout << ret << '\n';
    
    return 0;
}
