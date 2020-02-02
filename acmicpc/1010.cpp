#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 30;
int cache[SIZE][SIZE];

bool inRange(int n) {
    return 0 <= n && n < SIZE;
}

int buildBridge(int left, int right) {
    if (!inRange(left) || !inRange(right))
        return 0;

    if (left == 0 && right == 0)
        return 1;

    int &ret = cache[left][right];
    if (ret != -1)
        return ret;

    return ret = buildBridge(left, right - 1) + buildBridge(left - 1, right - 1);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(cache, -1, sizeof(cache));

    int T, lSite, rSite;
    cin >> T;

    while (T--) {
        cin >> lSite >> rSite;
        cout << buildBridge(lSite, rSite) << '\n';
    }

    return 0;
}
