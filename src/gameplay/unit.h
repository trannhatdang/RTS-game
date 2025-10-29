#include "raylib.h"


enum UnitType
{
	PERSON,
	BUILDING
};

typedef struct
{
	enum UnitType type;
	Vector2 position;
	Vector2 velocity;
	Image sprite;
	float speed;
}
Unit;

static int numUnits = 0;
static Unit** units;

Unit* SpawnUnit(enum UnitType type)
{
	Unit* newUnit = malloc(sizeof(Unit));
	newUnit->type = type;
	newUnit->speed = (float)10;
	units[numUnits] = newUnit;
	numUnits++; //not thread safe? lmao
		    //

	return units[numUnits-1];
}

void FreeUnits()
{
	for(int i = 0; i < numUnits; ++i)
	{
		free(units[i]);
	}
}

Unit* FindCloseUnit(Vector2 pos)
{
	float dist = (float)2;
	for(int i = 0; i < numUnits; ++i)
	{
		if(Vector2Distance(pos, units[i]->position) < dist)
		{
			return units[i];
		}
	}
	return NULL;
}

void UpdateUnits()
{
	for(int i = 0; i < numUnits; ++i)
	{
		units[i]->position = Vector2Add(units[i]->position + units[i]->speed * units[i] * velocity;
	}
}
