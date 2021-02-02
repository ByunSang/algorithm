from array import array
from random import random
import time

start = time.time()
floats = array('d', (random() for i in range(10**7)))
end = time.time()
print("assinged time :" , end-start)
print(floats[-1])

#sorted_floats = array(floats.typecode, sorted(floats))

fp = open("floats.bin", 'wb')

fp_start = time.time()
sorted_floats.tofile(fp)
print("write time :", time.time()-fp_start)
fp.close()

floats2 = array('d')

fp = open("floats.bin", 'rb')
floats2.fromfile(fp, 10**7)
print(floats2[-1])
fp.close()


