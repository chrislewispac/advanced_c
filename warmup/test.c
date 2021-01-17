# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void read_problem() {
    int num_tests = 0; 
    FILE *fp = fopen("sample.txt", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        exit(0);
    }

    // fscanf(fp, "%d", &num_tests);
    // printf("num_tests %d\n", num_tests);

    int matrix_size, num_words = 0;
    fscanf(fp, "%d", &matrix_size);
    printf("matrix_size %d\n", matrix_size);
    fscanf(fp, "%d", &num_words);
    printf("num_words %d\n", num_words);



    char buf[100];
    for (int i = 0; i < num_words; i++) {
        fscanf(fp, "%s", buf);
        printf("%s\n", buf);
    }

    fclose(fp);
}

int main() {
    read_problem();
    return 0;
}


// use structure to hold all elements of each individual structure
// and then pass a function to fill it

// create own test file with single problem