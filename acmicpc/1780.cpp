#include <iostream>
#include <vector>

using namespace std;

int retMinus = 0, retZero = 0, retOne = 0;

void paperCount(const vector<vector<int>>& matrix, int y, int x, int size) {
    bool isSame = true;
    
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            if (matrix[y][x] != matrix[y + j][x + i]) {
                isSame = false;
                break;
            }
        }
    }
    
    if (isSame) {
        if (matrix[y][x] == -1)
            ++retMinus;
        else if (matrix[y][x])
            ++retOne;
        else
            ++retZero;
        
        return;
    }
    
    int oneThird = size / 3;
    int twoThird = 2 * size / 3;
    
    paperCount(matrix, y, x, oneThird);
    paperCount(matrix, y, x + oneThird, oneThird);
    paperCount(matrix, y, x + twoThird, oneThird);
    
    paperCount(matrix, y + oneThird, x, oneThird);
    paperCount(matrix, y + oneThird, x + oneThird, oneThird);
    paperCount(matrix, y + oneThird, x + twoThird, oneThird);
    
    paperCount(matrix, y + twoThird, x, oneThird);
    paperCount(matrix, y + twoThird, x + oneThird, oneThird);
    paperCount(matrix, y + twoThird, x + twoThird, oneThird);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<vector<int>> matrix(N);
    
    for (int j = 0; j < N; ++j) {
        vector<int> row(N);
        
        for (int i = 0; i < N; ++i)
            cin >> row[i];
        
        matrix[j] = row;
    }
    
    paperCount(matrix, 0, 0, N);
    
    cout << retMinus << '\n';
    cout << retZero << '\n';
    cout << retOne << '\n';
    
    return 0;
}
