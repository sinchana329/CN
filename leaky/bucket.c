#include <stdio.h>

int main() {
    int bucket_size, outgoing_rate, n;
    int incoming, stored = 0;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);
    printf("Enter outgoing rate: ");
    scanf("%d", &outgoing_rate);
    printf("Enter number of inputs: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the incoming packet size: ");
        scanf("%d", &incoming);

        if (stored + incoming > bucket_size) {
            printf("Bucket overflow! %d packets dropped.\n", (stored + incoming - bucket_size));
            stored = bucket_size;
        } else {
            stored += incoming;
        }

        printf("Bucket buffer size %d out of %d\n", stored, bucket_size);

        if (stored >= outgoing_rate) {
            stored -= outgoing_rate;
            printf("After outgoing %d packets left out of %d in buffer\n", stored, bucket_size);
        } else {
            printf("After outgoing %d packets left out of %d in buffer\n", stored, bucket_size);
            stored = 0;
        }
    }

    return 0;
}
