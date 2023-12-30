int trMode = 1;
int trMultipler = 16;
int trConvert = 0;
int trCreated = 0;

int8_t transformer()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (trMode == 1) //convert crystal to metal
    {
      trMode = 2;
      trMultipler = 20 - Colony[11].level;
      trCreated = 0;
      trConvert = 0;
    }
    else if (trMode == 2) //convert metal to fuel
    {
      trMode = 3;
      trMultipler = 35 - Colony[11].level;
      trCreated = 0;
      trConvert = 0;
    }
    else if (trMode == 3) //convert crystal to fuel
    {
      trMode = 4;
      trMultipler = 25 - Colony[11].level;
      trCreated = 0;
      trConvert = 0;
    }
    else  //convert metal to crystal
    {
      trMode = 1;
      trMultipler = 16 - Colony[11].level;
      trCreated = 0;
      trConvert = 0;
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (trMode == 1)
    {
      trMode = 4;
      trMultipler = 25 - Colony[11].level;
      trCreated = 0;
      trConvert = 0;
    }
    else if (trMode == 4)
    {
      trMode = 3;
      trMultipler = 35 - Colony[11].level;
      trCreated = 0;
      trConvert = 0;
    }
    else if (trMode == 3)
    {
      trMode = 2;
      trMultipler = 20 - Colony[11].level;
      trCreated = 0;
      trConvert = 0;
    }
    else
    {
      trMode = 1;
      trMultipler = 16 - Colony[11].level;
      trCreated = 0;
      trConvert = 0;
    }
  }
  else if (gb.buttons.repeat(BUTTON_UP, 2))
  {
    if (trConvert < 9999)
    {
      if (trMode == 1 || trMode == 2)
      {
        if (PlayerResources[2] > (trConvert + trMultipler))
        {
          trConvert += trMultipler;
          trCreated += 6;
        } 
      }
      else if (trMode == 3) //metal to fuel
      {
        if (PlayerResources[0] > (trConvert + trMultipler))
        {
          trConvert += trMultipler;
          trCreated += 6;
        }
      }
      else  //crystal to fuel
      {
        if (PlayerResources[1] > (trConvert + trMultipler))
        {
          trConvert += trMultipler;
          trCreated += 6;
        }
      }
    }
  }
  else if (gb.buttons.repeat(BUTTON_DOWN, 2))
  {
    if (trConvert != 0)
    {
      trConvert -= trMultipler;
      trCreated -= 6;
    }
  }
  else if(gb.buttons.pressed(BUTTON_A))
  {
    if (trCreated > 0)
    {
      if (trMode == 1)
      {
        if ((PlayerResources[0] + trCreated) < 9999)
        {
          PlayerResources[0] += trCreated;
          PlayerResources[2] -= trConvert;
          trCreated = 0;
          trConvert = 0;
          gb.gui.popup("RESOURCE CREATED!", 50);
        }
      }
      else if (trMode == 2)
      {
        if ((PlayerResources[1] + trCreated) < 9999)
        {
          PlayerResources[1] += trCreated;
          PlayerResources[2] -= trConvert;
          trCreated = 0;
          trConvert = 0;
          gb.gui.popup("RESOURCE CREATED!", 50);
        }
      }
      else if (trMode == 3)
      {
        if ((PlayerResources[2] + trCreated) < 9999)
        {
          PlayerResources[2] += trCreated;
          PlayerResources[0] -= trConvert;
          trCreated = 0;
          trConvert = 0;
          gb.gui.popup("RESOURCE CREATED!", 50);
        }
      }
      else
      {
        if ((PlayerResources[2] + trCreated) < 9999)
        {
          PlayerResources[2] += trCreated;
          PlayerResources[1] -= trConvert;
          trCreated = 0;
          trConvert = 0;
          gb.gui.popup("RESOURCE CREATED!", 50);
        }
      }
    }
  }
  drawTransformer(trMode, trMultipler, trConvert, trCreated);
  return 9;
}

void resetTransformer()
{
  trMode = 1;
  trMultipler = 16 - Colony[11].level;
  trConvert = 0;
  trCreated = 0;
}

void resetTransformerAfterAttack()
{
  trConvert = 0;
  trCreated = 0;
}

