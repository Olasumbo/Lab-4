//============================================================================
// Name        : Lab4_part2.cpp
// Author      : Ola
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;

// Modify to take arguments
//-n  File #
//-o: offset value (value needed)
//-s: scale factor (value needed)
//-r: Rename files (name needed)
//-h: Help (display how the program should be called, including the different input options)

int *readfile(int num);
void manual();

//Global Variable
int arrayLength, numMax;

int main( int argc, char* argv[])
{
	// Command Line
	int n, o, s;
	int i =0;
	
	int *Array;
	

	if(argc <= 7)
	{
		//cout << argc << endl;
		
		for( i = 1; i < argc; i++ )
		{
			//cout << i << endl;
			
			if((argv[i][0] == '-') && (argv[i][1] == 'n'))// checks for n
			{
				n = atoi(argv[i+1]);
				i++;
				cout << "File value: " << n << endl;
				Array = readfile(n);
				cout << (Array) << endl;
				continue;
			}
			else if((argv[i][0] != '-') && (argv[i][1] != 'n'))
			{
				cout << "Wrong option for file number: " << argv[i] << endl;
				//return 1;
			}
			//cout << i << endl;
			// check for offset
			if((argv[i][0] == '-') && (argv[i][1] == 'o')) // checks for o
			{
				o = atoi(argv[i+1]);
				i++;
				cout << "Offset value: " << o << endl;
				continue;
			}
			else if((argv[i][0] != '-') && (argv[i][1] != 'n'))
			{
				cout << "Wrong option for offset: " << argv[i] << endl;
				//return 1;
			}
			//cout << i << endl;
			//check for Scale
			if((argv[i][0] == '-') && (argv[i][1] == 's')) // checks for o
			{
				s = atoi(argv[i+1]);
				cout << "scale value: " << s << endl;
				continue;
			}
			else if((argv[i][0] != '-') && (argv[i][1] != 'n'))
			{
				cout << "Wrong option for scale: " << argv[i] << endl;
				//return 1;
			}
				//cout << i << endl;
				
			// checking for rename
			if((argv[i][0] == '-') && (argv[i][1] == 'r')) 
			{
				cout << "New Name: " << argv[i+1] << endl;
				continue;
			}
			else if ((argv[i][0] != '-') && (argv[i][1] != 'n'))
			{
				cout << "Wrong option for renaming: " << argv[i] << endl;
				//return 1;
			}
				//cout << i << endl;
			// help function
			if((argv[i][0] == '-') && (argv[i][1] == 'h')) 
			{
				cout << "This are the different ways of inputing your command line,-n/-o/-s/-r can be interchanges nonetheless a number always have to come after it " << endl; 
				void manual();
				continue;
			}
			else if((argv[i][0] != '-') && (argv[i][1] != 'n')) 
			{
				cout << "Wrong option for help: " << argv[i] << endl;
			}
		}
	}
	else
		{
			manual();
		}
		
	
	return 0;
}
void manual()
{
	cout << "\nUsage: " <<"./exe -n IntValue " <<endl;
	cout << "\nUsage: " <<"./exe -n IntValue -o IntValue "<<endl;
	cout << "\nUsage: " <<"./exe -n IntValue -s IntValue "<<endl;		
	cout << "\nUsage: " <<"./exe -n IntValue -h IntValue "<<endl;
	cout << "\nUsage: " <<"./exe -n IntValue -r IntValue "<< endl;
}
// Will read and creates a space for the array length and make sure the numbers in the array are not greater than numMax
int *readfile(int num) //num is the file number
{
	int* dataArray;
	int x = 0;
	FILE *fp;
	char stringnum[3];
	char filename[16] = "Raw_data_";

	num < 10 ? sprintf(stringnum, "0%d", num) : sprintf(stringnum, "%d", num); //convert given integer into string for filename
	strcat(filename, stringnum);
	strcat(filename, ".txt");

	fp = fopen(filename, "r");
	fscanf(fp, "%d %d\n", &arrayLength, &numMax); //read in number of values and maximum value
	dataArray =  (int*) calloc(arrayLength, sizeof(int)); //allocate memory for number of integers
	while(fscanf(fp, "%d", &dataArray[x++]) != EOF)
	{
		//scan values into integer array
	}
	fclose(fp);
	
	return dataArray;
}

/*
void offset_scale(char* str, int offsetnum)// adds the raw data with offset/scales selected by user
{
	
}
 */
