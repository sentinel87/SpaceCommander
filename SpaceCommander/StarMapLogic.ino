int stPosX=38;
int stPosY=28;

int stIndex=0;
int stSelection=1;
bool stDropDownMenu=false;
int stEnabled[]={1,0,0,0,0};

int8_t starMap(int Astronomy)
{
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(stDropDownMenu==true)
    {
      getPreviousChoice();   
    }
    else
    {
      if(stPosY!=0)
      {
        stPosY--;
      } 
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(stDropDownMenu==true)
    {
      getNextChoice();
    }
    else
    {
      if(stPosY!=56)
      {
        stPosY++;
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
        if(PlayerShips[6]>0)
        {
          Fleet spyFleet={3,true,0,0,1,0,0,0,0,0,0,0,SelectedPlanet.Name,true};
          CustomFleet=spyFleet;
          setFleetParameters();
          return 21; //SPY MISSION CONFIRMATION
        }
        else
        {
          gb.gui.popup("NO SPY BOTS!",50);
        }
      }
      else if(stSelection==2)
      {
        if(PlayerShips[7]>0)
        {
          Fleet colonizationFleet={2,true,0,0,0,1,0,0,0,0,0,0,SelectedPlanet.Name,true};
          CustomFleet=colonizationFleet;
          setFleetParameters();
          return 22; //COLONIZATION MISSION CONFIRMATION
        }
        else
        {
          gb.gui.popup("NO COLONIZERS!",50);
        }
      }
      else if(stSelection==3)
      {
        if(SelectedPlanet.Name=="Cligg Prime") //Check Capital condition
        {
          if(EnemyColonies>0)
          {
            gb.gui.popup("NOT ALL COLONIES DESTROYED!",50);
          }
          else
          {
            Fleet attackFleet={1,true,0,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true};
            CustomFleet=attackFleet;
            setFleetParameters();
            return 20; //FLEET SELECTION SCREEN
          }
        }
        else
        {
          Fleet attackFleet={1,true,0,0,0,0,0,0,0,0,0,0,SelectedPlanet.Name,true};
          CustomFleet=attackFleet;
          setFleetParameters();
          return 20; //FLEET SELECTION SCREEN
        }
      }
      else if(stSelection==4)
      {
        TradeRoute route={true,SelectedPlanet.Name,SelectedPlanet.Resource1,SelectedPlanet.Resource2,SelectedPlanet.Resource3};
        SelectedRoute=route;
        return 23; //TRADE ROUTE CONFIRMATION
      }
      else if(stSelection==5)
      {
        abandonPlanet();
      }
    }
    else
    {
      selectedPlanet();
      if(SelectedPlanet.Name!="" && SelectedPlanet.Name!="Earth")
      {
        stDropDownMenu=true;
        bool activeChoices=buildDropdownMenu();
        if(activeChoices==true)
        {
          stSelection=1;  
        }
        else
        {
          stSelection=-1; 
        }
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
    drawDropdownMenu(stPosX,stPosY,stSelection,stEnabled);
  }
  //gb.display.setCursor(10, 5);
  //gb.display.setFontSize(1);
  //gb.display.setColor(RED);
  //gb.display.println(gb.getCpuLoad());
  //gb.display.setCursor(10, 12);
  //gb.display.println(gb.getFreeRam());
  //gb.display.setCursor(10, 19);
  //gb.display.println(Astronomy);
  return 6;
}

bool buildDropdownMenu()
{
  bool IsFleetSlot=checkFleetSlots();
  if(IsFleetSlot==true) //If Player Fleet Slot is available
  {
    if(SelectedPlanet.ActiveMission==true) //If planet has active mission
    {
      stEnabled[0]=0;
      stEnabled[1]=0;
      stEnabled[2]=0;
      stEnabled[3]=0;
      stEnabled[4]=0;
      return false;
    }
    if(SelectedPlanet.Hostile==true)
    {
      stEnabled[0]=1;
      stEnabled[1]=0;
      stEnabled[2]=1;
      stEnabled[3]=0;
      stEnabled[4]=0;
      return true;
    }
    else if(SelectedPlanet.Owned==false)
    {
      stEnabled[0]=1;
      stEnabled[1]=1;
      stEnabled[2]=0;
      stEnabled[3]=0;
      stEnabled[4]=0;
      return true;
    }
    else if(SelectedPlanet.TradeRoute==false)
    {
      stEnabled[0]=1;
      stEnabled[1]=0;
      stEnabled[2]=0;
      stEnabled[3]=1;
      stEnabled[4]=1;
      return true;
    }
    else
    {
      stEnabled[0]=1;
      stEnabled[1]=0;
      stEnabled[2]=0;
      stEnabled[3]=0;
      stEnabled[4]=1;
      return true;
    }
  }
  else
  {
    stEnabled[0]=0;
    stEnabled[1]=0;
    stEnabled[2]=0;
    stEnabled[3]=0;
    stEnabled[4]=0;
    return false;
  }
}

void abandonPlanet()
{
  if(SelectedPlanet.TradeRoute==true)
  {
    for(int i=0;i<12;i++) //Remove trade route
    {
      if(PlayerRoutes[i].Name==SelectedPlanet.Name)
      {
        TradeRoute route={false,"",0,0,0};
        PlayerRoutes[i]=route;
        break;
      }
    }
    refreshTradeRoutes();
  }
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==SelectedPlanet.Name)
    {
      System[i].Owned=false;
      System[i].TradeRoute=false;
      SelectedPlanet=System[i];
      gb.gui.popup("PLANET ABANDONED!",50);
      break;
    }
  }
}

