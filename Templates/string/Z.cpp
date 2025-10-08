void init() {
    Z[0] = N;
    for (int i = 1; i < N; i++) {
        if (i <= R)
            Z[i] = min(R - i, Z[i - L]);
        while (i + Z[i] < N && S[Z[i]] == S[i + Z[i]])
            Z[i]++;
        if (i > R)
            L = i;
        R = max(R, i + Z[i] - 1);
    }
}