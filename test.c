#include "parsing.h"

int main(int argc, char **argv, char **env)
{
    if (argc)
    {
        printf("entry : %s\n", argv[1]);
        get_name(argv[1], env);
    }
}