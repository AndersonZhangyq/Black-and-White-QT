#pragma once
struct Move {
	Move();
	Move(int x_in, int y_in);
    Move(const Move& in);

	int x;
	int y;
};
