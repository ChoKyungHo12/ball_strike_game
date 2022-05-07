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

		//정답에 같은 숫자 있는지 검증
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
		printf("세 자리 숫자를 입력하세요\n");
		scanf("%d", &trial_num);
		if (Num_Rule(trial_num, sz_input) == TRUE)
		{
			printf("옳은 숫자 입력! 판별 시작~~\n\n");
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
			printf("도전 횟수 초과!\n");
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
			printf("성공입니다~\n");
			Game_Ending(sz_answer, sz_input);
			return;
		}
		printf("%d 스트라이크, %d 볼 입니다~\n", strike, ball);
		ball = 0;
		strike = 0;
		printf("도전 횟수 : %d\n\n", Game_counter);
		Game_counter++;
	}

}

int Num_Rule(int trial_num, int sz_input[])
{
	int i = 0;
	int same_num = 0;
	//데이터가 범위안에 있는지 점검
	if (trial_num <= 99 || trial_num >= 999)
	{
		printf("잘못된 범위를 입력하셨습니다. 다시 입력\n");
		return FALSE;
	}

	//일단 데이터 저장
	for (i = 0; i < 3; i++)
	{
		sz_input[i] = (trial_num / (int)pow((double)10, (double)(2 - i)));
		trial_num -= sz_input[i] * (int)pow((double)10, (double)(2 - i));
	}

	//같은 숫자 있는지 검증
	if (sz_input[0] == sz_input[1])
	{
		printf("같은 숫자를 입력했습니다. 다시 입력\n");
		return FALSE;
	}
	if (sz_input[1] == sz_input[2])
	{
		printf("같은 숫자를 입력했습니다. 다시 입력\n");
		return FALSE;
	}
	if (sz_input[0] == sz_input[2])
	{
		printf("같은 숫자를 입력했습니다. 다시 입력\n");
		return FALSE;
	}

	return TRUE;
}

void Game_Ending(int sz_answer[], int sz_input[])
{
	int i = 0;
	printf("정답 배열: ");
	for (i = 0; i < 3; i++)
	{
		printf("%d", sz_answer[i]);
	}
	printf("\n");
}