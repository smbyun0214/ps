#include <iostream>
#include <vector>

using namespace std;

long long getLength(const vector<long long>& lan, long long width) {
    if (width == 0)
        return -1;
    
    long long tmp = 0;

    for (long long i : lan) {
        tmp += i / width;
    }
    
    return tmp;
}

long long maxlength(const vector<long long>& lan, long long left, long long right, long long count) {
    if (left == right) {
        if (count == getLength(lan, left))
            return left;
        else
            return left - 1;
    }
    
    long long mid = (left + right) / 2;
    long long tmp = getLength(lan, mid);
    
    if (tmp < count)
        return maxlength(lan, left, mid, count);
    else
        return maxlength(lan, mid + 1, right, count);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    
    vector<long long> lan(N);
    
    for (int i = 0; i < N; ++i)
        cin >> lan[i];
    
    long long maxLength = 2147483647;
    cout << maxlength(lan, 0, maxLength, K) << '\n';
    
    return 0;
}
