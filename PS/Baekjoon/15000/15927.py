S = input()

if S != "".join(reversed(S)):
    print(len(S))
else:
    if len(set(S)) == 1:
        print(-1)
    else:
        print(len(S) - 1)
