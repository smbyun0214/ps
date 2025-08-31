// https://www.acmicpc.net/problem/15654

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visited[10001];

void printSequence(vector<int>& ret, int step, const vector<int> &nums) {
    if (step == 0) {
        for (int i : ret) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        ret.push_back(nums[i]);
        printSequence(ret, step - 1, nums);
        ret.pop_back();
        visited[i] = false;
    }
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(visited, false, sizeof(visited));
    
    int N, M;
    cin >> N >> M;

    vector<int> nums(N), ret;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    printSequence(ret, M, nums);

    return 0;
}
