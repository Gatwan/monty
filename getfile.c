#include "monty.h"
/**
*get_file - gets the monty ByteCode files
*@str: string to be checked
*Return: line count one success else EXIT_FAILURE
*/
int get_file(char *str)
{
	char *line_buf = NULL, buff[1024], *b = buff;
	size_t line_buf_size = 0;
	int line_counter = 0, i, j;
	ssize_t line_size = 0;
	FILE *fp = fopen(str, "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	line_size = getline(&line_buff, &line_buf_size, fp);
	for (i = 0; i < 1024; i++)
		buff[i] = 0;
	while (line_size >= 0)
	{
		for (i = 0, j = 0, line_buff[i] && line_buff[i] != '\n'; i++)
		{
			if (line_buff[i] != ' ')
			{
				j++;
				break;
			}
		}
		if (line_buf[i] == '#')
		{
			line_size = getline(&line_buf, &line_buf_size, fp);
			line_counter++;
			continue;
		}
		line_counter++;
		if (j > 0)
		{
			clean_string(b, line_buf);
			create_instruction(&list_opcode, b, line_counter, fp);
		}
		line_size = getline(&line_buf, &line_buf_size, fp);
	}
	free(line_buf), line_buf = NULL, fclose(fp);
	return (line_counter);
}
