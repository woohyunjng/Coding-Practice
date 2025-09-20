#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<int> arr[MAX];
int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, K, X, ans = INF;
    vector<int> comp;
    vector<pr> val, lst;

    set<pr> st;
    set<pr>::iterator iter;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], comp.push_back(A[i]);

    function<int(int, int)> dis = [&](int x, int y) {
        return min((x + N - y) % N, (y + N - x) % N);
    };

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    S = comp.size();

    for (int i = 1; i <= N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin() + 1;
        arr[A[i]].push_back(i);
    }

    st.insert({1, 0});

    for (int i = 1; i <= S; i++) {
        val.clear(), K = arr[i].size();
        for (int j = 0; j < K; j++) {
            iter = st.lower_bound({arr[i][j], -1}), X = INF;
            if (iter != st.end())
                X = min(X, (*iter)[1] + dis(arr[i][j], (*iter)[0]));
            if (iter != st.begin())
                iter--, X = min(X, (*iter)[1] + dis(arr[i][j], (*iter)[0]));
            iter = prev(st.end()), X = min(X, (*iter)[1] + dis(arr[i][j], (*iter)[0]));
            iter = st.begin(), X = min(X, (*iter)[1] + dis(arr[i][j], (*iter)[0]));

            if (K == 1)
                val.push_back({arr[i][j], X});
            else {
                val.push_back({arr[i][(j + 1) % K], X + N - (arr[i][(j + 1) % K] + N - arr[i][j]) % N});
                val.push_back({arr[i][(j + K - 1) % K], X + N - (arr[i][j] + N - arr[i][(j + K - 1) % K]) % N});
            }
        }

        sort(val.begin(), val.end()), lst.clear();
        for (pr j : val) {
            while (!lst.empty() && lst.back()[1] >= j[1] + dis(lst.back()[0], j[0]))
                lst.pop_back();
            if (lst.empty() || lst.back()[1] + dis(lst.back()[0], j[0]) > j[1])
                lst.push_back(j);
        }
        val = lst, lst.clear();
        reverse(val.begin(), val.end());
        for (pr j : val) {
            while (!lst.empty() && lst.back()[1] >= j[1] + dis(lst.back()[0], j[0]))
                lst.pop_back();
            if (lst.empty() || lst.back()[1] + dis(lst.back()[0], j[0]) > j[1])
                lst.push_back(j);
        }

        while (lst.size() > 1 && lst.back()[1] >= lst[0][1] + dis(lst.back()[0], lst[0][0]))
            lst.pop_back();
        reverse(lst.begin(), lst.end());
        while (lst.size() > 1 && lst.back()[1] >= lst[0][1] + dis(lst.back()[0], lst[0][0]))
            lst.pop_back();
        reverse(lst.begin(), lst.end());
        while (lst.size() > 1 && lst.back()[1] >= lst[0][1] + dis(lst.back()[0], lst[0][0]))
            lst.pop_back();
        reverse(lst.begin(), lst.end());
        while (lst.size() > 1 && lst.back()[1] >= lst[0][1] + dis(lst.back()[0], lst[0][0]))
            lst.pop_back();

        st.clear();
        for (pr j : lst)
            st.insert(j);
    }

    for (pr i : st)
        ans = min(ans, i[1]);
    cout << ans << '\n';

    return 0;
}