# **The Maze**

**__This repository contains code for the Maze Project, done as the Foundations' final project in the ALX Software Engineering__**

<br>

![Maze](./screenshots/screencast_1.png)

<br>

The project explores how to create a realistic 3D maze using raycasting.


## **How to Compile and Run this Maze**
**Note:** To compile this program, ensure that libsdl2 is installed on the system <br>
If libsdl2 is not installed, on Ubuntu run

> ``` sudo apt-get install libsdl2-dev ```

To compile the program type these commands on the terminal

> ``` git clone https://github.com/reckafella/alx-maze_project ```<br>
> ``` cd alx-maze_project ```<br>
> ``` gcc src/*.c -Wall -Werror -Wextra -pedantic -lm -lSDL2main -lSDL2 -lSDL2_image -o maze ```<br>

or alternatively, run

> ``` make ```

To run this program <br>

> ``` ./maze map_name```

Where `map_name` is a file name for any text file located in the "maps" directory

Example Usage:

>```./maze default```

To enable textures run

> ```./maze map_name textured ```

where `map_name` is a map file

To disable textures run

> ``` ./maze map_name no-textures ```

Note: **By default, maze is rendered with the textures enabled.**

For help on how to run the maze run <br>
>```./maze help ```

or

> ```./maze map_name help ```

## **Maze Controls**
Use the following keys to control movement in the maze:<br>
> `W` or `up arrow key` - moving forward <br>
> `S` or `down arrow key` - moving backward <br>
> `A` or `left arrow key` - turning left <br>
> `D` or `right arrow key` - turning right <br>
> `R` - strafe right <br>
> `L` - strafe left <br>

## To-Do
* improve map parsing
* include more textures
* add options such as help, e.t.c
* add enemies, obstacles, e.t.c

## Resources
> * [SDL2 API](https://wiki.libsdl.org/CategoryAPI) <br>
> * [LazyFoo Beginning Game Programming](http://lazyfoo.net/tutorials/SDL/index.php) <br>
> * [Ray-Casting Tutorial For Game Development And Other Purposes by F. Permadi](http://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) <br>
> * [LodeV Raycasting Tutorial](http://lodev.org/cgtutor/raycasting.html) <br>
> * [Game Engine Black Book](https://www.amazon.com/Game-Engine-Black-Book-Wolfenstein/dp/1539692876) <br>

![Maze](./screenshots/screencast_4.png)
