# 🏗️ Tower of Hanoi - SDL2 Implementation

This project implements the **Tower of Hanoi** puzzle using **C and SDL2** for graphical representation. The game allows users to solve the Tower of Hanoi problem interactively using **mouse controls**.

---

## 🚀 Features

✅ **Graphical Representation** – Uses **SDL2** to render the towers and disks.  
✅ **Interactive Gameplay** – Move disks using the **mouse**.  
✅ **Color-Coded Disks** – Each disk has a unique color for better visualization.  
✅ **Automatic Progression** – Adds an extra disk after solving each puzzle.  
✅ **Win Condition** – The game **ends at 7 disks**.  

---

## 🛠 Requirements

Ensure you have the following installed:

- **C Compiler (GCC or Clang)**
- **SDL2 Library**

To install SDL2 on Linux:
```bash
sudo apt-get install libsdl2-dev
```

On Windows, download and install **SDL2** from [SDL's official website](https://www.libsdl.org/).

---

## 📥 Installation & Compilation

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/YathishPoojary98/TowerofHanoi.git
```

Navigate into the cloned directory:

```bash
cd TowerofHanoi/Towers-of-Hanoi-Puzzel-Game-master
```

### 2️⃣ Compile the Code

Compile the program using **GCC**:
```bash
gcc -o towerofhanoi towerofhanoi.c -lSDL2
```

### 3️⃣ Run the Game

Execute the compiled binary:
```bash
./towerofhanoi
```

---

## 🎮 How to Play

1️⃣ **Click on a disk to pick it up**.  
2️⃣ **Move the mouse to the desired tower** and **release the click** to drop the disk.  
3️⃣ **Follow the Tower of Hanoi rules** – A larger disk **cannot** be placed on a smaller disk.  
4️⃣ **Game Progression** – The number of disks increases after each successful solution.  
5️⃣ **The game ends** when the player successfully completes the puzzle with **7 disks**.  

---

## 📂 Code Structure

- **`towerofhanoi.c`** – Main game logic and SDL rendering.  
- **`stackd.h`** – Stack implementation for disk movement.  
- **`Makefile` (Optional)** – Compilation automation.  

---

