/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Lesson #3
** File: 	source.cpp
** Description: Finding out the most frequently occurring value in an array 
** of numbers. As an example, we can think of these values as coins, with 
** pennies, dimes, nickels, and quarters or other unknown denomination. 
** Provide functions and arrays accordinly.
**
** Author: 	Gerardo Castro
** Date: 	08/23/2025
** -------------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

// Function declarations
void startCounting(int coinList[], int coinListSize, int denominationCounts[]);
void displayCountSummary(int denominationCounts[]);
void findMostFrequentCoin(int denominationCounts[]);

int main()
{
	// Define an array variable for a list of coins
	const int SIZE = 10;
	int groupOfCoins[SIZE] = { 10, 10, 50, 10, 10, 5, 50, 1, 5, 1 };
	
	// Define an array to hold the counts of their type of coins: pennies, nickels, dimes, quarters, and other
	const int DENOMINATIONS = 5;
	int groupCounts[DENOMINATIONS] = { 0, 0, 0, 0, 0 }; // Initialize all counts to zero, super important!

	// Call these 3 functions to count the coins, display summary counts, and display message with highest count
	startCounting(groupOfCoins, SIZE, groupCounts);
	displayCountSummary(groupCounts);
	findMostFrequentCoin(groupCounts);

	// Indicate the end of the program
	cout << endl;
	cout << "End of Program";
	cout << endl;

	return 0;
}
/**
	Counts the number of each coin denomination in the given array.
	@param coinList An array of integers representing various type of coins.
	@param coinListSize The size of the coins array.
	@param denominationCounts The array holding the counts for the 5 coin denominations.
*/
void startCounting(int coinList[], int coinListSize, int denominationCounts[])
{
	for (int i = 0; i < coinListSize; i++)
	{
		switch (coinList[i])
		{
			case 1: denominationCounts[0]++;
			break;
			case 5: denominationCounts[1]++;
			break;
			case 10: denominationCounts[2]++;
			break;
			case 25: denominationCounts[3]++;
			break;
			default: denominationCounts[4]++;
			break;
		}
	}
}

/**
	Displays the count summary of each coin denomination.
	@param denominationCounts The array holding the counts for the 5 coin denominations.
*/
void displayCountSummary(int denominationCounts[])
{
	cout << "\nCoin Count Summary:\n";
	cout << "Pennies: " << denominationCounts[0] << endl;
	cout << "Nickels: " << denominationCounts[1] << endl;
	cout << "Dimes: " << denominationCounts[2] << endl;
	cout << "Quarters: " << denominationCounts[3] << endl;
	cout << "Other: " << denominationCounts[4] << endl;
	cout << endl;
}

/**
	Finds and displays the most frequently occurring coin denomination.
	@param denominationCounts The array holding the counts for the 5 coin denominations.
*/
void findMostFrequentCoin(int denominationCounts[])
{
	int biggestCount = denominationCounts[0];
	string coinName[5] = { "pennies", "nickels", "dimes", "quarters", "other" };
	string highCountCoin = coinName[0];

	for (int i = 1; i < 5; i++)
	{
		if (denominationCounts[i] > biggestCount)
		{
			biggestCount = denominationCounts[i];
			highCountCoin = coinName[i];
		}
	}
	cout << "The most frequently occurring coins are: " << highCountCoin << " with a count of " << biggestCount << endl;
}