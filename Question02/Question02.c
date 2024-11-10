#include <stdio.h>
#include <string.h>

void frequency(const char *slogan); //Function prototype

int main() {
    const char *slogan[] = {"buy now", "save big", "limited offer"};
    int no_of_slogans = sizeof(slogan) / sizeof(slogan[0]);

    for (int i = 0; i < no_of_slogans; i++) {
        frequency(slogan[i]);
    }

    return 0;
}
//Function Defination
void frequency(const char *slogan) {
    int frequencies[128] = {0};
    int printed[128] = {0};
    int i = 0;

    while (slogan[i] != '\0') {
        frequencies[(int)slogan[i]]++;
        i++;
    }

    printf("For \"%s\": {", slogan);
    int first = 1;

    i = 0;
    while (slogan[i] != '\0') {
        int ascii_val = (int)slogan[i];
        if (frequencies[ascii_val] > 0 && !printed[ascii_val]) {
            if (!first) {
                printf(", ");
            }
            printf("'%c': %d", slogan[i], frequencies[ascii_val]);
            printed[ascii_val] = 1;
            first = 0;
        }
        i++;
    }
    printf("}\n");
}