#include <stdio.h>
#include <stdlib.h>

void ft_sort_id();
void ft_sort_year();
void ft_sort_faculty();
void ft_deletion();

struct l_node{
    int num;
    char *name;
    struct l_node* next;
}*head = NULL;

struct s_node {
    struct l_node* data;
    struct s_node* link;
} *stack=NULL;

int*	ft_sort_int_tab(int *tab, int size)
{
	int	y;
	int	swap;

	y = 0;
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
    struct s_node *newStudent;
    newStudent->data = studentLink;
    newStudent->link = stack;
    stack = newStudent;
    printf("inside push\n");
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
    struct s_node *temp = stack;
    while (temp == NULL)
    {
        year_sort_array[i++] = ((temp->data->num) % 1000000);
        temp = temp->link;
    }
    year_sorted_array = ft_sort_int_tab(year_sort_array, i);
    while (y < i)
    {
        struct s_node *sorting = stack;
        if ( year_sorted_array[y] == (sorting->data->num) % 1000000)
        {
            printf("%d\t%s\n",sorting->data->num,sorting->data->name);
        }
    }
    
}

struct l_node *ft_input(char* st_name, int st_id)
{
    printf("inside input\n");
    struct l_node *new_student;
    new_student->num = st_id;
    new_student->name = st_name;
    return (new_student);
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
                ft_push(ft_input(name,idnum));
                printf("outside push\n");
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