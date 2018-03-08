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
double* offset( int * array, double offsetValue);
double* scale( int * array, double scaleValue);
void saveFile(char* newFilename, double* numArray, double val);
double average( int* data );
int max(int data[],int size);

//Global Variable
int arrayLength, numMax;
char neww[15];

int main( int argc, char* argv[])
{
	// Command Line
	int n;
	double o, s;
	int i = 0;
	
	int *Array;
	

	if(argc <= 7)
	{
		//cout << argc << endl;
		
		for( i = 1; i < argc; i++ )
		{			
			if((argv[i][0] == '-') && (argv[i][1] == 'n'))// checks for n
			{
				n = atoi(argv[i+1]);
				i++;
				cout << "File value: " << n << endl;
				Array = readfile(n);
				
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
				
				double * offsetArray;
				char offsetFilename[20];
				sprintf(offsetFilename, "Offset_data_%02d.txt", n);
				offsetArray = offset( Array, o );
				//cout << *(offsetArray) << endl;
				saveFile(offsetFilename, offsetArray, o);
				free(offsetArray);
				continue;
			}
			else if((argv[i][0] != '-') && (argv[i][1] != 'o'))
			{
				cout << "Wrong option for offset: " << argv[i] << endl;
				//return 1;
			}
			
			//check for Scale
			if((argv[i][0] == '-') && (argv[i][1] == 's')) // checks for o
			{
				s = atoi(argv[i+1]);
				cout << "scale value: " << s << endl;
				
				double * ScaleArray;
				char ScaleFilename[20];
				sprintf(ScaleFilename, "Scaled_data_%02d.txt", n);
				ScaleArray = scale(Array, s );
				//cout << *(ScaleArray) << endl;
				saveFile(ScaleFilename, ScaleArray, s);
				free(ScaleArray);
				continue;
			}
			else if((argv[i][0] != '-') && (argv[i][1] != 's'))
			{
				cout << "Wrong option for scale: " << argv[i] << endl;
				
			}
				//cout << i << endl;
				
			// checking for rename
			if((argv[i][0] == '-') && (argv[i][1] == 'r')) 
			{
				cout << "New Name: " << argv[i+1] << endl;
				continue;
			}
			else if ((argv[i][0] != '-') && (argv[i][1] != 'r'))
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
			else if((argv[i][0] != '-') && (argv[i][1] != 'h')) 
			{
				cout << "Wrong option for help: " << argv[i] << endl;
			}
		}
	}
	else
		{
			manual();
		}
	
	cout <<"Average value is:" << average( Array ) << endl;
	cout <<"Maximum values is:" << max(Array,arrayLength) << endl;
	sprintf(neww,"Statistic_data_%d.txt", n);
	FILE* offset = fopen(neww,"w");
	fprintf(offset, "%.2f %d\n",average( Array ) , max(Array,arrayLength) );
	
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
	if (fp != NULL) 
	{
		fscanf(fp, "%d %d\n", &arrayLength, &numMax); //read in number of values and maximum value
	}
	else
	{
		cout << "File cannot be opened\n";
	}
	dataArray =  (int*) calloc(arrayLength, sizeof(int)); //allocate memory for number of integers
	
	while( !feof(fp))
	{
		fscanf(fp, "%d", &dataArray[x]);
		//cout << (int) dataArray[x] << endl;  //scan values into integer array
		x++;
	}
	fclose(fp);
	
	return dataArray;
}

/*Outputs the offset values into the correct file*/
double* offset(int * array, double offsetValue)
{
	int i;
	double * newArray = (double * ) malloc( sizeof( double ) * arrayLength );

	for(i = 0; i < arrayLength; i++)
	{
		newArray[i] = ( (double) array[i] + offsetValue);
	}
	
	cout << "length of Array: "<< arrayLength << endl;
	//cout << "offset + inivalue:" << *(newArray) << endl; /// for some odd reason my offset is not adding to the array
	
	return newArray;
}

double* scale( int * array, double scaleValue)
{
	int i;
	double * newArray = (double *) malloc( sizeof( double ) * arrayLength ) ;
	
	for(i = 0; i < arrayLength; i++)
	{
		newArray[i] = ( ( (double) array[i] ) * (scaleValue) );
	}
	
	return newArray;
}

void saveFile(char* newFilename, double* numArray, double val)
{
	FILE* fp;
	int i;
	fp = fopen(newFilename, "w+");
	fprintf(fp, "%d %.4lf\n", arrayLength, val);
	for(i = 0; i < arrayLength; i++)
	{
		fprintf(fp, "%.4lf\n", numArray[i]);
		cout << numArray[i] << endl;  //scan values into integer array
		i++;
	}
	fclose(fp);
}

double average( int * data )
{
	int i = 0;
	double sum = 0;
	
	for( i = 0; i < arrayLength; i++ )
	{
		sum += (double) data[i];
	}
	
	return (sum / arrayLength);
}

int max(int data[],int size) // finds max of the data
{
	int i = 0;
	int max = 0;
	int filenumber;
	double buffer = 0;
	int j = 0;
	for(i = 1;i < size+1; i++)
	{
		if(data[i] > max)
		max = data[i];
	}
	sprintf(neww,"Normal_data_%d.txt",filenumber);
	FILE* normal = fopen(neww,"w");
	fprintf(normal,"%d %d\n",size, max);

	for(j = 1;j < size+1; j++)
	{
		buffer = (double)data[j]/ max;
		fprintf(normal, "%.2f\n",buffer);
	}

	return max;
}


