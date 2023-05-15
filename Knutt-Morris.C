#include <stdio.h>
#include <string.h>

int main() {
    char str[64];
    char word[20] = "abc";
    
    int i = 0;
    int j = 0;
    int index = 0;
    int length = 0;
    
    printf("Enter string: ");
    scanf("%s", str);
    
    while (i < strlen(str) && j < strlen(word)) {
        if (str[i] == word[j]) {
            if (j == 0) {
                index = i;
            }
            i++;
            j++;
        } else {
            i = index + 1;
            j = 0;
        }
    }
    
    if (j == strlen(word)) {
        printf("Word '%s' found from index %d to %d.\n", word, index, index + j - 1);
    } else {
        printf("No word found in the string.\n");
    }
    
    return 0;
}
