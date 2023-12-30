#include<Gamebuino-Meta.h>

String DebugData=""; 
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

Planet SelectedPlanet={true,"UEF Colony",38,28,false,0,0,0,0,true,false,-1,true,false};

Planet System[]={
  {true,"UEF Colony",38,28,false,0,0,0,0,true,false,-1,true,false},
  {false,"Sheez Prime",76,28,false,0,3,2,2,false,false,-1,false,false},
  {false,"Cligg Prime",0,28,true,1,0,0,0,false,false,0,false,false},
  {false,"Ganimedes",33,35,false,0,1,2,0,false,false,-1,false,false},//Poor resources (3)
  {false,"Raven",33,24,false,0,1,1,1,true,false,-1,false,false},
  {false,"Novaria",36,26,false,0,1,0,2,false,false,-1,false,false},
  {false,"Kanton",27,9,false,0,2,0,3,false,false,-1,false,false},//Medium resources(6)
  {false,"Armag",14,22,false,0,1,4,0,false,false,-1,false,false},
  {false,"Syrius",55,11,false,0,3,2,0,false,false,-1,false,false},
  {false,"Tibann",26,19,false,0,1,3,1,false,false,-1,false,false},
  {false,"San Da",48,17,false,0,0,5,0,false,false,-1,false,false},
  {false,"Tolka",63,23,false,0,1,1,3,false,false,-1,false,false},
  {false,"Eden",15,30,false,0,0,5,0,false,false,-1,false,false},
  {false,"Brantal V",24,32,false,0,5,0,0,false,false,-1,false,false},
  {false,"Dan 11",54,32,false,0,0,0,5,false,false,-1,false,false},
  {false,"Arti Ka",15,41,false,0,0,2,3,false,false,-1,false,false},
  {false,"Tyra",27,45,false,0,4,1,0,false,false,-1,false,false},
  {false,"Galant",51,48,false,0,2,1,2,false,false,-1,false,false},
  {false,"Saxa",60,40,false,0,0,5,0,false,false,-1,false,false},
  {false,"Tau 14",8,3,false,0,5,1,1,false,false,-1,false,false},//Rich resources (19)
  {false,"Cassia",14,3,false,0,2,2,3,false,false,-1,false,false},
  {false,"Nova 5",34,2,false,0,1,5,1,false,false,-1,false,false},
  {false,"Andromeda",44,6,false,0,1,1,5,false,false,-1,false,false},
  {false,"Arnval",71,7,false,0,1,2,4,false,false,-1,false,false},
  {false,"Duna",5,15,false,0,4,2,1,false,false,-1,false,false},
  {false,"Janya",7,43,false,0,5,1,1,false,false,-1,false,false},
  {false,"Rea 8",73,37,false,0,3,2,2,false,false,-1,false,false},
  {false,"IO",66,54,false,0,2,3,2,false,false,-1,false,false},
  {false,"Taka Van",33,55,false,0,3,4,0,false,false,-1,false,false},
  {false,"Europa",3,55,false,0,4,3,0,false,false,-1,false,false}
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

Technology TechTree[]={
  {1,"Astronomy",2,25,30,20,"Increases visibilityon the Star Map.","None",0,0,39},
  {2,"Espionage",0,200,75,75,"Unlock  Intelligenceand Spy Bots.","Astronomy",1,2,16},
  {3,"Jet Proplusion",0,100,100,100,"Unlock Fighters and increases their     speed.","Astronomy",1,2,19},
  {4,"Fleet Tactics",0,100,25,10,"Needed to upgrade   shipyard and build  high level ships.","Astronomy",1,5,16},
  {5,"Radiolocation",0,80,110,50,"Unlock Radar and    increases visibilityrange.","Espionage",2,2,15},
  {6,"Logistics",0,120,120,50,"+ 1 to Star Routes  and Colonies. UnlockTransports.","Astronomy",1,5,12},
  {7,"Aerodynamics",0,150,120,150,"Unlock Interceptors and increases their speed.","Jet Proplusion",3,4,15},
  {8,"Cloaking",0,250,190,150,"Unlock  Stalkers.   Stalker steal 1/lvl enemy fighter and   interceptor.","Radiolocation",5,1,11},
  {9,"EMP Weapon",0,300,400,300,"Unlock EMP Launcher and EMP missles.    Increases missle    power.","Radiolocation",5,6,10},
  {10,"Statics",0,200,350,50,"Unlock Warehouse andincreases it's      capacity.","Logistics",6,2,11},
  {11,"Economy",0,400,400,200,"Unlock and improve  Market.","Logistics",6,2,8},
  {12,"Impulse Engine",0,50,250,200,"Unlock Frigates and increases their     speed.","Aerodynamics",7,4,11},
  {13,"Shielding",0,350,400,100,"Unlock Planetary    Defence System and  increases firepower.","Fleet Tactics",4,1,14},
  {14,"Mind Control",0,350,500,350,"Unlock  Leviatans.  Leviatan steal 1/lvlenemy Frigate.","Cloaking",8,4,5},
  {15,"Hyperdrive",0,100,500,400,"Unlock War Cruisers and increases their speed.","Impulse Engine",12,2,10},
  {16,"Fusion Reaction",0,450,350,250,"Unlock and improve  Transformer.","Fleet Tactics",4,5,10},
  {17,"Ship Weapons",0,125,300,75,"Final level unlock  Star Dreadnought.","Shielding",13,2,10},
  {18,"Flight Control",0,350,200,250,"Unlock and improve  Logistic Centre.","Statics",10,2,10},
  {19,"Gravity Weapon",0,800,800,800,"Final level of this technology unlock   Solar Destructor.","Hyperdrive",15,1,9},
  {20,"Composite Armor",0,1000,1000,1000,"Reduce War Cruiser, Star Dreadnought andSolar Destructor    costs.","Ship Weapons",17,5,5}
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

Building Colony[]={
  {1,"Power Plant",1,"Required to build   higher level        mines.",200,190,150,0,0,0,0,15},
  {2,"Metal Mine",1,"Extract metal       resource.",210,195,25,0,0,1,2,15},
  {3,"Crystal Mine",1,"Extract crystal     resource.",200,230,50,0,0,1,2,15},
  {4,"Fuel Refinery",0,"Deliver fuel        resource.",200,185,65,0,0,1,2,14},
  {5,"Intelligence",0,"Reveals more intel  in hostile reports.",210,185,10,2,1,0,0,12},
  {6,"Radar",0,"Detects enemy fleets+1 visibility / lvl.",185,185,25,5,1,0,0,15},
  {7,"Shipyard",0,"Required to build   colony ships.",350,350,275,4,1,0,0,11},
  {8,"Research Lab",0,"Unlock additional   technology / lvl.",175,175,75,0,0,0,0,20},
  {9,"Defence System",0,"Provides additional firepower for colonydefence / lvl.",210,250,75,13,1,0,0,14},
  {10,"Factory",0,"Reduces metal and   crystal cost of     buildings.",300,220,60,0,0,0,0,10},
  {11,"Warehouse",0,"Stores resources    when losing battle. +200 for each       resource / lvl.",300,300,50,10,1,0,0,10},
  {12,"Transformer",0,"Converts one        resource to another.",350,300,550,16,1,0,0,10},
  {13,"Logistic Centre",0,"Increases resource  transport from traderoutes.",400,200,300,18,1,0,0,10},
  {14,"Market",0,"Exachange fuel for  resources and ships.",220,220,150,11,1,0,0,8},
  {15,"EMP Launcher",0,"Fires EMP Missles +1 / lvl into enemy   fleets.",300,300,200,9,1,0,0,10}
};

struct Ship
{
  String type;
  int imageId;
  String describtion;
  int resource1Cost;
  int resource2Cost;
};

Ship Shipyard[]={
  {"Fighter",1,"Swarm of Fighters isbasic fleet defence.",50,15},
  {"Interceptor",2,"Ship designed to    hunt down Fighters.",100,40},
  {"Frigate",3,"Light armored ship. Bonus against       Fighters.",270,150},
  {"War Cruiser",4,"First line attack   ship. Bonus against Interceptors.",400,230},
  {"Star Dreadnought",5,"Heavy armored ship  used to transport   entire fleet.",550,300},
  {"Solar Destructor",6,"Ship designed to    destroy entire      planet.",4000,4000},
  {"Spy Bot",7,"Fragile probe used  to scan planets and enemy fleets.",15,10},
  {"Colonizer",8,"Sets colony on the  planet.",900,900},
  {"Metal Transport",9,"Transport metal fromcolonies.",350,35},
  {"Crystal Transport",10,"Transport crystals  from colonies.",400,150},
  {"Fuel Transport",11,"Transport fuel from colonies.",300,200},
  {"Stalker",12,"Steal enemy Fightersand Interceptors.",300,300},
  {"Leviatan",13,"Steal enemy         Frigates.",700,700},
  {"EMP Missle",14,"Reduce enemy fleet  ships during        intercept missions.",150,200}
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

EnemyGarrison Enemy1Garrison[]={
  {-1,0,0,0,0,0,0}, //Capital
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0}
};

EnemyGarrison Enemy2Garrison[]={
  {-1,0,0,0,0,0,0}, //Capital
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0}
};

struct Fleet
{
  int Type; //1 - player armada 2 - Colonize 3 - Spy 4 - Enemy 5 - Return
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
  String DestinationName;
  bool Visible;
};

Fleet PlayerFleets[]={
  {0,false,0,0,0,0,0,0,0,0,0,0,0,0,"",true},
  {0,false,0,0,0,0,0,0,0,0,0,0,0,0,"",true},
  {0,false,0,0,0,0,0,0,0,0,0,0,0,0,"",true},
  {0,false,0,0,0,0,0,0,0,0,0,0,0,0,"",true}
};

Fleet EnemyFleets[]={
  {4,false,0,0,0,0,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,0,0,0,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,0,0,0,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,0,0,0,0,0,0,0,0,0,0,0,"",false}
};

Fleet CustomFleet={0,false,0,0,0,0,0,0,0,0,0,0,0,0,"",false};
Fleet CustomEnemyFleet={4,false,0,0,0,0,0,0,0,0,0,0,0,0,"",false};

int FleetFuelCost=0;

int PlayerShips[]={
  0, //Fighter
  0, //Interceptor
  0, //Frigate
  0, //War Cruiser
  0, //Star Dreadnought
  0, //Solar Destroyer
  0, //Spy Bot
  0, //Colonizer
  0, //Metal Transport
  0, //Crystal Transport
  0, //Fuel Transport
  0, //Stalkers
  0, //Leviatans
  0 //EMP Missles
};

struct TradeRoute
{
  bool Active;
  String Name;
  int8_t Metal;
  int8_t Crystal;
  int8_t Fuel;
};

TradeRoute PlayerRoutes[]={
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0}
};

