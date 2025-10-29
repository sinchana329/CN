#include <stdio.h>
#include <string.h>

void xor_operation(char *dividend, char *divisor, int start, int len) {
    for (int i = 0; i < len; i++) {
        dividend[start + i] = (dividend[start + i] == divisor[i]) ? '0' : '1';
    }
}

void compute_crc(char data[], char divisor[], char crc[]) {
    int data_len = strlen(data);
    int div_len = strlen(divisor);
    char temp[100];
    strcpy(temp, data);

    // Append (div_len - 1) zeros to data
    for (int i = 0; i < div_len - 1; i++)
        temp[data_len + i] = '0';
    temp[data_len + div_len - 1] = '\0';

    printf("\nData padded with n-1 zeroes: %s\n", temp);

    // Perform division (XOR)
    for (int i = 0; i <= strlen(temp) - div_len; i++) {
        if (temp[i] == '1')
            xor_operation(temp, divisor, i, div_len);
    }

    // Extract remainder (CRC value)
    strcpy(crc, &temp[strlen(temp) - (div_len - 1)]);
}

int main() {
    char data[100], divisor[100], crc[100], transmitted[100], received[100];
    
    printf("Enter data to be transmitted: ");
    scanf("%s", data);
    printf("Enter the divisor polynomial: ");
    scanf("%s", divisor);

    // Compute CRC
    compute_crc(data, divisor, crc);
    printf("CRC value is: %s\n", crc);

    // Form final codeword (data + crc)
    strcpy(transmitted, data);
    strcat(transmitted, crc);
    printf("Final codeword to be sent: %s\n", transmitted);

    // Receiver side
    printf("\nEnter the received data: ");
    scanf("%s", received);

    char remainder[100];
    compute_crc(received, divisor, remainder);

    // Check if remainder is all zeros
    int error = 0;
    for (int i = 0; i < strlen(remainder); i++) {
        if (remainder[i] == '1') {
            error = 1;
            break;
        }
    }

    if (error)
        printf("Error detected.\n");
    else
        printf("No error detected.\n");

    return 0;
}
