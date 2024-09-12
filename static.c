/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgerdzhi <rgerdzhi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:41:43 by rgerdzhi          #+#    #+#             */
/*   Updated: 2024/09/02 12:42:31 by rgerdzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
 
int fun()
{
    static int count = 0;
    count++;
    return count;
}
 
int main()
{
    printf("%d ", fun());
    printf("%d ", fun());
	printf("%d ", fun());

    return 0;
}
