//---------------------------LOAD------------------------------
void loadGame()
{
  loadSystem();
  loadTechs();
  loadBuildings();
  loadGarrisons(Enemy1Garrison, 3);
  loadGarrisons(Enemy2Garrison, 4);
  loadFleets(PlayerFleets, 5);
  loadFleets(EnemyFleets, 6);
  loadPlayerShips();
  loadTradeRoutes();
  loadReports();
  loadGameVariables();
  checkAndSetTotalColoniesCount();
}

void loadSystem()
{
  char RawPlanetData[349];
  gb.save.get(0, RawPlanetData);
  String PlanetsData(RawPlanetData);
  
  for (int i = 1; i < 30; i++)
  {
    String Part = PlanetsData.substring((i -1 ) * 12,(( i - 1) * 12) + 12);
    if (Part.substring(0, 1) == "1")
    {
      System[i].Discovered = true;
    }
    else
    {
      System[i].Discovered = false;
    }
    if (Part.substring(1, 2) == "1")
    {
      System[i].Hostile = true;
    }
    else
    {
      System[i].Hostile = false;
    }
    System[i].Resource1 = Part.substring(2, 3).toInt();
    System[i].Resource2 = Part.substring(3, 4).toInt();
    System[i].Resource3 = Part.substring(4, 5).toInt();
    if (Part.substring(5, 6) == "1")
    {
      System[i].Owned = true;
    }
    else
    {
      System[i].Owned = false;
    }
    if (Part.substring(6, 7) == "1")
    {
      System[i].TradeRoute = true;
    }
    else
    {
      System[i].TradeRoute = false;
    }
    System[i].GarrisonIndex = Part.substring(7, 9).toInt();
    if (Part.substring(9, 10) == "1")
    {
      System[i].Status=true;
    }
    else
    {
      System[i].Status=false;
    }
    if (Part.substring(10, 11) == "1")
    {
      System[i].ActiveMission = true;
    }
    else
    {
      System[i].ActiveMission = false;
    }
    System[i].Affilation = Part.substring(11, 12).toInt();  
  }
}

void loadTechs()
{
  char RawTechData[81];
  gb.save.get(1, RawTechData);
  String TechsData(RawTechData);
  
  for (int i = 0; i < 20; i++)
  {
    String Part = TechsData.substring(i * 4, (i * 4) + 4);
    TechTree[i].level = Part.substring(0, 2).toInt();
    TechTree[i].depTechLevel=Part.substring(2, 4).toInt();
  }
}

void loadBuildings()
{
  char RawBuildData[91];
  gb.save.get(2, RawBuildData);
  String BuildingsData(RawBuildData);
  
  for (int i = 0; i < 15; i++)
  {
    String Part = BuildingsData.substring(i * 6, (i * 6) + 6);
    Colony[i].level = Part.substring(0, 2).toInt();
    Colony[i].depTechLevel = Part.substring(2, 4).toInt();
    Colony[i].depBuildingLevel = Part.substring(4, 6).toInt();
  }
}

void loadGarrisons(EnemyGarrison GarrisonArray[6], uint16_t block)
{
  char RawGarData[157];
  gb.save.get(block, RawGarData);
  String GarrisonData(RawGarData);
  
  for (int i = 0; i < 6; i++)
  {
    String Part = GarrisonData.substring(i * 26, (i * 26) + 26);
    GarrisonArray[i].planetIndex = Part.substring(0, 2).toInt();
    GarrisonArray[i].Fighters = Part.substring(2, 6).toInt();
    GarrisonArray[i].Interceptors = Part.substring(6, 10).toInt();
    GarrisonArray[i].Frigates = Part.substring(10, 14).toInt();
    GarrisonArray[i].WarCruisers = Part.substring(14, 18).toInt();
    GarrisonArray[i].StarDreadnoughts = Part.substring(18, 22).toInt();
    GarrisonArray[i].SolarDestroyers = Part.substring(22, 26).toInt();
  }
}

