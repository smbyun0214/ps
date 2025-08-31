// https://www.acmicpc.net/problem/2443

#include <iostream>

using namespace std;

int n;

void print(int cnt, char delta) {
    for (int i = 0; i < cnt; ++i) {
        cout << delta;
    }
}

void printStar(int i) {
    if (n < i)
        return;
    
    print(i - 1, ' ');
    print(2 * (n - i) + 1, '*');
    cout << '\n';
    printStar(i + 1);
}

int main (int argc, char *argv[]) {
    cin >> n;
    
    printStar(1);
    
    return 0;
}
