N, X = map(int, input().split())

cur, val = N - 1, X - N
arr = ["A" for i in range(N)]
if val < 0:
    print("!")
    exit()

while val > 0:
    if cur < 0:
        print("!")
        exit()

    if val >= 25:
        val -= 25
        arr[cur] = "Z"
        cur -= 1
    else:
        arr[cur] = chr(val + 65)
        val = 0

print("".join(arr))