void loadFleets(Fleet Fleets[4], uint16_t block)
{
  char RawFleetData[257];
  gb.save.get(block, RawFleetData);
  String FleetData(RawFleetData);
  
  for (int i = 0; i < 4; i++)
  {
    String Part = FleetData.substring(i * 64, (i * 64) + 64);
    Fleets[i].Type = Part.substring(0, 1).toInt();
    if (Part.substring(1, 2) == "1")
    {
      Fleets[i].Active = true;
    }
    else
    {
      Fleets[i].Active = false;
    }
    Fleets[i].Minutes = Part.substring(2, 4).toInt();
    Fleets[i].Seconds = Part.substring(4, 6).toInt();
    Fleets[i].SpyBots = Part.substring(6, 10).toInt();
    Fleets[i].Colonizers = Part.substring(10, 14).toInt();
    Fleets[i].Fighters = Part.substring(14, 18).toInt();
    Fleets[i].Interceptors = Part.substring(18, 22).toInt();
    Fleets[i].Frigates = Part.substring(22, 26).toInt();
    Fleets[i].WarCruisers = Part.substring(26, 30).toInt();
    Fleets[i].StarDreadnoughts = Part.substring(30, 34).toInt();
    Fleets[i].SolarDestroyers = Part.substring(34, 38).toInt();
    Fleets[i].Stalkers = Part.substring(38, 42).toInt();
    Fleets[i].Leviatans = Part.substring(42, 46).toInt();
    Fleets[i].Missles = Part.substring(46, 48).toInt();
    String Destination = Part.substring(48, 62);
    Fleets[i].DestinationName = removeSpaces(Destination);
    if (Part.substring(62, 63) == "1")
    {
      Fleets[i].Visible = true;
    }
    else
    {
      Fleets[i].Visible = false;
    }
    Fleets[i].InterceptionId = Part.substring(63, 64).toInt();
  }
}

void loadPlayerShips()
{
  char RawPlShipsData[57];
  gb.save.get(7, RawPlShipsData);
  String ShipsData(RawPlShipsData);
  
  String Part = ShipsData.substring(0, 56);
  PlayerShips[0] = Part.substring(0, 4).toInt();
  PlayerShips[1] = Part.substring(4, 8).toInt();
  PlayerShips[2] = Part.substring(8, 12).toInt();
  PlayerShips[3] = Part.substring(12, 16).toInt();
  PlayerShips[4] = Part.substring(16, 20).toInt();
  PlayerShips[5] = Part.substring(20, 24).toInt();
  PlayerShips[6] = Part.substring(24, 28).toInt();
  PlayerShips[7] = Part.substring(28, 32).toInt();
  PlayerShips[8] = Part.substring(32, 36).toInt();
  PlayerShips[9] = Part.substring(36, 40).toInt();
  PlayerShips[10] = Part.substring(40, 44).toInt();
  PlayerShips[11] = Part.substring(44, 48).toInt();
  PlayerShips[12] = Part.substring(48, 52).toInt();
  PlayerShips[13] = Part.substring(52, 56).toInt();
}

void loadTradeRoutes()
{
  char RawPlRoutesData[217];
  gb.save.get(8, RawPlRoutesData);
  String RoutesData(RawPlRoutesData);

  for (int i = 0; i < 12; i++)
  {
    String Part = RoutesData.substring(i * 18, (i * 18) + 18);
    if (Part.substring(0, 1) == "1")
    {
      PlayerRoutes[i].Active = true;
    }
    else
    {
      PlayerRoutes[i].Active = false;
    }
    String Name = Part.substring(1, 15);
    PlayerRoutes[i].Name = removeSpaces(Name);
    PlayerRoutes[i].Metal = Part.substring(15, 16).toInt();
    PlayerRoutes[i].Crystal = Part.substring(16, 17).toInt();
    PlayerRoutes[i].Fuel = Part.substring(17, 18).toInt();
  }
}

