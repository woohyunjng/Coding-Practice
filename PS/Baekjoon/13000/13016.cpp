#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B, C;
    cin >> N;

    vector<pair<int, int>> arr[N + 1];
    for (int i = 0; i < N - 1; i++)
    {
        cin >> A >> B >> C;
        arr[A].push_back({B, C});
        arr[B].push_back({A, C});
    }

    stack<int> st;
    st.push(1);

    bool checked[N + 1] = {};
    int length[N + 1] = {}, D1[N + 1] = {}, D2[N + 1] = {}, first, second, mx = -1;
    checked[1] = true;

    while (!st.empty())
    {
        int p = st.top();
        st.pop();

        for (pair<int, int> i : arr[p])
        {
            if (checked[i.first])
                continue;
            checked[i.first] = true;
            length[i.first] = length[p] + i.second;
            if (length[i.first] > mx)
            {
                mx = length[i.first];
                first = i.first;
            }
            st.push(i.first);
        }
    }

    st.push(first);
    memset(checked, false, sizeof(checked));
    checked[first] = true;
    mx = -1;

    while (!st.empty())
    {
        int p = st.top();
        st.pop();

        for (pair<int, int> i : arr[p])
        {
            if (checked[i.first])
                continue;
            checked[i.first] = true;
            D1[i.first] = D1[p] + i.second;
            if (D1[i.first] > mx)
            {
                mx = D1[i.first];
                second = i.first;
            }
            st.push(i.first);
        }
    }

    st.push(second);
    memset(checked, false, sizeof(checked));
    checked[second] = true;
    mx = -1;

    while (!st.empty())
    {
        int p = st.top();
        st.pop();

        for (pair<int, int> i : arr[p])
        {
            if (checked[i.first])
                continue;
            checked[i.first] = true;
            D2[i.first] = D2[p] + i.second;
            st.push(i.first);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << max(D1[i], D2[i]) << '\n';
    }
}
