import collections
from random import choice

Card = collections.namedtuple('Card', ['rank', 'suit'])

class FrenchDeck:
	ranks = [str(n) for n in range(2, 11)] + list('JQKA')
	suits = 'spades diamonds clubs hearts'.split()
	def __init__(self):
		self._cards = [Card(rank, suit) for suit in self.suits for rank in self.ranks]
	def __len__(self):
		return len(self._cards)

	def __getitem__(self, position):
		return self._cards[position]
#beer_card = Card('7', 'diamonds')
#print(beer_card)
	
deck = FrenchDeck()

print(deck[12::14])	#slicing
#print(len(deck))
#print(deck.ranks)
#print(deck.suits)
#print(choice(deck))

#for card in reversed(deck): #doctest: +ELIPSIS
#	print(card)


values = dict(spades=3, hearts=2,diamonds=1, clubs=0)
#print (values['spades'])
#def spades_high(card):
#	rank_value = FrenchDeck.ranks.index(card.rank)
#	return rank_value * len(values) + values[card.suit]
#for card in sorted(deck, key=spades_high):
#	print(card)
