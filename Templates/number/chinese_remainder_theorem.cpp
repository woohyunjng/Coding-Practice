int gcd(int A, int B) { return B ? gcd(B, A % B) : A; }

tp extended_gcd(int A, int B) {
    if (B == 0)
        return {A, 1, 0};
    tp res = extended_gcd(B, A % B);
    return {res[0], res[2], res[1] - A / B * res[2]};
}

pr chinese_remainder_theorem(int A, int B, int M, int N) {
    int diff, M_prime, N_prime, G = gcd(M, N), mod, rem;

    if ((A - B) % G)
        return {-1, -1};

    M_prime = M / G, N_prime = N / G;
    diff = (B - A) / G;

    tp res = extended_gcd(M_prime, N_prime);

    mod = M_prime * N_prime * G;
    rem = (A + (res[1] * diff % N_prime) * M) % mod;

    if (rem < 0)
        rem += mod;

    return {rem, mod};
}