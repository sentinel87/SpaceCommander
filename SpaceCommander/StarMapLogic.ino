int stPosX=38;
int stPosY=28;

int stSelection=1;
bool stDropDownMenu=false;

int8_t starMap(int Astronomy,Planet System[30])
{
  if(gb.buttons.repeat(BUTTON_UP,0))
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
      } 
    }
  }
  else if(gb.buttons.repeat(BUTTON_DOWN,0))
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
      } 
    }
  }
  else if(gb.buttons.repeat(BUTTON_LEFT,0))
  {
    if(stDropDownMenu==false)
    {
      if(stPosX!=0)
      {
        stPosX--;
      }
    }
  }
  else if(gb.buttons.repeat(BUTTON_RIGHT,0))
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
      if(stSelection==3)
      {
        return 20; //FLEET SELECTION SCREEN
      }
      //CHOICE LOGIC
    }
    else
    {
      stDropDownMenu=true;
      stSelection=1;
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
  drawPlanetsColors(System);
  if(stDropDownMenu==true)
  {
    drawDropdownMenu(stPosX,stPosY,stSelection);
  }
  gb.display.setCursor(10, 5);
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.println(gb.getCpuLoad());
  gb.display.setCursor(10, 12);
  gb.display.println(gb.getFreeRam());
  //gb.display.setCursor(10, 19);
  //gb.display.println(Astronomy);
  return 3;
}

