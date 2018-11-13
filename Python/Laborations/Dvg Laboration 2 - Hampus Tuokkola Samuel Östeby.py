 # Av Hampus Tuokkola och Samuel Östeby

print("\n")

print("Laboration 2 - Datavetenskapens Grunder")
print("Av Hampus Tuokkola och Samuel Östeby")

print("\n")

# mängder
A = {1,2,3,4}
B = {3,4,5}
C = {5}
U = {0,1,2,3,4,5,6,7,8,9}
Tom = set()

# uppgift 1

def uppgift_1(): # definerar uppgifter i funktioner för att kunna göra val utan att det blir för mycket samma kod.
    #1a
    print("Uppgift 1", "\n")
    if 1 in A:
        print("1a", 1 in A)
    else:
        print("1a, False")

    #1b
    if 5 in A:
        print("1b", 5 in A)
    else:
        print("1b False")

    #1c
    if 1 in Tom:
        print("1c", 1 in Tom)
    else:
        print("1c False")

    #1d
    if 1 in U:
        print("1d", 1 in U)
    else:
        print("1d False")

    #1e
    if A.issubset(B):
        print("1e True")
    else:
        print("1e False")

    #1f
    if C.issubset(B):
        print("1f True")
    else:
        print("1f False")

    #1g
    if A in Tom:
        print("1g", A in Tom)
    else :
        print("1g False")

    #1h
    if A.issubset(U):
        print("1h True")
    else:
        print("1h False")

    #1i
    AC = A.intersection(C) # AC = Skärningen av A och C
    if AC.issubset(B):
        print("1i True då skärningen utav AC är en tom mängd då AC:s kardinalitet är", len(AC))
    else:
        print("1i False")

    #1j
    AC = A.union(C) # AC = Unionen av A och C
    if AC.issubset(B):
        print("1j True")
    else:
        print("1j False")

    #1k
    AB = A.difference(B) #AB = Differensen mellan A och B
    if AB == C:
        print("1k True")
    else :
        print("1k False")

    #1l
    BC = B.difference(C) #BC = Differensen mellan B och C
    if BC.issubset(A):
        print("1l True då ",BC, "är en delmängd utav",A)
    else:
        print("1l False")

    #1m
    BC = B.difference(C) #BC = Differensen mellan B och C
    if BC == A:
        print("1m True")
    else :
        print("1m False")

    #1n
    if len(U) == 5:
        print("1n True")
    else:
        print("1n False då kardinaliteten av U är", len(U))

    #1o
    if ((len(A) + len(B)) == 5):
        print("1o True då kardinaliteten av A och B är", (len(A) + len(B)), "är lika med 5")
    else:
        print("1o False då kardinaliteten av A och B är", (len(A) + len(B)))
        
    print("\n")
    


# uppgift 2
def uppgift_2():
    print("Uppgift 2")
    Testset = set([frozenset([2,1]),frozenset([2,1,3,4])]) # Testset håller test-mängden

    #2a
    if A in Testset:
        print("2a True") # Om A tillhör testmängden
    else:
        print("2a False") # Om A inte tillhör testmängden

    #2b
    if A.issubset(Testset): # Testset håller test-mängden
        print("2b True") # Om A är en delmängd av test-mängden
    else:
        print("2b False") # Om A inte är en delmängd av test-mängden

    #2c
    if C.issubset(Testset): # Testset håller test-mängden
        print("2c True") # Om C är en delmängd av test-mängden
    else:
        print("2c False") # Om C inte är en delmängd av test-mängden

    print("\n")
    

# uppgift 3

# Skapa en funktion för komplement # denna säts utanför funktionen så att den stannar kvar om vi behöver referera till denna funktion i senare uppgifter.
def comp(setinput):
    komplement = U.difference(setinput) #Differensen mellan U och input blir komplementet
    return komplement
def uppgift_3():
    print ("Uppgift 3")
    #3a
    print("3a Komplementet till A är", comp(A)) # Komplementet till A

    #3b
    answer = comp(U)
    if answer == set():
        print("3b Komplementet till U är en tom mängd")
    else:
        print("3b Komplementet till U är", answer)

    #3c
    Cc = comp(C)
    if A.issubset(Cc):
        print("3c True då", A, "är en delmängd av", Cc)
    else:
        print("3c False")

    #3d
    Ac = comp(A)
    Acc = comp(Ac)
    if Acc == A:
        print("3d True")
    else:
        print("3d False")

    print("\n")
    

# uppgift 4
def setprod(m1,m2): # Skapar produktmängden av av två mängder m1 och m2
        p = set()
        for e1 in m1:
            for e2 in m2:
                p.add((e1,e2))
        return p
    
def uppgift_4():
    print ("Uppgift 4")
    print("4a", setprod({1,2,3}, {4,5}))

    print("\n")


# uppgift 5
def uppgift_5():
    print ("Uppgift 5")
    #5a
    p = setprod(A,B)
    print("5a Produkten av mängderna", A, "och", B, "är","\n", p)

    #5b
    q = setprod(B,C)
    p = setprod(A,q)
    print("5b Produkten av mängderna","\n", A,"\n" "och","\n", q, "\n", "är","\n", p)

    #5c
    if setprod(A,B) == setprod(B,A):
        print("5c True")
    else:
        print("5c False")

    #5d
    Tom = set()
    if setprod(A,Tom) == Tom:
        print("5d True")
    else:
        print("5d False")

    print("\n")
    

print("Vilka uppgifter vill ni se? Skriv 1, 2, 3, 4, 5 eller Alla.") #frågar vilken fråga man vill ha svaret på
user_input = ("värde") # för att while loopen ska fungera behöver vi ett värde på user_input

while user_input != ("Alla"):
    user_input = input()
    if user_input == ("1"):
        print("\n")
        uppgift_1()
        print("Vilka uppgifter vill ni se? Skriv 1, 2, 3, 4, 5 eller Alla.")
    elif user_input == ("2"):
        print("\n")
        uppgift_2()
        print("Vilka uppgifter vill ni se? Skriv 1, 2, 3, 4, 5 eller Alla.")
    elif user_input == ("3"):
        print("\n")
        uppgift_3()
        print("Vilka uppgifter vill ni se? Skriv 1, 2, 3, 4, 5 eller Alla.")
    elif user_input == ("4"):
        print("\n")
        uppgift_4()
        print("Vilka uppgifter vill ni se? Skriv 1, 2, 3, 4, 5 eller Alla.")
    elif user_input == ("5"):
        print("\n")
        uppgift_5()
        print("Vilka uppgifter vill ni se? Skriv 1, 2, 3, 4, 5 eller Alla.")
else:
    print("\n")
    uppgift_1()
    uppgift_2()
    uppgift_3()
    uppgift_4()
    uppgift_5()
