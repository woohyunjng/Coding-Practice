def euler_phi(N):
    res = N
    for i in range(2, round(N**0.5) + 1):
        if N % i:
            continue

        while not N % i:
            N //= i
        res //= i
        res *= i - 1

    if N != 1:
        res //= N
        res *= N - 1
    return res


N = int(input())
arr = []

for i in range(1, int(N**0.5) + 1):
    if not N % i:
        arr.append(i)
        arr.append(N // i)

res = -1
arr = list(sorted(arr))

for i in arr:
    if i * euler_phi(i) == N:
        res = i
        break

print(res)
