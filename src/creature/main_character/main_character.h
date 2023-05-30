#pragma once
#include "../creature.h"
#include <string>

class MainCharacter : public Creature
{
public:
	// Create a main character with default stats.
	MainCharacter(std::string name);
	// Create a main character with the given ability scores.
	MainCharacter(std::string name,
		int strength,
		int dexterity,
		int constitution,
		int intelligence,
		int wisdom,
		int charisma);
	// Create a main character with all the essential stats given.
	MainCharacter(std::string name,
		int hp,
		int ac,
		int speed,
		int strength,
		int dexterity,
		int constitution,
		int intelligence,
		int wisdom,
		int charisma,
		std::string creature_type);

	std::string get_name();
	void set_name(std::string name);

	std::string get_class();
	void set_class(std::string player_class);

private:
	std::string m_name;
	std::string m_class;

	/**
	 * @brief A function that checks if the given string consists only of letters and whitespaces.
	 *
	 * @param string
	 * @return true if the above condition holds, false otherwise.
	 */
	bool CheckForAlphaOrWhitespace(std::string string);
};
