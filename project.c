#include<stdio.h>
struct query
{
	int id,a,b;
}f[100],s[100],E[100];
int n,sc=0,fc=0,ec=0;
void input()
{
	int job,ath,atm,bt,j,k=0,id=1;
	printf("\nEnter number of Queries: ");
	scanf("%d",&n);
	printf("Input 1 for Student 2 for Faculty...\n");
	for (k=0;k<n;k++)
	{
		printf("\n*********************Process %d**************************\n",k+1);
		printf("Enter (1/2):");
		scanf("%d",&j);
		if(j==1)
		{
			printf("Query ID: %d\n",id);
			s[sc].id=id;
			printf("Arrival Time: ");
			scanf("%d %d",&ath,&atm);
			if((ath<24) && (atm<60))
			{
				if((10<=ath) && (ath<12))
				{
					if((atm>=0) && (atm<60))
					{
						s[sc].a=600-(ath*60)+atm;
						printf("Resolving time: ");
						scanf("%d",&s[sc].b);
						sc++;
					}
					else
					printf("Enter valid minutes\n");
				}
				else
				printf("I am available from 10 to 12 only");
			}
			else
			printf("Not a valid time\n");
		}
		else if(j==2)
		{
			printf("Query ID: %d\n",id);
			f[fc].id=id;
			printf("Arrival Time: ");
			scanf("%d %d",&ath,&atm);
			if((ath<24) && (atm<60))
			{
				if((10<=ath) && (ath<12))
				{
					if((atm>=0) && (atm<60))
					{
						f[fc].a=600-(ath*60)+atm;
						printf("Resolving time: ");
						scanf("%d",&f[fc].b);
						fc++;
					}
					else
					printf("Enter valid minutes\n");
				}
				else
				printf("I am available from 10 to 12 only");
			}
			else
			printf("Not a valid time\n");
		}
		else
		{
		printf("please enter valid input\n");
		input();
		}
		id++;
	}
}

void Order_Of_Execution()
{
	int isc=0,ifc= 0;
	if( fc!=0  && sc!=0)
	{
		while(isc<sc && ifc<fc)
		{
			if(f[ifc].a == s[isc].a)
			{
				E[ec] = f[ifc];
				ec++;
				ifc++;
				E[ec]= s[isc];
				ec++;
				isc++;
			}
			else if(f[ifc].a < s[isc].a)
			{
				E[ec]= f[ifc];
				ec++;
				ifc++;
			}
			else if(f[ifc].a > s[isc].a)
			{
				E[ec]= s[isc];
				ec++;
				isc++;
			}
			else;
		}
		if(ec != (fc+sc))
		{
			if(fc!=ifc)
			{
				while(ifc!=fc)
				{
					E[ec]= f[ifc];
					ec++;
					ifc++;
				}
			}
			else if(sc!=isc)
			{
				while(isc!=sc)
				{
					E[ec]= s[isc];
					ec++;
					isc++;
				}
			}
		}
	}
	else if(fc==0)
	{
		while(isc!=sc)
		{
			E[ec]= s[isc];
			ec++;
			isc++;
		}
	}
	else if(sc==0)
	{
		while(ifc!=fc)
		{
			E[ec]= f[ifc];
			ec++;
			ifc++;
		}
	}
	else 
	{
		printf("\n No valid Jobs available\n");
	}
}

void rr()
{
	int k,j,i,ts,temp,q;
     int aw; float awt;
     int bt[10],wt[10],te[10],rt[10],at[10];j=0;
    for(i=0;i<n;i++)
      {
          at[i]=E[i].a;
          bt[i]=E[i].b;
          te[i]=0;     wt[i]=0;
      }
    for(i=0;i<n;i++)
      {
        for(j=i+1;j<n;j++)
         {
             if(at[i]>at[j])
               {
                    temp=at[i];                                          //sorting according to arrival time
                    at[i]=at[j];
                    at[j]=temp;
                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;
              }
         }
     }
    printf("\n enter time slice :   ");
    scanf("%d",&ts); q=0;
    printf("\nprocess      :")  ;
    for(i=0;i<n;i++)
     {
       printf("  %d",i+1);
      }
    printf("\nBrust time   :");
    for(i=0;i<n;i++)
       {
         printf("  %d",bt[i]); rt[i]=bt[i];
        }
    printf("\nArrival time :");
    for(i=0;i<n;i++)
      {
          printf("  %d",at[i]);
      }
    printf("\n\n ***Gannt chart*** \n");
    j=0;

    while(j<=n)
       {
          j++;
          for(i=0;i<n;i++)
            {
              if(rt[i]==0)  continue;
                   if(rt[i]>ts)
                     {
                        printf("\n %d\t P%d",q,i+1);
                        q=q+ts;
                        rt[i]=rt[i]-ts;
                        te[i]=te[i]+1;
                     }
                  else
                    {
                       printf("\n %d\t P%d",q,i+1);
                       wt[i]=q-te[i]*ts;
                       q=q+rt[i]; 
                       rt[i]=rt[i]-rt[i];
                    }
            }
       }                                   //end of while    
	   
	printf("\n"); 
    awt=0;
    printf("\n Process       Waiting time        Turn Around time");
    int ta[n],ata=0;
	float aata=0;
    for(i=0;i<n;i++)
       {
       	
                wt[i]=wt[i]-at[i];
                
                ta[i]=wt[i]+bt[i];
                printf("\n P%d\t\t  %d\t\t\t  %d",i+1,wt[i],ta[i]);
                ata=ata+ta[i];
				awt=awt+wt[i];
        }
    aw=awt;
    aata=ata;
    printf("\nTotal waiting time :  %d",aw);
    printf("\nAvg waiting time : %f ",awt/n);
    printf("\nTotal Query Time :  %d",ata);
    printf("\nAvg Query time:  %f ",(aata/n));
}


void start()
{
	input();
	Order_Of_Execution();
	rr();
}

int main()
{
	printf("1. Enter Arrival times as hr and min separated by SPACE in 24 hour format. eg: 10:30 AM as 10 30\n2. These should be in Ascending order\n");
	start();
	
}
