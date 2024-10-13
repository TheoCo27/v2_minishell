#include "parsing.h"

void	print_token(t_token *token)
{
	if (!token)
	{
		printf("Null Token\n");
		return ;
	}
	printf("Token type : ");
	if (token->type == INFILE)
		printf("INFILE\n");
	else if (token->type == HEREDOC)
		printf("HEREDOC\n");
	else if (token->type == OUTFILE_TRUNCATE)
		printf("OUTFILE_TRUNCATE\n");
	else if (token->type == OUTFILE_APPEND)
		printf("OUTFILE_APPEND\n");
	else if (token->type == PIPE)
		printf("PIPE\n");
	else if (token->type == CMD)
		printf("CMD\n");
	else if (token->type == ARG)
		printf("ARG\n");
	if (token->content)
		printf("Token content : %s\n\n", token->content);
	else
		printf("Token content : NULL\n\n");
}

void	print_array(t_token **array)
{
	int	i;

	if (!array)
	{
		printf("\nNull Array\n");
		return ;
	}
	i = 0;
	while(array[i])
	{
		printf("\nToken %i:\n", i);
		print_token(array[i]);
		i++;
	}
}

void	print_main_array(t_token ***main_array)
{
	int	i;


	if (!main_array)
	{
		printf("\nNull Main Array\n");
		return ;
	}
	i = 0;
	printf("\nPRINTING MAIN ARRAY :\n");
	while(main_array[i])
	{
		printf("\nSUB ARRAY %i:\n", i);
		print_array(main_array[i]);
		i++;
	}
}
