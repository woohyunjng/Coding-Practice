a = tuple(map(int, input().split()))
b = tuple(map(int, input().split()))
c = tuple(map(int, input().split()))

d = []
if a[0] == b[0]:
    d.append(c[0])
else:
    if a[0] == c[0]:
        d.append(b[0])
    else:
        d.append(a[0])

if a[1] == b[1]:
    d.append(c[1])
else:
    if a[1] == c[1]:
        d.append(b[1])
    else:
        d.append(a[1])

print(*d)
