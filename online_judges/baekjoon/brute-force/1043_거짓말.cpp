// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

bitset<51> party[51];
bitset<51> avoid;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int avoidCnt;
    cin >> avoidCnt;

    for (int i = 0, j; i < avoidCnt; ++i) {
        cin >> j;
        avoid[j].flip();
    }

    int cnt;
    for (int i = 0; i < M; ++i) {
        cin >> cnt;
        for (int j = 0, k; j < cnt; ++j) {
            cin >> k;
            party[i][k].flip();
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if ((avoid & party[j]).any()) {
                avoid |= party[j];
                party[j].reset();
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < M; ++i) {
        if (party[i].any()) {
            ++ret;
        }
    }
    
    cout << ret << '\n';

    return 0;
}
