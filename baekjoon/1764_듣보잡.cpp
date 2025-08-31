// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    vector<string> people(N + M);
    for (int i = 0; i < N + M; ++i) {
        cin >> people[i];
    }
    
    sort(people.begin(), people.end());
    
    vector<string> dup;
    for (int i = 1; i < people.size(); ++i) {
        if (people[i - 1] == people[i]) {
            dup.push_back(people[i]);
        }
    }
    
    cout << dup.size() << '\n';
    for (string& str : dup) {
        cout << str << '\n';
    }
    
    return 0;
}
