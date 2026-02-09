#include <stdio.h>
#include <conio.h>
main()
{
	FILE *fp;
	int regno,grade,count=0;
	char name[25], dob[12];
	clrscr();
	fp=fopen("student.txt", "r");
	printf("regno \t name \t class \t DOB \t");
	while(fscanf(fp,"%d %s %d %s",&regno, name, &grade, dob)!=EOF)
	{

		printf("\n%d %s %d %s",regno, name, grade, dob);
		count++;
	}
	fclose(fp);
	printf("\nTotal Numer of record is %d",count);
	getch();

}