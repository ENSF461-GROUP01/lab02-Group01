#include "util.h"

int* read_next_line(FILE* fin) {
    // This function reads the next line from the input file
    // The line is a comma-separated list of integers
    // Return the list of integers as an array where the first element
    // is the number of integers in the rest of the array
    // Return NULL if there are no more lines to read
   char buffer[4096];
    if (fgets(buffer, sizeof(buffer), fin) == NULL)
    {
        return NULL; //EOF
    }

    //count numbers 
    int count = 0;
    {
        char tmp[4096];
        strncpy(tmp, buffer, sizeof(tmp));
        tmp[sizeof(tmp) - 1] = '\0';
        char* tok = strtok(tmp, ",\r\n");
        while(tok != NULL)
        {
            //skip empty tokens here
            if(*tok != '\0') count++;
            tok = strtok(NULL, ",\r\n");
        }
    }
    
    if(count <= 0)
    {
        //blank line, go to next 
        return read_next_line(fin);
    }

    int* arr = (int*)malloc(sizeof(int) * (count + 1));
    if (!arr) return NULL;
    arr[0] = count;

    //parse integers
    int idx = 1;
    char* tok = strtok(buffer, ",\r\n");
    while (tok != NULL && idx <= count)
    {
        // use strtol tohandle possible spaces 
        char* endptr = NULL;
        long val = strtol(tok, &endptr, 10);
        arr[idx++] = (int)val;
        tok = strtok(NULL, ",\r\n");

    }
    return arr;

}


float compute_average(int* line) {
    // Compute the average of the integers in the vector
    // Recall that the first element of the vector is the number of 
    
    int n = line[0];
    if (n <= 0) return 0.0f;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) 
    {
        sum += line[i];
    }
    
    return (float)((double)sum / (double)n);
}


float compute_stdev(int* line) {
    // Compute the standard deviation of the integers in the vector
    // Recall that the first element of the vector is the number of integers

    int n = line[0];
    if (n <= 0) return 0.0f;

    float mean = compute_average(line);
    double acc = 0.0;

    for (int i = 1; i <= n; ++i)
    {
        double diff = (double)line[i] - (double)mean;
        acc += diff * diff;
    }
    double var = acc / (double)n; // population variance 
    
    return (float)sqrt(var);
}