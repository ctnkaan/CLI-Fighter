#include <stdio.h>
#include <windows.h>
#include <time.h>

//globals
int playerHP;
int PlayerSTR;
int PlayerSTM;
int PlayerAGL;
int playerAbility;
int playerDodgeGlobal = 0;

int cpuHP;
int cpuSTR;
int cpuSTM;
int cpuAGL;
int cpuDodgeGlobal = 0;

//-----------------------------FUNCTIONS----------------------------------------

int player_select(int player) {
  switch (player) {
    case 1: printf(" You have selected Pontiff Kuzheym\n");
    PlayerSTR = 8;
    PlayerSTM = 9;
    PlayerAGL = 4;
    break;
    case 2: printf(" You have selected Slave Knight Sadik\n");
    PlayerSTR = 6;
    PlayerSTM = 8;
    PlayerAGL = 5;
    break;
    case 3: printf(" You have selected Darkeater Eyup\n");
    PlayerSTR = 4;
    PlayerSTM = 8;
    PlayerAGL = 6;
    break;
    case 4: printf(" You have selected Ata, Devourer of Gods\n");
    PlayerSTR = 5;
    PlayerSTM = 10;
    PlayerAGL = 5;
    break;
    default: printf(" There was a error\n");
    return 0;
  }
}

int cpu_select(int cpu) {
  switch (cpu) {
    case 1: printf(" Your oppponent is Pontiff Kuzheym\n");
    cpuSTR = 8;
    cpuSTM = 9;
    cpuAGL = 4;
    break;
    case 2: printf(" Your opponent is Slave Knight Sadik\n");
    cpuSTR = 6;
    cpuSTM = 8;
    cpuAGL = 5;
    break;
    case 3: printf(" Your opponent is Darkeater Eyup\n");
    cpuSTR = 4;
    cpuSTM = 8;
    cpuAGL = 6;
    break;
    case 4: printf(" Your opponent is Ata, Devourer of Gods\n");
    cpuSTR = 5;
    cpuSTM = 10;
    cpuAGL = 5;
    break;
    default: printf( "There was a error\n");
    return 0;
  }
}

int PlayerAbilityFunction(int playerAbility) {
  srand(time(NULL));
  int functionIntegar;
  int playerParry = rand() % 20 + 1;
  int cpuParry = rand() % 20 + 1;
  int playerParryHolder;
  int cpuParryHolder;

  switch (playerAbility) {
    case 1: functionIntegar = PlayerSTR * 0.75 * 6;
    printf(" You deal %d damage\n\n", functionIntegar);
    cpuHP = cpuHP - functionIntegar;
    break;
    case 2: functionIntegar = PlayerAGL * 0.75 * 6;
    cpuHP = cpuHP - functionIntegar;
    printf(" You deal %d damage\n\n", functionIntegar);
    break;
    case 3:
    playerDodgeFunction();
    playerParryHolder = (PlayerSTR * 10) + (playerParry * 10);
    cpuParryHolder = (cpuSTR * 10) + (cpuParry * 10);
    functionIntegar = playerParryHolder - cpuParryHolder;

    if (playerParryHolder > cpuParryHolder && playerDodgeGlobal == 1) {
      printf(" You Parried the attack\n");
      playerDodgeGlobal = 0;
      cpuHP = cpuHP - 80;
      printf(" CRITICAL HIT ! 80 DMG \n\n");
    } else {
      printf(" You failed to parry the attack\n\n");
      playerDodgeGlobal = 0;
    }
    break;
  }
}

int playerDodgeFunction() {
  srand(time(NULL));
  int randomPlayerDodge = rand() % 15 + 1;
  randomPlayerDodge = randomPlayerDodge * 10;

  int randomCpuDodge = rand() % 15 + 1;
  randomCpuDodge = randomCpuDodge * 10;

  int playerDodge = PlayerAGL * 10 + randomPlayerDodge;
  int cpuDodge = cpuAGL * 10 + randomCpuDodge;

  int sum = playerDodge - cpuDodge;

  if (sum >= 0) {
    printf(" You dodged the attack\n\n");
    playerDodgeGlobal = 1;
  }else {
    printf(" You failed to dodge the attack\n");
    playerDodgeGlobal = 0;
}
}

