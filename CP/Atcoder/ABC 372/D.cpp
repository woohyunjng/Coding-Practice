#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K = 0;
    stack<pr> st;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    st.push({arr[N], N});
    for (int i = N - 1; i >= 1; i--) {
        if (!st.empty() && st.top().second != i + 1)
            res[i] = 1;
        res[i] += st.size();

        while (!st.empty() && st.top().first <= arr[i])
            st.pop();
        st.push({arr[i], i});
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << ' ';

    return 0;
}