#include <stdio.h>
#include <conio.h>
//#include <stdlib.h>
struct employee
{
   int emp_code;
   char emp_name[25],post[20];
   long int bsal;
}e;

void add_record(void);
void disp_record (void);
void search_record (void);
void update_record (void);
void delete_record (void);
main()
{
  int n;
  while(1)
  {
     //to display menu structure
     clrscr();
     printf("1.Add record:");
     printf("\n2.Display record:");
     printf("\n3.Search record:");
     printf("\n4.Upgrade record:");
     printf("\n5.Delete record:");
     printf("\n6.Exit:");
     printf("\nEnter your choice:");scanf("%d",&n);
     switch(n)
     {
         case 1:
	    	//to add record
		    add_record();
	 	 break;
         case 2:
			//to display record
			disp_record();
		 break;
         case 3:
			//to search record
			search_record();
		 break;
         case 4:
			//to update record
			update_record();
		 break;
         case 5:
			//to delete record
			delete_record();
		 break;
         default:
			exit(0);//to terminate the process
       }
       getch();
    }
  }//end of program
void add_record(void)
{
     FILE *f=fopen("employee.dat","ab");
     char ch;
     do
       {
         printf("Enter emp_code,Name,post and bsal:");
         scanf("%d%s%s%ld",&e.emp_code,&e.emp_name,&e.post,&e.bsal);
         fwrite(&e,sizeof(e),1,f);
          fflush(stdin);
          printf("\nDo You want to add more records (y/n)?"); scanf("%c",&ch);
        }while(ch=='y'|| ch=='Y');
      fclose(f);
}//end of program
void disp_record(void)
{
     FILE *fp=fopen("employee.dat","rb");
     printf("\n emp_code \t name \t post \t bsal");
     while(fread(&e,sizeof(e),1,fp)==1)
     {
       printf("\n %d \t %s \t %s \t %ld",e.emp_code,e.emp_name,e.post,e.bsal);
     }
     fclose(fp);
}
void search_record(void)
{
     FILE *fp=fopen("employee.dat","rb");
     int emp_id,found=0;
     printf("Enter the emp_code of the employee whose record you want to search:");
     scanf("%d",&emp_id);
     while(fread(&e,sizeof(e),1,fp)==1)
       {
	 if(e.emp_code==emp_id)
	     {
	          found=1;
	          break;
	     }
       }
      fclose(fp);
      if(found==1)
     {
       printf("\n the record is found and that is :");
       printf("\n emp_code \t name \t post \t bsal");
       printf("\n %d \t %s \t %s \t %ld",e.emp_code,e.emp_name,e.post,e.bsal);
     }
     else
     {
       printf("\n the record is not found");
     }
}
void update_record (void)
{
   FILE *fp,*fpt;
   char yn;
   fp=fopen("employee.dat","rb");
   fpt=fopen("temp.dat","wb");
   while(fread(&e,sizeof(e),1,fp)==1)
   {
     printf("\nemp_code:%d",e.emp_code);
     printf("\nName:%s",e.emp_name);
     printf("\npost:%s",e.post);
     printf("\nBsal:%ld",e.bsal);
     fflush(stdin);
     printf("\nDo you want to edit record (y/n)?");scanf("%c",&yn);
     if(yn=='y'|| yn=='Y')
     {
       printf("Enter new record of emp_code,name,post,bsal");
       scanf("%d%s%s%ld",&e.emp_code,&e.emp_name,&e.post,&e.bsal);
     }
     fwrite(&e,sizeof(e),1,fpt);
   }
   fclose(fp); fclose(fpt);
   remove("employee.dat");
   rename("temp.dat","employee.dat");
}//end of program
void delete_record(void)
{
  FILE *fp,*fpt;
  int emp_id,found=0;
  fp=fopen("employee.dat","rb");
  fpt=fopen("temp.dat","wb");
  printf("Enter the employee code whose record do you want to delete:");
  scanf("%d",&emp_id);
  while(fread(&e,sizeof(e),1,fp)==1)
  {
    if(e.emp_code==emp_id)
     {

       found=1;
     }
    else
    {
      fwrite(&e,sizeof(e),1,fpt);
    }
  }

  fclose(fp);
  fclose(fpt);
  remove("employee.dat");
  rename("temp.dat","employee.dat");
  if(found==1)
   {
     printf("\n the record is deleted from file");
   }
  else
  {
    printf("\n the record is not found");
  }

getch();
}

