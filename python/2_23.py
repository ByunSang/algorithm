from collections import deque

dq = deque(range(11), maxlen=10)

print(dq[0])

dq.rotate(1) # >>1

print(dq)  

dq.rotate(-1) # <<1

print(dq)

dq.appendleft(-1) # dq[0] = -1 && >> 1  maxlen = 10

print(dq)

dq.extend([11,12,13])  # dq[7] = 11 dq[8]= 12 dq[9] = 13  << 3 maxlen = 10

print(dq)

dq.extendleft([3, 2, 1, 0])

print(dq)
