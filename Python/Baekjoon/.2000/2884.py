H, M = map(int, input().split())

if M >= 45:
    print(H, M - 45)
if M < 45:
    if H > 0:
        print(H - 1, M + 15)
    else:
        print(23, M + 15)
