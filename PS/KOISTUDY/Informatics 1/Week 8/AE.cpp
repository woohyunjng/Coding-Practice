#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

vector<int> arr(20), sec(20);
int fuck[3] = {0, 2, 3};

int minimum()
{
    int res = 0;
    for (int i = 0; i < 18; i++)
    {
        if (sec[i])
        {
            for (int j = 0; j < 3; j++)
                sec[i + j] = !sec[i + j];
            res++;
        }
    }

    bool check = true;
    for (int i = 18; i < 20; i++)
        check = check && !sec[i];
    return check ? res : 100;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int res = 100;
    for (int i = 0; i < 20; i++)
        cin >> arr[i];

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            int val = 0;
            for (int k = 0; k < 20; k++)
                sec[k] = arr[k];

            for (int k = 0; k < fuck[i]; k++)
                sec[k] = !sec[k];
            for (int k = 0; k < fuck[j]; k++)
                sec[19 - k] = !sec[19 - k];

            val = minimum();
            if (i)
                val++;
            if (j)
                val++;
            res = min(res, val);
        }
    }

    cout << res;
}