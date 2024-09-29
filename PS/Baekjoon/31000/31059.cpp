#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, arr[MAX], sm[MAX];

int get_val(int A, int B, int K) {
    int X = lower_bound(arr + 1, arr + N + 1, K) - arr;
    return A * (K * (X - 1) - sm[X - 1]) + B * (sm[N] - sm[X - 1] - K * (N - X + 1));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, A, B, st, en, f_th, s_th, res = INF;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++)
        sm[i] = sm[i - 1] + arr[i];

    cin >> Q;
    while (Q--) {
        cin >> A >> B;
        st = arr[1], en = arr[N];

        while (en - st > 2) {
            f_th = st + (en - st) / 3;
            s_th = en - (en - st) / 3;

            if (get_val(A, B, f_th) < get_val(A, B, s_th))
                en = s_th;
            else
                st = f_th;
        }

        res = INF;
        for (int i = st; i <= en; i++)
            res = min(res, get_val(A, B, i));

        cout << res << '\n';
    }

    return 0;
}