int cpuAbilityFunction(int cpuAbility) {
  srand(time(NULL));
  int functionIntegar;
  int playerParry = rand() % 20 + 1;
  int cpuParry = rand() % 20 + 1;
  int playerParryHolder;
  int cpuParryHolder;

  switch (cpuAbility) {
    case 1: functionIntegar = cpuSTR * 0.75 * 6;
    printf(" Enemy uses Heavy Attack\n");
    printf(" Enemy deals %d damage\n\n", functionIntegar);
    playerHP = playerHP - functionIntegar;
    break;
    case 2: functionIntegar = cpuAGL * 0.75 * 6;
    playerHP = playerHP - functionIntegar;
    printf(" Enemy uses Fast Attack\n");
    printf(" Enemy deals %d damage\n\n", functionIntegar);
    break;
    case 3:
    printf(" Enemy tires to parry you\n");
    cpuDodgeFunction();
    playerParryHolder = (PlayerSTR * 10) + (playerParry * 10);
    cpuParryHolder = (cpuSTR * 10) + (cpuParry * 10);
    functionIntegar = cpuParryHolder - playerParryHolder;

    if (cpuParryHolder > playerParryHolder && cpuDodgeGlobal == 1) {
      printf(" Enemy Parried your attack\n");
      playerDodgeGlobal = 0;
      playerHP = playerHP - 100;
      printf(" CRITICAL HIT ! 80 DMG \n\n");
    } else {
      printf(" Enemy failed to parry your attack\n\n");
      playerDodgeGlobal = 0;
    }
    break;
  }
}

int cpuDodgeFunction() {
  srand(time(NULL));
  int randomPlayerDodge = rand() % 12 + 1;
  randomPlayerDodge = randomPlayerDodge * 10;

  int randomCpuDodge = rand() % 12 + 1;
  randomCpuDodge = randomCpuDodge * 10;

  int playerDodge = PlayerAGL * 10 + randomPlayerDodge;
  int cpuDodge = cpuAGL * 10 + randomCpuDodge;

  int sum = cpuDodge - playerDodge;

  if (sum >= 0) {
    printf(" Enemy dodged your attack\n\n");
    cpuDodgeGlobal = 1;
  }else {
    printf(" Enemy failed to dodge your attack\n");
    cpuDodgeGlobal = 0;
}
}

//--------------------------------MAIN------------------------------------------

