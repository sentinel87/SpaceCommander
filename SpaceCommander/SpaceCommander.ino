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
  {2,"Espionage",0,0,250,50,50,"Unlocks Intelligence building.","Astronomy",1,2},
  {3,"Jet Proplusion",0,0,100,100,100,"Unlocks Fighters and increases theirs speed.","Astronomy",1,2},
  {4,"Impulse Engine",0,0,50,250,200,"Unlocks Frigates and increases their speed.","Jet Proplusion",3,5},
  {5,"Hyperdrive",0,0,100,500,400,"Unlocks War Cruisers and increases their speed.","Impulse Engine",4,5},
  {6,"Logistics",0,0,120,120,50,"+ 1 to Star Routes and Colonies.","Astronomy",1,4},
  {7,"Radiolocation",0,0,100,150,0,"Unlock Radar building and increases visibility.","Espionage",2,2},
  {8,"Military Science",0,1,100,25,0,"Needed to upgrade shipyard level and build high level ships.","None",0,0},
  {9,"Shielding",0,0,400,500,0,"Unlock Planetary Defense System and increases it's power.","Military Science",8,10},
  {10,"Construction Mechanics",0,0,0,0,0,"Unlock Warehouse and increases it's capacity.","Logistics",6,1},
  {11,"Ship Weapons",0,0,125,300,75,"Needed to build high level ships.","Military Science",8,1},
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
  int depTechId;
  int8_t depTechLevel;
  int depBuildingId;
  int8_t depBuildingLevel;
};

Building Colony[]={
  {1,"Power Plant",0,1,"Required to build higher level structures",50,50,50,"None",0,0,0,0},
  {2,"Metal Mine",0,1,"Deliver metal resource.",50,0,0,"None",0,0,1,2},
  {3,"Crystal Mine",0,1,"Deliver crystal resource.",0,50,0,"None",0,0,1,2},
  {4,"Fuel Refinery",0,1,"Deliver fuel resource.",50,50,0,"None",0,0,1,2},
  {5,"Intelligence",0,0,"Reveal more intel in enemy reports.",100,75,0,"None",2,0,0,0},
  {6,"Radar",0,0,"Detects enemy fleets +1 visibility/lvl.",25,40,0,"None",7,1,5,1},
  {7,"Shipyard",0,1,"Required to build high level ships.",75,75,75,"None",8,1,0,0},
  {8,"Planetary Defence System",0,1,"+ 10 points to defense/lvl",100,200,50,"None",8,1,0,0},
  {9,"None",0,1,"None",0,0,0,"None",0,0,0,0},
  {10,"None",0,1,"None",0,0,0,"None",0,0,0,0},
  {11,"None",0,1,"None",0,0,0,"None",0,0,0,0},
  {12,"None",0,1,"None",0,0,0,"None",0,0,0,0},
  {13,"None",0,1,"None",0,0,0,"None",0,0,0,0},
  {14,"None",0,1,"None",0,0,0,"None",0,0,0,0},
  {15,"None",0,1,"None",0,0,0,"None",0,0,0,0},
};

struct Ship
{
  String type;
  int8_t imageId;
  String describtion;
  int resource1Cost;
  int resource2Cost;
  int8_t hitPoints;
  int8_t attack;
};

Ship Shipyard[]={
  {"Spy Bot",1,"Fragile probe used to scan planets and enemy fleet.",5,5,1,1},
  {"Fighter",2,"Swarm of fighters is the basic fleet defence.",75,25,1,1},
  {"Interceptor",3,"Ship designed to hunt fighters.",150,75,1,1},
  {"Frigate",4,"Light armored ship.",400,200,1,1},
  {"War Cruiser",5,"Primary planetary defense ship.",750,400,1,1},
  {"Star Dreadnought",6,"Heavy armored ship designed to transport entire fleet.",1000,750,1,1},
  {"Solar Destroyer",7,"Ship designed to destroy entire planet.",5000,5000,1,1},
  {"Metal Transport",8,"Transport metal from colonies.",500,5,0,1},
  {"Crystal Transport",9,"Transport crystals from colonies.",500,250,1,0},
  {"Fuel Transport",10,"Transport fuel from colonies.",750,500,1,0},
  {"Colonizer",11,"Set colony on the planet.",1000,1000,5,0}
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
  int8_t Type; //1 - player armada 2 - Colonize 3 - Spy 4 - Enemy 5 - Return
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
  bool Visible;
};

Fleet PlayerFleets[]={
  {0,false,0,0,0,0,0,0,0,0,0,0,"",true},
  {0,false,0,0,0,0,0,0,0,0,0,0,"",true},
  {0,false,0,0,0,0,0,0,0,0,0,0,"",true},
  {0,false,0,0,0,0,0,0,0,0,0,0,"",true},
  {0,false,0,0,0,0,0,0,0,0,0,0,"",true}
};

