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

	printf("������� ����������� ����� �� ������ 18,446,744,073,709,551,615: ");
	gets(in);
	number = strCheck(in);
	switch (number)
	{
	case 0:
		printf("������: 0 �� ����������� �����\n");
		system("pause");
		return 1;
		break;
	case 1:
		printf("������: ������� �� ����������� ����� �����\n");
		system("pause");
		return 2;
		break;
	case 2:
		printf("������: �������� ����� ������� �������.\n");
		system("pause");
		return 3;
		break;
	}
	printf("�� ����� ����� %llu \n", number);
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
	//////////////////////////////////////////////
	case 3:	//������
		switch (digit)
		{
		case 1:
			printf("%s", "���� ������ ");
			break;
		case 2:
			printf("%s", "��� ������ ");
			break;
		case 3:
			printf("%s", "��� ������ ");
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
	////////////////////////////////////////////////
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
			printf("%s", "��� �������� ");
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
	//////////////////////////////////////////////////////
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
	///////////////////////////////////////////////////
	case 12:	//��������
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
	case 13:	//������� ��������
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
	case 14:	//����� ��������
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
	///////////////////////////////////////////////
	case 15:	//�����������
		switch (digit)
		{
		case 1:
			printf("%s", "���� ����������� ");
			break;
		case 2:
			printf("%s", "��� ������������ ");
			break;
		case 3:
			printf("%s", "��� ������������ ");
			break;
		case 4:
			printf("%s", "������ ������������ ");
			break;
		case 5:
			printf("%s", "���� ������������� ");
			break;
		case 6:
			printf("%s", "����� ������������� ");
			break;
		case 7:
			printf("%s", "���� ������������� ");
			break;
		case 8:
			printf("%s", "������ ������������� ");
			break;
		case 9:
			printf("%s", "������ ������������� ");
			break;
		}
		break;
	case 16:	//������� �������������
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
			printf("%s", "������������� ");
		}
		break;
	case 17:	//����� �������������
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
	/////////////////////////////////////////////////////////
	case 18:	//�����������
		switch (digit)
		{
		case 1:
			printf("%s", "���� ����������� ");
			break;
		case 2:
			printf("%s", "��� ������������ ");
			break;
		case 3:
			printf("%s", "��� ������������ ");
			break;
		case 4:
			printf("%s", "������ ������������ ");
			break;
		case 5:
			printf("%s", "���� ������������� ");
			break;
		case 6:
			printf("%s", "����� ������������� ");
			break;
		case 7:
			printf("%s", "���� ������������� ");
			break;
		case 8:
			printf("%s", "������ ������������� ");
			break;
		case 9:
			printf("%s", "������ ������������� ");
			break;
		}
		break;
	case 19:	//������� �������������
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
			printf("%s", "������������� ");
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
