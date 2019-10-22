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
  return 6;
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
      PlayerShips[8]-=SelectedRoute.Metal;
      PlayerShips[9]-=SelectedRoute.Crystal;
      PlayerShips[10]-=SelectedRoute.Fuel;
      PlayerRoutes[0]=SelectedRoute;
      gb.gui.popup("ROUTE SET!",50); 
      return true; 
    }
  }
  drawRouteConfirmation(SelectedRoute,canSet,metal,crystal,fuel);
  return false;
}

