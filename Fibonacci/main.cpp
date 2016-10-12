#include <iostream>
#include <stdlib.h>
#include <curl/curl.h>

using namespace std;

int fibonacci(long int n){
    
    if (n == 0)
        return 0;
    
    else if (n == 1)
        return 1;
    
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}




int main(void){
    
    int num;
    int i = 0;
    int array[20];
    
    FILE *numbers;
    FILE *result;
    
    result = fopen("/Users/robert/result.html","w");
    
    if ( result == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }

    
    numbers = fopen("/Users/robert/codingtest.txt","r");
    
    if ( numbers == NULL) {
        printf ("File not created okay, errno = %d\n", errno);
        return 1;
    }
    
    while(fscanf(numbers, "%d,", &num) > 0) {
        array[i] = num;
        i++;
    }
    fclose(numbers);
    
    
    for(int i = 0; i < 6; i++){
    
        fprintf(result,"%d, \n",fibonacci(array[i]));
        
    }
    fclose(numbers);
    fclose(result);
    
    return 0;
}
