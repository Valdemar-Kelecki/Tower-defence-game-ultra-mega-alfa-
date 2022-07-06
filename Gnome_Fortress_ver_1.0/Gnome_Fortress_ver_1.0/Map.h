#pragma once
#include <string>

struct Map {

	static const int yHeigth = 25;
	static const int xHeigth = 45;

	/*
	struct Cell {

		char icon;
		int weight;
	} field[yHeigth][xHeigth];
	*/

	std::string field[yHeigth] = 
	{

		{"--c---------------------------------------h--"},
		{"|.........................................../"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"0                                           0"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|                                           /"},
		{"|___________________________________________/"},
		{"-----------------------------------------sHl-"},

	};

	//bool LoadMap(char* fileName);
};