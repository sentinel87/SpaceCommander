int8_t inReportIdx = 0;

int8_t intelligence()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    return 0;
  }
  drawIntelligence();
  return 10;
}

int8_t scoutReports()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    inReportIdx = 0;
    return 0;
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (inReportIdx < 4)
    {
      inReportIdx++;
    }
    else
    {
      inReportIdx = 0;
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (inReportIdx > 0)
    {
      inReportIdx--;
    }
    else
    {
      inReportIdx = 4;
    }
  }
  drawSpyReport(IntelligenceReports[inReportIdx]);
  return 7;
}

void generateScoutReport(Report report)
{
  Report Temp[5] = IntelligenceReports;
  IntelligenceReports[0] = report;
  for (int i = 1; i < 5; i++)
  {
    IntelligenceReports[i] = Temp[i - 1];
  }
  gb.gui.popup("NEW SCOUT REPORT!", 50);
}
