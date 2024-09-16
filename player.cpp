// Alex Beer
// University of Alaska Fairbanks
// CS311 Data Structures and Algorithms
// September 4, 2024
////////////////////////////////
// A source file for implementing class Player and its methods.

#include "player.hpp"
#include <cassert>
#include <string>

// Default constructor
Player::Player() : _realName("UNKNOWN"), _username("UNKNOWN"), _gamesPlayed(0) {}

// Parameterized constructor
Player::Player(const std::string& realName, const std::string& username, int gamesPlayed)
    : _realName(realName), _username(username), _gamesPlayed(gamesPlayed) {
    assert(gamesPlayed >= 0);
}

// Getters
std::string Player::getRealName() const {
    return _realName;
}

std::string Player::getUsername() const {
    return _username;
}

int Player::getGames() const {
    return _gamesPlayed;
}

// Setters
void Player::setRealName(const std::string& realName) {
    _realName = realName;
}

void Player::setUsername(const std::string& username) {
    _username = username;
}

void Player::setGames(int gamesPlayed) {
    assert(gamesPlayed >= 0);
    _gamesPlayed = gamesPlayed;
}

// Method to check if the player is inactive
bool Player::inactive() const {
    return _gamesPlayed == 0;
}

// String representation of player's information
std::string Player::toString() const {
    return _realName + " (" + _username + "): " + std::to_string(_gamesPlayed);
}

// Operator overloads
bool Player::operator==(const Player& rhs) const {
    return _realName == rhs._realName && _username == rhs._username && _gamesPlayed == rhs._gamesPlayed;
}

bool Player::operator!=(const Player& rhs) const {
    return !(*this == rhs);
}

// Pre-increment
Player& Player::operator++() {
    ++_gamesPlayed;
    return *this;
}

// Post-increment
Player Player::operator++(int) {
    Player temp = *this;
    ++(*this);
    return temp;
}

// Pre-decrement
Player& Player::operator--() {
    if (_gamesPlayed > 0) {
        --_gamesPlayed;
    }
    return *this;
}

// Post-decrement
Player Player::operator--(int) {
    Player temp = *this;
    --(*this);
    return temp;
}

// Overloading output operator for Player class
std::ostream & operator<<(std::ostream & str, const Player & obj) {
    return str << obj.toString();
}
