T_1, E_1, F_1 = map(int, input().split())
res_1 = T_1 * 3 + E_1 * 20 + F_1 * 120

T_2, E_2, F_2 = map(int, input().split())
res_2 = T_2 * 3 + E_2 * 20 + F_2 * 120

if res_1 > res_2:
    print("Max")
elif res_1 < res_2:
    print("Mel")
else:
    print("Draw")
