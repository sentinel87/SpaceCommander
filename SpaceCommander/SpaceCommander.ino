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

Planet SelectedPlanet={true,"UEF Colony",38,28,false,"Player",0,0,0,true,false,-1,true,false};

Planet System[]={
  {true,"UEF Colony",38,28,false,"Player",0,0,0,true,false,-1,true,false},
  {false,"Sheez Prime",76,28,false,"Shezz",3,2,2,false,false,-1,false,false},
  {false,"Cligg Prime",0,28,true,"Cligg",0,0,0,false,false,0,false,false},
  {false,"Ganimedes",33,35,true,"None",1,2,0,false,false,0,false,false},//Poor resources (3)
  {false,"Raven",33,24,false,"None",1,1,1,true,false,-1,false,false},
  {false,"Novaria",36,26,false,"None",1,0,2,false,false,-1,false,false},
  {false,"Kanton",27,9,false,"None",2,0,3,false,false,-1,false,false},//Medium resources(6)
  {false,"Armag",14,22,false,"None",1,4,0,false,false,-1,false,false},
  {false,"Syrius",55,11,false,"None",3,2,0,false,false,-1,false,false},
  {false,"Tibann",26,19,false,"None",1,3,1,false,false,-1,false,false},
  {false,"San Da",48,17,false,"None",0,5,0,false,false,-1,false,false},
  {false,"Tolka",63,23,false,"None",1,1,3,false,false,-1,false,false},
  {false,"Eden",15,30,false,"None",0,5,0,false,false,-1,false,false},
  {false,"Brantal V",24,32,false,"None",5,0,0,false,false,-1,false,false},
  {false,"Dan 11",54,32,false,"None",0,0,5,false,false,-1,false,false},
  {false,"Arti Ka",15,41,false,"None",0,2,3,false,false,-1,false,false},
  {false,"Tyra",27,45,false,"None",4,1,0,false,false,-1,false,false},
  {false,"Galant",51,48,false,"None",2,1,2,false,false,-1,false,false},
  {false,"Saxa",60,40,false,"None",0,5,0,false,false,-1,false,false},
  {false,"Tau 14",8,3,false,"None",5,1,1,false,false,-1,false,false},//Rich resources (19)
  {false,"Cassia",14,3,false,"None",2,2,3,false,false,-1,false,false},
  {false,"Nova 5",34,2,false,"None",1,5,1,false,false,-1,false,false},
  {false,"Andromeda",44,6,false,"None",1,1,5,false,false,-1,false,false},
  {false,"Arnval",71,7,false,"None",1,2,4,false,false,-1,false,false},
  {false,"Duna",5,15,false,"None",4,2,1,false,false,-1,false,false},
  {false,"Janya",7,43,false,"None",5,1,1,false,false,-1,false,false},
  {false,"Rea 8",73,37,false,"None",3,2,2,false,false,-1,false,false},
  {false,"IO",66,54,false,"None",2,3,2,false,false,-1,false,false},
  {false,"Taka Van",33,55,false,"None",3,4,0,false,false,-1,false,false},
  {false,"Europa",3,55,false,"None",4,3,0,false,false,-1,false,false}
};

struct Technology
{
  int8_t id;
  String techName;
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
  {1,"Astronomy",2,25,30,20,"Increases visibilityon the Star Map.","None",0,0,39},
  {2,"Espionage",0,200,75,75,"Unlocks Intelligencebuilding and        Spy Bots.","Astronomy",1,2,16},
  {3,"Jet Proplusion",0,100,100,100,"Unlocks Fighters andincreases their     speed.","Astronomy",1,2,19},
  {4,"Fleet Tactics",0,100,25,10,"Needed to upgrade   shipyard and build  high level ships.","Astronomy",1,5,16},
  {5,"Radiolocation",0,80,110,50,"Unlock Radar and    increases visibilityrange.","Espionage",2,2,15},
  {6,"Logistics",0,120,120,50,"+ 1 to Star Routes  and Colonies. UnlockTransports.","Astronomy",1,5,12},
  {7,"Aerodynamics",0,150,120,150,"Unlocks Interceptorsand increases their speed.","Jet Proplusion",3,4,15},
  {8,"Cloaking",0,150,140,100,"Unlocks Stalkers.   Stalker steal 1/lvl enemy fighter and   interceptor.","Radiolocation",5,1,11},
  {9,"Statics",0,200,350,50,"Unlock Warehouse andincreases it's      capacity.","Logistics",6,2,11},
  {10,"Impulse Engine",0,50,250,200,"Unlocks Frigates andincreases their     speed.","Aerodynamics",7,4,11},
  {11,"Shielding",0,350,400,100,"Unlock Planetary    Defence System and  increases firepower.","Fleet Tactics",4,1,14},
  {12,"Mind Control",0,200,300,300,"Unlocks Leviatans.  Leviatan steal 1/lvlenemy Frigate.","Cloaking",8,4,5},
  {13,"Hyperdrive",0,100,500,400,"Unlocks War Cruisersand increases their speed.","Impulse Engine",10,2,10},
  {14,"Fusion Reaction",0,450,350,250,"Unlocks Transformer and its upgrades.","Fleet Tactics",4,5,10},
  {15,"Ship Weapons",0,125,300,75,"Final level unlocks Star Dreadnoughts.","Shielding",11,2,10},
  {16,"Flight Control",0,350,200,250,"Unlocks Logistic    Centre and its      upgrades.","Statics",9,2,10},
  {17,"Gravity Weapon",0,800,800,800,"Final level of this technology unlocks  Solar Destroyer.","Hyperdrive",13,1,9}

};

