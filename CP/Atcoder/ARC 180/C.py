N = int(input())
A = [0] + list(map(int, input().split()))

MOD = 10**9 + 7
DEF = 1000
res = 1

sm = [0 for i in range(2001)]
zeroes = [0 for i in range(110)]
zeroes[0] = 1
sm[A[0] + DEF] = 1

for i in range(1, N + 1):
    do = []
    for j in range(2001):
        if j == DEF:
            if not A[i]:
                continue

            val = 0
            for k in range(i - 1, -1, -1):
                val = (val + zeroes[k]) % MOD
                if A[k] == A[i]:
                    break
            do.append((j, val))
            continue

        if not sm[j]:
            continue

        do.append((j, sm[j]))
        res = (res + sm[j]) % MOD

    for j, k in do:
        if j + A[i] == DEF:
            zeroes[i] = (zeroes[i] + k) % MOD
        else:
            sm[j + A[i]] = (sm[j + A[i]] + k) % MOD

print(res)
