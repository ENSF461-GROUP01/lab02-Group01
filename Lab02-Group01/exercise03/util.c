#include "util.h"

int* read_next_line(FILE* fin) {
    // TODO: This function reads the next line from the input file
    // The line is a comma-separated list of integers
    // Return the list of integers as an array where the first element
    // is the number of integers in the rest of the array
    // Return NULL if there are no more lines to read
    FILE* file = fin; 
    fin = fopen("numbers.csv", "r");
    if(fin==NULL)
    {
        perror("Error opening file.");
        return 1;
    }

    char buffer[1024]; 

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        
    }
    

}


float compute_average(int* line) {
    // TODO: Compute the average of the integers in the vector
    // Recall that the first element of the vector is the number of 
    


}


float compute_stdev(int* line) {
    // TODO: Compute the standard deviation of the integers in the vector
    // Recall that the first element of the vector is the number of integers

}