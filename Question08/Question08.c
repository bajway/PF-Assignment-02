/*
Name: Kashif Mehmood
Roll No: 24K-2539
Date: 25/10/24
Desc: Number conversion calculator
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h> //Using to convert letters into upper-case

//Function prototypes
int binary_to_decimal(int);
int decimal_to_binary(int);
void decimal_to_hexadecimal(int);
void hexadecimal_to_decimal(char *);
void binary_to_hexadecimal(int);
void hexadecimal_to_binary(char *);

int main(){
    int option, bin_number, dec_number;
    char hex_number[20] = {0};
    printf("MENU\n");
    printf("1. BinaryToDecimal\n");
    printf("2. DecimalToBinary\n");
    printf("3. DecimalToHexadecimal\n");
    printf("4. HexadecimalToDecimal\n");
    printf("5. BinaryToHexadecimal\n");
    printf("6. HexadecimalToBinary\n");
    printf("7. Exit\n\n");
    printf("Select an option from above to proceed:");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("Enter a binary number (e.g: 1011101):");
        scanf("%d", &bin_number);
        printf("Decimal Equivalent of %d is %d", bin_number, binary_to_decimal(bin_number));
        break;
    case 2:
        printf("Enter a decimal number (e.g: 212):");
        scanf("%d", &dec_number);
        bin_number = decimal_to_binary(dec_number);
        printf("Binary equivalent of %d is %d", dec_number, bin_number);
        break;
    case 3:
        printf("Enter a decimal number (e.g: 212):");
        scanf("%d", &dec_number);
        decimal_to_hexadecimal(dec_number);
        break;
    case 4:
        printf("Enter a hexadecimal number:");
        getchar();
        fgets(hex_number, 20, stdin);
        hex_number[strcspn(hex_number,"\n")] = '\0';
        hexadecimal_to_decimal(hex_number);
        printf("\n");
        break;
    case 5:
        printf("Enter a binary number: ");
        scanf("%d", &bin_number);
        binary_to_hexadecimal(bin_number);
        break;
    case 6:
        printf("Enter a hexadecimal number: ");
        getchar();
        fgets(hex_number, 20, stdin);
        hex_number[strcspn(hex_number,"\n")] = '\0';
        hexadecimal_to_binary(hex_number);
        printf("\n");
        break;
    case 7:
        return 0;
    }

    return 0;
}

//Function Definitions

int binary_to_decimal(int num) {
    int dec_num = 0, i = 0;
    while (num > 0) {
        int digit = num % 10;
        if (digit != 0 && digit != 1) {
            printf("Invalid binary number.\n");
            return -1;  // Return error code
        }
        dec_num = dec_num + (digit) * pow(2, i);
        num = num / 10;
        i++;
    }
    return dec_num;
}

int decimal_to_binary(int num) {
    int bin_num = 0, remainder, index = 1;

    while (num > 0) {
        remainder = num % 2;
        bin_num += remainder * index;
        num /= 2;
        index *= 10;
    }
    return bin_num;
}

void decimal_to_hexadecimal(int num) {
    char hex_digits[20];   //Array to store hexadecimal digits
    int index = 0;
    //Condition for 0 case
    if (num == 0) {
        printf("0");
        return;
    }
    //Dummy array
    char hex_map[] = "0123456789ABCDEF";
    //Convert decimal to hexadecimal
    while (num > 0) {
        int remainder = num % 16;
        hex_digits[index] = hex_map[remainder];
        num /= 16;
        index++;
    }
    //Printing hexadecimal number
    printf("Hexadecimal equivalent of decimal is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex_digits[i]);
    }
}

void hexadecimal_to_decimal(char *hex_number) {
    int decimal_value = 0;
    int base = 1, digit_value;
    for (int i = strlen(hex_number) - 1; i >= 0; i--) {
        char hex_digit = toupper(hex_number[i]);
        digit_value = 0;
        // Converting to uppercase
        if (hex_digit >= '0' && hex_digit <= '9')
            digit_value = hex_digit - '0';
        else if (hex_digit >= 'A' && hex_digit <= 'F')
            digit_value = hex_digit - 'A' + 10;  //Converting A-F to 10-15
        else {
            printf("Input valid hexadecimal number\n");
            return;
        }
        decimal_value += digit_value * base;
        base *= 16;
    }

    printf("Decimal equivalent of the hexadecimal number is %d", decimal_value);
}

void binary_to_hexadecimal(int binary) {
    int z = binary_to_decimal(binary);
    if (z != -1) {
        decimal_to_hexadecimal(z);
    }
}

void hexadecimal_to_binary(char *hex_number) {
    for (int i = 0; i < strlen(hex_number); i++) {
        char digit_value = hex_number[i];
        digit_value = toupper(digit_value);

        if ((digit_value <= '9' && digit_value >= '0') || (digit_value <= 'F' && digit_value >= 'A')) {
            if (digit_value == '0') {
                printf("0000");
            } else if (digit_value == '1') {
                printf("0001");
            } else if (digit_value == '2') {
                printf("0010");
            } else if (digit_value == '3') {
                printf("0011");
            } else if (digit_value == '4') {
                printf("0100");
            } else if (digit_value == '5') {
                printf("0101");
            } else if (digit_value == '6') {
                printf("0110");
            } else if (digit_value == '7') {
                printf("0111");
            } else if (digit_value == '8') {
                printf("1000");
            } else if (digit_value == '9') {
                printf("1001");
            } else if (digit_value == 'A') {
                printf("1010");
            } else if (digit_value == 'B') {
                printf("1011");
            } else if (digit_value == 'C') {
                printf("1100");
            } else if (digit_value == 'D') {
                printf("1101");
            } else if (digit_value == 'E') {
                printf("1110");
            } else if (digit_value == 'F') {
                printf("1111");
            }
        } else {
            printf("Invalid input\n");
            return;
        }
    }
}
