#include <stdio.h>
main()
{
	FILE *fp,*fpt;
	char filename[25],ch,c;
	clrscr();
	printf("Enter the name of file:");
	gets(filename);
	fp=fopen(filename,"r");
	fpt=fopen("textcopy.txt","w");
	if(fp==NULL)
	{
		printf("\nFile name %s is not found",filename);
		exit(0);//to terminate program 
	}
	 while ((ch = fgetc(fp)) != EOF)
	{
        fputc(ch, fpt);
    }

    printf("File copied successfully.\n");
    fclose(fp);
    fclose(fpt);
    //to read copied file
    fpt=fopen("textcopy.txt","r");
    printf("\nThe content of the file is :\n");
    while((c=fgetc(fpt))!=EOF)
    {
    	putchar(c);
	}
	fclose(fpt);
}