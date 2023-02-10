/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlimones <jlimones@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:21:08 by jlimones          #+#    #+#             */
/*   Updated: 2023/02/10 18:24:57 by jlimones         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
}

/**
 * @brief Pruebas
 * 
 * @param argc 
 * @param params 
 */
void	init_stacks(int argc, char **params)
{
	t_node	*nodes;
	t_node	*nodes_b;

	nodes = init_node_and_check(argc, params);
	nodes_b = NULL;
	// while (nodes)
	// {
	// 	printf("nodes = %i\n", nodes->value);
	// 	nodes = nodes->next;
	// }
	ft_push_swap(&nodes_b, &nodes);
	ft_push_swap(&nodes_b, &nodes->next);
	printf("llega\n");
	while (nodes_b)
	{
		printf("nodesb = %i\n", nodes_b->value);
		//printf("nodesb = %i\n", nodes_b->idx);
		//printf("nodesb = %i\n", nodes_b->pos_init);
		nodes_b = nodes_b->next;
	}
	while (nodes)
	{
		printf("nodes = %i\n", nodes->value);
		nodes = nodes->next;
	}
}

/**
 * @brief Inicializa las dos pilas:
 * 			En a se asigna el valor, el indice y la posicion
 * @param argc numero de arumentos
 * @param params argumentos
 * @return void* retorna el puntero al primer nodo de la pila
 */
void	*init_node_and_check(int argc, char **params)
{
	t_node	*node_a;
	char	**matrix;

	if (argc > 2)
	{
		check_param_num(argc, params);
		node_a = save_param_node_a(argc, params);
	}
	else
	{
		matrix = split_for_param(params[1]);
		argc = ft_count_num(params[1]);
		node_a = save_matrix_node_a(argc, matrix);
		free(matrix);
	}
	ft_get_pos(node_a);
	ft_get_idx(&node_a);
	return (node_a);
}

int	main(int argc, char **argv)
{
	// t_node	*nodes;
	// t_node	*nodes_b;

	atexit(leaks);
	// nodes = init_node_and_check(argc, argv);
	// nodes_b = NULL;
	init_stacks(argc, argv);
	// while (nodes)
	// {
	// 	printf("nodes = %i\n", nodes->value);
	// 	nodes = nodes->next;
	// }
	// ft_push(&nodes_b, 10000);
	// while (nodes_b)
	// {
	// 	printf("nodesb = %i\n", nodes_b->value);
	// 	nodes_b = nodes_b->next;
	// }
	return (0);
}
