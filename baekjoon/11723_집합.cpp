// https://www.acmicpc.net/problem/11723

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    int num;
    string cmd;
    bitset<21> status;
    
    while (n--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> num;
            status.set(num);
        }
        else if (cmd == "remove") {
            cin >> num;
            status.reset(num);
        }
        else if (cmd == "check") {
            cin >> num;
            if (status.test(num))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (cmd == "toggle") {
            cin >> num;
            if (status.test(num))
                status.reset(num);
            else
                status.set(num);
        }
        else if (cmd == "all") {
            status.set();
        }
        else if (cmd == "empty") {
            status.reset();
        }
    }
    
    return 0;
}
