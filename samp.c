#include <stdio.h>
#include <stdlib.h>

int main()
{
	int baseNum = 0; //initialize the number we'll use to count
	FILE *numFile=fopen("D:\\Projects\\Programming\\input.txt","r");
	if (numFile == NULL)
	{
		printf("Error! opening file");
		exit(-1);
	}	
	int total=0;
	int numRead;
	while (fscanf(numFile,"%d",&numRead)==1)
	{
		baseNum+=numRead;
		total++;
	}	
	
    printf("after %d lines, The result is %d\n",total,baseNum);
	char ch;
	scanf("%c",&ch);
	fclose(numFile);
    return 0;
}