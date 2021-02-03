#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <iomanip>
#include <memory>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

class Character
{
private:
    friend class boost::serialization::access;
    std::string name;
    int DAY;
    int LV;
    int HP;
    int maxHP;
    int AP;
    int DP;
    template <class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a &name &DAY &LV &HP &maxHP &AP &DP;
    }

public:
    Character();
    /**
     * Loading characters with their attributes
     * @parameter name: character name
     * @parameter DAY: in game date
     * @parameter LV: level of character
     * @parameter HP: Health of character
     * @parameter maxHP: max value of Health
     * @parameter AP: attack points
     * @parameter DP: defense points
    */
    Character(const std::string name, int DAY = 0, int LV = 0,
              int HP = 100, int maxHP = 100, int AP = 10, int DP = 6);
   // Character(const &Character)
    ~Character();
    
    //Older IMPLEMENTATION
    // void CharacterLoading(const std::string name, const int DAY, const int LV,
    //                       const int HP, const int maxHP, const int AP, const int DP);
    // Executed when the chareter is taken damge
    void takeDamage(int damage);
    // Show the current status of character
    void showStats();
    // pass a day
    void passDay();
    // restore HP
    void reset();
    int showAP();
    int showDP();
    // Check if the character is alive
    bool isAlive();
    //Older IMPLEMENTATION
    // std::string AttributeToString();
};
