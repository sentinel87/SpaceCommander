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
  resolveInterceptorsBattle(enIndex,plIndex,attacker);
  resolveFrigatesBattle(enIndex,plIndex,attacker);
  resolveWarCruisersBattle(enIndex,plIndex,attacker);
  //TODO: Report surviving units
  reportLosses(enIndex,plIndex,attacker);
}

void reportShipsBeforeBattle(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    BtResult.PlFighters=PlayerFleets[plIndex].Fighters;
    BtResult.EnFighters=Enemy1Garrison[enIndex].Fighters;
    BtResult.PlInterceptors=PlayerFleets[plIndex].Interceptors;
    BtResult.EnInterceptors=Enemy1Garrison[enIndex].Interceptors;
    BtResult.PlFrigates=PlayerFleets[plIndex].Frigates;
    BtResult.EnFrigates=Enemy1Garrison[enIndex].Frigates;
    BtResult.PlWarCruisers=PlayerFleets[plIndex].WarCruisers;
    BtResult.EnWarCruisers=Enemy1Garrison[enIndex].WarCruisers;
  }
  else
  {
    BtResult.PlFighters=PlayerShips[0];
    BtResult.EnFighters=EnemyFleets[enIndex].Fighters;
    BtResult.PlInterceptors=PlayerShips[1];
    BtResult.EnInterceptors=EnemyFleets[enIndex].Interceptors;
    BtResult.PlFrigates=PlayerShips[2];
    BtResult.EnFrigates=EnemyFleets[enIndex].Frigates;
    BtResult.PlWarCruisers=PlayerShips[3];
    BtResult.EnWarCruisers=EnemyFleets[enIndex].WarCruisers;
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
      if(Result>0)
      {
        Enemy1Garrison[enIndex].Fighters=0;
        PlayerFleets[plIndex].Fighters-=EnemyStrenght;
        if(PlayerFleets[plIndex].Fighters<0)
        {
          PlayerFleets[plIndex].Fighters=0;
        }
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

void resolveInterceptorsBattle(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    if(Enemy1Garrison[enIndex].Interceptors>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].Interceptors*3;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].Interceptors>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].Interceptors*3)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].Interceptors*3 + BattleExperience*3 + AttackerBonus;
      int Result=PlayerStrenght-EnemyStrenght;
      if(Result>0)
      {
        Enemy1Garrison[enIndex].Interceptors=0;
        PlayerFleets[plIndex].Interceptors-=(EnemyStrenght/3);
        if(PlayerFleets[plIndex].Interceptors<0)
        {
          PlayerFleets[plIndex].Interceptors=0;
        }
      }
      else if(Result<0)
      {
        PlayerFleets[plIndex].Interceptors=0;
        Enemy1Garrison[enIndex].Interceptors-=(PlayerStrenght/3);
        if(Enemy1Garrison[enIndex].Interceptors<0)
        {
          Enemy1Garrison[enIndex].Interceptors=0;
        }
      }
      else
      {
        PlayerFleets[plIndex].Interceptors=0;
        Enemy1Garrison[enIndex].Interceptors=0;
      }     
    }
  }
  else
  {
    if(PlayerShips[1]>0)
    {
      int PlayerStrenght=(PlayerShips[1]*3)+BattleExperience;
      int AttackerBonus=0;
      if(EnemyFleets[enIndex].Interceptors>0)
      {
         AttackerBonus=(EnemyFleets[enIndex].Interceptors*3)/10;
      }
      int EnemyStrenght=(EnemyFleets[enIndex].Interceptors*3)+AttackerBonus;
      int Result=EnemyStrenght-PlayerStrenght;
      if(Result>0) //Player lose
      {
        PlayerShips[1]=0;
        EnemyFleets[enIndex].Interceptors-=(PlayerStrenght/3);
        if(EnemyFleets[enIndex].Interceptors<0)
        {
          EnemyFleets[enIndex].Interceptors=0;
        }
      }
      else if(Result<0) //Player defend
      {
        EnemyFleets[enIndex].Interceptors=0;
        PlayerShips[1]-=(EnemyStrenght/3);
        if(PlayerShips[1]<0)
        {
          PlayerShips[1]=0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].Interceptors=0;
        PlayerShips[1]=0;
      }
    }  
  }
}

