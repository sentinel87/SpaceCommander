int markerPosX=1;
int markerPosY=7;

//Report
int reportPage=1;

int playerFleets(Fleet PlayerFleets[5])
{
  drawPlayerFleets(PlayerFleets,markerPosX,markerPosY);
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 8;
}

int enemyFleets(Fleet EnemyFleets[5])
{
  drawEnemyFleets(EnemyFleets,markerPosX,markerPosY);
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 9;
}

int playerFleetStats(int8_t fleet[11])
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawFleetStats(fleet);
  return 10;
}

bool battleResults()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(reportPage==1)
    {
      reportPage=2;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(reportPage==2)
    {
      reportPage=1;
    }
  }

  if(reportPage==1)
  {
    drawBattleResult1();
  }
  else
  {
    drawBattleResult2();
  }
  return false;
}

