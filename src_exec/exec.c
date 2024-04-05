/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:01:47 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/03/20 00:01:47 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	exec(t_tree *node, t_utils *utils)
{
	char	**split_cmd;

	if (node->operand == CMD)
	{
		split_cmd = ft_split(node->name, ' '); //Temporary split waiting for expand
		split_cmd[0] = get_cmd_path(split_cmd[0]);
		if (split_cmd[0] == NULL)
		{
			free_cmd(split_cmd + 1);
			free(split_cmd);
			return (-127);
		}
		return (exec_cmd(split_cmd, utils));
	}
	else if (node->operand == AND)
		return (exec_and(node, utils));
	else if (node->operand == OR)
		return (exec_or(node, utils));
	else if (node->operand == PIPE)
		return (exec_pipe(node, utils));
	else if (node->operand == SIMPLE_IN)
		return (exec_simple_in(node, utils));
	else if (node->operand == SIMPLE_OUT)
		return (exec_simple_out(node, utils));
	else if (node->operand == DOUBLE_OUT)
		return (exec_double_out(node, utils));
	else if (node->operand == DOUBLE_IN)
		return (exec_double_in(node, utils));
	return (0);
}

int main(void)
{
	t_tree *root = (t_tree *)malloc(sizeof(t_tree));
	root->name = "out1";
	root->operand = SIMPLE_OUT;
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;

	t_tree *leftChild = (t_tree *)malloc(sizeof(t_tree));
	leftChild->name = "|";
	leftChild->operand = PIPE;
	leftChild->parent = root;
	leftChild->left = NULL;
	leftChild->right = NULL;

	// Assignation des enfants à la racine
	root->left = leftChild;

	t_tree *rightChild = (t_tree *)malloc(sizeof(t_tree));
	rightChild->name = "echo test1";
	rightChild->operand = CMD;
	rightChild->parent = leftChild;
	rightChild->left = NULL;
	rightChild->right = NULL;

	t_tree *leftChild2 = (t_tree *)malloc(sizeof(t_tree));
	leftChild2->name = "out2";
	leftChild2->operand = SIMPLE_OUT;
	leftChild2->parent = leftChild;
	leftChild2->left = NULL;
	leftChild2->right = NULL;

	leftChild->left = leftChild2;
	leftChild->right = rightChild;

	t_tree *rightChild3 = (t_tree *)malloc(sizeof(t_tree));
	rightChild3->name = "echo test2";
	rightChild3->operand = CMD;
	rightChild3->parent = leftChild2;
	rightChild3->left = NULL;
	rightChild3->right = NULL;

	leftChild2->left = rightChild3;

	//char *file = create_heredoc("end\n");
	//unlink(file);
	//free(file);

	printf("Root: %s\n", root->name);

	printf("	Left: %s\n", root->left->name);

	printf("		Left: %s\n", root->left->left->name);
	printf("		Right: %s\n", root->left->right->name);

	printf("			Left: %s\n", root->left->left->left->name);

	//EXEC

	t_utils utils;

	utils.fds_vector = new_vector(10, sizeof(int));
	if (utils.fds_vector == NULL)
	{
		free_tree(root);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		return (1);
	}
	make_all_heredocs(root);
	exec(root, &utils);
	del_vector(utils.fds_vector);

	close(STDIN_FILENO);
	close(STDOUT_FILENO);

	// Libération de la mémoire
	free_tree(root);

	return (0);
}