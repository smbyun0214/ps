// https://www.acmicpc.net/problem/9625

#include <iostream>
#include <string>

using namespace std;

int A = 0, B = 1;
int cache[2] = {1, 0};

void push(int n) {
    if (n == 0)
        return;
    int aCnt = cache[A];
    int bCnt = cache[B];
    cache[A] = bCnt;
    cache[B] = aCnt + bCnt;
    
    push(n - 1);
}

int main (int argc, char *argv[]) {
    int K;
    cin >> K;
    
    push(K);
    
    cout << cache[0] << ' ' << cache[1] << '\n';
    
    return 0;
}
