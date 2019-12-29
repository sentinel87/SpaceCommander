int srPages=1;

int starRoutes(int Logistics)
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(srPages!=3)
    {
      srPages++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(srPages!=1)
    {
      srPages--;
    }
  }
  drawStarRoutes(srPages);
  return 11;
}

bool setRoute()
{
  bool canSet=true;
  bool metal=true;
  bool crystal=true;
  bool fuel=true;
  if(SelectedRoute.Metal>PlayerShips[8])
  {
    metal=false;
    canSet=false;
  }
  if(SelectedRoute.Crystal>PlayerShips[9])
  {
    crystal=false;
    canSet=false;
  }
  if(SelectedRoute.Fuel>PlayerShips[10])
  {
    fuel=false;
    canSet=false;
  }
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(canSet==true)
    {
      bool freePlace=checkAvailableRoutes();
      if(freePlace==true)
      {
        PlayerShips[8]-=SelectedRoute.Metal;
        PlayerShips[9]-=SelectedRoute.Crystal;
        PlayerShips[10]-=SelectedRoute.Fuel;
        int idx=getNextFreeSlot();
        if(idx!=-1)
        {
          PlayerRoutes[idx]=SelectedRoute;
          setPlanetRouteMarker(SelectedRoute.Name);
          gb.gui.popup("ROUTE SET!",50); 
          return true;
        }
      }
      else
      {
         gb.gui.popup("NO FREE SLOT!",50); 
      }
    }
  }
  drawRouteConfirmation(SelectedRoute,canSet,metal,crystal,fuel);
  return false;
}

void setPlanetRouteMarker(String planetName)
{
  for(int i=0;i<30;i++)
  {
    if(System[i].Name==planetName)
    {
      System[i].TradeRoute=true;
      break;
    }
  }
}

bool checkAvailableRoutes()
{
  bool canSet=false;
  for(int i=0;i<TechTree[5].level;i++)
  {
    if(PlayerRoutes[i].Active==false)
    {
      canSet=true;
      break;
    }
  }

  return canSet;
}

int getNextFreeSlot()
{
  int idx=-1;
  for(int i=0;i<TechTree[5].level;i++)
  {
    if(PlayerRoutes[i].Active==false)
    {
      idx=i;
      break;
    }
  }
  return idx;
}

void refreshTradeRoutes()
{ 
  
}

