N = int(input())
sq = int(N**0.5)

if sq**2 == N:
    print(-1)
    exit()

res = 0
for i in range(1, sq + 1):
    if 2 * i**2 > N:
        break

    j = N - i**2
    if int(j**0.5) ** 2 == j:
        res += 1

if N % 2:
    for i in range(1, sq + 1):
        if i**2 > N:
            break

        if not N % i:
            res += 1

elif not N % 4:
    N //= 4
    for i in range(1, sq + 1):
        if i**2 > N:
            break

        if not N % i:
            res += 1

print(res)
