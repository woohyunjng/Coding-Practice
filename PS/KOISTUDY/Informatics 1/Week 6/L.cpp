#include <iostream>
using namespace std;

int main()
{
    char N;
    cin >> N;

    for (int i = 97; i <= (int)N; i++)
        cout << (char)i << ' ';
}