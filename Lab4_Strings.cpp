// Lab4_strings.cpp
// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab4_strings.cpp -o Lab4_strings -std=c++11
//      or:  g++ Lab4_strings.cpp -o Lab4_strings -std=c++0x
// Some initialization methods and other things are not supported by the old standard. 

#include <iostream>
#include <string>
#include <cctype>
#include <locale>

using namespace std;

// Complete the assignments stated in the comments.
int main()
{
// ****************************************************************************
// Declare and initialize four or five strings. Use different ways of
// initializing, as shown in Table 7.1 (Lecture 7). 
    
    string how;
    string help (how);
    string system;

    cout << "Enter a string" << endl;
    cin >> system ;
	cout << "The sting you entered is: " << system << endl;
    
    string glass (system);
    string sweat ("6"); 
    string old = "6";
    string finale (5 , 'A');

// Try all the operations in Table 7.2 (Lecture 7) using the strings that
// you declared.
    int length;
    cout << "Enter a another string" << endl;
	cin >> help;
    //getline(cin, help );

    length = help.size();
	cout << "The size of the string you entered is: " << length << endl;
	if (!help.empty());
	{
		cout << "The string in here is " << help << endl;
	}
	
    help = help + finale;
    cout << "The sum of " << help << " and " << finale << " = " << help << endl;
    
    old = sweat;
    if (old == sweat) 
    {
        cout << old << " is equal to " << sweat << endl;
    }
    else 
    {
           cout << "Strings are not equal to each other "<< endl;
    }
    
    if (help != sweat)
    {
        cout << help << " is not equal to " << sweat << endl;
    }
    else 
    {
        cout << "Not cool" << endl;
    }
    if (glass < system)
    {
        cout << glass << " is less than " << system << endl;
    }
    if (old <= help)
    {
        cout << old << " is either less than or equal " << help << endl;
    }
    if (glass > system)
    {
        cout << glass << " is greater than " << system << endl;
    }
    if (old >= finale )
    {
        cout << old << " is greater than or equal to " << finale << endl;
    }

	cout << " **************************************************************************** "<< endl;
// -----------------------------------------------------------------------
	string line; 
	cout << "\nEnter some text:" << endl;
	cin.ignore();
	getline(cin, line);
	// 1) Count the number of letters in your input line above;
	auto i = line.size();
	cout << "Number of characters in the string: " << i << endl
		 << "Array (0) = " << line.at(0) << endl
		 << "Array ("<< i-1 << ")= " << line[i-1] << endl;
	
// ****************************************************************************
// Use "Range for" loops (L7_Ex6_Strings.cpp) and operations in table 7.3 to:

	int counter = 0;
	int wcount = 1;
	for(auto c:line)// "C goes through every char in the string"
	{
		// 3) Count the number of words (may be separated by white spaces, dots, etc.);
		if (isspace(c))
		{
			wcount++;
		}
	 // 2) Count the number of digits;
		if(isalnum(c))
		{
				if (isdigit(c))
				{
					counter++;
				}
		}
		if (islower(c))
		{
			c = toupper(c);
			cout << "Upper character =  " << c << endl;
		}
		else if (isupper(c))
		{
			c = tolower(c);
			cout << "Lower character = " << c << endl;
		}
		// 4) change the case of the letters (upper to lowercase and vice-versa).
	}
	cout << line << " is alphanumeric " << endl;
	cout << "Number of digits is: " << counter << endl;
	cout << "Number of words is: " << wcount << endl;
	
		// 5) Replace any whitespace with a dot ('.').
		// Print the converted text in 4) and 5)
	
	cout << " ****************************************************************************" << endl;
	cout << "Original String : " << line << endl;
	for (auto &c : line)
	{
		if (isspace(c))
		{
			c = '.';
		}
	}
	cout << "Reserved String: " << line << endl;
	
	/*for( i = 0; i >= line.size(); i++)
	{
		if (isspace(line[i]))
		{
			line[i] = '.';
		}
		cout << line[i] << endl;
	}
	//cout << "Reserved String " << line << endl;
	*/
cout << " ****************************************************************************" << endl;

// ****************************************************************************

	return 0;
}
