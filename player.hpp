// Alex Beer
// University of Alaska Fairbanks
// CS311 Data Structures and Algorithms
// September 4, 2024
////////////////////////////////
// A header file for declaring class Player and its methods.

#ifndef FILE_PLAYER_HPP
#define FILE_PLAYER_HPP

#include <string>
#include <ostream>

class Player {
    friend std::ostream & operator<<(std::ostream & str, const Player & obj);

private:
    std::string _realName;   // Real name of the player
    std::string _username;   // Username of the player
    int _gamesPlayed;        // Number of games played

public:
    Player();  // Default constructor
    Player(const std::string& realName, const std::string& username, int gamesPlayed); // Parameterized constructor

    // Getters
    std::string getRealName() const;
    std::string getUsername() const;
    int getGames() const;

    // Setters
    void setRealName(const std::string& realName);
    void setUsername(const std::string& username);
    void setGames(int gamesPlayed);

    // Method to check if player is inactive
    bool inactive() const;

    // String representation of player's information
    std::string toString() const;

    // Operator overloads
    bool operator==(const Player& rhs) const;
    bool operator!=(const Player& rhs) const;

    // Pre/post-increment and decrement operators
    Player& operator++();    // Pre-increment
    Player operator++(int);  // Post-increment
    Player& operator--();    // Pre-decrement
    Player operator--(int);  // Post-decrement
};

#endif
