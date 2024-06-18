#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define MAX_VAL 1000100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], ans[MAX];
int cnt[MAX_VAL];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S, A, B, l, r, nl, nr;
    vector<tp> query;

    cin >> N;
    S = sqrt(N);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cin >> M;
    for (int i = 1; i <= M; i++) {
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
        if (++cnt[arr[i]] == 1)
            ans[0]++;
    ans[query[0][2]] = ans[0];
    nl = query[0][0], nr = query[0][1];

    for (int i = 1; i < M; i++) {
        l = query[i][0], r = query[i][1];
        while (nl < l)
            if (--cnt[arr[nl++]] == 0)
                ans[0]--;
        while (nr > r)
            if (--cnt[arr[nr--]] == 0)
                ans[0]--;
        while (nl > l)
            if (++cnt[arr[--nl]] == 1)
                ans[0]++;
        while (nr < r)
            if (++cnt[arr[++nr]] == 1)
                ans[0]++;

        ans[query[i][2]] = ans[0];
    }

    for (int i = 1; i <= M; i++)
        cout << ans[i] << '\n';

    return 0;
}
