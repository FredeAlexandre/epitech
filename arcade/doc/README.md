# Arcade
Arcade is a gaming platform: a program that lets you choose a game to play and keeps a register of player scores.

Group(s):
- Alexandre Frede, Léandre Sentenac, Ange Mouquet

## Requirements for currently implemented features

- Ncurses
- SDL2
- SFML

# Table of contents
- Running the arcade<br>
- Global Process <br>
&nbsp; - Architecture <br>
- Core<br>
&nbsp; - Interfaces <br>
- Components<br>
- Games<br>
&nbsp; - Mandatory methods<br>
- Graphical libraries<br>
&nbsp; - Mandatory methods<br>
&nbsp; - Input/Signal retrieval

# Running the arcade
**0. Start the program**

To run the program we have developed an utility tool that does everything for you. To run it you just have to execute this command on a terminal:

```bash
./run
```

This will do the same as running

```bash
mkdir -p build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
cd ..
./arcade
```

**1. Changing the graphical library**

We handle multiple graphic libraries such as Ncurses, SFML and SDL2. You can change the graphical library rendering the arcade game at any time and at any page. You simply have to press the `F1` key on your keyboard

**2. Changing the Game**

We have also a large library of games... 2 Games are avaible right now ! You can change the currently playing game by pressing the `F2`. This can be done at any time when you are playing a game

**3. Reloading the Game**

To reload your current game you only have to press `F3`

**4. Exiting the game**

To return to the menu and see your score you can do it at any time by pressing to `F4`

# Global Process
## **Architecture**:
The project is built around an ECS architecture.

```
     ┌─────┐                                    ┌────┐                                        ┌────────┐
     │IGame│                                    │Core│                                        │IGraphic│
     └──┬──┘                                    └─┬──┘                                        └───┬────┘
        │           Initialize the game           │                                               │     
        │<─────────────────────────────────────────                                               │     
        │                                         │                                               │     
        │Return the entities to use and store them│                                               │     
        │─────────────────────────────────────────>                                               │     
        │                                         │                                               │     
        │                                         │ Initialize the graphic with size of the window│     
        │                                         │ ──────────────────────────────────────────────>     
        │                                         │                                               │     
        │       Apply an update on entities       │                                               │     
        │─────────────────────────────────────────>                                               │     
        │                                         │                                               │     
        │                                         │          Apply an update on entities          │     
        │                                         │ ──────────────────────────────────────────────>     
     ┌──┴──┐                                    ┌─┴──┐                                        ┌───┴────┐
     │IGame│                                    │Core│                                        │IGraphic│
     └─────┘                                    └────┘                                        └────────┘

```
# Core
## **Interfaces:**<br>

Our arcade implementation contains a few interfaces, namely:<br>
IGame, Igraphic, ISystem, IEntity and IComponent<br>
<br>
Those interfaces serve as templates to create new arcade features, and ensures they will communicate correctly with the core, if the necessary methods are implemented.

# Components
## **ClockComponent:**<br>
Used to handle features such as delay and timing, internal to the arcade process.
## **EndComponent:**<br>
Used to detect when a game has ended.
## **ExitComponent:**<br>
Used to detect when a game has exited.
## **GetInputComponent:**<br>
Used to transmit input information to an entity through an input list.
## **PositionComponent:**<br>
This component contains information such as X Y Z positions.
## **ScoreComponent:**<br>
This components contains necessary information to handle scores.
## **SizeComponent:**<br>
This component contains scale values to resize the visuals in graphic libraries.
## **SpriteComponent:**<br>
Contains information about a sprite.
Additionally, a rectangle to only display a certain part of the sprite, along its X Y positions on the sprite. Used for spriteSheet support.
## **SpriteSheetComponent:**<br>
Contains the path to the spriteSheet.
(single sprite spriteSheets also work)
## **TextComponent:**<br>
Contains information about a text, include the message itself, positions and rotation.
# Games
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; A game library must inherit from the IGame interface class and implement two mandatory methods to work properly: **init** and **update**.
## **Mandatory methods:**<br>
## - std::list\<std::shared_ptr\<arcade::ecs::IEntity>> **init**(void)

The init method is called when the game is loaded. This methods should set up all the necessary entities and components for the game logic to function properly in the update method. <br>
GraphicInit "value" contains basic information related to the initialisation, such as Height and Width of the display space.

## - void update(std::list\<std::shared_ptr\<arcade::ecs::IEntity>> &entities)

This method should apply the game logic of one game frame, using the provided entity list.

# Graphical libraries
## **Mandatory methods:**
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; A graphical library must inherit from the IGraphic interface class and implement two mandatory methods to work properly: **init** and **update**.

## - void **init**(arcade::GraphicInit value)
The init method is called when the library object is created. This methods should set up the display window or any kind of environment necessary for the library to display frames properly.<br>
GraphicInit "value" contains basic information related to the initialisation, such as Height and Width of the display space.

## - void **update**(std::list\<std::shared_ptr\<arcade::ecs::IEntity\>\> &entities)
This methods is called at every frame to display, it takes a list of entities.<br> Entities might have components with information that will allow the library to display objects properly.<br>
The library can also use different components as it needs. But the entity list and its contents should not be modified in any way unless it is for input transferring.

## **Input/Signal retrieval**
Detected events or inputs should be pushed into the list of the GetInputComponents.
If the displaying method is closed, the library should not stop the program, instead setting ExitComponents's boolean exit value to true and let the core handle the close signal.