test_case = int(input())

ans = []
for _ in range(test_case):
    x, y = map(int, input().split())
    ans.append((x,y))

ans = sorted(ans, key = lambda item: (item[0], item[1]))
for elem in ans:
    print(str(elem[0])+" "+str(elem[1]))