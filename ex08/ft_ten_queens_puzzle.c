/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:23:39 by wjo               #+#    #+#             */
/*   Updated: 2021/10/25 21:17:37 by wjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_c;

void	print(char *board)
{
	char	k;
	int		i;

	i = 0;
	while (i < 10)
	{
		k = board[i] + '0';
		write (1, &k, 1);
		i++;
	}
	write (1, "\n", 1);
}

int	check(char *board, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		if (board[i] == board[a])
			return (0);
		else if (board[i] == board[a] -(a - i))
			return (0);
		else if (board[i] == board[a] + a - i)
			return (0);
		i++;
	}
	return (1);
}

void	dfs(char	*board, int	a)
{
	int	i;

	i = 0;
	if (a == 10)
	{
		print(board);
		g_c++;
		return ;
	}
	else
	{
		while (i < 10)
		{
			board[a] = i;
			if (check(board, a))
				dfs(board, a + 1);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		i;

	i = 0;
	g_c = 0;
	dfs(board, 0);
	return (g_c);
}
