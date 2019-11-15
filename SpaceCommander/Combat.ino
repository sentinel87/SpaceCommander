//Report
int flReportPage=1;

int8_t spaceBattle(int enIndex,int plIndex,bool attacker) //attacker - true (Player attacks), false (Player is defender)
{
  BattleResult Reset={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,false};
  BtResult=Reset;
  
  //TODO: Report starting units
  reportShipsBeforeBattle(enIndex,plIndex,attacker);
  //BATTLE
  resolveBonuses(enIndex,plIndex,attacker);
  resolveFightersBattle(enIndex,plIndex,attacker);
  resolveInterceptorsBattle(enIndex,plIndex,attacker);
  resolveFrigatesBattle(enIndex,plIndex,attacker);
  resolveWarCruisersBattle(enIndex,plIndex,attacker);
  resolveStarDreadnoughtsBattle(enIndex,plIndex,attacker);
  resolveSolarDestroyersBattle(enIndex,plIndex,attacker);
  //TODO: Report surviving units
  int8_t winner=determineWinner(enIndex,plIndex,attacker);
  reportLosses(enIndex,plIndex,attacker,winner);
  
  return winner;
}

void resolveBonuses(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    Enemy1Garrison[enIndex].Fighters-=PlayerFleets[plIndex].Frigates*3;
    if(Enemy1Garrison[enIndex].Fighters<0)
    {
      Enemy1Garrison[enIndex].Fighters=0;
    }
    PlayerFleets[plIndex].Fighters-=Enemy1Garrison[enIndex].Frigates*3;
    if(PlayerFleets[plIndex].Fighters<0)
    {
      PlayerFleets[plIndex].Fighters=0;
    }

    Enemy1Garrison[enIndex].Interceptors-=PlayerFleets[plIndex].WarCruisers*5;
    if(Enemy1Garrison[enIndex].Interceptors<0)
    {
      Enemy1Garrison[enIndex].Interceptors=0;
    }
    PlayerFleets[plIndex].Interceptors-=Enemy1Garrison[enIndex].WarCruisers*3;
    if(PlayerFleets[plIndex].Fighters<0)
    {
      PlayerFleets[plIndex].Fighters=0;
    }
  }
  else
  {
    PlayerShips[0]-=EnemyFleets[enIndex].Frigates*3;
    if(PlayerShips[0]<0)
    {
      PlayerShips[0]=0;
    }
    EnemyFleets[enIndex].Fighters-=PlayerShips[2];
    if(EnemyFleets[enIndex].Fighters<0)
    {
      EnemyFleets[enIndex].Fighters=0;
    }

    PlayerShips[1]-=EnemyFleets[enIndex].WarCruisers*5;
    if(PlayerShips[1]<0)
    {
      PlayerShips[1]=0;
    }
    EnemyFleets[enIndex].Interceptors-=PlayerShips[3]*5;
    if(EnemyFleets[enIndex].Interceptors<0)
    {
      EnemyFleets[enIndex].Interceptors=0;
    }
  }
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
    BtResult.PlStarDreadnoughts=PlayerFleets[plIndex].StarDreadnoughts;
    BtResult.EnStarDreadnoughts=Enemy1Garrison[enIndex].StarDreadnoughts;
    BtResult.PlSolarDestroyers=PlayerFleets[plIndex].SolarDestroyers;
    BtResult.EnSolarDestroyers=Enemy1Garrison[enIndex].SolarDestroyers;
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
    BtResult.PlStarDreadnoughts=PlayerShips[4];
    BtResult.EnStarDreadnoughts=EnemyFleets[enIndex].StarDreadnoughts;
    BtResult.PlSolarDestroyers=PlayerShips[5];
    BtResult.EnSolarDestroyers=EnemyFleets[enIndex].SolarDestroyers;
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

