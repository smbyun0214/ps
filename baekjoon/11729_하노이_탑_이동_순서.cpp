#include <iostream>
#include <cmath>

using namespace std;

void hanoiTower(int N, int src, int mid, int dst) {
    if (N == 1) {
        cout << src << ' ' << dst << '\n';
        return;
    }
    
    hanoiTower(N - 1, src, dst, mid);
    hanoiTower(1, src, mid, dst);
    hanoiTower(N - 1, mid, src, dst);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    cout << fixed << int(pow(2, N) - 1) << '\n';
    
    hanoiTower(N, 1, 2, 3);
    
    return 0;
}
