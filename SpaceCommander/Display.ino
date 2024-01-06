Image Cursor(IMAGE_CURSOR);
Image Selector(IMAGE_BTN_SELECT);
Image FleetSelector(IMAGE_FLEET_SELECT);
Image Alert(IMAGE_ALERT);
Image MarketSelector(IMAGE_MARKET_SELECT);

int selectionFrame = 0;

//---------------Menu Logic--------

void drawMainMenu(int selection)
{
  updateSelectionFrame(); 
  gb.display.drawImage(3, 3, IMAGE_WINGS_L, 15, 23);
  gb.display.drawImage(62, 3, IMAGE_WINGS_R, 15, 23);
  gb.display.setColor(BLUE);
  gb.display.setFontSize(2);
  gb.display.setCursor(21, 5);
  gb.display.println("SPACE");
  gb.display.setFontSize(1);
  gb.display.setCursor(22, 18);
  gb.display.println("COMMANDER");
  gb.display.setCursor(23, 32);
  if (selectionFrame == 1 && selection == 0)
  {
    gb.display.setColor(BLUE);  
  }
  else
  {
    gb.display.setColor(WHITE); 
  } 
  gb.display.println("NEW GAME");
  gb.display.setCursor(14,38);
  if (GameStarted == true)
  {
    if (selectionFrame == 1 && selection == 1)
    {
      gb.display.setColor(BLUE);  
    }
    else
    {
      gb.display.setColor(WHITE); 
    }
  }
  else
  {
     gb.display.setColor(GRAY);
  }
  gb.display.println("CONTINUE GAME");
  gb.display.setCursor(21,44);
  if (SaveExist == true)
  {
    if (selectionFrame == 1 && selection == 2)
    {
      gb.display.setColor(BLUE);  
    }
    else
    {
      gb.display.setColor(WHITE); 
    }
  }
  else
  {
     gb.display.setColor(GRAY);
  } 
  gb.display.println("LOAD GAME");
  gb.display.setCursor(16, 50);
  if (selectionFrame == 1 && selection == 3)
  {
    gb.display.setColor(BLUE);  
  }
  else
  {
    gb.display.setColor(WHITE); 
  } 
  gb.display.println("GAME OPTIONS");
  gb.display.setCursor(16,56);
  if (selectionFrame == 1 && selection == 4)
  {
    gb.display.setColor(BLUE);  
  }
  else
  {
    gb.display.setColor(WHITE); 
  } 
  gb.display.println("HALL OF FAME");
}

void drawOptionsMenu(int selection)
{
  updateSelectionFrame();
  gb.display.setCursor(15, 2);
  gb.display.setColor(BLUE);
  gb.display.println("GAME OPTIONS");
  gb.display.setFontSize(1);
  gb.display.setCursor(4, 20);
  if(selectionFrame == 1 && selection == 0)
  {
    gb.display.setColor(BLUE);  
  }
  else
  {
    gb.display.setColor(WHITE); 
  } 
  gb.display.println("ENEMIES: " + (String)EnemyCount);
  gb.display.setCursor(4, 26);
  if(selectionFrame == 1 && selection == 1)
  {
    gb.display.setColor(BLUE);  
  }
  else
  {
    gb.display.setColor(WHITE); 
  } 
  gb.display.println("DIFFICULTY: " + Difficulty);
  gb.display.setCursor(4, 32);
  if(selectionFrame == 1 && selection == 2)
  {
    gb.display.setColor(BLUE);  
  }
  else
  {
    gb.display.setColor(WHITE); 
  } 
  gb.display.println("WEAPON POINTS: " + (String)ProgressPointsLimit);
  gb.display.setCursor(4, 38);
  if(selectionFrame == 1 && selection == 3)
  {
    gb.display.setColor(BLUE);  
  }
  else
  {
    gb.display.setColor(WHITE); 
  } 
  gb.display.println("BACK");
}

void drawHallOfFame()
{
  updateSelectionFrame();
  gb.display.setCursor(15, 2);
  gb.display.setColor(BLUE);
  gb.display.println("HALL OF FAME");
  gb.display.setFontSize(1);
  for (int i = 0; i < 5; i++)
  {
    String scoreStr = scoreStrMod(ScoreBoard[i]);
    String index = (String)(i + 1);
    scoreStr = index + ". " + scoreStr;
    gb.display.setCursor(20, 15 +(i * 6));
    gb.display.println(scoreStr);
  }
  if (selectionFrame == 1)
  {
    gb.display.setColor(BLUE);  
  }
  else
  {
    gb.display.setColor(WHITE); 
  } 
  gb.display.setCursor(32, 52);
  gb.display.println("BACK");
}

String scoreStrMod(int score)
{
  String result = String(score);
  int count = result.length();
  if (count < 6)
  {
    String spaces = "";
    for (int i = count; i <= 6;i++)
    {
          spaces += " ";
    }
    result = spaces + result;
  }
  return result;
}
//---------------Market Logic------------
void drawMarket(String choice, int8_t currentGood, String misslePrice)
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.drawImage(0, 56, IMAGE_BOTTOM_LINE);
  gb.display.drawImage(0, 56, IMAGE_FLAT_LINE);
  gb.display.setCursor(13, 0);
  gb.display.setColor(WHITE);
  gb.display.setCursor(27, 0);
  gb.display.println("MARKET");
  gb.display.setColor(BLACK);
  gb.display.setCursor(15, 15);
  gb.display.println("BUY FOR FUEL:");
  gb.display.setCursor(2, 34);
  gb.display.setColor(BLACK);
  gb.display.drawImage(5, 23, IMAGE_MARKET_GOODS);
  gb.display.drawImage(30, 23, IMAGE_MARKET_SHIPS);
  gb.display.drawImage(55, 23, IMAGE_MARKET_MISSLES);
  if (currentGood == 0)
  {
    gb.display.drawImage(4, 22, MarketSelector);
  }
  else if (currentGood == 1)
  {
    gb.display.drawImage(29, 22, MarketSelector);
  }
  else
  {
    gb.display.drawImage(54, 22, MarketSelector);
  }
  gb.display.setCursor(5, 40);
  gb.display.setColor(ORANGE);
  gb.display.println("5000");
  gb.display.setCursor(30, 40);
  gb.display.println("7500");
  gb.display.setCursor(55, 40);
  gb.display.println(misslePrice);
  gb.display.setColor(WHITE);
  gb.display.setCursor(2, 58);
  gb.display.println(choice);
}
//---------------Debug Screen-----------
void drawDebug()
{
  gb.display.setColor(WHITE);
  gb.display.setCursor(0, 0);
  gb.display.setFontSize(1);
  gb.display.println(DebugData);
}
//---------------Star Map Logic---------

void drawMap(int astronomy, int posX, int posY)
{
  gb.display.fill(GRAY);
  gb.display.setColor(BLACK);
  gb.display.fillRect(0, 58, 80, 6);
  int mapSize = 1 + astronomy * 2;
  gb.display.drawImage((79 - mapSize) / 2,(59 - mapSize) / 2,IMAGE_MAP,(79 - mapSize) / 2,(59 - mapSize) / 2,mapSize, mapSize);
  gb.display.drawImage(posX, posY, Cursor);
  gb.display.setColor(RED);
  gb.display.setCursor(1, 58);
  gb.display.println(SelectedPlanet.Name);
}

