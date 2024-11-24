# Software Requirements Specification for Snake Game: Terminal Edition

## Introduction

This document outlines the software requirements for the **Snake Game: Terminal Edition** (SGT). The game is designed to run in a terminal environment and will provide an interactive experience for users to play a classic Snake game.

## Functional Requirements

1. **Interactive Menus**

   - The game should allow users to navigate menus using the keyboard.
   - The menu options should include "Start Game", "How to Play", "About", "Customize Snake", and "Settings".

2. **Gameplay**

   - Users should be able to control the snake using the arrow keys.
   - The snake should grow in length each time it eats food.
   - The game should end if the snake collides with itself or the walls.

3. **Game Over and Pause**

   - The game should show a "Game Over" screen when the snake collides with itself or the wall.
   - The game should allow users to pause during gameplay using the 'P' key.

4. **Customization**
   - Users should be able to customize the snake’s appearance, including color and character.

## Non-Functional Requirements

1. **Performance**

   - The game should run smoothly without lag on modern terminal emulators.

2. **Portability**

   - The game should work on Linux and macOS terminal environments.

3. **Security**

   - The game should ensure that there are no vulnerabilities that could be exploited by users.

4. **Maintainability**
   - The codebase should be modular and well-documented to allow for easy maintenance and updates.

## Assumptions

- The game will be played in a terminal with raw input mode enabled.
- The game will be built using the C programming language.

```

```
