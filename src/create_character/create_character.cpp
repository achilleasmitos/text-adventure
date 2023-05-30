#include "./create_character.h"
#include "../utils/utils.h"
#include <string>
#include <fstream>

void SetAbilityScore(MainCharacter& main_character, int ability_score_pos, int main_stats[6], int array_length)
{
	std::string ability_scores[6] = {"Strength", "Dexterity", "Consitution", "Intelligence", "Wisdom", "Charisma"};

	// Print the remaining scores.
	std::cout << "Your remaining scores:" << std::endl;
	for (int i = 0; i < array_length; i++)
	{
		std::cout << i + 1 << ") " << main_stats[i] << std::endl;
	}

	int stat_choice = 0;

	// Ask for user input.
	utils::Print({"Which stat would you like for your " + ability_scores[ability_score_pos] +
		"? (1-" + std::to_string(array_length) + ")"});
	utils::GetUserInput(stat_choice);

	// Check for valid input, and set the appropriate ability score.
	while (stat_choice < 1 || stat_choice > array_length)
	{
		std::cout << "Sorry, that is an invalid number. Please give me an "
					 "intger\nbetween 1 and "
				  << array_length << ": ";
		utils::GetUserInput(stat_choice);
	}
	main_character.set_ability_score(ability_score_pos, main_stats[stat_choice - 1]);

	// Shift to the left the stats lying right of the chosen one.
	for (int i = stat_choice - 1; i < array_length - 1; i++)
	{
		main_stats[i] = main_stats[i + 1];
	}
}

void CreateCharacter(MainCharacter& main_character)
{
	utils::Print({"You are about to create a new character."});

	// Check if a savefile exists, and warn the player.
	std::string save_file_path = "savefile.txt";
	std::ifstream save_file(save_file_path);

	if (save_file.good())
	{
		utils::Print({"A save file with an already-created character has been "
					  "detected."});
		utils::Print({"Do you want to continue with the character creation and "
					  "overwrite it? (yes/no)"});

		std::string overwrite_character = "yes";
		utils::GetUserInput(overwrite_character);

		while (overwrite_character != "yes" && overwrite_character != "no")
		{
			std::cout << "Your answer is invalid. Please enter either \"yes\" "
						 "or \"no\": ";
			utils::GetUserInput(overwrite_character);
		}

		if (overwrite_character == "no")
		{
			return; // Exit CreateCharacter() without modifying the main character.
		}
	}
	save_file.close();

	// Begin the actual character creation.
	std::string user_answer;

	utils::Print({"Please give me your name: "});
	utils::GetUserInput(user_answer);
	main_character.set_name(user_answer);

	utils::Print({"Please give me your race: "});
	utils::GetUserInput(user_answer);
	main_character.set_creature_type(user_answer);

	utils::Print({"Please give me your class: "});
	utils::GetUserInput(user_answer);
	main_character.set_class(user_answer);

	// Roll the main stats, ala 4d6-drop-lowest style.
	int main_stats[6];
	for (int i = 0; i < 6; i++)
	{
		int rolls[4];
		int lowest_roll_pos = 0;
		int sum_of_rolls = 0;

		for (int j = 0; j < 4; j++)
		{
			rolls[j] = utils::RollDice({"1d6"});
			sum_of_rolls += rolls[j];

			if (rolls[j] < rolls[lowest_roll_pos])
			{
				lowest_roll_pos = j;
			}
		}

		sum_of_rolls -= rolls[lowest_roll_pos]; // Subtract the lowest roll (which has already been added before).

		main_stats[i] = sum_of_rolls;
	}

	std::cout << "You rolled: ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << main_stats[i] << ", ";
	}
	std::cout << main_stats[5] << std::endl;

	for (int i = 0; i < 6; i++)
	{
		SetAbilityScore(main_character, i, main_stats, 6 - i);
	}
}
