#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool checked[30];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, res = 0, val = 0, cur = 0;
    string A, B;
    vector<char> st;
    vector<int> tmp;

    cin >> T;

    while (T--) {
        cin >> N >> K;
        cin >> A >> B;

        st.clear(), tmp.clear();
        for (char i : A)
            st.push_back(i);

        sort(st.begin(), st.end());
        st.erase(unique(st.begin(), st.end()), st.end());

        K = min(K, (int)st.size());
        for (int i = 0; i < K; i++)
            tmp.push_back(1);
        for (int i = 0; i < st.size() - K; i++)
            tmp.push_back(0);

        res = 0;
        do {
            fill(checked, checked + 30, false);
            for (int i = 0; i < st.size(); i++) {
                if (tmp[i] == 0)
                    continue;
                checked[st[i] - 'a'] = true;
            }

            cur = 0, val = 0;

            for (int i = 0; i < N; i++) {
                if (checked[A[i] - 'a'] || B[i] == A[i])
                    cur++;
                else {
                    val += cur * (cur + 1) / 2;
                    cur = 0;
                }
            }

            val += cur * (cur + 1) / 2;
            res = max(res, val);
        } while (prev_permutation(tmp.begin(), tmp.end()));

        cout << res << '\n';
    }

    return 0;
}