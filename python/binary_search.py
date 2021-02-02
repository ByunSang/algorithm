import bisect

list = [0,1,2,3,4,5,6,7]
print(bisect.bisect(list, 7)) 
# 몇번째 인덱스에 존재하느냐 
# 없다면 list의 length 값 출력 이게 맞아?  
print (len(list))

def binary_search(list, x, lo = 0, hi=len(list)):
	if lo < 0:
		return ValueError('lo must be non-negative')
	while lo < hi:
		mid = (lo+hi) // 2 # / is float // is prime
		#print (mid)
		if list[mid] < x:
			lo = mid + 1
		else :
			hi = mid
	return lo + 1

print(binary_search(list, 7))
