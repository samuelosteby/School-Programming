# Initialize modules
import random
import time

# Initialize variables
Stranswer = ""
Intanswer = ""

# Skill List
#   Attack
#   Block
#   Heavy blow
#   Fireball
#   Quick slash

# Skill List
#   Lesser HP potion


# Initialize entities
# Define player class
class player :
    Name = ""
    Class = ""
    MaxHP = 100
    HP = 100
    MaxMP = 100
    MP = 100
    DefSTR = 10
    STR = 10
    defWIS = 10
    WIS = 10
    defDEX = 10
    DEX = 10
    defDEF = 0
    DEF = 0
    defATK = 0
    ATK = 0
    Skills = ["Attack", "Block"]
    Items = ["Lesser HP potion"]
    AvailableActions = ["Skill", "Item", "Escape"]

class AO :
    Name = ""
    Class = ""
    HP = 0
    MP = 0
    STR = 0
    WIS = 0
    DEX = 0
    DEF = 0
    ATK = 0
    Skills = []

# Define enemy classes
class imp :
    Name = "Imp"
    HP = 10
    MP = 100
    STR = 10
    WIS = 10
    DEX = 10
    DEF = 3
    ATK = 0
    Skills = ["Attack", "Block"]

class goblin :
    Name = "Goblin"
    HP = 25
    MP = 100
    STR = 15
    WIS = 15
    DEX = 15
    DEF = 6
    ATK = 0
    Skills = ["Attack", "Block"]


# Initializes Classes and Lists for other entities
def InitializeClass(CurrentClass) :
    # Determine skills available to player depending on their class
        if (CurrentClass == "Warrior") :
            player.Class = "Warrior"
            player.Skills.extend(["Heavy blow"])
        elif (CurrentClass == "Wizard") :
            player.Class = "Wizard"
            player.Skills.extend(["Fireball"])
        elif (CurrentClass == "Thief") :
            player.Class = "Thief"
            player.Skills.extend(["Quick slash"])

# Define enemy AI
def AI() :
    print("Let's see if this shit works")

# Resolve player's use of a skill
def ResolveSkill(PlayerSkillUsed) :
    if (PlayerSkillUsed in player.Skills) :
        if (PlayerSkillUsed == "Attack") :
            player.ATK = ((player.STR * 0.4) - AO.DEF)
            if (player.ATK < 0) :
                player.ATK = 0
            AO.HP = (AO.HP - player.ATK)
            if (AO.HP < 0) :
                AO.HP = 0
            print("You close in on ", AO.Name, " for a quick attack!")
            print("You dealt ", player.ATK, " damage to ", AO.Name, ".", AO.Name, " has ", AO.HP, " HP left.")
        elif (PlayerSkillUsed == "Block") :
            placeholder = 0
        elif (PlayerSkillUsed == "Fireball") :
            player.ATK = (player.WIS - AO.DEF)
            if (player.ATK < 0) :
                player.ATK = 0
            AO.HP = (AO.HP - player.ATK)
            if (AO.HP < 0) :
                AO.HP = 0
            print("You throw a mighty fireball at ", AO.Name, ("!"))
            print("You dealt ", player.ATK, " damage to ", AO.Name, ".", AO.Name, " has ", AO.HP, " HP left.")
        elif (PlayerSkillUsed == "Quick slash") :
            player.ATK = (player.DEX - AO.DEF)
            if (player.ATK < 0) :
                player.ATK = 0
            AO.HP = (AO.HP - player.ATK)
            if (AO.HP < 0) :
                AO.HP = 0
            print("You dash in and slash at ", AO.Name, "'s weak spot!")
            print("You dealt ", player.ATK, " damage to ", AO.Name, ".", AO.Name, " has ", AO.HP, " HP left.")


# Resolve player's use of an item
def ResolveItem(PlayerItemUsed) :
    if (PlayerItemUsed in player.Items) :
        HPPotionValue = 50
        if (PlayerItemUsed == "Lesser HP potion") :
            player.HP = (player.HP + HPPotionValue)
            if (player.HP > player.MaxHP) :
                player.HP = player.MaxHP
                print("You used a ", PlayerItemUsed, " . Your HP is now ", player.HP, ".")

