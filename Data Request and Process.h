#pragma once

#include<iostream>
#include "Data Request and Process.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stod;



void increment_day();

bool is_overloading(const double val, const double new_val);

int overload_notation(double &val);

bool is_number(const std::string& s);