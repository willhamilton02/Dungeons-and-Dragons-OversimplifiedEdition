#include "Header.h"
#include <Windows.h>

// Variable Initializers
string startCondition;
bool outOfGame = true;
bool raceChoice = false;
bool classChoiceMade;
string tempPlayerRace;
string tempPlayerClass;
int heightIn;
int heightFt;
string heightIn_s;
string heightFt_s;
bool turnOnGoing = true;
string questResponse1;
bool questChoice1 = false;
//Player Attributes
string name;
string race;
string playerClass;
string height;
int weight;
int hp;
int speed;
int str;
int dex;
int cons;
int lvl = 1;
int gold = 25;
string inv[6] = { "A Basic Shortsword","Empty","Empty","Empty","Empty","Empty" };
string quest = "Go To Hardun To Get Supplies For Your Adventure";

//Random Attack Generator
random_device rag;

//General RNG
random_device rng;

/*
	Functions
*/

//Race Confirmation
int confirmRace() {
	bool raceConfirmCmd = true;
	string raceDecision;
	cout << "Would you like to play as " << tempPlayerRace << "?" << endl;
	while (raceConfirmCmd == true) {
		cin >> raceDecision;
		if (raceDecision == "yes") {
			cout << "OK! You are a " << tempPlayerRace << "!" << endl;
			raceChoice = true;
			race = tempPlayerRace;
			raceConfirmCmd = false;
		} else if (raceDecision == "no") {
			cout << "Alright, maybe another race will suit you better." << endl;
			raceConfirmCmd = false;
		} else {
			cout << "Command not recognized. Please answer yes or no." << endl;
		}
	}
	return 0;
}

//Height Weight Engine
int heightWeightEngine(int max, int min) {
	random_device heightWeightGenerator;
	uniform_int_distribution<int> dist(min, max);
	return heightWeightGenerator();
}

//Height Weight Combo
int heightWeightAssign(int mxlbs, int mnlbs, int mxin, int mnin) {
	weight = heightWeightEngine(mnlbs, mxlbs);
	heightIn = heightWeightEngine(mnin, mxin);
	heightFt = heightIn / 12;
	heightIn = heightIn % 12;
	heightFt_s = to_string(heightFt);
	heightIn_s = to_string(heightIn);
	height = heightFt_s + " Foot " + heightIn_s;
	return 0;
}

//Statcheck
int statCheck() {
	cout << "Name: " << name << endl;
	cout << "Health: " << hp << endl;
	cout << "Race: " << race << endl;
	cout << "Class: " << playerClass << endl;
	cout << "Height: " << height << endl;
	cout << "Weight: " << weight << endl;
	cout << "Speed: " << speed << " Feet" << endl;
	cout << "Strength: " << str << endl;
	cout << "Constitution: " << cons << endl;
	cout << "Dexterity: " << dex << endl;
	cout << "Gold: " << gold << endl;
	return 0;
}

//Attack
random_device attack;
int attackRoll() {
	if (playerClass == "barbarian") {
		return attack() % 12 + 1;
	}
	else {
		return attack() % 10 + 1;
	}
}

//Console Interface
int midCampaignInterface() {
	string campaignCommand;
	while (turnOnGoing == true) {
		cout << "Campaign: ";
		cin >> campaignCommand;
		if (campaignCommand == "info") {
			statCheck();
		}
		else if (campaignCommand == "move") {
			cout << "You move up " << speed << " feet." << endl;
			turnOnGoing = false;
		}
		else if (campaignCommand == "inventory") {
			cout << "Slot 1: " << inv[0] << endl;
			cout << "Slot 2: " << inv[1] << endl;
			cout << "Slot 3: " << inv[2] << endl;
			cout << "Slot 4: " << inv[3] << endl;
			cout << "Slot 5: " << inv[4] << endl;
			cout << "Slot 6: " << inv[5] << endl;
			cout << "Gold Pouch: " << gold << " Coins" << endl;
		}
		else if (campaignCommand == "quest") {
			cout << "Current Quest: " << quest << endl;
		}
		else {
			cout << "Command not recognized" << endl;
		}
	}
	turnOnGoing = true;
	return 0;
}

