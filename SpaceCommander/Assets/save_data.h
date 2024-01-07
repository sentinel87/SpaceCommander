#pragma once

Planet System[] = {
  {true,"UEF Colony",38,28,false,0,0,0,0,true,false,-1,true,false},
  {false,"Sheez Prime",76,28,false,0,3,2,2,false,false,-1,false,false},
  {false,"Cligg Prime",0,28,true,1,0,0,0,false,false,0,false,false},
  {false,"Ganimedes",33,35,false,0,1,2,0,false,false,-1,false,false},//Poor resources (3)
  {false,"Raven",33,24,false,0,1,1,1,true,false,-1,false,false},
  {false,"Novaria",36,26,false,0,1,0,2,false,false,-1,false,false},
  {false,"Kanton",27,9,false,0,2,0,3,false,false,-1,false,false},//Medium resources(6)
  {false,"Armag",14,22,false,0,1,4,0,false,false,-1,false,false},
  {false,"Syrius",55,11,false,0,3,2,0,false,false,-1,false,false},
  {false,"Tibann",26,19,false,0,1,3,1,false,false,-1,false,false},
  {false,"San Da",48,17,false,0,0,5,0,false,false,-1,false,false},
  {false,"Tolka",63,23,false,0,1,1,3,false,false,-1,false,false},
  {false,"Eden",15,30,false,0,0,5,0,false,false,-1,false,false},
  {false,"Brantal V",24,32,false,0,5,0,0,false,false,-1,false,false},
  {false,"Dan 11",54,32,false,0,0,0,5,false,false,-1,false,false},
  {false,"Arti Ka",15,41,false,0,0,2,3,false,false,-1,false,false},
  {false,"Tyra",27,45,false,0,4,1,0,false,false,-1,false,false},
  {false,"Galant",51,48,false,0,2,1,2,false,false,-1,false,false},
  {false,"Saxa",60,40,false,0,0,5,0,false,false,-1,false,false},
  {false,"Tau 14",8,3,false,0,5,1,1,false,false,-1,false,false},//Rich resources (19)
  {false,"Cassia",14,3,false,0,2,2,3,false,false,-1,false,false},
  {false,"Nova 5",34,2,false,0,1,5,1,false,false,-1,false,false},
  {false,"Andromeda",44,6,false,0,1,1,5,false,false,-1,false,false},
  {false,"Arnval",71,7,false,0,1,2,4,false,false,-1,false,false},
  {false,"Duna",5,15,false,0,4,2,1,false,false,-1,false,false},
  {false,"Janya",7,43,false,0,5,1,1,false,false,-1,false,false},
  {false,"Rea 8",73,37,false,0,3,2,2,false,false,-1,false,false},
  {false,"IO",66,54,false,0,2,3,2,false,false,-1,false,false},
  {false,"Taka Van",33,55,false,0,3,4,0,false,false,-1,false,false},
  {false,"Europa",3,55,false,0,4,3,0,false,false,-1,false,false}
};