void resolveStarDreadnoughtsBattle(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    if(Enemy1Garrison[enIndex].StarDreadnoughts>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].StarDreadnoughts*50;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].StarDreadnoughts>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].StarDreadnoughts*50)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].StarDreadnoughts*50 + BattleExperience*50 + AttackerBonus;
      int Result=PlayerStrenght-EnemyStrenght;
      if(Result>0)
      {
        Enemy1Garrison[enIndex].StarDreadnoughts=0;
        PlayerFleets[plIndex].StarDreadnoughts-=(EnemyStrenght/50);
        if(PlayerFleets[plIndex].StarDreadnoughts<0)
        {
          PlayerFleets[plIndex].StarDreadnoughts=0;
        }
      }
      else if(Result<0)
      {
        PlayerFleets[plIndex].StarDreadnoughts=0;
        Enemy1Garrison[enIndex].StarDreadnoughts-=(PlayerStrenght/50);
        if(Enemy1Garrison[enIndex].StarDreadnoughts<0)
        {
          Enemy1Garrison[enIndex].StarDreadnoughts=0;
        }
      }
      else
      {
        PlayerFleets[plIndex].StarDreadnoughts=0;
        Enemy1Garrison[enIndex].StarDreadnoughts=0;
      }     
    }
  }
  else
  {
    if(PlayerShips[4]>0)
    {
      int PlayerStrenght=(PlayerShips[4]*50)+BattleExperience;
      int AttackerBonus=0;
      if(EnemyFleets[enIndex].StarDreadnoughts>0)
      {
         AttackerBonus=(EnemyFleets[enIndex].StarDreadnoughts*50)/10;
      }
      int EnemyStrenght=(EnemyFleets[enIndex].StarDreadnoughts*50)+AttackerBonus;
      int Result=EnemyStrenght-PlayerStrenght;
      if(Result>0) //Player lose
      {
        PlayerShips[4]=0;
        EnemyFleets[enIndex].StarDreadnoughts-=(PlayerStrenght/50);
        if(EnemyFleets[enIndex].StarDreadnoughts<0)
        {
          EnemyFleets[enIndex].StarDreadnoughts=0;
        }
      }
      else if(Result<0) //Player defend
      {
        EnemyFleets[enIndex].StarDreadnoughts=0;
        PlayerShips[4]-=(EnemyStrenght/50);
        if(PlayerShips[4]<0)
        {
          PlayerShips[4]=0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].StarDreadnoughts=0;
        PlayerShips[4]=0;
      }
    }  
  }
}

void resolveSolarDestroyersBattle(int enIndex,int plIndex,bool attacker)
{
  if(attacker==true)
  {
    if(Enemy1Garrison[enIndex].SolarDestroyers>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].SolarDestroyers*100;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].SolarDestroyers>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].SolarDestroyers*100)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].SolarDestroyers*100 + BattleExperience*100 + AttackerBonus;
      int Result=PlayerStrenght-EnemyStrenght;
      if(Result>0)
      {
        Enemy1Garrison[enIndex].SolarDestroyers=0;
        PlayerFleets[plIndex].SolarDestroyers-=(EnemyStrenght/100);
        if(PlayerFleets[plIndex].SolarDestroyers<0)
        {
          PlayerFleets[plIndex].SolarDestroyers=0;
        }
      }
      else if(Result<0)
      {
        PlayerFleets[plIndex].SolarDestroyers=0;
        Enemy1Garrison[enIndex].SolarDestroyers-=(PlayerStrenght/100);
        if(Enemy1Garrison[enIndex].SolarDestroyers<0)
        {
          Enemy1Garrison[enIndex].SolarDestroyers=0;
        }
      }
      else
      {
        PlayerFleets[plIndex].SolarDestroyers=0;
        Enemy1Garrison[enIndex].SolarDestroyers=0;
      }     
    }
  }
  else
  {
    if(PlayerShips[5]>0)
    {
      int PlayerStrenght=(PlayerShips[5]*100)+BattleExperience;
      int AttackerBonus=0;
      if(EnemyFleets[enIndex].SolarDestroyers>0)
      {
         AttackerBonus=(EnemyFleets[enIndex].SolarDestroyers*100)/10;
      }
      int EnemyStrenght=(EnemyFleets[enIndex].SolarDestroyers*100)+AttackerBonus;
      int Result=EnemyStrenght-PlayerStrenght;
      if(Result>0) //Player lose
      {
        PlayerShips[5]=0;
        EnemyFleets[enIndex].SolarDestroyers-=(PlayerStrenght/100);
        if(EnemyFleets[enIndex].SolarDestroyers<0)
        {
          EnemyFleets[enIndex].SolarDestroyers=0;
        }
      }
      else if(Result<0) //Player defend
      {
        EnemyFleets[enIndex].SolarDestroyers=0;
        PlayerShips[5]-=(EnemyStrenght/100);
        if(PlayerShips[5]<0)
        {
          PlayerShips[5]=0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].SolarDestroyers=0;
        PlayerShips[5]=0;
      }
    }  
  }
}

