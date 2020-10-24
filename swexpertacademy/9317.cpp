#include <iostream>

using namespace std;

char answer[100001];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    
    char dictation;
    int N, ret;
    for (int t = 1; t <= T; ++t) {
        ret = 0;
        
        cin >> N;
        
        for (int i = 0; i < N; ++i) cin >> answer[i];
        for (int i = 0; i < N; ++i) {
            cin >> dictation;
            if (dictation == answer[i]) ++ret;
        }
        
        cout << '#' << t << ' ' << ret << '\n';
    }
    
    return 0;
}
