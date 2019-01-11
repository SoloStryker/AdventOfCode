#include <stdio.h>
#include <stdlib.h>

int main()
{
	int baseNum = 0; //initialize the number we'll use to count
	FILE *numFile=fopen("D:\\Projects\\Programming\\input.txt","r"); //Opens input file
	if (numFile == NULL)//Verifies input file exists, exits if not
	{
		printf("Error! opening file");
		exit(-1);
	}	
	int total=0; //initializes a counter, to determine the array we will need.
	int numRead; //initializes int holder for loop
	while (fscanf(numFile,"%d",&numRead)==1) //Scans file for a value, stores it as numread, iterates through them
	{
		baseNum+=numRead; //add detected number to counting var
		total++; //increment counter
	}	
	printf("The file has %d numbers\n",total);//a readout
	
    printf("after %d lines, The result is %d\n",total,baseNum); //readout
	fclose(numFile); //Close the file
	char ch; //remaining code allows result to be seen in console before window closes
	scanf("%c",&ch);
    return 0;
}