N = int(input())
XA, YA = map(int, input().split())
XB, YB = map(int, input().split())

res = ((N + 1) * N // 2) ** 2
if XA == XB:
    YA, YB = max(min(max(YA, YB), N), -1), min(max(min(YA, YB), -1), N)
    Y = YA - YB
    res += (Y - 1) * Y // 2 * (N + 1)
elif YA == YB:
    XA, XB = max(min(max(XA, XB), N), -1), min(max(min(XA, XB), -1), N)
    X = XA - XB
    res += (X - 1) * X // 2 * (N + 1)

print(res)
