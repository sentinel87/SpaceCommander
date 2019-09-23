#include<Gamebuino-Meta.h>

uint8_t Astronomy=20;

struct Planet
{
  bool Discovered;
  String Name;
  int8_t posX;
  int8_t posY;
  bool Hostile;
  String Enemy;
  int Resource1;
  int Resource2;
  int Resource3;
  bool Owned;
  bool TradeRoute;
  int GarrisonIndex;  //If planet is hostile
  bool Status; //If planet was classified by spy bot
};

Planet SelectedPlanet={true,"Earth",38,28,false,"Player",0,0,0,true,false,-1,true};

Planet System[]={
  {true,"Earth",38,28,false,"Player",0,0,0,true,false,-1,true},
  {false,"Sheeza Prime",76,28,true,"Shezz",0,0,0,false,false,-1,false},
  {false,"Cligga Prime",0,28,true,"Cligg",0,0,0,false,false,0,true},
  {false,"Tau 14",8,3,false,"None",0,0,0,false,false,-1,false},
  {false,"Cassia",14,3,false,"None",0,0,0,false,false,-1,false},
  {false,"Kanton",27,9,false,"None",0,0,0,false,false,-1,false},
  {false,"Nova 5",34,2,false,"None",0,0,0,false,false,-1,false},
  {false,"Andromeda",44,6,false,"None",0,0,0,false,false,-1,false},
  {false,"Syrius",55,11,false,"None",0,0,0,false,false,-1,false},
  {false,"Arnval",71,7,false,"None",0,0,0,false,false,-1,false},
  {false,"Duna",5,15,false,"None",0,0,0,false,false,-1,false},
  {false,"Armag",14,22,false,"None",0,0,0,false,false,-1,false},
  {false,"Tibann",26,19,false,"None",0,0,0,false,false,-1,false},
  {false,"San Da",48,17,false,"None",0,0,0,false,false,-1,false},
  {false,"Tolka",63,23,false,"None",0,0,0,false,false,-1,false},
  {false,"Raven",33,24,false,"None",0,0,0,false,false,-1,false},
  {false,"Novaria",36,26,false,"None",0,0,0,false,false,-1,false},
  {false,"Eden",15,30,false,"None",0,0,0,false,false,-1,false},
  {false,"Brantal V",24,32,false,"None",0,0,0,false,false,-1,false},
  {false,"Ganimedes",33,35,false,"None",0,0,0,false,false,-1,false},
  {false,"Dan 11",54,32,false,"None",0,0,0,false,false,-1,false},
  {false,"Janya",7,43,false,"None",0,0,0,false,false,-1,false},
  {false,"Arti Ka",15,41,false,"None",0,0,0,false,false,-1,false},
  {false,"Tyra",27,45,false,"None",0,0,0,false,false,-1,false},
  {false,"Galant",51,48,false,"None",0,0,0,false,false,-1,false},
  {false,"Saxa",60,40,false,"None",0,0,0,false,false,-1,false},
  {false,"Rea 8",73,37,false,"None",0,0,0,false,false,-1,false},
  {false,"IO",66,54,false,"None",0,0,0,false,false,-1,false},
  {false,"Taka Van",33,55,false,"None",0,0,0,false,false,-1,false},
  {false,"Europa",3,55,false,"None",0,0,0,false,false,-1,false}
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
  {"Colonizer",11,"Set colony on the planet.",5,0,1000,1000}
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
  {2,100,50,25,10,5,0}, //Capital
  {0,0,0,0,0,0,0},
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
  int SpyBots;
  int Colonizers;
  int Fighters;
  int Interceptors;
  int Frigates;
  int WarCruisers;
  int StarDreadnoughts;
  int SolarDestroyers;
  String DestinationName;
};

Fleet PlayerFleets[]={
  {1,false,0,20,0,0,0,0,0,0,0,0,""},
  {2,false,0,30,0,0,0,0,0,0,0,0,""},
  {3,false,0,40,0,0,0,0,0,0,0,0,""},
  {1,false,0,50,0,0,0,0,0,0,0,0,""},
  {1,false,1,20,0,0,0,0,0,0,0,0,""}
};

Fleet EnemyFleets[]={
  {4,false,0,20,0,0,0,0,0,0,0,0,""},
  {4,false,0,30,0,0,0,0,0,0,0,0,""},
  {4,false,0,40,0,0,0,0,0,0,0,0,""},
  {4,false,0,50,0,0,0,0,0,0,0,0,""},
  {4,false,1,20,0,0,0,0,0,0,0,0,""}
};

Fleet CustomFleet={0,false,0,0,0,0,0,0,0,0,0,0,""};

int FleetFuelCost=0;

