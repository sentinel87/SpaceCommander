int flMarkerPosX = 1;
int flMarkerPosY = 11;
int flSelectionIdx = 1;

int flMarker2PosY = 7;

//Fleet Selection Markers
int flShipSelection = 1;
int flShipSelection2 = 7;
bool flSelectedShip = false;
int flQuantity = 10;

int playerFleets()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawPlayerFleets(flMarkerPosX, flMarkerPosY);
  return 1;
}

int enemyFleets()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    if (flSelectionIdx == 4)
    {
      flSelectionIdx = 1;
      flMarkerPosY = 11;
    }
    else
    {
      flSelectionIdx++;
      flMarkerPosY += 11;
    }
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    if (flSelectionIdx == 1)
    {
      flSelectionIdx = 4;
      flMarkerPosY = 44;
    }
    else
    {
      flSelectionIdx--;
      flMarkerPosY -= 11;
    }
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (PlayerShips[6] > 0 && flSelectionIdx != -1) //Generate fleet report
    {
      int count = 0;
      for (int i = 0; i < 4; i++)
      {
        if (EnemyFleets[i].Active == true && EnemyFleets[i].Visible == true)
        {
          count++;
          if (count == flSelectionIdx)
          {
            String header = "ENEMY " + EnemyFleets[i].DestinationName;
            Report Hostile = {header, 1, EnemyFleets[i].Fighters, EnemyFleets[i].Interceptors, EnemyFleets[i].Frigates, EnemyFleets[i].WarCruisers, EnemyFleets[i].StarDreadnoughts, EnemyFleets[i].SolarDestroyers, 0, 0, 0};
            generateScoutReport(Hostile);
            gb.gui.popup("NEW FLEET REPORT!", 50);
            PlayerShips[6]--;
          }
        }
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_MENU))
  {
    if (PlayerShips[13] > 0 && flSelectionIdx != -1) //Select fleet to intercept
    {
      int count = 0;
      for (int i = 0; i < 4; i++)
      {
        if (EnemyFleets[i].Active == true && EnemyFleets[i].Visible == true)
        {
          count++;
          if (count == flSelectionIdx && EnemyFleets[i].Minutes >= 1)
          {
            Fleet interceptFleet = {7,true,0,0,0,0,0,0,0,0,0,0,0,0,0,EnemyFleets[i].DestinationName,true,i};
            CustomFleet = interceptFleet;
            setInterceptFleetParameters(EnemyFleets[i].Minutes, EnemyFleets[i].Seconds);
            return 27; //INTERCEPT MISSION SELECTION
          }
          else if (count == flSelectionIdx)
          {
            gb.gui.popup("FLEET TOO CLOSE!", 50);
          }
        }
      }
    }
  }
  drawEnemyFleets(flMarkerPosX, flMarkerPosY, flSelectionIdx);
  return 3;
}

void setInterceptFleetParameters(int minutes, int seconds)
{
  int totalSeconds = (minutes * 60) + seconds;
  int interceptionFleetSeconds = totalSeconds / 2;

  if (interceptionFleetSeconds > 59)
  {
    CustomFleet.Minutes = interceptionFleetSeconds / 60;
    CustomFleet.Seconds = interceptionFleetSeconds - (CustomFleet.Minutes * 60);
  }
  else
  {
    CustomFleet.Minutes = 0;
    CustomFleet.Seconds = interceptionFleetSeconds;
  }
}

int playerFleetStats()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawFleetStats();
  return 5;
}

