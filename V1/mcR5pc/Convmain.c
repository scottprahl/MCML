/****************************************************************
 *	Convolution program for Monte Carlo simulation of photon
 *	distribution in multilayered turbid media.
 *
 ****/

#include "conv.h"

#define EPS 0.1			/* default relative error in convolution. */

void ReadMcoFile(InputStruct *, OutStruct *);
void OutputOrigData(InputStruct *, OutStruct *);
void OutputConvData(InputStruct *, OutStruct *);
void ContourOrigData(InputStruct *, OutStruct *);
void ContourConvData(InputStruct *, OutStruct *);
void ScanOrigData(InputStruct *, OutStruct *);
void ScanConvData(InputStruct *, OutStruct *);
void LaserBeam(BeamStruct *, OutStruct *);
void ConvResolution(InputStruct *, OutStruct *);
void ConvError(InputStruct *, OutStruct *);
void FreeOrigData(InputStruct * In_Ptr, OutStruct * Out_Ptr);
void FreeConvData(InputStruct * In_Ptr, OutStruct * Out_Ptr);
void ShowVersion(void);
/****************************************************************
 ****/
void 
ShowMainMenu()
{
  puts("i  = Input filename of mcml output");
  puts("b  = specify laser Beam");
  puts("r  = convolution Resolution. ");
  puts("e  = convolution Error. ");
  puts("oo = Output Original data");
  puts("oc = Output Convolved data");
  puts("co = Contour output of Original data");
  puts("cc = Contour output of Convolved data");
  puts("so = Scanning output of Original data");
  puts("sc = Scanning output of Convolved data");
  puts("q  = Quit");
  puts("* Commands in conv are not case-sensitive");
}

/****************************************************************
 ****/
void 
QuitProgram(InputStruct * In_Ptr, OutStruct * Out_Ptr)
{
  char        ch, cmd_str[STRLEN];

  printf("Do you really want to quit conv (y/n): ");
  scanf("%s", cmd_str);
  sscanf(cmd_str, "%c", &ch);
  if (toupper(ch) == 'Y') {	/* really quit. */
    if (Out_Ptr->allocated) {
      FreeOrigData(In_Ptr, Out_Ptr);
      FreeConvData(In_Ptr, Out_Ptr);
    }
    exit(0);
  }
}

/****************************************************************
 ****/
void 
BranchMainCmd1(char *Cmd,	/* Cmd is command char. */
	       InputStruct * In_Ptr, OutStruct * Out_Ptr)
{
  switch (toupper(Cmd[0])) {
    case 'I':ReadMcoFile(In_Ptr, Out_Ptr);
    break;
  case 'B':
    LaserBeam(&In_Ptr->beam, Out_Ptr);
    break;
  case 'R':
    ConvResolution(In_Ptr, Out_Ptr);
    break;
  case 'E':
    ConvError(In_Ptr, Out_Ptr);
    break;
  case 'H':
    ShowMainMenu();
    break;
  case 'Q':
    QuitProgram(In_Ptr, Out_Ptr);
    break;
  default:
    puts("...Wrong command");
  }
}

/****************************************************************
 ****/
void 
BranchMainCmd2(char *Cmd,	/* Cmd is command char. */
	       InputStruct * In_Ptr, OutStruct * Out_Ptr)
{
  switch (toupper(Cmd[0])) {
    case 'O':
    if (toupper(Cmd[1]) == 'O')
      OutputOrigData(In_Ptr, Out_Ptr);
    else if (toupper(Cmd[1]) == 'C')
      OutputConvData(In_Ptr, Out_Ptr);
    break;
  case 'C':
    if (toupper(Cmd[1]) == 'O')
      ContourOrigData(In_Ptr, Out_Ptr);
    else if (toupper(Cmd[1]) == 'C')
      ContourConvData(In_Ptr, Out_Ptr);
    break;
  case 'S':
    if (toupper(Cmd[1]) == 'O')
      ScanOrigData(In_Ptr, Out_Ptr);
    else if (toupper(Cmd[1]) == 'C')
      ScanConvData(In_Ptr, Out_Ptr);
    break;
  default:
    puts("...Wrong command");
  }
}

/****************************************************************
 ****/
void 
BranchMainCmd(char *Cmd)
{				/* Cmd is command char. */
  static InputStruct in_parm;
  static OutStruct out_parm = NULLOUTSTRUCT;
  static char first_time = 1;	/* used to initialize. */

  if (first_time) {
    in_parm.eps = EPS;
    first_time = 0;
  }
  if (strlen(Cmd) == 1)
    BranchMainCmd1(Cmd, &in_parm, &out_parm);
  else if (strlen(Cmd) == 2)
    BranchMainCmd2(Cmd, &in_parm, &out_parm);
  else
    puts("...Wrong command");
}

/****************************************************************
 ****/
int 
main(void)
{
  char        cmd_str[STRLEN];

  ShowVersion();
  do {
    printf("\n> Main menu (h for help) => ");
    scanf("%s", cmd_str);
    BranchMainCmd(cmd_str);
  } while (1);
}
