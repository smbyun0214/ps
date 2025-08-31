// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <cstring>

bool board[100][100];
bool isRemain[100];

using namespace std;

int worm(int, int);

int main (int argc, char *argv[]) {
    memset(board, 0, sizeof(board));
    
    int numOfComputers;
    cin >> numOfComputers;
    
    int numOfLinks;
    cin >> numOfLinks;
    
    int A, B;
    for (int i = 0; i < numOfLinks; ++i) {
        cin >> A >> B;
        board[A-1][B-1] = board[B-1][A-1] = true;
        isRemain[A-1] = isRemain[B-1] = true;
    }
    
    cout << worm(0, numOfComputers) << '\n';
    
    return 0;
}

int worm(int here, int size) {
    isRemain[here] = false;
    
    int ret = 0;
    for (int there = 0; there < size; ++there) {
        if (board[here][there] && isRemain[there]) {
            isRemain[there] = false;
            ret += 1 + worm(there, size);
        }
    }
    
    return ret;
}
