vector<bool> get_primes(int N) {
    vector<bool> primes(N + 1);
    fill(primes.begin(), primes.end(), true);
    primes[0] = false, primes[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (!primes[i])
            continue;
        for (int j = i * 2; j <= N; j += i)
            primes[j] = false;
    }

    return primes;
}