TradeRoute SelectedRoute={false,"None",0,0,0};

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

Report IntelligenceReports[]={
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0}
};

int8_t ScreenSelection=0;

int PlayerResources[]={0,0,0};

//Timer
int8_t frames=0;
bool timeUpdate=false;
int8_t visibilitySeconds=0;
int8_t visibilityMinutes=0;

//Attack
bool fight=false;

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

BattleResult BtResult={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,false};

//Fleet Selection
bool flSelection=false;
bool flRaidSelection=false;
bool spyMission=false;
bool spyMissionFleet=false;
bool attackMission=false;
bool colonizeMission=false;
bool routesMission=false;
bool raidMission=false;

int BattleExperience=18;

//Menu variables

bool IsMainMenu=true;
bool IsOptionMenu=false;
bool IsFameHall=false;
bool GameOver=false;
bool Victory=false;
bool GameStarted=false;

//Game options

int EnemyCount = 1;
int TempEnemyCount = 1;
String Difficulty = "NORMAL";
String TempDiff = "NORMAL";
bool SaveExist = false;
int ProgressPoints = 0;
int ProgressPointsLimit = 120;
int TempProgressPointsLimit = 120;
int EnemyColonies = 0;
int CliggColonies = 0;
int SheezColonies = 0;
int ScoreBoard[] = {0,0,0,0,0};
int Score = 0;

