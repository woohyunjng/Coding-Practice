#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int ans[MAX], arr[MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, T, S, A, B, nl, nr, l, r;
    vector<tp> query;

    cin >> N >> T;
    S = sqrt(N);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= T; i++) {
        cin >> A >> B;
        query.push_back({A, B, i});
    }

    sort(query.begin(), query.end(), [S](tp a, tp b) {
        int af = a[0] / S, bf = b[0] / S;
        if (af == bf)
            return a[1] / S < b[1] / S;
        return af < bf;
    });

    for (int i = query[0][0]; i <= query[0][1]; i++) {
        ans[0] -= arr[i] * cnt[arr[i]] * cnt[arr[i]];
        cnt[arr[i]]++;
        ans[0] += arr[i] * cnt[arr[i]] * cnt[arr[i]];
    }
    ans[query[0][2]] = ans[0];
    nl = query[0][0], nr = query[0][1];

    for (int i = 1; i < T; i++) {
        l = query[i][0], r = query[i][1];
        while (nl < l) {
            ans[0] -= arr[nl] * cnt[arr[nl]] * cnt[arr[nl]];
            cnt[arr[nl]]--;
            ans[0] += arr[nl] * cnt[arr[nl]] * cnt[arr[nl]];
            nl++;
        }
        while (nr > r) {
            ans[0] -= arr[nr] * cnt[arr[nr]] * cnt[arr[nr]];
            cnt[arr[nr]]--;
            ans[0] += arr[nr] * cnt[arr[nr]] * cnt[arr[nr]];
            nr--;
        }
        while (nl > l) {
            ans[0] -= arr[--nl] * cnt[arr[nl]] * cnt[arr[nl]];
            cnt[arr[nl]]++;
            ans[0] += arr[nl] * cnt[arr[nl]] * cnt[arr[nl]];
        }
        while (nr < r) {
            ans[0] -= arr[++nr] * cnt[arr[nr]] * cnt[arr[nr]];
            cnt[arr[nr]]++;
            ans[0] += arr[nr] * cnt[arr[nr]] * cnt[arr[nr]];
        }

        ans[query[i][2]] = ans[0];
    }

    for (int i = 1; i <= T; i++)
        cout << ans[i] << '\n';

    return 0;
}
