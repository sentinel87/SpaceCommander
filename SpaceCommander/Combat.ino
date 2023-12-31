//Report
int flReportPage = 1;

int8_t spaceBattle(int enIndex, int plIndex, bool attacker, int affilation) //attacker - true (Player attacks), false (Player is defender)
{
  BattleResult Reset = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,false};
  BtResult = Reset;
  
  if (attacker == false)
  {
    EnemyGarrison garrison = {-1,0,0,0,0,0,0};
    reportShipsBeforeBattle(enIndex, plIndex, attacker, garrison);
    //BATTLE
    defenceSystemActivation(enIndex); 

    resolveBonuses(enIndex, plIndex, attacker, garrison);
    resolveFightersBattle(enIndex, plIndex, attacker, garrison);
    resolveInterceptorsBattle(enIndex, plIndex, attacker, garrison);
    resolveFrigatesBattle(enIndex, plIndex, attacker, garrison);
    resolveWarCruisersBattle(enIndex, plIndex, attacker, garrison);
    resolveStarDreadnoughtsBattle(enIndex, plIndex, attacker, garrison);
    resolveSolarDestructorsBattle(enIndex, plIndex, attacker, garrison);
    resolveSecondRound(enIndex, plIndex, attacker, garrison);
  
    int8_t winner = determineWinner(enIndex, plIndex, attacker, garrison);
    reportLosses(enIndex, plIndex, attacker, winner, garrison);

    return winner;
  }
  else if (affilation == 1)//Determine, which enemy garrison is attacked
  {
    reportShipsBeforeBattle(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    //BATTLE
    resolveBonuses(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    resolveFightersBattle(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    resolveInterceptorsBattle(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    resolveFrigatesBattle(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    resolveWarCruisersBattle(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    resolveStarDreadnoughtsBattle(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    resolveSolarDestructorsBattle(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    resolveSecondRound(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
  
    int8_t winner = determineWinner(enIndex, plIndex, attacker, Enemy1Garrison[enIndex]);
    reportLosses(enIndex, plIndex, attacker, winner, Enemy1Garrison[enIndex]);

    return winner;
  }
  else if (affilation == 2)
  {
    reportShipsBeforeBattle(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    //BATTLE
    resolveBonuses(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    resolveFightersBattle(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    resolveInterceptorsBattle(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    resolveFrigatesBattle(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    resolveWarCruisersBattle(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    resolveStarDreadnoughtsBattle(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    resolveSolarDestructorsBattle(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    resolveSecondRound(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
  
    int8_t winner = determineWinner(enIndex, plIndex, attacker, Enemy2Garrison[enIndex]);
    reportLosses(enIndex, plIndex, attacker, winner, Enemy2Garrison[enIndex]);

    return winner;
  }
  return 0;
}

void defenceSystemActivation(int enIndex)
{
  int DefenceStrength = Colony[8].level * 15;
  
  if (DefenceStrength >= 50 && EnemyFleets[enIndex].StarDreadnoughts > 0)
  {
    int destroyed = DefenceStrength / 50;
    EnemyFleets[enIndex].StarDreadnoughts -= destroyed;
    if (EnemyFleets[enIndex].StarDreadnoughts < 0)
    {
      destroyed = EnemyFleets[enIndex].StarDreadnoughts + destroyed;
      EnemyFleets[enIndex].StarDreadnoughts = 0;
    }
    DefenceStrength -= 50 * destroyed;
  }
  if (DefenceStrength >= 25 && EnemyFleets[enIndex].WarCruisers > 0)
  {
    int destroyed = DefenceStrength / 25;
    EnemyFleets[enIndex].WarCruisers -= destroyed;
    if (EnemyFleets[enIndex].WarCruisers < 0)
    {
      destroyed = EnemyFleets[enIndex].WarCruisers + destroyed;
      EnemyFleets[enIndex].WarCruisers = 0;
    }
    DefenceStrength -= 25 * destroyed;
  }
  if (DefenceStrength >= 10 && EnemyFleets[enIndex].Frigates > 0)
  {
    int destroyed = DefenceStrength / 10;
    EnemyFleets[enIndex].Frigates -= destroyed;
    if (EnemyFleets[enIndex].Frigates < 0)
    {
      destroyed = EnemyFleets[enIndex].Frigates + destroyed;
      EnemyFleets[enIndex].Frigates = 0;
    }
    DefenceStrength -= 10 * destroyed;
  }
  if (DefenceStrength >= 3 && EnemyFleets[enIndex].Interceptors > 0)
  {
    int destroyed = DefenceStrength / 3;
    EnemyFleets[enIndex].Interceptors -= destroyed;
    if (EnemyFleets[enIndex].Interceptors < 0)
    {
      destroyed = EnemyFleets[enIndex].Interceptors + destroyed;
      EnemyFleets[enIndex].Interceptors = 0;
    }
    DefenceStrength -= 3 * destroyed;
  }
  if (DefenceStrength > 0 && EnemyFleets[enIndex].Fighters > 0)
  {
    int destroyed = DefenceStrength;
    EnemyFleets[enIndex].Fighters -= destroyed;
    if (EnemyFleets[enIndex].Fighters < 0)
    {
      destroyed = EnemyFleets[enIndex].Fighters + destroyed;
      EnemyFleets[enIndex].Fighters = 0;
    }
    DefenceStrength -= destroyed;
  }
}

void resolveBonuses(int enIndex, int plIndex, bool attacker, EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    garrison.Fighters -= PlayerFleets[plIndex].Frigates * 3;
    if (garrison.Fighters < 0)
    {
      garrison.Fighters = 0;
    }
    PlayerFleets[plIndex].Fighters -= garrison.Frigates * 3;
    if (PlayerFleets[plIndex].Fighters < 0)
    {
      PlayerFleets[plIndex].Fighters = 0;
    }

    garrison.Interceptors -= PlayerFleets[plIndex].WarCruisers * 5;
    if (garrison.Interceptors < 0)
    {
      garrison.Interceptors = 0;
    }
    PlayerFleets[plIndex].Interceptors -= garrison.WarCruisers * 5;
    if (PlayerFleets[plIndex].Interceptors < 0)
    {
      PlayerFleets[plIndex].Interceptors = 0;
    }
  }
  else
  {
    PlayerShips[0] -= EnemyFleets[enIndex].Frigates * 3;
    if (PlayerShips[0] < 0)
    {
      PlayerShips[0] = 0;
    }
    EnemyFleets[enIndex].Fighters -= PlayerShips[2] * 3;
    if (EnemyFleets[enIndex].Fighters < 0)
    {
      EnemyFleets[enIndex].Fighters = 0;
    }

    PlayerShips[1] -= EnemyFleets[enIndex].WarCruisers * 5;
    if (PlayerShips[1] < 0)
    {
      PlayerShips[1] = 0;
    }
    EnemyFleets[enIndex].Interceptors -= PlayerShips[3] * 5;
    if (EnemyFleets[enIndex].Interceptors < 0)
    {
      EnemyFleets[enIndex].Interceptors = 0;
    }
  }
}

void reportShipsBeforeBattle(int enIndex, int plIndex, bool attacker, EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    BtResult.PlFighters = PlayerFleets[plIndex].Fighters;
    BtResult.EnFighters = garrison.Fighters;
    BtResult.PlInterceptors = PlayerFleets[plIndex].Interceptors;
    BtResult.EnInterceptors = garrison.Interceptors;
    BtResult.PlFrigates = PlayerFleets[plIndex].Frigates;
    BtResult.EnFrigates = garrison.Frigates;
    BtResult.PlWarCruisers = PlayerFleets[plIndex].WarCruisers;
    BtResult.EnWarCruisers = garrison.WarCruisers;
    BtResult.PlStarDreadnoughts = PlayerFleets[plIndex].StarDreadnoughts;
    BtResult.EnStarDreadnoughts = garrison.StarDreadnoughts;
    BtResult.PlSolarDestroyers = PlayerFleets[plIndex].SolarDestroyers;
    BtResult.EnSolarDestroyers = garrison.SolarDestroyers;
  }
  else
  {
    BtResult.PlFighters = PlayerShips[0];
    BtResult.EnFighters = EnemyFleets[enIndex].Fighters;
    BtResult.PlInterceptors = PlayerShips[1];
    BtResult.EnInterceptors = EnemyFleets[enIndex].Interceptors;
    BtResult.PlFrigates = PlayerShips[2];
    BtResult.EnFrigates = EnemyFleets[enIndex].Frigates;
    BtResult.PlWarCruisers = PlayerShips[3];
    BtResult.EnWarCruisers = EnemyFleets[enIndex].WarCruisers;
    BtResult.PlStarDreadnoughts = PlayerShips[4];
    BtResult.EnStarDreadnoughts = EnemyFleets[enIndex].StarDreadnoughts;
    BtResult.PlSolarDestroyers = PlayerShips[5];
    BtResult.EnSolarDestroyers = EnemyFleets[enIndex].SolarDestroyers;
  }
}

void resolveFightersBattle(int enIndex, int plIndex, bool attacker, EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    if (PlayerFleets[plIndex].Fighters > 0)
    {
      int EnemyStrenght = garrison.Fighters;
      int AttackerBonus = 0;
      if (PlayerFleets[plIndex].Fighters > 0)
      {
         AttackerBonus = PlayerFleets[plIndex].Fighters / 10;
      }
      int PlayerStrenght = PlayerFleets[plIndex].Fighters + BattleExperience / 10 + AttackerBonus;
      int Result = PlayerStrenght - EnemyStrenght;
      if (Result > 0)
      {
        garrison.Fighters = 0;
        PlayerFleets[plIndex].Fighters -= EnemyStrenght;
        if (PlayerFleets[plIndex].Fighters < 0)
        {
          PlayerFleets[plIndex].Fighters = 0;
        }
      }
      else if (Result < 0)
      {
        PlayerFleets[plIndex].Fighters = 0;
        garrison.Fighters -= PlayerStrenght;
        if (garrison.Fighters < 0)
        {
          garrison.Fighters = 0;
        }
      }
      else
      {
          PlayerFleets[plIndex].Fighters = 0;
          garrison.Fighters = 0;
      }
    }     
  }
  else
  {
    if (PlayerShips[0] > 0)
    {
      int PlayerStrenght = PlayerShips[0] + BattleExperience;
      int AttackerBonus = 0;
      if (EnemyFleets[enIndex].Fighters > 0)
      {
         AttackerBonus = EnemyFleets[enIndex].Fighters / 10;
      }
      int EnemyStrenght = EnemyFleets[enIndex].Fighters + AttackerBonus; //110
      int Result = EnemyStrenght - PlayerStrenght;
      if (Result > 0) //Player lose
      {
        PlayerShips[0] = 0;
        EnemyFleets[enIndex].Fighters -= PlayerStrenght;
        if (EnemyFleets[enIndex].Fighters < 0)
        {
          EnemyFleets[enIndex].Fighters = 0;
        }
      }
      else if (Result < 0) //Player defend
      {
        EnemyFleets[enIndex].Fighters = 0;
        PlayerShips[0] -= EnemyStrenght;
        if(PlayerShips[0] < 0)
        {
          PlayerShips[0] = 0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].Fighters = 0;
        PlayerShips[0] = 0;
      }
    }  
  }
}

void resolveInterceptorsBattle(int enIndex,int plIndex,bool attacker,EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    if (PlayerFleets[plIndex].Interceptors > 0)
    {
      int EnemyStrenght = garrison.Interceptors * 3;
      int AttackerBonus = 0;
      if (PlayerFleets[plIndex].Interceptors > 0)
      {
         AttackerBonus = (PlayerFleets[plIndex].Interceptors * 3) / 10;
      }
      int PlayerStrenght = PlayerFleets[plIndex].Interceptors * 3 + (BattleExperience / 10) * 3 + AttackerBonus;
      int Result = PlayerStrenght - EnemyStrenght;
      if (Result > 0)
      {
        garrison.Interceptors = 0;
        PlayerFleets[plIndex].Interceptors -= (EnemyStrenght / 3);
        if (PlayerFleets[plIndex].Interceptors < 0)
        {
          PlayerFleets[plIndex].Interceptors = 0;
        }
      }
      else if (Result < 0)
      {
        PlayerFleets[plIndex].Interceptors = 0;
        garrison.Interceptors -= (PlayerStrenght / 3);
        if (garrison.Interceptors < 0)
        {
          garrison.Interceptors = 0;
        }
      }
      else
      {
        PlayerFleets[plIndex].Interceptors = 0;
        garrison.Interceptors = 0;
      }     
    }
  }
  else
  {
    if (PlayerShips[1] > 0)
    {
      int PlayerStrenght = (PlayerShips[1] * 3) + BattleExperience;
      int AttackerBonus = 0;
      if (EnemyFleets[enIndex].Interceptors > 0)
      {
         AttackerBonus = (EnemyFleets[enIndex].Interceptors * 3) / 10;
      }
      int EnemyStrenght = (EnemyFleets[enIndex].Interceptors * 3) + AttackerBonus;
      int Result = EnemyStrenght - PlayerStrenght;
      if(Result > 0) //Player lose
      {
        PlayerShips[1] = 0;
        EnemyFleets[enIndex].Interceptors -= (PlayerStrenght / 3);
        if (EnemyFleets[enIndex].Interceptors < 0)
        {
          EnemyFleets[enIndex].Interceptors = 0;
        }
      }
      else if (Result < 0) //Player defend
      {
        EnemyFleets[enIndex].Interceptors = 0;
        PlayerShips[1] -= (EnemyStrenght / 3);
        if(PlayerShips[1] < 0)
        {
          PlayerShips[1] = 0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].Interceptors = 0;
        PlayerShips[1] = 0;
      }
    }  
  }
}

void resolveFrigatesBattle(int enIndex, int plIndex, bool attacker, EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    if (PlayerFleets[plIndex].Frigates > 0)
    {
      int EnemyStrenght = garrison.Frigates * 10;
      int AttackerBonus = 0;
      if (PlayerFleets[plIndex].Frigates > 0)
      {
         AttackerBonus = (PlayerFleets[plIndex].Frigates * 10) / 10;
      }
      int PlayerStrenght = PlayerFleets[plIndex].Frigates * 10 + (BattleExperience / 10) * 10 + AttackerBonus;
      int Result = PlayerStrenght - EnemyStrenght;
      if (Result > 0)
      {
        garrison.Frigates = 0;
        PlayerFleets[plIndex].Frigates -= (EnemyStrenght / 10);
        if (PlayerFleets[plIndex].Frigates < 0)
        {
          PlayerFleets[plIndex].Frigates = 0;
        }
      }
      else if (Result < 0)
      {
        PlayerFleets[plIndex].Frigates = 0;
        garrison.Frigates -= (PlayerStrenght / 10);
        if (garrison.Frigates < 0)
        {
          garrison.Frigates = 0;
        }
      }
      else
      {
        PlayerFleets[plIndex].Frigates = 0;
        garrison.Frigates = 0;
      }     
    }
  }
  else
  {
    if (PlayerShips[2] > 0)
    {
      int PlayerStrenght = (PlayerShips[2] * 10) + BattleExperience;
      int AttackerBonus = 0;
      if (EnemyFleets[enIndex].Frigates > 0)
      {
         AttackerBonus = (EnemyFleets[enIndex].Frigates * 10) / 10;
      }
      int EnemyStrenght = (EnemyFleets[enIndex].Frigates * 10) + AttackerBonus;
      int Result = EnemyStrenght - PlayerStrenght;
      if(Result > 0) //Player lose
      {
        PlayerShips[2] = 0;
        EnemyFleets[enIndex].Frigates -= (PlayerStrenght / 10);
        if (EnemyFleets[enIndex].Frigates < 0)
        {
          EnemyFleets[enIndex].Frigates = 0;
        }
      }
      else if (Result < 0) //Player defend
      {
        EnemyFleets[enIndex].Frigates = 0;
        PlayerShips[2] -= (EnemyStrenght / 10);
        if (PlayerShips[2] < 0)
        {
          PlayerShips[2] = 0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].Frigates = 0;
        PlayerShips[2] = 0;
      }
    }  
  }
}

void resolveWarCruisersBattle(int enIndex, int plIndex, bool attacker, EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    if (PlayerFleets[plIndex].WarCruisers > 0)
    {
      int EnemyStrenght = garrison.WarCruisers * 25;
      int AttackerBonus = 0;
      if (PlayerFleets[plIndex].WarCruisers > 0)
      {
         AttackerBonus = (PlayerFleets[plIndex].WarCruisers * 25) / 10;
      }
      int PlayerStrenght = PlayerFleets[plIndex].WarCruisers * 25 + (BattleExperience / 10) * 25 + AttackerBonus;
      int Result = PlayerStrenght - EnemyStrenght;
      if (Result > 0)
      {
        garrison.WarCruisers = 0;
        PlayerFleets[plIndex].WarCruisers -= (EnemyStrenght / 25);
        if (PlayerFleets[plIndex].WarCruisers < 0)
        {
          PlayerFleets[plIndex].WarCruisers = 0;
        }
      }
      else if (Result < 0)
      {
        PlayerFleets[plIndex].WarCruisers = 0;
        garrison.WarCruisers -= (PlayerStrenght / 25);
        if (garrison.WarCruisers < 0)
        {
          garrison.WarCruisers = 0;
        }
      }
      else
      {
        PlayerFleets[plIndex].WarCruisers = 0;
        garrison.WarCruisers = 0;
      }     
    }
  }
  else
  {
    if (PlayerShips [3] > 0)
    {
      int PlayerStrenght = (PlayerShips[3] * 25) + BattleExperience;
      int AttackerBonus = 0;
      if (EnemyFleets[enIndex].WarCruisers > 0)
      {
         AttackerBonus = (EnemyFleets[enIndex].WarCruisers * 25) / 10;
      }
      int EnemyStrenght = (EnemyFleets[enIndex].WarCruisers * 25) + AttackerBonus;
      int Result = EnemyStrenght - PlayerStrenght;
      if (Result > 0) //Player lose
      {
        PlayerShips[3] = 0;
        EnemyFleets[enIndex].WarCruisers -= (PlayerStrenght / 25);
        if (EnemyFleets[enIndex].WarCruisers < 0)
        {
          EnemyFleets[enIndex].WarCruisers = 0;
        }
      }
      else if (Result < 0) //Player defend
      {
        EnemyFleets[enIndex].WarCruisers = 0;
        PlayerShips[3] -= (EnemyStrenght / 25);
        if (PlayerShips[3] < 0)
        {
          PlayerShips[3] = 0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].WarCruisers = 0;
        PlayerShips[3] = 0;
      }
    }  
  }
}

void resolveStarDreadnoughtsBattle(int enIndex, int plIndex, bool attacker, EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    if (PlayerFleets[plIndex].StarDreadnoughts > 0)
    {
      int EnemyStrenght = garrison.StarDreadnoughts * 50;
      int AttackerBonus = 0;
      if (PlayerFleets[plIndex].StarDreadnoughts > 0)
      {
         AttackerBonus = (PlayerFleets[plIndex].StarDreadnoughts * 50) / 10;
      }
      int PlayerStrenght = PlayerFleets[plIndex].StarDreadnoughts * 50 + (BattleExperience / 10) * 50 + AttackerBonus;
      int Result = PlayerStrenght - EnemyStrenght;
      if (Result > 0)
      {
        garrison.StarDreadnoughts = 0;
        PlayerFleets[plIndex].StarDreadnoughts -= (EnemyStrenght / 50);
        if (PlayerFleets[plIndex].StarDreadnoughts < 0)
        {
          PlayerFleets[plIndex].StarDreadnoughts = 0;
        }
      }
      else if (Result < 0)
      {
        PlayerFleets[plIndex].StarDreadnoughts = 0;
        garrison.StarDreadnoughts -= (PlayerStrenght / 50);
        if (garrison.StarDreadnoughts < 0)
        {
          garrison.StarDreadnoughts = 0;
        }
      }
      else
      {
        PlayerFleets[plIndex].StarDreadnoughts = 0;
        garrison.StarDreadnoughts = 0;
      }     
    }
  }
  else
  {
    if (PlayerShips[4] > 0)
    {
      int PlayerStrenght = (PlayerShips[4] * 50) + BattleExperience;
      int AttackerBonus = 0;
      if (EnemyFleets[enIndex].StarDreadnoughts > 0)
      {
         AttackerBonus = (EnemyFleets[enIndex].StarDreadnoughts * 50) / 10;
      }
      int EnemyStrenght = (EnemyFleets[enIndex].StarDreadnoughts * 50) + AttackerBonus;
      int Result = EnemyStrenght - PlayerStrenght;
      if (Result > 0) //Player lose
      {
        PlayerShips[4] = 0;
        EnemyFleets[enIndex].StarDreadnoughts -= (PlayerStrenght / 50);
        if (EnemyFleets[enIndex].StarDreadnoughts < 0)
        {
          EnemyFleets[enIndex].StarDreadnoughts = 0;
        }
      }
      else if (Result < 0) //Player defend
      {
        EnemyFleets[enIndex].StarDreadnoughts = 0;
        PlayerShips[4] -= (EnemyStrenght / 50);
        if(PlayerShips[4] < 0)
        {
          PlayerShips[4] = 0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].StarDreadnoughts = 0;
        PlayerShips[4] = 0;
      }
    }  
  }
}

void resolveSolarDestructorsBattle(int enIndex, int plIndex, bool attacker, EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    if (PlayerFleets[plIndex].SolarDestroyers)
    {
      int EnemyStrenght = garrison.SolarDestroyers*200;
      int AttackerBonus = 0;
      if (PlayerFleets[plIndex].SolarDestroyers > 0)
      {
         AttackerBonus = (PlayerFleets[plIndex].SolarDestroyers * 200) / 10;
      }
      int PlayerStrenght = PlayerFleets[plIndex].SolarDestroyers * 200 + (BattleExperience / 10) * 200 + AttackerBonus;
      int Result = PlayerStrenght - EnemyStrenght;
      if (Result > 0)
      {
        garrison.SolarDestroyers = 0;
        PlayerFleets[plIndex].SolarDestroyers -= (EnemyStrenght / 200);
        if (PlayerFleets[plIndex].SolarDestroyers < 0)
        {
          PlayerFleets[plIndex].SolarDestroyers = 0;
        }
      }
      else if (Result < 0)
      {
        PlayerFleets[plIndex].SolarDestroyers = 0;
        garrison.SolarDestroyers -= (PlayerStrenght / 200);
        if (garrison.SolarDestroyers < 0)
        {
          garrison.SolarDestroyers = 0;
        }
      }
      else
      {
        PlayerFleets[plIndex].SolarDestroyers = 0;
        garrison.SolarDestroyers = 0;
      }     
    }
  }
  else
  {
    if (PlayerShips[5] > 0)
    {
      int PlayerStrenght = (PlayerShips[5] * 200) + BattleExperience;
      int AttackerBonus = 0;
      if (EnemyFleets[enIndex].SolarDestroyers > 0)
      {
         AttackerBonus = (EnemyFleets[enIndex].SolarDestroyers * 200) / 10;
      }
      int EnemyStrenght = (EnemyFleets[enIndex].SolarDestroyers * 200) + AttackerBonus;
      int Result = EnemyStrenght - PlayerStrenght;
      if (Result > 0) //Player lose
      {
        PlayerShips[5] = 0;
        EnemyFleets[enIndex].SolarDestroyers -= (PlayerStrenght / 200);
        if (EnemyFleets[enIndex].SolarDestroyers < 0)
        {
          EnemyFleets[enIndex].SolarDestroyers = 0;
        }
      }
      else if (Result < 0) //Player defend
      {
        EnemyFleets[enIndex].SolarDestroyers = 0;
        PlayerShips[5] -= (EnemyStrenght / 200);
        if (PlayerShips[5] < 0)
        {
          PlayerShips[5] = 0;
        }
      }
      else //draw
      {
        EnemyFleets[enIndex].SolarDestroyers = 0;
        PlayerShips[5] = 0;
      }
    }  
  }
}

void resolveSecondRound(int enIndex,int plIndex,bool attacker,EnemyGarrison& garrison)
{
  int EnemyStrength = 0;
  int PlayerStrength = 0;
  if (attacker == true)
  {
    EnemyStrength += garrison.Fighters;
    EnemyStrength += (garrison.Interceptors * 3);
    EnemyStrength += (garrison.Frigates * 10);
    EnemyStrength += (garrison.WarCruisers * 25);
    EnemyStrength += (garrison.StarDreadnoughts * 50);
    EnemyStrength += (garrison.SolarDestroyers * 200);
    
    PlayerStrength += PlayerFleets[plIndex].Fighters;
    PlayerStrength += (PlayerFleets[plIndex].Interceptors * 3);
    PlayerStrength += (PlayerFleets[plIndex].Frigates * 10);
    PlayerStrength += (PlayerFleets[plIndex].WarCruisers * 25);
    PlayerStrength += (PlayerFleets[plIndex].StarDreadnoughts * 50);
    PlayerStrength += (PlayerFleets[plIndex].SolarDestroyers * 200);
    
    //----------------------Enemy casaulties-------------
    if (garrison.SolarDestroyers > 0 && PlayerStrength >= 200)
    {
      int casaulties = PlayerStrength / 200;
      int discrepancy = garrison.SolarDestroyers - casaulties;
      if (discrepancy >= 0)
      {
        garrison.SolarDestroyers -= casaulties;
        PlayerStrength -= casaulties * 200;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        garrison.SolarDestroyers -= fixed;
        PlayerStrength -= fixed * 200;
      }
    }

    if (garrison.StarDreadnoughts > 0 && PlayerStrength >= 50)
    {
      int casaulties = PlayerStrength / 50;
      int discrepancy = garrison.StarDreadnoughts - casaulties;
      if (discrepancy >= 0)
      {
        garrison.StarDreadnoughts -= casaulties;
        PlayerStrength -= casaulties * 50;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        garrison.StarDreadnoughts -= fixed;
        PlayerStrength -= fixed * 50;
      }
    }

    if (garrison.WarCruisers > 0 && PlayerStrength >= 25)
    {
      int casaulties = PlayerStrength / 25;
      int discrepancy = garrison.WarCruisers - casaulties;
      if (discrepancy >= 0)
      {
        garrison.WarCruisers -= casaulties;
        PlayerStrength -= casaulties * 25;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        garrison.WarCruisers -= fixed;
        PlayerStrength -= fixed * 25;
      }
    }

    if (garrison.Frigates > 0 && PlayerStrength >= 10)
    {
      int casaulties = PlayerStrength / 10;
      int discrepancy = garrison.Frigates - casaulties;
      if (discrepancy >= 0)
      {
        garrison.Frigates -= casaulties;
        PlayerStrength -= casaulties * 10;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        garrison.Frigates -= fixed;
        PlayerStrength -= fixed * 10;
      }
    }

    if (garrison.Interceptors > 0 && PlayerStrength >= 3)
    {
      int casaulties = PlayerStrength / 3;
      int discrepancy = garrison.Interceptors - casaulties;
      if (discrepancy >= 0)
      {
        garrison.Interceptors -= casaulties;
        PlayerStrength -= casaulties * 3;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        garrison.Interceptors -= fixed;
        PlayerStrength -= fixed * 3;
      }
    }

    if (garrison.Fighters > 0 && PlayerStrength >= 1)
    {
      int casaulties = PlayerStrength;
      int discrepancy = garrison.Fighters - casaulties;
      if (discrepancy >= 0)
      {
        garrison.Fighters -= casaulties;
        PlayerStrength -= casaulties;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        garrison.Fighters -= fixed;
        PlayerStrength -= fixed;
      }
    }
    //----------------------Player casaulties-----------
    if (PlayerFleets[plIndex].SolarDestroyers > 0 && EnemyStrength >= 200)
    {
      int casaulties = EnemyStrength / 200;
      int discrepancy = PlayerFleets[plIndex].SolarDestroyers - casaulties;
      if (discrepancy >= 0)
      {
        PlayerFleets[plIndex].SolarDestroyers -= casaulties;
        EnemyStrength -= casaulties * 200;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerFleets[plIndex].SolarDestroyers -= fixed;
        EnemyStrength -= fixed * 200;
      }
    }

    if (PlayerFleets[plIndex].StarDreadnoughts > 0 && EnemyStrength >= 50)
    {
      int casaulties = EnemyStrength / 50;
      int discrepancy = PlayerFleets[plIndex].StarDreadnoughts - casaulties;
      if (discrepancy >= 0)
      {
        PlayerFleets[plIndex].StarDreadnoughts -= casaulties;
        EnemyStrength -= casaulties * 50;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerFleets[plIndex].StarDreadnoughts -= fixed;
        EnemyStrength -= fixed * 50;
      }
    }

    if (PlayerFleets[plIndex].WarCruisers > 0 && EnemyStrength >= 25)
    {
      int casaulties = EnemyStrength / 25;
      int discrepancy = PlayerFleets[plIndex].WarCruisers - casaulties;
      if (discrepancy >= 0)
      {
        PlayerFleets[plIndex].WarCruisers -= casaulties;
        EnemyStrength -= casaulties * 25;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerFleets[plIndex].WarCruisers -= fixed;
        EnemyStrength -= fixed * 25;
      }
    }

    if (PlayerFleets[plIndex].Frigates > 0 && EnemyStrength >= 10)
    {
      int casaulties = EnemyStrength / 10;
      int discrepancy = PlayerFleets[plIndex].Frigates - casaulties;
      if (discrepancy >= 0)
      {
        PlayerFleets[plIndex].Frigates -= casaulties;
        EnemyStrength -= casaulties * 10;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerFleets[plIndex].Frigates -= fixed;
        EnemyStrength -= fixed * 10;
      }
    }

    if (PlayerFleets[plIndex].Interceptors > 0 && EnemyStrength >= 3)
    {
      int casaulties = EnemyStrength / 3;
      int discrepancy = PlayerFleets[plIndex].Interceptors - casaulties;
      if (discrepancy >= 0)
      {
        PlayerFleets[plIndex].Interceptors -= casaulties;
        EnemyStrength -= casaulties * 3;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerFleets[plIndex].Interceptors -= fixed;
        EnemyStrength -= fixed * 3;
      }
    }

    if (PlayerFleets[plIndex].Fighters > 0 && EnemyStrength >= 1)
    {
      int casaulties = EnemyStrength;
      int discrepancy = PlayerFleets[plIndex].Fighters - casaulties;
      if (discrepancy >= 0)
      {
        PlayerFleets[plIndex].Fighters -= casaulties;
        EnemyStrength -= casaulties;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerFleets[plIndex].Fighters -= fixed;
        EnemyStrength -= fixed;
      }
    }
  }
  else
  {
    EnemyStrength += EnemyFleets[enIndex].Fighters;
    EnemyStrength += (EnemyFleets[enIndex].Interceptors * 3);
    EnemyStrength += (EnemyFleets[enIndex].Frigates * 10);
    EnemyStrength += (EnemyFleets[enIndex].WarCruisers * 25);
    EnemyStrength += (EnemyFleets[enIndex].StarDreadnoughts * 50);
    EnemyStrength += (EnemyFleets[enIndex].SolarDestroyers * 200);
    
    PlayerStrength += PlayerShips[0];
    PlayerStrength += (PlayerShips[1] * 3);
    PlayerStrength += (PlayerShips[2] * 10);
    PlayerStrength += (PlayerShips[3] * 25);
    PlayerStrength += (PlayerShips[4] * 50);
    PlayerStrength += (PlayerShips[5] * 200);

    //----------------------Enemy casaulties-------------
    if (EnemyFleets[enIndex].SolarDestroyers > 0 && PlayerStrength >= 200)
    {
      int casaulties = PlayerStrength / 200;
      int discrepancy = EnemyFleets[enIndex].SolarDestroyers - casaulties;
      if (discrepancy >= 0)
      {
        EnemyFleets[enIndex].SolarDestroyers -= casaulties;
        PlayerStrength -= casaulties * 200;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        EnemyFleets[enIndex].SolarDestroyers -= fixed;
        PlayerStrength -= fixed * 200;
      }
    }

    if (EnemyFleets[enIndex].StarDreadnoughts > 0 && PlayerStrength >= 50)
    {
      int casaulties = PlayerStrength / 50;
      int discrepancy = EnemyFleets[enIndex].StarDreadnoughts - casaulties;
      if (discrepancy >= 0)
      {
        EnemyFleets[enIndex].StarDreadnoughts -= casaulties;
        PlayerStrength -= casaulties * 50;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        EnemyFleets[enIndex].StarDreadnoughts -= fixed;
        PlayerStrength -= fixed * 50;
      }
    }

    if (EnemyFleets[enIndex].WarCruisers > 0 && PlayerStrength >= 25)
    {
      int casaulties = PlayerStrength / 25;
      int discrepancy = EnemyFleets[enIndex].WarCruisers - casaulties;
      if (discrepancy >= 0)
      {
        EnemyFleets[enIndex].WarCruisers -= casaulties;
        PlayerStrength -= casaulties * 25;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        EnemyFleets[enIndex].WarCruisers -= fixed;
        PlayerStrength -= fixed * 25;
      }
    }

    if (EnemyFleets[enIndex].Frigates > 0 && PlayerStrength >= 10)
    {
      int casaulties = PlayerStrength / 10;
      int discrepancy = EnemyFleets[enIndex].Frigates - casaulties;
      if (discrepancy >= 0)
      {
        EnemyFleets[enIndex].Frigates -= casaulties;
        PlayerStrength -= casaulties * 10;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        EnemyFleets[enIndex].Frigates -= fixed;
        PlayerStrength -= fixed * 10;
      }
    }

    if (EnemyFleets[enIndex].Interceptors > 0 && PlayerStrength >= 3)
    {
      int casaulties = PlayerStrength / 3;
      int discrepancy = EnemyFleets[enIndex].Interceptors - casaulties;
      if (discrepancy >= 0)
      {
        EnemyFleets[enIndex].Interceptors -= casaulties;
        PlayerStrength -= casaulties * 3;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        EnemyFleets[enIndex].Interceptors -= fixed;
        PlayerStrength -= fixed * 3;
      }
    }

    if (EnemyFleets[enIndex].Fighters > 0 && PlayerStrength >= 1)
    {
      int casaulties = PlayerStrength;
      int discrepancy = EnemyFleets[enIndex].Fighters - casaulties;
      if (discrepancy >= 0)
      {
        EnemyFleets[enIndex].Fighters -= casaulties;
        PlayerStrength -= casaulties;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        EnemyFleets[enIndex].Fighters -= fixed;
        PlayerStrength -= fixed;
      }
    }
    //----------------------Player casaulties-----------
    if (PlayerShips[5] > 0 && EnemyStrength >= 200)
    {
      int casaulties = EnemyStrength / 200;
      int discrepancy = PlayerShips[5] - casaulties;
      if (discrepancy >= 0)
      {
        PlayerShips[5] -= casaulties;
        EnemyStrength -= casaulties * 200;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerShips[5] -= fixed;
        EnemyStrength -= fixed * 200;
      }
    }

    if (PlayerShips[4] > 0 && EnemyStrength >= 50)
    {
      int casaulties = EnemyStrength / 50;
      int discrepancy = PlayerShips[4] - casaulties;
      if (discrepancy >= 0)
      {
        PlayerShips[4] -= casaulties;
        EnemyStrength -= casaulties * 50;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerShips[4] -= fixed;
        EnemyStrength -= fixed * 50;
      }
    }

    if (PlayerShips[3] > 0 && EnemyStrength >= 25)
    {
      int casaulties = EnemyStrength / 25;
      int discrepancy = PlayerShips[3] - casaulties;
      if (discrepancy >= 0)
      {
        PlayerShips[3] -= casaulties;
        EnemyStrength -= casaulties * 25;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerShips[3] -= fixed;
        EnemyStrength -= fixed * 25;
      }
    }

    if (PlayerShips[2] > 0 && EnemyStrength >= 10)
    {
      int casaulties = EnemyStrength / 10;
      int discrepancy = PlayerShips[2] - casaulties;
      if (discrepancy >= 0)
      {
        PlayerShips[2] -= casaulties;
        EnemyStrength -= casaulties * 10;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerShips[2] -= fixed;
        EnemyStrength -= fixed * 10;
      }
    }

    if (PlayerShips[1] > 0 && EnemyStrength >= 3)
    {
      int casaulties = EnemyStrength / 3;
      int discrepancy = PlayerShips[1] - casaulties;
      if (discrepancy >= 0)
      {
        PlayerShips[1] -= casaulties;
        EnemyStrength -= casaulties * 3;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerShips[1] -= fixed;
        EnemyStrength -= fixed * 3;
      }
    }

    if (PlayerShips[0] > 0 && EnemyStrength >= 1)
    {
      int casaulties = EnemyStrength;
      int discrepancy = PlayerShips[0] - casaulties;
      if (discrepancy >= 0)
      {
        PlayerShips[0] -= casaulties;
        EnemyStrength -= casaulties;
      }
      else
      {
        int fixed = casaulties + discrepancy;
        PlayerShips[0] -= fixed;
        EnemyStrength -= fixed;
      }
    }
  }
}

int8_t determineWinner(int enIndex, int plIndex, bool attacker, EnemyGarrison& garrison)
{
  int EnemyPoints = 0;
  int PlayerPoints = 0;
  if (attacker == true)
  {
    EnemyPoints += garrison.Fighters;
    EnemyPoints += (garrison.Interceptors * 2);
    EnemyPoints += (garrison.Frigates * 3);
    EnemyPoints += (garrison.WarCruisers * 5);
    EnemyPoints += (garrison.StarDreadnoughts * 8);
    EnemyPoints += (garrison.SolarDestroyers * 10);
    PlayerPoints += PlayerFleets[plIndex].Fighters;
    PlayerPoints += (PlayerFleets[plIndex].Interceptors * 2);
    PlayerPoints += (PlayerFleets[plIndex].Frigates * 3);
    PlayerPoints += (PlayerFleets[plIndex].WarCruisers * 5);
    PlayerPoints += (PlayerFleets[plIndex].StarDreadnoughts * 8);
    PlayerPoints += (PlayerFleets[plIndex].SolarDestroyers * 10);
  }
  else
  {
    EnemyPoints += EnemyFleets[enIndex].Fighters;
    EnemyPoints += (EnemyFleets[enIndex].Interceptors * 2);
    EnemyPoints += (EnemyFleets[enIndex].Frigates * 3);
    EnemyPoints += (EnemyFleets[enIndex].WarCruisers * 5);
    EnemyPoints += (EnemyFleets[enIndex].StarDreadnoughts * 8);
    EnemyPoints += (EnemyFleets[enIndex].SolarDestroyers * 10);
    PlayerPoints += PlayerShips[0];
    PlayerPoints += (PlayerShips[1] * 2);
    PlayerPoints += (PlayerShips[2] * 3);
    PlayerPoints += (PlayerShips[3] * 5);
    PlayerPoints += (PlayerShips[4] * 8);
    PlayerPoints += (PlayerShips[5] * 10);
    if (PlayerPoints > 0)//At least one ship survived
    {
      int DefenceStrength = Colony[8].level * 5;
      PlayerPoints += DefenceStrength;
    }
  }
  
  if (PlayerPoints > EnemyPoints) //PLAYER WINS
  {
    return 1;
  }
  else if (PlayerPoints < EnemyPoints) //ENEMY WINS
  {
    return 2;
  }
  else //DRAW
  {
    return 0;
  }
}

void reportLosses(int enIndex, int plIndex, bool attacker, int8_t winner, EnemyGarrison& garrison)
{
  if (attacker == true)
  {
    BtResult.PlFightersLost = BtResult.PlFighters - PlayerFleets[plIndex].Fighters;
    BtResult.EnFightersLost = BtResult.EnFighters - garrison.Fighters;
    BtResult.PlInterceptorsLost = BtResult.PlInterceptors - PlayerFleets[plIndex].Interceptors;
    BtResult.EnInterceptorsLost = BtResult.EnInterceptors - garrison.Interceptors;
    BtResult.PlFrigatesLost = BtResult.PlFrigates - PlayerFleets[plIndex].Frigates;
    BtResult.EnFrigatesLost = BtResult.EnFrigates - garrison.Frigates;
    BtResult.PlWarCruisersLost = BtResult.PlWarCruisers - PlayerFleets[plIndex].WarCruisers;
    BtResult.EnWarCruisersLost = BtResult.EnWarCruisers - garrison.WarCruisers;
    BtResult.PlStarDreadnoughtsLost = BtResult.PlStarDreadnoughts - PlayerFleets[plIndex].StarDreadnoughts;
    BtResult.EnStarDreadnoughtsLost = BtResult.EnStarDreadnoughts - garrison.StarDreadnoughts;
    BtResult.PlSolarDestroyersLost = BtResult.PlSolarDestroyers - PlayerFleets[plIndex].SolarDestroyers;
    BtResult.EnSolarDestroyersLost = BtResult.EnSolarDestroyers - garrison.SolarDestroyers;
  }
  else
  {
    BtResult.PlFightersLost = BtResult.PlFighters - PlayerShips[0];
    BtResult.EnFightersLost = BtResult.EnFighters - EnemyFleets[enIndex].Fighters;
    BtResult.PlInterceptorsLost = BtResult.PlInterceptors - PlayerShips[1];
    BtResult.EnInterceptorsLost = BtResult.EnInterceptors - EnemyFleets[enIndex].Interceptors;
    BtResult.PlFrigatesLost = BtResult.PlFrigates - PlayerShips[2];
    BtResult.EnFrigatesLost = BtResult.EnFrigates - EnemyFleets[enIndex].Frigates;
    BtResult.PlWarCruisersLost = BtResult.PlWarCruisers - PlayerShips[3];
    BtResult.EnWarCruisersLost = BtResult.EnWarCruisers - EnemyFleets[enIndex].WarCruisers;
    BtResult.PlStarDreadnoughtsLost = BtResult.PlStarDreadnoughts - PlayerShips[4];
    BtResult.EnStarDreadnoughtsLost = BtResult.EnStarDreadnoughts - EnemyFleets[enIndex].StarDreadnoughts;
    BtResult.PlSolarDestroyersLost = BtResult.PlSolarDestroyers - PlayerShips[5];
    BtResult.EnSolarDestroyersLost = BtResult.EnSolarDestroyers - EnemyFleets[enIndex].SolarDestroyers;
  }
  BtResult.Winner = winner;
}

bool battleResults()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    flReportPage = 1;
    return true;
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (flReportPage == 1)
    {
      flReportPage = 2;
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (flReportPage == 2)
    {
      flReportPage = 1;
    }
  }

  if (flReportPage == 1)
  {
    drawBattleResult1();
  }
  else
  {
    drawBattleResult2();
  }
  return false;
}
