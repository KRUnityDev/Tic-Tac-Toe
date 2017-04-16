#include "Field.h"



Field::Field()
{
	state = Field::Empty;
}


Field::~Field()
{
}

Field::State Field::GetState()
{
	return this->state;
}

void Field::SetState(Field::State state)
{
	this->state = state;
}

std::ostream& operator<<(std::ostream& stream, Field& field)
{
	switch (field.state)
	{
		case Field::State::Empty:
			stream << " ";
			break;
		case Field::State::Circle:
			stream << "0";
			break;
		case Field::State::Cross:
			stream << "X";
			break;
	}
	return stream;
}
