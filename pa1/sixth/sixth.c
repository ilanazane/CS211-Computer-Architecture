#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}bstnode;

bstnode* root = NULL;

//void search(int);
void insert(bstnode*, int);
//void delete(int);
int findminnode(node*);

int findminnode(bstnode* start){
	bstnode* ptr = start;
	while(ptr->left != NULL){
		ptr = ptr->left;
	}
	return ptr->data;
}



void insert(bstnode* bstnode , int key){

	if(root == NULL){
		root = bstnode;
		    //printf("inserted %d\n", root);
		return;
	}
	bstnode* ptr = root;
	bstnode* parent = NULL;
	while(ptr != NULL){
		if(ptr->data == key){
		 	    //printf("duplicate: %d\n",key);
			return;
		}else if(ptr->data > key){
			parent = ptr;
			ptr = ptr->left;
		}else{
			parent = ptr;
			ptr = ptr->right;
		}
	}
	if(ptr == NULL){
		if(parent->data > key){
			parent->left = bstnode;
		}else{
			parent->right = bstnode;
		}
	}
	return;
}



void inorderTraversal(bstnode* root){
    if(root!=NULL){
      inorderTraversal(root->left);
      printf("%d\t",root->data);
      inorderTraversal(root->right);
    }
}


int main(int argc, char** argv){
	FILE* fp;
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("error\n");
		exit(0);
	}
	char op;
	int num;
      //printf("nodes are:\n");
  while(fscanf(fp,"%c\t%d\n", &op, & num) != EOF){
        //if character is equal to i,then bstnode is going to store num which
        //is all of the numbers
        //and left and right pointers are eqaul to null;
    if(op == 'i'){
			bstnode* bstnode = (bstnode*) malloc(sizeof(bstnode));
			bstnode->data = num;
			bstnode->left = NULL;
			bstnode->right = NULL;

      //printf("%d\n",num );

      insert(bstnode,num);
		}else{
			printf("error\n");
			exit(0);
		}
	}
  //printf("\t");
  inorderTraversal(root);

	return 0;
}
