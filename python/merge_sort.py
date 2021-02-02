
def merge(left, right):
	i = 0
	j = 0
	sorted_list = []
	while ((i < len(left)) & (j < len(right))):
		if left[i] < right[j]:
			sorted_list.append(left[i])
			i += 1
		else:
			sorted_list.append(right[j])
			j += 1
	while (i < len(left)):
		sorted_list.append(left[i])
		i += 1
	while (j < len(right)):
		sorted_list.append(left[j])
		j += 1	
	return sorted_list

def merge_sort(list):
	if (len(list) > 1):
		mid = len(list)//2
		left = list[:mid]
		right = list[mid:]

		l = merge_sort(left)
		r = merge_sort(right)

		return merge(l, r)

	else:
		return list

list = [int(x) for x in input().split()]
#for x in input().split()
	#list.append(int(x))
print(list)

print(merge_sort(list))
