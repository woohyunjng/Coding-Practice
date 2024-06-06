#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#define MOD 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, A, B, C, res = 0;
    cin >> N;

    vector<pair<long long, long long>> arr[N + 1];

    for (long long i = 0; i < N - 1; i++)
    {
        cin >> A >> B >> C;
        arr[A].push_back({B, C});
        arr[B].push_back({A, C});
    }

    stack<long long> st;
    queue<long long> qu;
    pair<long long, long long> parent[N + 1] = {{0, 0}};
    pair<long long, long long> dp[N + 1] = {{0, 0}};

    qu.push(1);
    parent[1] = {-1, 1};

    while (!qu.empty())
    {
        A = qu.front();
        st.push(A);
        qu.pop();

        for (pair<long long, long long> i : arr[A])
        {
            if (parent[i.first].first)
                continue;
            parent[i.first] = {A, i.second};
            qu.push(i.first);
        }
    }

    while (!st.empty())
    {
        A = st.top();
        st.pop();

        if (A != 1)
        {
            B = parent[A].second * (1 + dp[A].first) % MOD;
            dp[parent[A].first].second = (dp[parent[A].first].second + B + dp[parent[A].first].first * B) % MOD;
            dp[parent[A].first].first = (dp[parent[A].first].first + B) % MOD;
        }
        res = (res + dp[A].second) % MOD;
    }

    cout << res;
}