void drawPlanetsColors()
{
  for (int i = 0; i < 30; i++)
  {
    if (System[i].Hostile == true && System[i].Status == true)
    {
      gb.display.setColor(RED);
      gb.display.fillRect(System[i].posX + 1, System[i].posY + 1, 1, 1);
    }
    else if (System[i].Discovered == true && System[i].Status == true && System[i].Owned == true)
    {
      gb.display.setColor(LIGHTGREEN);
      gb.display.fillRect(System[i].posX + 1, System[i].posY + 1, 1, 1);
    }
    else if (System[i].Discovered == true && System[i].Status == true)
    {
      gb.display.setColor(YELLOW);
      gb.display.fillRect(System[i].posX + 1, System[i].posY + 1, 1, 1);
    }
  }
}

void drawDropdownMenu(int posX, int posY, int selection, int enabled[6])
{
  updateSelectionFrame();
  
  int fixedX = posX;
  int fixedY = posY;
  if (posX + 37 > 80)
  {
    fixedX -= 37;
  }
  if (posY + 38 > 64)
  {
    if (posY < 38)
    {
      fixedY = 0;
    }
    else
    {
      fixedY -= 38;
    }
  }
  gb.display.drawImage(fixedX, fixedY, IMAGE_DROPDOWN);
  if (enabled[0] != 0)
  {
    if (selectionFrame == 1 && selection == 1)
    {
      gb.display.setColor(RED);  
    }
    else
    {
      gb.display.setColor(BLACK); 
    } 
  }
  else
  {
    gb.display.setColor(GRAY);
  }
  gb.display.setCursor(fixedX + 1, fixedY + 1);
  gb.display.println("SCOUT");
  if (enabled[1] != 0)
  {
    if (selectionFrame == 1 && selection == 2)
    {
      gb.display.setColor(RED);  
    }
    else
    {
      gb.display.setColor(BLACK); 
    } 
  }
  else
  {
    gb.display.setColor(GRAY);
  }
  gb.display.setCursor(fixedX + 1, fixedY + 7);
  gb.display.println("COLONIZE");
  if (enabled[2] != 0)
  {
    if (selectionFrame == 1 && selection == 3)
    {
      gb.display.setColor(RED);  
    }
    else
    {
      gb.display.setColor(BLACK); 
    } 
  }
  else
  {
    gb.display.setColor(GRAY);
  }
  gb.display.setCursor(fixedX + 1, fixedY + 13);
  gb.display.println("ATTACK");
  if (enabled[3] != 0)
  {
    if (selectionFrame == 1 && selection == 4)
    {
      gb.display.setColor(RED);  
    }
    else
    {
      gb.display.setColor(BLACK); 
    } 
  }
  else
  {
    gb.display.setColor(GRAY);
  }
  gb.display.setCursor(fixedX + 1, fixedY + 19);
  gb.display.println("RAID");
  if(enabled[4] != 0)
  {
    if (selectionFrame == 1 && selection == 5)
    {
      gb.display.setColor(RED);  
    }
    else
    {
      gb.display.setColor(BLACK); 
    } 
  }
  else
  {
    gb.display.setColor(GRAY);
  }
  gb.display.setCursor(fixedX + 1, fixedY + 25);
  gb.display.println("SET ROUTE");
  if(enabled[5] != 0)
  {
    if (selectionFrame == 1 && selection == 6)
    {
      gb.display.setColor(RED);  
    }
    else
    {
      gb.display.setColor(BLACK); 
    } 
  }
  else
  {
    gb.display.setColor(GRAY);
  }
  gb.display.setCursor(fixedX + 1, fixedY + 31);
  gb.display.println("ABANDON");
}

//---------------War Room Logic---------

void drawWarRoom(int posX, int posY, String choice, bool alert)
{
  gb.display.drawImage(0, 0, IMAGE_WAR_ROOM);
  gb.display.setColor(BLUE);
  gb.display.drawRect(1, 1, 3, 3);
  gb.display.setCursor(6, 0);
  gb.display.setFontSize(1);
  gb.display.println(PlayerResources[0]);
  gb.display.setColor(PURPLE);
  gb.display.drawRect(27, 1, 3, 3);
  gb.display.setCursor(33, 0);
  gb.display.println(PlayerResources[1]);
  gb.display.setColor(ORANGE);
  gb.display.drawRect(54, 1, 3, 3);
  gb.display.setCursor(60, 0);
  gb.display.println(PlayerResources[2]);
  gb.display.drawImage(71, 9, IMAGE_BUILD_BTN);
  if (Colony[7].level > 0)
  {
    gb.display.drawImage(71, 16, IMAGE_RESEARCH_BTN); 
  }
  gb.display.drawImage(71, 23, IMAGE_MAP_BTN);
  if (Colony[6].level > 0)
  {
    gb.display.drawImage(71, 30, IMAGE_SHIPS_BTN);
  }
  if (Colony[4].level > 0)
  {
    gb.display.drawImage(71, 37, IMAGE_INTEL_BTN);
  }
  gb.display.drawImage(62, 44, IMAGE_TRANSPORT_BTN);
  if (Colony[13].level > 0)
  {
    gb.display.drawImage(71, 44, IMAGE_STATS_BTN);
  }
  gb.display.drawImage(62, 51, IMAGE_PAUSE_BTN);
  gb.display.drawImage(71, 51, IMAGE_SAVE_BTN);
  gb.display.drawImage(62, 9, IMAGE_FLEET_BTN);
  if (Colony[5].level > 0)
  {
    gb.display.drawImage(62, 16, IMAGE_RADIOLOCATION_BTN); 
  }
  gb.display.drawImage(62, 23, IMAGE_SHIPS_STATS_BTN);
  gb.display.drawImage(62, 30, IMAGE_REPORT_BTN);
  if (Colony[11].level > 0)
  {
    gb.display.drawImage(62, 37, IMAGE_TRANSFORM_BTN);
  }
  gb.display.drawImage(posX, posY, Selector);
  gb.display.setColor(WHITE);
  gb.display.setCursor(2, 59);
  gb.display.println(choice);
  if(alert == true)
  {
    gb.display.drawImage(36, 35, Alert); 
  }
}

//---------------Research Logic---------

void drawResearch(Technology technology, String depTechName, int depLevel, bool canResearch, bool maxReached)
{
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.drawImage(0, 6, IMAGE_LINE_UP2);
  gb.display.drawImage(0, 56, IMAGE_BOTTOM_LINE);
  gb.display.drawImage(0, 34, IMAGE_INFO_DIALOG);
  gb.display.drawImage(0, 56, IMAGE_FLAT_LINE);
  gb.display.drawImage(0, 32, IMAGE_LINE_DOWN2);
  gb.display.drawImage(44, 21, IMAGE_BUTTON_FRAME);
  gb.display.setColor(BLUE);
  gb.display.drawRect(1, 1, 3, 3);
  gb.display.setCursor(6, 0);
  gb.display.setFontSize(1);
  gb.display.println(PlayerResources[0]);
  gb.display.setColor(PURPLE);
  gb.display.drawRect(27, 1, 3, 3);
  gb.display.setCursor(33, 0);
  gb.display.println(PlayerResources[1]);
  gb.display.setColor(ORANGE);
  gb.display.drawRect(54, 1, 3, 3);
  gb.display.setCursor(60, 0);
  gb.display.println(PlayerResources[2]);
  gb.display.setColor(GRAY);
  drawTechImage(technology.id);
  gb.display.setColor(WHITE);
  gb.display.setCursor(20, 9);
  gb.display.println(technology.techName);
  gb.display.setColor(GREEN);
  gb.display.setCursor(45, 15);
  gb.display.println("LEVEL");
  gb.display.setCursor(70, 15);
  gb.display.println(technology.level);
  if (canResearch)
  {
    gb.display.drawImage(46, 23, IMAGE_RESEARCH_BTN);
    gb.display.drawImage(45, 22, Selector); 
  }
  gb.display.setColor(WHITE);
  gb.display.setCursor(0, 35);
  gb.display.println(technology.describtion);
  if (maxReached == false)
  {
    gb.display.setColor(BLUE);
    gb.display.setCursor(20, 15);
    gb.display.println(technology.resource1Cost * (technology.level + 1));
    gb.display.setColor(PURPLE);
    gb.display.setCursor(20, 21);
    gb.display.println(technology.resource2Cost * (technology.level + 1));
    gb.display.setColor(ORANGE);
    gb.display.setCursor(20, 27);
    gb.display.println(technology.resource3Cost * (technology.level + 1));
    if ((technology.depTechLevel > depLevel) && depTechName != "")
    {
      gb.display.setColor(RED);
      gb.display.setCursor(0, 58);
      gb.display.println(depTechName);
      gb.display.setCursor(65, 58);
      gb.display.println(technology.depTechLevel); 
    }
  }
  else
  {
    gb.display.setColor(GREEN);
    gb.display.setCursor(0, 58);
    gb.display.println("MAX LEVEL REACHED");
  }
}

