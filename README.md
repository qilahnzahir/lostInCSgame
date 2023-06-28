## Lost In School Of Computer Science Game
Hackathon Group 20
Members :
'Aqilah Nur Zahirah Mohd Asri
Nuranysa Fatihah Ismawady
Nur Nabilah Zahra Shaifuzi

#### Game Description.
"Lost in School of Computer Science" is a text based escape game where a students(player) got lost in the building. To escape from the school, player need to collect four hidden keys in different rooms namely Lecturer's Room, Library, Tutorial Class, Computer Lab and StudentLounge. Each rooms has challenging mission which need to be complete to get the key and special items that can be used along this adventure journey. As players make their way around the building and overcome hurdles, the game emphasises perseverance and problem-solving abilities.
#### Features of game.
1. **Multiple Rooms:** There are five rooms in the game namely Lecturer's Room, Library, Tutorial Class, Computer Lab and StudentLounge. Each rooms has challenging 
   mission which need to be complete to get the key and special items that can be used along this adventure journey.

2. **Challenging Mission:** These missions will ask you to perform calculations, arranging items, guessing the number, identifying mistake in coding and guessing the 
   locker. The player has an inventory where they can keep anything they've gained, such keys and a torch.

3. **Action:** Players can take actions like moving forward, backward, left, or right. They can also undo actions. The game features a stack data structure that 
   enables players to undo decisions and return to earlier places if necessary. In order to help players complete the mission, the game offers quests and 
   instructions. A queue can be used to organise these. Player can also take actions to do the mission, open player inventory to look through the special items and 
   collected key. These special items can be used as the items will be deleted means it no longer in the player's inventory.
4. **Inventory System:** Player has an inventory where they can keep anything they've gained, such keys and a torch.
5. **Saved Game:** Player can save the current game state which current room and inventory.
   
#### How to play your game.
1. The game begins with the player in Student Lounge in School of Computer Science.
2. Player can take action to move in diverse directions to move to the neighbour room and explore other room.
3. The player is given mission as soon as they enter a room.
4. To get a key, the player must complete the mission.
5. Throughout the game, player can open the inventory and always check the collected keys after passed the mission in particular room. 
7. The player can escape the school and win the game by obtaining four keys.
8. To advance, the player can use items in the inventory, undo actions and save the game.

This is our how to play to game: 
1. F/f: Forward                                                     
2. B/b: Backward                                                    
3. L/l: Left                                                        
4. R/r: Right
5. M/m: Do mission in room                                          
6. O/o: Open player inventory                                       
7. undo/UNDO: Undo action to the previous one                       
8. K/k: To see the total number of key in player's inventory            
9. U/u: Use                                                        
10. Q/q: Quit      

#### How object-oriented concepts were used to develop your game.
1. Objects: Classes that represent rooms, quests, items, and player, allowing for the encapsulation of pertinent information and behaviours.
2. Composition: Composition can be used to represent the relationship between the main game class and its components. For example, Room Class, Represents a specific 
   room in the school building. It has a relationship where the game class can compose multiple instances of the room class to represent different rooms within the 
   game.
3. Inheritance: Inheritance can be used to define relationships between different types of missions or rooms. For instance, different rooms may inherit from a common 
   "Room" class.
4. Polymorphism: Polymorphism can be employed to handle different types of missions or puzzles within the game, using methods or interfaces that can be implemented by 
   specific mission classes.
5. Encapsulation: Each class's data and functions can be organised using encapsulation, which also helps preserve readability and modularity in the code and ensures 
   adequate concern separation.
   
#### How linked lists/stacks/queues play a role in your game.
1. Linked Lists: The player's inventory system can be implemented using linked lists. Each acquired object can be kept as a node in the linked list, making it simple 
   to add and remove items from the list. We implemented three linkedList, linkedList for item in particular room, linkedList for inventory and linkedList for 
   gameState.
2. Stacks: The undo functionality can be implemented using stacks. Each action taken by the player can be added to a stack, and when that action is undone, the 
   preceding ones are removed from the stack in the opposite order. 
3. Queues: Quests and instruction can be managed via queues.  A queue of quests and instructions may exist in the game, and as one is completed, the player is shown 
   the next task. 
#### Game screenshot.

#### Game demo video link.
