#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ret = "";

void quadTree(const vector<vector<int>>& matrix, int y, int x, int size) {
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
        if (matrix[y][x])
            ret += '1';
        else
            ret += '0';
        
        return;
    }
    
    ret += '(';
    
    int half = size / 2;
    quadTree(matrix, y, x, half);
    quadTree(matrix, y, x + half, half);
    quadTree(matrix, y + half, x, half);
    quadTree(matrix, y + half, x + half, half);
    
    ret += ')';
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<vector<int>> matrix;
    
    string line;
    for (int i = 0; i < N; ++i) {
        cin >> line;
        
        vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        
        matrix.push_back(row);
    }
    
    quadTree(matrix, 0, 0, N);
    
    cout << ret << '\n';
    
    return 0;
}
