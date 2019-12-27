int mmSelection=0;
int omSelection=0;
int omDiffSel=1;

int8_t mainMenu()
{
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(mmSelection==0)
    {
      mmSelection=2;
    }
    else
    {
      mmSelection--;
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(mmSelection==2)
    {
      mmSelection=0;
    }
    else
    {
      mmSelection++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    return mmSelection;
  }
  drawMainMenu(mmSelection);
  return 4;
}

bool optionsMenu()
{
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(omSelection==0)
    {
      omSelection=2;
    }
    else
    {
      omSelection--;
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(omSelection==2)
    {
      omSelection=0;
    }
    else
    {
      omSelection++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(omSelection==2)
    {
      omSelection=0;
      return true;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(omSelection==1)
    {
      if(omDiffSel==0)
      {
        omDiffSel=2;
      }
      else
      {
        omDiffSel--;
      }
      setDifficulty(); 
    }
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(omSelection==1)
    {
      if(omDiffSel==2)
      {
        omDiffSel=0;
      }
      else
      {
        omDiffSel++;
      }
      setDifficulty(); 
    }
  }
  drawOptionsMenu(omSelection);
  return false;
}

void setDifficulty()
{
  if(omDiffSel==0)
  {
    Difficulty="EASY";
  }
  else if(omDiffSel==1)
  {
    Difficulty="NORMAL";
  }
  else
  {
    Difficulty="HARD";
  }
}

void prepareNewGame()
{
  ProgressPointsLimit=0;
  visibilitySeconds=0;
  visibilityMinutes=0;
  FleetFuelCost=0;
  ScreenSelection=0;
  GameOver=false;
  Victory=false;

  ScreenSelection=0;
  fight=false;

  //Set Timer variables
  frames=0;
  framesCount=0;
  timeUpdate=false;
  visibilitySeconds=0;
  visibilityMinutes=0;
  timeToAttack=120;
  attackUnderway=false;

  BattleResult BattleResultReset={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,false};
  BtResult=BattleResultReset;

  BattleExperience=0;
  EnemyColonies=5;
  EnemyCapitals=1;
  
  //Reset player ships
  for(int i=0;i<11;i++)
  {
    PlayerShips[i]=0;
  }
  
  if(Difficulty=="EASY")
  {
    ProgressPointsLimit=120;
    PlayerResources[0]=600;
    PlayerResources[1]=600;
    PlayerResources[2]=500;
    PlayerShips[0]=100;
    PlayerShips[1]=50;
    PlayerShips[2]=3;
  }
  else if(Difficulty=="NORMAL")
  {
    ProgressPointsLimit=120;
    PlayerResources[0]=400;
    PlayerResources[1]=400;
    PlayerResources[2]=350;
    PlayerShips[0]=50;
    PlayerShips[1]=25;
  }
  else //HARD
  {
    ProgressPointsLimit=60;
    PlayerResources[0]=200;
    PlayerResources[1]=200;
    PlayerResources[2]=150;
  }
  
  preparePlanets();
  prepareGarrisons();
  prepareTechs();
  prepareBuildings();
  prepareFleets();
  prepareRoutes();
  prepareReports();
}

void preparePlanets()
{
  for(int i=1;i<30;i++)
  {
    System[i].Discovered=false;
    System[i].Hostile=false;
    System[i].Owned=false;
    System[i].TradeRoute=false;
    System[i].GarrisonIndex=-1;
    System[i].Status=false;
    System[i].ActiveMission=false;
  }
}

void prepareGarrisons()
{
  EnemyGarrison ResetGarrison={-1,200,100,20,5,2,0};
  for(int i=0;i<6;i++)
  {
    Enemy1Garrison[i]=ResetGarrison;
  }

  Enemy1Garrison[0].planetIndex=2; //Set Capital Garrison
  System[2].Hostile=true;
  System[2].GarrisonIndex=0;

  int gIdx=1;
  while(gIdx!=6) //Set random planets for garrisons
  {
    int pIdx=random(3, 28);
    if(System[pIdx].Hostile==false)
    {
      Enemy1Garrison[gIdx].planetIndex=pIdx;
      System[pIdx].Hostile=true;
      System[pIdx].GarrisonIndex=gIdx;
      gIdx++;
    }
    else
    {
      continue;
    }
  }
}

void prepareTechs()
{
  TechTree[0].level=1;
  TechTree[1].level=0;
  TechTree[1].depTechLevel=2;
  TechTree[2].level=0;
  TechTree[2].depTechLevel=2;
  TechTree[3].level=0;
  TechTree[3].depTechLevel=5;
  TechTree[4].level=0;
  TechTree[4].depTechLevel=5;
  TechTree[5].level=0;
  TechTree[5].depTechLevel=2;
  TechTree[6].level=0;
  TechTree[6].depTechLevel=4;
  TechTree[7].level=0;
  TechTree[7].depTechLevel=2;
  TechTree[8].level=0;
  TechTree[8].depTechLevel=5;
  TechTree[9].level=0;
  TechTree[9].depTechLevel=1;
  TechTree[10].level=0;
  TechTree[10].depTechLevel=2;
  TechTree[11].level=0;
  TechTree[11].depTechLevel=1;
  TechTree[12].level=0;
  TechTree[12].depTechLevel=5;
  TechTree[13].level=0;
  TechTree[13].depTechLevel=2;
  TechTree[14].level=0;
  TechTree[14].depTechLevel=1;
}

void prepareBuildings()
{
  Colony[0].level=1;
  Colony[1].level=1;
  Colony[1].depBuildingLevel=2;
  Colony[2].level=1;
  Colony[2].depBuildingLevel=2;
  Colony[3].level=0;
  Colony[3].depBuildingLevel=1;
  Colony[4].level=0;
  Colony[4].depTechLevel=1;
  Colony[5].level=0;
  Colony[5].depTechLevel=1;
  Colony[5].depBuildingLevel=1;
  Colony[6].level=0;
  Colony[6].depTechLevel=1;
  Colony[7].level=0;
  Colony[8].level=0;
  Colony[8].depTechLevel=1;
  Colony[9].level=0;
  Colony[10].level=0;
  Colony[10].depTechLevel=1;
  Colony[11].level=0;
  Colony[11].depTechLevel=1;
  Colony[12].level=0;
  Colony[12].depTechLevel=1;
}

void prepareFleets()
{
  Fleet ResetFleet={0,false,0,0,0,0,0,0,0,0,0,0,"",false};
  CustomFleet=ResetFleet;
  CustomEnemyFleet=ResetFleet;
  FleetFuelCost=0;
  
  for(int i=0;i<4;i++)
  {
    PlayerFleets[i]=ResetFleet;
    PlayerFleets[i].Visible=true;
    EnemyFleets[i]=ResetFleet;
    EnemyFleets[i].Type=4;    
  }

  //Fleet Selection
  flSelection=false;
  spyMission=false;
  spyMissionFleet=false;
  attackMission=false;
  colonizeMission=false;
  routesMission=false;
}

void prepareRoutes()
{
  TradeRoute ResetRoute={false,"",0,0,0};
  for(int i=0;i<12;i++)
  {
    PlayerRoutes[i]=ResetRoute;    
  }
  
  SelectedRoute=ResetRoute;
}

void prepareReports()
{
  Report Reset={"Empty",0,0,0,0,0,0,0,0,0,0};
  for(int i=0;i<5;i++)
  {
    IntelligenceReports[i]=Reset;
  }
}

bool gameOverInfo(bool victory)
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  drawEndGameScreen(victory);
  return false;
}

