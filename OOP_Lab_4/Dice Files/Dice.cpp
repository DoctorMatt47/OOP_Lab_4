#include "Dice.h"

#include <iostream>

Dice::Dice()
{
	_amountOfFaces = 0;
}

size_t Dice::GetAmountOfFaces() const
{
	return _amountOfFaces;
}

void Dice::AddFace(Face& face)
{
	_faces.PushBack(face);
	_amountOfFaces++;
}

void Dice::SetAmountOfFaces(size_t amountOfFaces)
{
	_amountOfFaces = amountOfFaces;
}

double Dice::GetProbabilityByNumber(size_t num)
{
	if (num > _amountOfFaces)
		return 0;
	return _faces[num - 1].GetProbability();
}

void Dice::Print()
{
	for (int i = 0; i < _amountOfFaces; i++)
		std::cout << _faces[i].GetNumber() << " : " << _faces[i].GetProbability() << ",  ";
	std::cout << std::endl;
}
