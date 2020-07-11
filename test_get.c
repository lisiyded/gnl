# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t          ft_strlen(const char *s)
{
        size_t  len;

        len = 0;
        while (s[len])
                len++;
        return (len);
}

char            *ft_strdup(const char *s1)
{
        char    *str;
        size_t  i;

        i = 0;
        str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
        if (str == NULL)
                return (NULL);
        while (s1[i])
        {
                str[i] = s1[i];
                i++;
        }
        str[i] = '\0';
        return (str);
}

char            *ft_strjoin(char const *s1, char const *s2)
{
        int             i;
        int             j;
        char    *str;

        i = 0;
        j = 0;
        if (s1 == NULL || s2 == NULL)
                return (NULL);
        str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (str == NULL)
                return (NULL);
        while (s1[i])
        {
                str[i] = s1[i];
                i++;
        }
        while (s2[j])
        {
                str[i] = s2[j];
                i++;
                j++;
        }
        str[i] = '\0';
        return (str);
}

char            *ft_strchr(const char *s, int c)
{
        while (*s)
        {
                if (*s == c)
                        return ((char *)s);
                s++;
        }
        if (c == '\0')
                return ((char *)s);
        return (NULL);
}


// в line записано strdup "" чтобы строка была без мусора
// в цикле происходит полное чтение файла txt с помощью записи функции read
// в переменную butes_was_read
// массив записывается по 10 символов в лайн при помощи склеивания строк (strjoin)
// после последнего прочитанного байта ставится \0
// ft_strchr - когда среди прочитанных байт внутри цикла встретиться 
// конец строки - завершить чтение
// вывод обрезанной строки т к остаток никуда не сохранился
int	get_next_line(int fd, char **line)
{
	char buf[10 + 1];
	int bytes_was_read;
	
	
	*line = ft_strdup("");
	while ((bytes_was_read = read(fd, &buf, 10)))
	{
	if (ft_strchr(buf, '\n'))
		{
		break; 
		}
	buf[bytes_was_read] = '\0';
	*line = ft_strjoin(*line, buf);
	}
	return (0);
} 


int     main(void)
{
char    *line;
int     fd;
int     res;

fd = open("text.txt", O_RDONLY);
while ((res = get_next_line(fd, &line)))
{
        printf("res = %d, line is: %s\n", res, line);
        free(line);
}

printf("res = %d, line is:%s\n ",res, line);

return(0);
}
