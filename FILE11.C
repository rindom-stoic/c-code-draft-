#include <stdio.h>
#include <conio.h>
struct student
{
   int regno,sub1,sub2,sub3,sub4,sub5;
   char name[20];

}s;
main()
{
   FILE *fp=fopen("score.dat","rb");
   int total; float per;
   char ch;
   clrscr();
   printf("regno \t name \t sub1 \t sub2 \t sub3 \t sub4 \t sub5 \t total \t percent\n");
   //to retrive each record and display
   while (fread(&s,sizeof(s),1,fp)==1)
   {
      total=s.sub1+s.sub2+s.sub3+s.sub4+s.sub5;
      per=total/500.0*100.00;
      printf("\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f",s.regno,s.name,s.sub1,s.sub2,s.sub3,s.sub4,s.sub5,total,per);
   }
   fclose(fp);
   getch();
}
