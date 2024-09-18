#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int ans[MAX], color[MAX], arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, C, M, S, A, B, nl, nr, l, r, X;
    vector<tp> query;

    cin >> N >> C;
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

    X = query[0][1] - query[0][0] + 1;
    for (int i = query[0][0]; i <= query[0][1]; i++) {
        color[arr[i]]++;
        if (color[arr[i]] > X / 2)
            ans[0] = arr[i];
    }
    ans[query[0][2]] = ans[0];
    nl = query[0][0], nr = query[0][1];

    for (int i = 1; i < M; i++) {
        l = query[i][0], r = query[i][1];
        X = r - l + 1;

        while (nl < l)
            color[arr[nl++]]--;
        while (nr > r)
            color[arr[nr--]]--;
        while (nl > l)
            ++color[arr[--nl]];
        while (nr < r)
            ++color[arr[++nr]];

        for (int j = 1; j <= C; j++) {
            if (color[j] > X / 2) {
                ans[query[i][2]] = j;
                break;
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        if (ans[i])
            cout << "yes " << ans[i] << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}
