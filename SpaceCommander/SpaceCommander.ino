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
  bool Owned; //If planet is colonized
  bool TradeRoute;  //If trade route to planet is set
  int GarrisonIndex;  //If planet is hostile
  bool Status; //If planet was classified by spy bot
  bool ActiveMission; //If planet is currently targeted by player fleet mission 
};

Planet SelectedPlanet={true,"Earth",38,28,false,"Player",0,0,0,true,false,-1,true,false};

Planet System[]={
  {true,"Earth",38,28,false,"Player",0,0,0,true,false,-1,true,false},
  {false,"Sheeza Prime",76,28,true,"Shezz",0,0,0,false,false,-1,false,false},
  {false,"Cligga Prime",0,28,true,"Cligg",0,0,0,false,false,-1,true,false},
  {false,"Tau 14",8,3,false,"None",1,2,3,false,false,-1,false,false},
  {false,"Cassia",14,3,false,"None",3,0,1,false,false,-1,false,false},
  {false,"Kanton",27,9,false,"None",1,1,1,false,false,-1,false,false},
  {false,"Nova 5",34,2,false,"None",4,0,2,false,false,-1,false,false},
  {false,"Andromeda",44,6,false,"None",2,2,1,false,false,-1,false,false},
  {false,"Syrius",55,11,false,"None",3,1,0,false,false,-1,false,false},
  {false,"Arnval",71,7,false,"None",1,0,4,false,false,-1,false,false},
  {false,"Duna",5,15,false,"None",0,2,1,false,false,-1,false,false},
  {false,"Armag",14,22,false,"None",4,0,1,false,false,-1,false,false},
  {false,"Tibann",26,19,false,"None",2,1,3,false,false,-1,false,false},
  {false,"San Da",48,17,false,"None",3,1,1,false,false,-1,false,false},
  {false,"Tolka",63,23,false,"None",2,2,2,false,false,-1,false,false},
  {false,"Raven",33,24,false,"None",3,2,1,true,false,-1,false,false},
  {false,"Novaria",36,26,false,"None",1,4,0,false,false,-1,false,false},
  {false,"Eden",15,30,false,"None",0,5,0,false,false,-1,false,false},
  {false,"Brantal V",24,32,false,"None",1,0,4,false,false,-1,false,false},
  {false,"Ganimedes",33,35,true,"None",5,0,0,false,false,0,false,false},
  {false,"Dan 11",54,32,false,"None",0,0,5,false,false,-1,false,false},
  {false,"Janya",7,43,false,"None",1,2,2,false,false,-1,false,false},
  {false,"Arti Ka",15,41,false,"None",1,0,3,false,false,-1,false,false},
  {false,"Tyra",27,45,false,"None",1,0,3,false,false,-1,false,false},
  {false,"Galant",51,48,false,"None",2,0,2,false,false,-1,false,false},
  {false,"Saxa",60,40,false,"None",1,1,1,false,false,-1,false,false},
  {false,"Rea 8",73,37,false,"None",3,2,1,false,false,-1,false,false},
  {false,"IO",66,54,false,"None",2,2,1,false,false,-1,false,false},
  {false,"Taka Van",33,55,false,"None",3,1,2,false,false,-1,false,false},
  {false,"Europa",3,55,false,"None",1,2,2,false,false,-1,false,false}
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
  int resource1Cost;
  int resource2Cost;
  int resource3Cost;
  String restriction;
  int depTechId;
  int8_t depTechLevel;
  int depBuildingId;
  int8_t depBuildingLevel;
};

Building Colony[]={
  {1,"Power Plant",0,1,"Required to build   higher level        structures.",50,50,50,"None",0,0,0,0},
  {2,"Metal Mine",0,1,"Deliver metal       resource.",50,0,0,"None",0,0,1,2},
  {3,"Crystal Mine",0,1,"Deliver crystal     resource.",0,50,0,"None",0,0,1,2},
  {4,"Fuel Refinery",0,1,"Deliver fuel        resource.",50,50,0,"None",0,0,1,2},
  {5,"Intelligence",0,0,"Reveal more intel inenemy reports.",100,75,0,"None",2,1,0,0},
  {6,"Radar",0,0,"Detects enemy fleets+1 visibility / lvl.",25,40,0,"None",7,1,5,1},
  {7,"Shipyard",0,1,"Required to build   high level ships.",75,75,75,"None",8,1,0,0},
  {8,"Research Lab",0,1,"Unlocks additional  technology / lvl.",100,100,100,"None",0,0,0,0},
  {9,"Defence System",0,1,"+ 10 points to      defense / lvl.",100,200,50,"None",8,1,0,0},
  {10,"Factory",0,1,"None",0,0,0,"None",0,0,0,0},
  {11,"Warehouse",0,1,"None",0,0,0,"None",0,0,0,0},
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
  {"Fighter",1,"Swarm of fighters is the basic fleet defence.",75,25,1,1},
  {"Interceptor",2,"Ship designed to hunt fighters.",150,75,1,1},
  {"Frigate",3,"Light armored ship.",400,200,1,1},
  {"War Cruiser",4,"Primary planetary defense ship.",750,400,1,1},
  {"Star Dreadnought",5,"Heavy armored ship designed to transport entire fleet.",1000,750,1,1},
  {"Solar Destroyer",6,"Ship designed to destroy entire planet.",5000,5000,1,1},
  {"Spy Bot",7,"Fragile probe used to scan planets and enemy fleet.",5,5,1,1},
  {"Colonizer",8,"Set colony on the planet.",1000,1000,5,0},
  {"Metal Transport",9,"Transport metal from colonies.",500,5,0,1},
  {"Crystal Transport",10,"Transport crystals from colonies.",500,250,1,0},
  {"Fuel Transport",11,"Transport fuel from colonies.",750,500,1,0}
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
  {0,false,0,0,0,0,0,0,0,0,0,0,"",true}
};

