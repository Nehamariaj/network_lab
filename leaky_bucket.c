#include<stdio.h>
#include <unistd.h>

int leaky_bucket() {
    int bucket_capacity = 20, leak_rate = 2, water_level = 0, incoming_data;

    printf("Starting the Leaky Bucket simulation...\n");
    printf("Bucket capacity: %d units\n", bucket_capacity);
    printf("Leak rate: %d units per second\n", leak_rate);

    while (1) {
        printf("\nEnter the number of data units to be added to the bucket (enter 0 to stop): ");
        scanf("%d", &incoming_data);

        if (incoming_data == 0) {
            printf("Exiting simulation...\n");
            break;
        }

        if (incoming_data <= 0) {
            printf("Invalid input! The number of data units must be positive.\n");
            continue;
        }

        int remaining_space = bucket_capacity - water_level;

        if (remaining_space > 0) {
            if (incoming_data <= remaining_space) {
                water_level += incoming_data;
                printf("Data added: New water level = %d units\n", water_level);
            } else {
                water_level = bucket_capacity;
                printf("Bucket is full! Adding data up to capacity. New water level = %d units\n", water_level);
            }
        } else {
            printf("Bucket overflows! The data cannot be added.\n");
            continue;
        }

        sleep(1);

        if (water_level > leak_rate) {
            water_level -= leak_rate;
        } else {
            water_level = 0;
        }

        printf("After leak: Water level = %d units\n", water_level);
    }

    printf("Final water level = %d units\n", water_level);
    return 0;
}

int main() {
    leaky_bucket();
    return 0;
}
