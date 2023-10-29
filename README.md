# Tic-Tac-Toe-game
- A Two Player Tic Tac Toe Game, developed in C++

***

## Problem Statement 

Design a command-line based, 3x3 grid Tic Tac Toe game that can be played by 2-players.

## Requirements 

### Board 

3x3 grid board with the following naming convention for squares of the grid

```
A1    A2    A3
B1    B2    B3
C1    C2    C3
```

### Players 

Game has 2 players. Every player has a character. The character is by default, “X” and “O” for player 1 and 2.

### Game 

- Game starts with Player 1 inserting their character on one of the boxes 
- Players get alternative turns, and insert their characters on boxes 
- On every turn, take command line input of which box to place character
- After every turn show state of game 
- After every turn, one of 4 conditions can happen
  
  - Player specifies wrong box (already has been used);  
    In this case, same player will try again 
  - Placing the character results in game winning condition (specified below);  
    in this case end the game and declare winner 
  - Player specifies correct box, but doesn’t win game;  
    Give turn to other player and continue game  
  - Board is full (this was last entry), and no winner;  
    Declare game draw and end game 
- Winning conditions:   
  Same character in all boxes of: 
    - Any Row
    - Any Column
    - Any Diagonal 


## Gameplay

![image](https://user-images.githubusercontent.com/96369223/221359267-73aa3c0a-039c-42c8-a8ca-01c0b0fd2713.png)
![image](https://user-images.githubusercontent.com/96369223/221359284-7fb289d5-f04d-465d-9652-96e27ac0c097.png)
![image](https://user-images.githubusercontent.com/96369223/221359303-adbf8cf2-9f70-4060-b7f3-a48f909efaa9.png)
![image](https://user-images.githubusercontent.com/96369223/221359315-85b244de-5429-4965-b54e-f3cc1efa49f3.png)
![image](https://user-images.githubusercontent.com/96369223/221359364-47d37fa8-8bed-4f36-b1a8-432cbbaff796.png)
![image](https://user-images.githubusercontent.com/96369223/221359410-fe64ee2f-1e1c-44ee-8e2c-6705d35ca589.png)
![image](https://user-images.githubusercontent.com/96369223/221359443-f857985e-4165-4494-b8c0-a63e280d576c.png)



