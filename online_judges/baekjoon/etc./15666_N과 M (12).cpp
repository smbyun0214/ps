// https://www.acmicpc.net/problem/15666

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printNums(int here, int step, string str, vector<int>& nums) {
    if (step == 0) {
        cout << str << '\n';
        return;
    }

    if (here == nums.size()) {
        return;
    }

    printNums(here, step - 1, str + to_string(nums[here]) + " ", nums);
    printNums(here + 1, step, str, nums);
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<int> nums(M);

    for (int i = 0, j; i < M; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    printNums(0, N, "", nums);
    
    return 0;
}
