//Report
int flReportPage=1;

void spaceBattle(int enIndex,int plIndex,bool attacker) //attacker - true (Player attacks), false (Player is defender)
{
  BattleResult Reset={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,false};
  BtResult=Reset;
  
  //TODO: Report starting units
  reportShipsBeforeBattle(enIndex,plIndex,attacker);
  //BATTLE
  resolveFightersBattle(enIndex,plIndex,attacker);
  //TODO: Report surviving units
  reportLosses(enIndex,plIndex,attacker);
}

void reportShipsBeforeBattle(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    BtResult.PlFighters=PlayerFleets[plIndex].Fighters;
    BtResult.EnFighters=Enemy1Garrison[enIndex].Fighters;
  }
  else
  {
    BtResult.PlFighters=PlayerShips[0];
    BtResult.EnFighters=EnemyFleets[enIndex].Fighters;
  }
}

void resolveFightersBattle(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    if(Enemy1Garrison[enIndex].Fighters>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].Fighters;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].Fighters>0)
      {
         AttackerBonus=PlayerFleets[plIndex].Fighters/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].Fighters + BattleExperience + AttackerBonus;
      int Result=PlayerStrenght-EnemyStrenght;
      {
        if(Result>0)
        {
          Enemy1Garrison[enIndex].Fighters=0;
          PlayerFleets[plIndex].Fighters-=EnemyStrenght;
          if(PlayerFleets[plIndex].Fighters<0)
          {
            PlayerFleets[plIndex].Fighters=0;
          }
          else if(Result<0)
          {
            PlayerFleets[plIndex].Fighters=0;
            Enemy1Garrison[enIndex].Fighters-=PlayerStrenght;
            if(Enemy1Garrison[enIndex].Fighters<0)
            {
              Enemy1Garrison[enIndex].Fighters=0;
            }
          }
          else
          {
            PlayerFleets[plIndex].Fighters=0;
            Enemy1Garrison[enIndex].Fighters=0;
          }
        }     
      }
    }
  }
  else
  {
    if(PlayerShips[0]>0)
    {
      int PlayerStrenght=PlayerShips[0]+BattleExperience;
      int AttackerBonus=0;
      if(EnemyFleets[enIndex].Fighters>0)
      {
         AttackerBonus=EnemyFleets[enIndex].Fighters/10;
      }
      int EnemyStrenght=EnemyFleets[enIndex].Fighters+AttackerBonus;
      int Result=EnemyStrenght-PlayerStrenght;
      if(Result>0) //Player lose
      {
        PlayerShips[0]=0;
        EnemyFleets[enIndex].Fighters-=PlayerStrenght;
        if(EnemyFleets[enIndex].Fighters<0)
        {
          EnemyFleets[enIndex].Fighters=0;
        }
      }
      else if(Result<0) //Player defend
      {
        EnemyFleets[enIndex].Fighters=0;
        PlayerShips[0]-=EnemyStrenght;
        if(PlayerShips[0]<0)
        {
          PlayerShips[0]=0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].Fighters=0;
        PlayerShips[0]=0;
      }
    }
    
  }
}

void reportLosses(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    BtResult.PlFightersLost=BtResult.PlFighters-PlayerFleets[plIndex].Fighters;
    BtResult.EnFightersLost=BtResult.EnFighters-Enemy1Garrison[enIndex].Fighters;
  }
  else
  {
    BtResult.PlFightersLost=BtResult.PlFighters-PlayerShips[0];
    BtResult.EnFightersLost=BtResult.EnFighters-EnemyFleets[enIndex].Fighters;
  }
}

bool battleResults()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    return true;
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(flReportPage==1)
    {
      flReportPage=2;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(flReportPage==2)
    {
      flReportPage=1;
    }
  }

  if(flReportPage==1)
  {
    drawBattleResult1();
  }
  else
  {
    drawBattleResult2();
  }
  return false;
}
