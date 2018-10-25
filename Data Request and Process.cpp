
#include "stdafx.h"
#include<iostream>
#include "Data Request and Process.h"
#include <string>
#include<math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stod;
using std::fmod;



void increment_day() {
	cout << endl;
	cout << "----------- The Day has been Incremented ----------------" << endl;
}



bool is_overloading(const double val, const double new_val)
{
	if (val + new_val > 1000000)
	{
		return true;
	}
	return false;
}

//This function will convert the value input into an overloaded notation with a base of 1 million
int overload_notation(double &val)  
{
	int sig_fig(0);
	sig_fig = static_cast<int>(val) / 1000000;
		val = fmod(val,1000000); //Converts the input value at address to the value of the remainder
		return sig_fig; //Returns the signigicant figure
}



bool is_number(const std::string& s)
{
	try
	{
		stod(s);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

