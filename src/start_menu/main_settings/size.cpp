#include "size.h"
#include "../../utils/utils.h"
#include <iostream>

void Size(){
	std::cout << "Pick Number" << std::endl;
	utils::GetUserInput(utils::g_text_size);
	utils::CustomizeText(utils::g_text_size);
}