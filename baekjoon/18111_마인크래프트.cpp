// https://www.acmicpc.net/problem/18111

#include <iostream>
#include <cstring>

using namespace std;

// 같은 높이를 가지는 영역들의 총 개수
int areas[257];
const int INF = 987654321;

int length, width, inventory;

int solve(int toHeight, int inventory) {
    int ret = 0;
    for (int hi = 256; 0 <= hi; --hi) {
        const int area = areas[hi];
        // 높이가 hi인 영역이 없을 경우
        if (area == 0) continue;
        
        // hi인 높이를 toHieght만큼 만들기 위한 비용
        if (toHeight < hi) {
            ret += 2 * area * (hi - toHeight);
            inventory += area * (hi - toHeight);
        }
        else if (hi < toHeight) {
            // 인벤토리에 있는 블록의 갯수가 부족할 경우 최댓값 반환
            if (inventory < area * (toHeight - hi))
                return INF;
            
            ret += area * (toHeight - hi);
            inventory -= area * (toHeight - hi);
        }
    }
    return ret;
}

int main (int argc, char *argv[]) {
    memset(areas, 0, sizeof(areas));
    cin >> length >> width >> inventory;
    
    int hIndex;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> hIndex;
            ++areas[hIndex];
        }
    }
    
    int ret = INF, height = -1;
    for (int i = 256; 0 <= i; --i) {
        int cand = solve(i, inventory);
        if (cand < ret) {
            ret = cand;
            height = i;
        }
    }
    cout << ret << ' ' << height;
    
    return 0;
}
