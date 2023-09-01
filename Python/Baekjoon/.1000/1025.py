N, M = map(int, input().split())

arr = []
for i in range(N):
    arr.append(list(map(int, input())))

mx = -1
for a in range(N):
    for b in range(-N + 1, N):
        for i in range(M):
            for j in range(-M + 1, M):
                for k in range(1, max(M, N) + 1):
                    num = 0
                    x, y = a, i

                    for z in range(k):
                        if 0 <= x < N and 0 <= y < M:
                            num = num * 10 + arr[x][y]
                        x += b
                        y += j

                    if int(num**0.5) ** 2 == num:
                        mx = max(mx, num)

print(mx)
