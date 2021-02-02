import sys

input = sys.stdin.readline

n, m = map(int, input().split())
#map??
print (n, m)

nlist = list(map(int,input().split()))
mlist = list(map(int,input().split()))
print (nlist)
print (mlist)

nmlist = nlist + mlist

print (sorted(nmlist))
