#include "shell.h"
/**
 * get_len - gets lengths of numbers
 * @n: int type of number
 * Return: returns length of numbers
 */
int get_len(int n)
{
	unisgned int absolute_num;
	int length = 1;

	if (n < 0)
	{
		length++;
		absolute_num = n * -1;
	}
	else
	{
		absolute_num = n;
	}
	while (absolute_num > 9)
	{
		length++;
		absolute_num = absolute_num / 10;
	}
	return (length);

}
/**
 * aux_itoa - function that converts int into a string
 * @n: int type of numbers
 * Return: returns a string
 */
char *aux_itoa(int n)
{
	unsigned int absolute_num;
	int length = get_len(n);
	char *str_buffer;

	str_buffer = malloc(sizeof(char) * (length + 1));
	if (str_buffer == 0)
		return (NULL);
	*(str_buffer + length) = '\0';

	if (n < 0)
	{
		absolute_num = n * -1;
		str_buffer[0] = '-';
	}
	else
	{
		absolute_num = n;
	}
	length--;
	do {
		*(str_buffer + length) = (absolute_num % 10) + '0';
		absolute_num = absolute_num / 10;
		length__;
	}
	while (absolute_num > 0);
	return (str_buffer);
}
/**
 * _atoi - converts string in to integer
 * @s: accepts string input
 * Return: returns int
 *
 */
int _atoi(char *s)
{
unsigned int str_len = 0, num_size = 0, result = 0, sign = 1,
		     multiplier = 1, i;

	while (*(s + str_len) != '\0')
	{
		if (num_size > 0 && (*(s + str_len) < '0' || *(s + str_len) > '9'))
			break;

		if (*(s + str_len) == '-')
			sign *= -1;

		if ((*(s + str_len) >= '0') && (*(s + str_len) <= '9'))
		{
			if (num_size > 0)
				multiplier *= 10;
			num_size++;
		}
		str_len++;
	}
	for (i = str_len - num_size; i < str_len; i++)
	{
		result = result + ((*(s + i) - 48) * multiplier);
		multiplier /= 10;
	}
	return (result * sign);
}
