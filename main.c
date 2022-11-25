#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "STD_Types.h"
#include "BIT_CALC.h"
typedef struct Bank_Account Account;
//#define _CRT_SECURE_NO_WARNINGS
struct Bank_Account
{
	u8 Full_Name[50];
	u8 Full_Address[70];
	u32 National_ID;
	u8 Age;
	u32  Bank_Account_ID;
	u8 Guardian[50];
	u32 Guardian_National_ID;
	u8 Account_Status;
	u32 Balance;
	u8 Password[10];
};
Account arr_Account[50] = {0};
#include "Admin.h"
#include "Client.h"
u8 Admin_Username[10] ="IMT Admin";
u8 Admin_Password[10] ="ITI_g2_MR";
int main()
{
	//printf("\n %s \n",arr_Account[10].Full_Name);
	void* check[50];
	for(u16 i=0;i<50;i++)
	{
		check[i]=NULL;
	}
	u8 Window = 0;
	printf("----------Welcome in IMT Bank---------- \n");
	while (1)
	{
		printf("For Admin Window press '1' \n For Client Window press '2'\n For Exit press '0' \n");
		printf("Window :");
		scanf("%c",&Window);
		if (Window == '0')
		{
			printf("----------Thank you for chooseing IMT Bank----------\n");
			break;
		}
		else if (Window=='1')
		{
			u8 Admin_Username_ch[10];
			u8 Admin_Password_ch[10];
			printf("----------Welcome to the IMT Admin Window----------\n");
			while (1)
			{
				printf("Enter Admin Username: \n");
				fflush(stdin);
				scanf("%[^\n]%*c", Admin_Username_ch);
				u8 Username = strcmp(Admin_Username,Admin_Username_ch);
				if (Username == 0)
				{
					printf("Enter Admin Password:");
					fflush(stdin);
					scanf("%[^\n]%*c", Admin_Password_ch);
					u8 Password = strcmp(Admin_Password,Admin_Password_ch);
					if (Password == 0)
					{
						while(1)
						{
							u8 features=0;
							printf("Please input features :\n");
							printf("For Create New Account   '1'\n");
							printf("For Open Existing Account'2'\n");
							printf("For Exit the System      '3'\n");
							scanf("%c",&features);
							if(features== '1')
							{
								//Create New Account Function
								for(u16 i=0;i<50;i++)
								{
									 if(check[i]==NULL)
									{
										check[i]=&arr_Account[i];
										Create_New_Account(&arr_Account[i]);
									} 
								}
							}
							else if (features== '2')
							{
								while(1)
								{
									u32 scan_Account_ID=0;
									u8 check=0;
									//Open Existing Account Function
									printf("Enter Client Bank Account ID : \n");
									scanf("%d",&scan_Account_ID);
									for (u16 i=0;i<50;i++)
									{
										if(arr_Account[i].Bank_Account_ID ==scan_Account_ID)
										{
											check=1;
											Open_Existing_Account(&arr_Account[i]);
											break;
										}
									}
									if(check!='1')
									{
										printf("Error Bank Account ID not found");
									}
									else
									{
										break;
									}
								}
							}
							else if (features== '3')
							{
								//Exit the System
								break;
							}
						}
					}
					else
					{
						printf("Error Admin Password");
					}
				}
				else
				{
					printf("Error Admin Username");
				}
			}
		}
		else if (Window== '2')
		{
			while(1)
			{
				u32 scan_Account_ID=0;
				u8 check=0;
				//Open Client Window
				printf("Enter Bank Account ID : \n");
				scanf("%d",&scan_Account_ID);
				for (u16 i=0;i<50;i++)
				{
					if(arr_Account[i].Bank_Account_ID ==scan_Account_ID)
					{
						u8 Client_Password_ch[10];
						printf("Enter Password:");
						fflush(stdin);
						scanf("%[^\n]%*c", Client_Password_ch);
						u8 Password = strcmp(arr_Account[i].Password,Client_Password_ch);
						if (Password == 0)
						{
							check=1;
							Client_Window_fun(&arr_Account[i]);
							break;
						}
						else 
						{
							printf("Erorr Bank Account ID or Password not correct");
						}
					}
				}
				if(check!='1')
				{
					printf("Error Bank Account ID not found");
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			printf("Error Window");
			continue;
		}
	}
	return 0;
}