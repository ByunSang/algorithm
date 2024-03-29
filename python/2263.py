import sys
sys.setrecursionlimit(10**6) # 재귀함수 제한 늘리기.

inorder = []
postorder = []
position = {}
def solve (in_start, in_end, post_start, post_end):
	if in_start > in_end or post_start> post_end:
		return
	root = postorder[post_end]
	print(root, end= ' ')
	p = position[root]

	left = p - in_start

	solve(in_start, p-1, post_start, post_start + left -1)
	solve(p+1, in_end, post_start+left, post_end-1)

n = int(input())
inorder = list(map(int,input().split()))
postorder = list(map(int, input().split()))

for i in range(n):
	position[inorder[i]] = i

solve(0, n-1, 0, n-1)

