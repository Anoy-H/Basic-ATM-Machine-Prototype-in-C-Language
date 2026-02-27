# Basic-ATM-Machine-Prototype-in-C-Language
This project is a basic ATM machine prototype developed using the C programming language without any GUI.

Table of Contents
__________
- [Features](#features)
- [How to Run](#how-to-run)

## Features
> User Mode
- Account login
- Account login verification
- Check account balance
- Cardless cash deposit
- Cardless cash withdrawal
> Admin Mode
- Admin login verification
- Add cash to ATM machine
- Remove cash from ATM machine
> The persistence data Storage System utilises external .txt files to save data
- accountlist.txt : Stores user account numbers
- accountPINlist.txt : Stores user account pin numbers;
- balance.txt : Stores user account balances;
- namelist.txt : Stores user account names;
- notelist.txt : Stores the number of the notes available in the machine;
> ⚠️ All .txt files must remain in the same directory or folder as the .exe (executable) file or the .c script.

## How to Run
⚠️ All .txt files must remain in the same directory or folder as the .exe (executable) file or the .c script.
__________
> Run using the .c file
- Run the following code inside the directory using the terminal for Windows:
"gcc atm.c -o atm"
> Run using the .exe (executable file)
- Run the atm.exe
