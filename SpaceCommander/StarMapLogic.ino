int posX=38;
int posY=28;

int selection=1;
bool dropDownMenu=false;

int8_t starMap(int Astronomy,Planet System[30])
{
  drawMap(Astronomy,posX,posY);
  if(dropDownMenu==true)
  {
    drawDropdownMenu(posX,posY,selection);
  }
  gb.display.setCursor(10, 5);
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.println(gb.getCpuLoad());
  gb.display.setCursor(10, 12);
  gb.display.println(gb.getFreeRam());
  gb.display.setCursor(10, 19);
  gb.display.println(Astronomy);
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(dropDownMenu==true)
    {
      if(selection!=1)
      {
        selection--;
      }
      else
      {
        selection=4;
      }
    }
    else
    {
      if(posY!=0)
      {
        posY--;
      } 
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(dropDownMenu==true)
    {
      if(selection!=4)
      {
        selection++;
      }
      else
      {
        selection=1;
      }
    }
    else
    {
      if(posY!=56)
      {
        posY++;
      } 
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(dropDownMenu==false)
    {
      if(posX!=0)
      {
        posX--;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(dropDownMenu==false)
    {
      if(posX!=76)
      {
        posX++;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    searchForPlanet(System);
    if(dropDownMenu==true)
    {
      dropDownMenu=false;
      if(selection==3)
      {
        return 20; //FLEET SELECTION SCREEN
      }
      //CHOICE LOGIC
    }
    else
    {
      dropDownMenu=true;
      selection=1;
    }
  }
  else if(gb.buttons.pressed(BUTTON_B))
  {
    if(dropDownMenu==true)
    {
      dropDownMenu=false;
    }
    else
    {
      selection=1;
      return 0;
    }
  }

  return 3;
}

void searchForPlanet(Planet System[30])
{
  for(int i=0;i<30;i++)
  {
    if((posX==System[i].posX) && (posY==System[i].posY))
    {
      gb.display.setCursor(10, 28);
      gb.display.println(System[i].Name);
      break;
    }
  }
}