int PlayerShips[]={
  1000, //Fighter
  500, //Interceptor
  250, //Frigate
  125, //War Cruiser
  60, //Star Dreadnought
  1, //Solar Destroyer
  3, //Spy Bot
  1, //Colonizer
  0, //Metal Transport
  0, //Crystal Transport
  0  //Fuel Transport
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

struct Report
{
  String PlanetName;
  int Type;
  int Fighters;
  int Interceptors;
  int Frigates;
  int WarCruisers;
  int StarDreadnoughts;
  int SolarDestroyers;
  int Resource1;
  int Resource2;
  int Resource3;
};

Report IntelligenceReports[]={
  {"Cligga Prime",1,2,3,4,5,6,7,0,0,0},
  {"Cligga Prime",2,0,0,0,0,0,0,7,8,2},
  {"",0,0,0,0,0,0,0,0,0,0},
  {"",0,0,0,0,0,0,0,0,0,0},
  {"",0,0,0,0,0,0,0,0,0,0}
};

int8_t ScreenSelection=0;

int PlayerResources[]={2200,2200,2000};

//Timer
int8_t frames=0;
bool timeUpdate=false;

//Attack
bool fight=false;

//Fleet Selection
bool flSelection=false;
bool spyMission=false;
bool attackMission=false;
bool colonizeMission=false;

void setup() {
  gb.begin();
}

void loop() {
  while(!gb.update())
  gb.display.clear();
  gb.lights.clear();
  if(fight==true) //stop game to see fight results
  {
    bool resolved=battleResults();
    if(resolved==true)
    {
      fight=false;
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
  else if(attackMission==true)
  {
    bool selected=sendAttack();
    if(selected==true)
    {
      attackMission=false;
    }
  }
  else if(spyMission==true)// set spy to scout
  {
    bool selected=sendSpy();
    if(selected==true)
    {
      spyMission=false;
    }
  }
  else if(colonizeMission==true)// set spy to scout
  {
    bool selected=sendColonizer();
    if(selected==true)
    {
      colonizeMission=false;
    }
  }
  else
  {
    sendFleet();
    timeCalculations();
    if(ScreenSelection==0)
    {
      ScreenSelection=warRoom(PlayerResources);  
    }
    else if(ScreenSelection==1)
    {
      ScreenSelection=infrastructure();
    }
    else if(ScreenSelection==2)
    {
      ScreenSelection=research();
    }
    else if(ScreenSelection==3)
    {
      ScreenSelection=starMap(TechTree[0].level);
    }
    else if(ScreenSelection==6)
    {
      ScreenSelection=starRoutes(TechTree[5].level);
    }
    else if(ScreenSelection==8)
    {
      ScreenSelection=playerFleets();
    }
    else if(ScreenSelection==9)
    {
      ScreenSelection=enemyFleets();
    }
    else if(ScreenSelection==10)
    {
      ScreenSelection=playerFleetStats();
    }
    else if(ScreenSelection==11)
    {
      ScreenSelection=scoutReports();
    }
    else if(ScreenSelection==20)
    {
      ScreenSelection=3; //RETURN TO STAR MAP AFTER FLEET SELECTION
      flSelection=true;
    }
    else if(ScreenSelection==21)
    {
      ScreenSelection=3; //RETURN TO STAR MAP AFTER FLEET SELECTION
      spyMission=true;
    }
    else if(ScreenSelection==22)
    {
      ScreenSelection=3; //RETURN TO STAR MAP AFTER FLEET SELECTION
      colonizeMission=true;
    }
  }
}

void sendFleet()
{
  if(gb.buttons.pressed(BUTTON_MENU))
  {
    //EnemyFleets[0].Active=true;
    //EnemyFleets[0].Seconds=10;
    TechTree[0].level++;
    techEvents();
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
    if(PlayerFleets[index].Type==1)
    {
      gb.lights.fill(GREEN);
      //TODO: Attack report + return fleet
    }
    else if(PlayerFleets[index].Type==2)
    {
      gb.lights.fill(BLUE);
      colonizePlanet(PlayerFleets[index]);
    }
    else if(PlayerFleets[index].Type==3)
    {
      gb.lights.fill(YELLOW);
      scoutMission(PlayerFleets[index]);
    }
  }
  else
  {
    PlayerFleets[index].Seconds--;
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
      if(System[i].Hostile==true)
      {
        //TODO: Hostile Report
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
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==fleet.DestinationName)
    {
      System[i].Owned=true;
      break;
    }
  }
  String info=fleet.DestinationName + " COLONIZED!";
  gb.gui.popup("PLANET COLONIZED!",50);
}

void generateScoutReport(Report report)
{
  Report Temp[5]=IntelligenceReports;
  IntelligenceReports[0]=report;
  for(int i=1;i<4;i++)
  {
    IntelligenceReports[i]=Temp[i-1];
  }
  gb.gui.popup("NEW SCOUT REPORT!",50);
}

//----------------------------------------------

void updateResources()
{
  PlayerResources[0]+=1;
  PlayerResources[1]+=1;
  PlayerResources[2]+=1;
}

