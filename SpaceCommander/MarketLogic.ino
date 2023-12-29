int8_t maCurrentGood=0;

int8_t market()
{
  int metal = 3 + Colony[1].level*3; //Metal Mine
  int crystal = 3 + Colony[2].level*2; //Crystal Mine
  int fuel = 2 + Colony[3].level*2; //Fuel Refinery

  for(int i=0;i<12;i++)
  {
    metal+=PlayerRoutes[i].Metal + Colony[12].level;
    crystal+=PlayerRoutes[i].Crystal + Colony[12].level;
    fuel+=PlayerRoutes[i].Fuel + Colony[12].level;
  }
  String choice=getCommodityInfo();
  drawMarket(metal,crystal,fuel,choice,maCurrentGood);
  if(gb.buttons.pressed(BUTTON_A))
  {
    buyGoods();
  }
  else if(gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(maCurrentGood==0)
    {
      maCurrentGood=1;
    }
    else
    {
      maCurrentGood=0;
    }
  }
  else if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 12;
}

String getCommodityInfo()
{
  String Result="";
  if(maCurrentGood==0)
  {
    Result=getResourcesInfo();
  }
  else
  {
    Result=getShipsInfo();
  }
  return Result;
}

String getResourcesInfo()
{
  int goodsCount=400+Colony[13].level*100;
  String Result=String(goodsCount) + " Metal,Crystal";
  return Result;
}

String getShipsInfo()
{
  String Result="";
  switch(Colony[13].level)
  {
    case 1:
      Result = "30 Fighters"; break;
    case 2:
      Result = "40 Fighters"; break;
    case 3:
      Result = "20 Interceptors"; break;
    case 4:
      Result = "30 Interceptors"; break;
    case 5:
      Result = "5 Frigates"; break;
    case 6:
      Result = "7 Frigates"; break;
    case 7:
      Result = "2 War Cruisers"; break;
    case 8:
      Result = "3 War Cruisers"; break;
  }
  return Result;
}

void buyGoods()
{
  if(maCurrentGood==0)
  {
    if(PlayerResources[2]>=5000)
    {
      int goodsCount=400+Colony[13].level*100;
      PlayerResources[2]-=5000;
      PlayerResources[0]+=goodsCount;
      PlayerResources[1]+=goodsCount;
      if(PlayerResources[0]>9999)
      {
        PlayerResources[0]=9999;
      }
      if(PlayerResources[1]>9999)
      {
        PlayerResources[1]=9999;
      }
      gb.gui.popup("RESOURCES ACQUIRED!",50);
    }
  }
  else
  {
    if(PlayerResources[2]>=7500)
    {
      PlayerResources[2]-=7500;
      switch(Colony[13].level)
      {
        case 1:
          addMarketShips(0,30); break;
        case 2:
          addMarketShips(0,40); break;
        case 3:
          addMarketShips(1,20); break;
        case 4:
          addMarketShips(1,30); break;
        case 5:
          addMarketShips(2,5); break;
        case 6:
          addMarketShips(2,7); break;
        case 7:
          addMarketShips(3,2); break;
        case 8:
          addMarketShips(3,3); break;
      }
    }
  }
}

void addMarketShips(int idx, int quantity)
{
  PlayerShips[idx] += quantity;
  if (PlayerShips[idx] > 9999)
  {
    PlayerShips[idx] = 9999;
  }
  fillGarrisons(idx, quantity);
  gb.gui.popup("SHIPS ACQUIRED!", 50);
}

