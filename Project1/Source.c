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

	printf("%s", "������� ����������� ����� ");
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
	case 0: //�������
		switch (digit)
		{
		case 1:
			printf("%s", "����");
			break;
		case 2:
			printf("%s", "���");
			break;
		case 3:
			printf("%s", "���");
			break;
		case 4:
			printf("%s", "������");
			break;
		case 5:
			printf("%s", "����");
			break;
		case 6:
			printf("%s", "�����");
			break;
		case 7:
			printf("%s", "����");
			break;
		case 8:
			printf("%s", "������");
			break;
		case 9:
			printf("%s", "������");
			break;
		}
		break;
	case 1: //�������
		switch (digit)
		{
		case 2:
			printf("%s", "�������� ");
			break;
		case 3:
			printf("%s", "�������� ");
			break;
		case 4:
			printf("%s", "����� ");
			break;
		case 5:
			printf("%s", "��������� ");
			break;
		case 6:
			printf("%s", "���������� ");
			break;
		case 7:
			printf("%s", "��������� ");
			break;
		case 8:
			printf("%s", "����������� ");
			break;
		case 9:
			printf("%s", "��������� ");
			break;
		}
		break;
	case 2: //�����
		switch (digit)
		{
		case 1:
			printf("%s", "��� ");
			break;
		case 2:
			printf("%s", "������ ");
			break;
		case 3:
			printf("%s", "������ ");
			break;
		case 4:
			printf("%s", "��������� ");
			break;
		case 5:
			printf("%s", "������� ");
			break;
		case 6:
			printf("%s", "�������� ");
			break;
		case 7:
			printf("%s", "������� ");
			break;
		case 8:
			printf("%s", "��������� ");
			break;
		case 9:
			printf("%s", "��������� ");
			break;
		}
		break;
	case 3:
		switch (digit)
		{
		case 1:
			printf("%s", "���� ������ ");
			break;
		case 2:
			printf("%s", "��� ������  ");
			break;
		case 3:
			printf("%s", "��� ������  ");
			break;
		case 4:
			printf("%s", "������ ������ ");
			break;
		case 5:
			printf("%s", "���� ����� ");
			break;
		case 6:
			printf("%s", "����� ����� ");
			break;
		case 7:
			printf("%s", "���� ����� ");
			break;
		case 8:
			printf("%s", "������ ����� ");
			break;
		case 9:
			printf("%s", "������ ����� ");
			break;
		}
		break;
	case 4:	//������� �����
		switch (digit)
		{
		case 2:
			printf("%s", "�������� ");
			break;
		case 3:
			printf("%s", "�������� ");
			break;
		case 4:
			printf("%s", "����� ");
			break;
		case 5:
			printf("%s", "��������� ");
			break;
		case 6:
			printf("%s", "���������� ");
			break;
		case 7:
			printf("%s", "��������� ");
			break;
		case 8:
			printf("%s", "����������� ");
			break;
		case 9:
			printf("%s", "��������� ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "����� ");
		}
		break;
	case 5:	//����� �����
		switch (digit)
		{
		case 1:
			printf("%s", "��� ");
			break;
		case 2:
			printf("%s", "������ ");
			break;
		case 3:
			printf("%s", "������ ");
			break;
		case 4:
			printf("%s", "��������� ");
			break;
		case 5:
			printf("%s", "������� ");
			break;
		case 6:
			printf("%s", "�������� ");
			break;
		case 7:
			printf("%s", "������� ");
			break;
		case 8:
			printf("%s", "��������� ");
			break;
		case 9:
			printf("%s", "��������� ");
			break;
		}
		break;
	case 6:	//��������
		switch (digit)
		{
		case 1:
			printf("%s", "���� ������� ");
			break;
		case 2:
			printf("%s", "��� ��������  ");
			break;
		case 3:
			printf("%s", "��� ��������  ");
			break;
		case 4:
			printf("%s", "������ �������� ");
			break;
		case 5:
			printf("%s", "���� ��������� ");
			break;
		case 6:
			printf("%s", "����� ��������� ");
			break;
		case 7:
			printf("%s", "���� ��������� ");
			break;
		case 8:
			printf("%s", "������ ��������� ");
			break;
		case 9:
			printf("%s", "������ ��������� ");
			break;
		}
		break;
	case 7:	//������� ���������
		switch (digit)
		{
		case 2:
			printf("%s", "�������� ");
			break;
		case 3:
			printf("%s", "�������� ");
			break;
		case 4:
			printf("%s", "����� ");
			break;
		case 5:
			printf("%s", "��������� ");
			break;
		case 6:
			printf("%s", "���������� ");
			break;
		case 7:
			printf("%s", "��������� ");
			break;
		case 8:
			printf("%s", "����������� ");
			break;
		case 9:
			printf("%s", "��������� ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "��������� ");
		}
		break;
	case 8:	//����� ���������
		switch (digit)
		{
		case 1:
			printf("%s", "��� ");
			break;
		case 2:
			printf("%s", "������ ");
			break;
		case 3:
			printf("%s", "������ ");
			break;
		case 4:
			printf("%s", "��������� ");
			break;
		case 5:
			printf("%s", "������� ");
			break;
		case 6:
			printf("%s", "�������� ");
			break;
		case 7:
			printf("%s", "������� ");
			break;
		case 8:
			printf("%s", "��������� ");
			break;
		case 9:
			printf("%s", "��������� ");
			break;
		}
		break;
	case 9:	//���������
		switch (digit)
		{
		case 1:
			printf("%s", "���� �������� ");
			break;
		case 2:
			printf("%s", "��� ��������� ");
			break;
		case 3:
			printf("%s", "��� ��������� ");
			break;
		case 4:
			printf("%s", "������ ��������� ");
			break;
		case 5:
			printf("%s", "���� ���������� ");
			break;
		case 6:
			printf("%s", "����� ���������� ");
			break;
		case 7:
			printf("%s", "���� ���������� ");
			break;
		case 8:
			printf("%s", "������ ���������� ");
			break;
		case 9:
			printf("%s", "������ ���������� ");
			break;
		}
		break;
	case 10:	//������� ����������
		switch (digit)
		{
		case 2:
			printf("%s", "�������� ");
			break;
		case 3:
			printf("%s", "�������� ");
			break;
		case 4:
			printf("%s", "����� ");
			break;
		case 5:
			printf("%s", "��������� ");
			break;
		case 6:
			printf("%s", "���������� ");
			break;
		case 7:
			printf("%s", "��������� ");
			break;
		case 8:
			printf("%s", "����������� ");
			break;
		case 9:
			printf("%s", "��������� ");
			break;
		}
		if (prev_digit == 0)
		{
			printf("%s", "���������� ");
		}
		break;
	case 11:	//����� ����������
		switch (digit)
		{
		case 1:
			printf("%s", "��� ");
			break;
		case 2:
			printf("%s", "������ ");
			break;
		case 3:
			printf("%s", "������ ");
			break;
		case 4:
			printf("%s", "��������� ");
			break;
		case 5:
			printf("%s", "������� ");
			break;
		case 6:
			printf("%s", "�������� ");
			break;
		case 7:
			printf("%s", "������� ");
			break;
		case 8:
			printf("%s", "��������� ");
			break;
		case 9:
			printf("%s", "��������� ");
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
		printf("%s", "������");
		break;
	case 1:
		printf("%s", "�����������");
		break;
	case 2:
		printf("%s", "����������");
		break;
	case 3:
		printf("%s", "����������");
		break;
	case 4:
		printf("%s", "������������");
		break;
	case 5:
		printf("%s", "����������");
		break;
	case 6:
		printf("%s", "�����������");
		break;
	case 7:
		printf("%s", "����������");
		break;
	case 8:
		printf("%s", "������������");
		break;
	case 9:
		printf("%s", "������������");
		break;
	}
	if (digit_rank == 4)
	{
		printf("%s", " ����� ");
	}
	if (digit_rank == 7)
	{
		printf("%s", " ��������� ");
	}
	if (digit_rank == 10)
	{
		printf("%s", " ���������� ");
	}
	if (digit_rank == 13)
	{
		printf("%s", " ���������� ");
	}
	if (digit_rank == 16)
	{
		printf("%s", " ������������� ");
	}
	if (digit_rank == 19)
	{
		printf("%s", " ������������� ");
	}
}
/*
int check_number(unsigned long long int num)
{
	if (num == 0)
	{
		printf("%s\n", "����� �� ������ ��������� ����.");
		return 0;
	}
	if (num < 0)
	{
		printf("%s\n", "����� �� ������ ���� �������������.");
		return -1;
	}
	return 1;
}
*/