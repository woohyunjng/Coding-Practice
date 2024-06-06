N, K, X = map(int, input().split())

if X == 1:
    print(N - 3 * K + 3)
elif 2 <= X <= 4:
    print(N - 3 * K + 2)
else:
    print(N - 3 * K + 1)
