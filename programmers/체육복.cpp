#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> people(n, 1);
    for (int i : lost) {
        people[i-1] -= 1;
    }
    for (int i : reserve) {
        people[i-1] += 1;
    }
    for (int i = 1; i < n; ++i) {
        if (people[i-1] == 0 && people[i] == 2) {
            people[i-1] = 1;
            people[i] = 1;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (people[i] == 2 && people[i+1] == 0) {
            people[i] = 1;
            people[i+1] = 1;
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (people[i] >= 1) {
            ++answer;
        }
    }
    
    return answer;
}
