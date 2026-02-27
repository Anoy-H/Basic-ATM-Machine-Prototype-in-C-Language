#include <stdio.h>
#include <stdlib.h>

int accountList[1000];
FILE *accountListFile;
int accountPINList[1000];
FILE *accountPINListFile;
int balanceSheet[1000];
FILE *balanceSheetFile;
int notesList[2];
FILE *noteListFile;
char nameSheet[1000][50];
FILE *nameListFile;

int NotesOf500Available;
int NotesOf1000Available;

int accountNumber = 0;
int accountNumberSeq = 9999;

void Initialize();
void AdminMode();
void AccountCheck();
void SelectOptions();
void CardlessDeposit();
void AdminDeposit();
void CardlessWithdrawal();
void AdminWithdrawal();
void ClearScreen();
void LoadAccountList();
void LoadAccountPINList();
void LoadNameList();
void LoadNoteList();
void LoadBalanceSheet();
void SaveBalanceSheet();
void SaveNoteList();

int main()
{
	LoadBalanceSheet();
	return 0;
}

void Initialize()
{
	ClearScreen();
	printf("Welcome to Virtual Bank PLC.\n");
	printf("[Credit Card, Debit Card & MFS services are not available at the moment. Only cardless account deposit & withdrawal service is available.]\n");
	printf("Enter Your Account Number: ");
	scanf("%d", &accountNumber);
	ClearScreen();
	AccountCheck();
}

void AccountCheck()
{
	for(int i = 0; i < 5; i++)
	{
		if(accountList[i] == accountNumber)
		{
			accountNumberSeq = i;
			break;
		}
	}

	if(accountNumber == 19640419)
	{
	    printf("Enter ADMIN pin: ");
	    int pin;
	    scanf("%d", &pin);
	    if(pin == 196404)
        {
            AdminMode();
        }
		else
		{
		    Initialize();
		}
	}
	else if(accountNumber == accountList[accountNumberSeq])
	{
	    printf("Enter account pin: ");
	    int pin;
	    scanf("%d", &pin);
	    if(pin == accountPINList[accountNumberSeq])
        {
            ClearScreen();
            printf("Welcome, %s", nameSheet[accountNumberSeq]);
            printf("Your account balance is: %d Taka.\n", balanceSheet[accountNumberSeq]);
        }
		else
		{
		    Initialize();
		}
	}
	else
	{
		Initialize();
	}
	SelectOptions();
}

void SelectOptions()
{
	printf("\nFor cardless cash deposit, enter 1. ");
	printf("For cardless cash withdrawal, enter 2.\n");
	printf("Enter: ");
	int Input;
	scanf("%d", &Input);
	switch (Input)
	{
	case 1:
		CardlessDeposit();
		break;
	case 2:
		CardlessWithdrawal();
		break;
	default:
		Initialize();
		break;
	}
}

void CardlessWithdrawal()
{
	ClearScreen();
	printf("Enter the amount to withdraw (The amount must be a multiplier of 500): ");
	int amountToWithdraw;
	scanf("%d", &amountToWithdraw);
	if(amountToWithdraw % 500 == 0)
	{
		int remainingAmount, notesUsed500, notesUsed1000;
		if(amountToWithdraw <= balanceSheet[accountNumberSeq])
		{
			remainingAmount = amountToWithdraw;

			switch (remainingAmount / 1000 <= NotesOf1000Available)
			{
			case 1:
				notesUsed1000 = remainingAmount / 1000;
				break;
			case 0:
				notesUsed1000 = NotesOf1000Available;
				break;
			}
			remainingAmount = remainingAmount - notesUsed1000 * 1000;
			switch (remainingAmount / 500 <= NotesOf500Available)
			{
			case 1:
				notesUsed500 = remainingAmount / 500;
				break;
			case 0:
				notesUsed500 = NotesOf500Available;
				break;
			}
			remainingAmount = remainingAmount - notesUsed500 * 500;

			if(remainingAmount == 0)
			{
				balanceSheet[accountNumberSeq] = balanceSheet[accountNumberSeq] - amountToWithdraw;
				notesList[0] = NotesOf500Available - notesUsed500;
				notesList[1] = NotesOf1000Available - notesUsed1000;
				SaveNoteList();
				printf("Withdrawal successful. Collect the notes from the machine. Your current account balance is = %d Taka.\n", balanceSheet[accountNumberSeq]);
				SaveBalanceSheet();
			}
			else
			{
				printf("Sorry. Insufficient funds in the machine. Can't withdraw the amount.");
			}
		}
		else
		{
			printf("Insufficient funds in the account. Withdrawal unsuccessful. Your current account balance is = %d Taka.\n", balanceSheet[accountNumberSeq]);
		}
	}
	else
	{
		printf("Invalid amount.\n");
	}
	int Input;
	printf("Enter any number to close the session. \n");
	printf("Enter: ");
	scanf("%d", &Input);
	switch(Input)
	{
	default:
		Initialize();
	}
}

