#pragma once
#include <SFML/Audio.hpp>
#include <thread>
#include <iostream>

using namespace std;

class playMusic
{
public:
	static bool keepPlaying;
	playMusic() = delete;
	static void playBackgroundMusics();
	static void playSound(const std::string& action);

};

