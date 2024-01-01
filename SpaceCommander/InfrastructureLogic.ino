int8_t inCurrentBuilding = 0;

int8_t infrastructure()
{
  bool canBuild = true;
  bool maxLevelReached = true;
  if (Colony[inCurrentBuilding].level < Colony[inCurrentBuilding].maxLevel)
  {
    maxLevelReached = false;
  }
  int techIndex = Colony[inCurrentBuilding].depTechId - 1;
  int buildingIndex = Colony[inCurrentBuilding].depBuildingId - 1;
  String dependencyTechName = "";
  int dependencyTechLevel = 0;
  String dependencyBuildingName = "";
  int dependencyBuildingLevel = 0;

  if (buildingIndex != -1)
  {
    dependencyBuildingName = Colony[buildingIndex].bName;
    dependencyBuildingLevel = Colony[buildingIndex].level;
    if (Colony[inCurrentBuilding].depBuildingLevel <= Colony[buildingIndex].level)
    {
      canBuild = true;
    }
    else
    {
      canBuild = false;
    }
  }
  if (techIndex != -1)
  {
    dependencyTechName = TechTree[techIndex].techName;
    dependencyTechLevel = TechTree[techIndex].level;
    if (Colony[inCurrentBuilding].depTechLevel <= TechTree[techIndex].level)
    {
      canBuild = true;
    }
    else
    {
      canBuild = false;
    }
  }
  if (canBuild == true)
  {
    if ((PlayerResources[0] >= ((Colony[inCurrentBuilding].resource1Cost - 15 * (Colony[9].level)) * (Colony[inCurrentBuilding].level + 1))) 
    && (PlayerResources[1] >= ((Colony[inCurrentBuilding].resource2Cost - 15 * (Colony[9].level)) * (Colony[inCurrentBuilding].level + 1))) 
    && (PlayerResources[2] >= (Colony[inCurrentBuilding].resource3Cost * (Colony[inCurrentBuilding].level + 1))) 
    && maxLevelReached == false)
    {
      canBuild = true;
    }
    else
    {
      canBuild = false;
    }
  }
  if (canBuild == true)
  {
    if (Colony[inCurrentBuilding].maxLevel == Colony[inCurrentBuilding].level)
    {
      canBuild = false;
    }
  }
  
  if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (inCurrentBuilding == 14)
    {
      inCurrentBuilding = 0;
    }
    else
    {
      inCurrentBuilding++;
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (inCurrentBuilding == 0)
    {
      inCurrentBuilding = 14;
    }
    else
    {
      inCurrentBuilding--;
    }
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    if (canBuild == true)
    {
      PlayerResources[0] -= ((Colony[inCurrentBuilding].resource1Cost - 15 * (Colony[9].level)) * (Colony[inCurrentBuilding].level + 1));
      PlayerResources[1] -= ((Colony[inCurrentBuilding].resource2Cost - 15 * (Colony[9].level)) * (Colony[inCurrentBuilding].level + 1));
      PlayerResources[2] -= (Colony[inCurrentBuilding].resource3Cost * (Colony[inCurrentBuilding].level + 1));
      if (Colony[inCurrentBuilding].depTechLevel > 0)
      {
        Colony[inCurrentBuilding].depTechLevel++;   
      }
      else if (Colony[inCurrentBuilding].depBuildingLevel > 0)
      {
        Colony[inCurrentBuilding].depBuildingLevel++;
      }
      Colony[inCurrentBuilding].level++;
    }
  }
  else if (gb.buttons.pressed(BUTTON_B))
  {
    inCurrentBuilding = 0;
    return 0;
  }

  drawInfrastructureScreen(Colony[inCurrentBuilding], dependencyTechName, dependencyTechLevel,dependencyBuildingName, dependencyBuildingLevel, canBuild, maxLevelReached);
  return 2;
}

