#include <stdio.h>
#include <conio.h>
main()
{
	FILE *fp;
	char c;
	clrscr();
	fp=fopen("info.txt","w");
	do
	{
		c=getchar();
		putc(c,fp);
	}while(c!='\n');
	fclose(fp);
}