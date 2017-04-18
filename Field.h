#pragma once
#include <iostream>
class Field
{
public:
	Field();
	~Field();
	//States of Fields. States mean types of markers placed in single field.
	enum State
	{
		Empty = 0,
		Circle = 1,
		Cross = 2
	};
	//Return states of field
	Field::State GetState();
	//Setting state of field
	void SetState(Field::State state);
	friend std::ostream& operator<< (std::ostream& stream, Field& field);
private:
	//State of field
	Field::State state;
};

