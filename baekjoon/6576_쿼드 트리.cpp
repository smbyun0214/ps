// https://www.acmicpc.net/problem/6576

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

char board[512][512];

void decompressed(string::iterator& it, int y, int x, int size) {
    char head = *(it++);
    if (head == 'W' || head == 'B') {
        for (int dy = 0; dy < size; ++dy) {
            for (int dx = 0; dx < size; ++dx) {
                board[y + dy][x + dx] = head;
            }
        }
    }
    else {
        int half = size / 2;
        decompressed(it, y, x, half);
        decompressed(it, y, x + half, half);
        decompressed(it, y + half, x, half);
        decompressed(it, y + half, x + half, half);
    }
}

int main (int argc, char *argv[]) {
    memset(board, -1, sizeof(board));
    
    int size;       cin >> size;
    string str;     cin >> str;
    
    string::iterator it = str.begin();
    decompressed(it, 0, 0, size);
    
    cout << "#define quadtree_width " << size << '\n';
    cout << "#define quadtree_height " << size << '\n';
    cout << "static char quadtree_bits[] = {" << '\n';
    for (int i = 0; i < size; ++i) {
        int bit = 0;
        for (int j = 0; j < size; ++j) {
            bit += board[i][j] == 'B' ? pow(2, j % 8) : 0;
            if (j % 8 == 7) {
                cout << "0x" << setw(2) << setfill('0') << hex << bit << ',';
                bit = 0;
            }
        }
        cout << '\n';
    }
    cout << "};" << '\n';
    return 0;
}
