#include <stdio.h>
#include "sandpiles.h"
#include <stdbool.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * split - split the sell if the number is over than 4
 * @grid: 3x3 grid
 *
 *
 * this is algrithem 1 but cannot pass all the checks
 * void split(int grid[3][3])
 * {
 *	int i, j;
 *
 *	for (i = 0; i < 3; i++)
 *	{
 *		for (j = 0; j < 3; j++)
 *		{
 *			if (grid[i][j] > 3)
 *			{
 *				grid[i][j] -= 4;
 *				if ((i - 1) >= 0)
 *					grid[i - 1][j] += 1;
 *				if ((i + 1) <= 2)
 *					grid[i + 1][j] += 1;
 *				if ((j - 1) >= 0)
 *					grid[i][j - 1] += 1;
 *				if ((j + 1) <= 2)
 *					grid[i][j + 1] += 1;
 *			}
 *		}
 *	}
 *}
 */

void split(int grid[3][3])
{
	int i, j;
	int grid_tmp[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid_tmp[i][j] = grid[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				grid[i][j] -= 4;
			if ((i - 1) >= 0 && grid_tmp[i - 1][j] > 3)
				grid[i][j] += 1;
			if ((i + 1) <= 2 && grid_tmp[i + 1][j] > 3)
				grid[i][j] += 1;
			if ((j - 1) >= 0 && grid_tmp[i][j - 1] > 3)
				grid[i][j] += 1;
			if ((j + 1) <= 2 && grid_tmp[i][j + 1] > 3)
				grid[i][j] += 1;
		}
	}
}

/**
 * check_stable - check if the grid is stable
 * @grid: 3x3 grid
 * Return: 1 if stable 0 otherwise
 */

int check_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * sandpiles_sum - sum the sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	if (check_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
	}

	while (check_stable(grid1))
	{
		split(grid1);
		if (check_stable(grid1))
		{
			printf("=\n");
			print_grid(grid1);
		}
	}
}
