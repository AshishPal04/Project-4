/*
CSCI235 Fall 2023
Project 2 - Derived Classes
Ashish Pal
Oct 23 2023
Scoundrel.hpp defines the constructors and private and public function implementation of the Scoundrel class
*/
#ifndef SCOUNDREL_HPP
#define SCOUNDREL_HPP

#include "Character.hpp"
using namespace std;


enum Dagger
{
    WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE
};

class Scoundrel : public Character
{
    private:
      // A string that represents their Faction
      std::string faction_;
      // A boolean indicating if they have a disguise
      bool has_disguise_;
      // An enum representing their dagger type
      Dagger dagger_;

    public:
      /**
          Default constructor.
          Default-initializes all private members. 
          Default character name: "NAMELESS". Booleans are default-initialized to False. 
          Default dagger: WOOD. Default faction: "NONE". 
      */
      Scoundrel();

      /**
          Parameterized constructor.
           @param      : The name of the character (a const string reference)
           @param      : The race of the character (a const string reference)
           @param      : The character's vitality (an integer)
           @param      : The character's max armor level (an integer)
           @param      : The character's level (an integer)
           @param      : A flag indicating whether the character is an enemy
           @param      : The character's dagger type (a const string reference).
    							       String inputs can be in lowercase, but must be converted to 
									       uppercase when setting the dagger enum.
           @param      : The character's Faction (a const string reference). 
									       Valid Factions: [CUTPURSE, SHADOWBLADE, SILVERTONGUE] 
									       String inputs can be in lowercase, but must be converted to 
								        uppercase when setting the variable.
           @param      : A flag indicating whether the character has a disguise
          @post        : The private members are set to the values of the corresponding 
									       parameters.
 								         If the dagger type is not provided or invalid, the variable should 
									       be set to WOOD. 
    	                   If the Faction is not provided or invalid, the variable should be 
									       set to "NONE". 
      */
      Scoundrel(const std::string& name, const std::string& race, int vitality = 0, int armor = 0, int level = 0, bool enemy = false, const std::string& dagger = "WOOD", const std::string& faction = "NONE", bool has_disguise = false);

      /**
        @param  : a reference to a string representing the dagger type
        @post   : sets the private member variable to the value of the parameter. 
                : If the dagger type is not valid (i.e, is one of the following: [WOOD, BRONZE, IRON, STEEL, MITHRIL, ADAMANT, RUNE]), 
                the variable should be set to WOOD. 
      **/
      void setDagger(const std::string& dagger);

      /**
       @return  : the string indicating the character's dagger type
      **/
      std::string getDagger() const;


      /**
        @param  	: a reference to a string representing the character's Faction
        @post   	: sets the private member variable to the value of the parameter. 
    						    String inputs can be in lowercase, but must be converted to 
								    uppercase when setting the variable.
            	      If the provided faction is not one of the following: 
            	      [NONE, CUTPURSE, SHADOWBLADE, SILVERTONGUE], 
            	      do nothing and return false.
        @return  	: true if setting the variable was successful, false otherwise.
      **/
      bool setFaction(const std::string& faction);


      /**
       @return  : the string indicating the character's Faction
      **/
      std::string getFaction() const;

      /**
       @param  : a reference to boolean
      @post   : sets the private member variable indicating whether the character has a disguise
      **/
      void setDisguise(const bool& has_disguise);


      /**
       @return  : the visual aid flag
      **/
      bool hasDisguise() const;

      /**
    @post     : displays Scoundrel data in the form:
    "[NAME] is a Level [LEVEL] [RACE] SCOUNDREL.
    \nVitality: [VITALITY]
    \nArmor: [ARMOR]
    \nThey are [an enemy/not an enemy].
    \nDagger: [DAGGER]
    \nFaction: [FACTION]
    \nDisguise: [TRUE/FALSE]
    \n\n"
    
    Example:
    FLEA is a Level 4 DWARF SCOUNDREL.
    Vitality: 6
    Armor: 4
    They are an enemy.
    Dagger: ADAMANT
    Faction: CUTPURSE
    Disguise: TRUE
*/

      void display() const override;

      /**
    @post: 
    If the character is UNDEAD, gain 3 Vitality points. Nothing else happens. 
    
    If the character is NOT UNDEAD, their Vitality is set to 1. 
    In addition, as a Scoundrel: If the character is of the CUTPURSE faction, they steal a health potion and recover 3 Vitality points. 
    If they are of the SILVERTONGUE faction, they talk the cook into redoing their stew as follows: they have a 70% chance of recovering 4 Vitality points, but a 30% chance of resetting their Vitality to 1, and they lose their daggers, which are replaced with WOOD daggers. (If their daggers were already WOOD, nothing happens to the daggers). 
*/

      void eatTaintedStew() override;
};

#endif
