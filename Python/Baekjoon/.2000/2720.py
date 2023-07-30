T = int(input())
for i in range(T):
    N = int(input())

    a = N // 25
    N %= 25

    b = N // 10
    N %= 10

    c = N // 5
    N %= 5

    d = N

    print(a, b, c, d)
