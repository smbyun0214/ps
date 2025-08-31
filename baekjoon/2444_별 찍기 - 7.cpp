// https://www.acmicpc.net/problem/2444

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
        print(n - i - 1, ' ');
        print(2 * i + 1, '*');
        cout << '\n';
    }
    else if (i > n){
        print(i % n, ' ');
        print(2 * (n - (i % n)) - 1, '*');
        cout << '\n';
    }
    
    ++i;
    printStar(i);
}

int main (int argc, char *argv[]) {
    
    cin >> n;
    
    printStar(0);
    
    return 0;
}
