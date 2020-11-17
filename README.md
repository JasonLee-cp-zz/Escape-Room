# Escape-Room
HKU ENGG1340 Project

!!! Game Info !!!

    -> Collect as many as items possible with FEWER paths/Ammo/Bombs and get to the destination !!!
    

    <Before Game>
    
    1) Download the zip file from the github repo.
    
    2) Extract the zip file and place all the 8 files into the home directory (cd ~)
    
    3) Type "bash bash.sh"
    
    4) You're good to go !!
    
    
    <In Game> 
    
    1) Direction Control Keys: W(up) S(down) A(left) D(right)
    
    2) In the main menu, click SPACE to continue..
    
    3) When entered the game, directions keys are the same 
    
      3-1) You will enter your name to play. Here, press ENTER instead of SPACE BAR to proceed
      
      3-2) 'P' for shoot Ammo, 'O' for Bomb (Make sure to collect A/B to be able to perform this function)
      
    4) (IMPORTANT) When you shoot Ammo, you can ONLY shoot to the "current" direction, meaning the direction status at the bottom of the screen indicates
    
       the current direction. (This means, you cannot shoot upward or downward when you're stuck with a narrow hall with no space up and down
   
      


(1) Team Members :

    Changjin Lee UID : 3035435840

    Changmin Han UID : 3035496519

(2) About Game:

    Game Title: Escape Room

    Game Description: Escape the room collecting as many items as you can and avoiding creeping monsters.

(3) Game Features:

    (I) Basic Features

       (a) Stage
      
       (b) Items
    
        (b1) ! -> item to be collected
        
      
       (c) Weapons
        
         (c1) A -> Ammo / 5 bullets per 1 Ammo
      
         (c2) B -> bomb up&down&left&right by one cell 
         
      
        (d) Score Calculation System
    
         (d1) X: score   Y: # of paths    A: remaining Ammo    B: remaining Bomb
      
              Total Score = X*50 - Y*0.5 + A*3 + B*5


    (II) Generation of random game sets or events
    
       - Random generation of items
       

    (III) Data structures for storing game status

      - C++ Hashmap - multimap to store username/score/# of paths
    
       - Stored in decreasing order so that the player with highest score is located at the top


    (IV) Dynamic memory management

       - dynamic size of multimap to store username/score/# of paths
    
       - Score Data management through file (.txt)
    
    
    (V) File input/output (e.g., for loading/saving game status)

        - Score.txt file to store username / score
    
      - Import the scoreboard from the file when a new game is started
      

    (VI) Program codes in multiple files

       - 3 cpp files / 3 header files
       
    
    (VII) Proper indentation and naming styles
    

    (VIII) In-code documentation
    
    (Libarires)
    * termios.h -> getch()
    * unistd.h -> time delay


