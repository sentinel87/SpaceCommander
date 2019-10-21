int stPosX=38;
int stPosY=28;

int stSelection=1;
bool stDropDownMenu=false;

int8_t starMap(int Astronomy)
{
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(stDropDownMenu==true)
    {
      if(stSelection!=1)
      {
        stSelection--;
      }
      else
      {
        stSelection=4;
      }
    }
    else
    {
      if(stPosY!=0)
      {
        stPosY--;
        selectedPlanet();
      } 
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(stDropDownMenu==true)
    {
      if(stSelection!=4)
      {
        stSelection++;
      }
      else
      {
        stSelection=1;
      }
    }
    else
    {
      if(stPosY!=56)
      {
        stPosY++;
        selectedPlanet();
      } 
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(stDropDownMenu==false)
    {
      if(stPosX!=0)
      {
        stPosX--;
        selectedPlanet();
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(stDropDownMenu==false)
    {
      if(stPosX!=76)
      {
        stPosX++;
        selectedPlanet();
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(stDropDownMenu==true)
    {
      stDropDownMenu=false;
      if(stSelection==1)
      {
        Fleet spyFleet={3,true,0,0,1,0,0,0,0,0,0,0,SelectedPlanet.Name,true};
        CustomFleet=spyFleet;
        setFleetParameters();
        return 21; //SPY MISSION CONFIRMATION
      }
      else if(stSelection==2)
      {
        Fleet colonizationFleet={2,true,0,0,0,1,0,0,0,0,0,0,SelectedPlanet.Name,true};
        CustomFleet=colonizationFleet;
        setFleetParameters();
        return 22; //COLONIZATION MISSION CONFIRMATION
      }
      else if(stSelection==3)
      {
        Fleet attackFleet={1,true,0,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true};
        CustomFleet=attackFleet;
        return 20; //FLEET SELECTION SCREEN
      }
      else if(stSelection==4)
      {
        TradeRoute route={true,SelectedPlanet.Name,SelectedPlanet.Resource1,SelectedPlanet.Resource2,SelectedPlanet.Resource3};
        SelectedRoute=route;
        return 23; //TRADE ROUTE CONFIRMATION
      }
    }
    else
    {
      if(SelectedPlanet.Name!="")
      {
        stDropDownMenu=true;
        stSelection=1; 
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_B))
  {
    if(stDropDownMenu==true)
    {
      stDropDownMenu=false;
    }
    else
    {
      stSelection=1;
      return 0;
    }
  }
  drawMap(Astronomy,stPosX,stPosY);
  drawPlanetsColors();
  if(stDropDownMenu==true)
  {
    drawDropdownMenu(stPosX,stPosY,stSelection);
  }
  gb.display.setCursor(10, 5);
  gb.display.setFontSize(1);
  gb.display.setColor(RED);
  gb.display.println(gb.getCpuLoad());
  gb.display.setCursor(10, 12);
  gb.display.println(gb.getFreeRam());
  //gb.display.setCursor(10, 19);
  //gb.display.println(Astronomy);
  return 3;
}

void selectedPlanet()
{
  for(int i=0;i<30;i++)
  {
    if(System[i].posX==stPosX && System[i].posY==stPosY && System[i].Discovered==true)
    {
      SelectedPlanet=System[i];
      return;
    }
  }
  SelectedPlanet={false,"",0,0,false,"None",0,0,0,false,false,-1,false};
}

void setFleetParameters()
{
  FleetFuelCost=0;
  int Speed=0; //in seconds per 1 unit 
  //Calculate distance
  int distance=0;
  if(SelectedPlanet.posX<38)
  {
    distance+=38-SelectedPlanet.posX;
  }
  else
  {
    distance+=SelectedPlanet.posX-38;
  }
  if(SelectedPlanet.posY<28)
  {
    distance+=28-SelectedPlanet.posY;
  }
  else
  {
    distance+=SelectedPlanet.posY-28;
  }
  //Calculate fuel cost
  if(CustomFleet.SpyBots>0)
  {
    FleetFuelCost+=CustomFleet.SpyBots*(30-TechTree[2].level); //Jet Proplusion decrease cost
    Speed=2;
  }
  if(CustomFleet.Colonizers>0)
  {
    FleetFuelCost+=CustomFleet.Colonizers*(300-(TechTree[2].level*2)); //Jet Proplusion decrease cost
    Speed=5;
  }
  if(CustomFleet.Fighters>0)
  {
    FleetFuelCost+=CustomFleet.Fighters;
    Speed=13;
  }
  if(CustomFleet.Interceptors>0)
  {
    FleetFuelCost+=CustomFleet.Interceptors*5;
    Speed=15;
  }
  if(CustomFleet.Frigates>0)
  {
    FleetFuelCost+=CustomFleet.Frigates*10;
    Speed=17;
  }
  if(CustomFleet.WarCruisers>0)
  {
    FleetFuelCost+=CustomFleet.WarCruisers*20;
    if(Speed>10 || Speed==0)
    {
      Speed=10; 
    }
  }
  if(CustomFleet.StarDreadnoughts>0)
  {
    FleetFuelCost+=CustomFleet.StarDreadnoughts*40;
    if(Speed>8 || Speed==0)
    {
      Speed=8; 
    }
  }
  //Calculate minutes and seconds (1 unit - speed)
  int totalSeconds=distance*Speed;
  if(totalSeconds>59) //at least 1 minute
  {
    int minutes=totalSeconds/60;
    int seconds=totalSeconds-(minutes*60);
    CustomFleet.Seconds=seconds;
    CustomFleet.Minutes=minutes;
  }
  else
  {
    CustomFleet.Seconds=totalSeconds;
  }
}

void setFleetReturnParameters(int index)
{
  Planet StartPlanet={false,"none",0,0,false,"Player",0,0,0,false,false,-1,false};
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==PlayerFleets[index].DestinationName)
    {
      StartPlanet=System[i];
      break;
    } 
  }
  int Speed=0; //in seconds per 1 unit 
  //Calculate distance
  int distance=0;
  if(StartPlanet.posX<38)
  {
    distance+=38-StartPlanet.posX;
  }
  else
  {
    distance+=StartPlanet.posX-38;
  }
  if(SelectedPlanet.posY<28)
  {
    distance+=28-StartPlanet.posY;
  }
  else
  {
    distance+=StartPlanet.posY-28;
  }
  //Calculate max speed
  if(PlayerFleets[index].Fighters>0)
  {
    Speed=13;
  }
  if(PlayerFleets[index].Interceptors>0)
  {
    Speed=15;
  }
  if(PlayerFleets[index].Frigates>0)
  {
    Speed=17;
  }
  if(PlayerFleets[index].WarCruisers>0)
  {
    if(Speed>10 || Speed==0)
    {
      Speed=10; 
    }
  }
  if(PlayerFleets[index].StarDreadnoughts>0)
  {
    if(Speed>8 || Speed==0)
    {
      Speed=8; 
    }
  }
  //Calculate minutes and seconds (1 unit - speed)
  int totalSeconds=distance*Speed;
  if(totalSeconds>59) //at least 1 minute
  {
    int minutes=totalSeconds/60;
    int seconds=totalSeconds-(minutes*60);
    PlayerFleets[index].Seconds=seconds;
    PlayerFleets[index].Minutes=minutes;
  }
  else
  {
    PlayerFleets[index].Seconds=totalSeconds;
  }
  PlayerFleets[index].Type=5; //set returning fleet
}
