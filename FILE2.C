#include <stdio.h>
#include <conio.h>
#include <ctype.h>
main()
{
  FILE *fp;
  int n=0;
  char c;
  fp=fopen("info.txt","r");
  clrscr();
  do
  {
     c=getc(fp);
     if(c==' ')
     {
       n++;
     }
     putc(c,fp);
     putchar(toupper(c));
  }while(c!='\n');
  fclose(fp);
  printf("The total numberof words in the sentence is %d",n+1);
  getch();
}
