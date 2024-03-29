int stPosX = 38;
int stPosY = 28;

int stIndex = 0;
int stSelection = 1;
bool stDropDownMenu = false;
int stEnabled[] = {1,0,0,0,0,0};

int8_t starMap(int Astronomy)
{
  if (stDropDownMenu == true)
  {
    if (gb.buttons.pressed(BUTTON_UP))
    {
      getPreviousChoice();   
    }
    else if (gb.buttons.pressed(BUTTON_DOWN))
    {
      getNextChoice();
    }
    else if (gb.buttons.pressed(BUTTON_A))
    {
      stDropDownMenu = false;
      if (stSelection == 1)
      {
        if (PlayerShips[6] > 0)
        {
          Fleet spyFleet = {3,true,0,0,1,0,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true,0};
          CustomFleet = spyFleet;
          setFleetParameters();
          return 21; //SPY MISSION CONFIRMATION
        }
        else
        {
          gb.gui.popup("NO SPY BOTS!", 50);
        }
      }
      else if (stSelection == 2)
      {
        if (PlayerShips[7] > 0)
        {
          Fleet colonizationFleet = {2,true,0,0,0,1,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true,0};
          CustomFleet = colonizationFleet;
          setFleetParameters();
          return 22; //COLONIZATION MISSION CONFIRMATION
        }
        else
        {
          gb.gui.popup("NO COLONIZERS!", 50);
        }
      }
      else if (stSelection == 3)
      {
        if (SelectedPlanet.Name == "Cligg Prime") //Check Capital condition
        {
          if (countColonies(Enemy1Garrison) > 0)
          {
            gb.gui.popup("DESTROY COLONIES!", 50);
          }
          else
          {
            Fleet attackFleet = {1,true,0,0,0,0,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true,0};
            CustomFleet = attackFleet;
            return 20; //FLEET SELECTION SCREEN
          }
        }
        else if (SelectedPlanet.Name == "Sheez Prime" && EnemyCount == 2) //Check 2 Capital condition
        {
          if (countColonies(Enemy2Garrison) > 0)
          {
            gb.gui.popup("DESTROY COLONIES!", 50);
          }
          else
          {
            Fleet attackFleet = {1,true,0,0,0,0,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true,0};
            CustomFleet = attackFleet;
            return 20; //FLEET SELECTION SCREEN
          }
        }
        else
        {
          Fleet attackFleet = {1,true,0,0,0,0,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true,0};
          CustomFleet = attackFleet;
          return 20; //FLEET SELECTION SCREEN
        }
      }
      else if (stSelection == 4)
      {
        Fleet raidFleet = {6,true,0,0,0,0,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true,0};
        CustomFleet = raidFleet;
        return 26; //RAID SELECTION SCREEN
      }
      else if (stSelection == 5)
      {
        TradeRoute route = {true,SelectedPlanet.Name,SelectedPlanet.Resource1,SelectedPlanet.Resource2,SelectedPlanet.Resource3};
        SelectedRoute = route;
        return 23; //TRADE ROUTE CONFIRMATION
      }
      else if (stSelection == 6)
      {
        abandonPlanet();
      }
    }
    else if (gb.buttons.pressed(BUTTON_B))
    {
      stDropDownMenu = false;
    }
  }
  else
  {
    if (gb.buttons.repeat(BUTTON_UP, 3))
    {
      if (stPosY != 0)
      {
        stPosY--;
      } 
    }
    else if (gb.buttons.repeat(BUTTON_DOWN, 3))
    {
      if (stPosY != 56)
      {
        stPosY++;
      }
    }
    else if (gb.buttons.repeat(BUTTON_LEFT, 3))
    {
      if (stDropDownMenu == false)
      {
        if (stPosX != 0)
        {
          stPosX--;
        }
      }
    }
    else if (gb.buttons.repeat(BUTTON_RIGHT, 3))
    {
      if (stDropDownMenu == false)
      {
        if (stPosX != 76)
        {
          stPosX++;
        }
      }
    }
    else if (gb.buttons.pressed(BUTTON_A))
    {
      selectedPlanet();
      if (SelectedPlanet.Name != "" && SelectedPlanet.Name != "UEF Colony")
      {
        stDropDownMenu = true;
        bool activeChoices = buildDropdownMenu();
        if (activeChoices == true)
        {
          stSelection = 1;  
        }
        else
        {
          stSelection = -1; 
        }
      }
    }
    else if (gb.buttons.pressed(BUTTON_B))
    {
      stSelection = 1;
      return 0;
    }
  }
  drawMap(Astronomy, stPosX, stPosY);
  drawPlanetsColors();
  if (stDropDownMenu == true)
  {
    drawDropdownMenu(stPosX, stPosY, stSelection, stEnabled);
  }
  return 6;
}

