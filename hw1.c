#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int num;
    char name[50];
    struct node* next;
};

struct node* ft_deletion(struct node *list,int delnum)
{
    struct node *curr = list, *freenode;
    printf("inside deletion\n");
    if(list == NULL) 
    {
        printf("no data found to delete!\n");
        return list;
    }
    if(curr->num == delnum)
    {
        freenode = curr;
        curr = curr->next;
        free(freenode);
        return curr;
    }
    while (curr->next != NULL)
    {
        if(curr->next->num == delnum)
            break;
        else
            curr = curr->next;
    }
    if(curr->next == NULL)
        printf("numbers not matched..\n");
    else
    {
        curr = freenode->next;
        freenode->next = curr->next->next;
        free (freenode);
    }
    return list;
}

struct node* ft_push(char st_name[50], int st_id,struct node *stack)
{
    struct node *new_student;
    new_student->num = st_id;
    strcpy(new_student->name , st_name);
    new_student->next = stack;
    stack = new_student;
    return stack;
} 

struct node* ft_sorter(struct node* stack, int mod)
{
    struct node *sorted_stack = malloc(sizeof(struct node));
    struct node *curr, *min_num;
    int id;
    sorted_stack = NULL;
    if(stack)
        return stack;
    while (stack)
    {
        curr = stack;
        id = curr->num;
        min_num = curr;
        while (curr)
        {
            if((id % mod) <= (curr->num % mod))
                curr = curr->next;
            else
            {
                min_num = curr;
                id = min_num->num;
                curr = curr->next;
            }
        }
        sorted_stack = ft_push(min_num->name,min_num->num,sorted_stack);
        stack = ft_deletion(stack,min_num->num);
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
        if(menuInput <= 0 & menuInput >=7)
        {
            printf("please write a valid choice between 1-5\n");
            break;
        }
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
                case 4: 
                    stack = ft_sorter(stack,100000000);
                    curr = stack;
                    printf("///////Sorted by faculty code\\\\\\\\\\\n");
                case 5:
                    printf("enter school number you want to delete: ");
                    scanf("%d",&idnum);
                    stack = ft_deletion(stack,idnum);
                    break;
                case 6: 
                    while(stack)
                    {
                        printf("%d\t%s\n",curr->num,curr->name);
                        curr = curr->next;
                    }       
                    //exit(0);
            }
            if (menuInput <= 4 && menuInput >= 2)
            {
                while (curr)
                {
                    printf("%d\t%s\n",curr->num,curr->name);
                    curr = curr->next;
                }
            }
        }
    }
    return 0;
}