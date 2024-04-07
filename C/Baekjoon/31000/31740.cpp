#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B, first, second;
    long long int sm = 0, res = 10000000000000;
    cin >> N;

    int need[N + 1], parent[N + 1] = {};
    long long int dp[N + 1] = {};

    vector<int> arr[N + 1];
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> dp[i];
        sm += dp[i];
    }

    stack<int> st, fr;
    bool checked[N + 1] = {};
    st.push(1);
    checked[1] = true;

    while (st.size())
    {
        A = st.top();
        fr.push(A);
        st.pop();

        for (int i : arr[A])
        {
            if (checked[i])
                continue;
            checked[i] = true;
            parent[i] = A;
            st.push(i);
        }
    }

    while (fr.size())
    {
        A = fr.top();
        fr.pop();

        if (parent[A])
            dp[parent[A]] += dp[A];
    }

    for (int i = 2; i <= N; i++)
    {
        long long int val = abs(sm - 2 * dp[i]);
        if (val < res)
        {
            res = val;
            first = i;
            second = parent[i];
        }
    }

    cout << res << '\n';
    cout << min(first, second) << ' ' << max(first, second);
}