Fleet EnemyFleets[]={
  {4,false,0,20,0,0,250,500,30,20,0,0,"",false},
  {4,false,0,30,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,40,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,50,0,0,0,0,0,0,0,0,"",false}
};

Fleet CustomFleet={0,false,0,0,0,0,0,0,0,0,0,0,"",false};
Fleet CustomEnemyFleet={4,false,0,0,0,0,0,0,0,0,0,0,"",false};

int FleetFuelCost=0;

int PlayerShips[]={
  500, //Fighter
  250, //Interceptor
  60, //Frigate
  15, //War Cruiser
  0, //Star Dreadnought
  0, //Solar Destroyer
  90, //Spy Bot
  0, //Colonizer
  5, //Metal Transport
  2, //Crystal Transport
  1  //Fuel Transport
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
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0}
};

int8_t ScreenSelection=0;

int PlayerResources[]={9200,9200,9000};

//Timer
int8_t frames=0;
int8_t framesCount=0;
bool timeUpdate=false;
int8_t visibilitySeconds=0;
int8_t visibilityMinutes=0;

//Attack
bool fight=false;

struct BattleResult
{
  int PlFighters;
  int PlFightersLost;
  int EnFighters;
  int EnFightersLost;
  int PlInterceptors;
  int PlInterceptorsLost;
  int EnInterceptors;
  int EnInterceptorsLost;
  int PlFrigates;
  int PlFrigatesLost;
  int EnFrigates;
  int EnFrigatesLost;
  int PlWarCruisers;
  int PlWarCruisersLost;
  int EnWarCruisers;
  int EnWarCruisersLost;
  int PlStarDreadnoughts;
  int PlStarDreadnoughtsLost;
  int EnStarDreadnoughts;
  int EnStarDreadnoughtsLost;
  int PlSolarDestroyers;
  int PlSolarDestroyersLost;
  int EnSolarDestroyers;
  int EnSolarDestroyersLost;
  bool Winning;
};

BattleResult BtResult={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,false};

//Fleet Selection
bool flSelection=false;
bool spyMission=false;
bool attackMission=false;
bool colonizeMission=false;
bool routesMission=false;

int BattleExperience=0;

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
      lockPlanet();
      attackMission=false;
    }
  }
  else if(spyMission==true)// set spy to scout
  {
    bool selected=sendSpy();
    if(selected==true)
    {
      lockPlanet();
      spyMission=false;
    }
  }
  else if(colonizeMission==true)// set colonizer
  {
    bool selected=sendColonizer();
    if(selected==true)
    {
      lockPlanet();
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
    else if(ScreenSelection==5)
    {
      ScreenSelection=intelligence();
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
    else if(ScreenSelection==23)
    {
      ScreenSelection=3; //RETURN TO STAR MAP AFTER FLEET SELECTION
      routesMission=true;
    }
  }
}

void sendFleet()
{
  if(gb.buttons.pressed(BUTTON_MENU))
  {
    //prepareEnemyFleet();
    //EnemyFleets[0]=CustomEnemyFleet;
    //TechTree[0].level++;
    //techEvents();
    //spaceBattle(0,0,false);
    //spaceBattle(0,0,true);
    //fight=true;
    //gb.gui.popup("BATTLE!",50); 
  }
}

void timeCalculations()
{
  if(frames==25)// every second tick update game mechanics
  {
    framesCount++;
    frames=0;
    updateVisibilityDistance();
    updateFleets();
  }
  else
  {
    frames++;
  }
  if(framesCount==2)//slow time
  {
    framesCount=0;
    updateResources();
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
  for(int i=0;i<4;i++)
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

void lockPlanet()
{
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==SelectedPlanet.Name)
    {
      System[i].ActiveMission=true;
      System[i].ActiveMission=true;
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
    //TODO: Hostile Report - Enemy Fleet??
  }
}

void colonizePlanet(Fleet fleet)
{
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==fleet.DestinationName)
    {
      System[i].ActiveMission=false;
      System[i].Owned=true;
      break;
    }
  }
  gb.gui.popup("PLANET COLONIZED!",50);
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
  PlayerResources[0]+=1 + Colony[1].level*2; //Metal Mine
  PlayerResources[1]+=1 + Colony[2].level*2; //Crystal Mine
  PlayerResources[2]+=1 + Colony[3].level*2; //Fuel Refinery
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

