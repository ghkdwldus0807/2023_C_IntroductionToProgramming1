//21101989 È²Áö¿¬

#include <stdio.h>

#include <stdio.h>

int main() {
    char c;
    int count = 0;

    printf("Enter the character");

    while (1) {

        
        scanf_s(" %c", &c,1);
        if (c == '#') {
            break;
        }
        printf("%c %d ", c, (int)c);
        count++;

        if (count % 8 == 0) {
            printf("\n");
        }

        if (c == '\n') {
            getchar();
        }
    }
    printf("\nBYE!");
    return 0;
}