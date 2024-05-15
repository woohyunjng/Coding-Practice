#include <bits/stdc++.h>
#define MAX 300100
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

vector<int> arr[MAX];
int parent[MAX], dp[MAX], child[MAX], root_length[MAX];
bool visited[MAX];

int comb(int K) { return K * (K - 1) / 2; }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    queue<int> q;
    stack<int> st;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        A = q.front();
        q.pop();
        st.push(A);

        for (int i : arr[A])
        {
            if (visited[i])
                continue;
            visited[i] = true;
            parent[i] = A;
            q.push(i);
        }
    }

    while (!st.empty())
    {
        A = st.top();
        st.pop();

        dp[A] += root_length[A];
        for (int i : arr[A])
        {
            if (i == parent[A])
                continue;
            dp[A] += (child[A] - child[i] - 1) * (child[i] + root_length[i] + 1);
        }

        if (A == 1)
            break;
        dp[parent[A]] += dp[A] + comb(child[A] + 1);
        child[parent[A]] += child[A] + 1;
        root_length[parent[A]] += child[A] + root_length[A] + 1;
    }

    cout << dp[1];
    return 0;
}