import array

colors = ['black', 'white']
sizes  = ['S', 'M','L']


def _tuple():
	for c in colors:
		for s in sizes:
			print((c,s))


def _generate(): #within iterator protocol
	for tshirts in ('%s %s' % (c,s) for c in colors for s in sizes):
		print(tshirts)
	
	symbols = '$%^&*'
	print (tuple(ord(symbol) for symbol in symbols))#tuple init
	_array = array.array('I', (ord(symbol) for symbol in symbols))#array init #unsigned int
	#_array = array.array('i', (ord(symbol) for symbol in symbols))#int
	print(_array)

_tuple()
_generate()

	#generate는 tshirts6개의 항목을 메모리에 저장하지 않는다.한번에 한 항목을 생성할 수 있도록 for 루프에 데이터를 바로 전달하기 때문이다.
	#symbols 예제는tuple과 array에 각각 할당하는법을 제공한다. 이때 마찬가지로 symbols를 메모리에 적재하지 않는다.

