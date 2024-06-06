arr = []
for i in range(10):
    arr.append(list(map(int, input().split())))

Y, X = 1, 1
while True:
    arr[Y][X] = 9
    if not arr[Y][X + 1]:
        X += 1
    elif not arr[Y + 1][X]:
        Y += 1
    else:
        if arr[Y][X + 1] == 2:
            arr[Y][X + 1] = 9
        elif arr[Y + 1][X] == 2:
            arr[Y + 1][X] = 9
        break

print("\n".join(map(lambda x: " ".join(map(str, x)), arr)))
