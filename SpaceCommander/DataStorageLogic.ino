//---------------------------LOAD------------------------------
void loadGame()
{
  char RawPlanetData[309];
  char RawTechData[81];
  char RawBuildData[91];
  char RawGar1Data[157];
  char RawGar2Data[157];
  char RawPlFleetData[245];
  char RawEnFleetData[245];
  char RawPlShipsData[53];
  char RawPlRoutesData[217];
  char RawReportsData[211];
  char RawGameData[51];

  gb.save.get(0, RawPlanetData);
  gb.save.get(1, RawTechData);
  gb.save.get(2, RawBuildData);
  gb.save.get(3, RawGar1Data);
  gb.save.get(4, RawGar2Data);
  gb.save.get(5, RawPlFleetData);
  gb.save.get(6, RawEnFleetData);
  gb.save.get(7, RawPlShipsData);
  gb.save.get(8, RawPlRoutesData);
  gb.save.get(9, RawReportsData);
  gb.save.get(10, RawGameData);

  String strPlanetData(RawPlanetData);
  String strTechData(RawTechData);
  String strBuildData(RawBuildData);
  String strGar1Data(RawGar1Data);
  String strGar2Data(RawGar2Data);
  String strPlFleetData(RawPlFleetData);
  String strEnFleetData(RawEnFleetData);
  String strPlShipsData(RawPlShipsData);
  String strPlRoutesData(RawPlRoutesData);
  String strReports(RawReportsData);
  String strGameData(RawGameData);

  loadSystem(strPlanetData);
  loadTechs(strTechData);
  loadBuildings(strBuildData);
  loadGarrisons(strGar1Data,Enemy1Garrison);
  loadGarrisons(strGar2Data,Enemy2Garrison);
  loadFleets(strPlFleetData,PlayerFleets);
  loadFleets(strEnFleetData,EnemyFleets);
  loadPlayerShips(strPlShipsData);
  loadTradeRoutes(strPlRoutesData);
  loadReports(strReports);
  loadGameVariables(strGameData);

  
}

void loadSystem(String PlanetsData)
{
  for(int i=2;i<30;i++)
  {
    String Part=PlanetsData.substring((i-2)*11,((i-2)*11)+11);
    if(Part.substring(0,1)=="1")
      System[i].Discovered=true;
    else
      System[i].Discovered=false;
    if(Part.substring(1,2)=="1")
      System[i].Hostile=true;
    else
      System[i].Hostile=false;
    System[i].Resource1 = Part.substring(2,3).toInt();
    System[i].Resource2 = Part.substring(3,4).toInt();
    System[i].Resource3 = Part.substring(4,5).toInt();
    if(Part.substring(5,6)=="1")
      System[i].Owned=true;
    else
      System[i].Owned=false;
    if(Part.substring(6,7)=="1")
      System[i].TradeRoute=true;
    else
      System[i].TradeRoute=false;
    System[i].GarrisonIndex = Part.substring(7,9).toInt();
    if(Part.substring(9,10)=="1")
      System[i].Status=true;
    else
      System[i].Status=false;
    if(Part.substring(10,11)=="1")
      System[i].ActiveMission=true;
    else
      System[i].ActiveMission=false;  
  }
}

void loadTechs(String TechsData)
{
  for(int i=0;i<20;i++)
  {
    String Part=TechsData.substring(i*4,(i*4)+4);
    TechTree[i].level=Part.substring(0,2).toInt();
    TechTree[i].depTechLevel=Part.substring(2,4).toInt();
  }
}

void loadBuildings(String BuildingsData)
{
  for(int i=0;i<15;i++)
  {
    String Part=BuildingsData.substring(i*6,(i*6)+6);
    Colony[i].level=Part.substring(0,2).toInt();
    Colony[i].depTechLevel=Part.substring(2,4).toInt();
    Colony[i].depBuildingLevel=Part.substring(4,6).toInt();
  }
}

void loadGarrisons(String GarrisonData,EnemyGarrison GarrisonArray[6])
{
  for(int i=0;i<6;i++)
  {
    String Part=GarrisonData.substring(i*26,(i*26)+26);
    GarrisonArray[i].planetIndex=Part.substring(0,2).toInt();
    GarrisonArray[i].Fighters=Part.substring(2,6).toInt();
    GarrisonArray[i].Interceptors=Part.substring(6,10).toInt();
    GarrisonArray[i].Frigates=Part.substring(10,14).toInt();
    GarrisonArray[i].WarCruisers=Part.substring(14,18).toInt();
    GarrisonArray[i].StarDreadnoughts=Part.substring(18,22).toInt();
    GarrisonArray[i].SolarDestroyers=Part.substring(22,26).toInt();
  }
}

