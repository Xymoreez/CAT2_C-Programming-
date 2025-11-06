i) An array is a data structure that stores a collection of elements of the same data type in contiguous memory locations. It allows for efficient access to elements using an index.
//question 1
//ii)
  #include <stdio.h>




int main() {

    // Declare and initialize a 2D array with 2 rows and 2 columns

    int scores[2][2][2] = {

  {{65, 92}, {84, 72}}

  {{84, 72}, {59, 67}}

    };

 return 0;

}
//question 1
//iii)
#include <stdio.h>




int main() {

    int scores[2][2][2] = {

        { {65, 92}, {84, 72} }, // layer 0

        { {35, 70}, {59, 67} } // layer 1

    };




    for (int layer = 0; layer < 2; layer++) {

        printf("Layer %d:\n", layer);

        for (int i = 0; i < 2; i++) {

            for (int j = 0; j < 2; j++) {

                printf("%d ", scores[layer][i][j]);

            }

            printf("\n");

        }

    }

    return 0;

}
