/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void ft_sort_id();
void ft_sort_year();
void ft_sort_faculty();
void ft_deletion();

struct l_node{
    int num;
    struct l_node* next;
};

struct s_node {
    struct l_node* data;
    struct s_node* link;
} *stack=NULL;

int*	ft_sort_int_tab(int *tab, int size)
{
	int	y = 0, swap;
	while (y < size - 1)
	{
		if (tab[y] > tab[y + 1])
		{
			swap = tab[y + 1];
			tab[y + 1] = tab[y];
			tab[y] = swap;
			y = 0;
		}
		else
			y++;
	}
    return (tab);
}
//pushing new student linked list into stack
void ft_push(struct l_node *studentLink)
{
    printf("inside push\n");
    struct s_node *newStudent;
    newStudent->data = studentLink;
    newStudent->link = stack;
    stack = newStudent;
}

void ft_deletion()
{
    printf("inside deletion\n");
    if(stack == NULL) printf("no data found\n");
    else stack = stack->link;
}

void ft_sort_year()
{
    int year_sort_array[50], i= 0, *year_sorted_array, y = 0;
    struct s_node *current = stack;
    while (current == NULL)
    {
        struct l_node *temp = current->data;
        year_sort_array[i++] = ((temp->num) % 1000000);
        current = current->link;
    }
    year_sorted_array = ft_sort_int_tab(year_sort_array, i);
    while (y < i)
    {
        struct s_node *sorting = stack;
        if (year_sorted_array[y++] == (sorting->data->num) % 1000000)
        {
            printf("%d\t",sorting->data->num);
            sorting->data = sorting->data->next;
            while (sorting->data->next)
            {
                printf("%c",(char)(sorting->data->num));
                sorting->data = sorting->data->next;
            }
        }
        sorting = sorting->link;
    }
}
int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i] != '\0')
	{
	    i++;
	}
	printf("inside strlen\n");
	return (i);
}
struct l_node *ft_input(char *st_name, int st_id)
{
    printf("%s",st_name);
    struct l_node *head = NULL, *id_node;
    int len = ft_strlen(st_name);
    printf("inside input\n");
    while (len > 0)
    {
        printf("inside loop\n");
        struct l_node *newnode;
        newnode->num = (int)(st_name[--len]);
        newnode->next = head;
        head = newnode;
    }
    id_node->num = st_id;
    id_node->next = head;
    head = id_node;
    printf("outside input\n");
    ft_push(head);
}
void theMenu(void)
{
    //char below is for no use except preventing bugs.
    char *name;
    int idnum;
    int menuInput = 0;
    printf("1- Enter school number:\n2- Display school numbers sorted by id:\n3- Display school numbers sorted by year\n4- Display school numbers sorted by the faculty codes\n5- Detele a record by school number\n6- Exit\n");
    printf("enter choice: ");
    if(scanf("%d",&menuInput)<= 0)
    {
        printf("please write a valid choice:");
        exit(0);
    }
    switch(menuInput)
    {
        case 1: printf("\nenter school number: ");
                scanf("%d",&idnum);
                printf("\nenter name: ");
                scanf("%s", name);
                ft_input(name,idnum);
        case 2: ft_sort_id;
        case 3: ft_sort_year;
        case 4: ft_sort_faculty;
        case 5: ft_deletion;
        case 6: exit(0);
    }
}
    

int main()
{
    while(1)
    {
    theMenu();
    system("cls");
    }
    return 0;
}
