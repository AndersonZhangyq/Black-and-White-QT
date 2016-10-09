#include "Move.h"

Move::Move():x(-1),y(-1){}

Move::Move(int x_in, int y_in):x(x_in),y(y_in){}

Move::Move(const Move& in):x(in.x),y(in.y) {}