void drawTechImage(int id)
{
  switch (id)
  {
    case 1:
      gb.display.drawImage(2, 9, IMAGE_TECH_ASTRONOMY); break;
    case 2:
      gb.display.drawImage(2, 9, IMAGE_TECH_ESPIONAGE); break;
    case 3:
      gb.display.drawImage(2, 9, IMAGE_TECH_JET_PROPLUSION); break;
    case 4:
      gb.display.drawImage(2, 9, IMAGE_TECH_FLEET_TACTICS); break;
    case 5:
      gb.display.drawImage(2, 9, IMAGE_TECH_RADIOLOCATION); break;
    case 6:
      gb.display.drawImage(2, 9, IMAGE_TECH_LOGISTIC); break;
    case 7:
      gb.display.drawImage(2, 9, IMAGE_TECH_AERODYNAMICS); break;
    case 8:
      gb.display.drawImage(2, 9, IMAGE_TECH_CLOAKING); break;
    case 9:
      gb.display.drawImage(2, 9, IMAGE_TECH_EMP_WEAPON); break;
    case 10:
      gb.display.drawImage(2, 9, IMAGE_TECH_STATICS); break;
    case 11:
      gb.display.drawImage(2, 9, IMAGE_TECH_ECONOMY); break;
    case 12:
      gb.display.drawImage(2, 9, IMAGE_TECH_IMPULSE_ENGINE); break;
    case 13:
      gb.display.drawImage(2, 9, IMAGE_TECH_SHIELDING); break;
    case 14:
      gb.display.drawImage(2, 9, IMAGE_TECH_MIND_CONTROL); break;
    case 15:
      gb.display.drawImage(2, 9, IMAGE_TECH_HYPERDRIVE); break;
    case 16:
      gb.display.drawImage(2, 9, IMAGE_TECH_FUSION_REACTION); break;
    case 17:
      gb.display.drawImage(2, 9, IMAGE_TECH_SHIP_WEAPONS); break;
    case 18:
      gb.display.drawImage(2, 9, IMAGE_TECH_FLIGHT_CONTROL); break;
    case 19:
      gb.display.drawImage(2, 9, IMAGE_TECH_GRAVITY_WEAPON); break;
    case 20:
      gb.display.drawImage(2, 9, IMAGE_TECH_COMPOSITE_ARMOR); break;
    default:
      gb.display.drawRect(2, 9, 15, 15); break;
  }
}

//---------------Infrastructure Logic---

void drawInfrastructureScreen(Building building, String depTechName, int depLevel, String depBuildingName, int depBuildingLevel, bool canBuild, bool maxReached)
{
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.drawImage(0, 6, IMAGE_LINE_UP2);
  gb.display.drawImage(0, 56, IMAGE_BOTTOM_LINE);
  gb.display.drawImage(0, 34, IMAGE_INFO_DIALOG);
  gb.display.drawImage(0, 56, IMAGE_FLAT_LINE);
  gb.display.drawImage(0, 32, IMAGE_LINE_DOWN2);
  gb.display.drawImage(44, 21, IMAGE_BUTTON_FRAME);
  gb.display.setColor(BLUE);
  gb.display.drawRect(1, 1, 3, 3);
  gb.display.setCursor(6, 0);
  gb.display.setFontSize(1);
  gb.display.println(PlayerResources[0]);
  gb.display.setColor(PURPLE);
  gb.display.drawRect(27, 1, 3, 3);
  gb.display.setCursor(33, 0);
  gb.display.println(PlayerResources[1]);
  gb.display.setColor(ORANGE);
  gb.display.drawRect(54, 1, 3, 3);
  gb.display.setCursor(60, 0);
  gb.display.println(PlayerResources[2]);
  gb.display.setColor(GRAY);
  drawBuildingImage(building.id);
  gb.display.setColor(WHITE);
  gb.display.setCursor(20, 9);
  gb.display.println(building.bName);
  gb.display.setColor(GREEN);
  gb.display.setCursor(45, 15);
  gb.display.println("LEVEL");
  gb.display.setCursor(70, 15);
  gb.display.println(building.level);
  if (canBuild)
  {
    gb.display.drawImage(46, 23, IMAGE_BUILD_BTN);
    gb.display.drawImage(45, 22, Selector); 
  }

  gb.display.setColor(WHITE);
  gb.display.setCursor(0, 35);
  gb.display.println(building.describtion);
  if (maxReached == false)
  {
    gb.display.setColor(BLUE);
    gb.display.setCursor(20, 15);
    gb.display.println((building.resource1Cost - 15 * (Colony[9].level)) * (building.level + 1));
    gb.display.setColor(PURPLE);
    gb.display.setCursor(20, 21);
    gb.display.println((building.resource2Cost - 15 * (Colony[9].level)) * (building.level + 1));
    gb.display.setColor(ORANGE);
    gb.display.setCursor(20, 27);
    gb.display.println(building.resource3Cost * (building.level + 1));
    
    if ((building.depBuildingLevel > depBuildingLevel) && depBuildingName != "")
    {
      gb.display.setColor(RED);
      gb.display.setCursor(0, 58);
      gb.display.println(depBuildingName);
      gb.display.setCursor(65, 58);
      gb.display.println(building.depBuildingLevel);
    }
    else if ((building.depTechLevel > depLevel) && depTechName != "")
    {
      gb.display.setColor(RED);
      gb.display.setCursor(0, 58);
      gb.display.println(depTechName);
      gb.display.setCursor(65, 58);
      gb.display.println(building.depTechLevel); 
    }
  }
  else
  {
    gb.display.setColor(GREEN);
    gb.display.setCursor(0, 58);
    gb.display.println("MAX LEVEL REACHED");
  }
}

