void init() {
    S = (int)sqrt(N);
    for (int i = 1; i <= N; i++)
        bucket[i / S] += arr[i];
}

void update(int pos, int val) {
    bucket[pos / S] += val - arr[pos], arr[pos] = val;
}

int query(int l, int r) {
    int res = 0;
    for (; l % S && l <= r; l++)
        res += arr[l];
    for (; (r + 1) % S && l <= r; r--)
        res += arr[r];
    for (; l <= r; l += S)
        res += bucket[l / S];
    return res;
}