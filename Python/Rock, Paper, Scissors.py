# Initialize modules and variables
import random

# Set options
options = ["rock", "paper", "scissors"]

def getComputerChoice () :
    return random.choice(options)

def getUserChoice () :
        uc = input("Do you want to choose rock, paper or scissors? Please type your selection. ")
        while not ((uc in options) or (uc == "stop")):
            uc = input("Do you want to choose rock, paper or scissors? Please type your selection. ")
        return uc

def determineWinner(cc, uc) :
    if cc == uc :
        return "There is a draw!"
    elif cc == "scissors" and uc == "paper":
        return "Computer wins!"
    elif cc == "paper" and uc == "rock":
        return "Computer wins!"
    elif cc == "rock" and uc == "scissor":
        return "Computer wins!"
    else :
        return "You win!"

def play () :
    userChoice = " "
    while not (userChoice == "stop") :

        # Computer does a random selection from options
        computerChoice = getComputerChoice()
        userChoice = getUserChoice()
        while not ((userChoice in options) or (userChoice == "stop")):
            userChoice = input("Do you want to choose rock, paper or scissors? Please type your selection. ")
            
        # Print information
        if not (userChoice == "stop"):
            print("Computer selected", computerChoice, ", user selected", userChoice)
            # Determine winner
            result = determineWinner(computerChoice, userChoice)
            print(result)
        else :
            print("Take care!")

play()