void loadFleets(String FleetData,Fleet Fleets[4])
{
  for(int i=0;i<4;i++)
  {
    String Part=FleetData.substring(i*61,(i*61)+61);
    Fleets[i].Type=Part.substring(0,1).toInt();
    if(Part.substring(1,2)=="1")
      Fleets[i].Active=true;
    else
      Fleets[i].Active=false;
    Fleets[i].Minutes=Part.substring(2,4).toInt();
    Fleets[i].Seconds=Part.substring(4,6).toInt();
    Fleets[i].SpyBots=Part.substring(6,10).toInt();
    Fleets[i].Colonizers=Part.substring(10,14).toInt();
    Fleets[i].Fighters=Part.substring(14,18).toInt();
    Fleets[i].Interceptors=Part.substring(18,22).toInt();
    Fleets[i].Frigates=Part.substring(22,26).toInt();
    Fleets[i].WarCruisers=Part.substring(26,30).toInt();
    Fleets[i].StarDreadnoughts=Part.substring(30,34).toInt();
    Fleets[i].SolarDestroyers=Part.substring(34,38).toInt();
    Fleets[i].Stalkers=Part.substring(38,42).toInt();
    Fleets[i].Leviatans=Part.substring(42,46).toInt();
    String Destination=Part.substring(46,60);
    Fleets[i].DestinationName=removeSpaces(Destination);
    if(Part.substring(60,61)=="1")
      Fleets[i].Visible=true;
    else
      Fleets[i].Visible=false;
  }
}

void loadPlayerShips(String ShipsData)
{
  String Part=ShipsData.substring(0,52);
  PlayerShips[0]=Part.substring(0,4).toInt();
  PlayerShips[1]=Part.substring(4,8).toInt();
  PlayerShips[2]=Part.substring(8,12).toInt();
  PlayerShips[3]=Part.substring(12,16).toInt();
  PlayerShips[4]=Part.substring(16,20).toInt();
  PlayerShips[5]=Part.substring(20,24).toInt();
  PlayerShips[6]=Part.substring(24,28).toInt();
  PlayerShips[7]=Part.substring(28,32).toInt();
  PlayerShips[8]=Part.substring(32,36).toInt();
  PlayerShips[9]=Part.substring(36,40).toInt();
  PlayerShips[10]=Part.substring(40,44).toInt();
  PlayerShips[11]=Part.substring(44,48).toInt();
  PlayerShips[12]=Part.substring(48,52).toInt();
}

void loadTradeRoutes(String RoutesData)
{
  for(int i=0;i<12;i++)
  {
    String Part=RoutesData.substring(i*18,(i*18)+18);
    if(Part.substring(0,1)=="1")
      PlayerRoutes[i].Active=true;
    else
      PlayerRoutes[i].Active=false;
    String Name=Part.substring(1,15);
    PlayerRoutes[i].Name=removeSpaces(Name);
    PlayerRoutes[i].Metal=Part.substring(15,16).toInt();
    PlayerRoutes[i].Crystal=Part.substring(16,17).toInt();
    PlayerRoutes[i].Fuel=Part.substring(17,18).toInt();
  }
}

void loadReports(String ReportData)
{
  for(int i=0;i<5;i++)
  {
    String Part=ReportData.substring(i*42,(i*42)+42);
    String Name=Part.substring(0,14);
    IntelligenceReports[i].PlanetName=removeSpaces(Name);
    IntelligenceReports[i].Type=Part.substring(14,15).toInt();
    IntelligenceReports[i].Fighters=Part.substring(15,19).toInt();
    IntelligenceReports[i].Interceptors=Part.substring(19,23).toInt();
    IntelligenceReports[i].Frigates=Part.substring(23,27).toInt();
    IntelligenceReports[i].WarCruisers=Part.substring(27,31).toInt();
    IntelligenceReports[i].StarDreadnoughts=Part.substring(31,35).toInt();
    IntelligenceReports[i].SolarDestroyers=Part.substring(35,39).toInt();
    IntelligenceReports[i].Resource1=Part.substring(39,40).toInt();
    IntelligenceReports[i].Resource2=Part.substring(40,41).toInt();
    IntelligenceReports[i].Resource3=Part.substring(41,42).toInt();
  }
}

