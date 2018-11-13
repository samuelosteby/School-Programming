# Initialize modules and variables
import random

#Initialize variables
computerGuess = random.randint(1, 100) # Make the computer guess a number
maxValue = 100
minValue = 1

# Ask for user inputs
print("Think of a number between 1 and 100.") # Let the user think of a number between 1 and 100
print("The computer thinks the number you're thinking of is the number ", computerGuess) # Show the computer's guess
answer = input("Is this the right number? Write either 'True' or 'False'.") # Ask the player if the guess was correct

if (answer == "True") : #If the guess was right, end the game
    print("Hurray, the computer was right!")
elif (answer == "False") : # If the guess was wrong
    answer2 = False
    while not (answer2 == True) : # While the guess isn't right...
        answer = input("Is the number you're thinking of higher or lower than the guess? Type either 'Higher' or 'Lower'.") # Ask the player whether the answer is higher or lower
        if (answer == "Higher") : # If the guess was too low
            minValue = computerGuess
            if ((maxValue > minValue) and (minValue < maxValue)) :
                computerGuess = random.randint((minValue + 1), maxValue)
            elif (maxValue == minValue):
                answer = "Impossible"
                answer2 = True
        elif (answer == "Lower") : # If the guess was too high
            maxValue = computerGuess
            if ((maxValue > minValue) and (minValue < maxValue)) :
                computerGuess = random.randint (minValue, (maxValue - 1))
            elif (maxValue == minValue) :
                answer = "Impossible"
                answer2 = True
        if (answer == "Correct") : # If the guess was correct
            answer2 = True # Quit guessing for whatever reason
        print("The computer thinks you're thinking of the number ", computerGuess) # Show the user the guess
        print("If this is correct, type 'Correct'. Otherwise type 'Higher' or 'Lower.") # Ask user for input
    if ((answer2 == True) and (answer != "Impossible")): # If the computer finally guessed right
        print("Hurray, the computer was right!")
    elif ((answer2 == True) and (answer == "Impossible")): # If the user's answers aren't consistent and they've been contradicting themselves
        print("You failed, your answers weren't consistent.")