//Enemy Timer
int timeToAttack=160;//4 minutes interval
bool attackUnderway=false;
int8_t attackCounter=0;

const SaveDefault savefileDefaults[] = {
  { 0, SAVETYPE_BLOB,{.ptr="1123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-1110 "} ,349},
  { 1, SAVETYPE_BLOB,{.ptr="0101021001010101010101010101011101010125 "},81},
  { 2, SAVETYPE_BLOB,{.ptr="020313000000000000000000000000000000000000000000000000000000000000000000000000000000121120 "},91},
  { 3, SAVETYPE_BLOB,{.ptr="-10100200043510025000103330000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 "},157}, //Enemy1 Garrison
  { 4, SAVETYPE_BLOB,{.ptr="000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 "},157}, //Enemy2 Garrison
  { 5, SAVETYPE_BLOB,{.ptr="0000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000NAME**********0 "},245},
  { 6, SAVETYPE_BLOB,{.ptr="0000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000NAME**********0 "},245},
  { 7, SAVETYPE_BLOB,{.ptr="00000000000000000000000000000000000000000000000000000000 "},57},
  { 8, SAVETYPE_BLOB,{.ptr="0NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********000 "},217},
  { 9, SAVETYPE_BLOB,{.ptr="NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000 "},211},
  { 10, SAVETYPE_BLOB,{.ptr="00000000000000000NORMAL********00000000000000000 "},49},
  { 11,SAVETYPE_INT,0,0 },
  { 12,SAVETYPE_INT,0,0 },
  { 13,SAVETYPE_INT,0,0 },
  { 14,SAVETYPE_INT,0,0 },
  { 15,SAVETYPE_INT,0,0 },
  { 16,SAVETYPE_INT,0,0 } //Check if save exist
};

void setup() {
  gb.begin();
  gb.save.config(savefileDefaults);
  ScoreBoard[0]=gb.save.get(11);
  ScoreBoard[1]=gb.save.get(12);
  ScoreBoard[2]=gb.save.get(13);
  ScoreBoard[3]=gb.save.get(14);
  ScoreBoard[4]=gb.save.get(15);
  int check=gb.save.get(16);
  if(check==1)
  {
    SaveExist=true;
  }
}

