#include <stdio.h>
#include <conio.h>
int main()
{
	FILE *fp;
	int num[10],i,value,sum=0;
	clrscr();
	//to read ten integer

	for(i=0;i<10;i++)
	{
		printf("Enter %d integer:",i+1);
		scanf("%d",&num[i]);
	}
    //to write in text file
    fp=fopen("num.txt","w");
    for(i=0;i<10;i++)
    {
	fprintf(fp,"%d ", num[i]);
	}
	fclose(fp);
	//to read text file from disk
	fp=fopen("num.txt","r");
	printf("Number from disk :\n");
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%d ",&value);
		printf("%d ",value);
		sum+=value;
	}
	fclose(fp);
	//to dispaly sum
	printf("The total sum is %d ",sum);
	getch();
}