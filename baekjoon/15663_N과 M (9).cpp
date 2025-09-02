// https://www.acmicpc.net/problem/15663

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    string prev = "";
    do {
        string ret = "";
        for (int i = 0; i < M; ++i) {
            ret += to_string(nums[i]);
            ret += ' ';
        }
        if (prev == ret) {
            continue;
        }
        cout << ret << '\n';
        prev = ret;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}