void loop() {
  while(!gb.update())
  gb.display.clear();
  gb.lights.clear();
  if(IsMainMenu==true)  //MAIN MENU
  {
    int8_t choice=mainMenu();
    if(choice==0)
    {
      prepareNewGame();
      resetWarRoomMarkers();
      resetMapMarkers();
      IsMainMenu=false;
    }
    else if(choice==1)
    {
      IsMainMenu=false;
    }
    else if(choice==2) //loadGame
    {
      prepareNewGame();
      resetWarRoomMarkers();
      resetMapMarkers();
      loadGame();
      IsMainMenu=false;
    }
    else if(choice==3)
    {
      IsMainMenu=false;
      IsOptionMenu=true;
    }
    else if(choice==4)
    {
      IsMainMenu=false;
      IsFameHall=true;
    }
  }
  else if(IsOptionMenu) //OPTIONS MENU
  {
    bool accepted=optionsMenu();
    if(accepted==true)
    {
      IsOptionMenu=false;
      IsMainMenu=true;
    }
  }
  else if(IsFameHall) //HALL OF FAME
  {
    bool accepted=hallOfFame();
    if(accepted==true)
    {
      IsFameHall=false;
      IsMainMenu=true;
    }
  }
  else //GAME
  {
    if(fight==true) //stop game to see fight results
    {
      bool resolved=battleResults();
      if(resolved==true)
      {
        fight=false;
      }
    }
    else if(GameOver==true)
    {
      bool resolved=gameOverInfo(false);
      if(resolved==true)  //return to main menu
      {
        IsMainMenu=true;
        GameStarted=false;
        GameOver=false;
        setMenuSelection(0);
        bool HighScore=compareAndUpdateScore();
        if(HighScore)
        {
          gb.save.set(11,ScoreBoard[0]);
          gb.save.set(12,ScoreBoard[1]);
          gb.save.set(13,ScoreBoard[2]);
          gb.save.set(14,ScoreBoard[3]);
          gb.save.set(15,ScoreBoard[4]);
        }
      }
    }
    else if(Victory==true)
    {
      bool resolved=gameOverInfo(true);
      if(resolved==true)  //return to main menu
      {
        IsMainMenu=true;
        GameStarted=false;
        GameOver=false;
        setMenuSelection(0);
        bool HighScore=compareAndUpdateScore();
        if(HighScore)
        {
          gb.save.set(11,ScoreBoard[0]);
          gb.save.set(12,ScoreBoard[1]);
          gb.save.set(13,ScoreBoard[2]);
          gb.save.set(14,ScoreBoard[3]);
          gb.save.set(15,ScoreBoard[4]);
        }
      }
    }
    else if(flSelection==true)// set fleet to attack
    {
      int selected=playerFleetSelection();
      if(selected==2)
      {
        setFleetParameters();
        attackMission=true;
        flSelection=false;
      }
      else if(selected==0)
      {
        flSelection=false;
      }
    }
    else if(flRaidSelection==true)
    {
      int selected=playerFleetSelectionRaid();
      if(selected==2)
      {
        setFleetParameters();
        raidMission=true;
        flRaidSelection=false;
      }
      else if(selected==0)
      {
        flRaidSelection=false;
      }
    }
    else if(attackMission==true)
    {
      int8_t selected=sendAttack();
      if(selected==1)
      {
        lockPlanet();
        attackMission=false;
      }
      else if(selected==2)
      {
        attackMission=false;
      }
    }
    else if(raidMission==true)
    {
      int8_t selected=sendRaid();
      if(selected==1)
      {
        lockPlanet();
        raidMission=false;
      }
      else if(selected==2)
      {
        raidMission=false; 
      }
    }
    else if(spyMission==true)// set spy to scout
    {
      int8_t selected=sendSpy();
      if(selected==1)
      {
        lockPlanet();
        spyMission=false;
      }
      else if(selected==2)
      {
        spyMission=false;
      }
    }
    else if(spyMissionFleet==true)// set spy to scout enemy fleet
    {
      int8_t selected=sendSpy();
      if(selected==1)
      {
        spyMissionFleet=false;
      }
      else if(selected==2)
      {
        spyMissionFleet=false;
      }
    }
    else if(colonizeMission==true)// set colonizer
    {
      int8_t selected=sendColonizer();
      if(selected==1)
      {
        lockPlanet();
        colonizeMission=false;
      }
      else if(selected==2)
      {
        colonizeMission=false;
      }
    }
    else if(routesMission==true)// set trade route
    {
      bool selected=setRoute();
      if(selected==true)
      {
        routesMission=false;
      }
    }
    else
    {
      timeCalculations();
      if(ScreenSelection==0)
      {
        ScreenSelection=warRoom(PlayerResources);
        if(ScreenSelection==9)
        {
          resetTransformer();  
        }
      }
      else if(ScreenSelection==2)
      {
        ScreenSelection=infrastructure();
      }
      else if(ScreenSelection==4)
      {
        ScreenSelection=research();
      }
      else if(ScreenSelection==6)
      {
        ScreenSelection=starMap(TechTree[0].level);
      }
      else if(ScreenSelection==8)
      {
        ScreenSelection=shipyard(TechTree[7].level);
      }
      else if(ScreenSelection==10)
      {
        ScreenSelection=intelligence();
      }
      else if(ScreenSelection==11)
      {
        ScreenSelection=starRoutes(TechTree[5].level);
      }
      else if(ScreenSelection==12) //ECONOMY STATS
      {
        ScreenSelection=market();
      }
      else if (ScreenSelection == 13) //PAUSE
      {
        ScreenSelection = 0;
        TempDiff = Difficulty;
        TempEnemyCount = EnemyCount;
        TempProgressPointsLimit = ProgressPointsLimit;
        IsMainMenu = true;
      }
      else if(ScreenSelection==15) //DEBUG
      {
        ScreenSelection=debug();
      }
      else if(ScreenSelection==1)
      {
        ScreenSelection=playerFleets();
      }
      else if(ScreenSelection==3)
      {
        ScreenSelection=enemyFleets();
      }
      else if(ScreenSelection==5)
      {
        ScreenSelection=playerFleetStats();
      }
      else if(ScreenSelection==7)
      {
        ScreenSelection=scoutReports();
      }
      else if(ScreenSelection==9)
      {
        ScreenSelection=transformer();
      }
      else if(ScreenSelection==20)
      {
        ScreenSelection=6; //RETURN TO STAR MAP AFTER FLEET SELECTION
        flSelection=true;
      }
      else if(ScreenSelection==21)
      {
        ScreenSelection=6; //RETURN TO STAR MAP AFTER FLEET SELECTION
        spyMission=true;
      }
      else if(ScreenSelection==22)
      {
        ScreenSelection=6; //RETURN TO STAR MAP AFTER FLEET SELECTION
        colonizeMission=true;
      }
      else if(ScreenSelection==23)
      {
        ScreenSelection=6; //RETURN TO STAR MAP AFTER FLEET SELECTION
        routesMission=true;
      }
      else if(ScreenSelection==25)
      {
        ScreenSelection=3; //RETURN TO ENEMY FLEETS AFTER FLEET SELECTION
        spyMissionFleet=true;
      }
      else if(ScreenSelection==26)
      {
        ScreenSelection=6; //RETURN TO STAR MAP AFTER FLEET SELECTION;
        flRaidSelection=true;
      }
    }
  }
}

bool compareAndUpdateScore()
{
  bool isScoreQualified=false;
  int temp=0;
  int temp2=0;
  int index=0;

  for(int i=0;i<5;i++)
  {
    if(Score>ScoreBoard[i])
    {
       temp=ScoreBoard[i];
       ScoreBoard[i]=Score;
       index=i;
       isScoreQualified=true;
       break;
    } 
  }

  if(!isScoreQualified)
  {
    return false;
  }

  for(int i=index+1;i<5;i++)
  {
    temp2=ScoreBoard[i];
    ScoreBoard[i]=temp;
    temp=temp2;
  }
  return isScoreQualified;
}

