#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

vector<int> arr[200100], rvt_arr[200100], scc[200100];
stack<int> st;
bool checked[200100];
int scc_num = 0;

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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B;

    cin >> N >> M;
    while (M--)
    {
        cin >> A >> B;
        arr[A].push_back(B);
        rvt_arr[B].push_back(A);
    }

    kosaraju(N);
    if (scc_num == 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}