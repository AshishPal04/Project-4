/*
CSCI235 Fall 2023
Project 2 - Derived Classes
Ashish Pal
Oct 23 2023
Barbarian.cpp defines the constructors and private and public function implementation of the Barbarian class
*/


#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
using namespace std;

class Barbarian : public Character
{
    private:
        // A string representing their main weapon
        std::string main_weapon_;
        // A string representing their offhand weapon
        std::string secondary_weapon_;
        // A boolean indicating if they are enraged
        bool enraged_;

    public:
        /**
            Default constructor.
            Default-initializes all private members. Default character name: "NAMELESS". 
            Booleans are default-initialized to False. 
            Default weapons: "NONE". 
        */
        Barbarian();

        /**
            Parameterized constructor.
            @param      : The name of the character (a string)
            @param      : The race of the character (an enum)
            @param      : The character's vitality (an integer)
            @param      : The character's max armor level (an integer)
            @param      : The character's level (an integer)
            @param      : A flag indicating whether the character is an enemy
            @param      : The character's main weapon (a string). String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            @param      : The character's offhand weapon (a string). String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
            @param      : A flag indicating whether the character is enraged, false by default
            @post       : The private members are set to the values of the corresponding parameters. 
                        : If the main and secondary weapons are not provided or invalid, the variables are set to "NONE".
        */
        Barbarian(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& main_weapon = "NONE", const std::string& secondary_weapon = "NONE", bool enraged = false);

        /**
            @param  : a reference to a string representing the Character's main weapon
            @post   : sets the private member variable to the value of the parameter. Only alphabetical characters are allowed.
                    : String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
                    : If the given input is invalid (i.e contains numbers), do nothing and return false
            @return : true if setting the variable was successful, false otherwise.
        **/
        bool setMainWeapon(const std::string& main_weapon);

        /**
         @return  : a string of the Character's main weapon
        **/
        std::string getMainWeapon() const;

        /**
            @param  : a reference to a string representing the Character's secondary weapon
            @post   : sets the private member variable to the value of the parameter. Only alphabetical characters are allowed.
                    : String inputs can be in lowercase, but must be converted to uppercase when setting the variable.
                    : If the given input is invalid (i.e contains numbers), do nothing and return false
            @return : true if setting the variable was successful, false otherwise.
        **/
        bool setSecondaryWeapon(const std::string& secondary_weapon);

        /**
         @return  : a string of the Character's secondary weapon
        **/
        std::string getSecondaryWeapon() const;

        /**
         @param  : a reference to a bool
        @post   : sets the private member variable to the value of the parameter.
        **/
        void setEnrage(const bool& enraged);

        /**
         @return  : a boolean of whether the Character is enraged
        **/
        bool getEnrage() const;

        /**
         @post   : sets the enraged variable to the opposite of what it was
        **/
        void toggleEnrage();

        /**
    @post     : displays Barbarian data in the form:
    "[NAME] is a Level [LEVEL] [RACE] BARBARIAN.
    \nVitality: [VITALITY]
    \nArmor: [ARMOR]
    \nThey are [an enemy/not an enemy].
    \nMain Weapon: [MAINWEAPON]
    \nOffhand Weapon: [OFFHANDWEAPON]
    \nEnraged: [TRUE/FALSE]
    \n\n"
    
    Example:
    BONK is a Level 5 HUMAN BARBARIAN.
    Vitality: 11
    Armor: 5
    They are an enemy.
    Main Weapon: MACE
    Offhand Weapon: ANOTHERMACE
    Enraged: TRUE 
*/
        void display() const override;

        /**
    @post: 
    If the character is UNDEAD, gain 3 Vitality points. Nothing else happens.
    
    If the character is NOT UNDEAD, Vitality is set to 1. 
    In addition, as a Barbarian: 
    Become enraged if the character was not enraged, and not enraged if they were already enraged. 
    If they have now become enraged, the offhand weapon is replaced with "TABLE". 
    If they are now not enraged, the main weapon is replaced with "BUCKET".
*/

        void eatTaintedStew() override;
};

#endif
