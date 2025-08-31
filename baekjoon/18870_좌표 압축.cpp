// https://www.acmicpc.net/problem/18870 

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, x;
    cin >> N;

    vector<int> arr;
    set<int> keys;
    unordered_map<int, int> map;
    set<int>::iterator it;

    for (int i = 0; i < N; ++i) {
        cin >> x;
        keys.insert(x);
        arr.push_back(x);
    }
    
    int idx = 0;
    for (it = keys.begin(); it != keys.end(); ++it) {
        map.insert(make_pair(*it, idx++));
    }

    for (int i : arr) {
        cout << map[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
