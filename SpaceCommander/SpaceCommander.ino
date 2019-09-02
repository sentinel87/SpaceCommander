#include<Gamebuino-Meta.h>

uint8_t Astronomy=5;

struct Planet
{
  bool Discovered;
  String Name;
  int posX;
  int posY;
  bool hostile;
  String Enemy;
  int Resource1;
  int Resource2;
  int Resource3;
  bool Owned;
};

Planet System[]={
  {true,"Earth",38,28,false,"Player",0,0,0,true},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false},
  {false,"default",0,0,false,"Cligg",0,0,0,false}
};

struct Technology
{
  int8_t id;
  String techName;
  int8_t imageId;
  int8_t level;
  int resource1Cost;
  int resource2Cost;
  int resource3Cost;
  String describtion;
  String restriction;
  int8_t depTechId;
  int8_t depTechLevel;
};

Technology TechTree[]={
  {1,"Astronomy",0,1,100,100,0,"Increases visibility on the Star Map.","None",0,0},
  {2,"Espionage",0,0,250,50,50,"Unlocks Spy Bots unit and Intelligence building.","Astronomy",1,2},
  {3,"Jet Proplusion",0,0,100,100,100,"Unlocks Fighter unit and increases it's speed.","Astronomy",1,2},
  {4,"Default",0,0,0,0,0,"Default","None",0,0},
  {5,"Default",0,0,0,0,0,"Default","None",0,0},
  {6,"Logistics",0,0,120,120,50,"+ 1 to Star Routes and Colonies.","Astronomy",1,4},
  {7,"Default",0,0,0,0,0,"Default","None",0,0},
  {8,"Default",0,0,0,0,0,"Default","None",0,0},
  {9,"Default",0,0,0,0,0,"Default","None",0,0},
  {10,"Default",0,0,0,0,0,"Default","None",0,0},
  {11,"Default",0,0,0,0,0,"Default","None",0,0},
  {12,"Default",0,0,0,0,0,"Default","None",0,0},
  {13,"Default",0,0,0,0,0,"Default","None",0,0},
  {14,"Default",0,0,0,0,0,"Default","None",0,0},
  {15,"Default",0,0,0,0,0,"Default","None",0,0},
  {16,"Default",0,0,0,0,0,"Default","None",0,0},
  {17,"Default",0,0,0,0,0,"Default","None",0,0},
  {18,"Default",0,0,0,0,0,"Default","None",0,0},
  {19,"Default",0,0,0,0,0,"Default","None",0,0},
  {20,"Default",0,0,0,0,0,"Default","None",0,0}
};

struct Building
{
  int8_t id;
  String bName;
  int8_t imageId;
  int8_t level;
  String describtion;
  int8_t resource1Cost;
  int8_t resource2Cost;
  int8_t resource3Cost;
  String restriction;
  int8_t depTechId;
  int8_t depTechLevel;
  int8_t depBuildingId;
  int8_t depBuildingLevel;
};

Building Colony[]={
  {1,"Power Plant",0,1,"Required to build higher level structures",50,50,50,"None",0,0,0,0},
  {2,"Metal Mine",0,1,"Deliver metal resource.",0,0,0,"None",0,0,1,2},
  {3,"Crystal Mine",0,1,"Deliver crystal resource.",0,0,0,"None",0,0,1,2},
  {4,"Fuel Refinery",0,1,"Deliver fuel resource.",0,0,0,"None",0,0,1,2},
  {5,"None",0,1,"None",0,0,0,"None",0,0},
  {6,"None",0,1,"None",0,0,0,"None",0,0},
  {7,"None",0,1,"None",0,0,0,"None",0,0},
  {8,"None",0,1,"None",0,0,0,"None",0,0},
  {9,"None",0,1,"None",0,0,0,"None",0,0},
  {10,"None",0,1,"None",0,0,0,"None",0,0},
  {11,"None",0,1,"None",0,0,0,"None",0,0},
  {12,"None",0,1,"None",0,0,0,"None",0,0},
  {13,"None",0,1,"None",0,0,0,"None",0,0},
  {14,"None",0,1,"None",0,0,0,"None",0,0},
  {15,"None",0,1,"None",0,0,0,"None",0,0},
};

struct Ship
{
  String type;
  int8_t imageId;
  String describtion;
  int8_t hitPoints;
  int8_t attack;
  int8_t resource1Cost;
  int8_t resource2Cost;
};

Ship Shipyard[]={
  {"Spy Bot",1,"Fragile probe used to scan planets and enemy fleet.",1,1,5,5},
  {"Fighter",2,"Basic unit. Weak, but swarm of fighters is the basic fleet defence.",1,1,5,5},
  {"Fighter",3,"Basic unit. Weak, but swarm of fighters is the basic fleet defence.",1,1,5,5},
  {"Fighter",4,"Basic unit. Weak, but swarm of fighters is the basic fleet defence.",1,1,5,5},
  {"Fighter",5,"Basic unit. Weak, but swarm of fighters is the basic fleet defence.",1,1,5,5},
  {"Fighter",6,"Basic unit. Weak, but swarm of fighters is the basic fleet defence.",1,1,5,5},
  {"Fighter",7,"Basic unit. Weak, but swarm of fighters is the basic fleet defence.",1,1,5,5},
  {"Metal Cargo Transport",8,"Transport metal from colonies.",1,0,500,5},
  {"Crystal Cargo Transport",9,"Transport crystals from colonies.",1,0,500,250},
  {"Tank Cargo Transport",10,"Transport fuel from colonies.",1,0,750,500},
};

