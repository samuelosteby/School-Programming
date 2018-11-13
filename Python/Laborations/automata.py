# -*- coding: cp1252 -*-

# Tillst�ndsautomaten fr�n sidan 271, uppe.
# Anropas med: auto1_run('01000101')
# Skriver ut: tillst�nd -> nytt_tillst�nd

def auto1_run(indata_string):
    state = 's0'
    print(state,end="")
    for i in indata_string:
        state = auto1_step(state,i)
        print('->', state,end=" ")
    return state in ['s1']  # Kolla om i m�ltillst�nd

def auto1_step(state,indata):
    if state == 's0':         # Titta p� tillst�ndet (s0)
        if indata == '0':  # Titta p� indata
            return 's0'       # Returnera nytt tillst�nd
        elif indata == '1':
            return 's1'
    elif state == 's1':
        if indata == '0':
            return 's0'
        elif indata == '1':
            return 's1'
    print('Illegal input:', indata)
    return state

# Tillst�ndsautomaten fr�n s. 272, ex. 9.1
# Skickar ut en 1:a f�r var tredje 1:a, och 0 annars
# Anropas mealey_run('1010010')
# Skriver ut: tillst�nd -[ utdata ]-> nytt_tillst�nd

def mealy_run(indata_string):
    state = 's0'
    print(state,end="")
    for i in indata_string:
        output, state = mealy_step(state,i)
        print('-[',output,']->', state, end="")

def mealy_step(state,indata):
    if state == 's0':         # Titta p� tillst�ndet
        if indata == '0':     # Titta p� indata
            return '0','s0'   # Returnera utdata och nytt tillst�nd 
        elif indata == '1':
            return '0','s1'
    elif state == 's1':
        if indata == '0':
            return '0','s1'
        elif indata == '1':
            return '0','s2'
    elif state == 's2':
        if indata == '0':
            return '0','s2'
        elif indata == '1':
            return '1','s0'
    print('Illegal input:', indata)
    return '-', state 


