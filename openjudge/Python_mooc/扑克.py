import random
cards = [str(i) for i in range(2, 11)]
cards.extend(list('JQKA'))
allCards = []
for s in '♥♦♣♠':
    for c in cards:
        allCards.append(s+c)
random.shuffle(allCards)
for i in range(4):
    onePlayer = allCards[i::4]
    onePlayer.sort()
    print(onePlayer)