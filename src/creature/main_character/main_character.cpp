#include "main_character.h"
#include "../../utils/utils.h"
#include <iostream>

MainCharacter::MainCharacter(std::string name)
{
	if (CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
		utils::Print({"Welcome to the world, ", m_name, "!"});
	}
}

MainCharacter::MainCharacter(std::string name,
	int strength,
	int dexterity,
	int constitution,
	int intelligence,
	int wisdom,
	int charisma)
	: Creature(strength, dexterity, constitution, intelligence, wisdom, charisma)
{
	if (CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
		utils::Print({"Welcome to the world, ", m_name, "!"});
	}
}

MainCharacter::MainCharacter(std::string name,
	int hp,
	int ac,
	int speed,
	int strength,
	int dexterity,
	int constitution,
	int intelligence,
	int wisdom,
	int charisma,
	std::string creature_type)
	: Creature(hp, ac, speed, strength, dexterity, constitution, intelligence, wisdom, charisma, creature_type)
{
	if (CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
		utils::Print({"Welcome to the world, ", m_name, "!"});
	}
}

std::string MainCharacter::get_name() { return m_name; }

void MainCharacter::set_name(std::string name)
{
	if (CheckForAlphaOrWhitespace(name))
	{
		m_name = name;
		utils::Print({"Your new name is: ", m_name, "."});
	}
}

std::string MainCharacter::get_class() { return m_class; }
void MainCharacter::set_class(std::string player_class)
{
	m_class = player_class;
}

bool MainCharacter::CheckForAlphaOrWhitespace(std::string string)
{
	bool has_digit = false;

	for (const auto character : string)
	{
		if (!(std::isalpha(character) || character == ' '))
		{
			has_digit = true;
		}
	}

	if (has_digit)
	{
		utils::Print(
			{"Sorry, your name can only contain letters and spaces..."});
		return false;
	}
	else
	{
		return true;
	}
}
