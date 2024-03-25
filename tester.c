#include "parsing.h"

int main(void)
{
    char    *str;
	int		i = 0;
	t_tree	*tree;
	
	while (i < 1)
	{
    	str = readline("minishell$");
		tree = parse(str);
		print_tree(tree);
		i++;
		// free(tree->left->name);
		// free(tree->left);
		// free(tree->name);
		// free(tree);
	}

}