void resetMapMarkers()
{
  stPosX = 38;
  stPosY = 28;
}

bool buildDropdownMenu()
{
  bool isFleetSlot = checkFleetSlots();
  if (isFleetSlot == true) //If Player Fleet Slot is available
  {
    bool freeColonies=checkColonies();
    if (SelectedPlanet.ActiveMission == true) //If planet has active mission
    {
      stEnabled[0] = 0;
      stEnabled[1] = 0;
      stEnabled[2] = 0;
      stEnabled[3] = 0;
      stEnabled[4] = 0;
      stEnabled[5] = 0;
      return false;
    }
    if (SelectedPlanet.Status == false) //If planned was not scanned
    {
      stEnabled[0] = 1;
      stEnabled[1] = 0;
      stEnabled[2] = 0;
      stEnabled[3] = 0;
      stEnabled[4] = 0;
      stEnabled[5] = 0;
      return true;
    }
    if (SelectedPlanet.Hostile == true)
    {
      stEnabled[0] = 1;
      stEnabled[1] = 0;
      stEnabled[2] = 1;
      stEnabled[3] = 1;
      stEnabled[4] = 0;
      stEnabled[5] = 0;
      return true;
    }
    else if (SelectedPlanet.Owned == false)
    {
      if (freeColonies == true) //Can have more colonies
      {
        stEnabled[0] = 1;
        stEnabled[1] = 1;
        stEnabled[2] = 0;
        stEnabled[3] = 0;
        stEnabled[4] = 0;
        stEnabled[5] = 0; 
      }
      else
      {
        stEnabled[0] = 1;
        stEnabled[1] = 0;
        stEnabled[2] = 0;
        stEnabled[3] = 0;
        stEnabled[4] = 0;
        stEnabled[5] = 0;
      }
      return true;
    }
    else if (SelectedPlanet.TradeRoute == false)
    {
      stEnabled[0] = 1;
      stEnabled[1] = 0;
      stEnabled[2] = 0;
      stEnabled[3] = 0;
      stEnabled[4] = 1;
      stEnabled[5] = 1;
      return true;
    }
    else
    {
      stEnabled[0] = 1;
      stEnabled[1] = 0;
      stEnabled[2] = 0;
      stEnabled[3] = 0;
      stEnabled[4] = 0;
      stEnabled[5] = 1;
      return true;
    }
  }
  else
  {
    stEnabled[0] = 0;
    stEnabled[1] = 0;
    stEnabled[2] = 0;
    stEnabled[3] = 0;
    stEnabled[4] = 0;
    stEnabled[5] = 0;
    return false;
  }
}

bool checkColonies()
{
  bool result = false;
  int owned = 0;
  for (int i = 0; i < 30; i++)
  {
    if (System[i].Owned == true)
    {
      owned++;
    }
  }
  for (int i = 0; i < 4; i++) // check current colonization missions
  {
    if (PlayerFleets[i].Type == 2)
    {
      owned++;
    }
  }
  if (TechTree[5].level + 1 > owned)
  {
    result = true;
  }
  return result;
}