void loadGameVariables(String GameData)
{
  String Part=GameData.substring(0,50);
  PlayerResources[0]=Part.substring(0,4).toInt();
  PlayerResources[1]=Part.substring(4,8).toInt();
  PlayerResources[2]=Part.substring(8,12).toInt();
  BattleExperience=Part.substring(12,16).toInt();
  EnemyCount=Part.substring(16,17).toInt();
  Difficulty=removeSpaces(Part.substring(17,31));
  ProgressPoints=Part.substring(31,34).toInt();
  ProgressPointsLimit=Part.substring(34,37).toInt();
  EnemyColonies=Part.substring(37,39).toInt();
  EnemyCapitals=Part.substring(39,40).toInt();
  Score=Part.substring(40,46).toInt();
  timeToAttack=Part.substring(46,49).toInt();
  if(Part.substring(49,50)=="1")
    attackUnderway=true;
  else
    attackUnderway=false;
}

//---------------------------SAVE------------------------------
void saveGame()
{
  String StrSystemData=saveDataSystem();
  if(StrSystemData.length()==309)
  {
    char Buffer[309];
    StrSystemData.toCharArray(Buffer, 309);
    gb.save.set(0,Buffer);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE SYSTEM.",50);
    return;
  }
  
  String StrTechsData=saveDataTechs();
  if(StrTechsData.length()==81)
  {
    char Buffer2[81];
    StrTechsData.toCharArray(Buffer2, 81);
    gb.save.set(1,Buffer2);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE TECHS.",50);
    return;
  }
  
  String StrBuildingsData=saveDataBuildings();
  if(StrBuildingsData.length()==91)
  {
    char Buffer3[91];
    StrBuildingsData.toCharArray(Buffer3,91);
    gb.save.set(2,Buffer3);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE BUILD.",50);
    return;
  }

  String StrGar1Data=saveDataGarrison(Enemy1Garrison);
  if(StrGar1Data.length()==157)
  {
    char Buffer4[157];
    StrGar1Data.toCharArray(Buffer4,157);
    gb.save.set(3,Buffer4);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE GAR1.",50);
    return;
  }

  String StrGar2Data=saveDataGarrison(Enemy2Garrison);
  if(StrGar2Data.length()==157)
  {
    char Buffer5[157];
    StrGar2Data.toCharArray(Buffer5,157);
    gb.save.set(4,Buffer5);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE GAR2.",50);
    return;
  }

  String StrPlFleet=saveDataFleets(PlayerFleets);
  if(StrPlFleet.length()==245)
  {
    char Buffer6[245];
    StrPlFleet.toCharArray(Buffer6,245);
    gb.save.set(5,Buffer6);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE PLFLE.",50);
    return;
  }

  String StrEnFleet=saveDataFleets(EnemyFleets);
  if(StrEnFleet.length()==245)
  {
    char Buffer7[245];
    StrEnFleet.toCharArray(Buffer7,245);
    gb.save.set(6,Buffer7);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE ENFLE.",50);
    return;
  }
  
  String StrPlayerShips=saveDataPlayerShips();
  if(StrPlayerShips.length()==53)
  {
    char Buffer8[53];
    StrPlayerShips.toCharArray(Buffer8,53);
    gb.save.set(7,Buffer8);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE PLSHIPS.",50);
    return;
  }

  String StrPlayerRoutes=saveDataRoutes();
  if(StrPlayerRoutes.length()==217)
  {
    char Buffer9[217];
    StrPlayerRoutes.toCharArray(Buffer9,217);
    gb.save.set(8,Buffer9);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE ROUTES.",50);
    return;
  }

  String StrReports=saveDataReports();
  if(StrReports.length()==211)
  {
    char Buffer10[211];
    StrReports.toCharArray(Buffer10,211);
    gb.save.set(9,Buffer10);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE REPORTS.",50);
    return;
  }

  String StrVariables=saveDataGameVariables();
  if(StrVariables.length()==51)
  {
    char Buffer11[51];
    StrVariables.toCharArray(Buffer11,51);
    gb.save.set(10,Buffer11);
  }
  else
  {
    gb.gui.popup("ERROR: SAVE VARIABLES.",50);
    return;
  }

  gb.gui.popup("GAME SAVED!",50);
}

