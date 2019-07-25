#pragma once
#include<string>


class Cell
{
public:
	Cell(bool _IsAlive);
	~Cell();

	std::string ToString();

public:
	bool IsAlive = false;
};
