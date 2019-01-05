#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int baseNum = 0; //initialize the number we'll use to count
	FILE *fptr;
	
	if ((fptr = fopen("D:\\Projects\\Programming\\input.txt","r")) == NULL)
	{
		// Program exits if the file pointer returns NULL.
		printf("Error! opening file");
		exit(1);
	}
	
	//fscanf(fptr,"%d",&addList[i]);
	
    printf("The result is %d\n",baseNum);
	char ch;
	scanf("%c",&ch);
	fclose(fptr);
    return 0;
}