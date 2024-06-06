while True:
    S = input()
    if S == "0":
        break
    if S == str("".join(reversed(S))):
        print("yes")
    else:
        print("no")
