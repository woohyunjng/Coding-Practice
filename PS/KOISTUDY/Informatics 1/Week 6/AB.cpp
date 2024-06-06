#include <iostream>
using namespace std;

int main()
{
    int A, B, C, i = 1;
    cin >> A >> B >> C;
    for (; i <= A * B * C; i++)
    {
        if (i % A == 0 && i % B == 0 && i % C == 0)
            break;
    }
    cout << i;
}