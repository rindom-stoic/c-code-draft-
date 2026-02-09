#include <stdio.h>
#include <conio.h>
int main()
{
	FILE *fp;
	int regno,grade;
	char name[25], dob[12], c;
	//clrscr();
	fp=fopen("student.txt", "w");

	do
	{
		printf("Enter the regno, name, class, dob of student:");
		scanf("%d %s %d %s",&regno, name, &grade,dob);

		fprintf(fp,"%d %s %d %s\n",regno, name, grade, dob);
		printf("do you want to add another record (y/n)?");
		fflush(stdin);
		scanf("%c",&c);
	} while (c == 'y' || c == 'Y');
	fclose(fp);

}