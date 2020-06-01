/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Space Invaders V 1.0.cpp												*/
/*																										*/
/*	Content:			main(...)																	*/
/*																										*/
/*	Hint:				As a convention, all places marked "####" are to be treated	*/
/*						as UNDER CONSTRUCTION or there are KNOWN ERRORS around!		*/
/*						...																			*/
/*																										*/
/*	Author:			YouB																			*/
/*	Copyright:		© 2020 YouB																	*/
/*																										*/
/*	Revisions:																						*/
/*	1.00				30.01.2020 Initial phase												*/
/*																										*/
/* All Rights Reserved.																			*/
/* No part of this code or any of its contents may be reproduced, copied,		*/
/*	modified or adapted, without the prior written consent of the author,		*/
/*	unless otherwise indicated for stand-alone materials.								*/
/*																										*/
/******************************************************************************/

// Needed includes
	#include "stdafx.h"																			//

//	This is the last function called by this main()
	static int OnExit(void);																	//

//	This struct can be used from EVERY module! Be sure to know what you are
//	doing while accessing the struct!
	typeAPPLICATION tApp;																		//

//	As Mr. Ritchie defined it => int main(char argc, void* argv[])
//	Here we go again ...
	int _tmain(int argc, _TCHAR* argv[])													//
//	int main(int argc, _TCHAR* argv[])														//
{																										//
//	Internal variables
	int iArgs;																						//

//	Convert the input parameters from _TCHAR*[] to void*[] (type char!)
//	Back to caller, if the conversion failed!
	tApp.pvArgs = ConvertWideCharArguments(argc, argv);								//
	if ( !tApp.pvArgs )	{ return ERROR_OUTOFMEMORY; }									//

//	Just to have fun ...!
//	Start with the real argument(s), jump over the file name!
	for( iArgs = 1; iArgs < argc; iArgs++ )												//
		{																								//
//		Convert to upper case
		BufferToUpper((unsigned char*)tApp.pvArgs[iArgs]);								//
//		Inform the user ...
		printf("Parameter %3d: %s\r\n", iArgs+1, (char*)tApp.pvArgs[iArgs]);		//
		}																								//

//	If you want to have input from the console, process those parameters here
//	First argument after the file name! Start with index 1!!!!!
// if ( strcmp(tApp.pvArg[1], "???") == 0 )												//
// ...
// ...
//	Second argument after the file name has index 2
// if ( strcmp(tApp.pvArg[2], "???") == 0 )												//
// ...
// ...

//	Next, initialize the application
// tApp.enAppState will be set to get an idea of the application state.
//	If needed, tApp.iError will be set to an error code.
	if ( !ApplicationInit() ) { return OnExit(); }										//

//	Inform the user about this application
	UserInfo();																						//

//	Just produce heat ...
	while ( tApp.enState == appstateRUN )													//
		{																								//
//		Handle the timer requests
		tApp.fTimerHandler();																	//
//		Handle the input characters
		tApp.fInputHandler();																	//
//		Handle the standard application
		tApp.fApplicationHandler();															//
//		Release this thread for a little time!
//		If you don't release this thread, at least one CPU will be blocked by it!
//		This will give a 100% CPU processor load at older systems
		Sleep(1);																					//
		}																								//

// Done! Back to Mr. Gates
	return OnExit();																				//
}																										//

//
//	int OnExit
//
static int OnExit(void)																			//
{
//	Internal variables
//	Done
	return tApp.iError;																			//
} // OnExit
