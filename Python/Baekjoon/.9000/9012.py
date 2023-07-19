N = int(input())

for i in range(N):
    S = input()
    num, f = 0, True

    for j in S:
        if j == "(":
            num += 1
        else:
            num -= 1
            if num < 0:
                f = False
                break
    
    if num:
        f = False

    print("YES" if f else "NO")
