N = int(input())
arr = list(map(int, input().split()))

checked = [False for i in range(N + 1)]
sticker, mx = 0, 0

for i in arr:
    if checked[i]:
        sticker -= 1
        checked[i] = False
    else:
        sticker += 1
        checked[i] = True

    mx = max(mx, sticker)

print(mx)
