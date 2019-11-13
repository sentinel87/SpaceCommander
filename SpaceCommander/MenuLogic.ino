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
  
  if(Difficulty=="EASY")
  {
    ProgressPointsLimit=60;
    PlayerResources[0]=600;
    PlayerResources[1]=600;
    PlayerResources[2]=500;
  }
  else if(Difficulty=="NORMAL")
  {
    ProgressPointsLimit=120;
    PlayerResources[0]=400;
    PlayerResources[1]=400;
    PlayerResources[2]=350;
  }
  else
  {
    ProgressPointsLimit=120;
    PlayerResources[0]=200;
    PlayerResources[1]=200;
    PlayerResources[2]=150;
  }
  
  //Reset player ships
  for(int i=0;i<11;i++)
  {
    PlayerShips[i]=0;
  }
  
  //Fleets reset
  Fleet ResetFleet={0,false,0,0,0,0,0,0,0,0,0,0,"",false};
  CustomFleet=ResetFleet;
  CustomEnemyFleet=ResetFleet;
  for(int i=0;i<4;i++)
  {
    PlayerFleets[i]=ResetFleet;
    PlayerFleets[i].Visible=true;
    EnemyFleets[i]=ResetFleet;    
  }
  
  //Routes reset
  TradeRoute ResetRoute={false,"",0,0,0};
  for(int i=0;i<12;i++)
  {
    PlayerRoutes[i]=ResetRoute;    
  }
}
