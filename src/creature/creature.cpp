#include "creature.h"
#include <iostream>
#include <string>

Creature::Creature()
	: m_hp(10), m_ac(10), m_speed(30), m_ability_scores{10, 10, 10, 10, 10, 10},
	  m_creature_type("humanoid"){};
Creature::Creature(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma)
	: m_hp(10), m_ac(10 + (dexterity - 10) / 2), m_speed(30),
	  m_ability_scores{strength, dexterity, constitution, intelligence, wisdom, charisma},
	  m_creature_type("humanoid"){};
Creature::Creature(int hp,
	int ac,
	int speed,
	int strength,
	int dexterity,
	int constitution,
	int intelligence,
	int wisdom,
	int charisma,
	std::string creature_type)
	: m_hp(hp), m_ac(ac), m_speed(speed),
	  m_ability_scores{strength, dexterity, constitution, intelligence, wisdom, charisma},
	  m_creature_type(creature_type){};

void Creature::PrintStats()
{
	std::cout << "==============================" << std::endl;
	std::cout << "Your stats are: " << std::endl;
	std::cout << "HP: " << m_hp << std::endl;
	std::cout << "AC: " << m_ac << std::endl;
	std::cout << "Speed: " << m_speed << std::endl;
	std::cout << "Strength: " << m_ability_scores[0] << std::endl;
	std::cout << "Dexterity: " << m_ability_scores[1] << std::endl;
	std::cout << "Constitution: " << m_ability_scores[2] << std::endl;
	std::cout << "Intelligence: " << m_ability_scores[3] << std::endl;
	std::cout << "Wisdom: " << m_ability_scores[4] << std::endl;
	std::cout << "Charisma: " << m_ability_scores[5] << std::endl;
	std::cout << "Creature type: " << m_creature_type << std::endl;
	std::cout << "==============================" << std::endl;
}

int Creature::get_hp() { return m_hp; };

void Creature::set_hp(int hp)
{
	if (hp >= 0)
	{
		m_hp = hp;
	}
	else
	{
		std::cerr << "The HP stat of Creature cannot be negative!\n";
	}
}

int Creature::get_ac() { return m_ac; };

void Creature::set_ac(int ac)
{
	if (ac >= 0)
	{
		m_ac = ac;
	}
	else
	{
		std::cerr << "The AC stat of Creature cannot be negative!\n";
	}
}

int Creature::get_speed() { return m_speed; };

void Creature::set_speed(int speed)
{
	if (speed >= 0)
	{
		m_speed = speed;
	}
	else
	{
		std::cerr << "The SPEED stat of Creature cannot be negative!\n";
	}
}

int Creature::get_ability_score(int n)
{
	if (n > -1 && n < 6)
	{
		return m_ability_scores[n];
	}
	else
	{
		std::cerr << "You have asked for an invalid ability score. Valid "
					 "values are between 0 and 6."
				  << std::endl;
		return -1;
	}
}

void Creature::set_ability_score(int ability_score, int value)
{
	if (ability_score > -1 && ability_score < 6 && value > -1)
	{
		m_ability_scores[ability_score] = value;
	}
	else
	{
		std::cerr << "The ability scores of Creature cannot be negative!\n";
	}
}

std::string Creature::get_creature_type() { return m_creature_type; };

void Creature::set_creature_type(std::string creature_type)
{
	m_creature_type = creature_type;
}
