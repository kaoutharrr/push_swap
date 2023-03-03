/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 02:30:11 by kkouaz            #+#    #+#             */
/*   Updated: 2023/03/03 21:24:26 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

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

// 			if ((*a)->content >= arr[start] && (*a)->content <=
// arr[end]) 				push_b(a, b);
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

void sort_100(t_list **a, t_list **b, int size, int *arr) {
  int index;
  int mid;
  int offset;
  int start;
  int end;
  int lsize;
  int i;
  int max;
  // int an;
  //   int min;

  // t_list *last;

  mid = ((size - 1) / 2);
  offset = size / 8;
  start = mid - offset;
  end = mid + offset;
  lsize = lstsize(*a);
  // index = get_index(*a, arr[start], arr[end]);

  while (*a) {
    index = get_index(*a, arr[start], arr[end]);

    if (index == -1) {
      // index = get_index(*a, arr[start], arr[end]);
      start -= offset;
      end += offset;
      if (start < 0)
        start = 0;
      if (end >= size)
        end = size - 1;
    } else {
      lsize = lstsize(*a);
      i = 0;
      if (index <= lsize / 2)
        while (i++ < index)
          rotate_a(a);
      else if (index > lsize / 2)
        while (i++ < lsize - index)
          reverse_a(a);

      // index = get_index(*a, arr[start], arr[end]);
      // if ((*a)->content < arr[start] || (*a)->content > arr[end])
      // {

      // 	index = get_index(*a, arr[start], arr[end]);
      // 	if (index < lsize / 2)
      // 		rotate_a(a);
      // 	else
      // 		reverse_a(a);

      // }
      push_b(a, b);
      // lsize= lstsize(*a);
      if ((*b)->content < mid)
        rotate_b(b);
    }
  }

  while (*b) {
    // min = min_list(*b);
    max = arr[end];
    // last = ft_lstlast(*b);
    if ((*b)->content == max) {
      push_a(a, b);
      end--;
      size--;
    }
    // else if (is_sorted_stack(*a) || (*b)->content > ft_lstlast(*a)->content)
    else {
      index = get_index_list(max, *b);
      if (index < size / 2)
        rotate_b(b);
      else
        reverse_b(b);
    }
    // print_list(*b);
  }
  // print_list(*a);
  // an = is_sorted_list(*b);
  // printf("%d", an);
}

int get_index_list(int max, t_list *stack) {
  int i;

  i = 0;
  while (stack) {
    if (stack->content == max)
      return (i);
    i++;
    stack = stack->next;
  }
  return (-1);
}

void sort_500(t_list **a, t_list **b, int size, int *arr) {
  int index;
  int mid;
  int offset;
  int start;
  int end;
  int lsize;
  int i;
  int max;
  int bottom = 0;
  // int an;
  //   int min;

  // t_list *last;

  mid = ((size - 1) / 2);
  offset =  size / 18;
  start = mid - offset;
  end = mid + offset;
  lsize = lstsize(*a);
  // index = get_index(*a, arr[start], arr[end]);

  while (*a) {
    index = get_index(*a, arr[start], arr[end]);

    if (index == -1) {
      // index = get_index(*a, arr[start], arr[end]);
      start -= offset;
      end += offset;
      if (start < 0)
        start = 0;
      if (end >= size)
        end = size - 1;
    } else {
      lsize = lstsize(*a);
      i = 0;
      if (index <= lsize / 2)
        while (i++ < index)
          rotate_a(a);
      else if (index > lsize / 2)
        while (i++ < lsize - index)
          reverse_a(a);

      // index = get_index(*a, arr[start], arr[end]);
      // if ((*a)->content < arr[start] || (*a)->content > arr[end])
      // {

      // 	index = get_index(*a, arr[start], arr[end]);
      // 	if (index < lsize / 2)
      // 		rotate_a(a);
      // 	else
      // 		reverse_a(a);

      // }
      push_b(a, b);
      // lsize= lstsize(*a);
      if ((*b)->content < mid)
        rotate_b(b);
    }
    //
  }
  
  end = size - 1;
  while (*b) {
    max = arr[end];
    index = get_index_list(max, *b);
    size = lstsize(*b);
    if ((*b)->content == max) {
      push_a(a, b);
      end--;
    }  else if (index == -1) {
      reverse_a(a);
      end--;
      bottom--;
    } else if (!bottom || (*b)->content > ft_lstlast(*a)->content) {
      push_a(a, b);
      rotate_a(a);
      bottom++;
    } else {
      if (index <= size / 2)
          rotate_b(b);
      else
          reverse_b(b);
    }
  }

  while (bottom) {
    reverse_a(a);
    bottom--;
  }
  // printf("\n bottom %d \n", bottom);
  // print_list(*a);
}


void old()
{

  /*
    while (*b)
    {
      //min = min_list(*b);
      max = arr[end];
      //last = ft_lstlast(*b);
      if((*b)->content == max)
      {
        printf("here 1\n");
        push_a(a,b);
        end--;
        size--;
      }

      else if ( *b && ft_lstlast(*a) && (is_sorted_list(*a) == 1 ||
    (*b)->content > ft_lstlast(*a)->content))
      {
        printf("here 2\n");
          push_a(a,b);
          rotate_a(a);
        // if(ft_lstlast(*a)->content == max)
        // 	reverse_a(a);
      }
      else
      {
        index = get_index_list(max, b);
        printf("here 3 : max : %d | index : %d\n", max, index);
        //if (index < size / 2)
          rotate_b(b);
        // else
        // 	reverse_b(b);
      }
    print_list(*b);

    }
    an = is_sorted_list(*b);
  printf("%d", an);

  while (*b)
  {
    max = max_list(*b);
    index = get_index_list(max, *b);
    if ((*b)->content == max)
      push_a(a, b);
    else if (index == -1)
    {
      reverse_a(a);
      bottom--;
    }
    else if (*a && (!bottom || (*b)->content > ft_lstlast(*a)->content))
    {
      push_a(a, b);
      rotate_a(a);
      bottom++;
    }
    else
    {
      int i;

      i = -1;
      if (index < size / 2)
        while (++i < index)
          rotate_b(b);
      else
        while (++i < size - index)
          reverse_b(b);
    }
    size = ft_lstsize(*b);
  }
  */
}