#include <stdio.h>
#include <stdlib.h>
char **read_words(const char *input_filename, int *nPtr);
int main()
{
    int m; //number of words to be read from file
    char **list;
    list=read_words("words.txt",&m);
    printf("The number of words is %d\n",m);
    for(int i=0;i<m;i++){
        printf("%s\n",list[i]);
    }
    return 0;
}

char **read_words(const char *input_filename, int *nPtr){
    FILE *in=fopen(input_filename, "r");
    if(in==NULL){
        printf("The file did not open.\n"); return NULL;
    }
    else{
        //file did open
        int n; //number of words
        //read number of words from the file
        fscanf(in,"%d",&n);
        *nPtr=n;
        char **p;
        p=malloc(n*sizeof(char*));
        char temp[30];
        //allocate memory for the current string
        for(int i=0;i<n;i++){
            //read current word in temp
            fscanf(in, "%s", temp);
            //allocate memory for the current string
            p[i]=calloc(strlen(temp)+1, sizeof(char));
            //copy from temp into the new memory
            strcpy(p[i],temp);
        }//end for
        return p;
    }//end else
}//end of read_words
