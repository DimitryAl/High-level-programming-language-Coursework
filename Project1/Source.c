#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

void word_out(int digit_rank, int digit, int prev_digit, char num[500]);
void dec_out(int digit_rank, int digit, char num[500]);
unsigned long long int strCheck(char str[256]);

int main()
{
	unsigned long long int number;          //0 to 18,446,744,073,709,551,615
	int counter;
	int digits[20];
	char in[21];
	char numeral[500];

	setlocale(LC_ALL, "Rus");
	system("color F0");

	printf("Введите натуральное число не больше 18,446,744,073,709,551,615:\n");
	gets(in);
	number = strCheck(in);
	switch (number)
	{
	case 0:
		printf("Ошибка: 0 не натуральное число.\n");
		system("pause");
		return 1;
		break;
	case -4:
		printf("Ошибка: введено не натуральное число число.\n");
		system("pause");
		return 2;
		break;
	case -2:
		printf("Ошибка: введеное число слишком большое.\n");
		system("pause");
		return 3;
		break;
	case -3:
		printf("Ошибка: данные не введены.\n");
		system("pause");
		return 4;
		break;
	}
	printf("Введенное число: %llu \n", number);
	numeral[0] = '\0';
	printf("Число числительным:\n");
	counter = 0;
	while (number)
	{
		digits[counter] = number % 10;
		counter++;
		number /= 10;
	}
	for (int j = counter - 1; j >= 0; j--)
	{
		if ((j - 1) % 3 == 0 && digits[j] == 1)
		{
			dec_out(j, digits[j - 1], numeral);
			j -= 1;
		}
		else
		{
			if (j == 0) word_out(j, digits[j], 1, numeral);
			else word_out(j, digits[j], digits[j - 1], numeral);
		}
	}
	printf(numeral);
	printf("%c", '\n');
	system("pause");
	return 0;
}

unsigned long long int strCheck(char str[256])
{
	int i;
	unsigned long long int number;
	if (strlen(str) > 20)
	{
		return -2;
	}
	if (strlen(str) == 0)
	{
		return -3;
	}
	i = 0;
	for (i; i < strlen(str); i++)
	{
		if (isdigit(str[i]) == 0)
		{
			return -4;
		}
	}
	errno = 0;
	number = strtoull(str, NULL, 10);
	if (errno == ERANGE)
	{
		return -2;
	}
	else {
		return number;
	}
}

void dec_out(int digit_rank, int digit, char num[500])
{
	switch (digit)
	{
	case 0:
		strcat(num, "десять");
		break;
	case 1:
		strcat(num, "одиннадцать");
		break;
	case 2:
		strcat(num, "двенадцать");
		break;
	case 3:
		strcat(num, "тринадцать");
		break;
	case 4:
		strcat(num, "четырнадцать");
		break;
	case 5:
		strcat(num, "пятнадцать");
		break;
	case 6:
		strcat(num, "шестнадцать");
		break;
	case 7:
		strcat(num, "семнадцать");
		break;
	case 8:
		strcat(num, "восемнадцать");
		break;
	case 9:
		strcat(num, "девятнадцать");
		break;
	}
	switch (digit_rank)
	{
	case 4:
		strcat(num, " тысяч ");
		break;
	case 7:
		strcat(num, " миллионов ");
		break;
	case 10:
		strcat(num, " миллиардов ");
		break;
	case 13:
		strcat(num, " триллионов ");
		break;
	case 16:
		strcat(num, " квадриллионов ");
		break;
	case 19:
		strcat(num, " квинтиллионов ");
		break;
	}
}

