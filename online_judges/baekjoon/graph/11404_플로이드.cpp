// https://www.acmicpc.net/problem/11404

#include <iostream>
#include <cstring>

using namespace std;

int prices[101][101];

int INF = 987654321;

void init() {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            if (i == j) {
                prices[i][j] = 0;
            }
            else {
                prices[i][j] = INF;
            }
        }
    }
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    init();

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        prices[a][b] = min(prices[a][b], c);
    }

    for (int middle = 1; middle <= n; ++middle) {
        for (int from = 1; from <= n; ++from) {
            for (int to = 1; to <= n; ++to) {
                prices[from][to] = min(prices[from][to], prices[from][middle] + prices[middle][to]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << (prices[i][j] == INF ? 0 : prices[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
