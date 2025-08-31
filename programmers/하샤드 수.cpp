bool solution(int x) {
    int sum = 0, clone = x;
    while (clone > 0) {
        sum += clone % 10;
        clone /= 10;
    }
    
    return x % sum == 0;
}
