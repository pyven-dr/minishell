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
	char **split_cmd = ft_split(node->name, ' '); //Temporary split waiting for expand

	split_cmd[0] = get_cmd_path(split_cmd[0]);
	if (split_cmd[0] == NULL)
		return (127);
	if (node->operand == CMD)
		exec_cmd(split_cmd);
	return (0);
}

int main(void)
{
	t_tree *root = (t_tree *)malloc(sizeof(t_tree));
	root->name = "AND";
	root->operand = AND;
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;

	t_tree *leftChild = (t_tree *)malloc(sizeof(t_tree));
	leftChild->name = "ls -la";
	leftChild->operand = CMD;
	leftChild->parent = root;
	leftChild->left = NULL;
	leftChild->right = NULL;

	t_tree *rightChild = (t_tree *)malloc(sizeof(t_tree));
	rightChild->name = "PIPE";
	rightChild->operand = PIPE;
	rightChild->parent = root;
	rightChild->left = NULL;
	rightChild->right = NULL;

	// Assignation des enfants à la racine
	root->left = leftChild;
	root->right = rightChild;

	t_tree *rightChild2 = (t_tree *)malloc(sizeof(t_tree));
	rightChild2->name = "ls";
	rightChild2->operand = CMD;
	rightChild2->parent = rightChild;
	rightChild2->left = NULL;
	rightChild2->right = NULL;

	t_tree *rightChild3 = (t_tree *)malloc(sizeof(t_tree));
	rightChild3->name = "cat";
	rightChild3->operand = CMD;
	rightChild3->parent = rightChild;
	rightChild3->left = NULL;
	rightChild3->right = NULL;

	root->right->left = rightChild2;
	root->right->right = rightChild3;

	// Affichage de la structure de l'arbre
	printf("Root: %s\n", root->name);
	printf("	Left: %s\n", root->left->name);
	printf("	Right: %s\n", root->right->name);
	printf("		Right: %s\n", root->right->right->name);
	printf("		Left: %s\n", root->right->left->name);

	exec(leftChild);
	wait(NULL);
	// Libération de la mémoire
	free(root);
	free(leftChild);
	free(rightChild);
	free(rightChild2);
	free(rightChild3);

	return 0;
}