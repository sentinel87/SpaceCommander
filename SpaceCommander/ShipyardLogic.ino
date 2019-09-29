int8_t shCurrentShip=0;

int8_t shipyard(int MilitaryScience)
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(shCurrentShip==10)
    {
      shCurrentShip=0;
    }
    else
    {
      shCurrentShip++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(shCurrentShip==0)
    {
      shCurrentShip=10;
    }
    else
    {
      shCurrentShip--;
    }
  }
  drawShipyardScreen(Shipyard[shCurrentShip],true);
  return 4;
}

