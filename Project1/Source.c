#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
# define N  256

//int check_number(unsigned long long int num);
void word_out(int digit_rank, int digit, int prev_digit);
void dec_out(int digit_rank, int digit);
unsigned long long int strCheck(char str[N]);

int main()
{
	unsigned long long int number = 0;          //0 to 18,446,744,073,709,551,615
	int counter;
	//int N = 20;
	int digits[20];
	char  in[N];
	//size_t res = 0;

	setlocale(LC_ALL, "Rus");
	system("color F0");

	printf("Введите натуральное число не больше 18,446,744,073,709,551,615: ");
	gets(in);
	number = strCheck(in);
	switch (number)
	{
	case 0:
		printf("Ошибка: 0 не натуральное число\n");
		system("pause");
		return 1;
		break;
	case 1:
		printf("Ошибка: введено не натуральное число число\n");
		system("pause");
		return 2;
		break;
	case 2:
		printf("Ошибка: введеное число слишком большое.\n");
		system("pause");
		return 3;
		break;
	}
	printf("Вы ввели число %llu \n", number);
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
			dec_out(j, digits[j - 1]);
			j -= 1;
		}
		else
		{
			if (j == 0) word_out(j, digits[j], 1);
			else word_out(j, digits[j], digits[j - 1]);
		}
	}
	
	printf("%c", '\n');
	system("pause");
	return 0;
}

unsigned long long int strCheck(char str[N])
{
	int i;
	unsigned long long int number;
	//char* endptr;
	if (strlen(str) > 20)
	{
		return 2;
	}
	for (i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]) == 0)
		{
			return 1;
		}
	}
	errno = 0;
	number = strtoull(str, NULL, 10);
	if (errno == ERANGE)
	{
		return 2;
	}
	else {
		return number;
	}
	//return 0;
}

