#ifndef Client_H_
#define Client_H_

//Make Transaction Function
void Make_Transaction_Client_fun(Account *ptr)
{
	u32 scan_Account_ID=0;
	u32 scan_money=0;
	u8 check=0;
	printf("Enter Bank Account ID need to Make Transaction it: \n");
	scanf("%d",&scan_Account_ID);
	printf("Enter amount of money need to Make Transaction it: \n");
	scanf("%d",&scan_money);
	if(ptr->Account_Status==1)
	{
		if(ptr->Balance > scan_money)
		{
			while(1)
			{
				for (u16 i=0;i<50;i++)
				{
					if(arr_Account[i].Bank_Account_ID ==scan_Account_ID)
					{
						check=1;
						ptr->Balance -= scan_money;
						arr_Account[i].Balance +=scan_money;
						printf("Sussessful operation");
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
		else{
			printf("Transaction won’t be completed because amount of money in account Balance is less than money need to Make Transaction it");
		}
		
	}
	else{
		printf("Transaction won’t be completed because account is Restricted or Closed");
	}
}
//Change Account Password Function
void Change_Account_Password_Fun(Account *ptr)
{
	while(1)
	{
		u8 Client_Old_Password_ch[10];
		u8 Client_New_Password_ch[10];
		printf("Enter Old Password:");
		fflush(stdin);
		scanf("%[^\n]%*c", Client_Old_Password_ch);
		u8 Password_Old = strcmp(ptr->Password,Client_Old_Password_ch);
		if (Password_Old == 0)
		{
			printf("Enter New Password: \n");
			fflush(stdin);
			scanf("%[^\n]%*c", Client_New_Password_ch);
			u8 Password_New = strcmp(ptr->Password,Client_New_Password_ch);
			if (Password_Old == 1)
			{
				for(u8 i=0;i<10;i++)
				{
					ptr->Password[i] = Client_New_Password_ch[i];
				}
				break;
			}
			else{
				printf("Erorr Old Password == New Password");
			}
		}
		else 
		{
			printf("Erorr Password not correct");
		}
	}
}
//Get Cash Function
void Get_Cash_Client_fun(Account *ptr)
{
	u32 scan_money=0;
	if(ptr->Account_Status==1)
	{
		printf("Enter amount of money need to Get Cash it: \n");
		scanf("%d",&scan_money);
		if(ptr->Balance > scan_money)
		{
			ptr->Balance -= scan_money;
			printf("Sussessful operation");
		}
		else
		{
			printf("Transaction won’t be completed because amount of money in account Balance is less than money need to Make Transaction it");
		}
	}
	else{
		printf("Transaction won’t be completed because account is Restricted or Closed");
	}
}
//Deposit in Account Function
void Deposit_in_Account_Client_fun(Account *ptr)
{
	u32 scan_money=0;
	if(ptr->Account_Status==1)
	{
		printf("Enter amount of money need to Enter it: \n");
		scanf("%d",&scan_money);
		if(ptr->Balance > scan_money)
		{
			ptr->Balance += scan_money;
			printf("Sussessful operation");
		}
		else
		{
			printf("Transaction won’t be completed because amount of money in account Balance is less than money need to Make Transaction it");
		}
	}
	else{
		printf("Transaction won’t be completed because account is Restricted or Closed");
	}
}
//Open Existing Account Function
void Client_Window_fun(Account *ptr)
{
	while(1)
	{
		u8 Feature=0;
		printf("Feature Client Account:");
		printf("For Make Transaction        '1' \n");
		printf("For Change Account Password '2' \n");
		printf("For Get Cash                '3' \n");
		printf("For Deposit in Account      '4' \n");
		printf("For Return to main menu     '5' \n");
		printf("Enter Feature: \n");
		scanf("%c",&Feature);
		switch(Feature)
		{
			case '1':
				//Make Transaction function
				Make_Transaction_Client_fun(ptr);
				break;
			case '2':
				//Change Account Password Function
				Change_Account_Password_Fun(ptr);
				break;
			case '3':
				//Get Cash Function
				Get_Cash_Client_fun(ptr);
				break;
			case '4':
				//Deposit in Account Function
				Deposit_in_Account_Client_fun(ptr);
				break;
			default:
				//printf("Error Feature Open Existing Account");
				break;
		}
		//Return to main menu Function
		if(Feature == '5')
			break;
	}
}
#endif
