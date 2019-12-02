#include<Gamebuino-Meta.h>

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
  int8_t maxLevel;
};

Technology TechTree[]={
  {1,"Astronomy",0,1,100,100,0,"Increases visibilityon the Star Map.","None",0,0,39},
  {2,"Espionage",0,0,250,50,50,"Unlocks Intelligencebuilding and        Spy Bots.","Astronomy",1,2,21},
  {3,"Jet Proplusion",0,0,100,100,100,"Unlocks Fighters andincreases their     speed.","Astronomy",1,2,15},
  {4,"Aerodynamics",0,0,150,120,150,"Unlocks Interceptors and increases their speed.","Jet Proplusion",3,5,10},
  {5,"Impulse Engine",0,0,50,250,200,"Unlocks Frigates andincreases their     speed.","Jet Proplusion",3,5,10},
  {6,"Hyperdrive",0,0,100,500,400,"Unlocks War Cruisersand increases their speed.","Impulse Engine",5,2,10},
  {7,"Logistics",0,0,120,120,50,"+ 1 to Star Routes  and Colonies. UnlockTransports.","Astronomy",1,4,12},
  {8,"Radiolocation",0,0,100,150,0,"Unlock Radar and    increases visibilityrange.","Espionage",2,2,20},
  {9,"Fleet Tactics",0,10,100,25,0,"Needed to upgrade   shipyard and build  high level ships.","Astronomy",1,10},
  {10,"Shielding",0,0,400,500,0,"Unlock Planetary    Defense System and  increases firepower.","Fleet Tactics",9,5,15},
  {11,"Statics",0,0,0,0,0,"Unlock Warehouse andincreases it's      capacity.","Logistics",7,2,11},
  {12,"Ship Weapons",0,0,125,300,75,"Final level unlocks Star Dreadnoughts.","Fleet Tactics",9,1,10},
  {13,"Fusion Reaction",0,0,0,0,0,"Unlocks Transformer and its upgrades.","Fleet Tactics",9,8,10},
  {14,"Flight Control",0,0,0,0,0,"Unlocks Logistic    Centre and its      upgrades.","Statics",11,2,10},
  {15,"Gravity Weapon",0,0,0,0,0,"Final level of this technology unlocks  Solar Destroyer.","Fusion Reaction",13,1,10}
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
  int depTechId;
  int8_t depTechLevel;
  int depBuildingId;
  int8_t depBuildingLevel;
  int8_t maxLevel;
};

Building Colony[]={
  {1,"Power Plant",0,1,"Required to build   higher level        structures.",50,50,50,0,0,0,0,21},
  {2,"Metal Mine",0,1,"Deliver metal       resource.",50,0,0,0,0,1,2,20},
  {3,"Crystal Mine",0,1,"Deliver crystal     resource.",0,50,0,0,0,1,2,20},
  {4,"Fuel Refinery",0,1,"Deliver fuel        resource.",50,50,0,0,0,1,2,20},
  {5,"Intelligence",0,0,"Reveal more intel inenemy reports.",100,75,0,2,1,0,0,13},
  {6,"Radar",0,15,"Detects enemy fleets+1 visibility / lvl.",25,40,0,8,1,5,1,20},
  {7,"Shipyard",0,1,"Required to build   high level ships.",75,75,75,9,1,0,0,10},
  {8,"Research Lab",0,15,"Unlocks additional  technology / lvl.",100,100,100,0,0,0,0,15},
  {9,"Defence System",0,1,"+ 10 points to      defense / lvl.",100,200,50,10,1,0,0,10},
  {10,"Factory",0,1,"Reduces Metal and   Crystal cost of     buildings.",100,150,0,0,0,0,0,0},
  {11,"Warehouse",0,1,"Stores resources    when losing battle. +100 for each       resource / lvl.",250,250,0,11,1,0,0,10},
  {12,"Transformer",0,0,"Converts one        resource to another.",500,500,750,13,1,0,0,10},
  {13,"Logistic Centre",0,0,"Increases resource  transport from traderoutes.",300,100,200,14,1,0,0,10}
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
  {"Fighter",1,"Swarm of fighters isthe basic fleet     defence.",75,25,1,1},
  {"Interceptor",2,"Ship designed to    hunt fighters.",150,75,1,1},
  {"Frigate",3,"Light armored ship.",400,200,1,1},
  {"War Cruiser",4,"Primary first line attack ship.",750,400,1,1},
  {"Star Dreadnought",5,"Heavy armored ship  used to transport   entire fleet.",1000,750,1,1},
  {"Solar Destroyer",6,"Ship designed to    destroy entire      planet.",5000,5000,1,1},
  {"Spy Bot",7,"Fragile probe used  to scan planets and enemy fleets.",5,5,1,1},
  {"Colonizer",8,"Set colony on the   planet.",1000,1000,5,0},
  {"Metal Transport",9,"Transport metal fromcolonies.",500,5,0,1},
  {"Crystal Transport",10,"Transport crystals  from colonies.",500,250,1,0},
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
  {0,0,0,0,0,0,0}, //Capital
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
  {4,false,0,0,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,0,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,0,0,0,0,0,0,0,0,0,"",false},
  {4,false,0,0,0,0,0,0,0,0,0,0,"",false}
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
  int Winner;
};

BattleResult BtResult={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,false};

//Fleet Selection
bool flSelection=false;
bool spyMission=false;
bool spyMissionFleet=false;
bool attackMission=false;
bool colonizeMission=false;
bool routesMission=false;

