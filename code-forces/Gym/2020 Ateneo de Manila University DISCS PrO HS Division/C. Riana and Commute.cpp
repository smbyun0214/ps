//https://codeforces.com/gym/102556/problem/C
#include <iostream>
#include <vector>

using namespace std;

bool goAteneo(int start, const int dest, vector<int> &busStop) {
    if (start == dest) return true;
    
    if (start == 0 || start == busStop.size() || busStop[start] == 0)
        return false;
    
    int next = busStop[start];
    busStop[start] = 0;
    
    if (next != -1) return goAteneo(next, dest, busStop);
    
    return goAteneo(start - 1, dest, busStop) || goAteneo(start + 1, dest, busStop);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, A, B, X;
    
    cin >> N >> A >> B;
    
    vector<int> busStop(N + 1, -1);
    
    for (int i = 0; i < B; ++i) {
        cin >> X;
        cin >> busStop[X];
    }
    
    cout << (goAteneo(1, A, busStop) ? "YES" : "NO") << '\n';
    
    return 0;
}
