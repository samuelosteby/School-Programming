#Laboration 3 i Datavetenskapens Grunder
#Av Hampus Tuokkola och Samuel Östeby
print("\n")
print("Laboration 3 - Datanvetenskapens Grunder")
print("Av Hampus Tuokkola och Samuel Östeby")
print("\n")

#Uppgift 1
def klocka_plus(tid1,tid2):
    #Placera ut timmarna och minutrarna i två tupler
    timme1 = tid1[0] # Sätt timme1 i första positionen i tuple tid1
    minut1 = tid1[1] # Sätt minut1 i andra positionen i tuple tid1
    timme2 = tid2[0] # Sätt timme2 i första positionen i tuple tid2
    minut2 = tid2[1] # Sätt minut2 i andra positionen i tuple tid2

    #Addera minut1 och minut2 och spara resten av minuterna över 60 i minut3
    minut3 = ((minut1 + minut2) % 60)

    #Addera minut1 och minut2, ta kvoten som antalet extra timmar
    extra_timmar = ((minut1 + minut2) // 60)

    #Addera alla timmar och använd resten för att hålla det inom 0-23 timmar
    timme3 = ((timme1 + timme2 + extra_timmar) % 24)
    return timme3, minut3
#1a
print("Uppgift 1 a", klocka_plus((10, 45), (14, 30)))
#1b
print("Uppgift 1 b", klocka_plus((10, 45), (-14, -30)))

#Uppgift 2
#Skapa en funktion som kontrollerar om ett tal är delare till ett annat tal
def delare(a,b):
    c = (b % a) # Använd rest då ett delbart tal ska returnera 0
    if c == 0:
        return True
    else:
        return False
#2a
print("Uppgift 2 a", delare(3,6))
#2b
print("Uppgift 2 b", delare(3,7))
#2c
def primtal(prim):
    #Om prim är 0 eller negativt, returnera False då 0 och negativa tal ej är primtal
    if prim <= 0:
        return False
    c = 2 # 2 är närmaste heltalet större än 1
    for c in range(2, prim): #Gör en loop som kollar om alla tal mellan 2 och prim är delare med prim
        d = delare(c,prim)
        if d == True: #Om ett tal är delare med prim
            return False #Returnera False då det ej är ett primtal
    return True #Om inget tal över 1 förutom prim självt är delare med prim, returnera True
print("Uppgift 2 c:")
print("tal = 1", primtal(1))
print("tal = 2", primtal(2))
print("tal = 3", primtal(3))
print("tal = 4", primtal(4))
print("tal = 5", primtal(5))
print("tal = 9", primtal(9))
print("tal = 12", primtal(12))
print("tal = 13", primtal(13))
print("True = primtal, False = ej primtal")


#Uppgift 3
#3a
def fib(n):
    if n < 3:
        return 1
    else:
        print("Beräknar fib(", n-1, ") och fib(", n-2, ")")
        return fib(n-1)+fib(n-2)
#3b
def loopfib(n):
    curr = 1
    prev = 1
    for i in range(n-2):
        old_curr = curr
        curr = curr+prev
        prev = old_curr
    return curr

print("Uppgift 3 a och b Slutsats finns som kommentarer i koden.")
# Den rekursiva funktionen är många gånger mer långsam och till exempel beräknar fib(3) 21 gånger när man skriver in fib(10)
# Den är då väldigt oeffektiv eftersom den gör många beräkningar flera gånger trots att den redan gjort dem.
# Detta visar att trots att rekursiva funktioner kan vara väldigt användbara så är de inte rätt för alla situationer

#Uppgift 4 behöver inte redovisas
print("Uppgift 4 behöver inte redovisas.")

#Uppgift 5
#5a

###### Allt under denna linje utom angle-dangle är kopierat från LMS-instruktionerna!
import tkinter
from math import sin, cos, radians

class DrawingWindow(tkinter.Frame):
    def __init__(self):
        tkinter.Frame.__init__(self,None)
        self.canvas = tkinter.Canvas(self,width=500,height=500,bg='white')
        self.canvas.pack(expand=1,anchor=tkinter.CENTER)
        self.pack()

def draw_tree(x,y,angle,dangle,length,dlength,steps,canvas):
    if steps == 0:
        pass
    else:
        x2 = x+sin(radians(angle))*length
        y2 = y-cos(radians(angle))*length
        canvas.create_line(x,y,x2,y2)
        draw_tree(x2,y2,angle+dangle,dangle,length/dlength,dlength,steps-1,canvas)
        draw_tree(x2,y2,angle-dangle,dangle,length/dlength,dlength,steps-1,canvas)

def draw_tree3(x,y,angle,dangle,length,dlength,steps,canvas):
    if steps == 0:
        pass
    else:
        x2 = x+sin(radians(angle))*length
        y2 = y-cos(radians(angle))*length
        canvas.create_line(x,y,x2,y2)
        draw_tree(x2,y2,angle+dangle,dangle,length/dlength,dlength,steps-1,canvas)
        draw_tree(x2,y2,angle-dangle,dangle,length/dlength,dlength,steps-1,canvas)
        draw_tree(x2,y2,angle/dangle,dangle,length/dlength,dlength,steps-1,canvas)

###### Allt över denna linje utom angle-dangle är kopierat från LMS-instruktionerna!

# Vi har INTE gjort två funktioner av draw_tree eftersom
# draw_tree endast ritar trädet. Specifikationerna behöver man inte göra helt nya funktioner för.
print("Uppgift 5 Kolla på det andra fönstret för våra två fina träd. Kommentarer finns i koden.")

# Create window for drawing on
w = DrawingWindow()
# Draw the spiral on the canvas of that window
# Try to change the parameters and see what happens
draw_tree(100,250,0,30,100,2,3,w.canvas) # Träd med 2 förgreningar
draw_tree3(250,250,0,30,100,2,3,w.canvas) # Träd med 3 förgreningar
# Start the window, so it is displayed
w.mainloop()
