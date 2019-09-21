int flMarkerPosX=1;
int flMarkerPosY=7;

int flMarker2PosY=7;

//Fleet Selection Markers
int flShipSelection=1;
bool flSelectedShip=false;
int flQuantity=10;

//Report
int flReportPage=1;

int playerFleets()
{
  drawPlayerFleets(flMarkerPosX,flMarkerPosY);
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 8;
}

int enemyFleets()
{
  drawEnemyFleets(flMarkerPosX,flMarkerPosY);
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 9;
}

int playerFleetStats()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawFleetStats();
  return 10;
}

bool playerFleetSelection()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  else if(gb.buttons.pressed(BUTTON_UP))
  {
    if(flSelectedShip==true)
    {
      increaseShips();
    }
    else
    {
      if(flShipSelection==1)
      {
        flShipSelection=7;
        flMarker2PosY=55;
      }
      else
      {
        flShipSelection-=1;
        flMarker2PosY-=8;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(flSelectedShip==true)
    {
      decreaseShips();
    }
    else
    {
      if(flShipSelection==7)
      {
        flShipSelection=1;
        flMarker2PosY=7;
      }
      else
      {
        flShipSelection+=1;
        flMarker2PosY+=8;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(flSelectedShip==true)
    {
      if(flQuantity==1)
      {
        flQuantity=10;
      }
      else if(flQuantity==10)
      {
        flQuantity=100;
      }
      else if(flQuantity==100)
      {
        flQuantity=1000;
      }
      else
      {
        flQuantity=1;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(flSelectedShip==true)
    {
      if(flQuantity==1)
      {
        flQuantity=1000;
      }
      else if(flQuantity==10)
      {
        flQuantity=1;
      }
      else if(flQuantity==100)
      {
        flQuantity=10;
      }
      else
      {
        flQuantity=100;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_MENU))
  {
    if(flSelectedShip==true)
    {
      flSelectedShip=false;
    }
    else if(flSelectedShip==false && flShipSelection!=7)
    {
      flSelectedShip=true;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    PlayerFleets[0]=CustomFleet;
    return true;
  }
  drawFleetSelection(flMarker2PosY,flSelectedShip,flQuantity);
  return false;
}

void increaseShips()
{
  switch(flShipSelection)
  {
    case 1:
    {
      CustomFleet.Fighters+=flQuantity;
      if(CustomFleet.Fighters>9999)
      {
        CustomFleet.Fighters=0;
      }
    }
    break;
    case 2:
    {
      CustomFleet.Interceptors+=flQuantity;
      if(CustomFleet.Interceptors>9999)
      {
        CustomFleet.Interceptors=0;
      }
    }
    break;
    case 3:
    {
      CustomFleet.Frigates+=flQuantity;
      if(CustomFleet.Frigates>9999)
      {
        CustomFleet.Frigates=0;
      }
    }
    break;
    case 4:
    {
      CustomFleet.WarCruisers+=flQuantity;
      if(CustomFleet.WarCruisers>9999)
      {
        CustomFleet.WarCruisers=0;
      }
    }
    break;
    case 5:
    {
      CustomFleet.StarDreadnoughts+=flQuantity;
      if(CustomFleet.StarDreadnoughts>9999)
      {
        CustomFleet.StarDreadnoughts=0;
      }
    }
    break;
    case 6:
    {
      CustomFleet.SolarDestroyers+=flQuantity;
      if(CustomFleet.SolarDestroyers>9999)
      {
        CustomFleet.SolarDestroyers=0;
      }
    }
    break;
  }
}

void decreaseShips()
{
  switch(flShipSelection)
  {
    case 1:
    {
      CustomFleet.Fighters-=flQuantity;
      if(CustomFleet.Fighters<0)
      {
        CustomFleet.Fighters=9999;
      }
    }
    break;
    case 2:
    {
      CustomFleet.Interceptors-=flQuantity;
      if(CustomFleet.Interceptors<0)
      {
        CustomFleet.Interceptors=9999;
      }
    }
    break;
    case 3:
    {
      CustomFleet.Frigates-=flQuantity;
      if(CustomFleet.Frigates<0)
      {
        CustomFleet.Frigates=9999;
      }
    }
    break;
    case 4:
    {
      CustomFleet.WarCruisers-=flQuantity;
      if(CustomFleet.WarCruisers<0)
      {
        CustomFleet.WarCruisers=9999;
      }
    }
    break;
    case 5:
    {
      CustomFleet.StarDreadnoughts-=flQuantity;
      if(CustomFleet.StarDreadnoughts<0)
      {
        CustomFleet.StarDreadnoughts=9999;
      }
    }
    break;
    case 6:
    {
      CustomFleet.SolarDestroyers-=flQuantity;
      if(CustomFleet.SolarDestroyers<0)
      {
        CustomFleet.SolarDestroyers=9999;
      }
    }
    break;
  }
}

bool battleResults()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(flReportPage==1)
    {
      flReportPage=2;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(flReportPage==2)
    {
      flReportPage=1;
    }
  }

  if(flReportPage==1)
  {
    drawBattleResult1();
  }
  else
  {
    drawBattleResult2();
  }
  return false;
}

bool sendSpy()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(fleetPreStartCheck()==true)
    {
      PlayerResources[2]-=20;
      for(int i=0;i<5;i++)
      {
        if(PlayerFleets[i].Active==false)
        {
          PlayerShips[6]--;
          PlayerFleets[i]=CustomFleet;
          break;
        }
      }
      return true;
    }
    else
    {
      return false; 
    }
  }
  drawSendFleetConfirmation(3);
  return false;
}

bool fleetPreStartCheck()
{
  if(PlayerShips[6]==0)
  {
    return false;
  }
  bool fleetSlot=false;
  for(int i=0;i<5;i++)
  {
    if(PlayerFleets[i].Active==false)
    {
      fleetSlot=true;
      break;
    }
  }
  bool fuelCost=false;
  if(PlayerResources[2]>FleetFuelCost)
  {
    fuelCost=true;
  }
  return fleetSlot && fuelCost;
}

int scoutReports()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawSpyReport(IntelligenceReports[1]);
  return 11;
}

