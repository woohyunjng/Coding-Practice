// sum(i=1~N) [i * P / Q] O(logN)

int div_sum(int P, int Q, int N) {
    int G = gcd(P, Q);
    P /= G, Q /= G;
    if (N == 0 || P == 0)
        return 0;
    else if (Q == 1)
        return P * N * (N + 1) / 2;
    else if (P > Q)
        return div_sum(P % Q, Q, N) + N * (N + 1) / 2 * (P / Q);
    else
        return N * (N * P / Q) + N / Q - div_sum(Q, P, N * P / Q);
}