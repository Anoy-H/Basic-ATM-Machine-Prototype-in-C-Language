# Basic-ATM-Machine-Prototype-in-C-Language
This project is a basic ATM machine prototype without any GUI developed using the C programming language.

Table of Contents
__________
- [Features](#features)
- [How to Run](#how-to-run)
- [Demo Account Login or Admin Login Credinals](#demo_account_login_or_admin_login_credinals)
- [Usages](#usages)

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
> Run using the .c file
- Run the following code inside the directory using the terminal for Windows:
"gcc atm.c -o atm"
> Run using the .exe (executable file)
- Run the atm.exe

## Demo Account Login or Admin Login Credinals
⚠️ All .txt files must remain in the same directory or folder as the .exe (executable) file or the .c script.
> Demo Account Numbers
- 2312100
- 2312101
- 2312102
- 2312103
- 2312104
> Demo Account PIN Numbers
- 1234
- 1234
- 1234
- 1234
- 1234
> Demo Admin Login Credinals
- Admin Account Number: 19640419
- Admin PIN: 196404

## Usages
> This basic ATM machine prototype is totally console-based. In regular user mode, users can securely log in with their account number and PIN number to check their account balance, make cardless deposits, and withdraw cash, depending on the sufficient account balance and the available notes in the machine. The admin mode features administrators logging in using a different admin account number & different admin account PIN number to manage the machine’s cash vault by adding or by removing the notes already inserted into the machine. All account data is stored persistently in five external .txt files, so it is necessary to keep these .txt files in the same directory or in the same folder. This project provides a semi-realistic simulation of the basic ATM operations in a console or terminal, making the functionality of an ATM machine easier to understand.
__________
