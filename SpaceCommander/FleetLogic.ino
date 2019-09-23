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

int playerFleetSelection()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
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
      checkQuantity();
      flSelectedShip=false;
    }
    else if(flSelectedShip==false && flShipSelection!=7)
    {
      flSelectedShip=true;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(flSelectedShip!=true && (CustomFleet.Fighters!=0 || CustomFleet.Interceptors!=0 || CustomFleet.Frigates!=0 || CustomFleet.WarCruisers!=0 || CustomFleet.StarDreadnoughts!=0 || CustomFleet.SolarDestroyers!=0))
    {
      return 2; 
    }
  }
  drawFleetSelection(flMarker2PosY,flSelectedShip,flQuantity);
  return 1;
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

void checkQuantity()
{
  switch(flShipSelection)
  {
    case 1:
    {
      if(CustomFleet.Fighters>PlayerShips[0])
      {
        CustomFleet.Fighters=PlayerShips[0];
      }
    }
    break;
    case 2:
    {
      if(CustomFleet.Interceptors>PlayerShips[1])
      {
        CustomFleet.Interceptors=PlayerShips[1];
      }
    }
    break;
    case 3:
    {
      if(CustomFleet.Frigates>PlayerShips[2])
      {
        CustomFleet.Frigates=PlayerShips[2];
      }
    }
    break;
    case 4:
    {
      if(CustomFleet.WarCruisers>PlayerShips[3])
      {
        CustomFleet.WarCruisers=PlayerShips[3];
      }
    }
    break;
    case 5:
    {
      if(CustomFleet.StarDreadnoughts>PlayerShips[4])
      {
        CustomFleet.StarDreadnoughts=PlayerShips[4];
      }
    }
    break;
    case 6:
    {
      if(CustomFleet.SolarDestroyers>PlayerShips[5])
      {
        CustomFleet.SolarDestroyers=PlayerShips[5];
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
      PlayerResources[2]-=FleetFuelCost;
      for(int i=0;i<5;i++)
      {
        if(PlayerFleets[i].Active==false)
        {
          PlayerShips[6]--;
          PlayerFleets[i]=CustomFleet;
          gb.gui.popup("FLEET SEND!",50);
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

bool sendColonizer()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(fleetPreStartCheck()==true)
    {
      PlayerResources[2]-=FleetFuelCost;
      for(int i=0;i<5;i++)
      {
        if(PlayerFleets[i].Active==false)
        {
          PlayerShips[7]--;
          PlayerFleets[i]=CustomFleet;
          gb.gui.popup("FLEET SEND!",50);
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
  drawSendFleetConfirmation(2);
  return false;
}

bool sendAttack()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(fleetPreStartCheck()==true)
    {
      PlayerResources[2]-=FleetFuelCost;
      for(int i=0;i<5;i++)
      {
        if(PlayerFleets[i].Active==false)
        {
          
          PlayerFleets[i]=CustomFleet;
          gb.gui.popup("FLEET SEND!",50);
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
  drawSendFleetConfirmation(1);
  return false;
}

bool fleetPreStartCheck()
{
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
  drawSpyReport(IntelligenceReports[0]);
  return 11;
}

