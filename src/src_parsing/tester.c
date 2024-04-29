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
		print_tree(tree, 0);
		free_tree(&tree);
		i++;
	}
}

