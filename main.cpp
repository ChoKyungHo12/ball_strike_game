#include "GameHeader.h"

int main(void)
{
	srand(time(NULL));
	int sz_answer[3] = { 0 };
	int sz_input[3] = { 0 };
	int Game_counter = 1;
	Reset_Answer(sz_answer);
	Game_Start(sz_answer, sz_input, Game_counter);

	return 0;
}
