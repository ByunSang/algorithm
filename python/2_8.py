metro = [
	('asdf', (2,5)),
	('fdas', (5,7)),
	('kkkk', (2,5)),
]

for name, (No1,No2) in metro:
	print(name, No1,No2)

#No1 과 No2는 (2,5) (5,7) (2,5)를 각각 언패킹한다.
#때로는 필드에 이름을 붙여줄 필요가 있다.이는 2_9.py예에 나와있다.
