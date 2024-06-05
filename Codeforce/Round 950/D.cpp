#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int arr[200100], gcd_arr[200100];

int gcd(int A, int B) { return A ? gcd(B % A, A) : B; }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, A, B, count;
    bool res, before;
    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        for (int i = 1; i < N; i++)
            gcd_arr[i] = gcd(arr[i], arr[i + 1]);

        vector<int> bad_case;
        count = 0;
        res = true;

        for (int i = 2; i < N; i++)
        {
            if (gcd_arr[i] < gcd_arr[i - 1])
            {
                count++;
                if (count > 2)
                {
                    res = false;
                    break;
                }

                if (count == 1)
                {
                    bad_case.push_back(i - 1);
                    before = true;
                }
                else
                {
                    if (!before)
                    {
                        res = false;
                        break;
                    }
                    bad_case.push_back(i - 1);
                }
            }
            else
                before = false;
        }

        if (res)
        {
            if (count == 2)
            {
                B = bad_case[1];
                cout << "a" << B << ' ';
                if (B == 2)
                {
                    A = gcd(arr[B - 1], arr[B + 1]);
                    if (A <= gcd_arr[B + 1])
                        res = true;
                    else
                        res = false;
                }
                else if (B == N - 1)
                {
                    A = gcd(arr[B - 1], arr[B + 1]);
                    if (gcd_arr[B - 2] <= A)
                    {
                        res = true;
                        break;
                    }
                    else
                        res = false;
                }
                else if (B != 1)
                {
                    A = gcd(arr[B - 1], arr[B + 1]);
                    if (gcd_arr[B - 2] <= A && A <= gcd_arr[B + 1])
                        res = true;
                    else
                        res = false;
                }
            }
            else if (count == 1)
            {
                for (int i = bad_case[0]; i < bad_case[0] + 2; i++)
                {
                    cout << "a" << i << ' ';
                    if (i == 2)
                    {
                        A = gcd(arr[i - 1], arr[i + 1]);
                        if (A <= gcd_arr[i + 1])
                        {
                            res = true;
                            break;
                        }
                        else
                            res = false;
                    }
                    else if (i == N - 1)
                    {
                        A = gcd(arr[i - 1], arr[i + 1]);
                        if (gcd_arr[i - 2] <= A)
                        {
                            res = true;
                            break;
                        }
                        else
                            res = false;
                    }
                    else if (i != 1)
                    {
                        A = gcd(arr[i - 1], arr[i + 1]);
                        if (gcd_arr[i - 2] <= A && A <= gcd_arr[i + 1])
                        {
                            res = true;
                            break;
                        }
                        else
                            res = false;
                    }
                }
            }
        }

        for (int i = 1; i < N; i++)
            cout << gcd_arr[i] << ' ';

        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}