struct EnemyGarrison
{
  int8_t SpyBots;
  int8_t Fighters;
  int8_t Interceptor;
  int8_t Frigate;
  int8_t WarCruiser;
  int8_t StarDreadnought;
  int8_t SolarDestroyer;
};

EnemyGarrison Enemy1Garrison[]={
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0}
};

struct Fleet
{
  int8_t Type; //1 - player armada 2 - Colonize 3 - Spy 4 - Enemy
  bool Active;
  int8_t Minutes;
  int8_t Seconds;
  int8_t SpyBots;
  int8_t Fighters;
  int8_t Interceptor;
  int8_t Frigate;
  int8_t WarCruiser;
  int8_t StarDreadnought;
  int8_t SolarDestroyer;
};

Fleet PlayerFleets[]={
  {1,false,0,20,0,0,0,0,0,0,0},
  {2,false,0,30,0,0,0,0,0,0,0},
  {3,false,0,40,0,0,0,0,0,0,0},
  {1,false,0,50,0,0,0,0,0,0,0},
  {1,false,1,20,0,0,0,0,0,0,0}
};

Fleet EnemyFleets[]={
  {4,false,0,20,0,0,0,0,0,0,0},
  {4,false,0,30,0,0,0,0,0,0,0},
  {4,false,0,40,0,0,0,0,0,0,0},
  {4,false,0,50,0,0,0,0,0,0,0},
  {4,false,1,20,0,0,0,0,0,0,0}
};

int8_t SpyBots=0;
int8_t Fighters=0;
int8_t Interceptor=0;
int8_t Frigate=0;
int8_t WarCruiser=0;
int8_t StarDreadnought=0;
int8_t SolarDestroyer=0;
int8_t MetalTransport=0;
int8_t CrystalTransport=0;
int8_t FuelTransport=0;

struct TradeRoute
{
  bool Active;
  String Name;
  int8_t Metal;
  int8_t Crystal;
  int8_t Fuel;
};

TradeRoute PlayerRoutes[]={
  {true,"Artemis",1,1,2},
  {true,"Tau 12",4,2,3},
  {true,"Io",5,5,1},
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
  {false,"",0,0,0},
  {false,"",0,0,0}
};

int8_t ScreenSelection=0;

int PlayerResources[]={2200,2200,2000};

//Timer
int8_t frames=0;
bool timeUpdate=false;

void setup() {
  gb.begin();
}

void loop() {
  while(!gb.update())
  gb.display.clear();
  sendFleet();
  timeCalculations();
  if(ScreenSelection==0)
  {
    ScreenSelection=warRoom(PlayerResources);  
  }
  else if(ScreenSelection==1)
  {
    ScreenSelection=infrastructure(Colony,TechTree,PlayerResources);
  }
  else if(ScreenSelection==2)
  {
    ScreenSelection=research(TechTree,PlayerResources);
  }
  else if(ScreenSelection==3)
  {
    ScreenSelection=starMap(TechTree[0].level,System);
  }
  else if(ScreenSelection==6)
  {
    ScreenSelection=starRoutes(TechTree[5].level,PlayerRoutes);
  }
  else if(ScreenSelection==8)
  {
    ScreenSelection=playerFleets(PlayerFleets);
  }
  else if(ScreenSelection==9)
  {
    ScreenSelection=enemyFleets(EnemyFleets);
  }
}

void sendFleet()
{
  if(gb.buttons.pressed(BUTTON_MENU))
  {
    EnemyFleets[0].Active=true;
    EnemyFleets[0].Seconds=10;
  }
}

void timeCalculations()
{
  if(frames==25)// every second tick update game mechanics
  {
    frames=0;
    updateResources();
    updateFleets();
  }
  else
  {
    frames++;
  }
}

void updateFleets()
{
  for(int i=0;i<5;i++)
  {
    if(EnemyFleets[i].Active==true)
    {
      updateEnemyFleetTime(i);
    }
    if(PlayerFleets[i].Active==true)
    {
      updatePlayerFleetTime(i);
    }
  }
}

void updateEnemyFleetTime(int index)
{
  if(EnemyFleets[index].Seconds==0 && EnemyFleets[index].Minutes>0)
  {
    EnemyFleets[index].Seconds=59;
    EnemyFleets[index].Minutes--;
  }
  else if(EnemyFleets[index].Seconds==0 && EnemyFleets[index].Minutes==0)
  {
    EnemyFleets[index].Seconds=0;
    EnemyFleets[index].Active=false; 
  }
  else
  {
    EnemyFleets[index].Seconds--;
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
    PlayerFleets[index].Seconds=0;
    PlayerFleets[index].Active=false; 
  }
  else
  {
    PlayerFleets[index].Seconds--;
  }
}

void updateResources()
{
  PlayerResources[0]+=1;
  PlayerResources[1]+=1;
  PlayerResources[2]+=1;
}

