#include "Story3.h"

/*
Story 03 - As a company that provide services. 
I want to see the amounts withheld rounded
correctly to 2 decimal places.That way I
will not be confused about how much will
be discounted from my payment. 
*/


int main()
{
	struct invoice in;
	struct withhold_taxes wt;
    struct taxes t = rates();
	int choice;
	time_t time_date;
	time(&time_date);
	
	do
	{

		system("cls");
		system("color 1f");

		printf("/*************************************/\n");		
		printf("/*      NF-e Withheld Taxes - V3     */\n");
		printf("/*************************************/\n");		
		printf("\n\n1- Calculate Withheld Taxes");
		printf("\n\n2- Exit");
		printf("\n\n-> ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
					system("cls");
					printf("Invoice Amount: ");
					scanf("%f", &in.invoice_amount);
					
					//Display the current date and time according to O.S
					printf("\n\n%sThe current tax rates are: ", ctime(&time_date));
					printf("\n\nIR: %f", t.ir);
					printf("\n\nPIS: %.", t.pis);
					printf("\n\nCOFINS: %f", t.cofins); 
					printf("\n\nCSLL: %f", t.csll);
					wt = calculate(in, t);
					
					//The %.2f rounds the value correctly to 2 decimal places
					printf("\n\nGovern Amount: %.2f", wt.govern_amount);
					printf("\n\nAssumed Profit: %.2f", wt.assumed_profit);
					printf("\n\n");
					system("pause");
					break;
			
			case 2:
					printf("\nBye!\n\n");
					break;
					
			default: printf("\n\nOption Invalid!\nPlease try Again!\n\n");
		             system("pause");
	                 break;				
					
		}
	}while(choice != 2);

	printf("\n\n");
}

