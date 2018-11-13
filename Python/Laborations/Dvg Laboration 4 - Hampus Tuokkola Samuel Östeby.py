# Laboration 4 - Datavetenskapens Grunder
# Av Hampus Tuokkola och Samuel Östeby

print("Laboration 4 - Datavetenskapens Grunder")
print("Av Hampus Tuokkola och Samuel Östeby")

# Uppgift 1
from logic import *
print("Satslogik", "\n")

# 1a
# f är rainy eller windy
f1 = rainy | windy
i1 = [rainy]
print("Uppgift 1a:", val(f1, i1))

# 1b
# Om f är rainy, är f nu istället windy
f2 = rainy > windy
i2 = [windy]
print("Uppgift 1b:", val(f2, i2))

# 1c
# om f är rainy är f nu wet, OCH om f är inte rainy är f nu inte wet
f3 = (rainy > wet) & (~rainy > ~wet)
i3 = []
print("Uppgift 1c:", val(f3, i3))

# 1d
# om (f eller windy) OCH rainy medför wet OCH windy medför cold
f4 = (rainy | windy) & (rainy > wet) & (windy > cold)
i4 = [rainy, wet]
print("Uppgift 1d:", val(f4,i4))

# 1e
#
f5 = ((rainy & windy) == snow) & winter & (~snow | ~winter)
i5 = [winter]
print("Uppgift 1e:", val(f5, i5))

# 1f
#
f6 = (rainy == windy) & (winter | summer) & (spring | summer) & (~winter > ~windy)
i6 = [summer]
print("Uppgift 1f:", val(f6, i6))

# ig
#
f7 = (wet > sunny) & (summer | spring) & (snow == winter)
i7 = [summer]
print("Uppgift 1g:", val(f7, i7))

print("")

# Uppgift 2

# 2a
f8 = ((spring & ~(summer | autumn | winter)) | (summer & ~(spring | autumn | winter)) | (autumn & ~(spring | summer | winter)) |(winter & ~(spring | summer | autumn)))
i8 = [spring]
print("Uppgift 2a:")
print("Om spring:", val(f8, i8))
i8 = [autumn]
print("Om autumn:", val(f8, i8))
i8 = [summer, winter]
print("Om summer & winter:", val(f8, i8))
i8 = []
print("Om ingen årstid:", val(f8, i8))
print("")

# 2b
print("Uppgift 2b:")
f9 = (winter > snow) & ((rainy | snow) & ~(snow & rainy))
i9 = [snow, winter]
print("Om snow & winter:", val(f9, i9))
i9 = [rainy, snow]
print("Om rainy & snow:", val(f9, i9))
print("")

# 2c
f10 = (snow > cold) & ( rainy > ~cold)
i10 = [snow, cold]
print("Uppgift 2c:")
print("Om snow & cold:", val(f10, i10))
i10 = [rainy, cold]
print("Om rainy & cold:", val(f10, i10))
print("")

print("Predikatlogik", "\n")

# Uppgift 3

print("Uppgift 3","\n")

# 3a
f1 = forall(x, hungry(x) > ~happy(x))
i1 = [x, hungry(x), sad(x)]
print("Uppgift 3a:", val(f1, i1))

# 3b
f2 = exists(x, hungry(x) & ~happy(x))
i2 = [hungry(x)]
i21 = [x]
print("Uppgift 3b:",val(f2,i2,i21 ))


# 3c
f3 = ~hungry(fido) & forall(x,~hungry(x) > happy(x))
i3 = [happy(x),x, fido]
print("Uppgift 3c:", val(f3,i3))

# 3d
f4 = hungry(fido) & happy(cleo) & forall(x,~hungry(x) > happy(x))
i4 = [hungry(fido), happy(cleo), happy(x), fido, cleo, x]
print("Uppgift 3d:", val(f4,i4))

# 3e
f5 = exists(x, hungry(x) & ~happy(x) & ~(x == fido))
i5 = [hungry(x), happy(fido)]
i51 = [x, fido]
print("Uppgift 3e:", val(f5,i5,i51))

# 3f
f6 = exists(x, loves(x,john) & loves(john,x))
i6 = [loves(x,john), loves(john,x)]
i61 = [x, john]
print("Uppgift 3f:", val(f6,i6,i61))

# 3g
f7 = exists(x, loves(x,john)) & forall(x,forall(y, (loves(x,y) & loves(y,x)) > (happy(x) & happy(y))))
i7 = [loves(x,john),loves(x,y), happy(x), happy(y)]
i71 =  [x, john, y]
print("Uppgift 3g:", val(f7,i7,i71))

# 3h
f8 = loves(john, mary) & hates(mary,john) & forall(x, exists(y,(loves(x,y) & hates(y,x))) > ~happy(x))
i8 = [loves(john, mary), hates(mary,john)]
i81 = [john, mary, x, y]
print("Uppgift 3h:", val(f8,i8,i81))

# 3i
f9 =  human(john) & human(bob) & forall(x,human(x) > exists(y, (dog(y) | cat(y)) & owns(x,y)))
i9 = [human(john), human(bob), cat(y), dog(y), owns(john,y), owns(bob,y)]
i91 = [john, bob, x, y]
print("Uppgift 3i:", val(f9,i9,i91))

# 3j
f10 =  exists(x,dog(x)) & exists(y,cat(y)) & exists(z,female(z)) & exists(u,male(u)) & forall(x,male(x) | female(x))
i10 = [dog(x), cat(y), female(z), male(u), male(x), male(y)]
i101 = [x, y, z, u]
print("Uppgift 3j:", val(f10,i10,i101),"\n")

# Uppgift 4
print("Uppgift 4","\n")
# 4a
f1 =  exists(x, dog(x) & hungry(x))
i1 = [cat(x), hungry(x)]
i11 = [x]
f11 = exists(x, dog(x) > hungry(x))
print("Uppgift 4a:", "med & for några:", val(f1,i1,i11), ", > för några:", val(f11,i1,i11), "\n")
print("Orsaken till att man skriver & istället för > är att i en implikation kan man få True så länge q = 1 oavsett vad p är.")
print("Med & måste både p och q vara lika med 1.")
print("Med > räcker det alltså att x är hungrig. Att vara en hund implikerar (>) endast att x är hungrig, men inget mer.")
print("Med & måste x BÅDE vara några hund OCH (&) att dessa hundar är hungriga för att meningen ska vara sann.","\n")

# 4b
f2 = forall(x, dog(x) > hungry(x))
i2 = [hungry(x)]
i21 = [x]
f21 = forall(x, dog(x) & hungry(x))
print("Uppgift 4b:", "Med > för alla:", val(f2,i2,i21), ", & för alla,", val(f21,i2,i21), "\n")
print("Orsaken till att man skriver > istället för & när man talar om alla hundar är för att man vill berätta att alla hundar")
print("är hungriga, men inte att alla x är hundar. x skulle kunna vara alla djur, men att de djur som är hundar är hungriga.")
print("Då skulle inte & funka eftersom detta skulle implikera att alla djuren var hundar och hungriga, vilket inte är sant.")
print("Endast de djur som är hundar är hungriga.")
