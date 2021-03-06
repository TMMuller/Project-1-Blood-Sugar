// Blood Sugar Project.cpp : Defines the entry point for the console application.
//

/*
Objectives for this project

_______________Store for Each Day__________________
Sum of all Blood Sugar Readings
Max of all Blood Sugar Readings
Min of all Blood Sugar Readings
Count of VALID Blood Sugar Readings


_________________Store Each Day____________________
Sum of all Blood Sugar Readings
Max of all Blood Sugar Readings
Min of all Blood Sugar Readings
Count of VALID Blood Sugar Readings
Day of Week with Biggest Day-to-Day Delta of Valid Reading




Psuedo Code

Request Value from user
check if value is numberical
if value is not numerical determine if it is D, W, or N



===================================
				Notes
				------



===================================

*/


#include "stdafx.h"
#include "Data Request and Process.h"
#include "LinkedList.h"
#include<iostream>
#include<string>
#include<regex>

using std::cin;
using std::string;
using std::regex_match;
using std::regex_search;
using std::regex;
using std::stof;

int main()
{
	

	string input;
	int i(0); //Index to determine if the 14th day has been passed
	int week(1);
	float val(0);
	double weekSum(0);
	double weekCount(0);
	int sumOverload(0);
	int countOverload(0);
	double weekMax(0);
	double weekMin(0);
	double biggestDeltaDay(0);
	int start_week_day(0);
	double Delta(0);

	List ArrayofLinkedLists[14]; //Initialization of an array of 14 Linked Liist Classes



	while (i < 14) 
	{
		cout << "\nBlood Sugar Level\n -or- \nD/Day->Daily Summary\nW/Week->Weekly Summary \nN/Next->Increment Day \n : "; //User input


		cin >> input;
		

		if (regex_search(input, regex("\\d{25}"))) //This program will consider any entry greater accuaracy than 25 sig figs as invalid
		{
			continue;
		}


		if (!is_number(input)||(stof(input)<=0)) //If the value is not a float or int then the below conditions will be checked on the input
		{
			if (regex_match(input, regex("Day|D")))
			{
				ArrayofLinkedLists[i].Daily_Summary();  //Member function that displays a daily summary
				continue;
			}
			else if (regex_match(input, regex("Week|W"))) {
				if (i <= 6) //Determines what week the user is on 
				{
					start_week_day = 0;
					week = 1;
				}
				else //Determines what week the user is on 
				{
					start_week_day = 7;
					week = 2;
				}


				//Reset the weekly values
				
					weekSum = 0;
					weekCount = 0;
					weekMin = 301;
					weekMax = 0;
					Delta = 0;
					biggestDeltaDay = 0;
				

				//Weekly Summary
				for (int d = start_week_day; d <= i; d++) //Produces a weekly summary values for the user
				{
					if (is_overloading(weekSum,ArrayofLinkedLists[d].sum())) //If sum overloads this will store the count in a form of scientific notation
					{
						sumOverload = overload_notation(weekSum);
					}
					
					weekSum += ArrayofLinkedLists[d].sum(); //Sums the daily summaries


					if (is_overloading(weekCount, ArrayofLinkedLists[d].size())) //If count overloads this will store the count in a form of scientific notation
					{
						countOverload = overload_notation(weekCount);
					}

					weekCount += ArrayofLinkedLists[d].size(); //Sums the weekly count

					if (weekMax < ArrayofLinkedLists[d].Max())//Compares the daily max's
					{
						weekMax = ArrayofLinkedLists[d].Max(); //Sets the new weeks max
					}
				
					if ((weekMin > ArrayofLinkedLists[d].Min())||(weekMin==0))//Compares the weekly mins
					{
						weekMin = ArrayofLinkedLists[d].Min(); //Sets the new weeks min
					}

					if ((d > 0) && (ArrayofLinkedLists[d - 1].size() != 0) && (ArrayofLinkedLists[d].size() != 0)) //Sets conditions for finding the day delta
					{
						if (Delta < ArrayofLinkedLists[d].size() - ArrayofLinkedLists[d - 1].size()) {
							biggestDeltaDay = d%6 + 1; //Finds the day of the week with the biggest delta day for the counts
						}
					}

				}

				//Display of summary
				
				cout << "--------- Here is the Weekly Summary Thus Far for Week " << week << " -------- " << endl;
				if (sumOverload < 0)//Displays in significant figures
				{
					cout << "Sum of all Blood Sugar Readings : " << weekSum << "^"<<sumOverload << endl;
				}
				else {
					cout << "Sum of all Blood Sugar Readings : " << weekSum << endl;
				}
				cout << "Max of all Blood Sugar Readings : " << weekMax << endl;
				cout << "Min of all Blood Sugar Readings : " << weekMin << endl;
				if (countOverload > 0) //Displays in significant figures
				{
					cout << "Count of all Blood Sugar Readings : " << weekCount << "^" << countOverload << endl;
				}
				else
				{
					cout << "Count of all Blood Sugar Readings : " << weekCount << endl;
				}
				cout << "The Day of Week with the Biggest Day-to-Day Delta of Valid Readings is : " << biggestDeltaDay << endl << endl; 

				continue;
			}

			else if (regex_match(input, regex("Next|N"))) //Increments the day
			{
				increment_day(); //Displays a statement
				i += 1;//Increment the day
				continue;
			}
			else {
				continue;
			}
		}



		val = stof(input); //Convert the user input from string into a float value

		if (val > 300) //No human has ever recorded a higher blood sugar level than 150 therefore anything above 300 will be considered invalid
		{
			continue;
		}

		ArrayofLinkedLists[i].insertAsLast(val); // Inserts the value into the days linked list


	}




	cout << endl << "================= Last Day Has Been Passed ====================" << endl;


    return 0;
}

