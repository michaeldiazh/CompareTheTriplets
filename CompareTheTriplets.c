
#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 1000
// First lets make the function

int * CompareTheTriplets(int * p_alice, int * p_bob){
    // Create a array for Alice(0) and Bob(1) points respectively
    int * points = (int *) malloc(2 * sizeof(int));
    points[0] = 0; // Alice
    points[1] = 0; // Bob
    int i;

    // Traverse both Alice's and Bob's triplets 
    for(i=0;i<3;i++){
        if(p_alice[i] > p_bob[i]){
            points[0]++; // Give point to Alice
            continue;
        }
        if(p_alice[i]<p_bob[i]){
            points[1]++; // Give point to Bob
            continue;
        }
    }
    return points;


}

int main(){
    // Create a file_pointer
    FILE *file_pointer;
    
    // Let create a str pointer
    char * str = (char *)malloc(MAXCHAR);
    
    // Then specify the path of the file
    char * filename = "/Users/seppuku_kum/Desktop/CFolder/Coding_Challenges/CompareTheTriplets/input07.txt";

    file_pointer = fopen(filename,"r");
    
    // Participants string 
    int * alice_points = (int *)(malloc(3*sizeof(int)));
    int * bob_points = (int *)(malloc(3*sizeof(int)));
    
    // Put participents in an array of pointers
    int *participants[2];
    participants[0] = alice_points;
    participants[1] = bob_points;

    // Initalize the var that will be used in the while loop
    int participant = 0;
    int index, p_index;

    
    while(fgets(str,MAXCHAR,file_pointer)!=NULL){
        index = 0;
        p_index=0;
        // Iterate the str until it reaches the null terminator
        //First is Alice, then Bob
        
        while(str[index] != '\0'){
            int hold = atoi(&str[index]);
            *(participants[participant] + p_index) = hold;
            index+=2; p_index++;
        }
        participant++; 
    }
    fclose(file_pointer);
    int * compare_val = CompareTheTriplets(alice_points, bob_points);
    printf("Alice has: %d \nBob has: %d \n",compare_val[0],compare_val[1]);
    // Free Memory 
    free(alice_points);
    free(bob_points);
    
    return 0;

}