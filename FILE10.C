#include <stdio.h>
#include <conio.h>
struct student
{
   int regno,sub1,sub2,sub3,sub4,sub5;
   char name[20];

}s;
main()
{
   FILE *fp=fopen("score.dat","wb");
   char ch;
   clrscr();
   do
   {
      printf("Enter regno name and marks of sub1,sub2,sub3,sub4,sub5:\n");
      scanf("%d%s%d%d%d%d%d",&s.regno,&s.name,&s.sub1,&s.sub2,&s.sub3,&s.sub4,&s.sub5);
     fwrite(&s,sizeof(s),1,fp);
     fflush(stdin);
     printf("Do you want to add more record (y/n)?"); scanf("%c",&ch);
   }while(ch=='y'||ch=='Y');
   fclose(fp);
   getch();
}