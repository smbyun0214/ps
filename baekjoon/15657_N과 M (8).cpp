// https://www.acmicpc.net/problem/15657

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printSequence(vector<int>& indices, int step, const vector<int> &nums) {
    if (step == 0) {
        for (int i : indices) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int smallest = indices.empty() ? 0 : indices.back();
    for (int i = smallest; i < nums.size(); ++i) {
        if (nums[smallest] <= nums[i]) {
            indices.push_back(i);
            printSequence(indices, step - 1, nums);
            indices.pop_back();
        }
            
    }
}

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> nums(N), indices;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    printSequence(indices, M, nums);

    return 0;
}