void getNextChoice()
{
  if(SelectedPlanet.ActiveMission==false)
  {
    for(int i=1;i<=5;i++)
    {
      if((i>(stSelection))&& stEnabled[i-1]==1)
      {
        stSelection=i;
        return;
      }
    }
    stSelection=1; 
  }
  else
  {
    stSelection=-1;
  }
}

void getPreviousChoice()
{
  if(SelectedPlanet.ActiveMission==false)
  {
    for(int i=5;i>=0;i--)
    {
      if((i<(stSelection))&& stEnabled[i-1]==1)
      {
        stSelection=i;
        return;
      }
    }
    for(int i=5;i>=0;i--)
    {
      if(stEnabled[i-1]==1)
      {
        stSelection=i;
        return;
      }
    }
  }
  else
  {
    stSelection=-1;
  }
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
    FleetFuelCost+=CustomFleet.Fighters*2;
    Speed=33-TechTree[2].level;
  }
  if(CustomFleet.Interceptors>0)
  {
    FleetFuelCost+=CustomFleet.Interceptors*5;
    int Sp=27-TechTree[6].level;
    if(Sp<Speed || Speed==0)
    {
      Speed=Sp;
    }
  }
  if(CustomFleet.Frigates>0)
  {
    FleetFuelCost+=CustomFleet.Frigates*12;
    int Sp=21-TechTree[8].level;
    if(Sp<Speed || Speed==0)
    {
      Speed=Sp;
    }
  }
  if(CustomFleet.WarCruisers>0)
  {
    FleetFuelCost+=CustomFleet.WarCruisers*25;
    int Sp=15-TechTree[10].level;
    if(Sp<Speed || Speed==0)
    {
      Speed=Sp;
    }
  }
  if(CustomFleet.StarDreadnoughts>0)
  {
    FleetFuelCost+=CustomFleet.StarDreadnoughts*50;
    if(Speed>2 || Speed==0)
    {
      Speed=2; 
    }
  }
  if(CustomFleet.SolarDestroyers>0)
  {
    FleetFuelCost+=CustomFleet.SolarDestroyers*100;
    if(Speed>1 || Speed==0)
    {
      Speed=1; 
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
  if(StartPlanet.posY<28)
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
    Speed=33-TechTree[2].level;
  }
  if(PlayerFleets[index].Interceptors>0)
  {
    int Sp=27-TechTree[6].level;
    if(Sp<Speed || Speed==0)
    {
      Speed=Sp;
    }
  }
  if(PlayerFleets[index].Frigates>0)
  {
    int Sp=21-TechTree[8].level;
    if(Sp<Speed || Speed==0)
    {
      Speed=Sp;
    }
  }
  if(PlayerFleets[index].WarCruisers>0)
  {
    int Sp=15-TechTree[10].level;
    if(Sp<Speed || Speed==0)
    {
      Speed=Sp;
    }
  }
  if(PlayerFleets[index].StarDreadnoughts>0)
  {
    if(Speed>2 || Speed==0)
    {
      Speed=2; 
    }
  }
  if(PlayerFleets[index].SolarDestroyers>0)
  {
    if(Speed>1 || Speed==0)
    {
      Speed=1; 
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

bool checkFleetSlots()
{
  for(int i=0;i<4;i++)
  {
    if(PlayerFleets[i].Active==false)
    {
      return true;
    }
  }
  return false;
}

