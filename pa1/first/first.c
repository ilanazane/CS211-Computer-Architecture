#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

int size;
FILE*fp;
fp=fopen(argv[1],"r");
fscanf(fp,"%d",&size);
int array1[size];
int q;
for(q=0;q<size;q++){
    fscanf(fp,"%d\t",&array1[q]);

}
//first find size of array to create, then find numbers
int evens=0;
int odds=0;
int i;
//printf("%d,%d",evens, odds );

for (i=0;i<size;i++){
	if (array1[i]%2==0){
		evens++;
	}else odds++;
}


int* even = (int*)malloc(evens*sizeof(int));
int* odd = (int*)malloc(odds*sizeof(int));

//ADD EVEN NUMBERS TO ARRAY
int y=0;
int counter=0;

for(y=0;y<size;y++){
    //printf("%d ", array1[y]);

    if(array1[y]%2==0){
        even[counter]=array1[y];
        counter++;
    }
}

//SORT EVEN NUMBERS

int temp;
int a;
int b;
for( a=0;a<evens;a++){

for( b=a+1;b<evens;b++){

if(even[b]<even[a]){

temp=even[b];
even[b]=even[a];
even[a]=temp;
}
}


}
//SEPARATE ODD NUMBERS INTO THE ARRAY

int yy=0;
counter=0;
for(yy=0;yy<size;yy++){
    //printf("%d ", array1[yy]);
    if(array1[yy]%2!=0){

        odd[counter]=array1[yy];
        counter++;
    }
}

//SORT ODD NUMBERS
int tempo;
int aa;
int bb;
for( aa=0;aa<odds;aa++){
for( bb=aa+1;bb<odds;bb++){
if(odd[bb]>odd[aa]){
tempo=odd[bb];
odd[bb]=odd[aa];
odd[aa]=tempo;
}
}
}

int k;
for( k=0;k<odds;k++){
  //printf("%d\t",odd[k]);
}


//MERGE ARRAYS
int z;
int m=0;

for(z=0;z<evens;z++){
  array1[z]=even[m];
  m++;
}

int u=0;
for(z=m;z<m+odds;z++){
  array1[z]=odd[u];
  u++;
}

for(k=0;k<size;k++){
  printf("%d\t",array1[k]);

}

return 0;
}

