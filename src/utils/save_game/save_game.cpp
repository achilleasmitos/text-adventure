#include "save_game.h"
#include "../utils.h"
#include "../../creature/main_character/main_character.h"
#include <iostream>
#include <fstream>

void SaveGame(MainCharacter& main_character)
{
	std::ofstream output_file;

	output_file.open("savefile.txt");

	if (output_file.is_open())
	{
		output_file << "Ability Scores for: " << std::endl;
		output_file << main_character.get_name() << std::endl;
		output_file << "==============================" << std::endl;
		output_file << "HP: " << std::endl;
		output_file << main_character.get_hp() << std::endl;
		output_file << "AC: " << std::endl;
		output_file << main_character.get_ac() << std::endl;
		output_file << "Speed: " << std::endl;
		output_file << main_character.get_speed() << std::endl;
		std::string ability_scores[] = {"Strength: ", "Dexterity: ", "Constitution: ", "Intelligence: ", "Wisdom: ", "Charisma: "};
		for (int i = 0; i < sizeof(ability_scores) / sizeof(ability_scores[0]); i++)
		{
			output_file << ability_scores[i] << std::endl;
			output_file << main_character.get_ability_score(i) << std::endl;
		}
		output_file << "==============================" << std::endl;
		output_file << std::endl;
		output_file << "Sound Volume: " << std::endl;
		output_file << utils::g_sound_volume << std::endl;
		output_file << "Text Size: " << std::endl;
		output_file << utils::g_text_size << std::endl;
		output_file << "Text Speed: " << std::endl;
		output_file << utils::g_sleep_for_ms << std::endl;
		output_file << "Text Weight: " << std::endl;
		output_file << utils::g_text_weight << std::endl;

		output_file.close();

		std::cout << "Game saved successfully to savefile.txt" << std::endl;
	}
	else
	{
		std::cerr << "Unable to open the savefile: savefile.txt" << std::endl;
	}
}
