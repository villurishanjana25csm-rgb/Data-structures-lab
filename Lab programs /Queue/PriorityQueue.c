#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int priority[SIZE];
int n = 0;

void enqueue()
{
    int x, p;

    if (n == SIZE)
    {
        printf("Priority Queue is Full\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    printf("Enter priority: ");
    scanf("%d", &p);

    queue[n] = x;
    priority[n] = p;
    n++;

    printf("Element inserted successfully\n");
}

void dequeue()
{
    int i, pos = 0;

    if (n == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    for (i = 1; i < n; i++)
    {
        if (priority[i] < priority[pos])
            pos = i;
    }

    printf("Deleted element: %d\n", queue[pos]);

    for (i = pos; i < n - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;
}

void display()
{
    int i;

    if (n == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("\nElement\tPriority\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\n", queue[i], priority[i]);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
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