# Define combat
def combat(Enemy) :
    Turn = 0 # Set the turn timer to 0 at combat start
    # Active opponent, the enemy the player will be fighting
    # Initialize and copy enemy stats for combat
    TurnFighter = "Player" # TurnFighter determines whose turn it is
    FightResult = ""
    PlayerAction = ""
    PlayerSkillUsed = ""
    PlayerItemUsed = ""
    PlayerHasDecided = False
    EscapeChance = 75 # Percentage of success for the Player escaping
    AO.Name = Enemy.Name
    AO.HP = Enemy.HP
    AO.MP = Enemy.MP
    AO.STR = Enemy.STR
    AO.WIS = Enemy.WIS
    AO.DEX = Enemy.DEX
    AO.DEF = Enemy.DEF
    AO.ATK = Enemy.ATK
    AO.Skills = Enemy.Skills

    # Tell Player who or what they are fighting
    print("You are fighting ", AO.Name, "!")

    # While the fight isn't over...
    while(FightResult == "") :
        # Turn Phase - Player
        # While it's the player's turn
        while(TurnFighter == "Player"):
            # Until the player has decided on an action...
            while(PlayerHasDecided == False) :
                # Present options to Player
                print("It is your turn.")
                print("What do you wish to do?")
                print(player.AvailableActions)
                PlayerAction = input("")
                # If the Player decides to use a skill
                if (PlayerAction == "Skill") :
                    ValidInput = False
                    print("Which skill do you want to use?")
                    print(player.Skills)
                    PlayerSkillUsed = input("")
                    # If the skill the player wants to use is in the player's skill list
                    while (ValidInput != True) :
                        if (PlayerSkillUsed in player.Skills) :
                            ValidInput = True
                            PlayerHasDecided = True
                        else :
                            print("Invalid input. You have no such skill.")
                            print("Which skill do you want to use?")
                            print(player.Skills)
                            PlayerSkillUsed = input("")
                elif (PlayerAction == "Item") :
                    #Check if the player has items
                    if (player.Items) :
                        ValidInput = False
                        print("Which item do you want to use?")
                        print(player.Items)
                        PlayerItemUsed = input("")
                        # If the item the player wants to use is in the player's item list
                        while (ValidInput != True) :
                            if (PlayerItemUsed in player.Items) :
                                ValidInput = True
                                PlayerHasDecided = True
                            else :
                                print("Invalid input. You have no such item.")
                                print("Which item do you want to use?")
                                print(player.Items)
                                PlayerItemUsed = input("")
                    else :
                        print("You have no items.")
                elif (PlayerAction == "Escape") :
                    # The computer makes a random decision as to whether the Player manages to escape or not
                    EscapeValue = random.randint(1, 100)
                    # If EscapeValue is smaller than the EscapeChance, the player manages to flee
                    if (EscapeValue < EscapeChance) :
                        EscapeResult = "Succeeded"
                        PlayerHasDecided = True
                    else :
                        EscapeResult = "Failed"
                        PlayerHasDecided = True
                else :
                    print("Invalid input.")

            # Here the player's action is resolved    
            print("If shit works, this is where we resolve stuff")
            k = input("")
            # Check what action the player took
            # If the Player used a skill...
            if (PlayerAction == "Skill") :
                ResolveSkill(PlayerSkillUsed)
                TurnFighter = "AO"
                PlayerHasDecided = True

            # If the player used an item...
            elif (PlayerAction == "Item") :
                ResolveItem(PlayerItemUsed)
                TurnFighter = "AO"
                PlayerHasDecided = True

            # If the player tried to escape...
            elif (PlayerAction == "Escape") :
                # If the player managed to escape
                if (EscapeResult == "Succeeded") :
                    print("You successfully managed to escape.")
                    TurnFighter = ""
                    FightResult = "Escaped"
                elif (EscapeResult == "Failed") :
                    print("You failed to escape.")
                    TurnFighter = "AO"

        while (TurnFighter == "AO"):
            time.sleep(3)
            print("It is", AO.Name,"'s turn.")
            print("The ", AO.Name, " takes some time to consider the options.")
            time.sleep(3)
            AI()
            k = input("")
    k = input("")

################ START OF THE GAME ################
InitializeClass("Warrior")
print("Your class is ", player.Class, ".")
print("Your available skills are ", player.Skills, ".")
k = input("")

combat(imp)

print("The game has ended")
k = input("")