# Tic-Tac-Toe (C++)

A simple two-player Tic-Tac-Toe game that runs in the terminal. Players take turns entering a position from 1 to 9. The game checks for wins and draws, and rejects invalid or occupied positions.

## Build

You need a C++17 compiler such as `g++`.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o tic-tac-toe
```

## Run

On macOS or Linux:

```sh
./tic-tac-toe
```

On Windows PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o tic-tac-toe.exe
.\tic-tac-toe.exe
```

## Board positions

The empty board displays the position numbers used for each move:

```text
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9
```

X goes first, followed by O.
