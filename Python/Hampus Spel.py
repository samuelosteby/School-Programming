import time
import random
 
class Du :
    hitpoints = 15
    attack = 10
    defence = 10
 
class Imp :
    hitpoints = 10
    attack = 3
    defence = 1
 
print("En vild Imp med" , Imp.hitpoints, "liv kommer fram.")
while ((Imp.hitpoints >= 0) and Du.hitpoints > 0) : #loop så länge hp är över 1 för båda
    svar = input("Vill du slå honom? ")
    if svar == "Ja" or "ja" :
        Imp.hitpoints = (Imp.hitpoints - (Du.attack - Imp.defence)) #damage Imp tar = hp - (att - defence)
        print("Du slår Imp och gör", (Du.attack - Imp.defence), "i skada")
        if (Imp.hitpoints <= 0): #om Impens hp går under noll sätt den till 0
            Imp.hitpoints == 0
            print("Impen dog......")
        else :
            print("Impen har nu", Imp.hitpoints, "liv kvar")
    else :
        print("Imp springer iväg") # väljer man nej så sticker imp
 
if Imp.hitpoints <= 0 : #om impen har 0 eller mindre hp
    #time.sleep(5)
    print("Impen respawnar och blir transformerad till en demon.")
    Imp.hitpoints = 100 #ställer om imp variablar
    Imp.attack = 40
    Imp.defence = 20
    #time.sleep(1)
    print("Imp har nu", Imp.hitpoints, "liv,", Imp.attack, "attack och", Imp.defence, "försvar.")
   
#time.sleep(2)
item1 = input("Du hittar ett magiskt svärd, vill du ta upp det? ")
if item1 == "Ja" or "ja" :
    rollsword = random.randint(0,4) #rollar en check för om det är ett svärd eller en fälla
    if rollsword == 0 : #om den rollar 4 tar man skada
        rolldmg = random.randint(0,5)
        Du.hitpoints = Du.hitpoints - rolldmg
        print("Just när du ska ta upp svärdet så förvandlas den till eld, du har tagit", rolldmg, "skada, ditt nya liv är ", Du.hitpoints)
    else : #annars hittar man svärd
        print("Du hittade demonslayersword of doom, med hjälp utav svärdet kan du sänka demonens försvar och öka din styrka!")
        svar = input("Vill du använda svärdet? ")
        if svar == "Ja" or "ja" :
            swordreduc = random.randint(0,40) #buff på svärd + sänkning på imp
            Imp.attack = Imp.attack - swordreduc
            Imp.defence = Imp.defence - swordreduc
            Du.attack = Du.attack + swordreduc
            if (Imp.defence <0) :
                Imp.defence = 0
            print("Du sänkte Impens attack och försvar med", swordreduc,"dens nya attack är", Imp.attack, "och försvar är", Imp.defence, "Du ökade även din styrka till", Du.attack)
           
        svar = input("I högen fann du även en superrustning, vill du använda den? ")
        if svar == "Ja" or "ja" :
            print("Du sätter på dig rustningen och märker att den känns otroligt robust....")
            rustningpos = random.randint(20,100)
            Du.defence = Du.defence + rustningpos
            print("Din defence är nu", Du.defence)
           
       # svar = input("Vill du nu attackera demonen? ")
       # if svar == "Ja" or "ja" :
            #while ((Imp.hitpoints >= 0) and Du.hitpoints > 0) : #loop så länge hp är över 1 för båda
               # Imp.hitpoints = (Imp.hitpoints - (Du.attack - Imp.defence)) #damage Imp tar = hp - (att - defence)
               # print("Du slår Imp och gör", (Du.attack - Imp.defence), "i skada")
               # if (Imp.hitpoints <= 0): #om Impens hp går under noll sätt den till 0
                 #   Imp.hitpoints == 0
                #    print("Impen dog......")
               # else :
               #     print("Impen har nu", Imp.hitpoints, "liv kvar")
          #  else :
             #   print("Imp springer iväg") # väljer man nej så sticker imp
