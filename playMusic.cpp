#include "playMusic.h"

bool playMusic::keepPlaying = true;

void playMusic::playBackgroundMusics() {
	std::thread playBackground([]() {
		sf::Music music;
		music.setVolume(2);
		music.setLoop(true);

		if (!music.openFromFile("C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\backgroundMusic.wav")) {
			std::cerr << "Error: Could not load background music." << std::endl;
			return;
		}
		music.play();

		while (keepPlaying) {
			sf::sleep(sf::milliseconds(50));
		}

		music.stop();
		});

	playBackground.detach();
}

void playMusic::playSound(const std::string& action) {

	std::thread playSound([action]() {
		sf::SoundBuffer buffer;
		sf::Sound sound;

		std::string filePath;
		if (action == "reload") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\reload.wav";
			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(50);
			sound.play();
			sf::sleep(sf::milliseconds(2000));
		}
		else if (action == "death") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\deathSound.wav";
			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(50);
			sound.play();
			sf::sleep(sf::milliseconds(100));
		}
		else if (action == "boss") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\bossShowsUp.wav";
			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(50);
			sound.play();
			sf::sleep(sf::milliseconds(100));
		}
		else if (action == "bulletHitsEnemy") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\bulletHitsEnemy.wav";
			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(50);
			sound.play();
			sf::sleep(sf::milliseconds(100));
		}
		else if (action == "lever") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\lever.wav";
			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(50);
			sound.play();
			sf::sleep(sf::milliseconds(100));
		}
		else if (action == "pistolShot") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\pop.wav";
			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(50);
			sound.play();
			sf::sleep(sf::milliseconds(100));
		}
		else if (action == "emptyPistolShot") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\emptyGunShot.wav";
			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(50);
			sound.play();
			sf::sleep(sf::milliseconds(100));
		}
		else if (action == "stoneSlide") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\boulderPush.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(15);
			sound.play();
			sf::sleep(sf::milliseconds(2000));
		}
		else if (action == "booHaha") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\booHaha.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(4000));
		}
		else if (action == "bwaap") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\bossShowsUp.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}
		else if (action == "npcDeath") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\bulletHitsEnemy.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}
		else if (action == "plazerDeath") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\deathSound.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}
		else if (action == "NOO") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\NOOO.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}
		else if (action == "gateOpen") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\gateOpen.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}
		else if (action == "reload") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\reload.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}
		else if (action == "checkpoint") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\checkpoint.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}
		else if (action == "health") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\health.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}
		else if (action == "m") {
			filePath = "C:\\Users\\janko\\OneDrive\\Documents\\Visual Studio 2010\\Projects\\CppCMDGame\\CppCMDGame\\sounds\\m.wav";

			buffer.loadFromFile(filePath);
			sound.setBuffer(buffer);
			sound.setVolume(60);
			sound.play();
			sf::sleep(sf::milliseconds(10000));
		}






		/*else {
			std::cerr << "Error: Unknown action: " << action << std::endl;
			return;
		}

		if (!buffer.loadFromFile(filePath)) {
			std::cerr << "Error: Could not load sound file: " << filePath << std::endl;
			return;
		}*/



		});

	playSound.detach();
}
