#include <string>
#include <vector>

using namespace std;

bool isValid(int y, int x, int size, const vector<vector<int>>& arr) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[y + i][x + j] != arr[y][x])
                return false;
        }
    }
    return true;
}

pair<int, int> recursive(int y, int x, int size, const vector<vector<int>>& arr) {
    pair<int, int> ret(0, 0);
    pair<int, int> subRet;
    if (!isValid(y, x, size, arr)) {
        int half = size / 2;
        subRet = recursive(y, x, half, arr);
        ret.first += subRet.first; ret.second += subRet.second;
        subRet = recursive(y + half, x, half, arr);
        ret.first += subRet.first; ret.second += subRet.second;
        subRet = recursive(y, x + half, half, arr);
        ret.first += subRet.first; ret.second += subRet.second;
        subRet = recursive(y + half, x + half, half, arr);
        ret.first += subRet.first; ret.second += subRet.second;
    }
    else {
        if (arr[y][x] == 0)
            ++ret.first;
        else
            ++ret.second;
    }
    return ret;
}

vector<int> solution(vector<vector<int>> arr) {
    pair<int, int> ret = recursive(0, 0, arr.size(), arr);
    return {ret.first, ret.second};
}
