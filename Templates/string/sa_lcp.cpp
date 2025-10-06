int sa[MAX], lcp[MAX]; // sa[i] -> 사전째 i번째의 suffix, lcp[i] -> sa[i]와 sa[i-1]의 lcp

void init(string S) {
    int N = S.size(), K = 1;
    vector<int> group(N + 1, 0), nxt(N + 1, 0), rnk(N + 1, 0);

    for (int i = 0; i < N; i++)
        sa[i] = i, group[i] = S[i] - 'a';

    function<bool(int, int)> cmp = [&](int X, int Y) {
        if (group[X] == group[Y])
            return group[X + K] < group[Y + K];
        return group[X] < group[Y];
    };

    group[N] = -1;
    while (K <= N) {
        sort(sa, sa + N, cmp);

        for (int i = 1; i < N; i++) {
            if (cmp(sa[i - 1], sa[i]))
                nxt[sa[i]] = nxt[sa[i - 1]] + 1;
            else
                nxt[sa[i]] = nxt[sa[i - 1]];
        }

        for (int i = 0; i < N; i++)
            group[i] = nxt[i];
        K <<= 1;
    }

    int X = 0, Y, j;

    for (int i = 0; i < N; i++)
        rnk[sa[i]] = i;

    for (int i = 0; i < N; i++) {
        Y = rnk[i];
        if (Y) {
            j = sa[Y - 1];
            while (S[i + X] == S[j + X])
                X++;
            lcp[Y] = X;
            if (X)
                X--;
        }
    }
}