int BattleExperience=0;

bool IsMainMenu=true;
bool IsOptionMenu=false;

//Game options

int EnemyCount=1;
String Difficulty="NORMAL";
int ProgressPoints=105;
int ProgressPointsLimit=120;

//Enemy Timer
int timeToAttack=20;//4 minutes interval
bool attackUnderway=false;

void setup() {
  gb.begin();
}

void loop() {
  while(!gb.update())
  gb.display.clear();
  gb.lights.clear();
  if(IsMainMenu==true)  //MAIN MENU
  {
    int8_t choice=mainMenu();
    if(choice==0 || choice==1)
    {
      IsMainMenu=false;
    }
    else if(choice==2)
    {
      IsMainMenu=false;
      IsOptionMenu=true;
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
    else if(spyMissionFleet==true)// set spy to scout
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
      sendFleet();
      timeCalculations();
      if(ScreenSelection==0)
      {
        ScreenSelection=warRoom(PlayerResources);  
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
      else if(ScreenSelection==12) //SAVE GAME
      {
        ScreenSelection=0;
        IsMainMenu=true;
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
      else if(ScreenSelection==24)
      {
        ScreenSelection=3; //RETURN TO ENEMY FLEETS AFTER FLEET SELECTION
        spyMissionFleet=true;
      }
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
    enemyAttackTimer();
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
    int8_t winner=spaceBattle(index,-1,false);
    if(winner==2)//battle lost
    {
      resourcePillage();
      if(ProgressPoints<ProgressPointsLimit)
      {
        ProgressPoints++; //ultimate weapon progress
      }
    }
    fight=true;
    enemyFleetsCheck(); 
  }
  else
  {
    EnemyFleets[index].Seconds--;
  }
}

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
    attackUnderway=false;
    timeToAttack=20; //4 minutes
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
  String planet=PlayerFleets[index].DestinationName;
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==planet)
    {
      int idx=System[i].GarrisonIndex;
      if(idx!=-1)
      {
        int8_t winner=spaceBattle(idx,index,true);
        fight=true;
        if(winner==1) //if player wins move fleet back
        {
          setFleetReturnParameters(index);
          PlayerFleets[index].Active=true;
        }
        System[i].ActiveMission=false;
      }
      break;
    }
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

void resourcePillage()
{
  int reserve=Colony[10].level*100; //Warehouse protection
  for(int i=0;i<3;i++)
  {
    if(PlayerResources[i]>=reserve)
    {
      PlayerResources[i]=reserve;
    }
  }
}

//--------Enemy Attacks------------------------
void enemyAttackTimer()
{
  if(timeToAttack==-1) //at least two fleets are attacking
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
        prepareEnemyFleet();
        int idx=getEnemyFleetSlot();
        if(idx!=-1)
        {
          EnemyFleets[idx]=CustomEnemyFleet;
          attackUnderway=true;
          timeToAttack=10; // 2 minutes
        }
      }
    }
    else
    {
      int chance=random(0, 6);
      if(chance==1 || chance==3)
      {
        prepareEnemyFleet();
        int idx=getEnemyFleetSlot();
        if(idx!=-1)
        {
          EnemyFleets[idx]=CustomEnemyFleet;
          timeToAttack=-1; //stop attacks
        }
      }
    }
  }
}

void prepareEnemyFleet()
{
  CustomEnemyFleet=setEnemyFleet();
  int Speed=0; //in seconds per 1 unit 
  int distance=37;
  CustomEnemyFleet.Fighters=10;
  CustomEnemyFleet.Interceptors=10;
  CustomEnemyFleet.Frigates=10;
  CustomEnemyFleet.WarCruisers=10;
  CustomEnemyFleet.StarDreadnoughts=10;
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

int getEnemyFleetSlot()
{
  int result=-1;
  for(int i=0;i<4;i++)
  {
    if(EnemyFleets[i].Active==false)
    {
      result=i;
      break;
    }
  }
  return result;
}

Fleet setEnemyFleet()
{
  Fleet EnemyArmada={4,true,0,0,0,0,0,0,0,0,0,0,"",false};
  int modifier=0;
  if(Difficulty=="EASY")
  {
    modifier=8;
  }
  else if(Difficulty=="NORMAL")
  {
    modifier=4;
  }
  else
  {
    modifier=2;
  }
  
  EnemyArmada.Fighters = 100 + PlayerShips[0]+(PlayerShips[0]/modifier);
  if(TechTree[2].level>2)//Jet Proplusion
  {
    EnemyArmada.Interceptors = 50 + PlayerShips[1]+(PlayerShips[1]/modifier);
  }
  if(TechTree[3].level>5)//Aerodynamics
  {
    EnemyArmada.Frigates = 10 + PlayerShips[2]+(PlayerShips[2]/modifier);
  }
  if(TechTree[4].level>5)//Impulse Engine
  {
    EnemyArmada.WarCruisers = 5 + PlayerShips[3]+(PlayerShips[3]/modifier);
  }
  if(TechTree[5].level>5)//Hyperdrive
  {
    EnemyArmada.StarDreadnoughts = 2 + PlayerShips[4]+(PlayerShips[4]/modifier);
  }
  if(ProgressPoints==ProgressPointsLimit) //ultimate weapon discovered
  {
    EnemyArmada.SolarDestroyers=1; //solar destroyers 
  }
  return EnemyArmada;
}