void drawBuildingImage(int id)
{
  switch(id)
  {
    case 1:
      gb.display.drawImage(1, 11, IMAGE_POWER_PLANT); break;
    case 2:
      gb.display.drawImage(1, 11, IMAGE_METAL_MINE); break;
    case 3:
      gb.display.drawImage(1, 11, IMAGE_CRYSTAL_MINE); break;
    case 4:
      gb.display.drawImage(1, 11, IMAGE_FUEL_REFINERY); break;
    case 5:
      gb.display.drawImage(1, 11, IMAGE_INTELLIGENCE); break;
    case 6:
      gb.display.drawImage(1, 11, IMAGE_RADAR); break;
    case 7:
      gb.display.drawImage(1, 11, IMAGE_SHIPYARD); break;
    case 8:
      gb.display.drawImage(1, 11, IMAGE_RESEARCH_LAB); break;
    case 9:
      gb.display.drawImage(1, 11, IMAGE_PLANETARY_DEFENCE); break;
    case 10:
      gb.display.drawImage(1, 11, IMAGE_FACTORY); break;
    case 11:
      gb.display.drawImage(1, 11, IMAGE_WAREHOUSE); break;
    case 12:
      gb.display.drawImage(1, 11, IMAGE_TRANSFORMER); break;
    case 13:
      gb.display.drawImage(1, 11, IMAGE_LOGISTIC_CENTRE); break;
    case 14:
      gb.display.drawImage(1, 11, IMAGE_MARKET); break;
    case 15:
      gb.display.drawImage(1, 11, IMAGE_EMP_LAUNCHER); break;
    default:
      gb.display.drawRect(1, 11, 15, 15); break;
  }
}

//---------------Fleet Logic------------

void drawPlayerFleets(int posX, int posY)
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setCursor(13, 0);
  gb.display.setColor(WHITE);
  gb.display.println("ACTIVE FLEETS");
  int posFlY = 9;
  int ActiveFleets = 0;
  for (int i = 0; i < 4; i++)
  {
    if (PlayerFleets[i].Active == true)
    {
      if (PlayerFleets[i].Type == 1)
      {
        gb.display.drawImage(1, posFlY, IMAGE_FLEET_ROW_PLAYER); 
      }
      else if (PlayerFleets[i].Type == 2)
      {
        gb.display.drawImage(1, posFlY, IMAGE_FLEET_ROW_COLONIZATION);
      }
      else if (PlayerFleets[i].Type == 3)
      {
        gb.display.drawImage(1, posFlY, IMAGE_FLEET_ROW_SPY);
      }
      else if (PlayerFleets[i].Type == 5)
      {
        gb.display.drawImage(1, posFlY, IMAGE_FLEET_ROW_RETURN);
      }
      else if (PlayerFleets[i].Type == 6)
      {
        gb.display.drawImage(1, posFlY, IMAGE_FLEET_ROW_RAID);
      }
      else if (PlayerFleets[i].Type == 7)
      {
        gb.display.drawImage(1, posFlY, IMAGE_FLEET_ROW_INTERCEPT);
      }
      gb.display.setColor(WHITE);
      gb.display.setCursor(12, posFlY + 2);
      String strTime = setTimeString(PlayerFleets[i].Seconds, PlayerFleets[i].Minutes);
      gb.display.println(strTime);
      gb.display.setCursor(34, posFlY + 2);
      gb.display.println(PlayerFleets[i].DestinationName);
      posFlY += 11;
      ActiveFleets++;
    }
  }
}

void drawEnemyFleets(int posX, int posY, int selection)
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setCursor(15, 0);
  gb.display.setColor(WHITE);
  gb.display.println("ENEMY FLEETS");
  int posFlY = 11;
  bool canIntercept = false;
  for (int i = 0; i < 4; i++)
  {
    if (EnemyFleets[i].Active == true && EnemyFleets[i].Visible == true)
    {
      gb.display.drawImage(1, posFlY, IMAGE_FLEET_ROW_ENEMY);
      gb.display.setColor(WHITE);
      gb.display.setCursor(12, posFlY + 3);
      String strTime = setTimeString(EnemyFleets[i].Seconds, EnemyFleets[i].Minutes);
      gb.display.println(strTime);
      gb.display.setCursor(34, posFlY + 3);
      gb.display.println(EnemyFleets[i].DestinationName);
      posFlY += 11;

      if (EnemyFleets[i].Minutes >= 1)
      {
        canIntercept = true;
      }
    }
  }
  gb.display.drawImage(posX, posY, FleetSelector);
  if(PlayerShips[6] > 0)
  {
    gb.display.drawImage(2, 56, IMAGE_INTEL_BTN_OK);
    gb.display.setColor(WHITE);
    gb.display.setCursor(4, 57);
    gb.display.println("A");
  }
  if(PlayerShips[13] > 0 && canIntercept == true)
  {
    gb.display.drawImage(26, 56, IMAGE_INTERCEPT_BTN);
    gb.display.setColor(WHITE);
    gb.display.setCursor(28, 57);
    gb.display.println("MENU");
  }
}

String setTimeString(int8_t seconds, int8_t minutes)
{
  String strMinutes = "";
  String strSeconds = "";
  if (minutes < 10)
  {
    strMinutes = "0" + (String)minutes;
  }
  else
  {
    strMinutes = (String)minutes;
  }
  if (seconds < 10)
  {
    strSeconds = "0" + (String)seconds;
  }
  else
  {
    strSeconds = (String)seconds;
  }
  return strMinutes + ":" + strSeconds;
}

void drawStarRoutes(int page)
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setCursor(13, 0);
  gb.display.setColor(WHITE);
  gb.display.println("ROUTES PAGE " + (String)page);
  int idx = (page - 1) * 4;
  int posFlY = 12;
  for (int i = idx; i < 4 + idx; i++)
  {
    if (PlayerRoutes[i].Active == true)
    {
      gb.display.drawImage(1, posFlY, IMAGE_LOGISTIC_ROW);
      gb.display.setColor(WHITE);
      gb.display.setCursor(15, posFlY + 2);
      gb.display.println(PlayerRoutes[i].Name);
      gb.display.setColor(BLUE);
      gb.display.setCursor(50, posFlY + 2);
      gb.display.println("+" + (String)PlayerRoutes[i].Metal);
      gb.display.setColor(PURPLE);
      gb.display.setCursor(60, posFlY + 2);
      gb.display.println("+" + (String)PlayerRoutes[i].Crystal);
      gb.display.setColor(ORANGE);
      gb.display.setCursor(70, posFlY + 2);
      gb.display.println("+" + (String)PlayerRoutes[i].Fuel);
      posFlY += 11;
    }
  }
}

void drawRouteConfirmation(TradeRoute route, bool canSend, bool metal, bool crystal, bool fuel)
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setCursor(5, 0);
  gb.display.setColor(WHITE);
  gb.display.println("SET " + route.Name + " ROUTE");
  gb.display.setColor(BLACK);
  gb.display.setCursor(0, 9);
  gb.display.println(" METAL CARGO: ");
  gb.display.setCursor(52, 9);
  gb.display.println(route.Metal);
  gb.display.setCursor(0, 17);
  gb.display.println(" OWNED: ");
  if (metal == false)
  {
    gb.display.setColor(RED);
  }
  else
  {
    gb.display.setColor(GREEN);
  }
  gb.display.setCursor(30, 17);
  gb.display.println(PlayerShips[8]);
  gb.display.setColor(BLACK);
  gb.display.setCursor(0, 25);
  gb.display.println(" CRYSTAL CARGO: ");
  gb.display.setCursor(62, 25);
  gb.display.println(route.Crystal);
  gb.display.setCursor(0, 33);
  gb.display.println(" OWNED: ");
  if (crystal == false)
  {
    gb.display.setColor(RED);
  }
  else
  {
    gb.display.setColor(GREEN);
  }
  gb.display.setCursor(30, 33);
  gb.display.println(PlayerShips[9]);
  gb.display.setColor(BLACK);
  gb.display.setCursor(0, 41);
  gb.display.println(" FUEL CARGO: ");
  gb.display.setCursor(51, 41);
  gb.display.println(route.Fuel);
  gb.display.setCursor(0, 49);
  gb.display.println(" OWNED: ");
  if (fuel == false)
  {
    gb.display.setColor(RED);
  }
  else
  {
    gb.display.setColor(GREEN);
  }
  gb.display.setCursor(30, 49);
  gb.display.println(PlayerShips[10]);
  gb.display.setColor(WHITE);
  if (canSend == true)
  {
    gb.display.drawImage(2, 56, IMAGE_OK_BTN);
    gb.display.setCursor(4, 57);
    gb.display.println("A"); 
  }
  gb.display.drawImage(64, 56, IMAGE_CANCEL_BTN);
  gb.display.setCursor(66, 57);
  gb.display.println("B");
}

