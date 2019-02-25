#include <stdio.h>
#include <stdlib.h>

//int countertwo;

typedef struct node{
    int data;
    struct node* next;
} node;

node* head = NULL;

void printed(node*);
int counted(node*);
void delete(node** head,int value);
void insert(node*,int);



void printed(node* pt){
    node* temp=pt;
 	int printedval=0;
	int ishead=1;
    if(temp == NULL){
        return;
    }
    while(temp != NULL){
	if(ishead){
	printf("%d\t",temp->data);
printedval=temp->data;
ishead=0;
}else{
	if(temp->data!=printedval){
	printf("%d\t",temp->data);
printedval=temp->data;
}
}
	temp=temp->next;
}
    printf("\n");

}


int countll(node* pt){
     node* temp=pt;
    /*if(temp == NULL){
        return 0;
    }*/
    int counter = 0;

    while(temp != NULL){
        //printf("%d\n",temp->data);
        counter++;
        temp = temp->next;

    }
    return counter;
}



int main(int argc, char** argv){
    if(argc < 2){
        printf("0\n");
        return 0;
    }
    char ch;
    int data;
    FILE *fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("error\n");
        return 0;
    }
    while(fscanf(fp, "%c\t%d\n", &ch, &data) != EOF){
            //printf("data is: %d\n",data );
        if(ch == 'i'){
            node* newn = (node*) malloc(sizeof(node));
            newn->data = data;
            newn->next = NULL;
            insert(newn,data);
                //printed(head);
        }else if(ch == 'd'){
            delete(&head,data);
            //printed(head);
        }else{
            printf("error\n");
            return 0;
        }
    }

int nums=countll(head);
    printf("%d\n", nums);
    printed(head);
    fclose(fp);
    return 0;
}



void delete(node** head,int value){
    node* current= *head;
    node* prev=NULL;
    if(current!=NULL&&current->data==value){
        *head=current->next;
        free(current);
        return;
    }


    while(current!=NULL&&current->data<value){
        prev=current;
        current=current->next;
    }
    if(current==NULL){
        return;
    }
    prev->next=current->next;
        free(current);


    }




void insert(node* newn, int value){
    //int countertwo;
    if(head == NULL){
        head = newn;
        return;
    }
    node* pt = head;
    node* prev = NULL;
    while(pt != NULL){
        if(pt->data > value){ /* insert node at front of list */
            //printf("test head %p",pt->data );
            if(prev == NULL){
                newn->next = pt;
                head = newn;
                return;
            }else{
                prev->next = newn;
                newn->next = pt;
                return;
            }
        }else if(pt->data < value){
            if(pt->next == NULL){
                pt->next = newn;
                return;
            }else{
                prev = pt;
                pt = pt->next;
            }
        }else if(pt->data == value){
            //countertwo++;
            //struct node* temp=pt->next;
            newn->next=pt->next;
            pt->next=newn;
            /*prev = pt;
            pt = temp; */
            return;
        }
    }

}
