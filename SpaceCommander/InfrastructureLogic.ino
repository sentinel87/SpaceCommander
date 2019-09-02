int8_t currentBuilding=0;

int8_t infrastructure(Building colony[15],Technology techTree[20],int playerResources[3])
{
  int techIndex=colony[currentBuilding].depTechId;
  int buildingIndex=colony[currentBuilding].depBuildingId;
  String dependencyTechName=techTree[techIndex].techName;
  int dependencyTechLevel=techTree[techIndex].level;
  String dependencyBuildingName=colony[buildingIndex].bName;
  int dependencyBuuildingLevel=colony[buildingIndex].level;
  drawInfrastructureScreen(colony[currentBuilding],dependencyTechName,dependencyTechLevel,dependencyBuildingName,dependencyBuuildingLevel,playerResources,true);
  if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(currentBuilding==14)
    {
      currentBuilding=0;
    }
    else
    {
      currentBuilding++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(currentBuilding==0)
    {
      currentBuilding=14;
    }
    else
    {
      currentBuilding--;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(true)
    {
      colony[currentBuilding].level++;
      //colony[currentBuilding].depTechLevel++;
      playerResources[0]-=(colony[currentBuilding].resource1Cost*(colony[currentBuilding].level+1));
      playerResources[1]-=(colony[currentBuilding].resource2Cost*(colony[currentBuilding].level+1));
      playerResources[2]-=(colony[currentBuilding].resource3Cost*(colony[currentBuilding].level+1)); 
    }
  }
  else if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 1;
}