void word_out(int digit_rank, int digit, int prev_digit)
{
	switch (digit_rank)
	{
	case 0: //единицы
		switch (digit)
		{
		case 1:
			printf("%s", "один");
			break;
		case 2:
			printf("%s", "два");
			break;
		case 3:
			printf("%s", "три");
			break;
		case 4:
			printf("%s", "четыре");
			break;
		case 5:
			printf("%s", "пять");
			break;
		case 6:
			printf("%s", "шесть");
			break;
		case 7:
			printf("%s", "семь");
			break;
		case 8:
			printf("%s", "восемь");
			break;
		case 9:
			printf("%s", "девять");
			break;
		}
		break;
	case 1: //десятки
		switch (digit)
		{
		case 2:
			printf("%s", "двадцать ");
			break;
		case 3:
			printf("%s", "тридцать ");
			break;
		case 4:
			printf("%s", "сорок ");
			break;
		case 5:
			printf("%s", "пятьдесят ");
			break;
		case 6:
			printf("%s", "шестьдесят ");
			break;
		case 7:
			printf("%s", "семьдесят ");
			break;
		case 8:
			printf("%s", "восемьдесят ");
			break;
		case 9:
			printf("%s", "девяносто ");
			break;
		}
		break;
	case 2: //сотни
		switch (digit)
		{
		case 1:
			printf("%s", "сто ");
			break;
		case 2:
			printf("%s", "двести ");
			break;
		case 3:
			printf("%s", "триста ");
			break;
		case 4:
			printf("%s", "четыреста ");
			break;
		case 5:
			printf("%s", "пятьсот ");
			break;
		case 6:
			printf("%s", "шестьсот ");
			break;
		case 7:
			printf("%s", "семьсот ");
			break;
		case 8:
			printf("%s", "восемьсот ");
			break;
		case 9:
			printf("%s", "девятьсот ");
			break;
		}
		break;
	//////////////////////////////////////////////
	case 3:	//тысячи
		switch (digit)
		{
		case 1:
			printf("%s", "одна тысяча ");
			break;
		case 2:
			printf("%s", "две тысячи ");
			break;
		case 3:
			printf("%s", "три тысячи ");
			break;
		case 4:
			printf("%s", "четыре тысячи ");
			break;
		case 5:
			printf("%s", "пять тысяч ");
			break;
		case 6:
			printf("%s", "шесть тысяч ");
			break;
		case 7:
			printf("%s", "семь тысяч ");
			break;
		case 8:
			printf("%s", "восемь тысяч ");
			break;
		case 9:
			printf("%s", "девять тысяч ");
			break;
		}
		break;
	case 4:	//Десятки тысяч
		switch (digit)
		{
		case 2:
			printf("%s", "двадцать ");
			break;
		case 3:
			printf("%s", "тридцать ");
			break;
		case 4:
			printf("%s", "сорок ");
			break;
		case 5:
			printf("%s", "пятьдесят ");
			break;
		case 6:
			printf("%s", "шестьдесят ");
			break;
		case 7:
			printf("%s", "семьдесят ");
			break;
		case 8:
			printf("%s", "восемьдесят ");
			break;
		case 9:
			printf("%s", "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "тысяч ");
		}
		break;
	case 5:	//сотни тысяч
		switch (digit)
		{
		case 1:
			printf("%s", "сто ");
			break;
		case 2:
			printf("%s", "двести ");
			break;
		case 3:
			printf("%s", "триста ");
			break;
		case 4:
			printf("%s", "четыреста ");
			break;
		case 5:
			printf("%s", "пятьсот ");
			break;
		case 6:
			printf("%s", "шестьсот ");
			break;
		case 7:
			printf("%s", "семьсот ");
			break;
		case 8:
			printf("%s", "восемьсот ");
			break;
		case 9:
			printf("%s", "девятьсот ");
			break;
		}
		break;
	////////////////////////////////////////////////
	case 6:	//миллионы
		switch (digit)
		{
		case 1:
			printf("%s", "один миллион ");
			break;
		case 2:
			printf("%s", "два миллиона  ");
			break;
		case 3:
			printf("%s", "три миллиона ");
			break;
		case 4:
			printf("%s", "четыре миллиона ");
			break;
		case 5:
			printf("%s", "пять миллионов ");
			break;
		case 6:
			printf("%s", "шесть миллионов ");
			break;
		case 7:
			printf("%s", "семь миллионов ");
			break;
		case 8:
			printf("%s", "восемь миллионов ");
			break;
		case 9:
			printf("%s", "девять миллионов ");
			break;
		}
		break;
	case 7:	//десятки миллионов
		switch (digit)
		{
		case 2:
			printf("%s", "двадцать ");
			break;
		case 3:
			printf("%s", "тридцать ");
			break;
		case 4:
			printf("%s", "сорок ");
			break;
		case 5:
			printf("%s", "пятьдесят ");
			break;
		case 6:
			printf("%s", "шестьдесят ");
			break;
		case 7:
			printf("%s", "семьдесят ");
			break;
		case 8:
			printf("%s", "восемьдесят ");
			break;
		case 9:
			printf("%s", "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "миллионов ");
		}
		break;
	case 8:	//сотни миллионов
		switch (digit)
		{
		case 1:
			printf("%s", "сто ");
			break;
		case 2:
			printf("%s", "двести ");
			break;
		case 3:
			printf("%s", "триста ");
			break;
		case 4:
			printf("%s", "четыреста ");
			break;
		case 5:
			printf("%s", "пятьсот ");
			break;
		case 6:
			printf("%s", "шестьсот ");
			break;
		case 7:
			printf("%s", "семьсот ");
			break;
		case 8:
			printf("%s", "восемьсот ");
			break;
		case 9:
			printf("%s", "девятьсот ");
			break;
		}
		break;
	//////////////////////////////////////////////////////
	case 9:	//миллиарды
		switch (digit)
		{
		case 1:
			printf("%s", "один миллиард ");
			break;
		case 2:
			printf("%s", "два миллиарда ");
			break;
		case 3:
			printf("%s", "три миллиарда ");
			break;
		case 4:
			printf("%s", "четыре миллиарда ");
			break;
		case 5:
			printf("%s", "пять миллиардов ");
			break;
		case 6:
			printf("%s", "шесть миллиардов ");
			break;
		case 7:
			printf("%s", "семь миллиардов ");
			break;
		case 8:
			printf("%s", "восемь миллиардов ");
			break;
		case 9:
			printf("%s", "девять миллиардов ");
			break;
		}
		break;
	case 10:	//десятки миллиардов
		switch (digit)
		{
		case 2:
			printf("%s", "двадцать ");
			break;
		case 3:
			printf("%s", "тридцать ");
			break;
		case 4:
			printf("%s", "сорок ");
			break;
		case 5:
			printf("%s", "пятьдесят ");
			break;
		case 6:
			printf("%s", "шестьдесят ");
			break;
		case 7:
			printf("%s", "семьдесят ");
			break;
		case 8:
			printf("%s", "восемьдесят ");
			break;
		case 9:
			printf("%s", "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "миллиардов ");
		}
		break;
	case 11:	//сотни миллиардов
		switch (digit)
		{
		case 1:
			printf("%s", "сто ");
			break;
		case 2:
			printf("%s", "двести ");
			break;
		case 3:
			printf("%s", "триста ");
			break;
		case 4:
			printf("%s", "четыреста ");
			break;
		case 5:
			printf("%s", "пятьсот ");
			break;
		case 6:
			printf("%s", "шестьсот ");
			break;
		case 7:
			printf("%s", "семьсот ");
			break;
		case 8:
			printf("%s", "восемьсот ");
			break;
		case 9:
			printf("%s", "девятьсот ");
			break;
		}
		break;
	///////////////////////////////////////////////////
	case 12:	//триллион
		switch (digit)
		{
		case 1:
			printf("%s", "один триллион ");
			break;
		case 2:
			printf("%s", "два триллиона ");
			break;
		case 3:
			printf("%s", "три триллиона ");
			break;
		case 4:
			printf("%s", "четыре триллиона ");
			break;
		case 5:
			printf("%s", "пять триллионов ");
			break;
		case 6:
			printf("%s", "шесть триллионов ");
			break;
		case 7:
			printf("%s", "семь триллионов ");
			break;
		case 8:
			printf("%s", "восемь триллионов ");
			break;
		case 9:
			printf("%s", "девять триллионов ");
			break;
		}
		break;
	case 13:	//десятки триллион
		switch (digit)
		{
		case 2:
			printf("%s", "двадцать ");
			break;
		case 3:
			printf("%s", "тридцать ");
			break;
		case 4:
			printf("%s", "сорок ");
			break;
		case 5:
			printf("%s", "пятьдесят ");
			break;
		case 6:
			printf("%s", "шестьдесят ");
			break;
		case 7:
			printf("%s", "семьдесят ");
			break;
		case 8:
			printf("%s", "восемьдесят ");
			break;
		case 9:
			printf("%s", "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "триллионов ");
		}
		break;
	case 14:	//сотни триллион
		switch (digit)
		{
		case 1:
			printf("%s", "сто ");
			break;
		case 2:
			printf("%s", "двести ");
			break;
		case 3:
			printf("%s", "триста ");
			break;
		case 4:
			printf("%s", "четыреста ");
			break;
		case 5:
			printf("%s", "пятьсот ");
			break;
		case 6:
			printf("%s", "шестьсот ");
			break;
		case 7:
			printf("%s", "семьсот ");
			break;
		case 8:
			printf("%s", "восемьсот ");
			break;
		case 9:
			printf("%s", "девятьсот ");
			break;
		}
		break;
	///////////////////////////////////////////////
	case 15:	//квадриллион
		switch (digit)
		{
		case 1:
			printf("%s", "один квадриллион ");
			break;
		case 2:
			printf("%s", "два квадриллиона ");
			break;
		case 3:
			printf("%s", "три квадриллиона ");
			break;
		case 4:
			printf("%s", "четыре квадриллиона ");
			break;
		case 5:
			printf("%s", "пять квадриллионов ");
			break;
		case 6:
			printf("%s", "шесть квадриллионов ");
			break;
		case 7:
			printf("%s", "семь квадриллионов ");
			break;
		case 8:
			printf("%s", "восемь квадриллионов ");
			break;
		case 9:
			printf("%s", "девять квадриллионов ");
			break;
		}
		break;
	case 16:	//десятки квадриллионов
		switch (digit)
		{
		case 2:
			printf("%s", "двадцать ");
			break;
		case 3:
			printf("%s", "тридцать ");
			break;
		case 4:
			printf("%s", "сорок ");
			break;
		case 5:
			printf("%s", "пятьдесят ");
			break;
		case 6:
			printf("%s", "шестьдесят ");
			break;
		case 7:
			printf("%s", "семьдесят ");
			break;
		case 8:
			printf("%s", "восемьдесят ");
			break;
		case 9:
			printf("%s", "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "квадриллионов ");
		}
		break;
	case 17:	//сотни квадриллионов
		switch (digit)
		{
		case 1:
			printf("%s", "сто ");
			break;
		case 2:
			printf("%s", "двести ");
			break;
		case 3:
			printf("%s", "триста ");
			break;
		case 4:
			printf("%s", "четыреста ");
			break;
		case 5:
			printf("%s", "пятьсот ");
			break;
		case 6:
			printf("%s", "шестьсот ");
			break;
		case 7:
			printf("%s", "семьсот ");
			break;
		case 8:
			printf("%s", "восемьсот ");
			break;
		case 9:
			printf("%s", "девятьсот ");
			break;
		}
		break;
	/////////////////////////////////////////////////////////
	case 18:	//квинтиллион
		switch (digit)
		{
		case 1:
			printf("%s", "один квинтиллион ");
			break;
		case 2:
			printf("%s", "два квинтиллиона ");
			break;
		case 3:
			printf("%s", "три квинтиллиона ");
			break;
		case 4:
			printf("%s", "четыре квинтиллиона ");
			break;
		case 5:
			printf("%s", "пять квинтиллионов ");
			break;
		case 6:
			printf("%s", "шесть квинтиллионов ");
			break;
		case 7:
			printf("%s", "семь квинтиллионов ");
			break;
		case 8:
			printf("%s", "восемь квинтиллионов ");
			break;
		case 9:
			printf("%s", "девять квинтиллионов ");
			break;
		}
		break;
	case 19:	//десятки квадриллионов
		switch (digit)
		{
		case 2:
			printf("%s", "двадцать ");
			break;
		case 3:
			printf("%s", "тридцать ");
			break;
		case 4:
			printf("%s", "сорок ");
			break;
		case 5:
			printf("%s", "пятьдесят ");
			break;
		case 6:
			printf("%s", "шестьдесят ");
			break;
		case 7:
			printf("%s", "семьдесят ");
			break;
		case 8:
			printf("%s", "восемьдесят ");
			break;
		case 9:
			printf("%s", "девяносто ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "квинтиллионов ");
		}
		break;
	}
}

void dec_out(int digit_rank, int digit)
{
	switch (digit)
	{
	case 0:
		printf("%s", "десять");
		break;
	case 1:
		printf("%s", "одиннадцать");
		break;
	case 2:
		printf("%s", "двенадцать");
		break;
	case 3:
		printf("%s", "тринадцать");
		break;
	case 4:
		printf("%s", "четырнадцать");
		break;
	case 5:
		printf("%s", "пятнадцать");
		break;
	case 6:
		printf("%s", "шестнадцать");
		break;
	case 7:
		printf("%s", "семнадцать");
		break;
	case 8:
		printf("%s", "восемнадцать");
		break;
	case 9:
		printf("%s", "девятнадцать");
		break;
	}
	if (digit_rank == 4)
	{
		printf("%s", " тысяч ");
	}
	if (digit_rank == 7)
	{
		printf("%s", " миллионов ");
	}
	if (digit_rank == 10)
	{
		printf("%s", " миллиардов ");
	}
	if (digit_rank == 13)
	{
		printf("%s", " триллионов ");
	}
	if (digit_rank == 16)
	{
		printf("%s", " квадриллионов ");
	}
	if (digit_rank == 19)
	{
		printf("%s", " квинтиллионов ");
	}
}
