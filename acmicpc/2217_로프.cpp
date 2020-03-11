#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    
    vector<int> ropes(N + 1, 0);
    
    for (int i = 0; i < N; ++i)
        cin >> ropes[i];
    
    sort(ropes.begin(), ropes.end());
    
    int weight = 0;
    
    for (int i = 0; i < ropes.size(); ++i) {
        weight = max(weight, ((int)ropes.size() - i) * ropes[i]);
    }
    
    cout << weight << '\n';

    return 0;
}
