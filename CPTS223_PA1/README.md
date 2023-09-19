# PROJECT: CS223.PA1
## REVIEW C++ BY MAKING A MATCHING-GAME TO LEARN LINUX COMMANDS
In this project we review the basics of C++ including:    
- writing templates
- building data structures (a singly-linked list for the commands, an array for player profiles)

---
## **A. PROJECT OVERVIEW**
Within the scope of this project, I have developed an interactive text-based single-player matching game to learn some Linux commands and what they can do. The player will be asked to match a Linux command with its appropriate description. For reference, all available commands are stored in a file called commands.csv, following the format:

    command, "description"

Before a game start (see C.2. for more details), the player selects the number of match questions that he/she wants to play. The player then continues the game until he/she has exhausted the number of selected questions.

If the command is matched, the player gains 1 point. If it is not, the player loses 1 point. Negative point is also possible.

At the end of each game, the player's profile (containing the player's name and his/her score) is saved on a its own line in a file called profiles.csv, following the format:

    name, points   

---
## **B. THE GAME FLOW**
### **I. The Main Menu**
The program displays a text menu with the following basic options:

            1. Game Rules
            2. Play Game
            3. Load Previous Game
            4. Add Command
            5. Remove Commnad
            6. Exit

The program loops back to the Main Menu once any option between 1-5 has been executed.

### **II. The Question**
When option #2 is selected, the program does the following steps:

    1. prompts the user to enter a name.
    2. prompts the user to enter any number between 5-30 for the number of Linux commands to be selected for the game.
    3. selects at random and display a Linux command and its description, ALONG with 2 other randomly selected descriptions.
    4. prompts the user to select a description out of the 3 displayed.

### **III. The Response**
Once the player has selected a description:

    a. if the description matches the command, displays a message telling they player that he/she has earned 1 point.
    b. otherwise, tells the player that he/she has lost 1 point.

---
## **C. PROGRAM STRUCTURE**
Each menu option is encapsulated in its own function.

### **1. GAME RULES**
Display a summary of the game rules.

### **2. PLAY GAME** (C++ concepts: template, singly-linked list)
First, Write a template for a singly-linked list.
    
    NOTE:
    - The class template (for the list) has 1 parameter of type NODETYPE.
    - The NODETYPE will be representative of another class template with 1 parameter called Node.
    - The class template for a Node will consist of a parameter of type DATATYPE.
    - The parameter DATATYPE will represent a concrete class called Data.
    - Each instance of class Data should represent a different command and its coressponding description.
    
Second, the program instantiates a singly-linked list and populates it with ALL Linux commands. This should be the library-list.

Third, set the game duration with a user-selected number (between 5-30) of questions to be played. This number decreases with every question, and the game ends when it reaches 0.
    
    NOTE:
    Since a command should not be listed more than once during a game, it is best to have a string array to keep track of which commands have been previously selected.

### **3. LOAD PREVIOUS GAME**
Prompts the user to enter a profile name. If the profile matches one in the profiles array, the program displays the stored points to the screen. From this point onward, the game carries on like when option #2 is selected.

### **4. ADD COMMAND**
Prompts the user to enter a new command and its description to the current list of commands.

    This is accomplished sequentially:
    1. Ask for the command
    2. Ask for the description

Once the a new instance of class Data has been instantiated with the new command, the program then links it to the library-list. Duplicate commands are not allowed.

### **5. REMOVE COMMAND**
Prompts the user to enter a command to be removed from the library-list.

### **6. EXIT**
Up until this point, all operations such as adding or removing commands should have been done the library-list only. At exit, the library-list is finalized and saved into the commands.csv file.

The same applies to the profiles.csv file. If another profile already exists then it must be overwritten with new points.

---
## **D. OTHER REQUIREMENTS**
    - I must list 1 advantage and disadvantage of using a linked list for the data structure involed with storing the commands and description.
    - I must relate my ideas to the way the list is used in THIS assignment.
    - The commentary must be put in comment block at the top of the main.cpp file UNDER A CLEARLY MARKED AREA called "ADVANTAGES/DISADVANTAGES OF LINKED LIST:".
    - I must list 1 advantage and disadvantage of using an array for the data structure involved with storing the user profiles. The commentary similarly must be related to this assignment and put in a clearly marked area.