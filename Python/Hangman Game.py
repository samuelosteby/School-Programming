class Bampus :
    hp = 10
    atk = 10

class Sambos :
    defense = 5
    hp = 10

print("Bampus atk Sambos")
print("Bampus did",(Bampus.atk - Sambos.defense), "damage. Sambos now has ", Sambos.hp - (Bampus.atk - Sambos.defense), "HP left")
