from re import fullmatch

T = int(input())
for i in range(T):
    S = input()
    res = fullmatch(r"(100+1+|01)+", S)
    print("YES" if res else "NO")
