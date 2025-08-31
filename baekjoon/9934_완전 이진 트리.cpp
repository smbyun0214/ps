// https://www.acmicpc.net/problem/9934

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> nodes;

void printInOrder(int height, int here, int step) {
    if (height == 0) {
        cout << nodes[here + step] << ' ';
        return;
    }
    
    printInOrder(height - 1, here, step / 2);
    printInOrder(height - 1, here + step, step / 2);
}

int main (int argc, char *argv[]) {
    
    nodes.push_back(0);
    
    int K;
    cin >> K;
    
    int n, size = pow(2, K);
    for (int i = 0; i < size - 1; ++i) {
        cin >> n;
        nodes.push_back(n);
    }
    
    for (int height = 0; height < K; ++height) {
        printInOrder(height, 0, nodes.size() / 2);
        cout << '\n';
    }
    
    return 0;
}
