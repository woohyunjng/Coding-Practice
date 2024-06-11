#include <bits/stdc++.h>
#define int long long
#define MAX 10010

using namespace std;

vector<int> arr[MAX], rvt_arr[MAX], scc[MAX];
stack<int> st;
bool checked[MAX];
int scc_num = 0, scc_id[MAX];

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