//Goblin Attack
int goblinAttack() {
	cout << "The Goblin Swings at You With His Jagged Dagger!" << endl;
	int damageReceived = rng() % 4 + 1;
	hp -= damageReceived;
	cout << "You took " << damageReceived << " damage. You have " << hp << " Health remaining!" << endl;
	if (hp <= 0) {
		cout << "You Died" << endl;
		int enemyHP = 0;
		cout << "You wake up some time later in a dith by the side of the road, all of your gold is gone but you still have your sword." << endl;
		int baseHP = hp;
	}
	return 0;
}


int main() {
	// Intro
	while (outOfGame == true) {
		cout << "Welcome to Dungeons & Dragons: Oversimplified Edition" << endl << "Type Start to Begin Character Creation: ";
		cin >> startCondition;
		if (startCondition == "start") {
			cout << "Starting..." << endl;
			outOfGame = false;
		}
		else if (startCondition == "debug") {
			name = "Developer";
			hp = 30;
			speed = 30;
			race = "human";
			playerClass = "barbarian";
			str = 12;
			cons = 12;
			dex = 12;
			gold = 100;
			lvl = 1;
			goto adventure;

		}
		else if (startCondition == "debug_h") {
			name = "Developer";
			hp = 30;
			speed = 30;
			race = "human";
			playerClass = "barbarian";
			str = 12;
			cons = 12;
			dex = 12;
			gold = 100;
			lvl = 1;
			goto Hardun;

		}
		else {
			cout << "Command not Recognized";
		}
	}

	/*
		+++CHARACTER CREATION+++
	*/

	//Race Selection
	while (raceChoice == false) {
		cout << "There are 4 races in D&D: OSE: Human, Dwarf, Elf, and Halfling " << endl << "Which would you like to play as?" << endl;
		cin >> tempPlayerRace;
		if (tempPlayerRace == "human") {
			cout << "You Have Selected Human!" << endl << "Humans are characterized by ambition, versitility, and diversity. They generally get along with the other races and make up the majority of the world's population. Humans receive a +1 Buff to stats." << endl;
			confirmRace();
		}
		else if (tempPlayerRace == "dwarf") {
			cout << "You Have Selected Dwarf!" << endl << "Dwarves are a short race of humanoids, known for their skill in battle. Dwarves get a +2 Buff to Constitution and a +1 Buff to Strength" << endl;
			confirmRace();
		}
		else if (tempPlayerRace == "elf") {
			cout << "You Have Selected Elf!" << endl << "Elves are a tall, slender, intelligent race, known to live as long as 700 years. Elves recieve a +3 Buff to Dexterity" << endl;
			confirmRace();
		}
		else if (tempPlayerRace == "halfling") {
			cout << "You Have Selected Halfling!" << endl << "Halflings are a small race known for their kindness and positivity. Halflings receive a +2 Buff to Dexterity and a +1 Buff to Constitution" << endl;
			confirmRace();
		}
		else {
			cout << "Race not recognized :( " << endl;
		}
	}

	//Race Stat Synthesis
	if (race == "human") {
		heightWeightAssign(125, 250, 60, 78);
		speed = 30;
	}
	else if (race == "dwarf") {
		heightWeightAssign(140, 165, 48, 60);
		speed = 25;
	}
	else if (race == "elf") {
		heightWeightAssign(100, 140, 60, 82);
		speed = 30;
	}
	else {
		heightWeightAssign(40, 45, 30, 40);
		speed = 25;
	}

	//Class Selection
	cout << "Excellent! You are a " << race << " with a height of " << height << " and a weight of " << weight << " pounds. " << endl;
	while (classChoiceMade == false) {
		cout << "Now its time to choose a class. There are 3 classes in D&D: OSE: Barbarian, Fighter, and Ranger" << endl << "Which would you like to play? ";
		cin >> playerClass;
		if (playerClass == "barbarian" || playerClass == "fighter" || playerClass == "ranger") {
			cout << "Ok, your character will be a " << playerClass << endl;
			classChoiceMade = true;
		}
		else {
			cout << "Sorry, " << playerClass << " is not a playable class." << endl;
		}
	}

	//Ability Rolls
	random_device dice;
	int roll1 = dice() % 15 + 4;
	int roll2 = dice() % 15 + 4;
	int roll3 = dice() % 15 + 4;

	cout << "Your ability rolls are " << roll1 << ", " << roll2 << ", and " << roll3 << ". You have 3 stats in D&D: OSE: Strength, Dexterity, and Constitution." << endl << "Which roll would you like to assign to strength? ";
	cin >> str;
	cout << "Which roll would you like to use for dexterity? ";
	cin >> dex;
	cout << "Which roll would you like to use for constitution? ";
	cin >> cons;

	//Race Based Stat Buffs
	if (race == "human") {
		str += 1;
		dex += 1;
		cons += 1;
	}
	else if (race == "elf") {
		dex += 3;
	}
	else if (race == "dwarf") {
		str += 1;
		cons += 2;
	}
	else {
		dex += 2;
		cons += 1;
	}

	//Hit Poit Calculation (@LVL 1)
	if (playerClass == "barbarian") {
		hp = 12 + cons;
	}
	else {
		hp = 10 + cons;
	}
	int baseHP = hp;

	//Name
	cout << "Alright! Finally, your character needs a name: ";
	cin >> name;
	cout << "Got it, " << name << ". time to begin your adventure!" << endl;

	/*
		In Game
	*/

adventure:
	cout << "You want to go on an adventure, but first you must go into town to collect supplies for your journy." << endl;
	cout << "You set out down the road to town..." << endl;
	int rt1Encounters = 0;
	while (rt1Encounters != 3) {
		midCampaignInterface();
		int randomEncounter = rag() % 14 + 1;
		if (randomEncounter > 0 && randomEncounter <= 4) {
			cout << "A Goblin Raider Emerges from the woods, he eyes your gold pouch and you both draw your weapons!." << endl;
			cout << "You have " << hp << " health remaining!" << endl;
			int enemyHP = rng() % 16 + 5;
			string combatCommand;
			while (enemyHP > 0) {
				cout << "Combat: ";
				cin >> combatCommand;
				if (combatCommand == "attack") {
					int damageDelt = attackRoll();
					cout << "You rolled a " << damageDelt << "!" << endl;
					enemyHP -= damageDelt;
					cout << "Blue-Black Blood Splatters Across your blade as you slash the goblin!" << endl;
					if (enemyHP <= 0) {
						cout << "The Goblin has been slain!" << endl;
						rt1Encounters += 1;
					}
					else { goblinAttack(); }
				}
				else {
					cout << "You fumble around but are unable to do anything!" << endl;
					goblinAttack();
				}
			}
		}
	}
		Hardun : //Hardun
		cout << "You have reached the village of Hardun! As soon as you enter the town's walls, one of the villagers runs up to you." << endl;
		cout << "VILLAGER: Ahah! A hero, I see the goblin blood on your clothes. Some of those goblin raiders came into town and ransacked my shop! If you help me get my stock back, I will replace that sword of yours with a much finer blade. What do you say? Accept my quest?" << endl;
		
		while (questChoice1 == false) {
			cout << "(yes or no) YOU: ";
			cin >> questResponse1;
			if (questResponse1 == "yes") {
				cout << "VILLAGER: Marvelous! Be off then, brave hero. Brin those goblins to heel!" << endl;
				questChoice1 = true;
			}
			else if (questResponse1 == "no") {
				cout << "VILLAGER>: That's a shame. I'll have to find someone else. Someone more heroic." << endl;
				questChoice1 = true;
			}
			else {
				cout << "Sorry, what was that?, I only speak common." << endl;
			}
		}
		midCampaignInterface();

}