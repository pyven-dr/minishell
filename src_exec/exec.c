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

int	exec(t_tree *node)
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
		return (exec_cmd(split_cmd));
	}
	else if (node->operand == AND)
		return (exec_and(node));
	else if (node->operand == OR)
		return (exec_or(node));
	else if (node->operand == PIPE)
		return (exec_pipe(node));
	else if (node->operand == SIMPLE_IN)
		return (exec_simple_in(node));
	else if (node->operand == SIMPLE_OUT)
		return (exec_simple_out(node));
	else if (node->operand == DOUBLE_OUT)
		return (exec_double_out(node));
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
	leftChild->name = "&&";
	leftChild->operand = AND;
	leftChild->parent = root;
	leftChild->left = NULL;
	leftChild->right = NULL;


	// Assignation des enfants à la racine
	root->left = leftChild;

		t_tree *rightChild = (t_tree *)malloc(sizeof(t_tree));
	rightChild->name = "echo cmd1";
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

	root->left->left = leftChild2;
	root->left->right = rightChild;

	t_tree *rightChild3 = (t_tree *)malloc(sizeof(t_tree));
	rightChild3->name = "echo cmd2";
	rightChild3->operand = CMD;
	rightChild3->parent = leftChild2;
	rightChild3->left = NULL;
	rightChild3->right = NULL;

	root->left->left->left = rightChild3;

	// Affichage de la structure de l'arbre
	int fd_test = open(random_name(), O_CREAT | O_WRONLY, 0777);
	write(fd_test, "salut\n",6);
	close(fd_test);

	printf("Root: %s\n", root->name);

	printf("	Left: %s\n", root->left->name);

	printf("		Left: %s\n", root->left->left->name);
	printf("		Right: %s\n", root->left->right->name);

	printf("			Left: %s\n", root->left->left->left->name);

	exec(root);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	//wait(NULL);
	// Libération de la mémoire
	free(root);
	free(leftChild);
	free(rightChild);
	free(leftChild2);
	//free(rightChild3);

	return 0;
}