int playerFleetSelection()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    flShipSelection = 1;
    flMarker2PosY = 7; 
    return 0;
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    if (flSelectedShip == true)
    {
      increaseShips(flShipSelection);
    }
    else
    {
      if (flShipSelection == 1)
      {
        flShipSelection = 6;
        flMarker2PosY = 47;
      }
      else
      {
        flShipSelection -= 1;
        flMarker2PosY -= 8;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    if (flSelectedShip == true)
    {
      decreaseShips(flShipSelection);
    }
    else
    {
      if (flShipSelection == 6)
      {
        flShipSelection = 1;
        flMarker2PosY = 7;
      }
      else
      {
        flShipSelection += 1;
        flMarker2PosY += 8;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (flSelectedShip == true)
    {
      if(flQuantity == 1)
      {
        flQuantity = 10;
      }
      else if (flQuantity == 10)
      {
        flQuantity = 100;
      }
      else if (flQuantity == 100)
      {
        flQuantity = 1000;
      }
      else
      {
        flQuantity = 1;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (flSelectedShip == true)
    {
      if (flQuantity == 1)
      {
        flQuantity = 1000;
      }
      else if (flQuantity == 10)
      {
        flQuantity = 1;
      }
      else if (flQuantity == 100)
      {
        flQuantity = 10;
      }
      else
      {
        flQuantity = 100;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_MENU))
  {
    if (flSelectedShip == true)
    {
      checkQuantity(flShipSelection);
      flSelectedShip = false;
    }
    else if (flSelectedShip == false && flShipSelection != 7)
    {
      flSelectedShip = true;
    }
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (flSelectedShip != true && (CustomFleet.Fighters != 0 || CustomFleet.Interceptors != 0 || CustomFleet.Frigates != 0 || CustomFleet.WarCruisers != 0 || CustomFleet.StarDreadnoughts != 0 || CustomFleet.SolarDestroyers != 0))
    {
      flShipSelection = 1;
      flMarker2PosY = 7; 
      return 2; 
    }
  }
  drawFleetSelection(flMarker2PosY, flSelectedShip, flQuantity, 1);
  return 1;
}

int playerFleetSelectionRaid()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    flShipSelection2 = 7;
    flMarker2PosY = 7;
    return 0;
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    if (flSelectedShip == true)
    {
      increaseShips(flShipSelection2);
    }
    else
    {
      if (flShipSelection2 == 7)
      {
        flShipSelection2 = 8;
        flMarker2PosY = 15;
      }
      else
      {
        flShipSelection2 -= 1;
        flMarker2PosY -= 8;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    if (flSelectedShip == true)
    {
      decreaseShips(flShipSelection2);
    }
    else
    {
      if (flShipSelection2 == 8)
      {
        flShipSelection2 = 7;
        flMarker2PosY = 7;
      }
      else
      {
        flShipSelection2 += 1;
        flMarker2PosY += 8;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (flSelectedShip == true)
    {
      if (flQuantity == 1)
      {
        flQuantity = 10;
      }
      else if (flQuantity == 10)
      {
        flQuantity = 100;
      }
      else if (flQuantity == 100)
      {
        flQuantity = 1000;
      }
      else
      {
        flQuantity = 1;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (flSelectedShip == true)
    {
      if (flQuantity == 1)
      {
        flQuantity = 1000;
      }
      else if (flQuantity == 10)
      {
        flQuantity = 1;
      }
      else if (flQuantity == 100)
      {
        flQuantity = 10;
      }
      else
      {
        flQuantity = 100;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_MENU))
  {
    if (flSelectedShip == true)
    {
      checkQuantity(flShipSelection2);
      flSelectedShip = false;
    }
    else if (flSelectedShip == false)
    {
      flSelectedShip = true;
    }
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (flSelectedShip != true && (CustomFleet.Stalkers != 0 || CustomFleet.Leviatans != 0))
    {
      flShipSelection2 = 7;
      flMarker2PosY = 7;
      return 2; 
    }
  }
  drawFleetSelection(flMarker2PosY ,flSelectedShip, flQuantity, 2);
  return 1;
}

int playerFleetSelectionIntercept()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    if (flSelectedShip == true)
    {
      increaseShips(9);
    }
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    if (flSelectedShip == true)
    {
      decreaseShips(9);
    }
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (flSelectedShip == true)
    {
      if (flQuantity == 1)
      {
        flQuantity = 10;
      }
      else
      {
        flQuantity = 1;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (flSelectedShip == true)
    {
      if (flQuantity == 1)
      {
        flQuantity = 10;
      }
      else
      {
        flQuantity = 1;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_MENU))
  {
    if (flSelectedShip == true)
    {
      checkQuantity(9);
      flSelectedShip = false;
    }
    else if (flSelectedShip == false)
    {
      flSelectedShip = true;
    }
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (flSelectedShip != true && CustomFleet.Missles != 0)
    {
      return 2; 
    }
  }
  drawFleetSelection(flMarker2PosY ,flSelectedShip, flQuantity, 3);
  return 1;
}

void increaseShips(int shipSelection)
{
  switch(shipSelection)
  {
    case 1:
    {
      CustomFleet.Fighters += flQuantity;
      if (CustomFleet.Fighters > 9999)
      {
        CustomFleet.Fighters = 9999;
      }
    }
    break;
    case 2:
    {
      CustomFleet.Interceptors += flQuantity;
      if (CustomFleet.Interceptors > 9999)
      {
        CustomFleet.Interceptors = 9999;
      }
    }
    break;
    case 3:
    {
      CustomFleet.Frigates += flQuantity;
      if (CustomFleet.Frigates > 9999)
      {
        CustomFleet.Frigates = 9999;
      }
    }
    break;
    case 4:
    {
      CustomFleet.WarCruisers += flQuantity;
      if (CustomFleet.WarCruisers > 9999)
      {
        CustomFleet.WarCruisers = 9999;
      }
    }
    break;
    case 5:
    {
      CustomFleet.StarDreadnoughts += flQuantity;
      if (CustomFleet.StarDreadnoughts > 9999)
      {
        CustomFleet.StarDreadnoughts = 9999;
      }
    }
    break;
    case 6:
    {
      CustomFleet.SolarDestroyers += flQuantity;
      if (CustomFleet.SolarDestroyers > 9999)
      {
        CustomFleet.SolarDestroyers = 9999;
      }
    }
    break;
    case 7:
    {
      CustomFleet.Stalkers += flQuantity;
      if (CustomFleet.Stalkers > 9999)
      {
        CustomFleet.Stalkers = 9999;
      }
    }
    break;
    case 8:
    {
      CustomFleet.Leviatans += flQuantity;
      if (CustomFleet.Leviatans > 9999)
      {
        CustomFleet.Leviatans = 9999;
      }
    }
    break;
    case 9:
    {
      CustomFleet.Missles += flQuantity;
      if (CustomFleet.Missles > 9999)
      {
        CustomFleet.Missles = 9999;
      }
    }
    break;
  }
}

void decreaseShips(int shipSelection)
{
  switch (shipSelection)
  {
    case 1:
    {
      CustomFleet.Fighters -= flQuantity;
      if(CustomFleet.Fighters < 0)
      {
        CustomFleet.Fighters = 0;
      }
    }
    break;
    case 2:
    {
      CustomFleet.Interceptors -= flQuantity;
      if(CustomFleet.Interceptors < 0)
      {
        CustomFleet.Interceptors = 0;
      }
    }
    break;
    case 3:
    {
      CustomFleet.Frigates -= flQuantity;
      if (CustomFleet.Frigates < 0)
      {
        CustomFleet.Frigates = 0;
      }
    }
    break;
    case 4:
    {
      CustomFleet.WarCruisers -= flQuantity;
      if (CustomFleet.WarCruisers < 0)
      {
        CustomFleet.WarCruisers = 0;
      }
    }
    break;
    case 5:
    {
      CustomFleet.StarDreadnoughts -= flQuantity;
      if (CustomFleet.StarDreadnoughts < 0)
      {
        CustomFleet.StarDreadnoughts = 0;
      }
    }
    break;
    case 6:
    {
      CustomFleet.SolarDestroyers -= flQuantity;
      if (CustomFleet.SolarDestroyers < 0)
      {
        CustomFleet.SolarDestroyers = 0;
      }
    }
    break;
    case 7:
    {
      CustomFleet.Stalkers -= flQuantity;
      if (CustomFleet.Stalkers < 0)
      {
        CustomFleet.Stalkers = 0;
      }
    }
    break;
    case 8:
    {
      CustomFleet.Leviatans -= flQuantity;
      if (CustomFleet.Leviatans < 0)
      {
        CustomFleet.Leviatans = 0;
      }
    }
    break;
    case 9:
    {
      CustomFleet.Missles -= flQuantity;
      if (CustomFleet.Missles < 0)
      {
        CustomFleet.Missles = 0;
      }
    }
    break;
  }
}

void checkQuantity(int shipSelection)
{
  switch (shipSelection)
  {
    case 1:
    {
      if (CustomFleet.Fighters > PlayerShips[0])
      {
        CustomFleet.Fighters = PlayerShips[0];
      }
    }
    break;
    case 2:
    {
      if (CustomFleet.Interceptors > PlayerShips[1])
      {
        CustomFleet.Interceptors = PlayerShips[1];
      }
    }
    break;
    case 3:
    {
      if (CustomFleet.Frigates > PlayerShips[2])
      {
        CustomFleet.Frigates = PlayerShips[2];
      }
    }
    break;
    case 4:
    {
      if (CustomFleet.WarCruisers > PlayerShips[3])
      {
        CustomFleet.WarCruisers = PlayerShips[3];
      }
    }
    break;
    case 5:
    {
      if (CustomFleet.StarDreadnoughts > PlayerShips[4])
      {
        CustomFleet.StarDreadnoughts = PlayerShips[4];
      }
    }
    break;
    case 6:
    {
      if (CustomFleet.SolarDestroyers > PlayerShips[5])
      {
        CustomFleet.SolarDestroyers = PlayerShips[5];
      }
    }
    break;
    case 7:
    {
      if (CustomFleet.Stalkers > PlayerShips[11])
      {
        CustomFleet.Stalkers = PlayerShips[11];
      }
    }
    break;
    case 8:
    {
      if (CustomFleet.Leviatans > PlayerShips[12])
      {
        CustomFleet.Leviatans = PlayerShips[12];
      }
    }
    break;
    case 9:
    {
      if (CustomFleet.Missles > Colony[14].level)
      {
        CustomFleet.Missles = Colony[14].level;
        if (CustomFleet.Missles > PlayerShips[13])
        {
          CustomFleet.Missles = PlayerShips[13];
        }
      }
    }
    break;
  }
}

int8_t sendSpy()
{
  bool canSend = fleetPreStartCheck();
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 2;
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (canSend == true)
    {
      PlayerResources[2] -= FleetFuelCost;
      for (int i = 0; i < 4; i++)
      {
        if (PlayerFleets[i].Active == false)
        {
          PlayerShips[6]--;
          PlayerFleets[i] = CustomFleet;
          gb.gui.popup("FLEET SEND!", 50);
          break;
        }
      }
      return 1;
    }
  }
  drawSendFleetConfirmation(3, canSend);
  return 0;
}

int8_t sendColonizer()
{
  bool canSend = fleetPreStartCheck();
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 2;
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (canSend == true)
    {
      PlayerResources[2] -= FleetFuelCost;
      for (int i = 0; i < 4; i++)
      {
        if (PlayerFleets[i].Active == false)
        {
          PlayerShips[7]--;
          PlayerFleets[i] = CustomFleet;
          gb.gui.popup("FLEET SEND!", 50);
          break;
        }
      }
      return 1;
    }
  }
  drawSendFleetConfirmation(2, canSend);
  return 0;
}

int8_t sendAttack()
{
  bool canSend = fleetPreStartCheck();
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 2;
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (canSend == true)
    {
      PlayerResources[2] -= FleetFuelCost;
      for (int i = 0; i < 4; i++)
      {
        if (PlayerFleets[i].Active == false)
        {
          PlayerShips[0] -= CustomFleet.Fighters;
          PlayerShips[1] -= CustomFleet.Interceptors;
          PlayerShips[2] -= CustomFleet.Frigates;
          PlayerShips[3] -= CustomFleet.WarCruisers;
          PlayerShips[4] -= CustomFleet.StarDreadnoughts;
          PlayerShips[5] -= CustomFleet.SolarDestroyers;
          PlayerFleets[i] = CustomFleet;
          gb.gui.popup("FLEET SEND!", 50);
          break;
        }
      }
      return 1;
    }
  }
  drawSendFleetConfirmation(1, canSend);
  return 0;
}

int8_t sendRaid()
{
  bool canSend = fleetPreStartCheck();
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 2;
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (canSend == true)
    {
      PlayerResources[2] -= FleetFuelCost;
      for (int i = 0; i < 4; i++)
      {
        if (PlayerFleets[i].Active == false)
        {
          PlayerShips[11] -= CustomFleet.Stalkers;
          PlayerShips[12] -= CustomFleet.Leviatans;
          PlayerFleets[i] = CustomFleet;
          gb.gui.popup("FLEET SEND!", 50);
          break;
        }
      }
      return 1;
    }
  }
  drawSendFleetConfirmation(4, canSend);
  return 0;
}

int8_t sendIntercept()
{
  bool canSend = fleetPreStartCheck();
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 2;
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (canSend == true)
    {
      PlayerResources[2] -= FleetFuelCost;
      for (int i = 0; i < 4; i++)
      {
        if (PlayerFleets[i].Active == false)
        {
          PlayerShips[13] -= CustomFleet.Missles;
          PlayerFleets[i] = CustomFleet;
          gb.gui.popup("FLEET SEND!", 50);
          break;
        }
      }
      return 1;
    }
  }
  drawSendFleetConfirmation(5, canSend);
}

bool fleetPreStartCheck()
{
  bool fleetSlot = false;
  for (int i = 0; i < 4; i++)
  {
    if (PlayerFleets[i].Active == false)
    {
      fleetSlot = true;
      break;
    }
  }
  bool fuelCost = false;
  if (PlayerResources[2] > FleetFuelCost)
  {
    fuelCost = true;
  }
  return fleetSlot && fuelCost;
}

