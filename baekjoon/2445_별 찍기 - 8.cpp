// https://www.acmicpc.net/problem/2445

#include <iostream>

using namespace std;

int n;

void print(int cnt, char delta) {
    for (int i = 0; i < cnt; ++i)
        cout << delta;
}

void printStar(int i) {
    if (i == 2 * n)
        return;
    
    if (i < n) {
        print(i, '*');
        print(2 * (n - i), ' ');
        print(i, '*');
        cout << '\n';
    }
    else {
        print(n - (i % n), '*');
        print(2 * (i % n), ' ');
        print(n - (i % n), '*');
        cout << '\n';
    }
    
    ++i;
    printStar(i);
}

int main (int argc, char *argv[]) {
    
    cin >> n;
    
    printStar(1);
    
    return 0;
}