void loadReports()
{
  char RawReportsData[337];
  gb.save.get(9, RawReportsData);
  String ReportData(RawReportsData);
  
  for (int i = 0; i < 8; i++)
  {
    String Part = ReportData.substring(i * 42, (i * 42) + 42);
    String Name = Part.substring(0, 14);
    IntelligenceReports[i].PlanetName = removeSpaces(Name);
    IntelligenceReports[i].Type = Part.substring(14, 15).toInt();
    IntelligenceReports[i].Fighters = Part.substring(15, 19).toInt();
    IntelligenceReports[i].Interceptors = Part.substring(19, 23).toInt();
    IntelligenceReports[i].Frigates = Part.substring(23, 27).toInt();
    IntelligenceReports[i].WarCruisers = Part.substring(27, 31).toInt();
    IntelligenceReports[i].StarDreadnoughts = Part.substring(31, 35).toInt();
    IntelligenceReports[i].SolarDestroyers = Part.substring(35, 39).toInt();
    IntelligenceReports[i].Resource1 = Part.substring(39, 40).toInt();
    IntelligenceReports[i].Resource2 = Part.substring(40, 41).toInt();
    IntelligenceReports[i].Resource3 = Part.substring(41, 42).toInt();
  }
}

void loadGameVariables()
{
  char RawGameData[49];
  gb.save.get(10, RawGameData);
  String GameData(RawGameData);
  
  String Part = GameData.substring(0, 48);
  PlayerResources[0] = Part.substring(0, 4).toInt();
  PlayerResources[1] = Part.substring(4, 8).toInt();
  PlayerResources[2] = Part.substring(8, 12).toInt();
  BattleExperience = Part.substring(12, 16).toInt();
  EnemyCount = Part.substring(16, 17).toInt();
  Difficulty = removeSpaces(Part.substring(17, 31));
  ProgressPoints = Part.substring(31, 34).toInt();
  ProgressPointsLimit = Part.substring(34, 37).toInt();
  Score = Part.substring(37, 43).toInt();
  int loadedTimeToAttack = Part.substring(43, 46).toInt();
  if (loadedTimeToAttack == 999)
  {
    timeToAttack = -1;
  }
  else
  {
    timeToAttack = loadedTimeToAttack;
  }
  if (Part.substring(46, 47) == "1")
  {
    attackUnderway = true;
  }
  else
  {
    attackUnderway = false; 
  }
  attackCounter = Part.substring(47, 48).toInt();
}

//---------------------------SAVE------------------------------
void saveGame()
{
  if (saveDataSystem() == false)
  {
    gb.gui.popup("ERROR: SAVE SYS", 50);
    return;
  }
  if (saveDataTechs() == false)
  {
    gb.gui.popup("ERROR: SAVE TECH", 50);
    return;
  }
  if (saveDataBuildings() == false)
  {
    gb.gui.popup("ERROR: SAVE BUIL", 50);
    return;
  }
  if (saveDataGarrison(Enemy1Garrison, 3) == false)
  {
    gb.gui.popup("ERROR: SAVE EN1GAR", 50);
    return;
  }
  if (saveDataGarrison(Enemy2Garrison, 4) == false)
  {
    gb.gui.popup("ERROR: SAVE EN2GAR", 50);
    return;
  }
  if (saveDataFleets(PlayerFleets, 5) == false)
  {
    gb.gui.popup("ERROR: SAVE PLFLE", 50);
    return;
  }
  if (saveDataFleets(EnemyFleets, 6) == false)
  {
    gb.gui.popup("ERROR: SAVE ENFLE", 50);
    return;
  }  
  if (saveDataPlayerShips() == false)
  {
    gb.gui.popup("ERROR: SAVE SHIPS", 50);
    return;
  }
  if (saveDataRoutes() == false)
  {
    gb.gui.popup("ERROR: SAVE ROUT", 50);
    return;
  }
  if (saveDataReports() == false)
  {
    gb.gui.popup("ERROR: SAVE REP", 50);
    return;
  }
  if (saveDataGameVariables() == false)
  {
    gb.gui.popup("ERROR: SAVE VAR", 50);
    return;
  }
  gb.save.set(16, 1);
  gb.gui.popup("GAME SAVED!", 50);
}

void saveDataToBlock(uint16_t block, String data, int bufferSize)
{
  char Buffer[bufferSize];
  data.toCharArray(Buffer, bufferSize);
  gb.save.set(block, Buffer);
}

