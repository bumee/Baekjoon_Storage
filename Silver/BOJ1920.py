ans_num = int(input())

check_list = list(map(int, input().split()))

check_dict = dict()
for elem in check_list:
    check_dict[elem] = 1

q_num = int(input())

check_list2 = list(map(int, input().split()))

for elem in check_list2:
    try:
        if check_dict[elem] == 1:
            print(1)
    except KeyError:
        print(0)