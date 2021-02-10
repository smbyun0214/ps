#include <string>
#include <vector>

using namespace std;

pair<int, int> getLeftIndex(int here, const string& str) {
    int length = str.size();
    for (int i = 0; i < length; ++i) {
        int idx = (here - i + length) % length;
        if (str[idx] != 'A') {
            return {idx, i};
        }
    }

    return {-1, 0};
}

pair<int, int> getRightIndex(int here, const string& str) {
    int length = str.size();
    for (int i = 0; i < length; ++i) {
        int idx = (here + i) % length;
        if (str[idx] != 'A') {
            return {idx, i};
        }
    }

    return {-1, 0};
}

int changeCursor(char c) {
    if (c - 'A' + 1 <= ('Z' - 'A' + 1) / 2)
        return c - 'A';
    return 'Z' - c + 1;
}

int recursiveMin(int here, string str) {
    if (here == -1)
        return 0;

    int cnt = changeCursor(str[here]);

    str[here] = 'A';

    pair<int, int> left = getLeftIndex(here, str);
    pair<int, int> right = getRightIndex(here, str);

    int leftIdx = left.first, leftStep = left.second;
    int rightIdx = right.first, rightStep = right.second;

    int leftRet = cnt + leftStep + recursiveMin(leftIdx, str);
    int rightRet = cnt + rightStep + recursiveMin(rightIdx, str);

    return min(leftRet, rightRet);
}

int solution(string name) {
    return recursiveMin(0, name);
}
