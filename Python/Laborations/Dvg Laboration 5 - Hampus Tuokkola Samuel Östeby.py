from automata import *
import re
#Laborationen är utförd av Hampus Tuokkola & Samuel Östeby
print("Dvg - Laboration 5 - av Hampus Tuokkola & Samuel Östeby")

# UPPGIFT 1
print("Uppgift 1")
state = auto1_run('01010101')
print(state)
print("Denna automat byter tillstånd beroende på om den senast inlästa symbolen är 0 (s0) eller 1(s1).")
print("Är det senaste tillståndet s0 efter funktionen avslutas returnerar den False, är det s1 returnerar den True.")
print("Om något tecken är icke-binärt skriver den ut detta och ignorerar tecknet.\n")
print("Bokens automat gör precis detsamma.")

# UPPGIFT 2
print("Uppgift 2")
state1 = mealy_run('0')
print(state1)
state2 = mealy_run('1')
print(state2)
state3 = mealy_run('1101')
print(state3)
state4 = mealy_run('001010100')
print(state4)
state5 = mealy_run('111110')
print(state5, "\n")
print("Denna automat börjar på tillståndet s0, sedan går den igenom varje tecken i ordning.")
print("När den läser in symbolen 1 byter den till s1, när den igen läser 1 går den till s2. Sedan vid nästa 1 går den tillbaka till s0.")
print("Varje gång den läser 0 stannar den vid det tillstånd den är vid och gör ingenting.\n")

# UPPGIFT 3
print("Uppgift 3")
print("Var god se TORTOISE \n")

# UPPGIFT 4
print("Uppgift 4")
listofwords = ["auto", "autopilot", "autopiloten", "läskautomat"]
for i in listofwords:
    result = re.search('((auto|flyg)(mat|pilot))$', i)
    if result:
        if result.group(0) == i:
            print("True", i)
        else:
            print("False", i)
    else:
        print("False", i)
'((auto|flyg)(mat|pilot))$'
print("Orsaken till att autopilot är det enda ordet som är med är för att det är det\nenda ordet som har element ur båda uttrycken (auto i första och pilot i andra)")

print()

# UPPGIFT 5
print("Uppgift 5")
a = "myfile.tex"
b = "yourfile"
c = "cooldoc123.tex"
d = "textdocument.doc"
e = "filebile.ini"
filelist = [a,b,c,d,e]
print()

print("5a: Testa om filerna", "\'"+a+"\'", "\'"+b+"\'", "\'"+c+"\'", "\'"+d+"\'", "och", "\'"+e+"\'", "har extensionen \'.tex\' i dem.")
for i in filelist:
    result = re.search('.tex$', i)
    if result:
        if result.group(0) == '.tex':
            print("True", i)
        else:
            print("False", i)
    else:
        print("False", i)

print()

print("5b: Test om filerna",  "\'"+a+"\'", "\'"+b+"\'", "\'"+c+"\'", "\'"+d+"\'", "och", "\'"+e+"\'", "saknar extension.")
for i in filelist:
    result = re.search('[.^$]', i)
    if result:
        print("False", i)
    else:
        print("True", i)

print()

print("5c: Test om filerna",  "\'"+a+"\'", "\'"+b+"\'", "\'"+c+"\'", "\'"+d+"\'", "och", "\'"+e+"\'", "har tre siffror innan extensionen.")
for i in filelist:
    result = re.search('[1-9][1-9][1-9][.]', i)
    if result:
        print("True", i)
    else:
        print("False", i)

print()

print("5d: Test om filerna",  "\'"+a+"\'", "\'"+b+"\'", "\'"+c+"\'", "\'"+d+"\'", "och", "\'"+e+"\'", "har någon av exensionerna .tex, .doc., .ini eller .txt.")
for i in filelist:
    result = re.search('(.txt|.doc|.tex|.ini)$', i)
    if result:
        print("True", i)
    else:
        print("False", i)

print()

# UPPGIFT 6
print("Uppgift 6")
filelist = ['0', '0a','04', '15', '1066', 'femton']
for i in filelist:
    result = re.search('^([1-9]|0|^a-z)$|^[1-9]([1-9]|0)(([1-9]|0)*)$', i)
    print(result)
    if result:
        print("True", i)
    else:
        print("False", i)

print()

# UPPGIFT 7
print("Uppgift 7")
filelist = ['0', '10', '10+20', '7*8+33/5-999', 'mycket', '22**13+-4', '+32', '15+', '+']
for i in filelist:
    result = re.search('(([1-9]|0|^a-z)|[1-9]([1-9]|0)(([1-9]|0)*))(([+\-*/])(([1-9]|0|^a-z)|[1-9]([1-9]|0)(([1-9]|0)*))*)$', i)
    print(result)
    if result:
        print("True", i)
    else:
        print("False", i)         
