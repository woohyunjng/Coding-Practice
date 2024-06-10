#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

bool is_prime(int N)
{
    bool res = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (!(N % i))
        {
            res = false;
            break;
        }
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N;

    vector<int> res;
    int p[4] = {2, 3, 5, 7};

    for (int i : p)
    {
        queue<pr> st;
        st.push({i, 1});

        while (!st.empty())
        {
            pr A = st.front();
            st.pop();

            if (A.second == N)
            {
                res.push_back(A.first);
                continue;
            }

            for (int j = 1; j <= 10; j += 2)
            {
                K = 10 * A.first + j;
                if (is_prime(K))
                    st.push({K, A.second + 1});
            }
        }
    }

    sort(res.begin(), res.end());
    for (int i : res)
        cout << i << '\n';

    return 0;
}