bool saveDataSystem()
{
  String strData = "";
  for (int i = 1; i < 30; i++)
  {
    String strPlanet = "";
    if (System[i].Discovered == true) 
    {
      strPlanet += "1";
    }
    else 
    {
      strPlanet += "0";
    }
    if (System[i].Hostile == true) 
    {
      strPlanet += "1";
    }
    else 
    {
      strPlanet += "0";
    }
    strPlanet += (String)System[i].Resource1;
    strPlanet += (String)System[i].Resource2;
    strPlanet += (String)System[i].Resource3;
    if (System[i].Owned == true)
    {
      strPlanet += "1";
    }
    else
    {
      strPlanet += "0";
    }
    if (System[i].TradeRoute == true)
    {
      strPlanet += "1";
    }
    else 
    {
      strPlanet += "0";
    }
    if (System[i].GarrisonIndex >= 0)
    {
      strPlanet += "0" + (String)System[i].GarrisonIndex;
    }
    else
    {
      strPlanet += (String)System[i].GarrisonIndex;
    }
    if (System[i].Status == true)
    {
      strPlanet += "1";
    }
    else 
    {
      strPlanet += "0";
    }
    if (System[i].ActiveMission == true) 
    {
      strPlanet += "1";
    }
    else 
    {
      strPlanet += "0";
    }
    strPlanet += (String)System[i].Affilation;
    strData += strPlanet;
  }
  strData += " ";
  if (strData.length() == 349)
  {
    saveDataToBlock(0, strData, 349);
    return true;
  }
  else
  {
    DebugData = (String)strData.length();
    return false;
  }
}

bool saveDataTechs()
{
  String strData = "";
  for (int i = 0; i < 20; i++)
  {
    if (TechTree[i].level > 9)
    {
      strData += (String)TechTree[i].level;
    }
    else
    {
      strData += "0" + (String)TechTree[i].level;
    }
    if (TechTree[i].depTechLevel > 9)
    {
      strData += (String)TechTree[i].depTechLevel;
    }
    else
    {
      strData += "0" + (String)TechTree[i].depTechLevel;
    }
  }
  strData += " ";
  if (strData.length() == 81)
  {
    saveDataToBlock(1, strData, 81);
    return true;
  }
  else
  {
    DebugData = strData;
    return false;
  }
}

bool saveDataBuildings()
{
  String strData = "";
  for (int i = 0; i < 15; i++)
  {
    if (Colony[i].level > 9)
    {
      strData += (String)Colony[i].level;
    }
    else
    {
      strData += "0" + (String)Colony[i].level;
    }
    if (Colony[i].depTechLevel > 9)
    {
      strData += (String)Colony[i].depTechLevel;
    }
    else
    {
      strData += "0" + (String)Colony[i].depTechLevel;
    }
    if (Colony[i].depBuildingLevel > 9)
    {
      strData += (String)Colony[i].depBuildingLevel;
    }
    else
    {
      strData += "0" + (String)Colony[i].depBuildingLevel;
    }
  }
  strData += " ";
  if (strData.length() == 91)
  {
    saveDataToBlock(2, strData, 91);
    return true;
  }
  else
  {
    DebugData = strData;
    return false;
  }
}

bool saveDataGarrison(EnemyGarrison GarrisonArray[6], uint16_t block)
{
  String strData = "";
  for (int i = 0; i < 6; i++)
  {
    if (GarrisonArray[i].planetIndex > 9 || GarrisonArray[i].planetIndex < 0)
    {
      strData += (String)GarrisonArray[i].planetIndex;
    }
    else
    {
      strData += "0" + (String)GarrisonArray[i].planetIndex;
    }
    strData += returnDecimalString(GarrisonArray[i].Fighters);
    strData += returnDecimalString(GarrisonArray[i].Interceptors);
    strData += returnDecimalString(GarrisonArray[i].Frigates);
    strData += returnDecimalString(GarrisonArray[i].WarCruisers);
    strData += returnDecimalString(GarrisonArray[i].StarDreadnoughts);
    strData += returnDecimalString(GarrisonArray[i].SolarDestroyers);
  }
  strData += " ";
  if (strData.length() == 157)
  {
    saveDataToBlock(block, strData, 157);
    return true;
  }
  else
  {
    DebugData = strData;
    return false;
  }
}