void drawFleetStats()
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setCursor(13, 0);
  gb.display.setColor(WHITE);
  gb.display.setCursor(17, 0);
  gb.display.println("FLEET STATS");
  gb.display.setColor(BLUE);
  gb.display.setCursor(1, 8);
  gb.display.println("FIG");
  gb.display.setCursor(1, 14);
  gb.display.println("INT");
  gb.display.setCursor(1, 20);
  gb.display.println("FRI");
  gb.display.setCursor(1, 26);
  gb.display.println("W CR");
  gb.display.setCursor(1, 32);
  gb.display.println("S DR");
  gb.display.setCursor(1, 38);
  gb.display.println("S DS");
  gb.display.setCursor(1, 44);
  gb.display.println("STL");
  gb.display.setCursor(1, 50);
  gb.display.println("LEV");
  gb.display.setCursor(40, 8);
  gb.display.println("MIS");
  gb.display.setColor(GREEN);
  gb.display.setCursor(40, 20);
  gb.display.println("SPY");
  gb.display.setCursor(40, 26);
  gb.display.println("COL");
  gb.display.setCursor(40, 32);
  gb.display.println("M TR");
  gb.display.setCursor(40, 38);
  gb.display.println("C TR");
  gb.display.setCursor(40, 44);
  gb.display.println("F TR");
  gb.display.setColor(BLACK);
  gb.display.setCursor(19, 8);
  gb.display.println(PlayerShips[0]);
  gb.display.setCursor(19, 14);
  gb.display.println(PlayerShips[1]);
  gb.display.setCursor(19, 20);
  gb.display.println(PlayerShips[2]);
  gb.display.setCursor(19, 26);
  gb.display.println(PlayerShips[3]);
  gb.display.setCursor(19, 32);
  gb.display.println(PlayerShips[4]);
  gb.display.setCursor(19, 38);
  gb.display.println(PlayerShips[5]);
  gb.display.setCursor(19, 44);
  gb.display.println(PlayerShips[11]);
  gb.display.setCursor(19, 50);
  gb.display.println(PlayerShips[12]);
  gb.display.setCursor(59, 8);
  gb.display.println(PlayerShips[13]);
  gb.display.setCursor(59, 20);
  gb.display.println(PlayerShips[6]);
  gb.display.setCursor(59, 26);
  gb.display.println(PlayerShips[7]);
  gb.display.setCursor(59, 32);
  gb.display.println(PlayerShips[8]);
  gb.display.setCursor(59, 38);
  gb.display.println(PlayerShips[9]);
  gb.display.setCursor(59, 44);
  gb.display.println(PlayerShips[10]);
  gb.display.setCursor(1, 57);
  gb.display.println("BATTLE EXP: ");
  gb.display.setColor(ORANGE);
  gb.display.setCursor(45, 57);
  gb.display.println(BattleExperience);
}

void drawBattleResult1()
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setColor(WHITE);
  gb.display.setCursor(11, 0);
  gb.display.println("BATTLE RESULTS");
  gb.display.setColor(BLACK);
  gb.display.setCursor(6, 9);
  gb.display.println("PLAYER     ENEMY");
  gb.display.setColor(BLUE);
  gb.display.setCursor(24, 19);
  gb.display.println("Fighters");
  gb.display.setCursor(15, 31);
  gb.display.println("Interceptors");
  gb.display.setCursor(24, 43);
  gb.display.println("Frigates");
  gb.display.setColor(BLACK);
  gb.display.setCursor(0, 25);
  gb.display.println(BtResult.PlFighters);
  gb.display.setCursor(44, 25);
  gb.display.println(BtResult.EnFighters);
  gb.display.setCursor(0, 37);
  gb.display.println(BtResult.PlInterceptors);
  gb.display.setCursor(44, 37);
  gb.display.println(BtResult.EnInterceptors);
  gb.display.setCursor(0, 49);
  gb.display.println(BtResult.PlFrigates);
  gb.display.setCursor(44, 49);
  gb.display.println(BtResult.EnFrigates);
  gb.display.setColor(RED);
  gb.display.setCursor(16, 25);
  gb.display.println("-" + (String)BtResult.PlFightersLost);  
  gb.display.setCursor(60, 25);
  gb.display.println("-" + (String)BtResult.EnFightersLost);
  gb.display.setCursor(16, 37);
  gb.display.println("-" + (String)BtResult.PlInterceptorsLost);
  gb.display.setCursor(60, 37);
  gb.display.println("-" + (String)BtResult.EnInterceptorsLost);  
  gb.display.setCursor(16, 49);
  gb.display.println("-" + (String)BtResult.PlFrigatesLost); 
  gb.display.setCursor(60, 49);
  gb.display.println("-" + (String)BtResult.EnFrigatesLost);
  gb.display.setCursor(24, 58);
  if (BtResult.Winner == 1)
  {
    gb.display.setColor(GREEN);
    gb.display.println("VICTORY!"); 
  }
  else if (BtResult.Winner == 2)
  {
    gb.display.setColor(RED);
    gb.display.println("  LOST! "); 
  }
  else
  {
    gb.display.setColor(BLACK);
    gb.display.println("  DRAW  "); 
  }
}

void drawBattleResult2()
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setColor(WHITE);
  gb.display.setCursor(11, 0);
  gb.display.println("BATTLE RESULTS");
  gb.display.setColor(BLACK);
  gb.display.setCursor(6, 9);
  gb.display.println("PLAYER     ENEMY");
  gb.display.setColor(BLUE);
  gb.display.setCursor(13, 19);
  gb.display.println("War Cruisers");
  gb.display.setCursor(5, 31);
  gb.display.println("Star Dreadnoughts");
  gb.display.setCursor(5, 43);
  gb.display.println("Solar Destructors");
  gb.display.setColor(BLACK);
  gb.display.setCursor(0, 25);
  gb.display.println(BtResult.PlWarCruisers);
  gb.display.setCursor(44, 25);
  gb.display.println(BtResult.EnWarCruisers);
  gb.display.setCursor(0, 37);
  gb.display.println(BtResult.PlStarDreadnoughts);
  gb.display.setCursor(44, 37);
  gb.display.println(BtResult.EnStarDreadnoughts);
  gb.display.setCursor(0, 49);
  gb.display.println(BtResult.PlSolarDestroyers);
  gb.display.setCursor(44, 49);
  gb.display.println(BtResult.EnSolarDestroyers);
  gb.display.setColor(RED);
  gb.display.setCursor(16, 25);
  gb.display.println("-" + (String)BtResult.PlWarCruisersLost);  
  gb.display.setCursor(60, 25);
  gb.display.println("-" + (String)BtResult.EnWarCruisersLost);
  gb.display.setCursor(16, 37);
  gb.display.println("-" + (String)BtResult.PlStarDreadnoughtsLost);
  gb.display.setCursor(60, 37);
  gb.display.println("-" + (String)BtResult.EnStarDreadnoughtsLost);  
  gb.display.setCursor(16, 49);
  gb.display.println("-" + (String)BtResult.PlSolarDestroyersLost); 
  gb.display.setCursor(60, 49);
  gb.display.println("-" + (String)BtResult.EnSolarDestroyersLost);
  gb.display.setCursor(24, 58);
  if (BtResult.Winner == 1)
  {
    gb.display.setColor(GREEN);
    gb.display.println("VICTORY!"); 
  }
  else if (BtResult.Winner == 2)
  {
    gb.display.setColor(RED);
    gb.display.println("  LOST! "); 
  }
  else
  {
    gb.display.setColor(BLACK);
    gb.display.println("  DRAW  "); 
  }
}

