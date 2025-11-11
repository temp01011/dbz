#include <stdio.h>
#include<stdlib.h>
 
void main(int argc, char *argv[])
{ 
   
     
    int *data = (int *) malloc((argc) * sizeof(int));
     
    printf("\n Argc:%d",argc);
    for(int i = 0;i < argc;i++) 
    {
        data[i] = atoi(argv[i]);
    }
 
   
    printf("\n Printing Element in Reverse:");
    for(int i = argc-1; i>0;i--)
    {
        printf(" %d ",data[i]);
    }
     
    printf("\n\n EXCEV task Completed \n");
}
