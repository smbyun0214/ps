// https://www.acmicpc.net/problem/11721

#include <iostream>
#include <string>

using namespace std;

void print(int, string);

int main (int argc, char *argv[]) {
    string row;
    cin >> row;
    print(10, row);

    return 0;
}

void print(int n, string str) {
    // 기저 사례: 문장의 길이가 n보다 작을 경우 전체 출력
    if (str.size() < n) {
        cout << str << '\n';
        return;
    }
    
    cout << str.substr(0, n) << '\n';
    print(n, str.substr(n));
}