int8_t determineWinner(int enIndex,int plIndex,bool attacker)
{
  int EnemyPoints=0;
  int PlayerPoints=0;
  if(attacker==true)
  {
    EnemyPoints+=Enemy1Garrison[enIndex].Fighters;
    EnemyPoints+=(Enemy1Garrison[enIndex].Interceptors*2);
    EnemyPoints+=(Enemy1Garrison[enIndex].Frigates*3);
    EnemyPoints+=(Enemy1Garrison[enIndex].WarCruisers*5);
    EnemyPoints+=(Enemy1Garrison[enIndex].StarDreadnoughts*8);
    EnemyPoints+=(Enemy1Garrison[enIndex].SolarDestroyers*10);
    PlayerPoints+=PlayerFleets[plIndex].Fighters;
    PlayerPoints+=(PlayerFleets[plIndex].Interceptors*2);
    PlayerPoints+=(PlayerFleets[plIndex].Frigates*3);
    PlayerPoints+=(PlayerFleets[plIndex].WarCruisers*5);
    PlayerPoints+=(PlayerFleets[plIndex].StarDreadnoughts*8);
    PlayerPoints+=(PlayerFleets[plIndex].SolarDestroyers*10);
  }
  else
  {
    EnemyPoints+=EnemyFleets[enIndex].Fighters;
    EnemyPoints+=(EnemyFleets[enIndex].Interceptors*2);
    EnemyPoints+=(EnemyFleets[enIndex].Frigates*3);
    EnemyPoints+=(EnemyFleets[enIndex].WarCruisers*5);
    EnemyPoints+=(EnemyFleets[enIndex].StarDreadnoughts*8);
    EnemyPoints+=(EnemyFleets[enIndex].SolarDestroyers*10);
    PlayerPoints+=PlayerShips[0];
    PlayerPoints+=(PlayerShips[1]*2);
    PlayerPoints+=(PlayerShips[2]*3);
    PlayerPoints+=(PlayerShips[3]*5);
    PlayerPoints+=(PlayerShips[4]*8);
    PlayerPoints+=(PlayerShips[5]*10);
  }
  
  if(PlayerPoints>EnemyPoints) //PLAYER WINS
  {
    return 1;
  }
  else if(PlayerPoints<EnemyPoints) //ENEMY WINS
  {
    return 2;
  }
  else //DRAW
  {
    return 0;
  }
}

void reportLosses(int enIndex,int plIndex,bool attacker,int8_t winner)
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
    BtResult.PlStarDreadnoughtsLost=BtResult.PlStarDreadnoughts-PlayerFleets[plIndex].StarDreadnoughts;
    BtResult.EnStarDreadnoughtsLost=BtResult.EnStarDreadnoughts-Enemy1Garrison[enIndex].StarDreadnoughts;
    BtResult.PlSolarDestroyersLost=BtResult.PlSolarDestroyers-PlayerFleets[plIndex].SolarDestroyers;
    BtResult.EnSolarDestroyersLost=BtResult.EnSolarDestroyers-Enemy1Garrison[enIndex].SolarDestroyers;
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
    BtResult.PlStarDreadnoughtsLost=BtResult.PlStarDreadnoughts-PlayerShips[4];
    BtResult.EnStarDreadnoughtsLost=BtResult.EnStarDreadnoughts-EnemyFleets[enIndex].StarDreadnoughts;
    BtResult.PlSolarDestroyersLost=BtResult.PlSolarDestroyers-PlayerShips[5];
    BtResult.EnSolarDestroyersLost=BtResult.EnSolarDestroyers-EnemyFleets[enIndex].SolarDestroyers;
  }
  BtResult.Winner=winner;
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
