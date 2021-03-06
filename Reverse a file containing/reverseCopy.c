#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE* file;
    FILE* reverse;

    char filename[1024];
    char reversefilename[1024];

    printf("Please enter the normal file name : ");
    scanf("%s" , filename);

    printf("Now enter the file , where you want to reverse the %s containing : " , filename);
    scanf("%s" , reversefilename);

    file = fopen(filename , "r");
    reverse = fopen(reversefilename , "w");
	
    if(file == NULL || reverse == NULL){
        perror("Error while opening files\n");
        exit(0);
    }

    fseek(file , 0 , SEEK_END);
    int lengthofFile = ftell(file);
    fseek(file , -1 , SEEK_CUR);

    while(lengthofFile > 0){
        char c = fgetc(file);
        fputc(c , reverse);
        fseek(file , -2 , SEEK_CUR);
        --lengthofFile;
    }

    fclose(file);
    fclose(reverse);
}
