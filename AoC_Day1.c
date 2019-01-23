#include <stdio.h>
#include <stdlib.h>

int inArray(long val, long *allNums, int size)
{
	int i;
	for (i=0;i<size;i++) //go through all numbers in array
	{
		long b=allNums[i]; //set the array num to a var for readability
		/*
		printf("Check No.: %ld\n",val);
		printf("Array Num: %ld\n",b);
		printf("Array Index: %d\n",i);
		printf("Size: %d\n",size);
		printf("Does %ld = %ld (Array element %ld/%d)? \n",val,b,i,size); */
		if (b==val) //compare var to array var
		{ 
			printf("Found\n");
			return 1; //return true if match is found
		} 
		else
		{
			//printf("no\n");
		}
	}
	return 0;
}

int main()
{
	int solved = 0;
	long baseNum = 0; //initialize the number we'll use to store the count
	FILE *numFile = NULL;
	fopen_s(&numFile,"D:\\Projects\\Programming\\AdventofCode\\input_day1.txt","r"); //Opens input file
	if (numFile == NULL)//Verifies input file exists, exits if not
	{
		printf("Error! opening file");
		exit(-1);
	}	
	int total=0; //initializes a counter, to determine the array we will need.
	long numRead; //initializes int holder for loop
	while (fscanf_s(numFile,"%ld",&numRead)==1) //Scans file for a value, stores it as numread, iterates through them
	{
		total++; //increment counter
	}	
	printf("The file has %d numbers\n",total);
	long* allTotals = malloc(total*sizeof(long)); //create array for totals based on size we got
	long* allNumbers = malloc(total * sizeof(long)); //create array of the file nums, size based on size we got
	printf("Array is %zd element(s)\n\n",_msize(allTotals)/sizeof(long)); //Confirm array completed correctly
	rewind(numFile); //restart file scanning to beginning
	int indexNum = 0;
	baseNum = 0;
	while (fscanf_s(numFile,"%ld",&numRead)==1) //Scans file again for values, stores them in array
	{
		baseNum += numRead;
		//printf("Pass 1,Scanned %ld on line %d, added for new total of %ld\n",numRead,indexNum,baseNum);
		if (inArray(baseNum,allTotals,indexNum)==1)
		{
			printf("%d Found twice on line %d\n",baseNum,indexNum); //readout the number found
			solved = 1;
			break; //stop loop
		}
		allTotals[indexNum] = baseNum; //add new total num to array
		allNumbers[indexNum] = numRead; //add new total num to array
		indexNum++;
	}
	fclose(numFile); //Close the file
	//if solution still not found....
	int pass = 2;
	indexNum = 0;
	while (solved == 0)
	{
		size_t newSize = _msize(allTotals) + (total * sizeof(long));
		allTotals= (long *)realloc(allTotals,newSize );
		for (indexNum = 0; indexNum < total; indexNum++)
		{
			baseNum += allNumbers[indexNum];
			//printf("Pass %d, Scanned %ld on line %d, added for new total of %ld\n", pass, allNumbers[indexNum], indexNum, baseNum);
			if(inArray(baseNum, allTotals, (int)_msize(allTotals)/sizeof(long))==1)
			{
				printf("%d Found twice\n", baseNum); //readout the number found
				solved = 1;
				break; //stop loop
			}
		}
		if (solved == 1)
		{
			break;
		}
		else
		{
			pass++;
			printf("Pass %d, %zd totals checked\n", pass, _msize(allTotals)/sizeof(long));
			//if (pass > 50) { break; }
		}
	}

	printf("after %d lines and %d passes, The total is %d\n", total, pass,baseNum); //readout
	
	free(allTotals); //Free the memory we allocated
	free(allNumbers);
	//char ch; //remaining code allows result to be seen in console before window closes
	printf("Complete\n");
	//scanf_s("%c",&ch,1);
    return 0;
}