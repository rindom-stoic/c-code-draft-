#include <stdio.h>
#include <conio.h>
main()
{
  FILE *fp=fopen("moral.txt","r");
  char s[80];
  clrscr();
  fgets(s,80,fp);
  fclose(fp);
  printf("The string retrived from moral.txt is :\n");
  printf("%s",s);
  getch();
}