void resolveFrigatesBattle(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    if(Enemy1Garrison[enIndex].Frigates>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].Frigates*10;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].Frigates>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].Frigates*10)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].Frigates*10 + BattleExperience*10 + AttackerBonus;
      int Result=PlayerStrenght-EnemyStrenght;
      if(Result>0)
      {
        Enemy1Garrison[enIndex].Frigates=0;
        PlayerFleets[plIndex].Frigates-=(EnemyStrenght/10);
        if(PlayerFleets[plIndex].Frigates<0)
        {
          PlayerFleets[plIndex].Frigates=0;
        }
      }
      else if(Result<0)
      {
        PlayerFleets[plIndex].Frigates=0;
        Enemy1Garrison[enIndex].Frigates-=(PlayerStrenght/10);
        if(Enemy1Garrison[enIndex].Frigates<0)
        {
          Enemy1Garrison[enIndex].Frigates=0;
        }
      }
      else
      {
        PlayerFleets[plIndex].Frigates=0;
        Enemy1Garrison[enIndex].Frigates=0;
      }     
    }
  }
  else
  {
    if(PlayerShips[2]>0)
    {
      int PlayerStrenght=(PlayerShips[2]*10)+BattleExperience;
      int AttackerBonus=0;
      if(EnemyFleets[enIndex].Frigates>0)
      {
         AttackerBonus=(EnemyFleets[enIndex].Frigates*10)/10;
      }
      int EnemyStrenght=(EnemyFleets[enIndex].Frigates*10)+AttackerBonus;
      int Result=EnemyStrenght-PlayerStrenght;
      if(Result>0) //Player lose
      {
        PlayerShips[2]=0;
        EnemyFleets[enIndex].Frigates-=(PlayerStrenght/10);
        if(EnemyFleets[enIndex].Frigates<0)
        {
          EnemyFleets[enIndex].Frigates=0;
        }
      }
      else if(Result<0) //Player defend
      {
        EnemyFleets[enIndex].Frigates=0;
        PlayerShips[2]-=(EnemyStrenght/10);
        if(PlayerShips[2]<0)
        {
          PlayerShips[2]=0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].Frigates=0;
        PlayerShips[2]=0;
      }
    }  
  }
}

void resolveWarCruisersBattle(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    if(Enemy1Garrison[enIndex].WarCruisers>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].WarCruisers*25;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].WarCruisers>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].WarCruisers*25)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].WarCruisers*25 + BattleExperience*25 + AttackerBonus;
      int Result=PlayerStrenght-EnemyStrenght;
      if(Result>0)
      {
        Enemy1Garrison[enIndex].WarCruisers=0;
        PlayerFleets[plIndex].WarCruisers-=(EnemyStrenght/25);
        if(PlayerFleets[plIndex].WarCruisers<0)
        {
          PlayerFleets[plIndex].WarCruisers=0;
        }
      }
      else if(Result<0)
      {
        PlayerFleets[plIndex].WarCruisers=0;
        Enemy1Garrison[enIndex].WarCruisers-=(PlayerStrenght/25);
        if(Enemy1Garrison[enIndex].WarCruisers<0)
        {
          Enemy1Garrison[enIndex].WarCruisers=0;
        }
      }
      else
      {
        PlayerFleets[plIndex].WarCruisers=0;
        Enemy1Garrison[enIndex].WarCruisers=0;
      }     
    }
  }
  else
  {
    if(PlayerShips[3]>0)
    {
      int PlayerStrenght=(PlayerShips[3]*25)+BattleExperience;
      int AttackerBonus=0;
      if(EnemyFleets[enIndex].WarCruisers>0)
      {
         AttackerBonus=(EnemyFleets[enIndex].WarCruisers*25)/10;
      }
      int EnemyStrenght=(EnemyFleets[enIndex].WarCruisers*25)+AttackerBonus;
      int Result=EnemyStrenght-PlayerStrenght;
      if(Result>0) //Player lose
      {
        PlayerShips[3]=0;
        EnemyFleets[enIndex].WarCruisers-=(PlayerStrenght/25);
        if(EnemyFleets[enIndex].WarCruisers<0)
        {
          EnemyFleets[enIndex].WarCruisers=0;
        }
      }
      else if(Result<0) //Player defend
      {
        EnemyFleets[enIndex].WarCruisers=0;
        PlayerShips[3]-=(EnemyStrenght/25);
        if(PlayerShips[3]<0)
        {
          PlayerShips[3]=0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].WarCruisers=0;
        PlayerShips[3]=0;
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
    BtResult.PlInterceptorsLost=BtResult.PlInterceptors-PlayerFleets[plIndex].Interceptors;
    BtResult.EnInterceptorsLost=BtResult.EnInterceptors-Enemy1Garrison[enIndex].Interceptors;
    BtResult.PlFrigatesLost=BtResult.PlFrigates-PlayerFleets[plIndex].Frigates;
    BtResult.EnFrigatesLost=BtResult.EnFrigates-Enemy1Garrison[enIndex].Frigates;
    BtResult.PlWarCruisersLost=BtResult.PlWarCruisers-PlayerFleets[plIndex].WarCruisers;
    BtResult.EnWarCruisersLost=BtResult.EnWarCruisers-Enemy1Garrison[enIndex].WarCruisers;
  }
  else
  {
    BtResult.PlFightersLost=BtResult.PlFighters-PlayerShips[0];
    BtResult.EnFightersLost=BtResult.EnFighters-EnemyFleets[enIndex].Fighters;
    BtResult.PlInterceptorsLost=BtResult.PlInterceptors-PlayerShips[1];
    BtResult.EnInterceptorsLost=BtResult.EnInterceptors-EnemyFleets[enIndex].Interceptors;
    BtResult.PlFrigatesLost=BtResult.PlFrigates-PlayerShips[2];
    BtResult.EnFrigatesLost=BtResult.EnFrigates-EnemyFleets[enIndex].Frigates;
    BtResult.PlWarCruisersLost=BtResult.PlWarCruisers-PlayerShips[3];
    BtResult.EnWarCruisersLost=BtResult.EnWarCruisers-EnemyFleets[enIndex].WarCruisers;
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