#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void add_new_user();
void deposit();
void withdraw();
void check_bal();  
void menu();
void thanku();
float interest(float,float,float);
void fordelay(int);
int total_days(int,int,int,int,int,int);
int valid_date(int , int , int );
void back_to_menu();


struct date
{
    int month,day,year;
};
struct 
{
	char name[60];
    int acc_no;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
}add,check;

int i,j;
int new_month,new_day,new_year;
int main_exit,test=0;
float balance;

int main()
{ 
	
	char pass[10],password[10]="pass";
	int i=0;
	add.acc_no=1000;
	pass_try:
    printf("\n\n\t\t\t========================================\n\t\t\t*\t   BANK MANAGEMENT SYSTEM\t*\n\t\t\t========================================\n\n\t\t\t\t\t Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s",pass);
    if(strcmp(pass,password)==0)
    {
		printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(". ");
        }
        printf("\n");
        system("pause");
		system("cls");
        menu();  
	}
    else
    {   
		printf("\n\nWrong password!!\a\a\a");
        login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
        {
			system("cls");
			goto pass_try;
        }
        else if(main_exit==0)
        {
            thanku();	
            system("cls");
            exit(0);
		}
        else
        {
			printf("\nInvalid!");
            fordelay(1000000000);
            system("cls");
            goto login_try;
        }
	}
    return 0;
}

