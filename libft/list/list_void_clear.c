/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_void_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:31:19 by kaara             #+#    #+#             */
/*   Updated: 2025/03/30 15:57:23 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	list_void_clear(t_list *list)
{
	t_list *head;

	if (list == NULL)
		return ;
	head = list;
	list_void_clear(head->next);
	// if (head->element.str != NULL)
	// 	free(head->element.str);
	// else if (head->element.arr != NULL)
	// 	free(head->element.arr);
	free(head);
}
