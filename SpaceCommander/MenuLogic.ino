int mmSelection=0;


int8_t mainMenu()
{
  if(gb.buttons.pressed(BUTTON_UP))
  {
    if(mmSelection==0)
    {
      mmSelection=1;
    }
    else
    {
      mmSelection=0;
    }
  }
  if(gb.buttons.pressed(BUTTON_DOWN))
  {
    if(mmSelection==0)
    {
      mmSelection=1;
    }
    else
    {
      mmSelection=0;
    }
  }
  drawMainMenu(mmSelection);
  return 0;
}