void word_out(int digit_rank, int digit, int prev_digit, char num[500])
{
	if (digit_rank == 2 || digit_rank == 5 || digit_rank == 8 || digit_rank == 11 || digit_rank == 14 || digit_rank == 17)
	{
		switch (digit)
		{
		case 1:
			strcat(num, "сто ");
			break;
		case 2:
			strcat(num, "двести ");
			break;
		case 3:
			strcat(num, "триста ");
			break;
		case 4:
			strcat(num, "четыреста ");
			break;
		case 5:
			strcat(num, "пятьсот ");
			break;
		case 6:
			strcat(num, "шестьсот ");
			break;
		case 7:
			strcat(num, "семьсот ");
			break;
		case 8:
			strcat(num, "восемьсот ");
			break;
		case 9:
			strcat(num, "девятьсот ");
			break;
		}
	}
	switch (digit_rank)
	{
	case 0: //единицы
		switch (digit)
		{
		case 1:
			strcat(num, "один");
			break;
		case 2:
			strcat(num, "два");
			break;
		case 3:
			strcat(num, "три");
			break;
		case 4:
			strcat(num, "четыре");
			break;
		case 5:
			strcat(num, "пять");
			break;
		case 6:
			strcat(num, "шесть");
			break;
		case 7:
			strcat(num, "семь");
			break;
		case 8:
			strcat(num, "восемь");
			break;
		case 9:
			strcat(num, "девять");
			break;
		}
		break;
	case 1: //десятки
		switch (digit)
		{
		case 2:
			strcat(num, "двадцать ");
			break;
		case 3:
			strcat(num, "тридцать ");
			break;
		case 4:
			strcat(num, "сорок ");
			break;
		case 5:
			strcat(num, "пятьдесят ");
			break;
		case 6:
			strcat(num, "шестьдесят ");
			break;
		case 7:
			strcat(num, "семьдесят ");
			break;
		case 8:
			strcat(num, "восемьдесят ");
			break;
		case 9:
			strcat(num, "девяносто ");
			break;
		}
		break;
	case 3:	//тысячи
		switch (digit)
		{
		case 1:
			strcat(num, "одна тысяча ");
			break;
		case 2:
			strcat(num, "две тысячи ");
			break;
		case 3:
			strcat(num, "три тысячи ");
			break;
		case 4:
			strcat(num, "четыре тысячи ");
			break;
		case 5:
			strcat(num, "пять тысяч ");
			break;
		case 6:
			strcat(num, "шесть тысяч ");
			break;
		case 7:
			strcat(num, "семь тысяч ");
			break;
		case 8:
			strcat(num, "восемь тысяч ");
			break;
		case 9:
			strcat(num, "девять тысяч ");
			break;
		}
		break;
	case 4:	//Десятки тысяч
		switch (digit)
		{
		case 2:
			strcat(num, "двадцать ");
			break;
		case 3:
			strcat(num, "тридцать ");
			break;
		case 4:
			strcat(num, "сорок ");
			break;
		case 5:
			strcat(num, "пятьдесят ");
			break;
		case 6:
			strcat(num, "шестьдесят ");
			break;
		case 7:
			strcat(num, "семьдесят ");
			break;
		case 8:
			strcat(num, "восемьдесят ");
			break;
		case 9:
			strcat(num, "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			strcat(num, "тысяч ");
		}
		break;
	case 6:	//миллионы
		switch (digit)
		{
		case 1:
			strcat(num, "один миллион ");
			break;
		case 2:
			strcat(num, "два миллиона  ");
			break;
		case 3:
			strcat(num, "три миллиона ");
			break;
		case 4:
			strcat(num, "четыре миллиона ");
			break;
		case 5:
			strcat(num, "пять миллионов ");
			break;
		case 6:
			strcat(num, "шесть миллионов ");
			break;
		case 7:
			strcat(num, "семь миллионов ");
			break;
		case 8:
			strcat(num, "восемь миллионов ");
			break;
		case 9:
			strcat(num, "девять миллионов ");
			break;
		}
		break;
	case 7:	//десятки миллионов
		switch (digit)
		{
		case 2:
			strcat(num, "двадцать ");
			break;
		case 3:
			strcat(num, "тридцать ");
			break;
		case 4:
			strcat(num, "сорок ");
			break;
		case 5:
			strcat(num, "пятьдесят ");
			break;
		case 6:
			strcat(num, "шестьдесят ");
			break;
		case 7:
			strcat(num, "семьдесят ");
			break;
		case 8:
			strcat(num, "восемьдесят ");
			break;
		case 9:
			strcat(num, "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			strcat(num, "миллионов ");
		}
		break;
	case 9:	//миллиарды
		switch (digit)
		{
		case 1:
			strcat(num, "один миллиард ");
			break;
		case 2:
			strcat(num, "два миллиарда ");
			break;
		case 3:
			strcat(num, "три миллиарда ");
			break;
		case 4:
			strcat(num, "четыре миллиарда ");
			break;
		case 5:
			strcat(num, "пять миллиардов ");
			break;
		case 6:
			strcat(num, "шесть миллиардов ");
			break;
		case 7:
			strcat(num, "семь миллиардов ");
			break;
		case 8:
			strcat(num, "восемь миллиардов ");
			break;
		case 9:
			strcat(num, "девять миллиардов ");
			break;
		}
		break;
	case 10:	//десятки миллиардов
		switch (digit)
		{
		case 2:
			strcat(num, "двадцать ");
			break;
		case 3:
			strcat(num, "тридцать ");
			break;
		case 4:
			strcat(num, "сорок ");
			break;
		case 5:
			strcat(num, "пятьдесят ");
			break;
		case 6:
			strcat(num, "шестьдесят ");
			break;
		case 7:
			strcat(num, "семьдесят ");
			break;
		case 8:
			strcat(num, "восемьдесят ");
			break;
		case 9:
			strcat(num, "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			strcat(num, "миллиардов ");
		}
		break;
	case 12:	//триллион
		switch (digit)
		{
		case 1:
			strcat(num, "один триллион ");
			break;
		case 2:
			strcat(num, "два триллиона ");
			break;
		case 3:
			strcat(num, "три триллиона ");
			break;
		case 4:
			strcat(num, "четыре триллиона ");
			break;
		case 5:
			strcat(num, "пять триллионов ");
			break;
		case 6:
			strcat(num, "шесть триллионов ");
			break;
		case 7:
			strcat(num, "семь триллионов ");
			break;
		case 8:
			strcat(num, "восемь триллионов ");
			break;
		case 9:
			strcat(num, "девять триллионов ");
			break;
		}
		break;
	case 13:	//десятки триллион
		switch (digit)
		{
		case 2:
			strcat(num, "двадцать ");
			break;
		case 3:
			strcat(num, "тридцать ");
			break;
		case 4:
			strcat(num, "сорок ");
			break;
		case 5:
			strcat(num, "пятьдесят ");
			break;
		case 6:
			strcat(num, "шестьдесят ");
			break;
		case 7:
			strcat(num, "семьдесят ");
			break;
		case 8:
			strcat(num, "восемьдесят ");
			break;
		case 9:
			strcat(num, "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			strcat(num, "триллионов ");
		}
		break;
	case 15:	//квадриллион
		switch (digit)
		{
		case 1:
			strcat(num, "один квадриллион ");
			break;
		case 2:
			strcat(num, "два квадриллиона ");
			break;
		case 3:
			strcat(num, "три квадриллиона ");
			break;
		case 4:
			strcat(num, "четыре квадриллиона ");
			break;
		case 5:
			strcat(num, "пять квадриллионов ");
			break;
		case 6:
			strcat(num, "шесть квадриллионов ");
			break;
		case 7:
			strcat(num, "семь квадриллионов ");
			break;
		case 8:
			strcat(num, "восемь квадриллионов ");
			break;
		case 9:
			strcat(num, "девять квадриллионов ");
			break;
		}
		break;
	case 16:	//десятки квадриллионов
		switch (digit)
		{
		case 2:
			strcat(num, "двадцать ");
			break;
		case 3:
			strcat(num, "тридцать ");
			break;
		case 4:
			strcat(num, "сорок ");
			break;
		case 5:
			strcat(num, "пятьдесят ");
			break;
		case 6:
			strcat(num, "шестьдесят ");
			break;
		case 7:
			strcat(num, "семьдесят ");
			break;
		case 8:
			strcat(num, "восемьдесят ");
			break;
		case 9:
			strcat(num, "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			strcat(num, "квадриллионов ");
		}
		break;
	case 18:	//квинтиллион
		switch (digit)
		{
		case 1:
			strcat(num, "один квинтиллион ");
			break;
		case 2:
			strcat(num, "два квинтиллиона ");
			break;
		case 3:
			strcat(num, "три квинтиллиона ");
			break;
		case 4:
			strcat(num, "четыре квинтиллиона ");
			break;
		case 5:
			strcat(num, "пять квинтиллионов ");
			break;
		case 6:
			strcat(num, "шесть квинтиллионов ");
			break;
		case 7:
			strcat(num, "семь квинтиллионов ");
			break;
		case 8:
			strcat(num, "восемь квинтиллионов ");
			break;
		case 9:
			strcat(num, "девять квинтиллионов ");
			break;
		}
		break;
	case 19:	//десятки квадриллионов
		switch (digit)
		{
		case 2:
			strcat(num, "двадцать ");
			break;
		case 3:
			strcat(num, "тридцать ");
			break;
		case 4:
			strcat(num, "сорок ");
			break;
		case 5:
			strcat(num, "пятьдесят ");
			break;
		case 6:
			strcat(num, "шестьдесят ");
			break;
		case 7:
			strcat(num, "семьдесят ");
			break;
		case 8:
			strcat(num, "восемьдесят ");
			break;
		case 9:
			strcat(num, "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			strcat(num, "квинтиллионов ");
		}
		break;
	}
}