void timeCalculations()
{
  if(frames==25)// every second tick update game mechanics
  {
    frames=0;
    updateResources();
    PlayerResources[0]=9999;
    PlayerResources[1]=9999;
    PlayerResources[2]=9999;
    updateVisibilityDistance();
    enemyAttackTimer();
    updateFleets();
  }
  else
  {
    frames++;
  }
}

void updateVisibilityDistance()
{
  int base = 10 + (Colony[5].level * 13);
  if (base > 59)
  {
    visibilityMinutes = base / 60;
    visibilitySeconds = base - (visibilityMinutes * 60);
  }
  else
  {
    visibilityMinutes = 0;
    visibilitySeconds = base;
  }
}

//----------------------------------Fleets-----------------------

void updateFleets()
{
  for (int i = 0; i < 4; i++)
  {
    if (EnemyFleets[i].Active == true)
    {
      updateEnemyFleetTime(i);
      bool isFleetInRange = checkTimeWithVisibilityRange(EnemyFleets[i].Minutes, EnemyFleets[i].Seconds);
      if (isFleetInRange == true && EnemyFleets[i].Active == true && EnemyFleets[i].Visible == false)
      {
        EnemyFleets[i].Visible = true;
        gb.lights.fill(RED);
        gb.gui.popup("INCOMING ATTACK!", 50);
      }
    }
    if (PlayerFleets[i].Active == true)
    {
      updatePlayerFleetTime(i);
    }
  }
}

bool checkTimeWithVisibilityRange(int minutes, int seconds)
{
  if (minutes < visibilityMinutes)
  {
    return true;
  }
  if (minutes == visibilityMinutes)
  {
    if (seconds <= visibilitySeconds)
    {
      return true;
    }
  }
  return false;
}

void updateEnemyFleetTime(int index)
{
  if (EnemyFleets[index].Seconds == 0 && EnemyFleets[index].Minutes > 0)
  {
    EnemyFleets[index].Seconds = 59;
    EnemyFleets[index].Minutes--;
  }
  else if (EnemyFleets[index].Seconds == 0 && EnemyFleets[index].Minutes == 0)
  {
    EnemyFleets[index].Seconds = 0;
    EnemyFleets[index].Active = false;
    EnemyFleets[index].Visible = false;
    int8_t winner=spaceBattle(index, -1, false, 0);
    if(winner == 2)//battle lost
    {
      gb.lights.fill(RED);
      PlayerShips[6] = 0;
      PlayerShips[7] = 0;
      PlayerShips[8] = 0;
      PlayerShips[9] = 0;
      PlayerShips[10] = 0;
      PlayerShips[11] = 0;
      PlayerShips[12] = 0;
      PlayerShips[13] = 0;
      
      bool richBounty = resourcePillage();
      resetTransformerAfterAttack();
      int EnemyProgressPoints = 3;
      if (Difficulty == "NORMAL" || Difficulty == "HARD")
      {
        EnemyProgressPoints=4;
      }
      
      if (ProgressPoints < ProgressPointsLimit)
      {
        if (richBounty == true)
        {
          ProgressPoints += (2 * EnemyProgressPoints); //ultimate weapon progress
        }
        else
        {
          ProgressPoints += EnemyProgressPoints; //ultimate weapon progress
        }
        if (ProgressPoints > ProgressPointsLimit)
        {
          ProgressPoints = ProgressPointsLimit;
        }
        garrisonUpgrade(Enemy1Garrison);
        if (EnemyCount = 2)
        {
          garrisonUpgrade(Enemy2Garrison);
        }
      }
      if (EnemyFleets[index].SolarDestroyers > 0)  //If Attack was successfull and ultimate weapon survived, the game is over;
      {
        GameOver = true;
        countFinalScore(false);
      }
    }
    else
    {
      gb.lights.fill(GREEN);
      BattleExperience++;
      if (BattleExperience > 9999)
      {
        BattleExperience = 9999;
      }
      if (Difficulty == "EASY")
      {
        Score += 8;
      }
      else if (Difficulty == "HARD")
      {
        Score += 30;
      }
      else
      {
        Score += 15; 
      }
    }
    EnemyFleets[index].Fighters = 0;
    EnemyFleets[index].Interceptors = 0;
    EnemyFleets[index].Frigates = 0;
    EnemyFleets[index].WarCruisers = 0;
    EnemyFleets[index].StarDreadnoughts = 0;
    EnemyFleets[index].SolarDestroyers = 0;
    fight = true;
    enemyFleetsCheck(); 
  }
  else
  {
    EnemyFleets[index].Seconds--;
  }
}

void garrisonUpgrade(EnemyGarrison garrison[6])
{
  for (int i=0; i<6; i++)
  {
    if (garrison[i].planetIndex != -1)
    {
      garrison[i].Fighters += 10;
      garrison[i].Interceptors += 5;
      if (Difficulty == "NORMAL" || Difficulty == "HARD")
      {
          garrison[i].Frigates += 1;
      }
    }
  }
}

void updatePlayerFleetTime(int index)
{
  if(PlayerFleets[index].Seconds==0 && PlayerFleets[index].Minutes>0)
  {
    PlayerFleets[index].Seconds=59;
    PlayerFleets[index].Minutes--;
  }
  else if(PlayerFleets[index].Seconds==0 && PlayerFleets[index].Minutes==0)
  {
    Fleet Cleanup={0,false,0,0,0,0,0,0,0,0,0,0,0,0,""};
    PlayerFleets[index].Seconds=0;
    PlayerFleets[index].Active=false;
    if(PlayerFleets[index].Type==1)
    {
      gb.lights.fill(GREEN);
      attackPlanet(index);
    }
    else if(PlayerFleets[index].Type==2)
    {
      gb.lights.fill(BLUE);
      colonizePlanet(PlayerFleets[index]);
      PlayerFleets[index]=Cleanup;
    }
    else if(PlayerFleets[index].Type==3)
    {
      gb.lights.fill(YELLOW);
      scoutMission(PlayerFleets[index]);
      PlayerFleets[index]=Cleanup;
    }
    else if(PlayerFleets[index].Type==5)
    {
      gb.lights.fill(GREEN);
      fleetReturns(PlayerFleets[index]);
      PlayerFleets[index]=Cleanup;
    }
    else if(PlayerFleets[index].Type==6)
    {
      gb.lights.fill(LIGHTGREEN);
      raidPlanet(index);
    }
  }
  else
  {
    PlayerFleets[index].Seconds--;
  }
}