void abandonPlanet()
{
  if (SelectedPlanet.TradeRoute == true)
  {
    for(int i = 0; i < 12; i++) //Remove trade route
    {
      if (PlayerRoutes[i].Name == SelectedPlanet.Name)
      {
        TradeRoute route = {false,"",0,0,0};
        PlayerRoutes[i] = route;
        break;
      }
    }
    refreshTradeRoutes();
  }
  for (int i = 0; i < 30; i++)
  {
    if (System[i].Name == SelectedPlanet.Name)
    {
      System[i].Owned = false;
      System[i].TradeRoute = false;
      SelectedPlanet = System[i];
      gb.gui.popup("PLANET ABANDONED!", 50);
      break;
    }
  }
}

void getNextChoice()
{
  if (SelectedPlanet.ActiveMission == false)
  {
    for (int i = 1; i <= 6; i++)
    {
      if ((i > (stSelection)) && stEnabled[i - 1] == 1)
      {
        stSelection = i;
        return;
      }
    }
    stSelection = 1; 
  }
  else
  {
    stSelection = -1;
  }
}

void getPreviousChoice()
{
  if (SelectedPlanet.ActiveMission == false)
  {
    for (int i = 6; i >= 0; i--)
    {
      if ((i < (stSelection)) && stEnabled[i - 1] == 1)
      {
        stSelection = i;
        return;
      }
    }
    for (int i = 6; i >= 0; i--)
    {
      if (stEnabled[i - 1] == 1)
      {
        stSelection = i;
        return;
      }
    }
  }
  else
  {
    stSelection = -1;
  }
}

void selectedPlanet()
{
  for (int i = 0; i < 30; i++)
  {
    if (System[i].posX == stPosX && System[i].posY == stPosY && System[i].Discovered == true)
    {
      SelectedPlanet = System[i];
      return;
    }
  }
  SelectedPlanet = {false,"",0,0,false,0,0,0,0,false,false,-1,false};
}

void setInterceptFleetParameters()
{
  FleetFuelCost = CustomFleet.Missles * (Colony[14].level * 50); 
}

void setFleetParameters()
{
  FleetFuelCost = 0;
  int Speed = 0; //in seconds per 1 unit 
  //Calculate distance
  int distance = 0;
  if (SelectedPlanet.posX < 38)
  {
    distance += 38 - SelectedPlanet.posX;
  }
  else
  {
    distance += SelectedPlanet.posX - 38;
  }
  if (SelectedPlanet.posY < 28)
  {
    distance += 28 - SelectedPlanet.posY;
  }
  else
  {
    distance += SelectedPlanet.posY - 28;
  }
  //Calculate fuel cost
  if (CustomFleet.SpyBots > 0)
  {
    FleetFuelCost += CustomFleet.SpyBots * (40 - TechTree[2].level); //Jet Proplusion decrease cost
    Speed = 2;
  }
  if (CustomFleet.Colonizers > 0)
  {
    FleetFuelCost += CustomFleet.Colonizers * (400 - (TechTree[2].level * 2)); //Jet Proplusion decrease cost
    Speed = 5;
  }
  if (CustomFleet.Fighters > 0)
  {
    FleetFuelCost += CustomFleet.Fighters * 2;
    Speed = 33 - TechTree[2].level;
  }
  if (CustomFleet.Interceptors > 0)
  {
    FleetFuelCost += CustomFleet.Interceptors * 5;
    int sp = 27 - TechTree[6].level;
    if (sp < Speed || Speed == 0)
    {
      Speed = sp;
    }
  }
  if (CustomFleet.Frigates > 0)
  {
    FleetFuelCost += CustomFleet.Frigates * 12;
    int sp = 21 - TechTree[11].level;
    if (sp < Speed || Speed == 0)
    {
      Speed = sp;
    }
  }
  if (CustomFleet.WarCruisers > 0)
  {
    FleetFuelCost += CustomFleet.WarCruisers * 25;
    int sp = 15 - TechTree[14].level;
    if (sp < Speed || Speed == 0)
    {
      Speed = sp;
    }
  }
  if (CustomFleet.StarDreadnoughts > 0)
  {
    FleetFuelCost += CustomFleet.StarDreadnoughts * 50;
    if (Speed > 2 || Speed == 0)
    {
      Speed = 2; 
    }
  }
  if (CustomFleet.SolarDestroyers > 0)
  {
    FleetFuelCost += CustomFleet.SolarDestroyers * 100;
    if (Speed > 1 || Speed == 0)
    {
      Speed = 1; 
    }
  }
  if (CustomFleet.Stalkers > 0)
  {
    FleetFuelCost += CustomFleet.Stalkers * 20;
    Speed = 6;
  }
  if (CustomFleet.Leviatans > 0)
  {
    FleetFuelCost += CustomFleet.Leviatans * 50;
    Speed = 4;
  }
  //Calculate minutes and seconds (1 unit - speed)
  int totalSeconds = distance * Speed;
  if (totalSeconds > 59) //at least 1 minute
  {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds - (minutes * 60);
    CustomFleet.Seconds = seconds;
    CustomFleet.Minutes = minutes;
  }
  else
  {
    CustomFleet.Seconds = totalSeconds;
  }
}

