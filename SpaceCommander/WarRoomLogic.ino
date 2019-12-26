
int CursorPosX=70;
int CursorPosY=8;

int8_t Choice=2;
int8_t Column=1;
int8_t Row=0;

int8_t SelectionArray[6][2]={
  {1,2},
  {3,4},
  {5,6},
  {7,8},
  {9,10},
  {11,12}
};

int8_t warRoom(int playerResources[3])
{
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(Row==0)
    {
      Row=5;
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
    if(Row==5)
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
  drawWarRoom(CursorPosX,CursorPosY,selectedChoice());
  return 0;
}

String selectedChoice()
{
  String result="";
  switch(Choice)
  {
    case 2:
      result="BUILDINGS";break;
    case 4:
      result="TECHNOLOGIES";break;
    case 6:
      result="STAR MAP";break;
    case 8:
      result="SHIPYARD";break;
    case 10:
      result="INTELLIGENCE";break;
    case 11:
      result="STAR ROUTES";break;
    case 12:
      result="SAVE GAME";break;
    case 1:
      result="ACTIVE FLEETS";break;
    case 3:
      result="ENEMY FLEETS";break;
    case 5:
      result="FLEET STATS";break;
    case 7:
      result="REPORTS";break;
    case 9:
      result="TRANSFORM RESOURCES";break;
  }
  return result;
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

