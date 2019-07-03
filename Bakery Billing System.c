#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void menu(void);
void generatebill(void);
void displaybill(void);
void displayproducts(void);
void delete_products();
struct product 
{
	char nam[20];
	int id;
	int price;
}b1[10],b2[10];
struct custo 
{
	char name[20];
	int q;
	int bid;
}c1[10],c2[10];
FILE *fp,*fp1;
int i,j,k,l,c,d,e,f,g;
char ps[20] = "shiv",us[20]="shiv",ps1[4],us1[20],ch,ch1;
void main()
{	
	printf("\n\n\t*****************   SHIVAM PATEL BAKERY *****************");
	A:
	fflush(stdin);
	printf("\n\n\n\n\n\n\n\n\t\t\tEnter Username : ");
	gets(us1);
	printf("\n\n\t\t\tEnter password : ");
	for(i=0;i<4;i++)
     {
            ch = getch();
            ps1[i] = ch;
            ch = '*' ;
         printf("%c",ch);
     }
	c=strcmp(ps1,ps);
	d=strcmp(us1,us);
	if(c==0&&d==0)
	menu();
	else
	{
		printf("\n\n\n\n\n\t\tWarning !!! Wrong Password or Username");
		goto A;
	}
	getch();
}
void menu()
{        
int j=0,k=0;
     	system("cls");
     	A:
		printf("\n\n\n\n\t\t\t======================");
		printf("\n\t\t\t\tWelcome");
		printf("\n\t\t\t======================");
		printf("\n\n\t\t\t    1. ADD PRODUCT");
		printf("\n\n\t\t\t    2. DISPLAY PRODUCTS");
     	printf("\n\n\t\t\t    3. GENERATE BILL");
    	printf("\n\n\t\t\t    4. DELETE PRODUCTS FROM STOCK ");
    	printf("\n\n\t\t\t    5. EXIT");
    	 printf("\n\n\n\n\t\t\t Enter your choice : ");
	     scanf("%d",&c);
	     switch(c)
	     {
	     	case 5:
	     		exit(0);
	     	case 3:
	     		generatebill();
	     		break;
	     	case 2:
	     		displayproducts();
	     		break;
	        case 4:
	        	printf("\n\n\n\t\t Please Enter Bill ID :");
	            scanf("%d",&e);
	     		delete_products(e);
	     		break;
	     	case 1:
	     		system("cls");
	     		fp=fopen("bill.txt","rb");
	     		fread(b2,sizeof(b2),1,fp);
	     		for(i=0;b2[i].id='\0';i++)
	     		{k++;}
	     		while(j<k)
	     		{
	     			b1[j]=b2[j];
	     			j++;
				}
				 fclose(fp);
				
				 
				 B:  
				 while(k<10)
				 {
				 	system("cls");
				 	fflush(stdin);
	        		printf("\n\n\n\t\t\tEnter Product Name : ");
	        		scanf("%s",&b1[k].nam);
	        		printf("\n\n \t\t\tEnter Price : ");
	        		scanf("%d",&b1[k].price);
	        		printf("The unique iD of code is : %d\t",k+1);
	        		b1[k].id = k+1;
	        		printf("\n\n\t\t\tEnter Details Of Other Products(Y/N) : ");
	        		ch1=getch();
	                
	                if(toupper(ch1)=='Y')
	                {
	                 k++;
	                 goto B;
					}
	        	   else
	        	   {
	        	   	fp=fopen("bill.txt","wb");
			    fwrite(b1, sizeof(b1),1,fp);
                fclose(fp);	
	        	   	k++;
	        	   	goto A;
				   }		   
				}
				fp=fopen("bill.txt","wb");
			    fwrite(b1, sizeof(b1),1,fp);
                fclose(fp);		
				break;	 
		 }
}
void displayproducts()
{
	k=0;
	system("cls");
	fp=fopen("bill.txt","rb");
	fread(b1,sizeof(b1),1,fp);
	for(i=0;b1[i].id!='\0';i++)
	{k++;}
		printf("\n\n\n\n\t\t=============================================================");
	printf("\n\t             Unique Product id\t Product Name\t\tPrice");
	printf("\n\t\t=============================================================");
    for(i=0;i<k;++i)
    {
    	
        printf("\n\n\t\t\t    %d\t\t    %s\t\t%d Rs",b1[i].id,b1[i].nam,b1[i].price);
    }
    fclose(fp);
    getch();
    menu();
}
void generatebill()
{    
		int p,q,i=0,j=0,k=0,total=0,d[10],s=0;
		system("cls");
		B:
		printf("\n\n\n\t\t\t\tEnter Product ID :");
	    scanf("%d",&d[s]);
	fp=fopen("bill.txt","rb");
	fread(b1,sizeof(b1),1,fp);
	for(i=0;b1[i].id!='\0';i++)
	{k++;}
	fclose(fp);
	for(i=0;i<k;i++)
    {
    	if(b1[i].id==d[s])
    	{
    	 printf("\n\n\n\n\n\t\t\t\tPRODUCT NAME : %s",b1[i].nam);
    	 printf("\n\n\t\t\t\tPRODUCT PRICE : %d Rs",b1[i].price);
    	   s=i;
    	
    		fp1=fopen("bills.txt","rb");
	       fread(c2,sizeof(c2),1,fp1);
	    	for(p=0;c2[p].bid!='\0';p++)
	     		{l++;}
	     		while(q<l)
	     		{
	     			c1[q]=c2[q];
	     			q++;
				 }
				 fclose(fp);
    	while(l<10)
		{
			printf("\n\n\t\t\t\tENTER QUANTITY OF PRODUCT : ");
    	scanf("%d",&c1[l].q);
    	printf("\n\n\t\t\t\tADD MORE PRODUCTS(Y/N) : ");
	        		ch1=getch();
	                
	                if(toupper(ch1)=='Y')
	                {total=total+b1[i].price*c1[l].q;
	                 goto B;
					}
	        	   else
	        	   {
	        	   	fflush(stdin);
	        	   		printf("\n\n\t\t\t\tENTER CUSTOMER NAME : ");
    	              gets(c1[l].name);
    	             
    	             	printf("\n\n\t\t\t\tPRESS 1 TO GENERATE A BILL ");
	        		scanf("%d",&ch);
	                if(ch==1)
	                {
	                	printf("\n\t\t\t\tBAKERY BILLING SYSTEM");
	                	printf("\n\n\n\t\t    Customer Name : %s",c1[l].name);
	                
						("\t  Bill ID : %d",l+1);
	                	c1[l].bid = l+1;
	                	total=total+b1[i].price*c1[l].q;
	                	printf("\n\n\n\n=======================================================================");
	                	printf("\n\t Item Name  \t   Price   \t   Quantity   \t   Total   ");
	                	printf("\n=======================================================================\n");
	                	printf("\t%s   \t   Rs%d   \t   %d   \t   %d",b1[i].nam,b1[i].price,c1[l].q,total);fp1=fopen("bills.txt","wb");
			            fwrite(c1, sizeof(c1), 1, fp1);
                        fclose(fp1);
                        l++;
	                	getch();
	                	menu();
					}
	        	   else
	        	   {
	        	   	menu();
				   }
				   
    	      	   }
		   }   
		}
		else if(b1[i].id!=d[s])
		{
			system("cls");
			printf("\n\n\n\t\t\t\tNO SUCH PRODUCT EXISTS");
            goto B;
		}
    }
}
void delete_products()
{
	int p,q,k=0;
	fp= fopen("bill.txt", "rb");
    fread(b2, sizeof(b2), 1,fp);
    for(j=0;b2[j].id!='\0';j++)
    {k++;}
    fclose(fp);
    for(i=0;i<k;i++)
         {
         	if(b2[i].id==e)
         	{
         	q=i;
			 }
		 }
         		for(p=q;p<k;++p)
             {
         	b2[p-1]=b2[p];
		     }
		     for(i=0;i<k-2;i++)
             {
         	b1[i]=b2[i];
		     }
	fp=fopen("bill.txt","wb");
	fwrite(b1,sizeof(b1),1,fp);
	fclose(fp);
	printf("\n\n\n\n\t\t\tRECORDS DELETED");
	getch();
	menu();
}

