# 445/500

T = int(input())
for t in range(T):
    N = int(input())
    S = input()
    if S.count("1") % 2:
        print("NO")
        continue
    if S.count("1") == 2:
        if "11" in S:
            print("NO")
            continue
    print("YES")
