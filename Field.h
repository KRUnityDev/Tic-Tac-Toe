#pragma once
#include <iostream>
class Field
{
public:
	Field();
	~Field();
	enum State
	{
		Empty = 0,
		Circle = 1,
		Cross = 2
	};
	Field::State GetState();
	void SetState(Field::State state);
	friend std::ostream& operator<< (std::ostream& stream, Field& field);
private:
	Field::State state;
};

