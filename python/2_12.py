board1 = [['_'] * 3 for i in range(3)]
board2 = [['_'] * 3] * 3

print(board1)
print(board2)

def Comprehension():
	board1[1][2] = 'X'
def ListofList():
	board2[1][2] = 'X'
Comprehension()
ListofList()

print(board1)
print(board2)
