#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

void printMatrix(int**,int,int);


//OPEN FILE AND FIND ROW AND COLUMN NUMBERS
int i;
int j;
int size;
int row;
int col;
int** mat1;
int* arr;



  FILE* fp;
    fp = fopen(argv[1], "r");
  if(fp==NULL){
      printf("error in opening file");
}
  fscanf(fp,"%d %d\n",&row,&col);
      //printf("the row and col are %d %d\n",row,col);


//CREATE MATRIX1
    mat1 = (int**) malloc(row*sizeof(int*));
    for(i = 0; i < row; i++){
        arr = (int*) malloc(col*sizeof(int));
        for(j = 0; j < col; j++){
            fscanf(fp,"%d",&size);
            arr[j] = size;
        //printf("the array is %d\n",arr[j] );
        }
          mat1[i] = arr;
    }

//CREATE MATRIX2
int row2;
int col2;
  fscanf(fp, "%d %d",&row2,&col2);
        //printf("the second row and column is: %d %d\n",row2,col2 );
        if(col!=row2){
          printf("bad-matrices\n");
          exit(0);
        }


int**mat2;
int*arr2;

  mat2=(int**)malloc(row2*sizeof(int*));
    for(i=0;i<row2;i++){
  arr2=(int*)malloc(col2*sizeof(int));
  for(j=0;j<col2;j++){
    fscanf(fp,"%d",&size);
    arr2[j]=size;
     //printf("the second array is %d\n",arr2[j] );
  }
    mat2[i]=arr2;
  }

//FIND PRODUCT OF MATRICES


int** mult;

mult=(int**)malloc(row*sizeof(int*));
//int mult[row][col2]={{0}};


for(i=0;i<row;i++){
  mult[i]=(int*)malloc(col2*sizeof(int));
}
for(i=0;i<row;i++){
  for(j=0;j<col2;j++){
    mult[i][j]=0;
  }
}
//printf("%d\n", mult[0][0]);
int a;
int b;
int c;

for(a=0;a<row;a++){
  for(b=0;b<col2;b++){
    for(c=0;c< col;c++){
      mult[a][b]=mult[a][b]+mat1[a][c]*mat2[c][b];
      //printf("mult is: %d\n",mult[a][b] );
    }
    //printf("\n");
  }
}




printMatrix(mult,row,col2);
    for(i = 0; i < row; i++){
        free(mat1[i]);
    }
    for(i = 0; i < row2; i++){
        free(mat2[i]);
    }
    for(i = 0; i < row; i++){
        free(mult[i]);
    }
    free(mat1);
    free(mat2);
    free(mult);
  return 0;

  }

void printMatrix(int** final, int r, int c){


int x;
int z;
    //int i,j;
    for(x = 0; x < r; x++){
        for(z = 0; z < c; z++){
            printf("%d\t", final[x][z]);
        }
        printf("\n");
    }
}
