#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Class representing a player's match statistics
class Player {
public:
    int id;
    string nickname;
    string name;
    string surname;
    string versus;
    string map;
    string date;
    int kill;
    int death;
    int assist;
    int firstKill;
    int firstDeath;

    Player(int id, string nickname, string name, string surname, string versus, string map,
           string date, int kill, int death, int assist, int firstKill, int firstDeath) {
        this->id = id;
        this->nickname = nickname;
        this->name = name;
        this->surname = surname;
        this->versus = versus;
        this->map = map;
        this->date = date;
        this->kill = kill;
        this->death = death;
        this->assist = assist;
        this->firstKill = firstKill;
        this->firstDeath = firstDeath;
    }
};

// Read the CSV file and return a vector of Player objects
vector<Player> readCSV(const string& filename) {
    vector<Player> players;
    ifstream file(filename);
    string line;

    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> fields;

        while (getline(ss, token, '\t')) { // tab-separated
            fields.push_back(token);
        }

        if (fields.size() < 12) continue; // skip incomplete lines

        players.push_back(Player(
            stoi(fields[0]), fields[1], fields[2], fields[3], fields[4],
            fields[5], fields[6], stoi(fields[7]), stoi(fields[8]),
            stoi(fields[9]), stoi(fields[10]), stoi(fields[11])
        ));
    }
    file.close();
    return players;
}

// Show stats for a specific player
void showPlayerStats(const vector<Player>& players, const string& nickname) {
    bool found = false;
    for (const auto& p : players) {
        if (p.nickname == nickname) {
            found = true;
            cout << "\n--- " << p.nickname << " (" << p.name << " " << p.surname << ") ---\n";
            cout << "Versus: " << p.versus << " | Map: " << p.map << " | Date: " << p.date << "\n";
            cout << "Kills: " << p.kill << " | Deaths: " << p.death << " | Assists: " << p.assist
                 << " | First Kills: " << p.firstKill << " | First Deaths: " << p.firstDeath << "\n";
        }
    }
    if (!found) cout << "Player not found.\n";
}

// Show matches against a given team
void showTeamMatches(const vector<Player>& players, const string& team) {
    bool found = false;
    for (const auto& p : players) {
        if (p.versus == team) {
            found = true;
            cout << p.nickname << " | K: " << p.kill << " | D: " << p.death
                 << " | A: " << p.assist << " | Map: " << p.map
                 << " | Date: " << p.date << "\n";
        }
    }
    if (!found) cout << "No matches found against that team.\n";
}

// Show the player with the most kills
void showTopKiller(const vector<Player>& players) {
    int maxKill = -1;
    string topPlayer;
    for (const auto& p : players) {
        if (p.kill > maxKill) {
            maxKill = p.kill;
            topPlayer = p.nickname;
        }
    }
    cout << "Top fragger: " << topPlayer << " (" << maxKill << " kills)\n";
}

// Show the player with the best KD (kill - death difference)
void showBestKD(const vector<Player>& players) {
    int bestDiff = -9999;
    string bestPlayer;
    for (const auto& p : players) {
        int diff = p.kill - p.death;
        if (diff > bestDiff) {
            bestDiff = diff;
            bestPlayer = p.nickname;
        }
    }
    cout << "Best KD difference: " << bestPlayer << " (Kill-Death = " << bestDiff << ")\n";
}

// Show matches by date
void showMatchesByDate(const vector<Player>& players, const string& date) {
    bool found = false;
    for (const auto& p : players) {
        if (p.date == date) {
            found = true;
            cout << p.nickname << " | " << p.versus << " | K: " << p.kill
                 << " | D: " << p.death << " | A: " << p.assist
                 << " | Map: " << p.map << "\n";
        }
    }
    if (!found) cout << "No matches found for that date.\n";
}

// Main menu
int main() {
    vector<Player> players = readCSV("data.csv");

    int choice;
    do {
        cout << "\n--- BBL Esports Stats Menu ---\n";
        cout << "1. View player stats\n";
        cout << "2. View matches against a team\n";
        cout << "3. Show player with most kills\n";
        cout << "4. Show player with best KD difference\n";
        cout << "5. Show matches by date\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer

        if (choice == 1) {
            string nick;
            cout << "Enter player nickname: ";
            getline(cin, nick);
            showPlayerStats(players, nick);
        } 
        else if (choice == 2) {
            string team;
            cout << "Enter team name (e.g., GX): ";
            getline(cin, team);
            showTeamMatches(players, team);
        } 
        else if (choice == 3) {
            showTopKiller(players);
        } 
        else if (choice == 4) {
            showBestKD(players);
        } 
        else if (choice == 5) {
            string date;
            cout << "Enter date (e.g., 30.09.2025): ";
            getline(cin, date);
            showMatchesByDate(players, date);
        }

    } while (choice != 0);

    cout << "Program exited.\n";
    return 0;
}
