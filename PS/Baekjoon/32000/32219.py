T = int(input())
for t in range(T):
    R, C = map(int, input().split())
    if R == C:
        print("dohoon")
        continue

    print("jinseo")
    if R > C:
        print(C, C)
    else:
        print(R, R)
