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
    struct node *curr = stack, *freenode;    //one struct for current node, one for the node you're willing to delete

    if(stack == NULL)     //if stack is empty,  it will warn you
    {
        printf("no data found to delete/sort!\n");
        return stack;
    }
    
    if(curr->num == delnum)    //if first node is the searched node, it will delete it first.
    {
        freenode = curr;
        curr = curr->next;
        free(freenode);
        return curr;
    }

    while (curr->next)    //searching the node
    {
        if(curr->next->num == delnum)
            break;

        else
            curr = curr->next;
    }

    if(curr->next == NULL)    //if numbers doesn't match, it will execute the condition below
        printf("numbers not matched..\n");

    else    //otherwise it will execute the condition below and delete the specified node
    {
        freenode = curr->next;
        curr->next = curr->next->next;
        free (freenode);
    }
    return stack;
}
//this function will push the name and id into the stack. it will push like Head->5.->4.->3.->2.->1.->Null.
struct node* ft_push(char st_name[50], int st_id,struct node *stack)
{
    struct node *new_student = malloc(sizeof(struct node));
    //adding the name and id into created node.
    new_student->num = st_id;
    new_student->next = NULL;
    strcpy(new_student->name , st_name);
    //if stack is empty. it will return the first student.
    if ( stack == NULL)
        return new_student;
    //if stack is not empty, it will push new student into stack.
    new_student->next = stack;
    stack = new_student;
    return stack;
} 
//this function below will sort the datas. variable mod is to get the mod of the id in order to list it.
struct node* ft_sorter(struct node* stack, int mod)
{
    //struct for sorted stack, current node to hold the current node of stack & max node to hold the data of the node having max id num.
    struct node *sorted_stack = (struct node*)malloc(sizeof(struct node));
    struct node *curr, *max_node;
    int id;
    sorted_stack = NULL;
    if(stack == NULL)     //if nothing to sort, it will return null struct.
        return stack;
    while (stack)    //until stack == NULL
    {
        curr = stack;
        id = curr->num;
        max_node = curr;
        while (curr)    //until current == NULL
        {
            if((id % mod) >= (curr->num % mod)) //until finding the max id, it will keep searching
                curr = curr->next;
            else if ((id % mod) < (curr->num % mod)) // when it finds max id, it will  save it's data into max_node
            {
                max_node = curr;
                id = max_node->num;
                curr = curr->next;
            }
        }
        //sending the current max node into the push function. the big-O of sorting function is = O[n^2] (i guess?)
        sorted_stack = ft_push(max_node->name,max_node->num,sorted_stack);
        //Basiclly i used 2 stack. everytime i put one from stack into sorted_stack, it will delete the node from stack.
        stack = ft_deletion(stack,max_node->num);
    }
    return sorted_stack;
}

int main()
{
    struct node *stack = NULL, *curr;    //creating the main stack and current node
    char name[50], surname[50];     //creating to char array for name & surname
    int idnum, menuInput;
    printf("1- Enter school number:\n2- Display school numbers sorted by id:\n3- Display school numbers sorted by year\n4- Display school numbers sorted by the faculty codes\n5- Detele a record by school number\n6- Exit\n");
    while(1)
    {
        printf("enter choice: ");
        scanf("%d",&menuInput);
        if(menuInput <= 0 || menuInput >=7) // invalid menu input detector.
            printf("please write a valid choice between 1-5\n");
        else
        {
            switch(menuInput)
            {
                case 1: printf("\nenter school number: ");
                        scanf("%d",&idnum);
                        if((idnum / 100000000) <= 0 || (idnum / 100000000) > 9) //invalid id detector
                            {
                                printf("invalid id!\n");
                                break;
                            }
                        printf("enter first name: ");
                        scanf("%s", name);
                        printf("enter surname: ");
                        scanf("%s",surname);
                        strcat(name," "); // adding space next to name
                        strcat(name,surname); // adding surname next to space
                        stack = ft_push(name,idnum,stack); //pushing new data into stack
                        break;
                case 2: 
                    stack = ft_sorter(stack,10000); // 10000 stands for %10000. it will sort by ID
                    curr = stack;
                    printf("////////Sorted by ID:\\\\\\\\\n");
                    break;
                case 3: 
                    stack = ft_sorter(stack,1000000); //it will sort by year
                    curr = stack;
                    printf("///////Sorted by year\\\\\\\\\\\n");
                    break;
                case 4: 
                    stack = ft_sorter(stack,1000000000); //it will sort by faculty code
                    curr = stack;
                    printf("///////Sorted by faculty code\\\\\\\\\\\n");
                    break;
                case 5:
                    printf("enter school number you want to delete: ");
                    scanf("%d",&idnum);
                    stack = ft_deletion(stack,idnum); //it will search id in stack and then delete it
                    break;
                case 6:
                    exit(0);
            }
            if (menuInput <= 4 && menuInput >= 2) //this condition will print the IDs and names whenever we choose to print ID,year or faculty code.
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