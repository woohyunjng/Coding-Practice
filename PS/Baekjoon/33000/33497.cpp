#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200;

int A[MAX], B[MAX], res[MAX][MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, cnt = 0, K, X;
    bool ans = true;

    set<int> st;
    vector<int> arr;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        st.insert(i);

    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        cnt += A[i] + B[i], ans &= A[i] + B[i] <= N;
    }
    cnt += N, ans &= cnt <= N * M;

    if (ans) {
        for (int i = 1; i <= M; i++) {
            X = N - A[i] - B[i], arr.clear();
            while (!st.empty() && X--) {
                K = *st.begin(), st.erase(st.begin());
                chk[K] = true;
            }

            for (int j = 1; j <= N; j++) {
                if (!chk[j])
                    arr.push_back(j);
                chk[j] = false;
            }

            for (int j = 0; j < A[i]; j++)
                res[arr[j]][i] = -1;
            for (int j = A[i]; j < arr.size(); j++)
                res[arr[j]][i] = 1;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
    if (ans) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (res[i][j] == -1)
                    cout << '+';
                else if (res[i][j] == 1)
                    cout << '-';
                else
                    cout << 'X';
            }
            cout << '\n';
        }
    }

    return 0;
}