String saveDataSystem()
{
  String strData="";
  for(int i=2;i<30;i++)
  {
    String strPlanet="";
    if(System[i].Discovered==true) strPlanet+="1";
    else strPlanet+="0";
    if(System[i].Hostile==true) strPlanet+="1";
    else strPlanet+="0";
    strPlanet+=(String)System[i].Resource1;
    strPlanet+=(String)System[i].Resource2;
    strPlanet+=(String)System[i].Resource3;
    if(System[i].Owned==true) strPlanet+="1";
    else strPlanet+="0";
    if(System[i].TradeRoute==true) strPlanet+="1";
    else strPlanet+="0";
    if(System[i].GarrisonIndex>=0)
      strPlanet+="0"+(String)System[i].GarrisonIndex;
    else
      strPlanet+=(String)System[i].GarrisonIndex;
    if(System[i].Status==true) strPlanet+="1";
    else strPlanet+="0";
    if(System[i].ActiveMission==true) strPlanet+="1";
    else strPlanet+="0";
    strData+=strPlanet;
  }
  return strData+" ";
}

String saveDataTechs()
{
  String strData="";
  for(int i=0;i<20;i++)
  {
    if(TechTree[i].level>9)
      strData+=(String)TechTree[i].level;
    else
      strData+="0"+(String)TechTree[i].level;
    if(TechTree[i].depTechLevel>9)
      strData+=(String)TechTree[i].depTechLevel;
    else
      strData+="0"+(String)TechTree[i].depTechLevel;
  }
  return strData+" ";
}

String saveDataBuildings()
{
  String strData="";
  for(int i=0;i<15;i++)
  {
    if(Colony[i].level>9)
      strData+=(String)Colony[i].level;
    else
      strData+="0"+(String)Colony[i].level;
    if(Colony[i].depTechLevel>9)
      strData+=(String)Colony[i].depTechLevel;
    else
      strData+="0"+(String)Colony[i].depTechLevel;
    if(Colony[i].depBuildingLevel>9)
      strData+=(String)Colony[i].depBuildingLevel;
    else
      strData+="0"+(String)Colony[i].depBuildingLevel;
  }
  return strData + " ";
}

String saveDataGarrison(EnemyGarrison GarrisonArray[6])
{
  String strData="";
  for(int i=0;i<6;i++)
  {
    if(GarrisonArray[i].planetIndex>9 || GarrisonArray[i].planetIndex<0)
      strData+=(String)GarrisonArray[i].planetIndex;
    else
      strData+="0"+(String)GarrisonArray[i].planetIndex;;
    strData+=returnDecimalString(GarrisonArray[i].Fighters);
    strData+=returnDecimalString(GarrisonArray[i].Interceptors);
    strData+=returnDecimalString(GarrisonArray[i].Frigates);
    strData+=returnDecimalString(GarrisonArray[i].WarCruisers);
    strData+=returnDecimalString(GarrisonArray[i].StarDreadnoughts);
    strData+=returnDecimalString(GarrisonArray[i].SolarDestroyers);
  }
  return strData + " ";
}

String saveDataFleets(Fleet Fleets[4])
{
  String strData="";
  for(int i=0;i<4;i++)
  {
    strData+=(String)Fleets[i].Type;
    if(Fleets[i].Active==true) strData+="1";
    else strData+="0";
    if(Fleets[i].Minutes>9)
      strData+=(String)Fleets[i].Minutes;
    else
      strData+="0"+(String)Fleets[i].Minutes;
    if(Fleets[i].Seconds>9)
      strData+=(String)Fleets[i].Seconds;
    else
      strData+="0"+(String)Fleets[i].Seconds;
    strData+=returnDecimalString(Fleets[i].SpyBots);
    strData+=returnDecimalString(Fleets[i].Colonizers);
    strData+=returnDecimalString(Fleets[i].Fighters);
    strData+=returnDecimalString(Fleets[i].Interceptors);
    strData+=returnDecimalString(Fleets[i].Frigates);
    strData+=returnDecimalString(Fleets[i].WarCruisers);
    strData+=returnDecimalString(Fleets[i].StarDreadnoughts);
    strData+=returnDecimalString(Fleets[i].SolarDestroyers);
    strData+=returnDecimalString(Fleets[i].Stalkers);
    strData+=returnDecimalString(Fleets[i].Leviatans);
    strData+=addSpaces(Fleets[i].DestinationName);
    if(Fleets[i].Visible==true)
    {
      strData+="1"; 
    }
    else
    {
      strData+="0";
    }
  }
  return strData + " ";
}

