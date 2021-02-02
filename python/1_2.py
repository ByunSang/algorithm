from math import hypot

class Vector:
	
	def __repr__(self):
		return 'Vector(%r, %r)' % (self.x, self.y)
	def __init__(self, x=0, y=0):
		self.x = x
		self.y = y
	def __abs__(self):
		return hypot(self.x, self.y)
	def __add__(self,other):
		x = self.x + other.x
		y = self.y + other.y
		return Vector(x,y)
	def __bool__(self):
		#return bool(abs(self))
		return bool(self.x or self.y)

v1 = Vector(1,2)
v2 = Vector(3,4)
v3 = v1 + v2

print(bool(v3))
print(v3)
