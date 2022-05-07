#include "GameHeader.h"

void Reset_Answer(int sz_answer[])
{
	int i = 0;
	while (TRUE)
	{
		for (i = 0; i < 3; i++)
		{
			sz_answer[i] = (rand() % 9) + 1;
		}

		//���信 ���� ���� �ִ��� ����
		if (sz_answer[0] == sz_answer[1])
		{
			continue;
		}
		if (sz_answer[1] == sz_answer[2])
		{
			continue;
		}
		if (sz_answer[0] == sz_answer[2])
		{
			continue;
		}

		break;
	}
}

void Input_Num(int sz_input[])
{
	int trial_num = 0;
	int counter = 0;
	while (TRUE)
	{
		printf("�� �ڸ� ���ڸ� �Է��ϼ���\n");
		scanf("%d", &trial_num);
		if (Num_Rule(trial_num, sz_input) == TRUE)
		{
			printf("���� ���� �Է�! �Ǻ� ����~~\n\n");
			break;
		}
	}
}

void Game_Start(int sz_answer[], int sz_input[], int Game_counter)
{
	int ball = 0;
	int strike = 0;
	int i = 0;
	int j = 0;

	while (TRUE)
	{
		Input_Num(sz_input);
		if (Game_counter == 11)
		{
			printf("���� Ƚ�� �ʰ�!\n");
			Game_Ending(sz_answer, sz_input);
			return;
		}

		for (i = 0; i < 3; i++)
		{
			if (sz_answer[i] == sz_input[i])
				strike++;
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (i == j)
					continue;
				if (sz_answer[i] == sz_input[j])
				{
					ball++;
				}
			}
		}

		if (strike == 3)
		{
			printf("�����Դϴ�~\n");
			Game_Ending(sz_answer, sz_input);
			return;
		}
		printf("%d ��Ʈ����ũ, %d �� �Դϴ�~\n", strike, ball);
		ball = 0;
		strike = 0;
		printf("���� Ƚ�� : %d\n\n", Game_counter);
		Game_counter++;
	}

}

int Num_Rule(int trial_num, int sz_input[])
{
	int i = 0;
	int same_num = 0;
	//�����Ͱ� �����ȿ� �ִ��� ����
	if (trial_num <= 99 || trial_num >= 999)
	{
		printf("�߸��� ������ �Է��ϼ̽��ϴ�. �ٽ� �Է�\n");
		return FALSE;
	}

	//�ϴ� ������ ����
	for (i = 0; i < 3; i++)
	{
		sz_input[i] = (trial_num / (int)pow((double)10, (double)(2 - i)));
		trial_num -= sz_input[i] * (int)pow((double)10, (double)(2 - i));
	}

	//���� ���� �ִ��� ����
	if (sz_input[0] == sz_input[1])
	{
		printf("���� ���ڸ� �Է��߽��ϴ�. �ٽ� �Է�\n");
		return FALSE;
	}
	if (sz_input[1] == sz_input[2])
	{
		printf("���� ���ڸ� �Է��߽��ϴ�. �ٽ� �Է�\n");
		return FALSE;
	}
	if (sz_input[0] == sz_input[2])
	{
		printf("���� ���ڸ� �Է��߽��ϴ�. �ٽ� �Է�\n");
		return FALSE;
	}

	return TRUE;
}

void Game_Ending(int sz_answer[], int sz_input[])
{
	int i = 0;
	printf("���� �迭: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d", sz_answer[i]);
	}
	printf("\n");
}