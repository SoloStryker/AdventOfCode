#include <stdio.h>
#include <stdlib.h>

int main()
{ /*
	OpenFileDialog ofd = new OpenFileDialog();
	ofd.Title = "Open a Text File";
	ofd.Filter = "Text Files (*.txt) | *.txt | All Files(*.*) | *.*"; //Here you can filter which all files you wanted allow to open
	DialogResult dr = ofd.ShowDialog();
	if (dr == DialogResult.OK)
	{
		StreamReader sr = new StreamReader(ofd.FileName);
		txtEx.Text = sr.ReadToEnd();
		sr.Close();
	}*/
	FILE *numFile = NULL;
	fopen_s(&numFile, "D:\\Projects\\Programming\\AdventofCode\\input_day2.txt", "r"); //Opens input file
	if (numFile == NULL)//Verifies input file exists, exits if not
	{
		printf("Error! opening file");
		exit(-1);
	}
	//File is assumed to be a list of codes, all equal length
	//First scan through file to get # of codes and length, to allocate containers
	char codeRead[50];
	int totalEntries = 0; //initializes a counter, to determine the array we will need.
	while (fscanf_s(numFile, "%c", &codeRead) == 1) //Scans file for a value, stores it as codeRead, iterates through them
	{
		totalEntries++; //increment counter
	}

	printf("%d found", totalEntries);
	fclose(numFile); //Close the file
}