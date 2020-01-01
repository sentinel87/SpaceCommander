//Report
int flReportPage=1;

int8_t spaceBattle(int enIndex,int plIndex,bool attacker) //attacker - true (Player attacks), false (Player is defender)
{
  BattleResult Reset={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,false};
  BtResult=Reset;
  
  reportShipsBeforeBattle(enIndex,plIndex,attacker);
  //BATTLE
  if(attacker==false)
  {
    defenceSystemActivation(enIndex); 
  }
  resolveBonuses(enIndex,plIndex,attacker);
  resolveFightersBattle(enIndex,plIndex,attacker);
  resolveInterceptorsBattle(enIndex,plIndex,attacker);
  resolveFrigatesBattle(enIndex,plIndex,attacker);
  resolveWarCruisersBattle(enIndex,plIndex,attacker);
  resolveStarDreadnoughtsBattle(enIndex,plIndex,attacker);
  resolveSolarDestroyersBattle(enIndex,plIndex,attacker);
  resolveSecondRound(enIndex,plIndex,attacker);

  int8_t winner=determineWinner(enIndex,plIndex,attacker);
  reportLosses(enIndex,plIndex,attacker,winner);
  
  return winner;
}

void defenceSystemActivation(int enIndex)
{
  int DefenceStrength=Colony[8].level*10;
  
  if(DefenceStrength>50 && EnemyFleets[enIndex].StarDreadnoughts>0)
  {
    int destroyed=DefenceStrength/50;
    EnemyFleets[enIndex].StarDreadnoughts-=destroyed;
    if(EnemyFleets[enIndex].StarDreadnoughts<0)
    {
      destroyed=EnemyFleets[enIndex].StarDreadnoughts+destroyed;
      EnemyFleets[enIndex].StarDreadnoughts=0;
    }
    else
    {
      EnemyFleets[enIndex].StarDreadnoughts-=destroyed;
    }
    DefenceStrength-=50*destroyed;
  }
  if(DefenceStrength>25 && EnemyFleets[enIndex].WarCruisers>0)
  {
    int destroyed=DefenceStrength/25;
    EnemyFleets[enIndex].WarCruisers-=destroyed;
    if(EnemyFleets[enIndex].WarCruisers<0)
    {
      destroyed=EnemyFleets[enIndex].WarCruisers+destroyed;
      EnemyFleets[enIndex].WarCruisers=0;
    }
    else
    {
      EnemyFleets[enIndex].WarCruisers-=destroyed;
    }
    DefenceStrength-=25*destroyed;
  }
  if(DefenceStrength>10 && EnemyFleets[enIndex].Frigates>0)
  {
    int destroyed=DefenceStrength/10;
    EnemyFleets[enIndex].Frigates-=destroyed;
    if(EnemyFleets[enIndex].Frigates<0)
    {
      destroyed=EnemyFleets[enIndex].Frigates+destroyed;
      EnemyFleets[enIndex].Frigates=0;
    }
    else
    {
      EnemyFleets[enIndex].Frigates-=destroyed;
    }
    DefenceStrength-=10*destroyed;
  }
  if(DefenceStrength>10 && EnemyFleets[enIndex].Frigates>0)
  {
    int destroyed=DefenceStrength/10;
    EnemyFleets[enIndex].Frigates-=destroyed;
    if(EnemyFleets[enIndex].Frigates<0)
    {
      destroyed=EnemyFleets[enIndex].Frigates+destroyed;
      EnemyFleets[enIndex].Frigates=0;
    }
    else
    {
      EnemyFleets[enIndex].Frigates-=destroyed;
    }
    DefenceStrength-=10*destroyed;
  }
  if(DefenceStrength>3 && EnemyFleets[enIndex].Interceptors>0)
  {
    int destroyed=DefenceStrength/3;
    EnemyFleets[enIndex].Interceptors-=destroyed;
    if(EnemyFleets[enIndex].Interceptors<0)
    {
      destroyed=EnemyFleets[enIndex].Interceptors+destroyed;
      EnemyFleets[enIndex].Interceptors=0;
    }
    else
    {
      EnemyFleets[enIndex].Interceptors-=destroyed;
    }
    DefenceStrength-=3*destroyed;
  }
  if(DefenceStrength>0 && EnemyFleets[enIndex].Fighters>0)
  {
    int destroyed=DefenceStrength;
    EnemyFleets[enIndex].Fighters-=destroyed;
    if(EnemyFleets[enIndex].Fighters<0)
    {
      destroyed=EnemyFleets[enIndex].Fighters+destroyed;
      EnemyFleets[enIndex].Fighters=0;
    }
    else
    {
      EnemyFleets[enIndex].Fighters-=destroyed;
    }
    DefenceStrength-=destroyed;
  }
  int EnemyStrength=EnemyFleets[enIndex].Fighters+(EnemyFleets[enIndex].Interceptors*3)+(EnemyFleets[enIndex].Frigates*10)+(EnemyFleets[enIndex].WarCruisers*25)+(EnemyFleets[enIndex].StarDreadnoughts*50);
  int Damaged=EnemyStrength/150;
  if(Damaged>Colony[8].level)
  {
    Colony[8].level=0;
  }
  else
  {
    Colony[8].level-=Damaged;
  }
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
    PlayerFleets[plIndex].Interceptors-=Enemy1Garrison[enIndex].WarCruisers*5;
    if(PlayerFleets[plIndex].Interceptors<0)
    {
      PlayerFleets[plIndex].Interceptors=0;
    }
  }
  else
  {
    PlayerShips[0]-=EnemyFleets[enIndex].Frigates*3;
    if(PlayerShips[0]<0)
    {
      PlayerShips[0]=0;
    }
    EnemyFleets[enIndex].Fighters-=PlayerShips[2]*3;
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
    if(PlayerFleets[plIndex].Fighters>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].Fighters;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].Fighters>0)
      {
         AttackerBonus=PlayerFleets[plIndex].Fighters/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].Fighters + BattleExperience/10 + AttackerBonus;
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
    if(PlayerFleets[plIndex].Interceptors>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].Interceptors*3;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].Interceptors>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].Interceptors*3)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].Interceptors*3 + (BattleExperience/10)*3 + AttackerBonus;
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
    if(PlayerFleets[plIndex].Frigates>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].Frigates*10;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].Frigates>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].Frigates*10)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].Frigates*10 + (BattleExperience/10)*10 + AttackerBonus;
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
    if(PlayerFleets[plIndex].WarCruisers>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].WarCruisers*25;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].WarCruisers>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].WarCruisers*25)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].WarCruisers*25 + (BattleExperience/10)*25 + AttackerBonus;
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
    if(PlayerFleets[plIndex].StarDreadnoughts>0)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].StarDreadnoughts*50;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].StarDreadnoughts>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].StarDreadnoughts*50)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].StarDreadnoughts*50 + (BattleExperience/10)*50 + AttackerBonus;
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
    if(PlayerFleets[plIndex].SolarDestroyers)
    {
      int EnemyStrenght=Enemy1Garrison[enIndex].SolarDestroyers*100;
      int AttackerBonus=0;
      if(PlayerFleets[plIndex].SolarDestroyers>0)
      {
         AttackerBonus=(PlayerFleets[plIndex].SolarDestroyers*100)/10;
      }
      int PlayerStrenght=PlayerFleets[plIndex].SolarDestroyers*100 + (BattleExperience/10)*100 + AttackerBonus;
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

void resolveSecondRound(int enIndex,int plIndex,bool attacker)
{
  int EnemyStrength=0;
  int PlayerStrength=0;
  if(attacker==true)
  {
    EnemyStrength+=Enemy1Garrison[enIndex].Fighters;
    EnemyStrength+=(Enemy1Garrison[enIndex].Interceptors*3);
    EnemyStrength+=(Enemy1Garrison[enIndex].Frigates*10);
    EnemyStrength+=(Enemy1Garrison[enIndex].WarCruisers*25);
    EnemyStrength+=(Enemy1Garrison[enIndex].StarDreadnoughts*50);
    EnemyStrength+=(Enemy1Garrison[enIndex].SolarDestroyers*100);
    
    PlayerStrength+=PlayerFleets[plIndex].Fighters;
    PlayerStrength+=(PlayerFleets[plIndex].Interceptors*3);
    PlayerStrength+=(PlayerFleets[plIndex].Frigates*10);
    PlayerStrength+=(PlayerFleets[plIndex].WarCruisers*25);
    PlayerStrength+=(PlayerFleets[plIndex].StarDreadnoughts*50);
    PlayerStrength+=(PlayerFleets[plIndex].SolarDestroyers*100);
    
    //----------------------Enemy casaulties-------------
    if(Enemy1Garrison[enIndex].SolarDestroyers>0 && PlayerStrength>=100)
    {
      int casaulties=PlayerStrength/100;
      int discrepancy=Enemy1Garrison[enIndex].SolarDestroyers-casaulties;
      if(discrepancy>=0)
      {
        Enemy1Garrison[enIndex].SolarDestroyers-=casaulties;
        PlayerStrength-=casaulties*100;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        Enemy1Garrison[enIndex].SolarDestroyers-=fixed;
        PlayerStrength-=fixed*100;
      }
    }

    if(Enemy1Garrison[enIndex].StarDreadnoughts>0 && PlayerStrength>=50)
    {
      int casaulties=PlayerStrength/50;
      int discrepancy=Enemy1Garrison[enIndex].StarDreadnoughts-casaulties;
      if(discrepancy>=0)
      {
        Enemy1Garrison[enIndex].StarDreadnoughts-=casaulties;
        PlayerStrength-=casaulties*50;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        Enemy1Garrison[enIndex].StarDreadnoughts-=fixed;
        PlayerStrength-=fixed*50;
      }
    }

    if(Enemy1Garrison[enIndex].WarCruisers>0 && PlayerStrength>=25)
    {
      int casaulties=PlayerStrength/25;
      int discrepancy=Enemy1Garrison[enIndex].WarCruisers-casaulties;
      if(discrepancy>=0)
      {
        Enemy1Garrison[enIndex].WarCruisers-=casaulties;
        PlayerStrength-=casaulties*25;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        Enemy1Garrison[enIndex].WarCruisers-=fixed;
        PlayerStrength-=fixed*25;
      }
    }

    if(Enemy1Garrison[enIndex].Frigates>0 && PlayerStrength>=10)
    {
      int casaulties=PlayerStrength/10;
      int discrepancy=Enemy1Garrison[enIndex].Frigates-casaulties;
      if(discrepancy>=0)
      {
        Enemy1Garrison[enIndex].Frigates-=casaulties;
        PlayerStrength-=casaulties*10;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        Enemy1Garrison[enIndex].Frigates-=fixed;
        PlayerStrength-=fixed*10;
      }
    }

    if(Enemy1Garrison[enIndex].Interceptors>0 && PlayerStrength>=3)
    {
      int casaulties=PlayerStrength/3;
      int discrepancy=Enemy1Garrison[enIndex].Interceptors-casaulties;
      if(discrepancy>=0)
      {
        Enemy1Garrison[enIndex].Interceptors-=casaulties;
        PlayerStrength-=casaulties*3;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        Enemy1Garrison[enIndex].Interceptors-=fixed;
        PlayerStrength-=fixed*3;
      }
    }

    if(Enemy1Garrison[enIndex].Fighters>0 && PlayerStrength>=1)
    {
      int casaulties=PlayerStrength;
      int discrepancy=Enemy1Garrison[enIndex].Fighters-casaulties;
      if(discrepancy>=0)
      {
        Enemy1Garrison[enIndex].Fighters-=casaulties;
        PlayerStrength-=casaulties;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        Enemy1Garrison[enIndex].Fighters-=fixed;
        PlayerStrength-=fixed;
      }
    }
    //----------------------Player casaulties-----------
    if(PlayerFleets[plIndex].SolarDestroyers>0 && EnemyStrength>=100)
    {
      int casaulties=EnemyStrength/100;
      int discrepancy=PlayerFleets[plIndex].SolarDestroyers-casaulties;
      if(discrepancy>=0)
      {
        PlayerFleets[plIndex].SolarDestroyers-=casaulties;
        EnemyStrength-=casaulties*100;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerFleets[plIndex].SolarDestroyers-=fixed;
        EnemyStrength-=fixed*100;
      }
    }

    if(PlayerFleets[plIndex].StarDreadnoughts>0 && EnemyStrength>=50)
    {
      int casaulties=EnemyStrength/50;
      int discrepancy=PlayerFleets[plIndex].StarDreadnoughts-casaulties;
      if(discrepancy>=0)
      {
        PlayerFleets[plIndex].StarDreadnoughts-=casaulties;
        EnemyStrength-=casaulties*50;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerFleets[plIndex].StarDreadnoughts-=fixed;
        EnemyStrength-=fixed*50;
      }
    }

    if(PlayerFleets[plIndex].WarCruisers>0 && EnemyStrength>=25)
    {
      int casaulties=EnemyStrength/25;
      int discrepancy=PlayerFleets[plIndex].WarCruisers-casaulties;
      if(discrepancy>=0)
      {
        PlayerFleets[plIndex].WarCruisers-=casaulties;
        EnemyStrength-=casaulties*25;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerFleets[plIndex].WarCruisers-=fixed;
        EnemyStrength-=fixed*25;
      }
    }

    if(PlayerFleets[plIndex].Frigates>0 && EnemyStrength>=10)
    {
      int casaulties=EnemyStrength/10;
      int discrepancy=PlayerFleets[plIndex].Frigates-casaulties;
      if(discrepancy>=0)
      {
        PlayerFleets[plIndex].Frigates-=casaulties;
        EnemyStrength-=casaulties*10;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerFleets[plIndex].Frigates-=fixed;
        EnemyStrength-=fixed*10;
      }
    }

    if(PlayerFleets[plIndex].Interceptors>0 && EnemyStrength>=3)
    {
      int casaulties=EnemyStrength/3;
      int discrepancy=PlayerFleets[plIndex].Interceptors-casaulties;
      if(discrepancy>=0)
      {
        PlayerFleets[plIndex].Interceptors-=casaulties;
        EnemyStrength-=casaulties*3;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerFleets[plIndex].Interceptors-=fixed;
        EnemyStrength-=fixed*3;
      }
    }

    if(PlayerFleets[plIndex].Fighters>0 && EnemyStrength>=1)
    {
      int casaulties=EnemyStrength;
      int discrepancy=PlayerFleets[plIndex].Fighters-casaulties;
      if(discrepancy>=0)
      {
        PlayerFleets[plIndex].Fighters-=casaulties;
        EnemyStrength-=casaulties;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerFleets[plIndex].Fighters-=fixed;
        EnemyStrength-=fixed;
      }
    }
  }
  else
  {
    EnemyStrength+=EnemyFleets[enIndex].Fighters;
    EnemyStrength+=(EnemyFleets[enIndex].Interceptors*3);
    EnemyStrength+=(EnemyFleets[enIndex].Frigates*10);
    EnemyStrength+=(EnemyFleets[enIndex].WarCruisers*25);
    EnemyStrength+=(EnemyFleets[enIndex].StarDreadnoughts*50);
    EnemyStrength+=(EnemyFleets[enIndex].SolarDestroyers*100);
    
    PlayerStrength+=PlayerShips[0];
    PlayerStrength+=(PlayerShips[1]*3);
    PlayerStrength+=(PlayerShips[2]*10);
    PlayerStrength+=(PlayerShips[3]*25);
    PlayerStrength+=(PlayerShips[4]*50);
    PlayerStrength+=(PlayerShips[5]*100);

    //----------------------Enemy casaulties-------------
    if(EnemyFleets[enIndex].SolarDestroyers>0 && PlayerStrength>=100)
    {
      int casaulties=PlayerStrength/100;
      int discrepancy=EnemyFleets[enIndex].SolarDestroyers-casaulties;
      if(discrepancy>=0)
      {
        EnemyFleets[enIndex].SolarDestroyers-=casaulties;
        PlayerStrength-=casaulties*100;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        EnemyFleets[enIndex].SolarDestroyers-=fixed;
        PlayerStrength-=fixed*100;
      }
    }

    if(EnemyFleets[enIndex].StarDreadnoughts>0 && PlayerStrength>=50)
    {
      int casaulties=PlayerStrength/50;
      int discrepancy=EnemyFleets[enIndex].StarDreadnoughts-casaulties;
      if(discrepancy>=0)
      {
        EnemyFleets[enIndex].StarDreadnoughts-=casaulties;
        PlayerStrength-=casaulties*50;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        EnemyFleets[enIndex].StarDreadnoughts-=fixed;
        PlayerStrength-=fixed*50;
      }
    }

    if(EnemyFleets[enIndex].WarCruisers>0 && PlayerStrength>=25)
    {
      int casaulties=PlayerStrength/25;
      int discrepancy=EnemyFleets[enIndex].WarCruisers-casaulties;
      if(discrepancy>=0)
      {
        EnemyFleets[enIndex].WarCruisers-=casaulties;
        PlayerStrength-=casaulties*25;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        EnemyFleets[enIndex].WarCruisers-=fixed;
        PlayerStrength-=fixed*25;
      }
    }

    if(EnemyFleets[enIndex].Frigates>0 && PlayerStrength>=10)
    {
      int casaulties=PlayerStrength/10;
      int discrepancy=EnemyFleets[enIndex].Frigates-casaulties;
      if(discrepancy>=0)
      {
        EnemyFleets[enIndex].Frigates-=casaulties;
        PlayerStrength-=casaulties*10;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        EnemyFleets[enIndex].Frigates-=fixed;
        PlayerStrength-=fixed*10;
      }
    }

    if(EnemyFleets[enIndex].Interceptors>0 && PlayerStrength>=3)
    {
      int casaulties=PlayerStrength/3;
      int discrepancy=EnemyFleets[enIndex].Interceptors-casaulties;
      if(discrepancy>=0)
      {
        EnemyFleets[enIndex].Interceptors-=casaulties;
        PlayerStrength-=casaulties*3;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        EnemyFleets[enIndex].Interceptors-=fixed;
        PlayerStrength-=fixed*3;
      }
    }

    if(EnemyFleets[enIndex].Fighters>0 && PlayerStrength>=1)
    {
      int casaulties=PlayerStrength;
      int discrepancy=EnemyFleets[enIndex].Fighters-casaulties;
      if(discrepancy>=0)
      {
        EnemyFleets[enIndex].Fighters-=casaulties;
        PlayerStrength-=casaulties;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        EnemyFleets[enIndex].Fighters-=fixed;
        PlayerStrength-=fixed;
      }
    }
    //----------------------Player casaulties-----------
    if(PlayerShips[5]>0 && EnemyStrength>=100)
    {
      int casaulties=EnemyStrength/100;
      int discrepancy=PlayerShips[5]-casaulties;
      if(discrepancy>=0)
      {
        PlayerShips[5]-=casaulties;
        EnemyStrength-=casaulties*100;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerShips[5]-=fixed;
        EnemyStrength-=fixed*100;
      }
    }

    if(PlayerShips[4]>0 && EnemyStrength>=50)
    {
      int casaulties=EnemyStrength/50;
      int discrepancy=PlayerShips[4]-casaulties;
      if(discrepancy>=0)
      {
        PlayerShips[4]-=casaulties;
        EnemyStrength-=casaulties*50;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerShips[4]-=fixed;
        EnemyStrength-=fixed*50;
      }
    }

    if(PlayerShips[3]>0 && EnemyStrength>=25)
    {
      int casaulties=EnemyStrength/25;
      int discrepancy=PlayerShips[3]-casaulties;
      if(discrepancy>=0)
      {
        PlayerShips[3]-=casaulties;
        EnemyStrength-=casaulties*25;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerShips[3]-=fixed;
        EnemyStrength-=fixed*25;
      }
    }

    if(PlayerShips[2]>0 && EnemyStrength>=10)
    {
      int casaulties=EnemyStrength/10;
      int discrepancy=PlayerShips[2]-casaulties;
      if(discrepancy>=0)
      {
        PlayerShips[2]-=casaulties;
        EnemyStrength-=casaulties*10;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerShips[2]-=fixed;
        EnemyStrength-=fixed*10;
      }
    }

    if(PlayerShips[1]>0 && EnemyStrength>=3)
    {
      int casaulties=EnemyStrength/3;
      int discrepancy=PlayerShips[1]-casaulties;
      if(discrepancy>=0)
      {
        PlayerShips[1]-=casaulties;
        EnemyStrength-=casaulties*3;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerShips[1]-=fixed;
        EnemyStrength-=fixed*3;
      }
    }

    if(PlayerShips[0]>0 && EnemyStrength>=1)
    {
      int casaulties=EnemyStrength;
      int discrepancy=PlayerShips[0]-casaulties;
      if(discrepancy>=0)
      {
        PlayerShips[0]-=casaulties;
        EnemyStrength-=casaulties;
      }
      else
      {
        int fixed=casaulties+discrepancy;
        PlayerShips[0]-=fixed;
        EnemyStrength-=fixed;
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
    flReportPage=1;
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