void lockPlanet()
{
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==SelectedPlanet.Name)
    {
      System[i].ActiveMission=true;
      SelectedPlanet.ActiveMission=true;
      break;
    }
  }
}

//Fleet reached destination (Actions) 
void scoutMission(Fleet fleet)
{
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==fleet.DestinationName)
    {
      System[i].Status=true;
      System[i].ActiveMission=false;
      if(System[i].Hostile==true)
      {
        int gIdx=System[i].GarrisonIndex;
        if(gIdx>=0 && gIdx<6)
        {
          Report Hostile={System[i].Name,1,Enemy1Garrison[gIdx].Fighters,Enemy1Garrison[gIdx].Interceptors,Enemy1Garrison[gIdx].Frigates,Enemy1Garrison[gIdx].WarCruisers,Enemy1Garrison[gIdx].StarDreadnoughts,Enemy1Garrison[gIdx].SolarDestroyers,0,0,0};
          generateScoutReport(Hostile);
        }
      }
      else
      {
        Report Mining={System[i].Name,2,0,0,0,0,0,0,System[i].Resource1,System[i].Resource2,System[i].Resource3};
        generateScoutReport(Mining);
      }
      break;
    }
  }
}

void colonizePlanet(Fleet fleet)
{
  for (int i = 0; i < 30; i++)
  {
    if (System[i].Name == fleet.DestinationName)
    {
      System[i].ActiveMission = false;
      System[i].Owned = true;
      break;
    }
  }
  gb.gui.popup("PLANET COLONIZED!", 50);
}

void raidPlanet(int index)
{
  if(PlayerFleets[index].Stalkers>0)
  {
    int ModFighters = TechTree[7].level;
    int ModInterceptors = 0;
    if(TechTree[7].level>5)
    {
      ModInterceptors = TechTree[7].level - 5;
    }
    PlayerFleets[index].Fighters=ModFighters*PlayerFleets[index].Stalkers;
    PlayerFleets[index].Interceptors=ModInterceptors*PlayerFleets[index].Stalkers;
  }
  if(PlayerFleets[index].Leviatans>0)
  {
    int ModFrigates = TechTree[13].level;
    PlayerFleets[index].Frigates=ModFrigates*PlayerFleets[index].Leviatans;
  }
  
  Report Raid={PlayerFleets[index].DestinationName,3,PlayerFleets[index].Fighters,PlayerFleets[index].Interceptors,PlayerFleets[index].Frigates,0,0,0,0,0,0};
  generateScoutReport(Raid);

  for(int i=0;i<30;i++)
  {
    if(System[i].Name==PlayerFleets[index].DestinationName)
    {
      System[i].ActiveMission=false;
      break;
    }
  }
  
  setFleetReturnParameters(index);
  PlayerFleets[index].Active=true;
}

void attackPlanet(int index)
{
  String planet=PlayerFleets[index].DestinationName;
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==planet)
    {
      int idx=System[i].GarrisonIndex;
      if(idx!=-1)
      {
        int8_t winner=spaceBattle(idx,index,true,System[i].Affilation);
        fight=true;
        if(winner==1) //if player wins move fleet back
        {
          BattleExperience+=2;
          setFleetReturnParameters(index);
          PlayerFleets[index].Active=true;
          if(idx==0)//Capital planet defeated
          {
            if(PlayerFleets[index].SolarDestroyers>0)//At least one Solar Destroyer survived 
            {
              Score+=100;
              if(EnemyCount == 1) //Victory with 1 enemy
              {
                Victory=true;
                countFinalScore(true);
              }
              else
              {
                if(System[i].Affilation == 1)
                {
                  colonyDefeated(Enemy1Garrison[idx],i);
                }
                else if(System[i].Affilation == 2)
                {
                  colonyDefeated(Enemy2Garrison[idx],i);
                }

                if(Enemy1Garrison[0].planetIndex == -1 && Enemy2Garrison[0].planetIndex == -1) //Victory with 2 enemies
                {
                  Victory=true;
                  countFinalScore(true);
                }
                else
                {
                  rewardForPlayer();
                }
              }
            }
            else
            {
              rewardForPlayer();
            }
          }
          else //Colony defeated
          {
            if(System[i].Affilation == 1)
            {
              colonyDefeated(Enemy1Garrison[idx],i);
            }
            else
            {
              colonyDefeated(Enemy2Garrison[idx],i);
            }
            checkAndSetTotalColoniesCount();
            Score+=50;
          }
        }
        System[i].ActiveMission=false;
      }
      break;
    }
  }
}

void colonyDefeated(EnemyGarrison& garrison, int systemIdx)
{
  garrison.planetIndex=-1;
  System[systemIdx].Hostile=false;
  System[systemIdx].GarrisonIndex=-1;
  rewardForPlayer();
}

