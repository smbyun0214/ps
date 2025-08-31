//
//  cin_ignore.cpp
//  ProblemSolving
//
//  Created by 변성목 on 2020/10/29.
//  Copyright © 2020 변성목. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    cin.ignore();
    
    string row;
    while (n--) {
        getline(cin, row);
    }
    
    return 0;
}

