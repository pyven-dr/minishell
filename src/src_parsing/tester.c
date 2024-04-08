#include "parsing.h"
#include "exec.h"

int main(void)
{
    char    *str;
	int		i = 0;
	t_tree	*tree;
	t_utils utils;
	
	while (1)
	{
    	str = readline("minishell$");
		tree = parse(str);

		utils.fds_vector = new_vector(10, sizeof(int));
		if (utils.fds_vector == NULL)
		{
			free_tree(&tree);
			close(STDIN_FILENO);
			close(STDOUT_FILENO);
			return (1);
		}
		if (tree != NULL)
		{
			make_all_heredocs(tree);
			exec(tree, &utils);
		}
		del_vector(utils.fds_vector);
		free_tree(&tree);
		i++;
	}
}

