/*
Programmer Name: Jonathan Christian
		Some functions by Steven Miller
Date Submitted:
File Purpose: htmlcheck driver
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a


*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "htmltags.h"

namespace DS {

	
	//pre: argc is the number of arguments provided. Right is the expected number of arguments, ignoring the first one (ie: name of exe)
	//		that is ALWAYS present.  Usage is the error message that is displayed if number of args does not match.
	//post: Outputs message and returns false when it fails to validate, true otherwise.
	bool validate_argc(int argc, int right, const char usage[]) {
		if ((argc - 1) == right)
			return true;
		std::cerr << usage << std::endl;
		return false;
	}

	// A function that opens a file for input and checks that the opening process did not fail.
	// pre: The ifstream f has been opened for reading using the given filename. 
	// post: If any errors occurred then an error message has been printed and the program has been halted.
	void open_for_read(std::ifstream& f, const char filename[]) {
		f.open(filename);
		if (f.fail()) {
			std::cerr << "Could not open input file" << std::endl;
			std::exit(1);
		}
	}

	// A boolean function that determines whether a specified file still has valid input.
	// post: The return value is true if f still has more valid input to read; 
	// otherwise the return valid is false.
	bool is_more(std::istream& f) {
		return f && f.peek() != EOF;
	}

	int main(int argc, char* argv[])
	{
		std::ifstream fileIn;
		open_for_read(fileIn, argv[1]);

		while (is_more)
			htmltags(fileIn);

		return 0;
	}

}