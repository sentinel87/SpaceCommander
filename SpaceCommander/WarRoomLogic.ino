
int CursorPosX=70;
int CursorPosY=8;

int8_t Choice=1;
int8_t Column=2;

int8_t warRoom(int playerResources[3])
{
  drawWarRoom(CursorPosX,CursorPosY,selectedChoice(),playerResources);
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(Column==2)
    {
     if(CursorPosY==8)
     {
        Choice=7;
        CursorPosY=50; 
     }
     else
     {
        Choice--;
        CursorPosY-=7;
     } 
    }
    else
    {
      if(CursorPosY==8)
      {
        Choice=9;
        CursorPosY=15; 
      }
      else
      {
        Choice--;
        CursorPosY-=7;
      } 
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(Column==2)
    {
      if(CursorPosY==50)
      {
        Choice=1;
        CursorPosY=8;
      }
      else
      {
        Choice++;
        CursorPosY+=7;
      } 
    }
    else
    {
      if(CursorPosY==15)
      {
        Choice=8;
        CursorPosY=8;
      }
      else
      {
        Choice++;
        CursorPosY+=7;
      } 
    }
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(Column==2)
    {
      CursorPosY=8;
      Choice=8;
      CursorPosX=61;
      Column=1;
    }
    else
    {
      Choice=1;
      CursorPosY=8;
      CursorPosX=70;
      Column=2;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(Column==2)
    {
      CursorPosY=8;
      Choice=8;
      CursorPosX=61;
      Column=1;
    }
    else
    {
      Choice=1;
      CursorPosY=8;
      CursorPosX=70;
      Column=2;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    return Choice;   
  }
  return 0;
}

String selectedChoice()
{
  String result="";
  switch(Choice)
  {
    case 1:
      result="BUILDINGS";break;
    case 2:
      result="TECHNOLOGIES";break;
    case 3:
      result="STAR MAP";break;
    case 4:
      result="SHIPYARD";break;
    case 5:
      result="INTELLIGENCE";break;
    case 6:
      result="STAR ROUTES";break;
    case 7:
      result="SAVE GAME";break;
    case 8:
      result="ACTIVE FLEETS";break;
    case 9:
      result="ENEMY FLEETS";break;
  }
  return result;
}

