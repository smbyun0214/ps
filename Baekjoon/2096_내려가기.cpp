#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int board[3];
int cacheMax[2][3], cacheMin[2][3];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    memset(cacheMax, 0, sizeof(cacheMax));
    memset(cacheMin, 0, sizeof(cacheMin));
    
    cacheMin[0][0] = cacheMin[0][1] = cacheMin[0][2] = INF;
    
    int N; cin >> N;
    
    int step = 0;
    
    N--;
    
    cin >> board[0] >> board[1] >> board[2];
    
    cacheMax[0][0] = cacheMin[0][0] = board[0];
    cacheMax[0][1] = cacheMin[0][1] = board[1];
    cacheMax[0][2] = cacheMin[0][2] = board[2];
    
    ++step;
    
    while (N--) {
        cin >> board[0] >> board[1] >> board[2];
        
        cacheMax[step % 2][0] = max(board[0] + cacheMax[(step + 1) % 2][0],
                                    board[0] + cacheMax[(step + 1) % 2][1]);
        cacheMax[step % 2][1] = max(board[1] + cacheMax[(step + 1) % 2][0],
                             max(board[1] + cacheMax[(step + 1) % 2][1],
                                 board[1] + cacheMax[(step + 1) % 2][2]));
        cacheMax[step % 2][2] = max(board[2] + cacheMax[(step + 1) % 2][1],
                                    board[2] + cacheMax[(step + 1) % 2][2]);
                                    
        cacheMin[step % 2][0] = min(board[0] + cacheMin[(step + 1) % 2][0],
                                    board[0] + cacheMin[(step + 1) % 2][1]);
        cacheMin[step % 2][1] = min(board[1] + cacheMin[(step + 1) % 2][0],
                             min(board[1] + cacheMin[(step + 1) % 2][1],
                                 board[1] + cacheMin[(step + 1) % 2][2]));
        cacheMin[step % 2][2] = min(board[2] + cacheMin[(step + 1) % 2][1],
                                    board[2] + cacheMin[(step + 1) % 2][2]);
        
        ++step;
    }
    
    int retMax = 0, retMin = INF;
    for (int i = 0; i < 3; ++i) {
        retMax = max(retMax, cacheMax[(step + 1) % 2][i]);
        retMin = min(retMin, cacheMin[(step + 1) % 2][i]);
    }
    
    cout << retMax << ' ' << retMin << '\n';
    
    return 0;
}
