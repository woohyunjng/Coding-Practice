#include <bits/stdc++.h>
#define int long long

#define MAX 1500000
using namespace std;

typedef array<int, 2> pr;

int A[MAX], B[MAX], cnt[2][MAX], X[MAX], ans[2][MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, V;
    set<pr> st;
    set<pr>::iterator iter;
    bool flag = true;
    cin >> N;

    for (int i = N; i >= 1; i--)
        cin >> A[i], cnt[0][A[i]]++;
    for (int i = 1; i <= N; i++)
        cin >> B[i], cnt[1][B[i]]++;

    for (int i = 1; i <= N; i++)
        flag &= cnt[0][i] == cnt[1][i];
    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= N; i++)
        arr[A[i]].push_back(i);
    for (int i = 1; i <= N; i++)
        reverse(arr[i].begin(), arr[i].end());

    for (int i = 1; i <= N; i++)
        X[i] = arr[B[i]].back(), arr[B[i]].pop_back();

    for (int i = 1; i <= N; i++) {
        if (st.empty() || (*st.begin())[0] > X[i])
            V = st.size() + 1;
        else
            iter = prev(st.lower_bound({X[i], 0})), V = (*iter)[1], st.erase(iter);
        ans[0][X[i]] = ans[1][i] = V;
        st.insert({X[i], V});
    }

    cout << st.size() << '\n';
    for (int i = N; i >= 1; i--)
        cout << ans[0][i] << ' ';
    cout << '\n';
    for (int i = 1; i <= N; i++)
        cout << ans[1][i] << ' ';
    cout << '\n';

    return 0;
}