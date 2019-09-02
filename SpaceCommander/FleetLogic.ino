int markerPosX=1;
int markerPosY=7;

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