Technology TechTree[] = {
  {1,"Astronomy",2,25,30,20,"Increases visibilityon the Star Map.","None",0,0,39},
  {2,"Espionage",0,150,75,75,"Unlock  Intelligenceand Spy Bots.","Astronomy",1,2,16},
  {3,"Jet Proplusion",0,100,100,100,"Unlock Fighters and increases their     speed.","Astronomy",1,2,19},
  {4,"Fleet Tactics",0,100,25,10,"Needed to upgrade   shipyard and build  high level ships.","Astronomy",1,5,16},
  {5,"Radiolocation",0,70,90,60,"Unlock Radar and    increases visibilityrange.","Espionage",2,1,16},
  {6,"Logistics",0,120,120,50,"+ 1 to Star Routes  and Colonies. UnlockTransports.","Astronomy",1,5,12},
  {7,"Aerodynamics",0,150,120,150,"Unlock Interceptors and increases their speed.","Jet Proplusion",3,4,15},
  {8,"Cloaking",0,250,190,150,"Unlock  Stalkers.   Stalker steal 1/lvl enemy fighter and   interceptor.","Radiolocation",5,1,11},
  {9,"EMP Weapon",0,300,400,300,"Unlock EMP Launcher and EMP missles.    Increases missle    power.","Radiolocation",5,6,10},
  {10,"Statics",0,200,350,50,"Unlock Warehouse andincreases it's      capacity.","Logistics",6,2,11},
  {11,"Economy",0,400,400,200,"Unlock and improve  Market.","Logistics",6,2,8},
  {12,"Impulse Engine",0,50,250,200,"Unlock Frigates and increases their     speed.","Aerodynamics",7,4,11},
  {13,"Shielding",0,350,400,100,"Unlock Planetary    Defence System and  increases firepower.","Fleet Tactics",4,1,14},
  {14,"Mind Control",0,350,500,350,"Unlock  Leviatans.  Leviatan steal 1/lvlenemy Frigate.","Cloaking",8,4,5},
  {15,"Hyperdrive",0,100,500,400,"Unlock War Cruisers and increases their speed.","Impulse Engine",12,2,10},
  {16,"Fusion Reaction",0,450,350,250,"Unlock and improve  Transformer.","Fleet Tactics",4,5,10},
  {17,"Ship Weapons",0,125,300,75,"Final level unlock  Star Dreadnought.","Shielding",13,2,10},
  {18,"Flight Control",0,350,200,250,"Unlock and improve  Logistic Centre.","Statics",10,2,10},
  {19,"Gravity Weapon",0,800,800,800,"Final level of this technology unlock   Solar Destructor.","Hyperdrive",15,1,9},
  {20,"Composite Armor",0,1000,1000,1000,"Reduce War Cruiser, Star Dreadnought andSolar Destructor    costs.","Ship Weapons",17,5,5}
};

Building Colony[] = {
  {1,"Power Plant",1,"Required to build   higher level        mines.",200,190,150,0,0,0,0,15},
  {2,"Metal Mine",1,"Extract metal       resource.",210,195,25,0,0,1,2,15},
  {3,"Crystal Mine",1,"Extract crystal     resource.",200,230,50,0,0,1,2,15},
  {4,"Fuel Refinery",0,"Deliver fuel        resource.",200,185,65,0,0,1,2,14},
  {5,"Intelligence",0,"Reveals more intel  in hostile reports.",210,185,10,2,1,0,0,12},
  {6,"Radar",0,"Detects enemy fleets+1 visibility / lvl.",165,165,35,5,1,0,0,16},
  {7,"Shipyard",0,"Required to build   colony ships.",350,350,275,4,1,0,0,11},
  {8,"Research Lab",0,"Unlock additional   technology / lvl.",175,175,75,0,0,0,0,20},
  {9,"Defence System",0,"Provides additional firepower for colonydefence / lvl.",210,250,75,13,1,0,0,14},
  {10,"Factory",0,"Reduces metal and   crystal cost of     buildings.",300,220,60,0,0,0,0,10},
  {11,"Warehouse",0,"Stores resources    when losing battle. +200 for each       resource / lvl.",300,300,50,10,1,0,0,10},
  {12,"Transformer",0,"Converts one        resource to another.",350,300,550,16,1,0,0,10},
  {13,"Logistic Centre",0,"Increases resource  transport from traderoutes.",400,200,300,18,1,0,0,10},
  {14,"Market",0,"Exachange fuel for  resources and ships.",220,220,150,11,1,0,0,8},
  {15,"EMP Launcher",0,"Fires EMP Missles +1 / lvl into enemy   fleets.",300,300,200,9,1,0,0,10}
};

Ship Shipyard[] = {
  {"Fighter",1,"Swarm of Fighters isbasic fleet defence.",50,15},
  {"Interceptor",2,"Ship designed to    hunt down Fighters.",100,40},
  {"Frigate",3,"Light armored ship. Bonus against       Fighters.",270,150},
  {"War Cruiser",4,"First line attack   ship. Bonus against Interceptors.",400,230},
  {"Star Dreadnought",5,"Heavy armored ship  used to transport   entire fleet.",550,300},
  {"Solar Destructor",6,"Ship designed to    destroy entire      planet.",4000,4000},
  {"Spy Bot",7,"Fragile probe used  to scan planets and enemy fleets.",15,10},
  {"Colonizer",8,"Sets colony on the  planet.",900,900},
  {"Metal Transport",9,"Transport metal fromcolonies.",350,35},
  {"Crystal Transport",10,"Transport crystals  from colonies.",400,150},
  {"Fuel Transport",11,"Transport fuel from colonies.",300,200},
  {"Stalker",12,"Steal enemy Fightersand Interceptors.",300,300},
  {"Leviatan",13,"Steal enemy         Frigates.",700,700},
  {"EMP Missle",14,"Reduce enemy fleet  ships during        intercept missions.",140,140}
};

