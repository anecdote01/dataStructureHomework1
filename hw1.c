#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining a node struct. it will hold student's informations.
struct node{
    int num;
    char name[50];
    struct node* next;
};

//this function will delete the node having specified id number
struct node* ft_deletion(struct node *stack,int delnum)
{
    //one struct for current node, one for the node you're willing to delete
    struct node *curr = stack, *freenode;
    //if stack is empty,  it will warn you
    if(stack == NULL) 
    {
        printf("no data found to delete/sort!\n");
        return stack;
    }
    //if first node is the searched node, it will delete it first.
    if(curr->num == delnum)
    {
        freenode = curr;
        curr = curr->next;
        free(freenode);
        return curr;
    }
    //searching the node
    while (curr->next)
    {
        if(curr->next->num == delnum)
            break;
        else
            curr = curr->next;
    }
    //if numbers doesn't match, it will execute the condition below
    if(curr->next == NULL)
        printf("numbers not matched..\n");
    //otherwise it will execute the condition below and delete the specified node
    else
    {
        freenode = curr->next;
        curr->next = curr->next->next;
        free (freenode);
    }
    return stack;
}

//this function will push the nodes from back. it will go like head-1.-2.-4.-5.-Null
struct node *ft_push(char nam[50], int id,struct node * stack)
{
    struct node *curr , *new_student;
    new_student = malloc(sizeof(struct node));
    //strcpy will copy the variable 'nam' into newstudent's name.
    strcpy(new_student->name, nam);        
    new_student->num = id;     
    new_student->next = NULL;                                                
    curr = stack; 
    if (!stack)
        return new_student;

    while (curr->next)
        curr=curr->next;
    curr->next=new_student;
    
    return stack;
}
/*
struct node* ft_push(char st_name[50], int st_id,struct node *stack)
{
    struct node *new_student = malloc(sizeof(struct node));
    new_student->num = st_id;
    new_student->next = NULL;
    strcpy(new_student->name , st_name);
    if ( stack == NULL)
        return new_student;
    new_student->next = stack;
    stack = new_student;
    return stack;
} 
*/
struct node* ft_sorter(struct node* stack, int mod)
{
    struct node *sorted_stack = (struct node*)malloc(sizeof(struct node));
    struct node *curr, *min_node;
    int id;
    sorted_stack = NULL;
    if(stack == NULL)
        return stack;
    while (stack)
    {
        curr = stack;
        id = curr->num;
        min_node = curr;
        while (curr)
        {
            if((id % mod) <= (curr->num % mod))
                curr = curr->next;
            else if ((id % mod) > (curr->num % mod))
            {
                min_node = curr;
                id = min_node->num;
                curr = curr->next;
            }
        }
        sorted_stack = ft_push(min_node->name,min_node->num,sorted_stack);
        stack = ft_deletion(stack,min_node->num);
    }
    return sorted_stack;
}

int main()
{
    struct node *stack = NULL;
    struct node *curr;
    char name[50];
    char surname[50];
    int idnum;
    int menuInput;
    printf("1- Enter school number:\n2- Display school numbers sorted by id:\n3- Display school numbers sorted by year\n4- Display school numbers sorted by the faculty codes\n5- Detele a record by school number\n6- Exit\n");
    while(1)
    {
        printf("enter choice: ");
        scanf("%d",&menuInput);
        if(menuInput <= 0 || menuInput >=7)
            printf("please write a valid choice between 1-5\n");
        else
        {
            switch(menuInput)
            {
                case 1: printf("\nenter school number: ");
                        scanf("%d",&idnum);
                        if((idnum / 100000000) <= 0 || (idnum / 100000000) > 9)
                            {
                                printf("invalid id!\n");
                                break;
                            }
                        printf("enter first name: ");
                        scanf("%s", name);
                        printf("enter surname: ");
                        scanf("%s",surname);
                        strcat(name," ");
                        strcat(name,surname);
                        stack = ft_push(name,idnum,stack);
                        break;
                case 2: 
                    stack = ft_sorter(stack,10000);
                    curr = stack;
                    printf("////////Sorted by ID:\\\\\\\\\n");
                    break;
                case 3: 
                    stack = ft_sorter(stack,1000000);
                    curr = stack;
                    printf("///////Sorted by year\\\\\\\\\\\n");
                    break;
                case 4: 
                    stack = ft_sorter(stack,1000000000);
                    curr = stack;
                    printf("///////Sorted by faculty code\\\\\\\\\\\n");
                    break;
                case 5:
                    printf("enter school number you want to delete: ");
                    scanf("%d",&idnum);
                    stack = ft_deletion(stack,idnum);
                    break;
                case 6:
                    curr = stack;
                    while (curr)
                    {
                        printf("%d\t%s\n",curr->num,curr->name);
                        curr = curr->next;
                    }
                    break;
                    exit(0);
            }
            if (menuInput <= 4 && menuInput >= 2)
            {
                while (curr)
                {
                    printf("%d\t%s\n",curr->num,curr->name);
                    curr = curr->next;
                }
                printf("\\\\\\\\\\\\_______///////\n\n");
            }
        }
    }
    return 0;
}