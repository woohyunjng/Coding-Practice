bool is_prime(int N) {
    for (int i = 2; i * i <= N; i++) {
        if (!(N % i))
            return false;
    }
    return true;
}