void fordelay(int j)
{   
	int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void menu(void)
{
	int option_chooser;
	printf("\n\t\t\tBANK MANAGEMENT SYSTEM");	
	printf("\n\n\t\t==========Welcome to Main Menu==========\n\n");
	printf("\n\t\t 1 .  Create a new account\n");
    printf("\n\t\t 2 .  Deposit\n");
    printf("\n\t\t 3 .  Withdraw\n");
    printf("\n\t\t 4 .  Check Balance\n");
    printf("\n\t\t 5 .  Exit\n\n");
    printf("\n\t\t----Please choose one of the options below----\n");
    scanf("%d",&option_chooser);
    switch(option_chooser)
    {
    	case 1: add_new_user();
    			break;
    			
    	case 2: deposit();
				break;
				
		case 3: withdraw();
				break;
				
		case 4: check_bal();
				break;
				
		case 5: thanku();
				exit(0);
				break;	
	}
}

void add_new_user()
{
	int acc_type_choice;
    FILE *ptr;
	ptr=fopen("record.dat","a+");
   	system("cls");
    printf("\t\t\t==== ADD RECORD  ====");
    add.acc_no+=1;
   	printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
	printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit (Note : Minimum balance should be Rs 1000): Rs ");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t1. Saving\n\t2. Current\n\t3. Fixed1(for 1 year)\n\t4. Fixed2(for 2 years)\n\t5. Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%d",&acc_type_choice);
    switch(acc_type_choice)
    {
    	case 1:
    		strcpy(add.acc_type,"saving");
    		break;
    	case 2:
			strcpy(add.acc_type,"current");
			break;	
		case 3:
			strcpy(add.acc_type,"fixed1");
			break;	
		case 4:
			strcpy(add.acc_type,"fixed2");
			break;	
		case 5:
			strcpy(add.acc_type,"fixed3");
			break;	
	}
    fprintf(ptr,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
	fclose(ptr);
    printf("\nAccount created successfully!");
    printf("\n\n----Your account number : %d----",add.acc_no);
    printf("\nFor accessing your account, kindly please note your account number. \n\t\t--Thank you for choosing us.--");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
    {
		thanku();
        exit(0);
    }
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}

void deposit()
{
	float amt;
	FILE *old;
    FILE *newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
	
    printf("Enter the account number:");
    scanf("%d",&check.acc_no);
        
	while(fscanf(old,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==check.acc_no)
		{
			test=1;
			if(strcmp(add.acc_type,"fixed1")==0||strcmp(add.acc_type,"fixed2")==0||strcmp(add.acc_type,"fixed3")==0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
            }
            else
			{
				printf("\n\n----Current balance : Rs %f----",add.amt);
				printf("\n\n\tEnter the amount you want to deposit:Rs ");
                scanf("%f",&check.amt);
                    
                add.amt+=check.amt;
                 
                fprintf(newrec,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\n----Deposited successfully!----");
                    
                printf("\n\n----New current balance : Rs %f----\n",add.amt);
            }                      
        }
        else
        {
            fprintf(newrec,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		}
	}
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    back_to_menu();		
}

void withdraw()
{   
	float y,diff,retri_amt;
	int test=0,confirm=0;
	FILE *old;
    FILE *newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
	
    printf("Enter the account number:");
    scanf("%d",&check.acc_no);
	while (fscanf(old,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if(add.acc_no==check.acc_no)
		{
			test=1;
			if(strcmp(add.acc_type,"fixed1")==0||strcmp(add.acc_type,"fixed2")==0||strcmp(add.acc_type,"fixed3")==0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu();
            }
            else
			{
				if(add.amt == 1000)
				{
					printf("\n----You don't have sufficient balance in your account----\n");
        			printf("\n----Your Balance is: Rs %.2f\n\n", add.amt);
				}
				else
				{
				
					printf("\nEnter the amount you want to withdraw: Rs ");
	                scanf("%f",&check.amt);
	                diff=add.amt-check.amt;
	                if (diff >= 1000)
					{
						printf("\nConfirm your withdraw amount of Rs %.2f\n",check.amt);
						printf("Press '1' to withdraw or Press '0' to discard the process : ");
						scanf("%d",&confirm);
						if(confirm == 1)
						{
	        				add.amt-=check.amt;
	        				fprintf(newrec,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
	        				printf("\n\nWithdraw successfull!");
	        				printf("\n\n----Your New Balance is: Rs %.2f\n\n", add.amt);
	        			}
	        			else
	        				printf("\nProcess failed !\a");
	    			}
	    			else if(diff < 1000)
	    			{
	    				y=1000-diff;
	    				retri_amt = check.amt-y;
	    				printf("\n----You don't have sufficient balance in your account----\n");
	        			printf("\n----Your Balance is: Rs %.2f\n\n", add.amt);
						printf("\nDo you want to withdraw an amount of Rs %.2f\n",retri_amt);
						printf("\n\tPress '1' to withdraw or Press '0' to discard the process : ");
						scanf("%d",&confirm);
						if(confirm == 1)
						{
	        				add.amt-=retri_amt;
	    					fprintf(newrec,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
	        				printf("\n\nWithdraw successfull!");
	        				printf("\n\n----Your New Balance is: Rs %.2f\n\n", add.amt);
	        			}
	        			else
	        				printf("\nProcess failed !\a");
						
					}
								
        	  }//outer else
            }      
        }
        else
    	{
            fprintf(newrec,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");
	back_to_menu();		
}

void check_bal()
{
	FILE *ptr;
    int choice;
    float balance,tot_period,rate=6;
     
    time_t t;
    float intrst;
    char currnt[30];
    int day,month,year;
    ptr=fopen("record.dat","r");
    printf("Enter the account number:");
    scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {  
				system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nType Of Account:%s \nBALANCE:Rs %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmp(add.acc_type,"fixed1")==0)
				{
                    tot_period=365;
                     
                    intrst=interest(tot_period,add.amt,rate);
                    printf("Interest for 1 years : Rs %f",intrst);
                    printf("\n\n\t---- Your current balance : Rs %f",add.amt);
                }
                else if(strcmp(add.acc_type,"fixed2")==0)
                {
                    tot_period=365*2;
                       
                    intrst=interest(tot_period,add.amt,rate);
                    printf("Interest for 2 years : Rs %f",intrst);
                    printf("\n\n\t---- Your current balance : Rs %f",add.amt);
                }
                else if(strcmp(add.acc_type,"fixed3")==0)
                {
                    tot_period=365*3;
                        
                    intrst=interest(tot_period,add.amt,rate);
                    printf("Interest for 3 years : Rs %f",intrst);
                    printf("\n\n\t---- Your current balance : Rs %f",add.amt);
                }
                else if(strcmp(add.acc_type,"saving")==0)
                {	
					time_t t=time(NULL);
					struct tm tm=*localtime(&t);
					sprintf(currnt,"%d/%d/%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
						
					new_month=(tm.tm_mon+1);
					new_day=tm.tm_mday;
					new_year=(tm.tm_year+1900);
							
					day=add.deposit.day;
					month=add.deposit.month;
					year=add.deposit.year;
			
					tot_period=total_days(day,month,year,new_day,new_month,new_year);
						                     
                    intrst=interest(tot_period,add.amt,rate);
                    printf("\n\nYou will get Rs %.2f as interest on %d/%d/%d",intrst,new_day,new_month,new_year);
                    printf("\n\n\t---- Your current balance : Rs %f",add.amt);
                }
                else if(strcmp(add.acc_type,"current")==0)
                {
                    printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    
    fclose(ptr);
    back_to_menu();
    
}

float interest(float t,float amount,float rate)
{
    FILE *ptr=fopen("record.dat","a+");
    float SI,initial,per_day;
    initial=(amount*(rate/100));
    per_day=initial/365;
	SI=per_day*t;
	add.amt=add.amt+SI;
	fprintf(ptr,"%f",add.amt); 
    return SI;
	fclose(ptr);
}

void thanku()
{
	int x;
	double y;
	char text1[]="\n\t\tTHANK YOU FOR VISITING.$\n";
	for(x=0; text1[x]!='$'; x++)
   	{
    	printf("%c",text1[x]);
      	for(y=0; y<=8888888; y++);
   	}
}

int total_days(int days1,int month1,int years1,int days2,int month2,int years2)
{
	int day_diff, mon_diff, year_diff;     
    int day1=days1;
	int mon1=month1;
    int year1=years1;
    int day2=days2;
    int mon2=month2;
    int year2=years2;
    
    if(!valid_date(day1, mon1, year1))
    {
        printf("First date is invalid.\n");        
    }

    if(!valid_date(day2, mon2, year2))
    {
        printf("Second date is invalid.\n");
        return 0;
    }       
    
    if(day2 < day1)
    {      
        // borrow days from february
        if (mon2 == 3)
        {
            //  check whether year is a leap year
            if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) 
            {
                day2 += 29;
            }

            else
            {
                day2 += 28;
            }                        
        }

        // borrow days from April or June or September or November
        else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) 
        {
           day2 += 30; 
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           day2 += 31;
        }

        mon2 = mon2 - 1;
    }

    if (mon2 < mon1)
    {
        mon2 += 12;
        year2 -= 1;
    }       

    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;

    return ((year_diff*365)+(mon_diff*30)+day_diff); 
}
// function to check whether a date is valid or not
int valid_date(int day, int mon, int year)    
{
    int is_valid = 1, is_leap = 0;

    if (year >= 1800 && year <= 9999) 
    {

        //  check whether year is a leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
        {
            is_leap = 1;
        }

        // check whether mon is between 1 and 12
        if(mon >= 1 && mon <= 12)
        {
            // check for days in feb
            if (mon == 2)
            {
                if (is_leap && day == 29) 
                {
                    is_valid = 1;
                }
                else if(day > 28) 
                {
                    is_valid = 0;
                }
            }
            // check for days in April, June, September and November
            else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) 
            {
                if (day > 30)
                {
                    is_valid = 0;
                }
            }
            // check for days in rest of the months 
            // i.e Jan, Mar, May, July, Aug, Oct, Dec
            else if(day > 31)
            {            
                is_valid = 0;
            }        
        }
        else
        {
            is_valid = 0;
        }
    }
    else
    {
        is_valid = 0;
    }
    return is_valid;
}

void back_to_menu()
{
	if(test!=1)
    {   
		system("cls");
        printf("\nRecord not found!!\a\a\a"); 
    }
    else
    {
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
	}
    if (main_exit==1)
    {
        system("cls");
        fflush(stdin);
        menu();
   	}
    else
    {
		thanku();
        system("cls");
        exit(0);
    }	
}
