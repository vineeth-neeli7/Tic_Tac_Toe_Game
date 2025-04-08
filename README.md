readme: |
  # Tic Tac Toe Game (C++ Console)

  This is my **first C++ mini-project**, which I initially built and ran locally as part of my learning. I'm now uploading it to GitHub to preserve my journey and demonstrate my fundamentals with file handling, board logic, and game structure.

  ---

  ## Features

  - 3×3 Tic Tac Toe board
  - 2-player turn-based play
  - Win detection (rows, columns, diagonals)
  - Logs winner and final board state to a file (`t_t_o_history.txt`)

  ---

  ## File Logging

  When a player wins, the following gets logged:

  Winner: Player 1 Final Board: 
  X O X 
  O X O
  _ _ X

 You can open `t_t_o_history.txt` to view the results of past games.

---

## 🛠 Technologies Used

- C++
- Standard I/O
- File Handling (fstream)

---

## How to Run

1. Open terminal in the project folder.
2. Compile the code:
   ```bash
   g++ tic_tac_toe.cpp -o game
   ./game
   ```
3. Play the game as prompted.
4. Check `t_t_o_history.txt` to see who won and what the final board looked like.

---

## Author

**Sai Vineeth Neeli**  
[GitHub Profile](https://github.com/vineeth-neeli7)

