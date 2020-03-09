#include<stdio.h>
#include<string.h>
//CREATED A STRUCTURE TO KEEP ALL THE ARRAYS
struct shyam{
int item_number;
char item_description[25];
int quantity_in_hand;
char supplier_name[25];
char supplier_address[25];
long long int supplier_telephone;
int buy_item_number;
char buy_item_name[25];
int buying_quantity;
int rejected_item_number;
char rejected_item_name[25];
int rejected_quantity;
};
void main(){
    struct shyam st[100];
int i; //TO LOOP THE MENU ENDLESS

//DIFFERENT SIZES OF ARRAY
int size=0,size1=0,size2=0,size3=0,count=0,size4=0;
i=1;
int array=0;
int index;
int option;
int buy_item_number1;
char buy_item_name1[25];
int buying_quantity1;

//MENU WILL BE PRINTED
while(i==1){
    printf("\nPlease Select one of the following Options :\n");
    printf("  1. Add a new item \n");
    printf("  2. Remove an item \n");
    printf("  3. Add a supplier \n");
    printf("  4. Remove a supplier \n");
    printf("  5. Place an order \n");
    printf("  6. process a issue request \n");
    printf("  7. List the requests which have been rejected \n");
    printf("  8. Exit\n");
    printf("\nSelect an Option (1-8):");
    scanf("%d", &option);

    switch(option)
    {
     case 1:
     //ADDING NEW ITEM IN THE LIST
     printf("\nAdd a new item \n");
     size++;
     array=size-1;
     printf("Enter a item number\n");
     scanf("%d",&st[array].item_number);   
     printf("Enter the description of item\n");
     scanf("%s",&st[array].item_description);
     printf("Enter the quantity in hand\n");
     scanf("%d",&st[array].quantity_in_hand); 
     //CHECKING THE MULTIPLE OCCURENCE OF ITEM NUMBER AND ADDING THE QUANTITY IN HAND     
      for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            
            if(st[i].item_number == st[j].item_number)
            {    st[i].quantity_in_hand+=st[j].quantity_in_hand;
                
                for(int k=j; k<size; k++)
                {
                    st[k].item_number = st[k + 1].item_number;
                    
                }
                size--;
                j--;
            }
        }  
     break;
     case 2:
     //REMOVE AN ITEM FROM THE LIST
     printf("\nREMOVE AN ITEM\n");
     //PRINTING THE EARLIER  VALUES OF ARRAY
     printf("\n The items in the list are:-\n");
     for(int j=0;j<size;j++){
         printf("%d) ",j+1);
         printf(" The item name is %d\n",st[j].item_number);
         printf(" The item number is %s\n",st[j].item_description);
          printf(" The quantity in hand is %d\n",st[j].quantity_in_hand);
     }
     //DELETING AN ARRAY ELEMENT
     printf("\nEnter the index number to remove the item from the list\n");
     scanf("%d",&index);
     for(int j=index-1;j<size-1;j++){
         st[j].item_number= st[j+1].item_number;
         st[j].quantity_in_hand=st[j+1].quantity_in_hand;
     }
     size--;
     }
     break;
     case 3:
     //ADD A SUPPLIER
     printf("\nADD A SUPPLIER\n");
      size1++;
     array=size1-1;
     printf("Enter a supplier name\n");
     scanf("%s",&st[array].supplier_name);   
     printf("Enter the address of supplier\n");
     scanf("%s",&st[array].supplier_address);
     printf("Enter the supplier telephone number\n");
     scanf("%lld",&st[array].supplier_telephone);  
     break;
     case 4:
     //REMOVE A SUPPLIER
     printf("\nREMOVE A SUPPLIER\n");
     //PRINT THE ARRAYOF SUPPLIER
         printf("\n The suppliers in the list are:-\n");
     for(int j=0;j<size1;j++){
         printf("%d) ",j+1);
         printf(" The name of supplier is %s\n",st[j].supplier_name);
         printf(" the address of the supplier is %s\n",st[j].supplier_address);
          printf(" The telephone number of the supplier is %lld\n",st[j].supplier_telephone);
     }
     //DELETING AN ARRAY ELEMENT FROM THE LIST
     printf("\nEnter the index number to remove the supplier from the list\n");
     scanf("%d",&index);
     for(int j=index-1;j<size-1;j++){
         st[j].supplier_telephone=st[j+1].supplier_telephone;
     }
     size1--;
     break;
     case 5:
     //PLACE AN ORDER
     printf("\nPlace an order\n");
     printf(" Enter the item number which you want to buy\n");
     scanf("%d",&buy_item_number1);
     printf(" Enter the name of item you want to buy\n");
     scanf("%s",&buy_item_name1);
     printf(" Enter the number of items you want to buy\n ");
     scanf("%d",&buying_quantity1);
     //SEARCHING THAT THE ITEM IS PRESENT OR NOT
     for(i=0; i<size; i++)
    {
        if(st[i].item_number ==buy_item_number1)
        {
            size2++;
            array=size2-1;
            st[array].buy_item_number =  buy_item_number1;
            strcpy(st[array].buy_item_name, buy_item_name1);
            st[array].buying_quantity = buying_quantity1;
            st[array].quantity_in_hand=st[array].quantity_in_hand-buying_quantity1;
            
     
        }
        else{
             size3++;
            array=size3-1;
            st[array].rejected_item_number =  buy_item_number1;
            strcpy(st[array].rejected_item_name, buy_item_name1);
            st[array].rejected_quantity = buying_quantity1;
    }
    }
     break;
     case 6:
     //PPROCESSING THE ORDER
     printf("\nProcess a issue request\n");
     for(int j=0;j<size2;j++){
                printf(" The processing item number is %d\n",st[j].buy_item_number);
                printf(" The processing item name is %s\n",st[j].buy_item_name);
                printf(" The processing Quantity is %d\n",st[j].buying_quantity);
                printf(" The is is processed\n");
               
            }
     break;
     case 7:
     //PRINTING THE REJECTED LIST
     printf("\nList of order which have been rejected\n");
     for(int j=0;j<size3;j++){
         printf("%d ) ",j+1);
                printf(" The rejected item number is %d\n",st[j].rejected_item_number);
                printf(" The rejected item name is %s\n",st[j].rejected_item_name);
                printf(" The rejected quantity is %d\n",st[j].rejected_quantity);

        }
     break;
     case 8:
     printf("\n Exiting the program\n");
     i=2;
     for(int i = 0; i < size2; i++) {    
         
        for(int j = i + 1; j < size2; j++) {   
            if(st[i].buy_item_number == st[j].buy_item_number) 
            printf("%d)\n",i+1);   
                printf("The item number which is reordered %d\n", st[j].buy_item_number);    
                printf(" The name of item reordered %s\n", st[j].buy_item_name); 
                st[j].buying_quantity+=st[i].buying_quantity;
                printf(" The total no of order made of the above item is %d\n",st[j].buying_quantity);       
                
        }    
    }      
     break;
    }
     
    }
    

}