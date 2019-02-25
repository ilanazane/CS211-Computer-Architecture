#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

int i;

if(!argc>=2){
return EXIT_FAILURE;
}

int num=1;
while(num<argc){


for(i=0;i<strlen(argv[num]);i++){

if(argv[num][i]=='a'||argv[num][i]=='e'||argv[num][i]=='i'||argv[num][i]=='o'||
	argv[num][i]=='u'||argv[num][i]=='A'||argv[num][i]=='E'||
	argv[num][i]=='I'||argv[num][i]=='O'||argv[num][i]=='U'){
printf("%c",argv[num][i]);
}
}
num++;
}

return 0;
}
