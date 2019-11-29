int trMode=5;
int trMultipler=15;
int trConvert=0;
int trCreated=0;

int8_t transformer()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
    trConvert=0;
    trCreated=0;
    return 0;
  }
  else if(gb.buttons.pressed(BUTTON_RIGHT))
  {
    if(trMode==1)
    {
      trMode=2;
      trMultipler=20;
      trCreated=0;
      trConvert=0;
    }
    else
    {
      trMode=1;
      trMultipler=15;
      trCreated=0;
      trConvert=0;
    }
  }
  else if(gb.buttons.pressed(BUTTON_LEFT))
  {
    if(trMode==1)
    {
      trMode=2;
      trMultipler=20;
      trCreated=0;
      trConvert=0;
    }
    else
    {
      trMode=1;
      trMultipler=15;
      trCreated=0;
      trConvert=0;
    }
  }
  else if(gb.buttons.pressed(BUTTON_UP))
  {
    if(trConvert<9999)
    {
      if(PlayerResources[2]>(trConvert+trMultipler))
      {
        trConvert+=trMultipler;
        trCreated+=3;
      }
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(trConvert!=0)
    {
      trConvert-=trMultipler;
      trCreated-=3;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if(trCreated>0)
    {
      if(trMode==1)
      {
        if((PlayerResources[0]+trCreated)<9999)
        {
          PlayerResources[0]+=trCreated;
          PlayerResources[2]-=trConvert;
          trCreated=0;
          trConvert=0;
          gb.gui.popup("RESOURCE CREATED!",50);
        }
      }
      else
      {
        if((PlayerResources[1]+trCreated)<9999)
        {
          PlayerResources[1]+=trCreated;
          PlayerResources[2]-=trConvert;
          trCreated=0;
          trConvert=0;
          gb.gui.popup("RESOURCE CREATED!",50);
        }
      } 
    }
  }
  drawTransformerScreen(trMode,trMultipler,trConvert,trCreated);
  return 9;
}

