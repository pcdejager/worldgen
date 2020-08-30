// gen-console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "Races.h"
#include "Logger.h"
#include "WorldBuilder.h"

int main()
{
    LoggerPtr logger = Logger::GetLogger();
    logger->Log(L"World Builder started");
    logger->Log(L"Loading configuration");
    RacesPtr races = Races::GetRaces();
    logger->Log(L"Configuration loaded");
    
    WorldBuilder builder;
    builder.Run();
         
    logger->Log(L"Exit...");
    int i;
    std::cin >> i;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


/*


Character
- Age (birth date, death date, isalive?)
- parents (mother, father)
- children
- Sex/Gender (can father? can bear? sex[not binary]? attaction[not binary]?)
- Height (?? Race have impact)
- Weight (?? Race have impact)

- Attribs (strength[body, mind], IQ, charisma)

- Race (?? adjustments to certain attribs and other parts)


*/