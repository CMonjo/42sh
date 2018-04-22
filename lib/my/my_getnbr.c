/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Get a number from a char
*/

int my_getnbr(char const *str)
{
	int res = 0;
	int i = -1;
	char op = '+';

	while (str[++i]) {
		if (str[i] >= 48 && str[i] <= 57) {
			res = res * 10 + (str[i] - 48);
		} else if (res > 0)
			break;
		if (str[i] == '+' || str[i] == '-')
			op = op != str[i] ? '-' : '+';
		if (res < 0 && (op != '-' || res != -2147483648))
			return (0);
	}
	return (op == '-' ? res * -1 : res);
}