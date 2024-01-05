int8_t maCurrentGood = 0;

int8_t market()
{
  String choice = getCommodityInfo();
  int misslesPrice = getMisslesCurrentPrice();
  if (gb.buttons.pressed(BUTTON_A))
  {
    buyGoods();
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (maCurrentGood == 2)
    {
      maCurrentGood = 0;
    }
    else
    {
      maCurrentGood++;
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (maCurrentGood == 0)
    {
      maCurrentGood = 2;
    }
    else
    {
      maCurrentGood--;
    }
  }
  else if (gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawMarket(choice, maCurrentGood, (String)misslesPrice);
  return 12;
}

String getCommodityInfo()
{
  String Result = "";
  if (maCurrentGood == 0)
  {
    Result = getResourcesInfo();
  }
  else if (maCurrentGood == 1)
  {
    Result = getShipsInfo();
  }
  else
  {
    Result = getMisslesInfo();
  }
  return Result;
}

int getMisslesCurrentPrice()
{
  int resource1Cost = getResourceCostWithDiscount(Shipyard[13].resource1Cost, 13);
  int modifier = getMissleTotalCount();

  return resource1Cost * modifier;
}

int getMissleTotalCount()
{
  int modifier = 1;
  if (Colony[13].level < 3)
  {
    modifier = 1;
  }
  else if (Colony[13].level < 5)
  {
    modifier = 2;
  }
  else if (Colony[13].level < 8)
  {
    modifier = 3;
  }
  else
  {
    modifier = 4;
  }

  return modifier;
}

String getResourcesInfo()
{
  int goodsCount = 400 + Colony[13].level * 100;
  String Result = String(goodsCount) + " Metal,Crystal";
  return Result;
}

String getShipsInfo()
{
  String Result = "";
  switch (Colony[13].level)
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

String getMisslesInfo()
{
  String result = "1 Missle";

  if (Colony[13].level < 3)
  {
    result = "1 Missle";
  }
  else if (Colony[13].level < 5)
  {
    result = "2 Missles";
  }
  else if (Colony[13].level < 8)
  {
    result = "3 Missles";
  }
  else
  {
    result = "4 Missles";
  }

  return result;
}

void buyGoods()
{
  if (maCurrentGood == 0)
  {
    if (PlayerResources[2] >= 5000)
    {
      int goodsCount = 400 + Colony[13].level * 100;
      PlayerResources[2] -= 5000;
      PlayerResources[0] += goodsCount;
      PlayerResources[1] += goodsCount;
      if (PlayerResources[0] > 9999)
      {
        PlayerResources[0] = 9999;
      }
      if (PlayerResources[1] > 9999)
      {
        PlayerResources[1] = 9999;
      }
      gb.gui.popup("RESOURCES ACQUIRED!", 50);
    }
  }
  else if (maCurrentGood == 1)
  {
    if (PlayerResources[2] >= 7500)
    {
      PlayerResources[2] -= 7500;
      switch (Colony[13].level)
      {
        case 1:
          addMarketShips(0, 30); break;
        case 2:
          addMarketShips(0, 40); break;
        case 3:
          addMarketShips(1, 20); break;
        case 4:
          addMarketShips(1, 30); break;
        case 5:
          addMarketShips(2, 5); break;
        case 6:
          addMarketShips(2, 7); break;
        case 7:
          addMarketShips(3, 2); break;
        case 8:
          addMarketShips(3, 3); break;
      }
    }
  }
  else
  {
    int totalPrice = getMisslesCurrentPrice();
    int totalMissles = getMissleTotalCount();
    if (PlayerResources[2] >= totalPrice)
    {
      PlayerResources[2] -= totalPrice;
      addMarketShips(13, totalMissles);
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
  
  if (idx == 13)
  {
    gb.gui.popup("MISSLES ACQUIRED!", 50);
  }
  else
  {
    gb.gui.popup("SHIPS ACQUIRED!", 50);
  }
}

