#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define MAX_LOG 18

using namespace std;
typedef pair<int, int> pr;

int N, parent[MAX][MAX_LOG], depth[MAX];
vector<int> arr[MAX];
bool checked[MAX];

void dfs(int K)
{
    int A;
    stack<int> st;

    st.push(K);
    checked[K] = true;

    while (!st.empty())
    {
        A = st.top();
        st.pop();

        for (int i : arr[A])
        {
            if (checked[i])
                continue;
            parent[i][0] = A;
            checked[i] = true;
            depth[i] = depth[A] + 1;

            for (int j = 1; j < MAX_LOG; j++)
            {
                if (!parent[i][j - 1])
                    continue;
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }

            st.push(i);
        }
    }
}

int LCA(int A, int B)
{
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B];
    for (int i = 0; diff; i++)
    {
        if (diff & 1)
            A = parent[A][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--)
    {
        if (parent[A][i] != parent[B][i])
            A = parent[A][i], B = parent[B][i];
    }
    if (A != B)
        A = parent[A][0];
    return A;
}

int get_dis(int A, int B)
{
    int X = LCA(A, B);
    return depth[A] + depth[B] - 2 * depth[X];
}
int center(int A, int B)
{
    int X = LCA(A, B), diff;

    if (depth[A] < depth[B])
        swap(A, B);

    diff = get_dis(A, B);
    if (diff & 1)
        return -1;

    diff >>= 1;
    for (int i = 0; diff; i++)
    {
        if (diff & 1)
            A = parent[A][i];
        diff >>= 1;
    }

    return A;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, C, X, Y, Z;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }
    dfs(1);

    cin >> Q;
    while (Q--)
    {
        cin >> A >> B >> C;
        X = center(A, B);
        Y = center(B, C);
        Z = center(C, A);

        if (X == -1 || Y == -1 || Z == -1)
            cout << -1 << '\n';
        else if (get_dis(X, C) == get_dis(X, A))
            cout << X << '\n';
        else if (get_dis(Y, A) == get_dis(Y, B))
            cout << Y << '\n';
        else if (get_dis(Z, B) == get_dis(Z, C))
            cout << Z << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}