struct Building
{
  int8_t id;
  String bName;
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
  {1,"Power Plant",1,"Required to build   higher level        mines.",200,190,150,0,0,0,0,15},
  {2,"Metal Mine",1,"Extract metal       resource.",210,195,25,0,0,1,2,15},
  {3,"Crystal Mine",1,"Extract crystal     resource.",200,230,50,0,0,1,2,15},
  {4,"Fuel Refinery",0,"Deliver fuel        resource.",200,185,65,0,0,1,2,15},
  {5,"Intelligence",0,"Reveals more intel  in hostile reports.",210,185,10,2,1,0,0,12},
  {6,"Radar",0,"Detects enemy fleets+1 visibility / lvl.",185,185,25,5,1,0,0,15},
  {7,"Shipyard",0,"Required to build   colony ships.",350,350,275,4,1,0,0,10},
  {8,"Research Lab",0,"Unlocks additional  technology / lvl.",100,100,75,0,0,0,0,17},
  {9,"Defence System",0,"Provides additional firepower for colonydefence / lvl.",210,250,75,11,1,0,0,14},
  {10,"Factory",0,"Reduces metal and   crystal cost of     buildings.",300,220,60,0,0,0,0,10},
  {11,"Warehouse",0,"Stores resources    when losing battle. +200 for each       resource / lvl.",300,300,50,9,1,0,0,10},
  {12,"Transformer",0,"Converts one        resource to another.",350,300,550,14,1,0,0,10},
  {13,"Logistic Centre",0,"Increases resource  transport from traderoutes.",400,200,300,16,1,0,0,10}
};

struct Ship
{
  String type;
  int8_t imageId;
  String describtion;
  int resource1Cost;
  int resource2Cost;
};