void drawFleetSelection(int posY, bool selectedShip, int quantity, int type)
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setCursor(12, 0);
  gb.display.setColor(WHITE);
  gb.display.println("SET FLEET SHIPS");
  gb.display.setColor(BLUE);
  if (type == 1) //Select Fleet to attack
  {
    gb.display.setCursor(2, 9);
    gb.display.println("FIG");
    gb.display.setCursor(2, 17);
    gb.display.println("INT");
    gb.display.setCursor(2, 25);
    gb.display.println("FRI");
    gb.display.setCursor(2, 33);
    gb.display.println("W CR");
    gb.display.setCursor(2, 41);
    gb.display.println("S DR");
    gb.display.setCursor(2, 49);
    gb.display.println("S DS");
    gb.display.setColor(GREEN);
    gb.display.setCursor(19, 9);
    gb.display.println(PlayerShips[0]);
    gb.display.setCursor(19, 17);
    gb.display.println(PlayerShips[1]);
    gb.display.setCursor(19, 25);
    gb.display.println(PlayerShips[2]);
    gb.display.setCursor(19, 33);
    gb.display.println(PlayerShips[3]);
    gb.display.setCursor(19, 41);
    gb.display.println(PlayerShips[4]);
    gb.display.setCursor(19, 49);
    gb.display.println(PlayerShips[5]);
    gb.display.setColor(BLACK);
    gb.display.setCursor(40, 9);
    gb.display.println(CustomFleet.Fighters);
    gb.display.setCursor(40, 17);
    gb.display.println(CustomFleet.Interceptors);
    gb.display.setCursor(40, 25);
    gb.display.println(CustomFleet.Frigates);
    gb.display.setCursor(40, 33);
    gb.display.println(CustomFleet.WarCruisers);
    gb.display.setCursor(40, 41);
    gb.display.println(CustomFleet.StarDreadnoughts);
    gb.display.setCursor(40, 49);
    gb.display.println(CustomFleet.SolarDestroyers); 
  }
  else if (type == 2) //Select Fleet to raid
  {
    gb.display.setCursor(2, 9);
    gb.display.println("STL");
    gb.display.setCursor(2, 17);
    gb.display.println("LEV");
    gb.display.setColor(GREEN);
    gb.display.setCursor(19, 9);
    gb.display.println(PlayerShips[11]);
    gb.display.setCursor(19, 17);
    gb.display.println(PlayerShips[12]);
    gb.display.setColor(BLACK);
    gb.display.setCursor(40, 9);
    gb.display.println(CustomFleet.Stalkers);
    gb.display.setCursor(40, 17);
    gb.display.println(CustomFleet.Leviatans);
  }
  else //Select Fleet to intercept
  {
    gb.display.setCursor(2, 9);
    gb.display.println("MIS");
    gb.display.setColor(GREEN);
    gb.display.setCursor(19, 9);
    gb.display.println(PlayerShips[13]);
    gb.display.setColor(BLACK);
    gb.display.setCursor(40, 9);
    gb.display.println(CustomFleet.Missles);
  }
  gb.display.drawImage(2, 56, IMAGE_OK_BTN);
  gb.display.drawImage(26, 56, IMAGE_SELECTION_BTN);
  gb.display.drawImage(64, 56, IMAGE_CANCEL_BTN);
  gb.display.setColor(WHITE);
  gb.display.setCursor(4, 57);
  gb.display.println("A");
  gb.display.setCursor(28, 57);
  gb.display.println("MENU");
  gb.display.setCursor(66, 57);
  gb.display.println("B");
  if (selectedShip == true)
  {
    gb.display.setColor(RED);
    gb.display.drawRect(0, posY, 80, 9);
    gb.display.setCursor(56, posY + 2);
    gb.display.println("+-" + (String)quantity);
  }
  else
  {
    gb.display.setColor(DARKGRAY);
    gb.display.drawRect(0, posY, 80, 9);
  }
}

void drawSendFleetConfirmation(int mission, bool canSend)
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setColor(BLUE);
  gb.display.drawRect(1, 1, 3, 3);
  gb.display.setCursor(6, 0);
  gb.display.setFontSize(1);
  gb.display.println(PlayerResources[0]);
  gb.display.setColor(PURPLE);
  gb.display.drawRect(27, 1, 3, 3);
  gb.display.setCursor(33, 0);
  gb.display.println(PlayerResources[1]);
  gb.display.setColor(ORANGE);
  gb.display.drawRect(54, 1, 3, 3);
  gb.display.setCursor(60, 0);
  gb.display.println(PlayerResources[2]);
  gb.display.setColor(BLACK);
  if (mission != 5)
  {
    gb.display.setCursor(2, 8);
    gb.display.println("PLANET: " + SelectedPlanet.Name);
  }
  gb.display.setCursor(2, 15);
  gb.display.println("MISSION: ");
  gb.display.setCursor(2, 22);
  gb.display.println("FUEL COST: ");
  gb.display.setCursor(2, 29);
  gb.display.println("FLIGHT TIME: ");
  gb.display.setCursor(35, 15);
  if (mission == 1)
  {
    gb.display.setColor(RED);
    gb.display.println("ATTACK");
  }
  else if (mission == 2)
  {
    gb.display.setColor(BLUE);
    gb.display.println("COLONIZE");
  }
  else if (mission == 3)
  {
    gb.display.setColor(ORANGE);
    gb.display.println("SCOUT");
  }
  else if (mission == 4)
  {
    gb.display.setColor(GREEN);
    gb.display.println("RAID");
  }
  else if (mission == 5)
  {
    gb.display.setColor(PURPLE);
    gb.display.println("INTERCEPT");
  }
  gb.display.setCursor(42, 22);
  gb.display.println(FleetFuelCost);
  gb.display.setCursor(50, 29);
  gb.display.println(setTimeString(CustomFleet.Seconds, CustomFleet.Minutes));
  gb.display.drawImage(64, 56, IMAGE_CANCEL_BTN);
  gb.display.setColor(WHITE);
  gb.display.setCursor(66, 57);
  gb.display.println("B");
  if (canSend == true)
  {
    gb.display.drawImage(2, 56, IMAGE_OK_BTN);
    gb.display.setColor(WHITE);
    gb.display.setCursor(4, 57);
    gb.display.println("A");
  }
}

//---------------Intelligence Logic---------

