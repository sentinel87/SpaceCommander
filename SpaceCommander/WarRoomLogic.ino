
int CursorPosX=70;
int CursorPosY=8;

int8_t Choice=2;
int8_t Column=1;
int8_t Row=0;

int8_t SelectionArray[7][2]={
  {1,2},
  {3,4},
  {5,6},
  {7,8},
  {9,10},
  {11,12},
  {13,14}
};

int8_t warRoom(int playerResources[3])
{
  bool alert=checkVisibleFleets();
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(Row==0)
    {
      Row=6;
    }
    else
    {
      Row--;
    }
    CursorPosY=8+Row*7;
    Choice=SelectionArray[Row][Column];
    selectedChoice();
    
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(Row==6)
    {
      Row=0;
    }
    else
    {
      Row++;
    }
    CursorPosY=8+Row*7;
    Choice=SelectionArray[Row][Column];
    selectedChoice();
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(Column==0)
    {
      CursorPosX=70;
      Column=1;
    }
    else
    {
      CursorPosX=61;
      Column=0;
    }
    Choice=SelectionArray[Row][Column];
    selectedChoice();
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(Column==0)
    {
      CursorPosX=70;
      Column=1;
    }
    else
    {
      CursorPosX=61;
      Column=0;
    }
    Choice=SelectionArray[Row][Column];
    selectedChoice();
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    bool access=checkRestrictions();
    if(access==true)
    {
      return Choice; 
    }   
  }
  drawWarRoom(CursorPosX,CursorPosY,selectedChoice(),alert);
  return 0;
}

String selectedChoice()
{
  String result="";
  switch(Choice)
  {
    case 1:
      result="ACTIVE FLEETS";break;
    case 2:
      result="BUILDINGS";break;
    case 3:
      result="ENEMY FLEETS";break;
    case 4:
      result="TECHNOLOGIES";break;
    case 5:
      result="FLEET STATS";break;
    case 6:
      result="STAR MAP";break;
    case 7:
      result="REPORTS";break;
    case 8:
      result="SHIPYARD";break;
    case 9:
      result="TRANSFORM RESOURCES";break;
    case 10:
      result="INTELLIGENCE";break;
    case 11:
      result="STAR ROUTES";break;
    case 12:
      result="GAME STATS";break;
    case 13:
      result="PAUSE";break;
    case 14:
      result="SAVE GAME";break;
  }
  return result;
}

void resetWarRoomMarkers()
{
  CursorPosX=70;
  CursorPosY=8;
  Choice=2;
  Column=1;
  Row=0;
}

bool checkRestrictions()
{
  bool result=false;
  switch(Choice)
  {
    case 3:
    {
      if(Colony[5].level>0)
      {
        result=true;
      }
    }
    break;
    case 4:
    {
      if(Colony[7].level>0)
      {
        result=true;
      }
    }
    break;
    case 8:
    {
      if(Colony[6].level>0)
      {
        result=true;
      }
    }
    break;
    case 9:
    {
      if(Colony[11].level>0)
      {
        result=true;
      }
    }
    break;
    case 10:
    {
      if(Colony[4].level>0)
      {
        result=true;
      }
    }
    break;
    default:
      result=true; break;
  }
  return result;
}

bool checkVisibleFleets()
{
  bool result=false;
  for(int i=0;i<4;i++)
  {
    if(EnemyFleets[i].Visible==true)
    {
      result=true;
      break;
    }
  }
  return result;
}

