#include <algorithm>

using namespace std;

long long solution(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    
    // 등차수열의 합
    long long lla = a, llb = b;
    return (llb - lla + 1) * (lla + llb) / 2;
}