String saveDataPlayerShips()
{
  String strData="";
  strData+=returnDecimalString(PlayerShips[0]);
  strData+=returnDecimalString(PlayerShips[1]);
  strData+=returnDecimalString(PlayerShips[2]);
  strData+=returnDecimalString(PlayerShips[3]);
  strData+=returnDecimalString(PlayerShips[4]);
  strData+=returnDecimalString(PlayerShips[5]);
  strData+=returnDecimalString(PlayerShips[6]);
  strData+=returnDecimalString(PlayerShips[7]);
  strData+=returnDecimalString(PlayerShips[8]);
  strData+=returnDecimalString(PlayerShips[9]);
  strData+=returnDecimalString(PlayerShips[10]);
  strData+=returnDecimalString(PlayerShips[11]);
  strData+=returnDecimalString(PlayerShips[12]);
  
  return strData + " ";
}

String saveDataRoutes()
{
  String strData="";
  for(int i=0;i<12;i++)
  {
    if(PlayerRoutes[i].Active==true) strData+="1";
    else strData+="0";
    strData+=addSpaces(PlayerRoutes[i].Name);
    strData+=PlayerRoutes[i].Metal;
    strData+=PlayerRoutes[i].Crystal;
    strData+=PlayerRoutes[i].Fuel;
  }
  
  return strData + " ";
}

String saveDataReports()
{
  String strData="";
  for(int i=0;i<5;i++)
  {
    strData+=addSpaces(IntelligenceReports[i].PlanetName);
    strData+=(String)IntelligenceReports[i].Type;
    strData+=returnDecimalString(IntelligenceReports[i].Fighters);
    strData+=returnDecimalString(IntelligenceReports[i].Interceptors);
    strData+=returnDecimalString(IntelligenceReports[i].Frigates);
    strData+=returnDecimalString(IntelligenceReports[i].WarCruisers);
    strData+=returnDecimalString(IntelligenceReports[i].StarDreadnoughts);
    strData+=returnDecimalString(IntelligenceReports[i].SolarDestroyers);
    strData+=(String)IntelligenceReports[i].Resource1;
    strData+=(String)IntelligenceReports[i].Resource2;
    strData+=(String)IntelligenceReports[i].Resource3;
  }
  
  return strData + " ";
}

String saveDataGameVariables()
{
  String strData="";
  strData+=returnDecimalString(PlayerResources[0]);
  strData+=returnDecimalString(PlayerResources[1]);
  strData+=returnDecimalString(PlayerResources[2]);
  strData+=returnDecimalString(BattleExperience);
  strData+=(String)EnemyCount;
  strData+=addSpaces(Difficulty);
  strData+=returnDecimalStringPoint(ProgressPoints);
  strData+=returnDecimalStringPoint(ProgressPointsLimit);
  if(EnemyColonies>9)
      strData+=(String)EnemyColonies;
    else
      strData+="0"+(String)EnemyColonies;
  strData+=(String)EnemyCapitals;   
  strData+=returnDecimalStringScore(Score);
  strData+=returnDecimalStringPoint(timeToAttack);
  if(attackUnderway==true)
  {
    strData+="1";
  }
  else
  {
    strData+="0";
  }
  
  return strData + " ";
}
//---------------HELPERS---------------------------------
String returnDecimalStringPoint(int number)
{
  if(number>99)
    return (String)number;
  else if(number<100 && number>9)
    return "0"+(String)number;
  else if(number>=0)
    return "00" + (String)number;
  else
    return "000";  
}

String returnDecimalString(int number)
{
  if(number>999)
    return (String)number;
  else if(number<1000 && number>99)
    return "0"+(String)number;
  else if(number<100 && number>9)
    return "00"+(String)number;
  else if(number>=0)
    return "000" + (String)number;
  else
    return "0000";  
}

String returnDecimalStringScore(int number)
{
  if(number<1000000 && number>99999)
    return (String)number;
  else if(number<100000 && number>9999)
    return "0"+(String)number;
  else if(number<10000 && number>999)
    return "00"+(String)number;
  else if(number<1000 && number>99)
    return "000"+(String)number;
  else if(number<100 && number>9)
    return "0000"+(String)number;
  else if(number>=0)
    return "00000" + (String)number;
  else
    return "000000";  
}

String removeSpaces(String phrase)
{
  int idx=phrase.indexOf('*');
  if(idx!=-1)
  {
    phrase.remove(idx);
  }
  return phrase;
}

String addSpaces(String phrase)
{
  int count=phrase.length();
  if(count<14)
  {
    int toRemove=14-count;
    if(toRemove>0)
    {
      for(int i=0;i<toRemove;i++)
      {
        phrase+="*";
      }
    }
  }
  return phrase;
}