void CardlessDeposit()
{
	ClearScreen();
	printf("Enter the number of 500 notes to deposit: ");
	int notesToDepositUsing500;
	scanf("%d", &notesToDepositUsing500);
	printf("Enter the number of 1000 notes to deposit: ");
	int notesToDepositUsing1000;
	scanf("%d", &notesToDepositUsing1000);
	balanceSheet[accountNumberSeq] = balanceSheet[accountNumberSeq] + notesToDepositUsing500 * 500 + notesToDepositUsing1000 * 1000;
	NotesOf500Available += notesToDepositUsing500;
	NotesOf1000Available += notesToDepositUsing1000;
	SaveNoteList();
	printf("Deposit successful. Your current account balance is = %d Taka.\n", balanceSheet[accountNumberSeq]);
	SaveBalanceSheet();
	int Input;
	printf("Enter any number to close the session. \n");
	printf("Enter: ");
	scanf("%d", &Input);
	switch(Input)
	{
	default:
		Initialize();
	}
}

void LoadBalanceSheet()
{
	balanceSheetFile = fopen("balance.txt", "r");
	if(balanceSheetFile == NULL) {
		printf("System Error. \n");
	}
	for(int i = 0; i < 5; i++) {
		fscanf(balanceSheetFile, "%d", &balanceSheet[i]);
	}
	fclose(balanceSheetFile);
	LoadNoteList();
	LoadAccountList();
	LoadAccountPINList();
	LoadNameList();
	Initialize();
}

void SaveBalanceSheet()
{
	balanceSheetFile = fopen("balance.txt", "w");
	for (int i = 0; i < 1000; i++)
	{
		fprintf(balanceSheetFile, "%d\n", balanceSheet[i]);
	}
	fclose(balanceSheetFile);
}

void LoadAccountList()
{
    accountListFile = fopen("accountlist.txt", "r");
	if(accountListFile == NULL) {
		LoadBalanceSheet();
	}
	for(int i = 0; i < 1000; i++) {
		fscanf(accountListFile, "%d", &accountList[i]);
	}
	fclose(accountListFile);
}

void LoadAccountPINList()
{
    accountPINListFile = fopen("accountPINlist.txt", "r");
	if(accountPINListFile == NULL) {
		LoadBalanceSheet();
	}
	for(int i = 0; i < 1000; i++) {
		fscanf(accountPINListFile, "%d", &accountPINList[i]);
	}
	fclose(accountPINListFile);
}

void LoadNameList()
{
    nameListFile = fopen("namelist.txt", "r");
	if(nameListFile == NULL) {
		LoadBalanceSheet();
	}
	for(int i = 0; i < 1000; i++) {
		fgets(nameSheet[i], sizeof(nameSheet[i]), nameListFile);
	}
	fclose(nameListFile);
}

void LoadNoteList()
{
	noteListFile = fopen("notelist.txt", "r");
	if(noteListFile == NULL) {
		LoadBalanceSheet();
	}
	for(int i = 0; i < 2; i++) {
		fscanf(noteListFile, "%d", &notesList[i]);
	}
	fclose(noteListFile);
	NotesOf500Available = notesList[0];
	NotesOf1000Available = notesList[1];
}

void SaveNoteList()
{
	notesList[0] = NotesOf500Available;
	notesList[1] = NotesOf1000Available;
	noteListFile = fopen("notelist.txt", "w");
	for (int i = 0; i < 2; i++)
	{
		fprintf(noteListFile, "%d\n", notesList[i]);
	}
	fclose(noteListFile);
}

void AdminMode()
{
	ClearScreen();
	printf("Welcome to ADMIN mode.\n");
	printf("To add cash, enter 1. ");
	printf("To take away cash, enter 2.\n");
	printf("Enter: ");
	int Input;
	scanf("%d", &Input);
	switch (Input)
	{
	case 1:
		AdminDeposit();
		break;
	case 2:
		AdminWithdrawal();
		break;
	default:
		Initialize();
		break;
	}


}

void AdminDeposit()
{
	printf("Enter the number of 500 notes to deposit: ");
	int notesToDepositUsing500;
	scanf("%d", &notesToDepositUsing500);
	printf("Enter the number of 1000 notes to deposit: ");
	int notesToDepositUsing1000;
	scanf("%d", &notesToDepositUsing1000);
	NotesOf500Available += notesToDepositUsing500;
	NotesOf1000Available += notesToDepositUsing1000;
	SaveNoteList();
	printf("Deposit successful.\n");
	SaveBalanceSheet();
	int Input;
	printf("Enter any number to close the session. \n");
	printf("Enter: ");
	scanf("%d", &Input);
	switch(Input)
	{
	default:
		Initialize();
	}
}

void AdminWithdrawal()
{
	printf("Enter the number of 500 notes to withdraw: ");
	int notesOf500ToWithdraw;
	scanf("%d", &notesOf500ToWithdraw);
	printf("Enter the number of 1000 notes to deposit: ");
	int notesOf1000ToWithdraw;
	scanf("%d", &notesOf1000ToWithdraw);
	if(notesOf500ToWithdraw <= NotesOf500Available && notesOf1000ToWithdraw <= NotesOf1000Available)
	{
		notesList[0] = NotesOf500Available - notesOf500ToWithdraw;
		notesList[1] = NotesOf1000Available - notesOf1000ToWithdraw;
		SaveNoteList();
		printf("Admin withdrawal successful.");
	}
	else
	{
		printf("Insufficient notes to perform the action.");
	}
	int Input;
	printf("Enter any number to close the session. \n");
	printf("Enter: ");
	scanf("%d", &Input);
	switch(Input)
	{
	default:
		Initialize();
	}
}

void ClearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
