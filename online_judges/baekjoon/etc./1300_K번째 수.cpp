// https://www.acmicpc.net/problem/1300

#include <iostream>
#include <cstring>

using namespace std;

long long N;
long long k;

long long getLessCount(long long num, long long size) {
    long long ret = 0;
    for (long long i = 1; i <= size; ++i) {
        long long cnt = min(num / i, size);
        if (cnt == 0) {
            break;
        }
        ret += cnt;
    }
    return ret;
}

long long binarySearch(long long left, long long right) {
    if (left == right) {
        return left;
    }

    long long mid = (left + right) / 2;

    if (getLessCount(mid, N) < k) {
        return binarySearch(mid + 1, right);
    }
    return binarySearch(left, mid);
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> k;

    cout << binarySearch(1, N * N) << '\n';

    return 0;
}
