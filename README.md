# Math Quiz Game 🎮

A simple console-based Math Quiz Game built using **C++**.
The program generates random math questions with different difficulty levels and operation types, then evaluates the player's answers and displays the final score.

---

#  Features

* Randomly generated math questions
* Multiple difficulty levels:

  * Easy
  * Medium
  * Hard
  * Mixed
* Multiple operation types:

  * Addition
  * Subtraction
  * Multiplication
  * Division
  * Mixed Operations
* Tracks:

  * Correct answers
  * Wrong answers
  * Final result (Pass / Fail)
* Color feedback for correct and wrong answers
* Ability to replay the game

---

#  Technologies Used

* **C++**
* Standard Library:

  * `<iostream>`
  * `<cstdlib>`

---


---

#  How to Run

## Requirements

You need:

* A C++ compiler such as:

  * GCC (g++)
  * MSVC
  * MinGW

* Windows terminal (because the project uses `system("color")` and `system("cls")`)

---

## Compile the Project

Using g++:

```bash
g++ main.cpp -o MathGame
```


#  How the Game Works

1. The player chooses:

   * Number of questions
   * Difficulty level
   * Operation type

2. The game generates random questions.

3. The player answers each question.

4. The system:

   * Checks the answer
   * Displays whether it is correct or wrong
   * Changes screen color accordingly

5. At the end, the game shows:

   * Total questions
   * Correct answers
   * Wrong answers
   * Final result



#  Programming Concepts Used

This project demonstrates:

* Enums
* Structs
* Functions
* Arrays
* Loops
* Conditional Statements
* Random Number Generation
* Passing by Reference
* Simple Game Logic

---

#  Notes

* The division operation uses integer division.
* The project is currently designed for Windows terminals.
* `system("cls")` and `system("color")` may not work properly on Linux/macOS.


# Example Gameplay

```text
How many question do you want to answer? 3

Enter Question Level:
[1] Easy
[2] Med
[3] Hard
[4] Mix

Enter Operation Type:
[1] Add
[2] Sub
[3] Mult
[4] Div
[5] Mix

Question [1/3]

5
3 +
__________

8

Right Answer :-)
```

---

# 👨‍💻 Author

Developed by  **Yousif**



