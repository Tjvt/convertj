#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void decimalToBinary(long long n) {
    char bin[65];
    int i = 0;
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }
    while (n > 0) {
        bin[i++] = (n % 2) + '0';
        n /= 2;
    }
    bin[i] = '\0';
    reverse(bin);
    printf("Binary: %s\n", bin);
}

void binaryToDecimal(char *bin) {
    long long decimal = 0;
    int len = strlen(bin);
    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            decimal = (decimal << 1) | 1;
        } else if (bin[i] == '0') {
            decimal = (decimal << 1);
        } else {
            printf("Invalid binary digit!\n");
            return;
        }
    }
    printf("Decimal: %lld\n", decimal);
}

void decimalToOctal(long long n) {
    char oct[65];
    int i = 0;
    if (n == 0) {
        printf("Octal: 0\n");
        return;
    }
    while (n > 0) {
        oct[i++] = (n % 8) + '0';
        n /= 8;
    }
    oct[i] = '\0';
    reverse(oct);
    printf("Octal: %s\n", oct);
}

void octalToDecimal(char *oct) {
    long long decimal = 0;
    int len = strlen(oct);
    for (int i = 0; i < len; i++) {
        if (oct[i] >= '0' && oct[i] <= '7') {
            decimal = decimal * 8 + (oct[i] - '0');
        } else {
            printf("Invalid octal digit!\n");
            return;
        }
    }
    printf("Decimal: %lld\n", decimal);
}

void hexToBinary(char *hex) {
    printf("Binary: ");
    for (int i = 0; hex[i] != '\0'; i++) {
        switch (toupper(hex[i])) {
            case '0': printf("0000"); break;
            case '1': printf("0001"); break;
            case '2': printf("0010"); break;
            case '3': printf("0011"); break;
            case '4': printf("0100"); break;
            case '5': printf("0101"); break;
            case '6': printf("0110"); break;
            case '7': printf("0111"); break;
            case '8': printf("1000"); break;
            case '9': printf("1001"); break;
            case 'A': printf("1010"); break;
            case 'B': printf("1011"); break;
            case 'C': printf("1100"); break;
            case 'D': printf("1101"); break;
            case 'E': printf("1110"); break;
            case 'F': printf("1111"); break;
            default: printf("\nInvalid hexadecimal digit: %c\n", hex[i]); return;
        }
    }
    printf("\n");
}

void binaryToHex(char *bin) {
    int len = strlen(bin);
    int paddedLen = (len + 3) / 4 * 4;
    char paddedBin[257] = {0};
    int padding = paddedLen - len;
    
    for (int i = 0; i < padding; i++) paddedBin[i] = '0';
    strcat(paddedBin, bin);
    
    printf("Hexadecimal: ");
    for (int i = 0; i < paddedLen; i += 4) {
        int val = 0;
        for (int j = 0; j < 4; j++) {
            val = val * 2 + (paddedBin[i + j] - '0');
        }
        if (val < 10) printf("%c", val + '0');
        else printf("%c", val - 10 + 'A');
    }
    printf("\n");
}

int main() {
    int choice;
    long long decimal;
    char str[256];

    while (1) {
        printf("\n--- Number System Conversion ---\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Hexadecimal to Binary\n");
        printf("6. Binary to Hexadecimal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter decimal number: ");
                scanf("%lld", &decimal);
                decimalToBinary(decimal);
                break;
            case 2:
                printf("Enter binary string: ");
                scanf("%s", str);
                binaryToDecimal(str);
                break;
            case 3:
                printf("Enter decimal number: ");
                scanf("%lld", &decimal);
                decimalToOctal(decimal);
                break;
            case 4:
                printf("Enter octal string: ");
                scanf("%s", str);
                octalToDecimal(str);
                break;
            case 5:
                printf("Enter hexadecimal string: ");
                scanf("%s", str);
                hexToBinary(str);
                break;
            case 6:
                printf("Enter binary string: ");
                scanf("%s", str);
                binaryToHex(str);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
