#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h> //Using to convert letters into upper-case
//Functions prototypes
int binary_to_decimal(int);
int decimal_to_binary(int);
void decimal_to_hexadecimal(int);
void hexadecimal_to_decimal(char *);
void binary_to_hexadecimal(int);
void hexadecimal_to_binary(char);
int main(){
    int option, bin_number,dec_number;
    char hex_number[] = {"0123456789ABCDEF"};
    printf("******MENU******\n");
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
        binary_to_decimal(bin_number);
        printf("Decimal Equivalent of %d is %d", bin_number, binary_to_decimal(bin_number));
        break;
    case 2:
        printf("Enter a decimal number (e.g: 212):");
        scanf("%d", &dec_number);
        bin_number= decimal_to_binary(dec_number);
        printf("Binary equivalent of %d is %d", dec_number, bin_number);
        break;
    case 3:
        printf("Enter a decimal number (e.g:212):");
        scanf("%d", &dec_number);
        decimal_to_hexadecimal(dec_number);
        break;
    case 4:
    printf("Enter a hexadecimal number:");
    scanf("%s", &hex_number);
    hexadecimal_to_decimal(hex_number);
    break;
    }
}
//End main
//Function Definations
int binary_to_decimal(int num){
    int dec_num=0,i=0;
    while (num>0)
    {
    dec_num = dec_num + (num % 10)* pow(2,i);
    num = num / 10;
    i++;
    }
    return dec_num;
}
int decimal_to_binary(int num){
    int bin_num=0, remainder,index=1;

    while (num>0){
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
    if (num == 0)
    {
        printf("0");
        return;
    }
    //Dummy array
    char hex_map[] = "0123456789ABCDEF";
    //Convert decimal to hexadecimal
    while (num > 0)
    {
        int remainder = num % 16;
        hex_digits[index] = hex_map[remainder]; 
        num /= 16;
        index++;
    }//Printing hexadeccimal number
    printf("Hexadecimal equivalent of decimal is: ");
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%c", hex_digits[i]);
    }
} //End decimal_to_hexdecimal
void hexadecimal_to_decimal(char *hex_number)
 {
    int decimal_value = 0;
    int base = 1,digit_value;
    for (int i = strlen(hex_number) - 1; i >= 0; i--) {
        char hex_digit = toupper(hex_number[i]);  // Converting to uppercase
        if (hex_digit >= '0' && hex_digit <= '9') 
            digit_value = hex_digit - '0'; 
        else if (hex_digit >= 'A' && hex_digit <= 'F') 
            digit_value = hex_digit - 'A' + 10;  //Converting A-F to 10-15
        else 
            return -1; 
        }
       //Sum
        decimal_value += digit_value * base;
        base *= 16;
        printf("hexadecimal equivalent of the number is %d", decimal_value);
 } //End hexadecimal_to_decimal