int main() {
  srand(time(NULL));
  int player;
  int cpu;
  int countdown = 3;
  int cpuAbility = rand() % 3 + 1;
  int player_win = 0;
  int cpu_win = 0;

  printf(" SELECT YOUR FIGHTER\n\n");

  printf(" 1) Pontiff Kuzheym          STR 8/10   STM 9/10   AGL 4/10\n\n");
  printf(" 2) Slave Knight Sadik       STR 6/10   STM 8/10   AGL 5/10\n\n");
  printf(" 3) Darkeater Eyup           STR 4/10   STM 8/10   AGL 6/10\n\n");
  printf(" 4) Ata, Devourer of Gods    STR 5/10   STM 10/10  AGL 5/10\n\n");
  scanf("%d", &player);

  player_select(player);

  system("pause");
  system("cls");

  printf(" SELECT YOUR OPPONENT\n\n");

  printf(" 1) Pontiff Kuzheym          STR 8/10   STM 9/10   AGL 5/10\n\n");
  printf(" 2) Slave Knight Sadik       STR 6/10   STM 8/10   AGL 6/10\n\n");
  printf(" 3) Darkeater Eyup           STR 5/10   STM 7/10   AGL 7/10\n\n");
  printf(" 4) Ata, Devourer of Gods    STR 5/10   STM 10/10  AGL 5/10\n\n");
  scanf("%d", &cpu);

  cpu_select(cpu);

  system("pause");
  system("cls");

  playerHP = PlayerSTM * 15;
  cpuHP = cpuSTM * 15;

  while (countdown != 0)
  {
      printf(" ROUND 1 WILL BEGIN IN\n");
      printf("          %d\n", countdown);
      Sleep(1200);
      countdown--;
      system("cls");
  }
  printf("      FIGHT");
  Sleep(1800);
  system("cls");
  system("start RoundOne.mp3");

  while (playerHP > 0 && cpuHP > 0) {
    int cpuAbility = rand() % 3 + 1;
    printf(" Your Turn     Player: %d   CPU: %d\n\n", player_win, cpu_win);

    if (cpu == 1) {
      printf(" Opponent : Pontiff Kuzheym\n");
    }else if (cpu == 2) {
      printf(" Opponent : Slave Knight Sadik\n");
    }else if (cpu == 3) {
      printf(" Opponent : Darkeater Eyup\n");
    }else {
      printf(" Opponent : Ata, Devourer of Gods\n");
    }

    printf(" HP = %d   STR = %d   STM = %d   AGL = %d\n\n", cpuHP, cpuSTR, cpuSTM, cpuAGL );

    if (player == 1) {
      printf(" You : Pontiff Kuzheym\n");
    }else if (player == 2) {
      printf(" You : Slave Knight Sadik\n");
    }else if (player == 3) {
      printf(" You : Darkeater Eyup\n");
    }else {
      printf(" You : Ata, Devourer of Gods\n");
    }

    printf(" HP = %d   STR = %d   STM = %d   AGL = %d\n\n", playerHP, PlayerSTR, PlayerSTM, PlayerAGL);
    printf(" 1) Heavy Attack\n");
    printf(" 2) Fast Attack\n");
    printf(" 3) Parry\n >>> ");
    scanf("%d", &playerAbility);

    cpuDodgeFunction();

    if (cpuDodgeGlobal == 0) {
      PlayerAbilityFunction(playerAbility);
    }
    if (playerHP <= 0 || cpuHP <= 0) {
      break;
    }
  system("pause");
  system("cls");

  playerDodgeFunction();

  if (playerDodgeGlobal == 0) {
    cpuAbilityFunction(cpuAbility);
  }
  if (playerHP <= 0 || cpuHP <= 0) {
    break;
  }
}

//control
if (cpuHP <= 0) {
  player_win++;
}else {
  cpu_win++;
}

if (player_win == 2) {
  printf("Player Wins !\n");
  system("pause");
  return 0;
} else if (cpu_win == 2) {
  printf("The CPU Wins !\n");
  system("pause");
  return 0;
}

system("pause");

//restart
playerHP = PlayerSTM * 15;
cpuHP = cpuSTM * 15;

countdown = 3;

while (countdown != 0)
{
    printf(" ROUND 2 WILL BEGIN IN\n");
    printf("          %d\n", countdown);
    Sleep(1200);
    countdown--;
    system("cls");
}
printf("      FIGHT");
Sleep(1800);
system("cls");

system("start RoundTwo.mp3");

while (playerHP > 0 && cpuHP > 0) {
  int cpuAbility = rand() % 3 + 1;
  playerDodgeFunction();

  if (playerDodgeGlobal == 0) {
    cpuAbilityFunction(cpuAbility);
  }

  if (playerHP <= 0 || cpuHP <= 0) {
    break;
  }

  printf(" Your Turn     Player: %d   CPU: %d\n\n", player_win, cpu_win);

  if (cpu == 1) {
    printf(" Opponent : Pontiff Kuzheym\n");
  }else if (cpu == 2) {
    printf(" Opponent : Slave Knight Sadik\n");
  }else if (cpu == 3) {
    printf(" Opponent : Darkeater Eyup\n");
  }else {
    printf(" Opponent : Ata, Devourer of Gods\n");
  }

  printf(" HP = %d   STR = %d   STM = %d   AGL = %d\n\n", cpuHP, cpuSTR, cpuSTM, cpuAGL );

  if (player == 1) {
    printf(" You : Pontiff Kuzheym\n");
  }else if (player == 2) {
    printf(" You : Slave Knight Sadik\n");
  }else if (player == 3) {
    printf(" You : Darkeater Eyup\n");
  }else {
    printf(" You : Ata, Devourer of Gods\n");
  }

  printf(" HP = %d   STR = %d   STM = %d   AGL = %d\n\n", playerHP, PlayerSTR, PlayerSTM, PlayerAGL);
  printf(" 1) Heavy Attack\n");
  printf(" 2) Fast Attack\n");
  printf(" 3) Parry\n >>> ");
  scanf("%d", &playerAbility);

  cpuDodgeFunction();

  if (cpuDodgeGlobal == 0) {
    PlayerAbilityFunction(playerAbility);
  }

  if (playerHP <= 0 || cpuHP <= 0) {
    break;
  }

  system("pause");
  system("cls");
}

//control
if (cpuHP <= 0) {
  player_win++;
}else {
  cpu_win++;
}

if (player_win == 2) {
  printf("\n Player Wins !\n");
  system("pause");
  return 0;
} else if (cpu_win == 2) {
  printf("\n The CPU Wins !\n");
  system("pause");
  return 0;
}

system("pause");

//restart
playerHP = PlayerSTM * 15;
cpuHP = cpuSTM * 15;

countdown = 3;

while (countdown != 0)
{
    printf(" ROUND 3 WILL BEGIN IN\n");
    printf("          %d\n", countdown);
    Sleep(1200);
    countdown--;
    system("cls");
}
printf("      FIGHT");
Sleep(1800);
system("cls");
system("start RoundThree.mp3");

while (playerHP > 0 && cpuHP > 0) {
  int cpuAbility = rand() % 3 + 1;
  printf(" Your Turn     Player: %d   CPU: %d\n\n", player_win, cpu_win);

  if (cpu == 1) {
    printf(" Opponent : Pontiff Kuzheym\n");
  }else if (cpu == 2) {
    printf(" Opponent : Slave Knight Sadik\n");
  }else if (cpu == 3) {
    printf(" Opponent : Darkeater Eyup\n");
  }else {
    printf(" Opponent : Ata, Devourer of Gods\n");
  }

  printf(" HP = %d   STR = %d   STM = %d   AGL = %d\n\n", cpuHP, cpuSTR, cpuSTM, cpuAGL );

  if (player == 1) {
    printf(" You : Pontiff Kuzheym\n");
  }else if (player == 2) {
    printf(" You : Slave Knight Sadik\n");
  }else if (player == 3) {
    printf(" You : Darkeater Eyup\n");
  }else {
    printf(" You : Ata, Devourer of Gods\n");
  }

  printf(" HP = %d   STR = %d   STM = %d   AGL = %d\n\n", playerHP, PlayerSTR, PlayerSTM, PlayerAGL);
  printf(" 1) Heavy Attack\n");
  printf(" 2) Fast Attack\n");
  printf(" 3) Parry\n >>> ");
  scanf("%d", &playerAbility);

  cpuDodgeFunction();

  if (cpuDodgeGlobal == 0) {
    PlayerAbilityFunction(playerAbility);
  }

  if (playerHP <= 0 || cpuHP <= 0) {
    break;
  }

system("pause");
system("cls");
playerDodgeFunction();

if (playerDodgeGlobal == 0) {
  cpuAbilityFunction(cpuAbility);
}
if (playerHP <= 0 || cpuHP <= 0) {
  break;
}
}

if (cpuHP <= 0) {
  player_win++;
}else {
  cpu_win++;
}

if (player_win == 2) {
  printf(" \nPlayer Wins !\n");
  system("pause");
  return 0;
} else if (cpu_win == 2) {
  printf(" \nThe CPU Wins !\n");
  system("pause");
  return 0;
}

  return 0;
}
