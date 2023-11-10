#include <iostream>
using namespace std;

int main()
{
    int R, G, B;
    cin >> R >> G >> B;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < G; j++)
        {
            for (int k = 0; k < B; k++)
                cout << i << ' ' << j << ' ' << k << '\n';
        }
    }
    cout << R * G * B;
}