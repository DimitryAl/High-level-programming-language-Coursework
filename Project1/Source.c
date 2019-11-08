#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//int check_number(unsigned long long int num);
void word_out(int digit_rank, int digit, int prev_digit);
void dec_out(int digit_rank, int digit);

int main()
{
	//unsigned long long int number;          //0 to 18,446,744,073,709,551,615
	char number[21];
	int counter;
	int N = 20;
	int digits[20][1];
	//char test;
	size_t res = 0;
	setlocale(LC_ALL, "Rus");
	system("color F0");

	printf("%s", "Введите натуральное число ");
	scanf("%s", number);
	//scanf("%c", &number);
	//number = 18446744073709551615;
	//number = 120929;
	/*
	if (check_number(number) != 1)
	{
		return 1;
	}
	*/
	res = strchr(number, '\0');
	if (strchr(number, '\0') == NULL)
	{
		printf("%s", "error");
	}
	for (int j = 0; j < N; j++)
	{
		digits[j][0] = 0;
	}
	
	counter = 0;
	/*
	while (number)
	{
		digits[counter][0] = number % 10;
		counter++;
		number /= 10;
	}
	
	for (int j = counter; j >= 0; j--)
	{
		if ((j - 1) % 3 == 0 && digits[j][0] == 1)
		{
			dec_out(j, digits[j - 1][0]);
			j -= 1;
		}
		else
		{
			word_out(j, digits[j][0], digits[j - 1][0]);
		}
	}*/
	printf("%c", '\n');
	system("pause");
	return 0;
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
	case 3:
		switch (digit)
		{
		case 1:
			printf("%s", "одна тысяча ");
			break;
		case 2:
			printf("%s", "две тысячи  ");
			break;
		case 3:
			printf("%s", "три тысячи  ");
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
			printf("%s", "три миллиона  ");
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
/*
int check_number(unsigned long long int num)
{
	if (num == 0)
	{
		printf("%s\n", "Число не должно равняться нулю.");
		return 0;
	}
	if (num < 0)
	{
		printf("%s\n", "Число не должно быть отрицательным.");
		return -1;
	}
	return 1;
}
*/