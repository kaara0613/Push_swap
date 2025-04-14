# ifndef LIST_H
#define LIST_H

typedef union s_element t_element;

union s_element {
    int		i;
	int		*arr;
    char	c;
    char	*str;
} ;

typedef struct s_list t_list;

struct s_list
{
    t_list		*next;
    t_element 	element;
} ;

//list
void    list_int_insert_at(t_list **list, int n, int i);
int     list_int_pop_at(t_list **list, int n);
int     list_int_pop_back(t_list **list);
int     list_int_pop(t_list **list);
void    list_int_print(t_list *list);
void    list_int_push(t_list **list, int n);
void    list_int_rotate(t_list **list);
void	list_void_clear(t_list *list);
t_list  *list_int_clone(t_list *list);
t_list  *list_int_sort(t_list *list);
int		list_int_count(t_list *list);
int		list_int_access_at(t_list *list, int i);

#endif