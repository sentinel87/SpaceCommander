int8_t shCurrentShip=0;
int shQuantity=1;
bool shSelectedShip=false;
int shQuantityToBuy=1;

int8_t shipyard(int MilitaryScience)
{
  bool canBuy=resourceCostValidation();
  String restriction=restrictionValidation(); 
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
    if(restriction=="")
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
  }
  drawShipyardScreen(Shipyard[shCurrentShip],canBuy,shSelectedShip,shQuantity,shQuantityToBuy,PlayerShips[shCurrentShip],restriction);
  return 8;
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

String restrictionValidation()
{
  String result="";
  int requiredLvl=1;
  switch(shCurrentShip)//Shipyard Level
  {
    case 0:
      requiredLvl=2; break;
    case 1:
      requiredLvl=3; break;
    case 2:
      requiredLvl=5; break;
    case 3:
      requiredLvl=6; break;
    case 4:
      requiredLvl=8; break;
    case 5:
      requiredLvl=10; break;
    case 6:
      requiredLvl=1; break;
    case 7:
      requiredLvl=3; break;
    case 8:
      requiredLvl=2; break;
    case 9:
      requiredLvl=2; break;
    case 10:
      requiredLvl=2; break;
  }
  if(Colony[6].level<requiredLvl)
  {
    result="Shipyard "+(String)requiredLvl;
    return result;
  }

  int techIdx=0;
  switch(shCurrentShip)//Tech Restrictions
  {
    case 0: //Fighters
      requiredLvl=1;
      techIdx=2; //Jet Proplusion 
      break;
    case 1: //Interceptors
      requiredLvl=1; 
      techIdx=6; //Aerodynamics
      break;
    case 2: //Frigates
      requiredLvl=1; 
      techIdx=8; //Impulse Engine
      break;
    case 3: //War Cruisers
      requiredLvl=1;
      techIdx=10; //Hyperdrive 
      break;
    case 4: //Star Dreadnoughts
      requiredLvl=10; 
      techIdx=12; //Ship Weapons 
      break;
    case 5: //Solar Destroyers
      requiredLvl=9;
      techIdx=14; //Gravity Weapon 
      break;
    case 6: //Spy bot
      requiredLvl=1; //Espionage
      techIdx=1; 
      break;
    case 7: //Colonizer
      requiredLvl=0; 
      techIdx=0; 
      break;
    case 8: //Transports
      requiredLvl=1;
      techIdx=5;   //Logistics
      break;
    case 9:
      requiredLvl=1; 
      techIdx=5; 
      break;
    case 10:
      requiredLvl=1; 
      techIdx=5; 
      break;
  }
  if(TechTree[techIdx].level<requiredLvl)
  {
    result=TechTree[techIdx].techName + " " + (String)requiredLvl;
  }
  return result;
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
    modifier=5 + (5-EnemyColonies);
  }
  else if(Difficulty=="NORMAL")
  {
    modifier=3 + (5-EnemyColonies);
  }
  else
  {
    modifier=2 + (5-EnemyColonies);
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

