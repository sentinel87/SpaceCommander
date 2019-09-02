int pages=1;

int starRoutes(int Logistics,TradeRoute PlayerRoutes[12])
{
  
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawStarRoutes(PlayerRoutes);
  return 6;
}

