from sys import stdin

T = int(stdin.readline())
for t in range(T):
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().rstrip().split()))

    res = [0]
    for i in arr:
        if i > 0:
            if res[-1] <= 0 and res[-1] + i > 0:
                res[-1] += i
            else:
                res.append(i)
        elif i < 0:
            if res[-1] > 0 and res[-1] + i <= 0:
                res.append(i)
            else:
                res[-1] += i

    val = 0
    for i in res:
        if i > 0:
            val += 1
        elif i < 0:
            val -= 1

    if val > 0:
        print("YES")
    else:
        print("NO")
