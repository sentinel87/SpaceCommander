int8_t shCurrentShip=0;
int shQuantity=10;
bool shSelectedShip=false;
int shQuantityToBuy=0;

int8_t shipyard(int MilitaryScience)
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    if(shSelectedShip!=true)
    {
      return 0; 
    }
  }
  if(gb.buttons.pressed(BUTTON_A))
  {
    if(shSelectedShip==true)
    {
      shSelectedShip=false;
      shQuantityToBuy=0;
      shQuantity=10;
      gb.gui.popup("ACQUIRED!",50);
    }
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(shSelectedShip!=true)
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
    else
    {
      if(shQuantity==1)
      {
        shQuantity=10;
      }
      else if(shQuantity==10)
      {
        shQuantity=100;
      }
      else
      {
        shQuantity=1;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(shSelectedShip!=true)
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
    else
    {
      if(shQuantity==1)
      {
        shQuantity=100;
      }
      else if(shQuantity==100)
      {
        shQuantity=10;
      }
      else
      {
        shQuantity=1;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_UP))
  {
    if(shSelectedShip==true)
    {
      increaseQuantity();
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(shSelectedShip==true)
    {
      decreaseQuantity();
    }
  }
  else if(gb.buttons.pressed(BUTTON_MENU))
  {
    if(shSelectedShip==true)
    {
      shSelectedShip=false;
    }
    else
    {
      shSelectedShip=true;
    }
  }
  drawShipyardScreen(Shipyard[shCurrentShip],true,shSelectedShip,shQuantity,shQuantityToBuy);
  return 4;
}

void increaseQuantity()
{
  shQuantityToBuy+=shQuantity;
  if(shQuantityToBuy>999)
  {
    shQuantityToBuy=0;
  }
}

void decreaseQuantity()
{
  shQuantityToBuy-=shQuantity;
  if(shQuantityToBuy<0)
  {
    shQuantityToBuy=999;
  }
}

