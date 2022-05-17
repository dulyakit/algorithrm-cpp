
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
	
   struct node *next;
   struct node *prev;
};

//this link always point to first Link
struct node *head = NULL;

//this link always point to last Link 
struct node *last = NULL;

struct node *current = NULL;

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}

//display the list in from first to last
void display() {

   //start from the beginning
   struct node *ptr = head;
	
   //navigate till the end of the list
   printf(" [ ");
	
   while(ptr != NULL) {        
      printf("%d ",ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]\n");
}


//insert link at the first location
void insertFirst(int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
	
   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {
      //update first prev link
      head->prev = link;
   }

   //point it to old first link
   link->next = head;
   head = link;
}

//insert link at the last location
void insertLast( int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;
	
   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {
      //make link a new last link
      last->next = link;     
      
      //mark old last node as prev of new link
      link->prev = last;
   }

   //point last to new last node
   last = link;
}

//delete first item
struct node* removeFirst() {

   //save reference to first link
   struct node *tempLink = head;
	
   //if only one link
   if(head->next == NULL){
      last = NULL;
   } else {
      head->next->prev = NULL;
   }
	
   head = head->next;
   //return the deleted link
   return tempLink;
}

//delete link at the last location
struct node* removeLast() {
   //save reference to last link
   struct node *tempLink = last;
	
   //if only one link
   if(head->next == NULL) {
      head = NULL;
   } else {
      last->prev->next = NULL;
   }
	
   last = last->prev;
	
   //return the deleted link
   return tempLink;
}

traverseList(){
    int L,R,Sum,Ans,Number;
    printf(" Input Step : ");
    scanf("%d",&Number);
    printf(" Form Step : ");
    char str[Number];
    scanf("%s",&str);
    if(Number!=strlen(str)){
        printf(" Error!\n");
    }else{
        struct node *ptr = head;
        for(int i = 0;i<strlen(str);i++){
            if(str[i]== 'L' && i != 0){
                ptr = ptr->prev;
                Ans = ptr->data;
             }else if(str[i]== 'L' && i == 0){
             }else{
                ptr = ptr->next;
                Ans = ptr->data;
            }
       }
       printf(" %d \n",Ans);
    }
    
    
}

int main()
{
    int data;
    int choice;
        printf(" 1 : Operation isEmpty \n");
        printf(" 2 : Operation getSize \n");
        printf(" 3 : Operation insertFirst \n");
        printf(" 4 : Operation insertLast \n");
        printf(" 5 : Operation removeFirst \n");
        printf(" 6 : Operation removeLast \n");
        printf(" 7 : Operation displayList \n");
        printf(" 8 : Operation traverseList \n");
        printf(" 9 : Exit \n");
    while(1){
        printf(" Please Select functions : ");
        scanf("%d",&choice);
        if(choice == 1){
           if(length() >= 1){
               printf(" Operation isEmpty : No \n");
           }else{
               printf(" Operation isEmpty : Yes \n");
           }
        }else if(choice == 2){
           printf(" Operation getSize  : %d \n",length());
        }else if(choice == 3){
           printf(" Operation insertFirst :  ");
           scanf("%d",&data);
           insertFirst(data);
        }else if(choice == 4){
           printf(" Operation insertLast :  ");
           scanf("%d",&data);
           insertLast(data);
        }
        else if(choice == 5){
           printf(" Operation removeFirst\n ");
           removeFirst();
        }
        else if(choice == 6){
           printf(" Operation removeLast\n ");
           removeLast();
        }else if(choice == 7){
           display();
        }
        else if(choice == 8){
           traverseList();
        }
        else if(choice == 9 ){
          printf(" Exit Program.");
          break;
        }
        
    }
    
}