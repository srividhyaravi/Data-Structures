#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ThreeB
{
    int rollno;
    char name[20];
    struct ThreeB *next;
}ThreeB;

void LLDemoOptions()
{
    printf("\n**** Singly Linked List Program. Having ONLY 'Insert' & 'Search' *** \n");
    printf("0.menu\n");
    printf("1.Insert Begining of Singly Linked List for ThreeB\n");
    printf("2.Insert End of Singly Linked List for ThreeB\n");
    printf("3.Search RollNo in Singly Linked List for ThreeB\n");
    printf("4.Insert After RollNo in Singly Linked List for ThreeB\n");
    printf("5.Insert Before RollNo in Singly Linked List for ThreeB\n");
    printf("6.Display Students in Singly Linked List for ThreeB\n");
    printf("-1.Quit Singly Linked List Program\n");

}//end LLDemoOptions

/* This function takes care of printing the contents of the single linked list.
 Note that 'head' pointer is always reassigned to beginning of the linked list whereever 'insertBegin' function is called. Therefore, printing always happens from beginning.
 Note: The Pointer Addresses of the current and next node are purposely given for you to understand the fundamentals of a single linked list
 */
void printThreeBDetails(ThreeB * head)
{
    if(head == NULL)
    {
        printf("Student Linked List is empty");
        printf("\nNULL");
    }
    else
    {
        ThreeB * pointer = head;
        while(pointer != NULL)
        {
            printf("\nStudent Node Created in Pointer Address ->%d.",pointer);
            printf("\nRollNo: %d -> ",pointer->rollno);
            printf("  Name: %s-> ",pointer->name); //Helps Understand funda of current node
            pointer = pointer->next;
            printf("Next student node pointer address->%d ", pointer);/*Helps Understand funda of next node */
        }//end while
    }//end else
}//end printAccountDetails

/*This is a generic function to create a new node. All four 'insert' functions call this very same function. No code-change required to handle these four insert operations.  */
ThreeB * createNewStudent(ThreeB * next,int srollno, char *sname)
{
    ThreeB * newStudent = (ThreeB *)malloc(sizeof(ThreeB));
    strcpy(newStudent->name,sname);
    newStudent->rollno = srollno;
    newStudent->next = next;
    return newStudent;
}//end createNewStudent

/* In this function 'head' pointer is always reassigned to beginning of the linked list whereever 'insertBegin' function is called. Therefore, printing always happens from beginning. */
ThreeB * insertBegin(ThreeB * head,int srollno, char *sname)
{

    if(head == NULL)
        printf("\n Congratulations - Very first student to enroll!");

    ThreeB * newStudent = createNewStudent(head,srollno, sname);
    head = newStudent; /*Very important. Dont forget this to do this!Otherwise you will never be able to print the new student node created.*/
    return head;
}//end insertBegin

/* The logic of this function expects you to traverse till the end of the linked list where the last node's next points to NULL. The new node needs to be inserted here. */
ThreeB * insertEnd(ThreeB * head, int srollno, char *sname)
{
    if(head == NULL)
        return NULL;
    else
    {
        ThreeB * pointer = head;
        while(pointer->next != NULL)
            pointer = pointer->next;
        /*Note the passing of 'NULL' as value of 'next' in 'createNewStudent' function. This is because the new node created will be the new last node in the singly linked list train. */
        ThreeB * newStudent = createNewStudent(NULL, srollno, sname);

        pointer->next = newStudent;/*Very important. Dont forget this to do this!Otherwise you will never be able to print the new student node created. The linked list chain will be broken*/
        return head;
    }
}//end of insertEnd

/*The  point to remember in the 'search' function is to return the pointer to the node which contains the 'rollno' searched. */
ThreeB * searchStudent(ThreeB *head,int srollno)
{
    ThreeB * pointer = head;
    if(head == NULL) return NULL;
    else
    {
        while(pointer != NULL)
        {
            if(pointer->rollno == srollno)
                return pointer;
            else
                pointer = pointer->next;
        }
        return NULL;
    }
}//end of searchStudent

/*In this function two pointer assignments are required
 1) Assign the 'next' of the new node created with the address of the 'next' node you need to inseret after
 2) Assign the 'next' of the node you need to insert after with the address of the new node created.
 */
