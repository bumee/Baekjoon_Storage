import sys
nums = int(sys.stdin.readline())
elem = []
for _ in range(0,nums):
    elem.append(input())
not_elem = list(set(elem))
not_elem_dict = dict()
for element in not_elem:
    not_elem_dict[element] = len(element)
not_elem_dict = sorted(not_elem_dict.items(), key = lambda item: (item[1], item[0]))
for element in not_elem_dict:
    print(element[0])