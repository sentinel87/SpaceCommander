int8_t shCurrentShip=0;
int shQuantity=1;
bool shSelectedShip=false;
int shQuantityToBuy=1;

int8_t shipyard(int MilitaryScience)
{
  bool canBuy=resourceCostValidation();
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
      if(canBuy==true)
      {
        buySelectedShipQuantity();
        shSelectedShip=false;
        shQuantityToBuy=1; 
      }
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
      shQuantity=1;
      shQuantityToBuy=1;
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
      shQuantity=1;
      shQuantityToBuy=1; 
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
  drawShipyardScreen(Shipyard[shCurrentShip],canBuy,shSelectedShip,shQuantity,shQuantityToBuy,PlayerShips[shCurrentShip]);
  return 4;
}

bool resourceCostValidation()
{
  if(((Shipyard[shCurrentShip].resource1Cost)*shQuantityToBuy)>PlayerResources[0])
  {
    return false;
  }
  if(((Shipyard[shCurrentShip].resource2Cost)*shQuantityToBuy)>PlayerResources[1])
  {
    return false;
  }
  return true;
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

void buySelectedShipQuantity()
{
  int fixedQuantity=shQuantityToBuy;
  if(PlayerShips[shCurrentShip]+shQuantityToBuy>9999)
  {
    fixedQuantity=9999-PlayerShips[shCurrentShip];
  }
  PlayerResources[0]-=((Shipyard[shCurrentShip].resource1Cost)*fixedQuantity);
  PlayerResources[1]-=((Shipyard[shCurrentShip].resource2Cost)*fixedQuantity);
  PlayerShips[shCurrentShip]+=fixedQuantity;
  if(shCurrentShip<=4)
  {
    fillGarrisons();
  }
  gb.gui.popup("ACQUIRED!",50); 
}

void fillGarrisons()
{
  int modifier=0;
  if(Difficulty=="EASY")
  {
    modifier=4;
  }
  else if(Difficulty=="NORMAL")
  {
    modifier=2;
  }
  else
  {
    modifier=1;
  }
  int toDistribute=shQuantityToBuy/modifier;
  for(int i=0;i<6;i++)
  {
    switch(shCurrentShip)
    {
      case 0:
      {
        if((Enemy1Garrison[i].Fighters+toDistribute)!=9999)
        {
          Enemy1Garrison[i].Fighters+=toDistribute; 
        }
        break;
      }
      case 1:
      {
        if((Enemy1Garrison[i].Interceptors+toDistribute)!=9999)
        {
          Enemy1Garrison[i].Interceptors+=toDistribute; 
        }
        break;
      }
      case 2:
      {
        if((Enemy1Garrison[i].Frigates+toDistribute)!=9999)
        {
          Enemy1Garrison[i].Frigates+=toDistribute; 
        }
        break;
      }
      case 3:
      {
        if((Enemy1Garrison[i].WarCruisers+toDistribute)!=9999)
        {
          Enemy1Garrison[i].WarCruisers+=toDistribute; 
        }
        break;
      }
      case 4:
      {
        if((Enemy1Garrison[i].StarDreadnoughts+toDistribute)!=9999)
        {
          Enemy1Garrison[i].StarDreadnoughts+=toDistribute; 
        }
        break;
      }
    }
  }
}

