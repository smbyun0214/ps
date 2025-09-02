// https://www.acmicpc.net/problem/5525

#include <iostream>
#include <string>

using namespace std;

string getIOI(int N) {
    string ret = "";
    for (int i = 0; i < N; ++i) {
        ret += "IO";
    }
    return ret + "I";
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    string str;
    cin >> N >> M >> str;

    string IOI = getIOI(N);
    int idx = 0, ret = 0;
    for (char c : str) {
        if (c == IOI[idx]) {
            if (idx + 1 == IOI.size()) {
                idx -= 2;
                ret += 1;
            }
        }
        else if (c == 'I') {
            idx = 0;
        }
        else {
            idx = -1;
        }
        ++idx;
    }

    cout << ret << '\n';

    return 0;
}
