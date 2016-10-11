#include<stdio.h>
#include<stdlib.h>

struct coin{
	int value[20];
	int number[20];

};

/*typedef struct{
	int *value,*number;
	int counter;
}coins;*/

struct coin *final;
	int n_coins;

void readCoin(struct coin *ob);											//.....UD function declarations
void findChange(struct coin *ob);
void dispChange(struct coin *ob);
void leastChange(struct coin *ob,struct coin *preOb,int amount,int lastCounter,int i);

void sort(struct coin *ob)
{
  int c,d,t,n=0;
  for(c=0;ob->value[c]!='\0';c++)//.............pseudo strlen
  {
  	n++;
  }

  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (ob->value[d] < ob->value[d+1])
      {
        /* Swapping */

        t         = ob->value[d];
        ob->value[d]   = ob->value[d+1];
        ob->value[d+1] = t;
      }
    }
  }
}

void readCoin(struct coin *ob)
{
	int choice,place=0,amnt;
//	struct coin *obNew=(struct coin *)calloc(1,sizeof(struct coin));
	while(1)
	{
		printf("Enter the denomination of the coin\nEnter 0 if no more struct coin are to be added\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: if(ob->value[0]==0)
				{
					printf("\nPlease enter at least one denomination for the coin\n");
					readCoin(ob);
				}
				printf("Ok. \n Now calculating");
				sort(ob);
					printf("********************************************************************************");
				printf("\nEnter 1 to Calculate by the Greedy Method.\nEnter 2 to Calculate by the Recursive Method(Much More Accurate Result)\n");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1: findChange(ob);
							return;
					case 2:	printf("Enter the amount to be converted\n");
							scanf("%d",&amnt);
							 leastChange(ob,final,amnt,10000,0);
							 break;
					default: printf("Please enter a valid choice\n");
							exit(0);


				}

				return;
			default: ob->value[place++]=choice;
					break;
		}
	}
}

void leastChange(struct coin *ob,struct coin *preOb,int amount,int lastCounter,int i)
{
	int temp_amount=amount,temp,pos=0,counter=0;
	struct coin *obj;
		obj=(struct coin *)calloc(n_coins,(sizeof(struct coin)));




	for(temp=i;ob->value[temp]!='\0';temp++)
	{
		obj->value[temp]=ob->value[temp];
		obj->number[pos]=(amount/ob->value[temp]);//..........incrementing amount
		counter=counter+obj->number[pos++];//.........counter incremented to store total struct coin
		amount=amount-ob->value[temp]*(amount/ob->value[temp]);
		if(amount==0)
		{

			if(ob->value[i]==0)
			{
				dispChange(final);
				return;
			}
			if (counter>lastCounter)
			{
				free(obj);
					final=preOb;
				leastChange(ob,preOb,temp_amount,lastCounter,i+1);

			}
			else
			{
				free(preOb);
					final=obj;
				leastChange(ob,obj,temp_amount,counter,i+1);

			}

		}
    }
    printf("printed here\n");
    dispChange(final);
}

void findChange(struct coin *ob)
{
	int amount;
	int i;
	printf("\nEnter the amount to be converted\n");
	scanf("%d",&amount);
	for(i=0;ob->value[i]!='\0';i++)
	{
		ob->number[i]=(amount/ob->value[i]);
		amount=amount-ob->value[i]*(amount/ob->value[i]);
		if(amount==0)
		{
		 dispChange(ob);
		 return;
		}
	}
	printf("The change wasn't calculated accurately. \n Amount left unconverted=%d\n ",amount);

	dispChange(ob);
}

void dispChange(struct coin *ob)
{
	int i,j=0;
	while(ob->value[j]==0)
		{
			j++;
		}
	for(i=0;;)
	{

		while(ob->number[i]==0)
		{
			i++;
			j++;
		}
		printf("********************************************************************************");
		printf("No. of %d coin = %d \n",ob->value[j++],ob->number[i++]);
		if(ob->value[i]==0)
		{
			exit(0);
		}

	}
}

int main()
{

	struct coin ob;
		printf("********************************************************************************");
	printf("********************************************************************************\n");
	printf("       \t\t\tWELCOME TO THE COIN CHANGE\n");
	printf("********************************************************************************");
	printf("********************************************************************************\n\n\n");
	printf("We provide you with your money in the minimum number of coins as possible\n\n");
	printf("Enter the number of coins you want in the set...\n");
	
	scanf("%d",&n_coins);
//	ob=(struct coin *)calloc(n_coins,(sizeof(struct coin)));

	readCoin(&ob);


	return 0;
}














