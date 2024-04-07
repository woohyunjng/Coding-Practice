from sys import stdin


def pow(A, B, MOD):
    res = 1
    while B:
        if B % 2:
            res = res * A % MOD
        B >>= 1
        A = A**2 % MOD
    return res


phi = []
T, M = map(int, stdin.readline().rstrip().split())

while M > 1:
    phi.append(M)
    val = M
    for i in range(2, int(M**0.5) + 1):
        if M % i:
            continue

        val -= val // i
        while not M % i:
            M //= i

    if M > 1:
        val -= val // M
    M = val
print(phi)
for t in range(T):
    arr = list(map(int, stdin.readline().rstrip().split()))
    N, arr = arr[0], arr[1:]
    res = 1

    for i in range(N - 1, 0):
        if i >= len(phi):
            res = 1
            continue
        res = pow(arr[i], res, phi[i]) + phi[i]

    print(pow(arr[0], res, phi[0]))
