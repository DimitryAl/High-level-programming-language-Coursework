#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

void word_out(int digit_rank, int digit, int prev_digit, char num[256]);  //������ ����� � ���� �������������
void dec_out(int digit_rank, int digit, char num[256]);					 //������ �������� ����� � ���� �������������
unsigned long long int strCheck(char str[256]);							//�������� ������� ������
																	   //� �������������� � � ������������� ��� 

int main()
{
	unsigned long long int number;					//0 to 18,446,744,073,709,551,615
	int counter;								   //������� ���������� �������� � �����
	int digits[20];								  //������������� ����� � ���� �������
	char in[256];								 //������� ������
	char numeral[256];							//������ � ������������
	int j;
	setlocale(LC_ALL, "Rus");
	system("color F0");

	printf("������� ����������� ����� �� ������ 18,446,744,073,709,551,615:\n");
	gets(in);
	number = strCheck(in);					//�������� ������� ������ � �������������� �� � �����
	switch (number)							//����� ��������� �� ������ � ���������� ���������
	{
	case 0:
		printf("������: 0 �� ����������� �����.\n");
		system("pause");
		return 1;
		break;
	case -4:
		printf("������: ������� �� ����������� ����� �����.\n");
		system("pause");
		return 2;
		break;
	case -2:
		printf("������: �������� ����� ������� �������.\n");
		system("pause");
		return 3;
		break;
	case -3:
		printf("������: ������ �� �������.\n");
		system("pause");
		return 4;
		break;
	}			   
	printf("��������� �����: %llu \n", number);
	numeral[0] = '\0';
	counter = 0;
	while (number)								//���������� ������� ������� �����
	{
		digits[counter] = number % 10;
		counter++;
		number /= 10;
	}
	for (j = counter - 1; j >= 0; j--)					//������ ����� � ���� �������������
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
	printf("����� ������������:\n");
	printf(numeral);
	printf("%c", '\n');
	system("pause");
	return 0;
}

