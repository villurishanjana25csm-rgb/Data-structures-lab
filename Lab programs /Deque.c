#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int isFull()
{
    return (front == 0 && rear == MAX - 1) ||
           (front == rear + 1);
}

int isEmpty()
{
    return front == -1;
}

void insertFront(int x)
{
    if (isFull())
    {
        printf("Deque is Full\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    dq[front] = x;
}

void insertRear(int x)
{
    if (isFull())
    {
        printf("Deque is Full\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    dq[rear] = x;
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted from Front: %d\n", dq[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted from Rear: %d\n", dq[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");

    i = front;

    while (1)
    {
        printf("%d ", dq[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int ch, x;

    do
    {
        printf("\n--- DEQUE OPERATIONS ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertRear(x);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 0:
                printf("Program Ended\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (ch != 0);

    return 0;
}
