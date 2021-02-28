#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void deposit();
void withdrowal();
void password();
void bankbal();
void main()
{
	int a;
	char pass[20],yes;
	int choice;
	printf("!!Walcome ATM Software!!");
	do
	{
	printf("\nEnter Your Password: ");
	fflush(stdin);
	gets(pass);
	a=verify(pass);
	if(a==0)
	{
		printf("Verify\n");
		printf("press 1 for Deposit: \npress 2 for Withdrowal: \npress 3 for password update: \npress 4 for Balance Check: \nEnter Your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				deposit();
				break;
			case 2:
				withdrowal();
				break;
			case 3:
				password();
				break;
			case 4:
				bankbal();
				break;
			default:
				printf("Invild Choice");
		}
	}
	else
	{
		printf("Wrong password");
	}
	
	printf("\nYou want Any other service (press y or Y)(No press any key): ");
	fflush(stdin);
	scanf("%c",&yes);

	}while(yes=='y'||yes=='Y');
}

//function Check Your password 
int verify(char pass[])
{
	FILE *fp;
	char str[50];
	fp=fopen("password.txt","r");
	fgets(str,11,fp);
	return strcmp(str,pass);
	
}

// Deposit finction 
void deposit()
{
	int a;
	char str[10];
	FILE *fp;
	printf("Enter Deposit Amount: ");
	scanf("%d",&a);
	fp=fopen("balance.txt","r");
	fgets(str,11,fp);
//	printf("%s",str);
	fclose(fp);
	fp=fopen("balance.txt","w");
	int b=atoi(str);  //Covert string Into int
	a=a+b;
	sprintf(str,"%d",a);   //covert string into int 
	fputs(str,fp);
	printf("Amount Deposit Sucessfully!!\nYour Account Balance is: %s",str);
	fclose(fp);
}

//Withdrowal function
void withdrowal()
{
	FILE *fp;
	char str[10];
	int a,b;
	printf("Entert Withdrowal Amount: ");
	scanf("%d",&a);
	fp=fopen("balance.txt","r");
	fgets(str,11,fp);
	b=atoi(str);   //conert string into int 
//	printf("%d",b);
	fclose(fp);
	if(a<b)
	{
		a=b-a;
		printf("Amount Withdrowal Sucessfully!\nAccount Balance: %d",a);		
		sprintf(str,"%d",a);
		fopen("balance.txt","w");
		fputs(str,fp);
		fclose(fp);
	}
	else
	{
		printf("Ensufficient Amount!!");
		fopen("balance.txt","r");
		fgets(str,11,fp);
		printf("\nYour Account Balance is: %s",str);
		fclose(fp);
	}
}


//password update function
void password()
{
	FILE *fp;
	char str[20];
	printf("Enter New Password(under 10): ");
	fflush(stdin);
	gets(str);
	if(10>=strlen(str))
	{
		fp=fopen("password.txt","w");
		fputs(str,fp);
		fclose(fp);
		printf("Password Update Sucessfully");
	}
	else
	{
		printf("Password Lenth is Mismatch");
	}
}

void bankbal()
{
	FILE *p;
	char str[20];
	p=fopen("balance.txt","r");
	fgets(str,11,p);
	printf("Account Balance is: %s",str);
}
