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
        Fleet spyFleet={3,true,0,0,1,0,0,0,0,0,0};
        CustomFleet=spyFleet;
        setFleetParameters();
        return 21; //SPY MISSION CONFIRMATION
      }
      else if(stSelection==3)
      {
        return 20; //FLEET SELECTION SCREEN
      }
      //CHOICE LOGIC
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
    Speed=5;
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

