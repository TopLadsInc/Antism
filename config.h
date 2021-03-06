#pragma once
#include <fstream>
#include <string>
#include <cctype>
class Config
{
public:
	Config();
	~Config();
	static void loadConfig(std::fstream *f);
	static void loadConfig();
	static void writeConfig();
	static void loadDefaultValues();
	static void loadDefaultColonySize();
	static int applicationWidth;
	static int applicationHeight;
	static bool vsync;
	static float PheremoneDecay;
	static float smellStrength;
	static float FoodSmellRadius;
	static int MaxFrames;
	static int SimSpeed;
	static float AlphaParam;
	static float BetaParam;
	static int ColonySize;
	static float MaxSmell;
	static float MaxPheromone;
	static int FoodCapacity;
	static int QueenCapacity;

	static bool isFloatNumber(const std::string& string) {
		std::string::const_iterator it = string.begin();
		bool decimalPoint = false;
		int minSize = 0;
		if (string.size()>0 && (string[0] == '-' || string[0] == '+')) {
			it++;
			minSize++;
		}
		while (it != string.end()) {
			if (*it == '.') {
				if (!decimalPoint) decimalPoint = true;
				else break;
			}
			else if (!std::isdigit(*it) && ((*it != 'f') || it + 1 != string.end() || !decimalPoint)) {
				break;
			}
			++it;
		}
		return string.size()>minSize && it == string.end();
	}
};