void drawIntelligence()
{
  updateSelectionFrame();
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.drawImage(0, 11, IMAGE_INTELLIGENCE_BCG);
  gb.display.setColor(WHITE);
  gb.display.setCursor(15, 0);
  gb.display.println("INTELLIGENCE");
  gb.display.setColor(GREEN);
  gb.display.fillRect(10, 24, 60, 2);
  if (ProgressPointsLimit == 120)
  {
    gb.display.fillRect(10, 35, 60, 2); 
  }
  gb.display.setColor(RED);
  gb.display.setCursor(12, 17);
  gb.display.println("ENEMY ULTIMATE");
  if(selectionFrame == 0)
  {
    gb.display.setColor(RED);
  }
  else
  {
    gb.display.setColor(ORANGE);
  }
  int fixed1 = 0;
  if (ProgressPoints >= 60)
  {
    fixed1 = 60;
  }
  else
  {
    fixed1 = ProgressPoints;
  }
  gb.display.fillRect(10, 24, fixed1, 2);
  if(ProgressPointsLimit == 120)
  {
    int fixed2 = 0;  
    if (ProgressPoints >= 60)
    {
      fixed2 = ProgressPoints - 60;
    }
    gb.display.fillRect(10, 35, fixed2, 2); 
  }
  gb.display.setColor(RED);
  gb.display.setCursor(10, 39);
  gb.display.println("WEAPON PROGRESS");
  gb.display.setColor(ORANGE);
  gb.display.setCursor(25, 28);
  if(Difficulty == "EASY" || Difficulty == "NORMAL")
  {
    gb.display.println((String)ProgressPoints + "/" + (String)ProgressPointsLimit); 
  }
  else
  {
    gb.display.println((String)ProgressPoints + " / " + (String)ProgressPointsLimit);
  }
  gb.display.setCursor(8, 46);
  gb.display.setColor(RED);
  gb.display.println("CLIGG COLONIES:" + (String)CliggColonies);
  if (EnemyCount == 2)
  {
    gb.display.setCursor(8, 52);
    gb.display.setColor(RED);
    gb.display.println("SHEEZ COLONIES:" + (String)SheezColonies);
  }
}

void drawSpyReport(Report IntelligenceReport)
{
  gb.display.fill(WHITE);
  gb.display.drawImage(4, 8, IMAGE_MAIN_THEME);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setColor(WHITE);
  String title = "REPORT:" + IntelligenceReport.PlanetName;
  gb.display.println(title);
  gb.display.setCursor(0, 9);
  gb.display.setColor(BLACK);
  gb.display.println("TYPE: ");
  if (IntelligenceReport.Type == 1) //hostile report
  {
    gb.display.setCursor(20, 9);
    gb.display.setColor(RED);
    gb.display.println("HOSTILE");
    gb.display.setColor(BLUE);
    gb.display.setCursor(2, 17);
    gb.display.println("FIG");
    gb.display.setCursor(2, 25);
    gb.display.println("INT");
    gb.display.setCursor(2, 33);
    gb.display.println("FRI");
    gb.display.setCursor(2, 41);
    gb.display.println("W CR");
    gb.display.setCursor(2, 49);
    gb.display.println("S DR");
    gb.display.setCursor(2, 57);
    gb.display.println("S DS");
    gb.display.setColor(BLACK);
    gb.display.setCursor(25, 17);
    if (Colony[4].level >= 2) //Intelligence building
    {
      gb.display.println(IntelligenceReport.Fighters);
    }
    else
    {
      gb.display.println("???");
    }
    gb.display.setCursor(25, 25);
    if (Colony[4].level >= 4)
    {
      gb.display.println(IntelligenceReport.Interceptors);
    }
    else
    {
      gb.display.println("???");
    }
    gb.display.setCursor(25, 33);
    if (Colony[4].level >= 6)
    {
      gb.display.println(IntelligenceReport.Frigates);
    }
    else
    {
      gb.display.println("???");
    }
    gb.display.setCursor(25, 41);
    if (Colony[4].level >= 8)
    {
      gb.display.println(IntelligenceReport.WarCruisers);
    }
    else
    {
      gb.display.println("???");
    }
    gb.display.setCursor(25, 49);
    if (Colony[4].level >= 10)
    {
      gb.display.println(IntelligenceReport.StarDreadnoughts);
    }
    else
    {
      gb.display.println("???");
    }
    gb.display.setCursor(25, 57);
    if (Colony[4].level == 12) //Intelligence building
    {
      gb.display.println(IntelligenceReport.SolarDestroyers);
    }
    else
    {
      gb.display.println("???");
    }
  }
  else if (IntelligenceReport.Type == 2)
  {
    gb.display.setCursor(20, 9);
    gb.display.setColor(ORANGE);
    gb.display.println("MINING");
    gb.display.setColor(BLUE);
    gb.display.setCursor(2, 17);
    gb.display.println("METAL");
    gb.display.setCursor(30, 17);
    gb.display.println("+" + (String)IntelligenceReport.Resource1);
    gb.display.setColor(PURPLE);
    gb.display.setCursor(2, 25);
    gb.display.println("CRYSTAL");
    gb.display.setCursor(30, 25);
    gb.display.println("+" + (String)IntelligenceReport.Resource2);
    gb.display.setColor(ORANGE);
    gb.display.setCursor(2, 33);
    gb.display.println("FUEL");
    gb.display.setCursor(30, 33);
    gb.display.println("+" + (String)IntelligenceReport.Resource3);
  }
  else if (IntelligenceReport.Type == 3)
  {
    gb.display.setCursor(20, 9);
    gb.display.setColor(GREEN);
    gb.display.println("RAID - ACQUIRED");
    gb.display.setColor(BLUE);
    gb.display.setCursor(2, 17);
    gb.display.println("FIG");
    gb.display.setCursor(2, 25);
    gb.display.println("INT");
    gb.display.setCursor(2, 33);
    gb.display.println("FRI");
    gb.display.setColor(BLACK);
    gb.display.setCursor(25, 17);
    gb.display.println(IntelligenceReport.Fighters);
    gb.display.setCursor(25, 25);
    gb.display.println(IntelligenceReport.Interceptors);
    gb.display.setCursor(25, 33);
    gb.display.println(IntelligenceReport.Frigates);
  }
  else if (IntelligenceReport.Type == 4)
  {
    gb.display.setCursor(20, 9);
    gb.display.setColor(PURPLE);
    gb.display.println("INTERCEPT");
    gb.display.setColor(BLUE);
    gb.display.setCursor(2, 17);
    gb.display.println("FIG");
    gb.display.setCursor(2, 25);
    gb.display.println("INT");
    gb.display.setCursor(2, 33);
    gb.display.println("FRI");
    gb.display.setCursor(2, 41);
    gb.display.println("W CR");
    gb.display.setCursor(2, 49);
    gb.display.println("S DR");
    gb.display.setColor(BLACK);
    gb.display.setCursor(25, 17);
    gb.display.println("-" + (String)IntelligenceReport.Fighters);
    gb.display.setCursor(25, 25);
    gb.display.println("-" + (String)IntelligenceReport.Interceptors);
    gb.display.setCursor(25, 33);
    gb.display.println("-" + (String)IntelligenceReport.Frigates);
    gb.display.setCursor(25, 41);
    gb.display.println("-" + (String)IntelligenceReport.WarCruisers);
    gb.display.setCursor(25, 49);
    gb.display.println("-" + (String)IntelligenceReport.StarDreadnoughts);
  }
}