Fleet EnemyFleets[]={
  {4,false,0,20,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,30,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,40,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,50,0,0,0,0,0,0,0,0,"",false},
  {4,false,1,20,0,0,0,0,0,0,0,0,"",false}
};

Fleet CustomFleet={0,false,0,0,0,0,0,0,0,0,0,0,"",false};
Fleet CustomEnemyFleet={4,false,0,0,0,0,0,0,0,0,0,0,"",false};

int FleetFuelCost=0;

int PlayerShips[]={
  10, //Fighter
  10, //Interceptor
  10, //Frigate
  10, //War Cruiser
  10, //Star Dreadnought
  10, //Solar Destroyer
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

int PlayerResources[]={5200,5200,5000};

//Timer
int8_t frames=0;
bool timeUpdate=false;
int8_t visibilitySeconds=0;
int8_t visibilityMinutes=0;

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
    else if(ScreenSelection==4)
    {
      ScreenSelection=shipyard(TechTree[7].level);
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
    prepareEnemyFleet();
    EnemyFleets[0]=CustomEnemyFleet;
    //TechTree[0].level++;
    //techEvents();
  }
}

void timeCalculations()
{
  if(frames==25)// every second tick update game mechanics
  {
    frames=0;
    updateVisibilityDistance();
    updateResources();
    updateFleets();
  }
  else
  {
    frames++;
  }
}

void updateVisibilityDistance()
{
  int base=10+(Colony[5].level*10);
  if(base>59)
  {
    visibilityMinutes=base/60;
    visibilitySeconds=base-(visibilityMinutes*60);
  }
  else
  {
    visibilityMinutes=0;
    visibilitySeconds=base;
  }
}

void updateFleets()
{
  for(int i=0;i<5;i++)
  {
    if(EnemyFleets[i].Active==true)
    {
      updateEnemyFleetTime(i);
      if(EnemyFleets[i].Minutes==visibilityMinutes && EnemyFleets[i].Seconds==visibilitySeconds)
      {
        EnemyFleets[i].Visible=true;
        gb.lights.fill(RED);
        gb.gui.popup("INCOMING ATTACK!",50);
      }
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
    Fleet Cleanup={0,false,0,20,0,0,0,0,0,0,0,0,""};
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

void attackPlanet(int index)
{
  PlayerFleets[index].Active=true;
  //TODO: Battle Function
  if(true) //If fleet wasn't destroyed
  {
    setFleetReturnParameters(index);
  }
}

void fleetReturns(Fleet fleet)
{
  PlayerShips[0]+=fleet.Fighters;
  PlayerShips[1]+=fleet.Interceptors;
  PlayerShips[2]+=fleet.Frigates;
  PlayerShips[3]+=fleet.WarCruisers;
  PlayerShips[4]+=fleet.StarDreadnoughts;
  PlayerShips[5]+=fleet.SolarDestroyers;
  gb.gui.popup("FLEET HAS RETURNED!",50);
}
//--------Resources----------------------------

void updateResources()
{
  PlayerResources[0]+=1;
  PlayerResources[1]+=1;
  PlayerResources[2]+=1;
}

//--------Enemy Attacks------------------------
void prepareEnemyFleet()
{
  Fleet temp={4,true,0,0,0,0,0,0,0,0,0,0,"",false};
  CustomEnemyFleet=temp;
  int Speed=0; //in seconds per 1 unit 
  int distance=37;
  //TODO: Fleet ships algorithm
  CustomEnemyFleet.Fighters=1;
  CustomEnemyFleet.Interceptors=1;
  CustomEnemyFleet.Frigates=1;
  CustomEnemyFleet.WarCruisers=1;
  CustomEnemyFleet.StarDreadnoughts=1;
  //Calculate speed
  if(CustomEnemyFleet.Fighters>0)
  {
    Speed=9;
  }
  if(CustomEnemyFleet.Interceptors>0)
  {
    Speed=11;
  }
  if(CustomEnemyFleet.Frigates>0)
  {
    Speed=13;
  }
  if(CustomEnemyFleet.WarCruisers>0)
  {
    if(Speed>7 || Speed==0)
    {
      Speed=7; 
    }
  }
  if(CustomEnemyFleet.StarDreadnoughts>0)
  {
    if(Speed>6 || Speed==0)
    {
      Speed=6; 
    }
  }
  //Calculate minutes and seconds (1 unit - speed)
  int totalSeconds=distance*Speed;
  if(totalSeconds>59) //at least 1 minute
  {
    int minutes=totalSeconds/60;
    int seconds=totalSeconds-(minutes*60);
    CustomEnemyFleet.Seconds=seconds;
    CustomEnemyFleet.Minutes=minutes;
  }
  else
  {
    CustomEnemyFleet.Seconds=totalSeconds;
  }
}

