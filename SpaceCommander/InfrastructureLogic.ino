int8_t inCurrentBuilding=0;

int8_t infrastructure()
{
  int techIndex=Colony[inCurrentBuilding].depTechId;
  int buildingIndex=Colony[inCurrentBuilding].depBuildingId;
  String dependencyTechName=TechTree[techIndex].techName;
  int dependencyTechLevel=TechTree[techIndex].level;
  String dependencyBuildingName=Colony[buildingIndex].bName;
  int dependencyBuildingLevel=Colony[buildingIndex].level;
  drawInfrastructureScreen(Colony[inCurrentBuilding],dependencyTechName,dependencyTechLevel,dependencyBuildingName,dependencyBuildingLevel,true);
  if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(inCurrentBuilding==14)
    {
      inCurrentBuilding=0;
    }
    else
    {
      inCurrentBuilding++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(inCurrentBuilding==0)
    {
      inCurrentBuilding=14;
    }
    else
    {
      inCurrentBuilding--;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(true)
    {
      PlayerResources[0]-=(Colony[inCurrentBuilding].resource1Cost*(Colony[inCurrentBuilding].level+1));
      PlayerResources[1]-=(Colony[inCurrentBuilding].resource2Cost*(Colony[inCurrentBuilding].level+1));
      PlayerResources[2]-=(Colony[inCurrentBuilding].resource3Cost*(Colony[inCurrentBuilding].level+1)); 
      Colony[inCurrentBuilding].level++;
      //Colony[inCurrentBuilding].depTechLevel++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 1;
}
