#pragma once
#include <string>

namespace N_Pokemon 
{
	struct Move
	{
		std::string name;
		int power;

		Move(const std::string& moveName, int movePower) 
		{
			name = moveName;
			power = movePower;
		}
	};
}

