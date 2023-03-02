/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 02:30:11 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/02 09:14:14 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	sort_100(t_list **a, t_list **b, int size, int *arr)
// {
// 	int	mid;
// 	int offset;
// 	int start;
// 	int end;
// 	int index;
// 	int lsize;
	
// 	mid =  size / 2 - 1;
// 	offset = size / 5;
// 	start = mid - offset;
// 	end = mid + offset;
	
// 	lsize = lstsize(a);

// 	while (lsize > 0)
// 	{
// 		while ((*a)->content >= arr[start] && (*a)->content <= arr[end])
// 			push_b(a, b);

// 		if(start < 0)
// 			start = 0;
// 		if (end > size)
// 			end = size;
			
// 		while((*a)->content != arr[start])
// 		{
// 			index = get_index(*a, arr[start]);
				
// 			lsize = lstsize(a);
// 			printf("appahapaaahaaappppaaaaaaaaahhhh\n");
// 			printf("%d\n",lsize);
			
// 			if(index > lsize / 2)
// 			{
// 				rotate_a(a);
// 			}
// 			else if (index <= lsize /2)
// 				reverse_a(a);
				
// 			if ((*a)->content >= arr[start] && (*a)->content <= arr[end])
// 				push_b(a, b);
// 		}
// 		// else if((*a)->content == arr[start])
// 		// 	push_b(a, b);
// 		//start++;
// 		start-= offset;
// 		end += offset;
			
// 	}
// 	print_list(*a);
// 	print_list(*b);
// }






 void	sort_100(t_list **a, t_list **b, int size, int *arr)
 {
	int index;
   int  mid;
    int offset;
    int start;
    int end;
	int lsize;
	 int max;
	//  int min;

	// t_list *last;
   
    mid = ((size - 1 )  / 2 ) ;
	offset = size / 8;
	start  = mid - offset;
	end = mid + offset;
	lsize = lstsize(*a);
	index = get_index(*a, arr[start], arr[end]); 
	
	while (*a)
	{
		index = get_index(*a, arr[start], arr[end]); 
		
		if (index == -1)
		{
			index = get_index(*a, arr[start], arr[end]); 
			start -= offset;
			end += offset;
			if(start < 0)
				start = 0;
			if(end >= size)
				end = size - 1;
		}
		else
		{
			lsize = lstsize(*a);
				index = get_index(*a, arr[start], arr[end]);
			if ((*a)->content < arr[start] || (*a)->content > arr[end])
			{		
				
				index = get_index(*a, arr[start], arr[end]); 
				if (index < lsize / 2)
					rotate_a(a);
				else
					reverse_a(a);
				
			}
			push_b(a , b);
			lsize= lstsize(*a);
			if((*b)->content < mid)
			{
				rotate_b(b);
			}
			
		}
		
 }

	while (*b)
	{
		//min = min_list(*b);
		max = max_list(*b);
		lsize = lstsize(*b);
		//last = ft_lstlast(*b);
		index = get_index_list(max, *b);
		if((*b)->content == max)
			push_a(a,b);
		else
		{
		lsize = lstsize(*b);
		index = get_index_list(max, *b);
		if (index < lsize / 2)
		{
			
				rotate_b(b);
		}
		else
		{

			reverse_b(b);
		}
	}
		// print_list(*b);
		
	}
	//print_list(*a);
  }
 
int	get_index_list(int max, t_list *a)
{
	int	i;

	i = 0;
	while(a)
	{
		if(a->content == max)
			return(i);
		i++;
		a = a->next;
	}
	return(i);
}
