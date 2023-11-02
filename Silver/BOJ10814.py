test_case = int(input())

info_list = dict()

for _ in range(test_case):
    age, name = map(str,input().split())
    try:
        info_list[int(age)].append(name)
    except KeyError:
        info_list[int(age)] = []
        info_list[int(age)].append(name)

keys = sorted(info_list.keys())
for key in keys:
    v = info_list[key]
    for elem in v:
        print(str(key)+" "+elem)