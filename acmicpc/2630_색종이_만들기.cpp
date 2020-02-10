#include <iostream>
#include <vector>

using namespace std;

int white = 0, blue = 0;
void countMatrix(const vector<vector<int>>& matrix, int x, int y, int wh) {
    bool isSame = true;
    for (int i = 0; i < wh; ++i) {
        for (int j = 0; j < wh; ++j) {
            if (matrix[y][x] != matrix[y + i][x + j]) {
                isSame = false;
                break;
            }
        }
    }
    
    if (isSame) {
        if (matrix[y][x])
            ++blue;
        else
            ++white;
        
        return;
    }
    
    countMatrix(matrix, x, y, wh / 2);
    countMatrix(matrix, x, y + wh / 2, wh / 2);
    countMatrix(matrix, x + wh / 2, y, wh / 2);
    countMatrix(matrix, x + wh / 2, y + wh / 2, wh / 2);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<vector<int>> matrix(N);
    
    for (int i = 0; i < N; ++i) {
        vector<int> row(N);
        for (int j = 0; j < N; ++j) {
            cin >> row[j];
        }
        
        matrix[i] = row;
    }

    countMatrix(matrix, 0, 0, N);
    
    cout << white << '\n';
    cout << blue << '\n';
    
    return 0;
}
