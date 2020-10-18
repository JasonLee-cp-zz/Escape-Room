# Escape-Room
HKU ENGG1340 Project

(1) Team Members :

    Changjin Lee UID : 3035435840

    Changmin Han UID : 3035496519

(2) About Game:

    Game Title: Escape Room

    Game Description: Escape the room collecting as many items as you can and avoiding creeping monsters.

(3) Game Features:

(I) Basic Features

    (a) Stages
    
      (a1) Three Stages (Easy, Medium, Hard)
      
      (a2) Bonus Map (Item random generation - as many items as possible in the limited time)
      
    (b) Items
    
      (b1) ! -> item to be collected
      
    (c) Weapons
    
      (c1) A -> Ammo / 5 bullets per 1 Ammo
      
      (c2) B -> Time Bomb / bomb up&down&left&right by one cell ->explode in 2-3 seconds
      
      (c3) M -> Magnet / Collect a distant item (visual effect of pulling the item into the user)
      
      (c4) (Optional) S -> Super Weapon / 
      
    (d) Score Calculation System
    
      (d1) X: score   Y: # of paths
      
           Total Score = X*50 - Y*0.5 (Details TBA)
           
           If the Scores are the same, the player with less paths wins

(II) Generation of random game sets or events

    - Wandering monsters in the map
    
    - Random generation of items

(III) Data structures for storing game status

    - C++ Hashmap - multimap to store username/score/# of paths
    
    - Stored in decreasing order so that the player with highest score is located at the top

(IV) Dynamic memory management

    - dynamic size of multimap to store username/score/# of paths
    
    - more too be added...
    
(V) File input/output (e.g., for loading/saving game status)

    - Score.txt file to store username/score/#of paths
    
    - Import the scoreboard from the file when a new game is started

(VI) Program codes in multiple files

    - 3 cpp files / 3 header files
    
(VII) Proper indentation and naming styles

(VIII) In-code documentation


