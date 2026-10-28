#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void initialize()
{
    int i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key)
{
    int index, i;

    index = key % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == -1)
        {
            hashTable[pos] = key;
            printf("Element inserted successfully\n");
            return;
        }
    }

    printf("Hash table is full\n");
}

void search(int key)
{
    int index, i;

    index = key % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        int pos = (index + i) % SIZE;

        if (hashTable[pos] == key)
        {
            printf("Element found at index %d\n", pos);
            return;
        }

        if (hashTable[pos] == -1)
            break;
    }

    printf("Element not found\n");
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d --> ", i);

        if (hashTable[i] == -1)
            printf("Empty\n");
        else
            printf("%d\n", hashTable[i]);
    }
}

int main()
{
    int choice, key;

    initialize();

    while (1)
    {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
