#include "InGame.h"
int ATTRIBUTE_COUT_LENGTH = 12;
Character::Character()
{
}
Character::Character(const std::string name, int DAY, int LV,
					 int HP, int maxHP, int AP, int DP)
{
	this->name = name;
	this->DAY = DAY;
	this->LV = LV;
	this->HP = HP;
	this->maxHP = maxHP;
	this->AP = AP;
	this->DP = DP;
}
Character::~Character()
{
}
//Older IMPLEMENTATION
// void Character::CharacterLoading(const std::string name, const int DAY, const int LV,
// 								 const int HP, const int maxHP, const int AP, const int DP)
// {
// 	this->name = name;
// 	this->DAY = DAY;
// 	this->LV = LV;
// 	this->HP = HP;
// 	this->maxHP = maxHP;
// 	this->AP = AP;
// 	this->DP = DP;
// }
void Character::showStats()
{
	std::cout << "You have spent " << DAY << " days in the game." << std::endl;
	std::cout << "Your current state shows below" << std::endl;
	// TODO: ADD character info;
	std::cout << std::setw(ATTRIBUTE_COUT_LENGTH) << "name: " << name << std::endl;
	std::cout << std::setw(ATTRIBUTE_COUT_LENGTH) << "level: " << LV << std::endl;
	std::cout << std::setw(ATTRIBUTE_COUT_LENGTH) << "health: " << HP << "/" << maxHP << std::endl;
	std::cout << std::setw(ATTRIBUTE_COUT_LENGTH) << "attack: " << AP << std::endl;
	std::cout << std::setw(ATTRIBUTE_COUT_LENGTH) << "defense: " << DP << std::endl;
}
void Character::reset()
{
	HP = maxHP;
}
void Character::passDay()
{
	DAY++;
}
void Character::takeDamage(int damage)
{
	HP -= damage;
	HP = std::max(0, HP);
}
int Character::showAP()
{
	return AP;
}
int Character::showDP()
{
	return DP;
}
bool Character::isAlive()
{
	return (HP > 0);
}
//Older IMPLEMENTATION
// std::string Character::AttributeToString()
// {
// 	return name + " " + std::to_string(DAY) + " " + std::to_string(LV) + " " +
// 		   std::to_string(HP) + " " + std::to_string(maxHP) + " " + std::to_string(AP) + " " + std::to_string(DP) + " ";
// }