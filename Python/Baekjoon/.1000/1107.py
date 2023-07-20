N = int(input())
M = int(input())
K = [True for i in range(10)]

if M > 0:
    btn = map(int, input().split())
else:
    btn = []

for i in btn:
    K[i] = False

res = abs(N - 100)
for i in range(N, -1, -1):
    if len(str(i)) + N - i >= res:
        break

    check = False
    for j in str(i):
        if not K[int(j)]:
            check = True
            break
    if check:
        continue

    res = len(str(i)) + N - i
    break

if M != 10:
    i = N
    while True:
        i += 1
        if len(str(i)) + i - N >= res:
            break

        check = False
        for j in str(i):
            if not K[int(j)]:
                check = True
                break
        if check:
            continue

        res = len(str(i)) + i - N
        break

print(res)   
