#include <stdio.h>
#include <conio.h>
#define max 100
int main()
{
	FILE *fp,*fpt,*fptr;
	int num[max],i,n,value,odd,even;
	clrscr();
	//to read ten integer
	printf("How many integer do you want to enter (max 100)?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter %d integer:",i+1);
		scanf("%d",&num[i]);
	}
    //to write in text file
    fp=fopen("integer.txt","w");
    fpt=fopen("odd.txt","w");
    fptr=fopen("even.txt","w");
    for(i=0;i<n;i++)
    {
	fprintf(fp,"%d ", num[i]);
	//to seperate
	if(num[i] % 2==0)
	{
	   fprintf(fptr,"%d ",num[i]);
	}
	else
	{
	   fprintf(fpt,"%d ",num[i]);
	}

    }
	fclose(fp);
	fclose(fpt);
	fclose(fptr);
	//to read text file from disk
	fp=fopen("integer.txt","r");
	fpt=fopen("odd.txt","r");
	fptr=fopen("even.txt","r");
	printf("Number from disk :\n");
	while(fscanf(fp, "%d", &value) != EOF)
	{
		printf("%d ",value);
	}
	printf("\nOdd Number from disk :\n");
	while(fscanf(fpt, "%d ", &value) != EOF)
	{
		printf(" %d ",value);
	}
	printf("\nEven Number from disk :\n");
	while(fscanf(fptr, "%d ", &value) != EOF)
	{
		printf(" %d ",value);

	}
	fclose(fp);
	fclose(fpt);
	fclose(fptr);
	getch();
}