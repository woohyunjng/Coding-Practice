#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[100];

char unused(char A, char B)
{
    if (A == 'A')
        return B == 'B' ? 'C' : 'B';
    else if (A == 'B')
        return B == 'A' ? 'C' : 'A';
    else
        return B == 'A' ? 'B' : 'A';
}

void hanoi(int N, char start, char end)
{
    if (N == 1)
        cout << "move disk 1 " << start << "->" << end << '\n';
    else
    {
        hanoi(N - 1, start, unused(start, end));
        cout << "move disk " << N << " " << start << "->" << end << '\n';
        hanoi(N - 1, unused(start, end), end);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";
    hanoi(N, 'A', 'C');

    return 0;
}