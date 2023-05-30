#include "start_game.h"
#include "../../utils/utils.h"
#include "../../create_character/create_character.h"
#include "../../story/prologue.h"

void StartGame(MainCharacter& main_character)
{
	utils::Print({"Starting the game..."});

	utils::ClearScreen();

	CreateCharacter(main_character);

	SaveGame(main_character);

	Prologue(main_character);
}
