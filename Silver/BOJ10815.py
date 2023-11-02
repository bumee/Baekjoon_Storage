ans_num = int(input())

check_list = list(map(int, input().split()))

check_dict = dict()
for elem in check_list:
    check_dict[elem] = 1

q_num = int(input())

check_list2 = list(map(int, input().split()))
ans = []

for elem in check_list2:
    try:
        if check_dict[elem] == 1:
            ans.append(1)
    except KeyError:
        ans.append(0)
        
for elem in ans :
    print(elem, end = " ")