void setFleetReturnParameters(int index)
{
  Planet StartPlanet = {false,"none",0,0,false,0,0,0,0,false,false,-1,false};
  for (int i = 0; i < 30; i++)
  {
    if (System[i].Name == PlayerFleets[index].DestinationName)
    {
      StartPlanet = System[i];
      break;
    } 
  }
  int Speed = 0; //in seconds per 1 unit 
  //Calculate distance
  int distance = 0;
  if (StartPlanet.posX < 38)
  {
    distance += 38 - StartPlanet.posX;
  }
  else
  {
    distance += StartPlanet.posX - 38;
  }
  if (StartPlanet.posY < 28)
  {
    distance += 28 - StartPlanet.posY;
  }
  else
  {
    distance += StartPlanet.posY - 28;
  }
  //Calculate max speed
  if (PlayerFleets[index].Fighters > 0)
  {
    Speed = 33 - TechTree[2].level;
  }
  if (PlayerFleets[index].Interceptors > 0)
  {
    int sp = 27 - TechTree[6].level;
    if (sp < Speed || Speed == 0)
    {
      Speed = sp;
    }
  }
  if (PlayerFleets[index].Frigates > 0)
  {
    int sp = 21 - TechTree[11].level;
    if (sp < Speed || Speed == 0)
    {
      Speed = sp;
    }
  }
  if (PlayerFleets[index].WarCruisers > 0)
  {
    int sp = 15 - TechTree[14].level;
    if (sp < Speed || Speed == 0)
    {
      Speed = sp;
    }
  }
  if (PlayerFleets[index].StarDreadnoughts > 0)
  {
    if (Speed > 2 || Speed == 0)
    {
      Speed = 2; 
    }
  }
  if (PlayerFleets[index].SolarDestroyers > 0)
  {
    if (Speed > 1 || Speed == 0)
    {
      Speed = 1; 
    }
  }
  if (PlayerFleets[index].Stalkers > 0)
  {
    Speed = 6;
  }
  if (PlayerFleets[index].Leviatans > 0)
  {
    Speed = 4;
  }
  //Calculate minutes and seconds (1 unit - speed)
  int totalSeconds = distance * Speed;
  if (totalSeconds > 59) //at least 1 minute
  {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds - (minutes * 60);
    PlayerFleets[index].Seconds = seconds;
    PlayerFleets[index].Minutes = minutes;
  }
  else
  {
    PlayerFleets[index].Seconds = totalSeconds;
  }
  PlayerFleets[index].Type = 5; //set returning fleet
}

bool checkFleetSlots()
{
  for (int i = 0; i < 4; i++)
  {
    if (PlayerFleets[i].Active == false)
    {
      return true;
    }
  }
  return false;
}

