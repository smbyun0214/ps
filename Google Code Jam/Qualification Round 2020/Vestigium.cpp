#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool usedRow[101][101], usedCol[101][101];

int main(int argc, const char * argv[]) {
    int T; cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        
        memset(usedRow, false, sizeof(usedRow));
        memset(usedCol, false, sizeof(usedCol));
        
        vector<vector<int> > matrix(N, vector<int>(N));
        
        int retK = 0, retR = 0, retC = 0;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cin >> matrix[i][j];
            
            retK += matrix[i][i];
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (usedRow[i][matrix[i][j]]) {
                    ++retR;
                    break;
                }
                
                usedRow[i][matrix[i][j]] = true;
            }
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (usedCol[i][matrix[j][i]]) {
                    ++retC;
                    break;
                }
                usedCol[i][matrix[j][i]] = true;
            }
        }
        
        cout << "Case #" << t << ": " << retK << ' ' << retR << ' ' << retC << '\n';
    }
    
    return 0;
}
