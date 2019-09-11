int8_t reCurrentTech=0;

int8_t research(Technology techTree[20],int playerResources[3])
{
  String dependencyTechName="";
  int dependencyTechLevel=0; 
  int depIndex=techTree[reCurrentTech].depTechId-1;
  if(depIndex<20)
  {
    dependencyTechName=techTree[depIndex].techName;
    dependencyTechLevel=techTree[reCurrentTech].depTechLevel; 
  }
  bool canDevelop=canResearch(techTree[reCurrentTech],techTree[depIndex].level,playerResources); 
  drawTechScreen(techTree[reCurrentTech],dependencyTechName,techTree[depIndex].level,playerResources,canDevelop);
  if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(reCurrentTech==19)
    {
      reCurrentTech=0;
    }
    else
    {
      reCurrentTech++;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(reCurrentTech==0)
    {
      reCurrentTech=19;
    }
    else
    {
      reCurrentTech--;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(canDevelop)
    {
      techTree[reCurrentTech].level++;
      techTree[reCurrentTech].depTechLevel++;
      playerResources[0]-=(techTree[reCurrentTech].resource1Cost*(techTree[reCurrentTech].level+1));
      playerResources[1]-=(techTree[reCurrentTech].resource2Cost*(techTree[reCurrentTech].level+1));
      playerResources[2]-=(techTree[reCurrentTech].resource3Cost*(techTree[reCurrentTech].level+1));
      techEvents(); 
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

void techEvents()
{
  if(reCurrentTech==0)//Astronomy
  {
    discoverNewPlanet();
  }
}

void discoverNewPlanet()
{
  switch(TechTree[0].level)
  {
    case 2:
      System[16].Discovered=true; break;
    case 5:
      System[15].Discovered=true; break;
    case 7:
      System[19].Discovered=true; break;
    case 11:
      System[13].Discovered=true; break;
    case 12:
      System[12].Discovered=true; break;
    case 14:
      System[18].Discovered=true; break;
    case 16:
      System[20].Discovered=true; break;
    case 17:
      System[8].Discovered=true;
      System[23].Discovered=true; break;
    case 19:
      System[5].Discovered=true; break;
    case 20:
      System[24].Discovered=true; break;
    case 22:
      System[7].Discovered=true;
      System[25].Discovered=true; break;
    case 23:
      System[17].Discovered=true;
      System[22].Discovered=true; break;
    case 24:
      System[11].Discovered=true; break;
    case 25:
      System[4].Discovered=true;
      System[14].Discovered=true; break;
    case 26:
      System[6].Discovered=true; break;
    case 27:
      System[28].Discovered=true; break;
    case 28:
      System[27].Discovered=true; break;
    case 30:
      System[3].Discovered=true; break;
    case 31:
      System[21].Discovered=true; break;
    case 33:
      System[9].Discovered=true;
      System[10].Discovered=true; break;
    case 35:
      System[26].Discovered=true;
      System[29].Discovered=true; break;
    case 38:
      System[1].Discovered=true;
      System[2].Discovered=true; break;
  }
}

