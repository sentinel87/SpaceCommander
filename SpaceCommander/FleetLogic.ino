int flMarkerPosX=1;
int flMarkerPosY=7;

int flMarker2PosY=7;

//Fleet Selection Markers
int flShipSelection=1;
bool flSelectedShip=false;
int flQuantity=10;
Fleet flCustomFleet={1,false,0,20,0,0,0,0,0,0,0};

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
    PlayerFleets[0]=flCustomFleet;
    return true;
  }
  drawFleetSelection(flMarker2PosY,flSelectedShip,flCustomFleet,flQuantity);
  return false;
}

void increaseShips()
{
  switch(flShipSelection)
  {
    case 1:
    {
      flCustomFleet.Fighters+=flQuantity;
      if(flCustomFleet.Fighters>9999)
      {
        flCustomFleet.Fighters=0;
      }
    }
    break;
    case 2:
    {
      flCustomFleet.Interceptors+=flQuantity;
      if(flCustomFleet.Interceptors>9999)
      {
        flCustomFleet.Interceptors=0;
      }
    }
    break;
    case 3:
    {
      flCustomFleet.Frigates+=flQuantity;
      if(flCustomFleet.Frigates>9999)
      {
        flCustomFleet.Frigates=0;
      }
    }
    break;
    case 4:
    {
      flCustomFleet.WarCruisers+=flQuantity;
      if(flCustomFleet.WarCruisers>9999)
      {
        flCustomFleet.WarCruisers=0;
      }
    }
    break;
    case 5:
    {
      flCustomFleet.StarDreadnoughts+=flQuantity;
      if(flCustomFleet.StarDreadnoughts>9999)
      {
        flCustomFleet.StarDreadnoughts=0;
      }
    }
    break;
    case 6:
    {
      flCustomFleet.SolarDestroyers+=flQuantity;
      if(flCustomFleet.SolarDestroyers>9999)
      {
        flCustomFleet.SolarDestroyers=0;
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
      flCustomFleet.Fighters-=flQuantity;
      if(flCustomFleet.Fighters<0)
      {
        flCustomFleet.Fighters=9999;
      }
    }
    break;
    case 2:
    {
      flCustomFleet.Interceptors-=flQuantity;
      if(flCustomFleet.Interceptors<0)
      {
        flCustomFleet.Interceptors=9999;
      }
    }
    break;
    case 3:
    {
      flCustomFleet.Frigates-=flQuantity;
      if(flCustomFleet.Frigates<0)
      {
        flCustomFleet.Frigates=9999;
      }
    }
    break;
    case 4:
    {
      flCustomFleet.WarCruisers-=flQuantity;
      if(flCustomFleet.WarCruisers<0)
      {
        flCustomFleet.WarCruisers=9999;
      }
    }
    break;
    case 5:
    {
      flCustomFleet.StarDreadnoughts-=flQuantity;
      if(flCustomFleet.StarDreadnoughts<0)
      {
        flCustomFleet.StarDreadnoughts=9999;
      }
    }
    break;
    case 6:
    {
      flCustomFleet.SolarDestroyers-=flQuantity;
      if(flCustomFleet.SolarDestroyers<0)
      {
        flCustomFleet.SolarDestroyers=9999;
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

int scoutReports()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawSpyReport(IntelligenceReports[1]);
  return 11;
}