bool saveDataFleets(Fleet Fleets[4], uint16_t block)
{
  String strData = "";
  for (int i = 0; i < 4; i++)
  {
    strData += (String)Fleets[i].Type;
    if (Fleets[i].Active == true) 
    {
      strData += "1";
    }
    else
    {
      strData += "0";
    }
    if (Fleets[i].Minutes > 9)
    {
      strData += (String)Fleets[i].Minutes;
    }
    else
    {
      strData += "0" + (String)Fleets[i].Minutes;
    }
    if (Fleets[i].Seconds>9)
    {
      strData += (String)Fleets[i].Seconds;
    }
    else
    {
      strData += "0" + (String)Fleets[i].Seconds;
    }
    strData += returnDecimalString(Fleets[i].SpyBots);
    strData += returnDecimalString(Fleets[i].Colonizers);
    strData += returnDecimalString(Fleets[i].Fighters);
    strData += returnDecimalString(Fleets[i].Interceptors);
    strData += returnDecimalString(Fleets[i].Frigates);
    strData += returnDecimalString(Fleets[i].WarCruisers);
    strData += returnDecimalString(Fleets[i].StarDreadnoughts);
    strData += returnDecimalString(Fleets[i].SolarDestroyers);
    strData += returnDecimalString(Fleets[i].Stalkers);
    strData += returnDecimalString(Fleets[i].Leviatans);
    strData += returnDecimalStringTwoSpaces(Fleets[i].Missles);
    strData += addSpaces(Fleets[i].DestinationName);
    if (Fleets[i].Visible == true)
    {
      strData += "1"; 
    }
    else
    {
      strData += "0";
    }
    strData += (String)Fleets[i].InterceptionId;
  }
  strData += " ";
  if (strData.length() == 257)
  {
    saveDataToBlock(block, strData, 257);
    return true;
  }
  else
  {
    DebugData = strData;
    return false;
  }
}

bool saveDataPlayerShips()
{
  String strData = "";
  strData += returnDecimalString(PlayerShips[0]);
  strData += returnDecimalString(PlayerShips[1]);
  strData += returnDecimalString(PlayerShips[2]);
  strData += returnDecimalString(PlayerShips[3]);
  strData += returnDecimalString(PlayerShips[4]);
  strData += returnDecimalString(PlayerShips[5]);
  strData += returnDecimalString(PlayerShips[6]);
  strData += returnDecimalString(PlayerShips[7]);
  strData += returnDecimalString(PlayerShips[8]);
  strData += returnDecimalString(PlayerShips[9]);
  strData += returnDecimalString(PlayerShips[10]);
  strData += returnDecimalString(PlayerShips[11]);
  strData += returnDecimalString(PlayerShips[12]);
  strData += returnDecimalString(PlayerShips[13]);
  strData += " ";
  if (strData.length() == 57)
  {
    saveDataToBlock(7, strData, 57);
    return true;
  }
  else
  {
    DebugData = strData;
    return false;
  }
}

bool saveDataRoutes()
{
  String strData = "";
  for (int i = 0; i < 12; i++)
  {
    if (PlayerRoutes[i].Active == true) 
    {
      strData += "1";
    }
    else 
    {
      strData += "0";
    }
    strData += addSpaces(PlayerRoutes[i].Name);
    strData += PlayerRoutes[i].Metal;
    strData += PlayerRoutes[i].Crystal;
    strData += PlayerRoutes[i].Fuel;
  }
  strData += " ";
  if (strData.length() == 217)
  {
    saveDataToBlock(8, strData, 217);
    return true;
  }
  else
  {
    DebugData = strData;
    return false;
  }
}

