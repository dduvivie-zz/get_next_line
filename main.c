int main(void)
{
	int	fd;
	char *s;
	int	finish;

	fd = open("text1.txt", O_RDONLY);
	finish = 0;
	while (!finish)
	{
		s = get_next_line(fd);
		if (s == NULL)
			finish = 1;
		printf("%s\n", s);
		free(s);
	}
	close(fd);
	return (0);
}