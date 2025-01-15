#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007

using namespace std;

int A[MAX], power_two[MAX], minimum_cover_dp[MAX][2], independent_dp[MAX][2], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, X, Y, minimum_coloring = 0, minimum_cover_max = 0, minimum_cover_cnt = 0, independent_max = 0, independent_cnt = 1, clique_max = 0, clique_cnt = 1;
    bool flag;

    vector<int> arr, val, hamiltonian_front, hamiltonian_back, hamiltonian;
    set<int> st;
    bool check_if_hamiltonian = true;

    cin >> N >> D;

    power_two[0] = 1;
    for (int i = 1; i <= N; i++)
        power_two[i] = power_two[i - 1] * 2 % MOD;

    for (int i = 1; i <= N; i++)
        cin >> A[i], arr.push_back(i), val.push_back(A[i]);

    sort(arr.begin(), arr.end(), [&](int X, int Y) { return A[X] < A[Y]; });
    sort(val.begin(), val.end());

    for (int i = 0; i < N; i++) {
        minimum_cover_dp[i][1] = 2;
        X = lower_bound(val.begin(), val.begin() + i, A[arr[i]] - D) - val.begin() - 1;
        if (i >= 1) {
            minimum_cover_dp[i][0] = 1 + minimum_cover_dp[i - 1][0];
            minimum_cover_dp[i][1] = minimum_cover_dp[i - 1][1];
            if (X >= 0) {
                minimum_cover_dp[i][0] = min(minimum_cover_dp[i][0], minimum_cover_dp[X][0] + i - X - 1);
                minimum_cover_dp[i][1] = (minimum_cover_dp[i][1] + minimum_cover_dp[X][1]) % MOD;
            } else
                minimum_cover_dp[i][1] = (minimum_cover_dp[i][1] + 1) % MOD;
        }
    }
    minimum_cover_max = minimum_cover_dp[N - 1][0], minimum_cover_cnt = minimum_cover_dp[N - 1][1];

    for (int i = 0; i < N; i++) {
        independent_dp[i][0] = 1, independent_dp[i][1] = 1;
        X = lower_bound(val.begin(), val.begin() + i, A[arr[i]] - D) - val.begin() - 1;
        if (X >= 0)
            independent_dp[i][0] = independent_dp[X][0] + 1, independent_dp[i][1] = (independent_dp[i][1] + sm[X]) % MOD;
        if (i)
            sm[i] = (sm[i - 1] + independent_dp[i][1]) % MOD;
        else
            sm[i] = independent_dp[i][1];
    }
    independent_max = independent_dp[N - 1][0], independent_cnt = sm[N - 1] + 1;

    for (int i = 0; i < N; i++) {
        X = lower_bound(val.begin(), val.begin() + i + 1, A[arr[i]] - D) - val.begin();
        clique_max = max(clique_max, i - X + 1), clique_cnt = (clique_cnt + power_two[i - X]) % MOD;
    }

    for (int i : arr) {
        if (st.empty() || A[i] - *st.begin() <= D)
            st.insert(A[i]), minimum_coloring++;
        else
            st.erase(*st.begin()), st.insert(A[i]);
    }

    if (N == 1)
        hamiltonian.push_back(arr[0]);
    else {
        X = arr[0], Y = arr[1];
        check_if_hamiltonian &= A[Y] - A[X] <= D;
        hamiltonian_front.push_back(X), hamiltonian_back.push_back(Y);
        for (int i = 2; i < N - 1; i++) {
            check_if_hamiltonian &= A[arr[i]] - A[X] <= D;
            X = Y, Y = arr[i];
            if (i & 1)
                hamiltonian_back.push_back(Y);
            else
                hamiltonian_front.push_back(Y);
        }
        check_if_hamiltonian &= A[N] - A[X] <= D;
        if (N > 2)
            hamiltonian_back.push_back(arr[N - 1]);
    }

    cout << minimum_cover_max << ' ' << minimum_cover_cnt << '\n';

    cout << independent_max << ' ' << independent_cnt << '\n';

    cout << clique_max << ' ' << clique_cnt << '\n';

    cout << minimum_coloring << '\n';

    cout << check_if_hamiltonian << '\n';

    if (check_if_hamiltonian) {
        reverse(hamiltonian_back.begin(), hamiltonian_back.end());
        hamiltonian.insert(hamiltonian.end(), hamiltonian_front.begin(), hamiltonian_front.end());
        hamiltonian.insert(hamiltonian.end(), hamiltonian_back.begin(), hamiltonian_back.end());

        for (int i : hamiltonian)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}