void rewardForPlayer()
{
  PlayerResources[0]+=1000; //reward
  if(PlayerResources[0]>9999)
  {
    PlayerResources[0]=9999;
  }
  PlayerResources[1]+=1000;
  if(PlayerResources[1]>9999)
  {
    PlayerResources[1]=9999;
  }
  PlayerResources[2]+=1000;
  if(PlayerResources[2]>9999)
  {
    PlayerResources[2]=9999;
  }
}

void fleetReturns(Fleet fleet)
{
  PlayerShips[0] += fleet.Fighters;
  if (PlayerShips[0] > 9999)
  {
    PlayerShips[0] = 9999;
  }
  PlayerShips[1] += fleet.Interceptors;
  if (PlayerShips[1] > 9999)
  {
    PlayerShips[1] = 9999;
  }
  PlayerShips[2] += fleet.Frigates;
  if (PlayerShips[2] > 9999)
  {
    PlayerShips[2] = 9999;
  }
  PlayerShips[3] += fleet.WarCruisers;
  if (PlayerShips[3] > 9999)
  {
    PlayerShips[3] = 9999;
  }
  PlayerShips[4] += fleet.StarDreadnoughts;
  if (PlayerShips[4] > 9999)
  {
    PlayerShips[4] = 9999;
  }
  PlayerShips[5] += fleet.SolarDestroyers;
  if (PlayerShips[5] > 9999)
  {
    PlayerShips[5] = 9999;
  }
  PlayerShips[11] += fleet.Stalkers;
  if (PlayerShips[11] > 9999)
  {
    PlayerShips[11] = 9999;
  }
  PlayerShips[12] += fleet.Leviatans;
  if(PlayerShips[12] > 9999)
  {
    PlayerShips[12] = 9999;
  }
  gb.gui.popup("FLEET HAS RETURNED!", 50);
}
//--------Resources----------------------------

void updateResources()
{
  PlayerResources[0] += 3 + Colony[1].level*3; //Metal Mine
  PlayerResources[1] += 3 + Colony[2].level*3; //Crystal Mine
  PlayerResources[2] += 2 + Colony[3].level*2; //Fuel Refinery

  for(int i=0;i<12;i++)
  {
    PlayerResources[0]+=PlayerRoutes[i].Metal + Colony[12].level;
    PlayerResources[1]+=PlayerRoutes[i].Crystal + Colony[12].level;
    PlayerResources[2]+=PlayerRoutes[i].Fuel + Colony[12].level;
  }
  if(PlayerResources[0]>9999)
  {
    PlayerResources[0]=9999;
  }
  if(PlayerResources[1]>9999)
  {
    PlayerResources[1]=9999;
  }
  if(PlayerResources[2]>9999)
  {
    PlayerResources[2]=9999;
  }
}

bool resourcePillage()
{
  bool result=false;
  int reserve=Colony[10].level*200; //Warehouse protection
  int totalPillaged=0;
  for(int i=0;i<3;i++)
  {
    if(PlayerResources[i]>=reserve)
    {
      int pillage=PlayerResources[i]-reserve;
      totalPillaged+=pillage;
      PlayerResources[i]=reserve;
    }
  }
  if(totalPillaged>=1000)
  {
    result=true;
  }
  return result;
}

//--------Enemy Attacks------------------------
void enemyFleetsCheck() //check if all attacks are completed and reset prepare timer
{
  bool allClear=true;
  for(int i=0;i<4;i++)
  {
    if(EnemyFleets[i].Active!=false)
    {
      allClear=false;
      break;
    }
  }
  if(allClear==true)
  {
    attackCounter=0;
    attackUnderway=false;
    setBaseTimeToAttack();
  }
}

void enemyAttackTimer()
{
  if(timeToAttack==-1) //at least two (four) fleets are attacking
  {
    return;
  }
  if(timeToAttack>0)  //"Peace" time
  {
    timeToAttack--;  
  }
  else
  {
    if(!attackUnderway)
    {
      int chance=random(0, 5);
      if(chance==0 || chance==2 || chance==4)
      {
        int idx=getEnemyFleetSlot();
        if(idx!=-1)
        {
          attackCounter++;
          prepareEnemyFleet(idx);
          EnemyFleets[idx]=CustomEnemyFleet;
          attackUnderway=true;
          setTimeToAnotherAttack();
        }
        else
        {
          timeToAttack = -1; //stop attacks
        }
      }
    }
    else
    {
      int chance=random(0, 6);
      if(chance==1 || chance==3)
      {
        int idx=getEnemyFleetSlot();
        if(idx!=-1)
        {
          prepareEnemyFleet(idx);
          EnemyFleets[idx]=CustomEnemyFleet;
          attackCounter++;
          if(EnemyCount == 2)
          {
            checkAndSetTotalColoniesCount();
            if(EnemyColonies > 5 && attackCounter < 4)
            {
              setTimeToAnotherAttack();
            }
            else
            {
              timeToAttack = -1; //stop attacks
            }
          }
          else
          {
            timeToAttack = -1; //stop attacks
          }
        }
        else
        {
          timeToAttack = -1; //stop attacks
        }
      }
    }
  }
}

void setBaseTimeToAttack()
{
  timeToAttack = 160;
  if (Difficulty == "NORMAL")
  {
    timeToAttack = 140;
  }
  else if (Difficulty == "HARD")
  {
    timeToAttack = 110;
  }
}

void setTimeToAnotherAttack()
{
  timeToAttack = 125;
  if (Difficulty == "NORMAL")
  {
    timeToAttack = 105;
  }
  else if (Difficulty == "HARD")
  {
    timeToAttack = 85;
  }
}

