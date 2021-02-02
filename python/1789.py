N = int(input())

arr = [list(map(int,input().split())) for _ in range(N)]
cnt = [0]*3
#for i in range(N):
#	for j in range(N):
#		print(arr[i][j], end=' ')
#	print()

def same(x,y,N):
	for i in range(x, x+N):
		for j in range(y, y+N):
			if arr[x][y] != arr[i][j]:
				return False
	return True

def solve(x, y, N):
	if (same(x,y,N)):
		cnt[arr[x][y] + 1] += 1
		return
	m = N//3
	for i in range(3):
		for j in range(3):
			solve(x+i*m, y+j*m, m)


solve(0,0,N)
for i in cnt:
	print(i)