ThreeB * insertAfter(ThreeB *head,ThreeB *after, int srollno,char *sname)
{
    if(head == NULL || after == NULL)
        return NULL;

    ThreeB *pointer = head;
    while(pointer != after)
        pointer = pointer->next;

    if(pointer != NULL)
    {
        /*Note the passing of 'pointer-next' to 'createNewStudent' function. One short-cut way to remember is 'insertAfter' and 'insertBefore' will have 'pointer-next' passed, while 'insertBegin' and insertEnd' will not.  */
        ThreeB *newStudent = createNewStudent(pointer->next,srollno,sname);
        pointer->next = newStudent;
        return head;
    }
    else
        return NULL;

    /*The below 4 lines is enough, for "insertAfter" instead of above code
     Didnot teach the below code in class, so as to maintain consistency with the code for
     "insertBefore" below.

     /*Funda is: "before" or "after" pointers DONOT know who is "before" that node.
     Only "next" is maintained in a singly-linked list such as "ThreeB"

     /*ThreeB *pointer = after;
     ThreeB *newStudent = createNewStudent(pointer->next,data,sname);
     pointer->next = newStudent;
     return head;*/

}//end of insertAfter

/*In this function two pointer assignments are required
 1) Assign the 'next' of the new node created with the address of the node you need to inseret before
 2) Assign the 'next' of the node previous to the one you need to insert before with the address of the new node created.
 */
ThreeB * insertBefore(ThreeB * head, ThreeB *before, int srollno,char *sname)
{
    if(before == NULL || head == NULL)
        return NULL;

    if(head == before)
    {
        head = insertBegin(head,srollno,sname);
        return head;
    }

    ThreeB *pointer = head;
    while(pointer != NULL)
    {
        /*Note the difference in condition here. It is not 'pointer' == before. This is because the node that you are currently in, knows only its 'next' node.
         It does not know its 'previous' node. To form the singly linked-list  chain, we need the new node to be connected to the previous node of 'before' which is 'pointer->next'*/
        if(pointer->next == before)
            break;
        pointer = pointer->next;
    }

    if(pointer != NULL)
    {
         /*Note the passing of 'pointer-next' to 'createNewStudent' function. One short-cut way to remember is 'insertAfter' and 'insertBefore' will have 'pointer-next' passed, while 'insertBegin' and insertEnd' will not.  */
        ThreeB *newStudent = createNewStudent(pointer->next,srollno,sname);
        pointer->next = newStudent;
        return head;
    }
    else
        return NULL;

}//end of insertBefore

int srollno;
char sname[20];

int main()
{

    int choice;


    ThreeB *head = NULL;
    ThreeB *searchptr = NULL; //This is used to find position of element searched.

    LLDemoOptions();

    while(1)
    {
        printf("\nEnter your choice(0-10,-1 to quit):");
        scanf("%d",&choice);

        if(choice == -1)
            break;
        //Caution: DONOT forget to write 'break' for every case!
        switch(choice)
        {
            case 0:
                LLDemoOptions();
                break;
            case 1:
                printf("\nEnter the Student RollNo ");scanf("%d",&srollno);
                printf("\nEnter the Student Name "); scanf("%s", sname);
                head = insertBegin(head,srollno, sname);
                printThreeBDetails(head);
                break;
            case 2:
                printf("\nEnter the Student RollNo ");scanf("%d",&srollno);
                printf("\nEnter the Student Name "); scanf("%s", sname);
                head = insertEnd(head,srollno, sname);
                printThreeBDetails(head);
                break;
            case 3:
                printf("Please enter a number to search:");
                scanf("%d",&srollno);
                searchptr = searchStudent(head,srollno);
                if(searchptr != NULL)
                {
                    printf("Student with RollNo %d found. Name is %s",searchptr->rollno, searchptr->name);
                }
                else
                {
                    printf("Student with RollNo %d not found.",srollno);
                }
                break;
            case 4:
                printf("\nEnter the Student RollNo to insert after ");scanf("%d",&srollno);
                searchptr = searchStudent(head,srollno);
                if(searchptr != NULL)
                {
                    printf("\nEnter the name of the new student "); scanf("%s", sname);
                    printf("\nEnter the rollno of the new student "); scanf("%d",&srollno);
                    head = insertAfter(head,searchptr,srollno,sname);
                    printThreeBDetails(head);
                }
                else
                {
                    printf("\nStudent with RollNo %d not found.",srollno);
                }
                break;
            case 5:
                printf("\nEnter the Student RollNo to insert before: ");
                scanf("%d",&srollno);
                searchptr = searchStudent(head,srollno);
                if(searchptr != NULL)
                {
                    printf("\nEnter the name of the new student "); scanf("%s", sname);
                    printf("\nEnter the rollno of the new student "); scanf("%d",&srollno);
                    head = insertBefore(head,searchptr,srollno,sname);

                    if(head != NULL)
                        printThreeBDetails(head);
                }
                else
                {
                    printf("\nStudent with rollno %d not found.",srollno);
                }
                break;
            case 6:
                if(head != NULL)
                    printThreeBDetails(head);
                else
                    printf("\nNo students in ThreeB!!");
                break;
        }//end switch

    }//end while

}//end main


