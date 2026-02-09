#include <stdio.h>
#include <conio.h>
main()
{
  FILE *fp=fopen("moral.txt","w");
  char s[]="Honesty is the best policy";
  fputs(s,fp);
  fclose(fp);
}