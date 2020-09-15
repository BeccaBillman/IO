/* Becca Billman, Assignment File I/O,COP 3223C, CR02, 06/18/2018*/

#include <stdio.h>

//Main Function
int main()
{

	//variable declarations
	FILE *ifp, *ofp;
	
	//using a two dimensional array, character variables 
    char infile[20] = "input.txt";
    char outfile[20] = "output.txt";
    char lines[100][256];

	//int varibales 
    int numLines = 0;
    int i,j;

	//input
	ifp = fopen(infile, "r");
	
	if(ifp == NULL)
	{
        //Print this output if the file cannot be read
        printf("ERROR: could not open input file %s for reading \n", infile);
        return 1;
	}

	//output
	ofp = fopen(outfile, "w");
	
	if(ofp == NULL)
	{
        //Print if this the file cannot be read
        printf("ERROR: could not open input file %s for reading \n", outfile);
        return 1;
	}

	//to read the input file
	printf("Reading input file\n");


	while(!feof(ifp))
	{
        
        fgets(lines[numLines], 256, ifp);
        numLines++;
	}

	fclose(ifp);

	printf("File %s has %d lines\n", infile, numLines);

	for(i = 0 ;i < numLines; i++)

	puts(lines[i]);

	printf("\nWriting to output file %s\n", outfile);

	for(i = 0, j = 1; i < numLines; i++)
	{
        //we dont want the 5th line thats why I used 4
        if(i == 4)
        continue;
        fprintf(ofp, "Line %d: %s", j, lines[i]);
        j++;
	}

	fclose(ofp);

	printf("Generated output in %s\n", outfile);

	//end main
	return 0;
}