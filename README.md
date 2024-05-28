# Minishell

## As beautiful as a shell

### This project is about creating a simple shell. Yes, your own little bash. You will learn a lot about processes and file descriptors.

![minishell](https://github.com/pyven-dr/minishell/assets/150053673/2eb700f7-5e15-4ab9-8900-317d3b0e025d)

## How to use

Clone the project
```bash
git clone https://github.com/pyven-dr/minishell.git
```

Compile
```bash
cd minishell && make
```

Run minishell
```bash
./minishell
```

## Available features

- `’` (single quote)
- `"` (double quote)
- Redirections :
  - `<` should redirect input
  - `>` should redirect output
  - `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history
  - `>>` should redirect output in append mode
- `pipes` (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe
-  `And` (&& operator)
-  `Or` (|| operator)
-  `Parenthesis` (for priorities only)
-  `Wildcards` (* character) in current working directory
- `environment variables` ($ followed by a sequence of characters)
- `$?`
- Signals :
  - `ctrl-C`
  - `Ctrl-D`
  - `Ctrl-\`
- Builtins :
  - `echo` with option -n
  - `cd` with only a relative or absolute path
  - `pwd` with no options
  - `export` with no options
  - `unset` with no options
  - `env` with no options or arguments
  - `exit` with no options
