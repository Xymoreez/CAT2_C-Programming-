#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define NUM_INTS 10

/* Function prototypes */
void write_input_file(void);
void process_input_file(void);
void display_files(void);

int main(void) {
    puts("=== File-based Integer Processor ===");
    write_input_file();
    process_input_file();
    display_files();
    return 0;
}

/* 1. Prompt user for NUM_INTS integers and write them to INPUT_FILE */
void write_input_file(void) {
    FILE *f = fopen(INPUT_FILE, "w");
    if (f == NULL) {
        perror("Error opening input file for writing");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d integers (separated by space or newline):\n", NUM_INTS);
    for (int i = 0; i < NUM_INTS; ++i) {
        int val;
        /* robust read from stdin */
        while (scanf("%d", &val) != 1) {
            /* Clear invalid token from stdin */
            int c;
            while ((c = getchar()) != EOF && c != '\n');
            printf("Invalid input. Please enter an integer for value %d: ", i + 1);
        }
        fprintf(f, "%d\n", val); /* store one integer per line */
    }

    if (fclose(f) == EOF) {
        perror("Error closing input file");
        exit(EXIT_FAILURE);
    }

    puts("Input saved to \"" INPUT_FILE "\".\n");
}

/* 2. Read integers from INPUT_FILE, calculate sum and average, then write to OUTPUT_FILE. */
void process_input_file(void) {
    FILE *fin = fopen(INPUT_FILE, "r");
    if (fin == NULL) {
        perror("Error opening input file for reading");
        exit(EXIT_FAILURE);
    }

    long sum = 0;
    int value;
    int count = 0;
    while (fscanf(fin, "%d", &value) == 1) {
        sum += value;
        ++count;
    }

    if (ferror(fin)) {
        perror("Error reading from input file");
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    if (fclose(fin) == EOF) {
        perror("Error closing input file after reading");
        exit(EXIT_FAILURE);
    }

    if (count == 0) {
        fprintf(stderr, "No integers found in \"%s\". Cannot compute sum/average.\n", INPUT_FILE);
        exit(EXIT_FAILURE);
    }

    double average = (double)sum / count;

    FILE *fout = fopen(OUTPUT_FILE, "w");
    if (fout == NULL) {
        perror("Error opening output file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(fout, "Count: %d\n", count);
    fprintf(fout, "Sum: %ld\n", sum);
    fprintf(fout, "Average: %.6f\n", average);

    if (fclose(fout) == EOF) {
        perror("Error closing output file");
        exit(EXIT_FAILURE);
    }

    puts("Results written to \"" OUTPUT_FILE "\".\n");
}

/* 3. Read and display the contents of both input and output files in a formatted manner */
void display_files(void) {
    FILE *f;
    int ch;

    printf("----- Contents of %s -----\n", INPUT_FILE);
    f = fopen(INPUT_FILE, "r");
    if (f == NULL) {
        perror("Error opening input file for display");
    } else {
        int line = 1;
        while (fscanf(f, "%d", &ch) == 1) {
            printf("Integer %2d: %d\n", line++, ch);
        }
        if (fclose(f) == EOF) {
            perror("Error closing input file after display");
        }
    }

    printf("\n----- Contents of %s -----\n", OUTPUT_FILE);
    f = fopen(OUTPUT_FILE, "r");
    if (f == NULL) {
        perror("Error opening output file for display");
    } else {
        /* print file line by line */
        int c;
        while ((c = fgetc(f)) != EOF)
            putchar(c);
        if (fclose(f) == EOF) {
            perror("Error closing output file after display");
        }
    }

    puts("\n=== End ===");
}
