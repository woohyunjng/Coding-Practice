#include <bits/stdc++.h>
#define MAX 110
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int A[MAX], B[MAX];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, sm;
    bool check;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];
    cin >> M;

    for (int i = 1; i <= 1000000; i++)
    {
        check = true;
        sm = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i % A[j] != B[j] % A[j])
            {
                check = false;
                break;
            }
            sm += (i - B[j]) / A[j];
        }
        if (!check)
            continue;

        if (sm > M)
            break;
        else if (sm < M)
            continue;

        cout << i;
        return 0;
    }

    cout << 0;

    return 0;
}