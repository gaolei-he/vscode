from fractions import Fraction
from decimal import Decimal, getcontext
from math import atan
from mpmath import mp

getcontext().prec = 100

frac = Fraction(3, 3)

mp.dps = 100
dec = mp.atan(1) * 4
print(dec)
