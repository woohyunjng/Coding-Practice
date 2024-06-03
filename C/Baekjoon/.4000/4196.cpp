#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

vector<int> arr[100010], rvt_arr[100010], scc[100010];
stack<int> st;
bool checked[100010];
int scc_num = 0, scc_group[100010], in_degree[100010];

void clear_all(int V)
{
    scc_num = 0;
    for (int i = 1; i <= V; i++)
    {
        arr[i].clear();
        rvt_arr[i].clear();
        scc[i].clear();
    }
}

void add_path(int A, int B)
{
    arr[A].push_back(B);
    rvt_arr[B].push_back(A);
}

void kosaraju_first_dfs(int K)
{
    checked[K] = true;
    for (int i : arr[K])
    {
        if (!checked[i])
            kosaraju_first_dfs(i);
    }
    st.push(K);
}

void kosaraju_second_dfs(int K)
{
    checked[K] = true;
    for (int i : rvt_arr[K])
    {
        if (!checked[i])
            kosaraju_second_dfs(i);
    }
    scc[scc_num].push_back(K);
    scc_group[K] = scc_num;
}

void kosaraju(int V)
{
    int A;
    scc_num = 0;

    fill(checked, checked + V + 1, false);
    for (int i = 1; i <= V; i++)
    {
        if (!checked[i])
            kosaraju_first_dfs(i);
    }

    fill(checked, checked + V + 1, false);
    while (!st.empty())
    {
        A = st.top();
        st.pop();
        if (!checked[A])
        {
            kosaraju_second_dfs(A);
            scc_num++;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, T, res;

    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        clear_all(N);

        while (M--)
        {
            cin >> A >> B;
            add_path(A, B);
        }

        kosaraju(N);

        fill(in_degree, in_degree + N + 1, 0);
        for (int i = 1; i <= N; i++)
        {
            for (int j : arr[i])
            {
                if (scc_group[i] != scc_group[j])
                    in_degree[scc_group[j]]++;
            }
        }

        res = 0;
        for (int i = 1; i <= scc_num; i++)
        {
            if (!in_degree[i])
                res++;
        }

        cout << res << '\n';
    }

    return 0;
}