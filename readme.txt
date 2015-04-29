Project:

The goal of this project is to create a version of the Mario Kart's time trial mode for Rainbow Road using GLUT and SDL.  We included the functionality to load in 3D models of Karts.

Gameplay:

Once the user pulls the files from this repository. He/She can run the 'make' command to compile the program.  Then the user can run the program by entering the command './main'. When the game is first run a menu is displayed prompting the user to enter a 1 or a 2 corresponding to the easy and hard track respectively.  Once the the program receives an appropriate track choice, another menu is displayed prompting the user for a Kart choice of 1,2, and 3 corresponding to the teapot, cow, and snowman respectively.  After a Kart is chosen the track with a view of the kart from behind is shown. In addition the lap number, speed, and number of mushrooms are displayed in the upper left hand corner, and current lap time and best lap time displays in the upper right hand corner.  Once the user presses the up arrow, the kart will start to accelerate and the timer will start.  The kart will decelerate if the user stops pressing the up arrow.  If the user presses the side arrows the kart will turn and the back arrow causes the kart to go in reverse.  If the kart goes the wrong way an appropriate message is displayed on the right hand side of the screen.  If the user falls off of the track, he/she is reset in the middle of the track with a speed of zero.  The user also has three "mushrooms" which speed up the car when the user presses the spacebar.


User Manual:

Compile the program with the ‘make’ command
Run the game using the command ./main
Enter your track choice:
  1. Easy
  2. Hard
Enter your Kart choice:
  1. Teapot
  2. Cow
  3. Snowman
Controls:
  Up Arrow: Accelerate
  Down Arrow: Reverse
  Left Arrow: Left turn.
  Right Arrow: Turn Right
  SpaceBar: Use mushroom(max 3)
Lap Number, Speed, and number of mushrooms are displayed in the upper left hand corner of the screen.
Lap time and best lap time are displayed on the right, and when a lap is
completed, that time is displayed temporarily on the right. The wrong way
warning will also display on the right.
