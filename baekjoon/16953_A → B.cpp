// https://www.acmicpc.net/problem/16953

#include <iostream>
#include <limits>

using namespace std;

int minStep = numeric_limits<int>::max();

void setMinStep(long long src, long long dst, int step) {
    if (src > dst || step > minStep) {
        return;
    }

    if (src == dst) {
        minStep = min(step, minStep);
        return;
    }

    setMinStep(src * 2, dst, step + 1);
    setMinStep(src * 10 + 1, dst, step + 1);
}


int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long A, B;
    cin >> A >> B;
    
    setMinStep(A, B, 1);

    cout << (minStep == numeric_limits<int>::max() ? -1 : minStep) << '\n';
    
    return 0;
}
