#include <stdio.h>
#include <string.h>

void main() {
    char str[100], *start, *end;

    printf("Enter a string: ");
    scanf("%s", str);

    start = str;
    end = str + strlen(str) - 1;

    while (start < end) {
        if (*start != *end) {
            printf("Not a Palindrome\n");
            return 0;
        }
        start++;
        end--;
    }

    printf("Palindrome\n");


}