//---------------Shipyard Logic---------

void drawShipyardScreen(Ship ship, bool canBuild, bool selection, int quantity, int quantityToBuy, int owned, String restriction, int resource1Cost, int resource2Cost)
{
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.drawImage(0, 6, IMAGE_LINE_UP1);
  gb.display.drawImage(0, 34, IMAGE_INFO_DIALOG);
  gb.display.drawImage(0, 56, IMAGE_BOTTOM_LINE);
  gb.display.drawImage(0, 55, IMAGE_FLAT_LINE);
  gb.display.drawImage(0, 32, IMAGE_LINE_DOWN1);
  gb.display.drawImage(65, 17, IMAGE_BUTTON_FRAME);
  gb.display.setColor(BLUE);
  gb.display.drawRect(1, 1, 3, 3);
  gb.display.setCursor(6, 0);
  gb.display.setFontSize(1);
  gb.display.println(PlayerResources[0]);
  gb.display.setColor(PURPLE);
  gb.display.drawRect(27, 1, 3, 3);
  gb.display.setCursor(33, 0);
  gb.display.println(PlayerResources[1]);
  gb.display.setColor(ORANGE);
  gb.display.drawRect(54, 1, 3, 3);
  gb.display.setCursor(60, 0);
  gb.display.println(PlayerResources[2]);
  gb.display.setColor(GRAY);
  drawShipImage(ship.imageId);
  gb.display.setColor(WHITE);
  gb.display.setCursor(2, 9);
  gb.display.println(ship.type);
  gb.display.setColor(BLUE);
  gb.display.setCursor(36, 15);
  gb.display.println(resource1Cost);
  if (canBuild)
  {
    gb.display.drawImage(67, 19, IMAGE_SHIPS_BTN);
    gb.display.drawImage(66, 18, Selector); 
  }
  gb.display.setColor(PURPLE);
  gb.display.setCursor(36, 21);
  gb.display.println(resource2Cost);
  gb.display.setColor(WHITE);
  gb.display.setCursor(0, 35);
  gb.display.println(ship.describtion);
  if (restriction != "")
  {
    gb.display.setColor(RED);
    gb.display.setCursor(2, 57);
    gb.display.println(restriction);
  }
  else
  {
    if (selection)
    {
      gb.display.setColor(GRAY);
      gb.display.setCursor(47, 57);
      gb.display.println(quantityToBuy);
      gb.display.setColor(YELLOW);
      gb.display.drawRect(45, 55, 35, 9);
      gb.display.setCursor(59, 57);
      gb.display.println("+-" + (String)quantity);
    }
    gb.display.setColor(GREEN);
    gb.display.setCursor(2, 57);
    gb.display.println("OWNED:" + (String)owned);
  }
}

void drawShipImage(int id)
{
  switch (id)
  {
    case 1:
      gb.display.drawImage(3, 16, IMAGE_FIGHTER); break;
    case 2:
      gb.display.drawImage(3, 16, IMAGE_INTERCEPTOR); break;
    case 3:
      gb.display.drawImage(3, 16, IMAGE_FRIGATE); break;
    case 4:
      gb.display.drawImage(2, 16, IMAGE_WAR_CRUISER); break;
    case 5:
      gb.display.drawImage(2, 16, IMAGE_STAR_DREADNOUGHT); break;
    case 6:
      gb.display.drawImage(2, 16, IMAGE_SOLAR_DESTROYER); break;
    case 7:
      gb.display.drawImage(2, 16, IMAGE_SPY_BOT); break;
    case 8:
      gb.display.drawImage(2, 16, IMAGE_COLONIZER); break;
    case 9:
      gb.display.drawImage(2, 16, IMAGE_METAL_TRANSPORT); break;
    case 10:
      gb.display.drawImage(2, 16, IMAGE_CRYSTAL_TRANSPORT); break;
    case 11:
      gb.display.drawImage(2, 16, IMAGE_FUEL_TRANSPORT); break;
    case 12:
      gb.display.drawImage(2, 16, IMAGE_STALKER); break;
    case 13:
      gb.display.drawImage(2, 16, IMAGE_LEVIATAN); break;
    case 14:
      gb.display.drawImage(2, 16, IMAGE_MISSLE); break;
    default:
      gb.display.drawRect(3, 16, 28, 13); break;
  }
}

//---------------Transformer Logic---------

void drawTransformer(int mode, int multipler, int convert, int created)
{
  gb.display.drawImage(0, 22, IMAGE_TRANSFORMER_BCG);
  gb.display.drawImage(0, 0, IMAGE_INFO_FRAME);
  gb.display.setColor(WHITE);
  gb.display.setCursor(18, 0);
  gb.display.println("TRANSFORMER");
  gb.display.setCursor(0, 14);
  gb.display.println("CREATE:");
  gb.display.setCursor(30, 14); 
  if (mode == 1)
  {
    gb.display.setColor(BLUE);
    gb.display.println("METAL");
    gb.display.setColor(ORANGE);
    gb.display.fillRect(5, 37, 3, 3); 
  }
  else if (mode == 2)
  {
    gb.display.setColor(PURPLE);
    gb.display.println("CRYSTAL");
    gb.display.setColor(ORANGE);
    gb.display.fillRect(5, 37, 3, 3); 
  }
  else if (mode == 3)
  {
    gb.display.setColor(ORANGE);
    gb.display.println("FUEL");
    gb.display.setColor(BLUE);
    gb.display.fillRect(5, 37, 3, 3);
  }
  else
  {
    gb.display.setColor(ORANGE);
    gb.display.println("FUEL");
    gb.display.setColor(PURPLE);
    gb.display.fillRect(5, 37, 3, 3);
  }
  gb.display.setCursor(11, 36);
  String toConvert = createString(convert);
  gb.display.println(toConvert);
  if (mode == 1)
  {
    gb.display.setColor(BLUE); 
  }
  else if (mode == 2)
  {
    gb.display.setColor(PURPLE);
  }
  else
  {
    gb.display.setColor(ORANGE);
  }
  gb.display.fillRect(54, 37, 3, 3);
  gb.display.setCursor(60, 36);
  String toCreate = createString(created);
  gb.display.println(toCreate);
  gb.display.setColor(RED);
  gb.display.setCursor(32, 27);
  gb.display.println((String)multipler + "/6");
}

String createString(int number)
{
  String result = "";
  if ((number >= 0) && (number < 10))
  {
    result = "   " + (String)number;
  }
  else if ((number > 9) && (number < 100))
  {
    result = "  " + (String)number;
  }
  else if ((number > 99) && (number < 1000))
  {
    result = " " + (String)number;
  }
  else
  {
    result = (String)number;
  }
  return result;
}

//---------------Game Over---------

void drawEndGameScreen(bool victorious)
{
  gb.display.setFontSize(2);
  gb.display.setCursor(21, 5);
  if (victorious == true)
  {
    gb.display.setCursor(10, 25);
    gb.display.setColor(GREEN);
    gb.display.println("VICTORY!");
  }
  else
  {
    gb.display.setCursor(14, 25);
    gb.display.setColor(RED);
    gb.display.println("DEFEAT!");
  }
  gb.display.setFontSize(1); 
  gb.display.setCursor(15, 46);
  gb.display.setColor(BLUE);
  gb.display.println("SCORE:" + scoreStrMod(Score));
}

void updateSelectionFrame()
{
  if (selectionFrame == 0)
  {
    selectionFrame = 1;
  }
  else
  {
    selectionFrame = 0;
  }
}