bool saveDataReports()
{
  String strData = "";
  for (int i = 0; i < 8; i++)
  {
    strData += addSpaces(IntelligenceReports[i].PlanetName);
    strData += (String)IntelligenceReports[i].Type;
    strData += returnDecimalString(IntelligenceReports[i].Fighters);
    strData += returnDecimalString(IntelligenceReports[i].Interceptors);
    strData += returnDecimalString(IntelligenceReports[i].Frigates);
    strData += returnDecimalString(IntelligenceReports[i].WarCruisers);
    strData += returnDecimalString(IntelligenceReports[i].StarDreadnoughts);
    strData += returnDecimalString(IntelligenceReports[i].SolarDestroyers);
    strData += (String)IntelligenceReports[i].Resource1;
    strData += (String)IntelligenceReports[i].Resource2;
    strData += (String)IntelligenceReports[i].Resource3;
  }
  strData += " ";
  if (strData.length() == 337)
  {
    saveDataToBlock(9, strData, 337);
    return true;
  }
  else
  {
    DebugData = strData;
    return false;
  }
}

bool saveDataGameVariables()
{
  String strData = "";
  strData += returnDecimalString(PlayerResources[0]);
  strData += returnDecimalString(PlayerResources[1]);
  strData += returnDecimalString(PlayerResources[2]);
  strData += returnDecimalString(BattleExperience);
  strData += (String)EnemyCount;
  strData += addSpaces(Difficulty);
  strData += returnDecimalStringPoint(ProgressPoints, false);
  strData += returnDecimalStringPoint(ProgressPointsLimit, false);   
  strData += returnDecimalStringScore(Score);
  strData += returnDecimalStringPoint(timeToAttack, true);
  if (attackUnderway == true)
  {
    strData += "1";
  }
  else
  {
    strData += "0";
  }
  strData += (String)attackCounter;
  strData += " ";
  if (strData.length() == 49)
  {
    saveDataToBlock(10, strData, 49);
    return true;
  }
  else
  {
    DebugData = strData;
    return false;
  }
}
//---------------HELPERS---------------------------------
String returnDecimalStringPoint(int number, bool allowBelowZero)
{
  if(number > 99)
  {
    return (String)number;
  }
  else if (number < 100 && number > 9)
  {
    return "0" + (String)number;
  }
  else if (number >= 0)
  {
    return "00" + (String)number;
  }
  else if (number < 0 && allowBelowZero == true)
  {
    return "999";
  }
  else
  {
    return "000";
  }  
}

String returnDecimalStringTwoSpaces(int number)
{
  if (number > 9)
  {
    return (String)number;
  }
  else if (number <= 9 && number >= 0)
  {
    return "0" + (String)number;
  }
  else
  {
    return "00";
  }
}

String returnDecimalString(int number)
{
  if (number > 999)
  {
    return (String)number;
  }
  else if (number < 1000 && number > 99)
  {
    return "0" + (String)number;
  }
  else if (number < 100 && number > 9)
  {
    return "00" + (String)number;
  }
  else if (number >= 0)
  {
    return "000" + (String)number;
  }
  else
  {
    return "0000"; 
  } 
}

String returnDecimalStringScore(int number)
{
  if (number < 1000000 && number > 99999)
  {
    return (String)number;
  }
  else if (number < 100000 && number > 9999)
  {
    return "0" + (String)number;
  }
  else if (number < 10000 && number > 999)
  {
    return "00" + (String)number;
  }
  else if (number < 1000 && number > 99)
  {
    return "000" + (String)number;
  }
  else if (number < 100 && number > 9)
  {
    return "0000" + (String)number;
  }
  else if (number >= 0)
  {
    return "00000" + (String)number;
  }
  else
  {
    return "000000"; 
  } 
}

String removeSpaces(String phrase)
{
  int idx = phrase.indexOf('*');
  if (idx != -1)
  {
    phrase.remove(idx);
  }
  return phrase;
}

String addSpaces(String phrase)
{
  int count = phrase.length();
  if (count < 14)
  {
    int toRemove = 14 - count;
    if (toRemove > 0)
    {
      for (int i = 0; i < toRemove; i++)
      {
        phrase += "*";
      }
    }
  }
  return phrase;
}