EnemyGarrison Enemy1Garrison[] = {
  {-1,0,0,0,0,0,0}, //Capital
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0}
};

EnemyGarrison Enemy2Garrison[] = {
  {-1,0,0,0,0,0,0}, //Capital
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0},
  {-1,0,0,0,0,0,0}
};

Fleet PlayerFleets[] = {
  {0,false,0,0,0,0,0,0,0,0,0,0,0,0,0,"",true,0},
  {0,false,0,0,0,0,0,0,0,0,0,0,0,0,0,"",true,0},
  {0,false,0,0,0,0,0,0,0,0,0,0,0,0,0,"",true,0},
  {0,false,0,0,0,0,0,0,0,0,0,0,0,0,0,"",true,0}
};

Fleet EnemyFleets[] = {
  {4,false,0,0,0,0,0,0,0,0,0,0,0,0,0,"",false,0},
  {4,false,0,0,0,0,0,0,0,0,0,0,0,0,0,"",false,0},
  {4,false,0,0,0,0,0,0,0,0,0,0,0,0,0,"",false,0},
  {4,false,0,0,0,0,0,0,0,0,0,0,0,0,0,"",false,0}
};

int PlayerShips[] = {
  0, //Fighter
  0, //Interceptor
  0, //Frigate
  0, //War Cruiser
  0, //Star Dreadnought
  0, //Solar Destructor
  0, //Spy Bot
  0, //Colonizer
  0, //Metal Transport
  0, //Crystal Transport
  0, //Fuel Transport
  0, //Stalkers
  0, //Leviatans
  0 //EMP Missles
};

TradeRoute PlayerRoutes[] = {
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0},
  {false,"",0,0,0}
};

Report IntelligenceReports[] = {
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0},
  {"Empty",0,0,0,0,0,0,0,0,0,0}
};

int PlayerResources[] = {0,0,0};

int ScoreBoard[] = {0,0,0,0,0};

const SaveDefault savefileDefaults[] = {
  { 0, SAVETYPE_BLOB,{.ptr="1123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-11101123411-1110 "} ,349},
  { 1, SAVETYPE_BLOB,{.ptr="0101021001010101010101010101011101010125 "},81},
  { 2, SAVETYPE_BLOB,{.ptr="020313000000000000000000000000000000000000000000000000000000000000000000000000000000121120 "},91},
  { 3, SAVETYPE_BLOB,{.ptr="-10100200043510025000103330000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 "},157}, //Enemy1 Garrison
  { 4, SAVETYPE_BLOB,{.ptr="000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 "},157}, //Enemy2 Garrison
  { 5, SAVETYPE_BLOB,{.ptr="000000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000000NAME**********00 "},257}, //Player Fleets
  { 6, SAVETYPE_BLOB,{.ptr="000000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000000NAME**********00000000000000000000000000000000000000000000000000NAME**********00 "},257}, //Enemy Fleets
  { 7, SAVETYPE_BLOB,{.ptr="00000000000000000000000000000000000000000000000000000000 "},57},
  { 8, SAVETYPE_BLOB,{.ptr="0NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********0000NAME**********000 "},217},
  { 9, SAVETYPE_BLOB,{.ptr="NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000NAME**********0000000000000000000000000000 "},337},
  { 10, SAVETYPE_BLOB,{.ptr="00000000000000000NORMAL********00000000000000000 "},49},
  { 11, SAVETYPE_INT,0,0 },
  { 12, SAVETYPE_INT,0,0 },
  { 13, SAVETYPE_INT,0,0 },
  { 14, SAVETYPE_INT,0,0 },
  { 15, SAVETYPE_INT,0,0 },
  { 16, SAVETYPE_INT,0,0 } //Check if save exist
};
