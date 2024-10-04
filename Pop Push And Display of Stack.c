#include<stdio.h>
void push(int *aa,int data,int *top,int size);
void pop(int *aa,int *top,int size);
void display(int *aa,int *top);

int main()
{
    int top=-1;
    int ar[100],choice,n,x,i;
    printf("\n Enter the size of the stack[max:100]:");
    scanf("%d",&n);
    printf("\n STACK OPERATIONS USING ARRAY:");
    printf("\n 1.Push \n 2.Pop \n 3.Display \n 4.Exit");
    do
    {
        printf("\n Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {
                        printf("Enter value to be pushed:");
                        scanf("%d",&x);
                        push(ar,x,&top,n);
                        break;
                    }
            case 2: {
                        pop(ar,&top,n);
                        break;
                    }

            case 3: display(&top,ar);
                    break;
            case 4: exit(0);
            default:
                    printf("\n Invalid Entry");
        }
    }while(choice!=4);

}
void push(int *aa ,int data ,int *top ,int size)
{
    if(*top>=size-1)
    {
        printf("The stack is overflow");
    }
    else
    {
        (*top)++;
        aa[*top]=data;
    }
}

void pop(int *aa,int *top,int size)
{
    if(*top<=-1)
    {
        printf("\n Stack is underflow");
    }
    else
    {
        printf("The popped element is %d",aa[*top]);
        (*top)--;
    }
}

void display(int *top,int *aa)
{
    if(*top>-1)
    {
        printf("The elements is stack are:");
        for(int i=*top;i>=0;i--)
        {
            printf("\n%d",aa[i]);
        }

    }
    else
        printf("\n the stack is empty");

}
