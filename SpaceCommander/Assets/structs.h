#pragma once

struct Planet
{
  bool Discovered;
  String Name;
  int posX;
  int posY;
  bool Hostile;
  int Affilation; //0 - None, 1 - First Enemy, 2 - Second Enemy
  int Resource1;
  int Resource2;
  int Resource3;
  bool Owned; //If planet is colonized
  bool TradeRoute;  //If trade route to planet is set
  int GarrisonIndex;  //If planet is hostile
  bool Status; //If planet was classified by spy bot
  bool ActiveMission; //If planet is currently targeted by player fleet mission 
};

struct Technology
{
  int id;
  String techName;
  int level;
  int resource1Cost;
  int resource2Cost;
  int resource3Cost;
  String describtion;
  String restriction;
  int depTechId;
  int depTechLevel;
  int maxLevel;
};

struct Building
{
  int id;
  String bName;
  int level;
  String describtion;
  int resource1Cost;
  int resource2Cost;
  int resource3Cost;
  int depTechId;
  int depTechLevel;
  int depBuildingId;
  int depBuildingLevel;
  int maxLevel;
};

struct Ship
{
  String type;
  int imageId;
  String describtion;
  int resource1Cost;
  int resource2Cost;
};

struct EnemyGarrison
{
  int planetIndex;
  int Fighters;
  int Interceptors;
  int Frigates;
  int WarCruisers;
  int StarDreadnoughts;
  int SolarDestroyers;
};

struct Fleet
{
  int Type; //1 - player armada 2 - Colonize 3 - Spy 4 - Enemy 5 - Return 6 - Raid 7 - Intercept
  bool Active;
  int8_t Minutes;
  int8_t Seconds;
  int SpyBots;
  int Colonizers;
  int Fighters;
  int Interceptors;
  int Frigates;
  int WarCruisers;
  int StarDreadnoughts;
  int SolarDestroyers;
  int Stalkers;
  int Leviatans;
  int Missles;
  String DestinationName;
  bool Visible;
  int InterceptionId;
};

struct TradeRoute
{
  bool Active;
  String Name;
  int8_t Metal;
  int8_t Crystal;
  int8_t Fuel;
};

struct Report
{
  String PlanetName;
  uint16_t Type;
  uint16_t Fighters;
  uint16_t Interceptors;
  uint16_t Frigates;
  uint16_t WarCruisers;
  uint16_t StarDreadnoughts;
  uint16_t SolarDestroyers;
  uint16_t Resource1;
  uint16_t Resource2;
  uint16_t Resource3;
};

struct BattleResult
{
  uint16_t PlFighters;
  uint16_t PlFightersLost;
  uint16_t EnFighters;
  uint16_t EnFightersLost;
  uint16_t PlInterceptors;
  uint16_t PlInterceptorsLost;
  uint16_t EnInterceptors;
  uint16_t EnInterceptorsLost;
  uint16_t PlFrigates;
  uint16_t PlFrigatesLost;
  uint16_t EnFrigates;
  uint16_t EnFrigatesLost;
  uint16_t PlWarCruisers;
  uint16_t PlWarCruisersLost;
  uint16_t EnWarCruisers;
  uint16_t EnWarCruisersLost;
  uint16_t PlStarDreadnoughts;
  uint16_t PlStarDreadnoughtsLost;
  uint16_t EnStarDreadnoughts;
  uint16_t EnStarDreadnoughtsLost;
  uint16_t PlSolarDestroyers;
  uint16_t PlSolarDestroyersLost;
  uint16_t EnSolarDestroyers;
  uint16_t EnSolarDestroyersLost;
  uint16_t Winner;
};