unsigned long long int strCheck(char str[256])
{
	int i;
	unsigned long long int number;
	i = 0;
	while (i < strlen(str))
	{
		if (str[i] != '0')
		{
			str = &str[i];
			break;
		}
		i++;
	}
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

void dec_out(int digit_rank, int digit, char num[256])
{
	switch (digit)
	{
	case 0:
		strcat(num, "������");
		break;
	case 1:
		strcat(num, "�����������");
		break;
	case 2:
		strcat(num, "����������");
		break;
	case 3:
		strcat(num, "����������");
		break;
	case 4:
		strcat(num, "������������");
		break;
	case 5:
		strcat(num, "����������");
		break;
	case 6:
		strcat(num, "�����������");
		break;
	case 7:
		strcat(num, "����������");
		break;
	case 8:
		strcat(num, "������������");
		break;
	case 9:
		strcat(num, "������������");
		break;
	}
	switch (digit_rank)							//� ����������� �� ������ ����� ������� ��� ��������
	{
	case 4:
		strcat(num, " ����� ");
		break;
	case 7:
		strcat(num, " ��������� ");
		break;
	case 10:
		strcat(num, " ���������� ");
		break;
	case 13:
		strcat(num, " ���������� ");
		break;
	case 16:
		strcat(num, " ������������� ");
		break;
	case 19:
		strcat(num, " ������������� ");
		break;
	}
}

void word_out(int digit_rank, int digit, int prev_digit, char num[256])
{
	if (digit_rank == 2 || digit_rank == 5 || digit_rank == 8 || digit_rank == 11 || digit_rank == 14 || digit_rank == 17)								//���� ����� ��������� � ������� �����
	{
		switch (digit)
		{
		case 1:
			strcat(num, "��� ");
			break;
		case 2:
			strcat(num, "������ ");
			break;
		case 3:
			strcat(num, "������ ");
			break;
		case 4:
			strcat(num, "��������� ");
			break;
		case 5:
			strcat(num, "������� ");
			break;
		case 6:
			strcat(num, "�������� ");
			break;
		case 7:
			strcat(num, "������� ");
			break;
		case 8:
			strcat(num, "��������� ");
			break;
		case 9:
			strcat(num, "��������� ");
			break;
		}
	}
	if (digit_rank == 1 || digit_rank == 4 || digit_rank == 7 || digit_rank == 10 || digit_rank == 13 || digit_rank == 16 || digit_rank == 19)						//���� ����� ��������� � ������� ��������
	{
		switch (digit)
		{
		case 2:
			strcat(num, "�������� ");
			break;
		case 3:
			strcat(num, "�������� ");
			break;
		case 4:
			strcat(num, "����� ");
			break;
		case 5:
			strcat(num, "��������� ");
			break;
		case 6:
			strcat(num, "���������� ");
			break;
		case 7:
			strcat(num, "��������� ");
			break;
		case 8:
			strcat(num, "����������� ");
			break;
		case 9:
			strcat(num, "��������� ");
			break;
		}
		if (prev_digit == 0)														//���� ���������� ����� ����� ����, �� ��������� � ������ � ������������ �������������� �������� ������
		{
			switch (digit_rank)
			{
			case 4:
				strcat(num, "����� ");
				break;
			case 7:
				strcat(num, "��������� ");
				break;
			case 10:
				strcat(num, "���������� ");
				break;
			case 13:
				strcat(num, "���������� ");
				break;
			case 16:
				strcat(num, "�������������  ");
				break;
			case 19:
				strcat(num, "�������������  ");
				break;
			}
		}
	}
	switch (digit_rank)
	{
	case 0: //�������
		switch (digit)
		{
		case 1:
			strcat(num, "����");
			break;
		case 2:
			strcat(num, "���");
			break;
		case 3:
			strcat(num, "���");
			break;
		case 4:
			strcat(num, "������");
			break;
		case 5:
			strcat(num, "����");
			break;
		case 6:
			strcat(num, "�����");
			break;
		case 7:
			strcat(num, "����");
			break;
		case 8:
			strcat(num, "������");
			break;
		case 9:
			strcat(num, "������");
			break;
		}
		break;
	case 3:	//������
		switch (digit)
		{
		case 1:
			strcat(num, "���� ������ ");
			break;
		case 2:
			strcat(num, "��� ������ ");
			break;
		case 3:
			strcat(num, "��� ������ ");
			break;
		case 4:
			strcat(num, "������ ������ ");
			break;
		case 5:
			strcat(num, "���� ����� ");
			break;
		case 6:
			strcat(num, "����� ����� ");
			break;
		case 7:
			strcat(num, "���� ����� ");
			break;
		case 8:
			strcat(num, "������ ����� ");
			break;
		case 9:
			strcat(num, "������ ����� ");
			break;
		}
		break;
	case 6:	//��������
		switch (digit)
		{
		case 1:
			strcat(num, "���� ������� ");
			break;
		case 2:
			strcat(num, "��� ��������  ");
			break;
		case 3:
			strcat(num, "��� �������� ");
			break;
		case 4:
			strcat(num, "������ �������� ");
			break;
		case 5:
			strcat(num, "���� ��������� ");
			break;
		case 6:
			strcat(num, "����� ��������� ");
			break;
		case 7:
			strcat(num, "���� ��������� ");
			break;
		case 8:
			strcat(num, "������ ��������� ");
			break;
		case 9:
			strcat(num, "������ ��������� ");
			break;
		}
		break;
	case 9:	//���������
		switch (digit)
		{
		case 1:
			strcat(num, "���� �������� ");
			break;
		case 2:
			strcat(num, "��� ��������� ");
			break;
		case 3:
			strcat(num, "��� ��������� ");
			break;
		case 4:
			strcat(num, "������ ��������� ");
			break;
		case 5:
			strcat(num, "���� ���������� ");
			break;
		case 6:
			strcat(num, "����� ���������� ");
			break;
		case 7:
			strcat(num, "���� ���������� ");
			break;
		case 8:
			strcat(num, "������ ���������� ");
			break;
		case 9:
			strcat(num, "������ ���������� ");
			break;
		}
		break;
	case 12:	//��������
		switch (digit)
		{
		case 1:
			strcat(num, "���� �������� ");
			break;
		case 2:
			strcat(num, "��� ��������� ");
			break;
		case 3:
			strcat(num, "��� ��������� ");
			break;
		case 4:
			strcat(num, "������ ��������� ");
			break;
		case 5:
			strcat(num, "���� ���������� ");
			break;
		case 6:
			strcat(num, "����� ���������� ");
			break;
		case 7:
			strcat(num, "���� ���������� ");
			break;
		case 8:
			strcat(num, "������ ���������� ");
			break;
		case 9:
			strcat(num, "������ ���������� ");
			break;
		}
		break;
	case 15:	//�����������
		switch (digit)
		{
		case 1:
			strcat(num, "���� ����������� ");
			break;
		case 2:
			strcat(num, "��� ������������ ");
			break;
		case 3:
			strcat(num, "��� ������������ ");
			break;
		case 4:
			strcat(num, "������ ������������ ");
			break;
		case 5:
			strcat(num, "���� ������������� ");
			break;
		case 6:
			strcat(num, "����� ������������� ");
			break;
		case 7:
			strcat(num, "���� ������������� ");
			break;
		case 8:
			strcat(num, "������ ������������� ");
			break;
		case 9:
			strcat(num, "������ ������������� ");
			break;
		}
		break;
	case 18:	//�����������
		switch (digit)
		{
		case 1:
			strcat(num, "���� ����������� ");
			break;
		case 2:
			strcat(num, "��� ������������ ");
			break;
		case 3:
			strcat(num, "��� ������������ ");
			break;
		case 4:
			strcat(num, "������ ������������ ");
			break;
		case 5:
			strcat(num, "���� ������������� ");
			break;
		case 6:
			strcat(num, "����� ������������� ");
			break;
		case 7:
			strcat(num, "���� ������������� ");
			break;
		case 8:
			strcat(num, "������ ������������� ");
			break;
		case 9:
			strcat(num, "������ ������������� ");
			break;
		}
		break;
	}
}
