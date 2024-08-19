int ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, S, A, B, nl, nr, l, r;
    vector<tp> query;

    cin >> N;
    S = sqrt(N);

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> A >> B;
        query.push_back({A, B, i});
    }

    sort(query.begin(), query.end(), [S](tp a, tp b) {
        int af = a[0] / S, bf = b[0] / S;
        if (af == bf)
            return a[1] / S < b[1] / S;
        return af < bf;
    });

    for (int i = query[0][0]; i <= query[0][1]; i++)
        continue;
    ans[query[0][2]] = ans[0];
    nl = query[0][0], nr = query[0][1];

    for (int i = 1; i < M; i++) {
        l = query[i][0], r = query[i][1];
        while (nl < l)
            continue;
        while (nr > r)
            continue;
        while (nl > l)
            continue;
        while (nr < r)
            continue;

        ans[query[i][2]] = ans[0];
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}
