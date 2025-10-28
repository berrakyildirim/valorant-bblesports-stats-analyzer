# VALORANT - BBL Esports Stats Analyzer (C++)

This project is a simple console-based statistics analyzer for BBL Esports match data.
It reads match records from a CSV file and allows the user to view various statistics interactively via a text-based menu.

## Features

The program reads data from a tab-separated CSV file (data.csv) with the following columns:

### Column	Description
id	Player ID
nickname	In-game nickname
name	Player’s first name
surname	Player’s last name
versus	Opponent team name
map	Map played
date	Match date (DD.MM.YYYY)
kill	Number of kills
death	Number of deaths
assist	Number of assists
first kill	Number of first kills
first death	Number of first deaths

Note:
The CSV data used in this project is based on real match statistics taken from vlr.gg
, one of the most reputable sources for professional Valorant esports data.

## Menu Options

When you run the program, you’ll see a menu with the following options:

### Option	Description
1	View statistics for a specific player (search by nickname)
2	View all matches played against a specific team
3	Show the player with the highest number of kills
4	Show the player with the best KD difference (kills - deaths)
5	Show all matches played on a specific date
0	Exit the program

## Setup Instructions
### 1. Prepare Your CSV File

Save your match data as data.csv (tab-separated).
Example snippet:

id	nickname	name	surname	versus	map	date	kill	death	assist	first kill	first death
1	Sociablee	Volkan	Yonal	GX	Ascent	30.09.2025	11	14	0	2	2
2	Jamppi	Elias	Olkkonen	GX	Ascent	30.09.2026	6	12	7	0	1
3	MAGNUM	Martin	Penkov	GX	Ascent	30.09.2027	8	14	4	1	2

### 2. Compile the Code

Make sure you have a C++ compiler installed (for example, g++).
Then run:

g++ main.cpp -o stats
./stats

### 3. Run the Program

You’ll see a menu like this:

--- BBL Esports Stats Menu ---
1. View player stats
2. View matches against a team
3. Show player with most kills
4. Show player with best KD difference
5. Show matches by date
0. Exit


Then simply follow the on-screen prompts.

## Example Queries

### Example 1 – View Player Stats

Enter player nickname: Sociablee
--- Sociablee (Volkan Yonal) ---
Versus: GX | Map: Ascent | Date: 30.09.2025
Kills: 11 | Deaths: 14 | Assists: 0 | First Kills: 2 | First Deaths: 2


### Example 2 – Find Top Killer

Top fragger: Elite (20 kills)

## Possible Improvements

Add average KDA per map

Support comma-separated CSV files

Integrate an SQLite database

Export summaries as text, JSON, or CSV

## Author

Match data sourced from vlr.gg
