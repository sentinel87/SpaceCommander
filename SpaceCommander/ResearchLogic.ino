int8_t reCurrentTech=0;

int8_t research()
{
  String dependencyTechName="";
  int dependencyTechLevel=0; 
  int depIndex=TechTree[reCurrentTech].depTechId-1;
  if(depIndex>-1&&depIndex<20)
  {
    dependencyTechName=TechTree[depIndex].techName;
    dependencyTechLevel=TechTree[reCurrentTech].depTechLevel;   
  }
  bool canDevelop=canResearch(TechTree[reCurrentTech],TechTree[depIndex].level);
  drawTechScreen(TechTree[reCurrentTech],dependencyTechName,TechTree[depIndex].level,canDevelop);
  if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    moveNext();
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    movePrevious();
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(canDevelop)
    {
      PlayerResources[0]-=(TechTree[reCurrentTech].resource1Cost*(TechTree[reCurrentTech].level+1));
      PlayerResources[1]-=(TechTree[reCurrentTech].resource2Cost*(TechTree[reCurrentTech].level+1));
      PlayerResources[2]-=(TechTree[reCurrentTech].resource3Cost*(TechTree[reCurrentTech].level+1));
      TechTree[reCurrentTech].level++;
      if(TechTree[reCurrentTech].depTechLevel!=0)
      {
        TechTree[reCurrentTech].depTechLevel++; 
      }
      techEvents(); 
    }
  }
  else if(gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  return 4;
}

bool canResearch(Technology technology, int depTechLvl)
{
  bool result=true;
  if(PlayerResources[0]<(technology.resource1Cost*(technology.level+1)))
  {
    result=false; 
  }
  if(PlayerResources[1]<(technology.resource2Cost*(technology.level+1)))
  {
    result=false; 
  }
  if(PlayerResources[2]<(technology.resource3Cost*(technology.level+1)))
  {
    result=false;
  }
  if(technology.depTechLevel>0)
  {
    if(technology.depTechLevel>depTechLvl)
    {
      result=false;     
    }
  }
  if(technology.maxLevel==technology.level)
  {
    result=false;  
  }
  return result;
}

void moveNext()
{
  if(reCurrentTech+1<Colony[7].level)
  {
    if(reCurrentTech==15)
    {
      reCurrentTech=0;
    }
    else
    {
      reCurrentTech++;
    }
  }
  else
  {
    reCurrentTech=0;
  }
}

void movePrevious()
{
  if(reCurrentTech==0)
  {
    reCurrentTech=Colony[7].level-1;
  }
  else
  {
    reCurrentTech--;
  }
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

