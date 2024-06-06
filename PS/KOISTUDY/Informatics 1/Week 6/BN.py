N = int(input())
arr = list(map(int, input().split()))

a, b = 0, 0
for i in arr:
    if i == 25:
        a += 1
    elif i == 50:
        if not a:
            break
        a -= 1
        b += 1
    else:
        if not b:
            if a < 3:
                break
            a -= 3
        else:
            if not a:
                break
            a -= 1
            b -= 1
else:
    print("YES")
    exit()
print("NO")