Ship Shipyard[]={
  {"Fighter",1,"Swarm of fighters isthe basic fleet     defence.",50,15},
  {"Interceptor",2,"Ship designed to    hunt fighters.",100,40},
  {"Frigate",3,"Light armored ship. Bonus against       Fighters.",270,150},
  {"War Cruiser",4,"First line attack ship. Bonus against   Interceptors.",400,230},
  {"Star Dreadnought",5,"Heavy armored ship  used to transport   entire fleet.",550,300},
  {"Solar Destroyer",6,"Ship designed to    destroy entire      planet.",4000,4000},
  {"Spy Bot",7,"Fragile probe used  to scan planets and enemy fleets.",15,10},
  {"Colonizer",8,"Set colony on the   planet.",900,900},
  {"Metal Transport",9,"Transport metal fromcolonies.",350,35},
  {"Crystal Transport",10,"Transport crystals  from colonies.",400,150},
  {"Fuel Transport",11,"Transport fuel from colonies.",300,200},
  {"Stalker",12,"Steal enemy fightersand interceptors.",300,300},
  {"Leviatan",13,"Steal enemy         frigates.",700,700}
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
  0 //Leviatans
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

//Menu variables

bool IsMainMenu=true;
bool IsOptionMenu=false;
bool IsFameHall=false;
bool GameOver=false;
bool Victory=false;
bool GameStarted=false;

//Game options

int EnemyCount=1;
String Difficulty="NORMAL";
String TempDiff="NORMAL";
int ProgressPoints=0;
int ProgressPointsLimit=120;
int EnemyColonies=5;
int EnemyCapitals=1;
int ScoreBoard[]={0,0,0,0,0};
int Score=0;

//Enemy Timer
int timeToAttack=0;//4 minutes interval
bool attackUnderway=false;

const SaveDefault savefileDefaults[] = {
  { 0,SAVETYPE_INT,0,0 },
  { 1,SAVETYPE_INT,0,0 },
  { 2,SAVETYPE_INT,0,0 },
  { 3,SAVETYPE_INT,0,0 },
  { 4,SAVETYPE_INT,0,0 }
};

void setup() {
  gb.begin();
  gb.save.config(savefileDefaults);
  ScoreBoard[0]=gb.save.get(0);
  ScoreBoard[1]=gb.save.get(1);
  ScoreBoard[2]=gb.save.get(2);
  ScoreBoard[3]=gb.save.get(3);
  ScoreBoard[4]=gb.save.get(4);
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
    else if(choice==2)
    {
      IsMainMenu=false;
      IsOptionMenu=true;
    }
    else if(choice==3)
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
          gb.save.set(0,ScoreBoard[0]);
          gb.save.set(1,ScoreBoard[1]);
          gb.save.set(2,ScoreBoard[2]);
          gb.save.set(3,ScoreBoard[3]);
          gb.save.set(4,ScoreBoard[4]);
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
          gb.save.set(0,ScoreBoard[0]);
          gb.save.set(1,ScoreBoard[1]);
          gb.save.set(2,ScoreBoard[2]);
          gb.save.set(3,ScoreBoard[3]);
          gb.save.set(4,ScoreBoard[4]);
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
      else if(ScreenSelection==12) //SAVE GAME (PAUSE)
      {
        ScreenSelection=0;
        TempDiff=Difficulty;
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
    updateFleets();
    enemyAttackTimer();
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

//----------------------------------Fleets-----------------------

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
    EnemyFleets[index].Visible=false;
    int8_t winner=spaceBattle(index,-1,false);
    if(winner==2)//battle lost
    {
      gb.lights.fill(RED);
      PlayerShips[6]=0;
      PlayerShips[7]=0;
      PlayerShips[8]=0;
      PlayerShips[9]=0;
      PlayerShips[10]=0;
      
      bool richBounty=resourcePillage();
      resetTransformerAfterAttack();
      if(ProgressPoints<ProgressPointsLimit)
      {
        if(richBounty==true)
        {
          ProgressPoints+=6; //ultimate weapon progress
        }
        else
        {
          ProgressPoints+=3; //ultimate weapon progress
        }
        if(ProgressPoints>ProgressPointsLimit)
        {
          ProgressPoints=ProgressPointsLimit;
        }
        garrisonUpgrade();
      }
      if(EnemyFleets[index].SolarDestroyers>0)  //If Attack was successfull and ultimate weapon survived, the game is over;
      {
        GameOver=true;
        countFinalScore(false);
      }
    }
    else
    {
      gb.lights.fill(GREEN);
      BattleExperience++;
      if(Difficulty=="EASY")
      {
        Score+=8;
      }
      else if(Difficulty=="HARD")
      {
        Score+=30;
      }
      else
      {
        Score+=15; 
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

void garrisonUpgrade()
{
  for(int i=0;i<6;i++)
  {
    if(Enemy1Garrison[i].planetIndex!=-1)
    {
      Enemy1Garrison[i].Fighters+=10;
      Enemy1Garrison[i].Interceptors+=5;
      if(Difficulty=="NORMAL" || Difficulty=="HARD")
      {
          Enemy1Garrison[i].Frigates+=1;
      }
    }
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
    timeToAttack=110;
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
          BattleExperience+=2;
          setFleetReturnParameters(index);
          PlayerFleets[index].Active=true;
          if(idx==0)//Capital planet defeated
          {
            if(PlayerFleets[index].SolarDestroyers>0)//At least one Solar Destroyer survived 
            {
              Score+=100;
              Victory=true;
              countFinalScore(true);
            }
            else
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
          }
          else //Colony defeated
          {
            Enemy1Garrison[idx].planetIndex=-1;
            System[i].Hostile=false;
            System[i].GarrisonIndex=-1;
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
            EnemyColonies--;
            Score+=50;
          }
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
  PlayerResources[0] += 3 + Colony[1].level*3; //Metal Mine
  PlayerResources[1] += 3 + Colony[2].level*2; //Crystal Mine
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
          timeToAttack=90;
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
    modifier=6;
  }
  else if(Difficulty=="NORMAL")
  {
    modifier=4;
  }
  else
  {
    modifier=2;
  }
  
  EnemyArmada.Fighters = 10 + PlayerShips[0]+(PlayerShips[0]/modifier) + random(0,20);
  if(TechTree[2].level>=4)//Jet Proplusion
  {
    EnemyArmada.Interceptors = 5 + PlayerShips[1]+(PlayerShips[1]/modifier) + random(0,15);
  }
  if(TechTree[6].level>=4)//Aerodynamics
  {
    EnemyArmada.Frigates = 3 + PlayerShips[2]+(PlayerShips[2]/modifier) + random(0,5);
  }
  if(TechTree[8].level>=2)//Impulse Engine
  {
    EnemyArmada.WarCruisers = 2 + PlayerShips[3]+(PlayerShips[3]/modifier) + random(0,2);
  }
  if(TechTree[12].level==10)//Ship Weapons
  {
    EnemyArmada.StarDreadnoughts = 1 + PlayerShips[4]+(PlayerShips[4]/modifier) + random(0,2);
  }
  if(ProgressPoints==ProgressPointsLimit) //ultimate weapon discovered
  {
    EnemyArmada.SolarDestroyers=1; //solar destroyers 
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

