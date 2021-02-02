l = [10, 20, 30, 40, 50]
s = 'bicycle'

print(l[:3])
print(l[3:])

print(s[::3]) #jump by 3
print(s[::-1])
print(s[::-2])


l = list(range(10))
print (l)

l[2:5] = [20,30]
print(l)

del l[2:5]
print(l)

l[3::2] = [11, 22]
print(l)

l[2:7] = [100]
print(l)
