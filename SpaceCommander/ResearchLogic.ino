int8_t currentTech=0;

int8_t research(Technology techTree[20],int playerResources[3])
{
  String dependencyTechName="";
  int dependencyTechLevel=0; 
  int depIndex=techTree[currentTech].depTechId-1;
  if(depIndex<20)
  {
    dependencyTechName=techTree[depIndex].techName;
    dependencyTechLevel=techTree[currentTech].depTechLevel; 
  }
  bool canDevelop=canResearch(techTree[currentTech],techTree[depIndex].level,playerResources); 
  drawTechScreen(techTree[currentTech],dependencyTechName,techTree[depIndex].level,playerResources,canDevelop);
  if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(currentTech==19)
    {
      currentTech=0;
    }
    else
    {
      currentTech++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(currentTech==0)
    {
      currentTech=19;
    }
    else
    {
      currentTech--;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(canDevelop)
    {
      techTree[currentTech].level++;
      techTree[currentTech].depTechLevel++;
      playerResources[0]-=(techTree[currentTech].resource1Cost*(techTree[currentTech].level+1));
      playerResources[1]-=(techTree[currentTech].resource2Cost*(techTree[currentTech].level+1));
      playerResources[2]-=(techTree[currentTech].resource3Cost*(techTree[currentTech].level+1)); 
    }
  }
  else if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 2;
}

bool canResearch(Technology technology, int depTechLvl, int playerResources[3])
{
  bool result=true;
  if(playerResources[0]<(technology.resource1Cost*(technology.level+1)))
  {
    result=false; 
  }
  if(playerResources[1]<(technology.resource2Cost*(technology.level+1)))
  {
    result=false; 
  }
  if(playerResources[2]<(technology.resource3Cost*(technology.level+1)))
  {
    result=false;
  }
  if(depTechLvl>0)
  {
    if(technology.depTechLevel>depTechLvl)
    {
      result=false;     
    }
  }  
  return result;
}

