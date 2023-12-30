int wrPosX = 70;
int wrPosY = 8;

int8_t wrSelectedChoice = 2;
int8_t wrColumn = 1;
int8_t wrRow = 0;

int8_t SelectionArray[7][2] = {
  {1, 2},
  {3, 4},
  {5, 6},
  {7, 8},
  {9, 10},
  {11, 12},
  {13, 14}
};

int8_t warRoom(int playerResources[3])
{
  bool alert = checkVisibleFleets();
  if (gb.buttons.pressed(BUTTON_UP))
  {
    if (wrRow == 0)
    {
      wrRow = 6;
    }
    else
    {
      wrRow--;
    }
    wrPosY = 8 + wrRow * 7;
    wrSelectedChoice = SelectionArray[wrRow][wrColumn];
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    if (wrRow == 6)
    {
      wrRow = 0;
    }
    else
    {
      wrRow++;
    }
    wrPosY = 8 + wrRow * 7;
    wrSelectedChoice = SelectionArray[wrRow][wrColumn];
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (wrColumn == 0)
    {
      wrPosX = 70;
      wrColumn = 1;
    }
    else
    {
      wrPosX = 61;
      wrColumn = 0;
    }
    wrSelectedChoice = SelectionArray[wrRow][wrColumn];
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (wrColumn == 0)
    {
      wrPosX = 70;
      wrColumn = 1;
    }
    else
    {
      wrPosX = 61;
      wrColumn = 0;
    }
    wrSelectedChoice = SelectionArray[wrRow][wrColumn];
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    bool access = checkRestrictions();
    if (access == true)
    {
      if (wrSelectedChoice == 14) //SAVE
      {
        saveGame();
        return 0;
      }
      return wrSelectedChoice; 
    }   
  }
  drawWarRoom(wrPosX, wrPosY, getChoiceName(), alert);
  return 0;
}

String getChoiceName()
{
  String result = "";
  switch (wrSelectedChoice)
  {
    case 1:
      result = "ACTIVE FLEETS"; break;
    case 2:
      result = "BUILDINGS"; break;
    case 3:
      result = "ENEMY FLEETS"; break;
    case 4:
      result = "TECHNOLOGIES"; break;
    case 5:
      result = "FLEET STATS"; break;
    case 6:
      result = "STAR MAP"; break;
    case 7:
      result = "REPORTS"; break;
    case 8:
      result = "SHIPYARD"; break;
    case 9:
      result = "TRANSFORM RESOURCES"; break;
    case 10:
      result = "INTELLIGENCE"; break;
    case 11:
      result = "STAR ROUTES"; break;
    case 12:
      result = "MARKET"; break;
    case 13:
      result = "PAUSE"; break;
    case 14:
      result = "SAVE GAME"; break;
  }
  return result;
}

void resetWarRoomMarkers()
{
  wrPosX = 70;
  wrPosY = 8;
  wrSelectedChoice = 2;
  wrColumn = 1;
  wrRow = 0;
}

bool checkRestrictions()
{
  bool result = false;
  switch (wrSelectedChoice)
  {
    case 3:
    {
      if (Colony[5].level > 0)
      {
        result = true;
      }
    }
    break;
    case 4:
    {
      if (Colony[7].level > 0)
      {
        result = true;
      }
    }
    break;
    case 8:
    {
      if (Colony[6].level > 0)
      {
        result = true;
      }
    }
    break;
    case 9:
    {
      if (Colony[11].level > 0)
      {
        result = true;
      }
    }
    break;
    case 10:
    {
      if (Colony[4].level > 0)
      {
        result = true;
      }
    }
    break;
    case 12:
    {
      if (Colony[13].level > 0)
      {
        result = true;
      }
    }
    break;
    default:
      result = true; break;
  }
  return result;
}

bool checkVisibleFleets()
{
  bool result = false;
  for (int i = 0; i < 4; i++)
  {
    if (EnemyFleets[i].Visible == true)
    {
      result = true;
      break;
    }
  }
  return result;
}

int8_t debug()
{
  drawDebug();
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 0;    
  }
  return 15;
}

