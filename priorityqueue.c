
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void enQueueByPriority(int);
void deQueueByPriority(void);
void sortQueueByPriority(int);
void display(void);

int pri_que[SIZE];
int front = -1;
int rear = -1;

int main()
{
    int element, choice;

    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            printf("\nEnter value to be inserted : ");
            scanf("%d",&element);
            enQueueByPriority(element);
            break;
            case 2: deQueueByPriority();
            break;
            case 3: display();
            break;
            case 4:
            exit(0);
            default:
            printf("\nChoice is incorrect, Enter a correct choice");
        }//end switch
    }//end while-true
}//end Main

/* Function to insert value into priority queue */
void enQueueByPriority(int element)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    //Happens first time, when Q is initially empty
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = element;
        return;
    }
    /* Viva Q: Why is this else required?
     Answer: The logic of this program sorts the queue elements in descending order in below function call.
     */
    else
    sortQueueByPriority(element); //function call to sort in descending order of values

} //end enQueueByPriority


/* Function to sort my Priority Queue - basically check priority and place new value in correct position */
/* Array is sorted by descending order - meaning smallest element is at the last index */
/* "rear" always points to the last index with a valid element in the ordered Queue */

void sortQueueByPriority(int data)
{
    int i;
    for(i = rear; i>=0; i--)
    {
        if(data < pri_que[i])
        pri_que[i+1] = pri_que[i];
        else
        break;

    }//end for
    pri_que[i+1] = data;
    rear++;


}//end sortQueueByPriority

/* Function to delete an element from queue. In this case, it is assumed that the highest priority elements are always
 pointed by the index of "rear" */

void deQueueByPriority()
{
    int i;
    printf("\nIn DeQueue %d front %d rear", front, rear);
    if ((front==rear+1) || (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");

    }
    //Smallest value implies highest priority
    else
    {
        i = pri_que[front];
        printf("\n The highest priority element removed is %d", i);
        front++;
    }

}//end deQueueByPriority

/* Function to display queue elements */
void display()
{
    if ((front == -1) || (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    /*Viva Q: Why does this for-loop not have a intial condition?
     Answer: It means, "for whatever is the value of front, check if its leaa than or equal to rear.
     There is no need to specify this*/
    for (; front <=rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }

    front = 0;
}//end display