void prepareEnemyFleet(int fleetIdx)
{
  CustomEnemyFleet = setEnemyFleet(fleetIdx);
  int Speed = 0; //in seconds per 1 unit 
  int distance = 37;
  
  //Calculate speed
  if (CustomEnemyFleet.Fighters > 0)
  {
    Speed = 9;
  }
  if (CustomEnemyFleet.Interceptors > 0)
  {
    Speed = 11;
  }
  if (CustomEnemyFleet.Frigates > 0)
  {
    Speed = 13;
  }
  if (CustomEnemyFleet.WarCruisers > 0)
  {
    if (Speed > 7 || Speed == 0)
    {
      Speed = 7; 
    }
  }
  if (CustomEnemyFleet.StarDreadnoughts > 0)
  {
    if (Speed > 6 || Speed == 0)
    {
      Speed = 6; 
    }
  }
  //Calculate minutes and seconds (1 unit - speed)
  int totalSeconds = distance * Speed;
  if (totalSeconds > 59) //at least 1 minute
  {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds - (minutes * 60);
    CustomEnemyFleet.Seconds = seconds;
    CustomEnemyFleet.Minutes = minutes;
  }
  else
  {
    CustomEnemyFleet.Seconds = totalSeconds;
  }
}

int getEnemyFleetSlot()
{
  int result = -1;
  for (int i = 0; i < 4; i++)
  {
    if (EnemyFleets[i].Active == false)
    {
      result = i;
      break;
    }
  }
  return result;
}

Fleet setEnemyFleet(int fleetIdx)
{
  String fleetName = "FLEET " + (String)(fleetIdx + 1);
  Fleet EnemyArmada = {4,true,0,0,0,0,0,0,0,0,0,0,0,0,fleetName,false};
  int modifier = 2;
  int base = 4;

  if (Difficulty == "NORMAL")
  {
    modifier = 3;
  }
  else if (Difficulty == "HARD")
  {
    modifier = 4;
  }

  if (PlayerShips[0] == 0)
  {
    EnemyArmada.Fighters = 10 + random(0, 20);
  }
  else
  {
    EnemyArmada.Fighters = 10 + ((PlayerShips[0] * modifier) / base) + random(0, 20);
  }
  if (EnemyArmada.Fighters > 9999)
  {
    EnemyArmada.Fighters = 9999;
  }
  
  if (TechTree[2].level >= 4)//Jet Proplusion
  {
    if (PlayerShips[1] == 0)
    {
      EnemyArmada.Interceptors = 5 + random(0, 15);
    }
    else
    {
      EnemyArmada.Interceptors = 5 + ((PlayerShips[1] * modifier) / base) + random(0, 15);
    }
    if (EnemyArmada.Interceptors > 9999)
    {
      EnemyArmada.Interceptors = 9999;
    }
  }
  
  if (TechTree[6].level >= 4)//Aerodynamics
  {
    if (PlayerShips[2] == 0)
    {
      EnemyArmada.Frigates = 3 + random(0, 5);
    }
    else
    {
      EnemyArmada.Frigates = 3 + ((PlayerShips[2] * modifier) / base) + random(0, 5);
    }
    if (EnemyArmada.Frigates > 9999)
    {
      EnemyArmada.Frigates = 3 + PlayerShips[2];
    }
  }
  
  if (TechTree[11].level >= 2)//Impulse Engine
  {
    if (PlayerShips[3] == 0)
    {
      EnemyArmada.WarCruisers = 2 + random(0, 2);
    }
    else
    {
      EnemyArmada.WarCruisers = 2 + ((PlayerShips[3] * modifier) / base) + random(0, 2);
    }
    if (EnemyArmada.WarCruisers > 9999)
    {
      EnemyArmada.WarCruisers = 9999;
    }
  }
  
  if (TechTree[16].level >= 8)//Ship Weapons
  {
    if (PlayerShips[4] == 0)
    {
      EnemyArmada.StarDreadnoughts = 1 + random(0, 2);
    }
    else
    {
      EnemyArmada.StarDreadnoughts = 1 + ((PlayerShips[4] * modifier) / base) + random(0, 2);
    }
    if (EnemyArmada.StarDreadnoughts > 9999)
    {
      EnemyArmada.StarDreadnoughts = 9999;
    }
  }
  
  if(ProgressPoints==ProgressPointsLimit) //ultimate weapon discovered
  {
    EnemyArmada.SolarDestroyers = 2 + random(0, 4); //solar destroyers 
  }
  
  return EnemyArmada;
}

//---------------------------Score--------------------------

void countFinalScore(bool victory)
{
  if(victory==true)
  {
    if(Difficulty=="EASY")
    {
      Score+=250;
    }
    else if(Difficulty=="NORMAL")
    {
      Score+=500;
    }
    else
    {
      Score+=750;
    }
  }
  for(int i=0;i<12;i++)
  {
    if(PlayerRoutes[i].Active==true)
    {
      Score+=2;
      Score+=PlayerRoutes[i].Metal;
      Score+=PlayerRoutes[i].Crystal;
      Score+=PlayerRoutes[i].Fuel;
    }
  }
  for(int i=0;i<15;i++)
  {
    Score+=TechTree[i].level;
  }
  for(int i=0;i<13;i++)
  {
    Score+=Colony[i].level;
  }
  Score+=((ProgressPointsLimit-ProgressPoints)*3);
}

void checkAndSetTotalColoniesCount()
{
  CliggColonies = countColonies(Enemy1Garrison);
  SheezColonies = countColonies(Enemy2Garrison);
  EnemyColonies = CliggColonies + SheezColonies;
}

int countColonies(EnemyGarrison garrison[6])
{
  int total = 0;
  for(int i = 1; i < 6; i++)
  {
    if(garrison[i].planetIndex != -1)
    {
      total++;
    }
  }
  return total;
}
