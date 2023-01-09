#include "Level.h"

void Level::buildLevelOnePlatforms() {
    platforms.emplace_back(0, 969, winWidth, winHeight);
    platforms.emplace_back(0, 0, winWidth, 83);
    platforms.emplace_back(0, 243, 321, 65);
    platforms.emplace_back(0, 0, 80, 619);
    platforms.emplace_back(483, 243, 241, 65);
    platforms.emplace_back(0, 486, 404, 65);
    platforms.emplace_back(562, 486, 164, 82);
    platforms.emplace_back(1042, 486, 242, 86);
    platforms.emplace_back(1278, 564, 85, 160);
    platforms.emplace_back(1361, 646, 81, 82);
    platforms.emplace_back(1520, 727, 83, 73);
    platforms.emplace_back(1682, 809, winWidth, 85);
    platforms.emplace_back(1600, 890, winWidth, winHeight);
    platforms.emplace_back(1361, 327, 240, 80);
    platforms.emplace_back(1530, 407, winWidth, 80);
    platforms.emplace_back(1608, 486, winWidth, 80);
    platforms.emplace_back(722, 882, 240, winHeight);
    platforms.emplace_back(802, 807, 82, winHeight);
    platforms.emplace_back(641, 62, 82, 262);
    platforms.emplace_back(1763, 0, winWidth, winHeight);
    platforms.emplace_back(0, 573, 14, 440);
    platforms.emplace_back(659, 566, 429, 65);

    deathZone.emplace_back(720, 543, 325, 8);
}

void Level::buildLevelTwoPlatforms() {
   platforms.emplace_back(0, 919, 573, 86);
   platforms.emplace_back(1114, 919, 689, 86);
   platforms.emplace_back(163, 837, 83, 80);
   platforms.emplace_back(243, 752, 83, 80);
   platforms.emplace_back(321, 670, 83, 80);
   platforms.emplace_back(402, 587, 83, 80);
   platforms.emplace_back(487, 502, 83, 421);
   platforms.emplace_back(487, 502, 230, 80);
   platforms.emplace_back(640, 415, 83, 92);
   platforms.emplace_back(1116, 667, 158, 82);
   platforms.emplace_back(1363, 172, 435, 86);
   platforms.emplace_back(0, 252, 312, 82); //(for alan) clound on left
   platforms.emplace_back(1116, 667, 83, 254);
   platforms.emplace_back(1278, 749, 83, 80);
   platforms.emplace_back(1360, 835, 83, 86); //(for alan) cloud on right
   platforms.emplace_back(1518, 583, 243, 86);
   platforms.emplace_back(1438, 501, 84, 102);
   platforms.emplace_back(1757, 501, 43, 102);
   platforms.emplace_back(0, 0, 6, winHeight);
   platforms.emplace_back(1794, 0, 6, winHeight);

   deathZone.emplace_back(570, 1006, 552, 8);
}

void Level::buildLevelThreePlatforms() {
    platforms.emplace_back(0, 961, 1800, 52);
    platforms.emplace_back(2, 560, 381, 101); 
    platforms.emplace_back(1417, 560, 381, 101); 
    platforms.emplace_back(1, 158, 61, 415); 
    platforms.emplace_back(1738, 158, 61, 821); 
    platforms.emplace_back(2, 158, 1800, 62); 
    platforms.emplace_back(0, 0, 6, winHeight); 
}

void Level::destroyLevel() {
    platforms.clear();
}

void Level::draw(sf::RenderWindow& window) {
    checkLever();
    
    setDoor(113, 88);
    setLever(1644.f, 336.f);
    for (int i = 0; i < platforms.size(); i++) {
        platforms[i].setColour(sf::Color::White);
        window.draw(platforms[i].getShape());
    }

    window.draw(deathZone[0].getShape());
    window.draw(lever);
    window.draw(door);
}

void Level::setFileName(std::string fileName) {
    leverFileName = fileName;
}

void Level::setLever(float posx, float posy) {
    checkLever();
    lever.setScale(0.35, 0.35);
    lever.setPosition(posx, posy);
    leverTexture.loadFromFile(leverFileName);
    lever.setTexture(leverTexture);
}

void Level::checkLever() {
    if (leverPulled) {
        leverFileName = "assets/leverLeft.png";
        doorFileName = "assets/doorOpen.png";
    } else {
        leverFileName = "assets/leverRight.png";
        doorFileName = "assets/doorClosed.png";
    }
}

void Level::setDoor(float posx, float posy) {
    door.setScale(0.80, 0.80);
    door.setPosition(posx, posy);
    doorTexture.loadFromFile(doorFileName);
    door.setTexture(doorTexture);
}

void Level::setBackground(std::string fileName) {
    
    backgroundTexture.loadFromFile(fileName);
    background.setTexture(backgroundTexture);
    background.setPosition(0, 0);
}
