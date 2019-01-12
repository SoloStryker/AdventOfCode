#include <stdio.h>
#include <stdlib.h>

int inArray(long val, long *allNums, int size)
{
	int i;
	for (i=0;i<size;i++) //go through all numbers in array
	{
		long b=allNums[i]; //set the array num to a var for readability
		printf("Check No.: %I\n",val);
		printf("Array Num: %I\n",b);
		printf("Array Index: %d\n",i);
		printf("Size: %d\n",size);
		printf("Does %I = %I (Array element %I/%d)? \n",val,b,i,size);
		if (b==val) //compare var to array var
		{ 
			printf("Yes\n");
			return 1; //return true if match is found
		} 
		else
		{
			printf("no\n");
		}
	}
	return 0;
}

int main()
{
	long baseNum = 0; //initialize the number we'll use to store the count
	FILE *numFile=fopen("D:\\Projects\\Programming\\input.txt","r"); //Opens input file
	if (numFile == NULL)//Verifies input file exists, exits if not
	{
		printf("Error! opening file");
		exit(-1);
	}	
	int total=0; //initializes a counter, to determine the array we will need.
	long numRead; //initializes int holder for loop
	while (fscanf(numFile,"%I",&numRead)==1) //Scans file for a value, stores it as numread, iterates through them
	{
		baseNum+=numRead; //add detected number to counting var
		total++; //increment counter
	}	
	printf("The file has %d numbers\n",total);//a readout
	long *allNumbers = malloc(total*sizeof(long)); //create array based on size we got (success?)
	printf("Array is %d",sizeof(allNumbers)/sizeof(long));
	rewind(numFile); //restart file scanning to beginning
	/*
	while (fscanf(numFile,"%I",&numRead)==1) //Scans file again for values, stores them in array
	{
		allNumbers+=numRead; //add scanned num to array
		//printf("Numbers: %d",allNumbers); //console tracking
		printf("\nScanned %I\n",numRead);
		if (inArray(numRead,allNumbers,sizeof(allNumbers)/sizeof(long))==1)
		{
			printf("%d Found twice",numRead); //readout the number found
			break; //stop loop
		}
		
	}	
	*/
	
    printf("after %d lines, The total is %d\n",total,baseNum); //readout
	fclose(numFile); //Close the file
	free(allNumbers); //Free the memory we allocated
	
	char ch; //remaining code allows result to be seen in console before window closes
	printf("Complete");
	scanf("%c",&ch);
    return 0;
}