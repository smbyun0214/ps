// https://www.acmicpc.net/problem/6580

#include <iostream>
#include <sstream>

using namespace std;

int width;
int height;
char board[512][512];

void filledXBM(int y, int x, int size, int xbm) {
    for (int i = 0; i < size; ++i) {
        board[y][x + i] = xbm % 2 ? 'B' : 'W';
        xbm /= 2;
    }
}

string compressed(int y, int x, int size) {
    if (size == 1)
        return string(1, board[y][x]);
    
    int half = size / 2;
    string leftUp = compressed(y, x, half);
    string rightUp = compressed(y, x + half, half);
    string leftDown = compressed(y + half, x, half);
    string rightDown = compressed(y + half, x + half, half);
    
    if (leftUp[0] != 'Q' && leftUp == rightUp && rightUp == leftDown
        && leftDown == rightDown && rightDown == leftUp)
        return leftUp;
    else {
        return "Q" + leftUp + rightUp + leftDown + rightDown;
    }
}

int main (int argc, char *argv[]) {

    char arrWidth[30];
    char arrHeight[30];
    char arrDump[40];
    char arrXBMs0[700];
    int arrXBMs1[700];
    
    cin.getline(arrWidth, sizeof(arrWidth));
    cin.getline(arrHeight, sizeof(arrHeight));
    
    width = atoi(&arrWidth[23]);
    height = atoi(&arrHeight[23]);
    
    cin.getline(arrDump, sizeof(arrDump));
    
    for (int i = 0; i < height; ++i) {
        cin.getline(arrXBMs0, sizeof(arrXBMs0));
        
        int j = 0;
        while (j < width / 8) {
            arrXBMs0[5 * j + 4] = 0;
            stringstream ss(&arrXBMs0[5 * j]);
            ss >> hex >> arrXBMs1[j];
            ++j;
        }
        for (int j = 0; j < width / 8; ++j) {
            filledXBM(i, 8 * j, 8, arrXBMs1[j]);
        }
    }
    
    cout << width << '\n';
    
    cout << compressed(0, 0, width) << '\n';
    
    return 0;
}
