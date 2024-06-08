#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

vector<int> arr[200010], rvt_arr[200010], scc[200010], new_arr[200010];
stack<int> st;
bool checked[200010];
int scc_num = 0, scc_id[200010], in_degree[200010];

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
    scc_id[K] = scc_num;
}

void kosaraju(int V)
{
    int A;
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

int comb(int N) { return N * (N - 1) / 2; }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, res = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        arr[i].push_back(A);
        rvt_arr[A].push_back(i);
    }

    kosaraju(N);

    res = N;
    for (int i = 1; i <= N; i++)
    {
        for (int j : rvt_arr[i])
        {
            if (scc_id[i] != scc_id[j])
                new_arr[scc_id[i]].push_back(scc_id[j]);
        }
    }

    queue<pr> q;
    for (int i = 0; i < scc_num; i++)
    {
        sort(new_arr[i].begin(), new_arr[i].end());
        new_arr[i].erase(unique(new_arr[i].begin(), new_arr[i].end()), new_arr[i].end());
        for (int j : new_arr[i])
            in_degree[j]++;
    }

    for (int i = 0; i < scc_num; i++)
    {
        if (!in_degree[i])
        {
            res += comb(scc[i].size()) * 2;
            q.push({i, scc[i].size()});
        }
    }

    while (!q.empty())
    {
        pr A = q.front();
        q.pop();

        for (int j : new_arr[A.first])
        {
            res += A.second;
            q.push({j, A.second + 1});
        }
    }

    cout << res;

    return 0;
}