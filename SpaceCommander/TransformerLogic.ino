int trMode=5;
int trMultipler=15;
int trConvert=0;
int trCreated=0;

int8_t transformer()
{
  if(gb.buttons.pressed(BUTTON_B))
  {
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
      trConvert+=trMultipler;
      trCreated+=1;
    }
  }
  else if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(trConvert!=0)
    {
      trConvert-=trMultipler;
      trCreated-=1;
    }
  }
  drawTransformerScreen(trMode,trMultipler,trConvert,trCreated);
  return 9;
}

