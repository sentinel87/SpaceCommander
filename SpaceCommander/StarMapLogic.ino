int posX=38;
int posY=28;

int8_t starMap(int Astronomy,Planet System[30])
{
  drawMap(Astronomy,posX,posY);
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
    if(posY!=0)
    {
      posY--;
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(posY!=56)
    {
      posY++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(posX!=0)
    {
      posX--;
    }
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(posX!=76)
    {
      posX++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    searchForPlanet(System);
  }
  else if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
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

