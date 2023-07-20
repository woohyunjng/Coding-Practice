T = int(input())
P = [0, 1, 1, 1, 2, 2, 3, 4]

for i in range(T):
    N = int(input())

    for i in range(len(P), N + 1):
        P.append(P[-1] + P[-5])

    print(P[N])
