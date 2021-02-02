lax_coordinates = (33.3333, -118.05555)
city, year, pop, chg, area = ('tokyo', 2003, 32450, 0.66, 8016)

traveler_ids = [('USA', '12345'), ('KOR', '121212'), ('JAP', 'XDA1123')]

for passport in sorted(traveler_ids):
	print('%s/%s' % passport)

for country, _ in traveler_ids:
	print(country)

#2번라인은 튜플 언패킹을 보여준다. 아래는 튜플 언패킹의 다양한 예제를 확인해 볼 수 있다.
a = (1,2)
c,d = a
print(c,d) #1과 2출력

c,d = d,c
print(c,d) #2와 1출력   #C와는 수준이 다른 언어...

print(divmod(20, 8))	#print (20//8, 20%8)  몫과 나머지 #단 작은 수는 후자가 빠르다.

t = (20,8)
print (divmod(*t))		#*을 이용하여 튜플을 언패킹할수 있다. *이 없다면 인자를 t변수 하나로 인식한다.

c,d = divmod(*t)
print(c,d)

import os
_, filename = os.path.split('/usr/bin/id')
print (_, filename)		#국제화된 소프트웨어를 개발할때 dummy용으로 언더바를 많이 사용한다. #파이썬에서 이를 '플레이스홀더' 라고 하는것 같다

a,b,*rest = range(5)
print (a,b,rest)	# 0 1 [2,3,4]
a,b,*rest = range(2)
print (a,b,rest)	# 0 1 []

a,*body,c,d = range(5)
print(a,body,c,d)	# 0 [1,2] 3 4 
*head,a,b,c = range(7)
print(head,a,b,c)	# [0,1,2,3] 4 5 6 


