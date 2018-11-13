
# Modules
import random

# define number

# roll
def die(d):
    die_value = random.randint(1,d)
    print("The", d, "sided die rolled a", str(die_value)+".")

# amount of die


## Detta blir fel, gör alla seperata i en lista fel för att räkna antal tärningar
##def diecount(amount):
##    amountlist = []
##    for c in range(1,(int(amount)+1)): # so the amount starts from 1
##        amountlist.append(c) # add to list
##        print(amountlist)
##
##        
##    for i in amountlist:
##        die(i)
        

# game
amount = input("How many die do you want to roll? ")
amount = int(amount)
d = input("What kind of die do you want to roll? Write with numbers. ")
yes_no = "y"
while (yes_no.lower()) == "y":
        die(int(d))
        
        yes_no = input("Do you want to continue? Y/N ")
else:
    print("Thank you for playing")
    
