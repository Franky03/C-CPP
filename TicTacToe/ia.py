import tensorflow as tf
from keras.models import Sequential
from keras.layers import Dense, Flatten
from keras.models import load_model
from keras import optimizers
import random
import numpy as np
import math

reward_dep= .7
x_train= True

#Modelo 1
#Add is to add a new layer in neural network

model= Sequential()
model.add(Dense(units=130, activation='relu', input_dim=27, kernel_initializer='random_uniform', bias_initializer='zeros'))
model.add(Dense(units=250, activation='relu', kernel_initializer='random_uniform', bias_initializer='zeros'))
model.add(Dense(units=140, activation='relu', kernel_initializer='random_uniform', bias_initializer='zeros'))
model.add(Dense(units=60, activation='relu', kernel_initializer='random_uniform', bias_initializer='zeros'))
model.add(Dense(9, kernel_initializer='random_uniform', bias_initializer='zeros'))
model.compile(optimizer='adam', loss='mean_squared_error', metrics=['accuracy'])

#Modelo 2

model_2 = Sequential()
model_2.add(Dense(units=130, activation='relu', input_dim=27, kernel_initializer='random_uniform', bias_initializer='zeros'))
model_2.add(Dense(units=250, activation='relu', kernel_initializer='random_uniform', bias_initializer='zeros'))
model_2.add(Dense(units=140, activation='relu', kernel_initializer='random_uniform', bias_initializer='zeros'))
model_2.add(Dense(units=60, activation='relu', kernel_initializer='random_uniform', bias_initializer='zeros'))
model_2.add(Dense(9, kernel_initializer='random_uniform', bias_initializer='zeros'))
model_2.compile(optimizer='adam', loss='mean_squared_error', metrics=['accuracy'])

def one_hot(state):
    current_state=[]

    for square in state:
        if (square==0):
            current_state.append(1)
            current_state.append(0)
            current_state.append(0)
        elif (square == 1):
            current_state.append(0)
            current_state.append(1)
            current_state.append(0)

        elif (square == -1):
            current_state.append(0)
            current_state.append(0)
            current_state.append(1)

    return current_state

def get_outcome(state):
    total_reward= 0

    for i in range(0,9):
        if i==0 or i==3 or i==6:
            if state[i] == state[i + 1] and state[i] == state[i + 2]:
                total_reward = state[i]
                break
            elif state[0] == state[4] and state[0] == state[8] and i==0:
                total_reward= state[0]
                break
        
        if i< 3:
            if state[i] == state[i + 3] and state[i] == state[i + 6]:
                total_reward= state[i]
                break
            elif state[2]==state[4] and state[2] == state[6] and i==2:
                total_reward = state[2]
                break
        
    if (state[0] == state[1] == state[2]) and not state[0]==0:
        total_reward = state[0]
    elif (state[3] == state[4] == state[5]) and not state[3] == 0:
        total_reward = state[3]
    elif (state[6] == state[7] == state[8]) and not state[6] == 0:
        total_reward = state[6]
    elif (state[0] == state[3] == state[6]) and not state[0] == 0:
        total_reward= state[0]
    elif (state[1] == state[4] == state[7]) and not state[1] == 0:
        total_reward = state[1]
    elif (state[2] == state[5] == state[8]) and not state[2] == 0:
        total_reward = state[2]	
    elif (state[0] == state[4] == state[8]) and not state[0] == 0:
        total_reward = state[0]
    elif (state[2] == state[4] == state[6]) and not state[2] == 0:
        total_reward = state[2]
    
    return total_reward

try:
    model = load_model('tic_tac_toe.h5')
    model_2 = load_model('tic_tac_toe_2.h5')
    print('Pre-existing model found... loading data.')
except:
    pass

