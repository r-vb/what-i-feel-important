/* There are ‘n’ different books available with a particular student. The student is
arranging the books in a shelf in the increasing order of the books height. The
arrangement of the books happen randomly. After the arrangement the books are
placed from the shortest to the tallest book from left to right. Implement this scenario
using dynamic memory allocation in C. */

/* Code: */
#include <stdio.h>
#include <stdlib.h>

int main() 
{   
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);

    int *books = (int*)malloc(n * sizeof(int)); // allocate memory for n integers
  
    // get the heights of the books
    printf("Enter the height of the books:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    // sort the books in increasing order of height
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (books[i] > books[j]) {
                // swap books[i] and books[j]
                int temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
  
    // display the arrangement of books
    printf("The arrangement of books from shortest to tallest is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", books[i]);
    }
  
    free(books); // free the dynamically allocated memory
return 0;
}
