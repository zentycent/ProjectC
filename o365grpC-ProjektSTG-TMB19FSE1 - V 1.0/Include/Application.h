/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Application.h																*/
/*																										*/
/*	Content:			Base for this project!													*/
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

// Was here before? If not, define the H-flag for further calls and add the
// contents of the file to the actual project! Under WINDOWS, one can use
// #pragma once
   #ifndef _APPLICATION_DEF_H_																//
   #define _APPLICATION_DEF_H_																//

//	All needed WINDOWS defines
	#include <Windows.h>																			//	includes 'WinBase.h'
	#include <Graphics\V 1.1\Graphics V 1.1.h>											// Little graphic packet

//	Main standard includes for this project
	#include <ctype.h>																			// toupper, ...
	#include <conio.h>																			// kbhit, ...
	#include <math.h>																				// ceil, ...
	#include <stdio.h>																			//
	#include <tchar.h>																			//
	#include <time.h>																				//
	#include <assert.h>																			//
	#include <strsafe.h>																			//

//	Nice to have ...
	#include <Generic\V 1.0\Generic V 1.0.h>												//
	#include <TypeDEF\V 1.0\TypeDEF V 1.0.h>												//
	#include <Timer And Time\V 1.0\Timer And Time V 1.0.h>							//

//	Base handlers
	#include <Application Handler\Base\V 1.0\Base Application Handler V 1.0.h>	//
	#include <Timer Handler\Base\V 1.0\Base Timer Handler V 1.0.h>					//
	#include <Input Handler\Base\V 1.0\Base Input Handler V 1.0.h>					//

//	Space Invaders handlers
	#include <Application Handler\Space Invaders\V 1.0\Space Invaders Application Handler V 1.0.h>	//
	#include <Timer Handler\Space Invaders\V 1.0\Space Invaders Timer Handler V 1.0.h>					//
	#include <Input Handler\Space Invaders\V 1.0\Space Invaders Input Handler V 1.0.h>					//

//	The Game!
	#include <Space Invaders V 1.0.h>														// THIS !
	#include <Space Invaders\V 1.0\Space Invaders Graphics V 1.0.h>				// Graphic packet for Space Invaders
	#include <User Utilities V 1.0.h>														//

// ****************************************************************************
//
//                             APPLICATION DEFINES
//
// ****************************************************************************

	#define facultyMAX_VALUE						20											// Needed by Generic V 1.0.h/c (Faculty function)
	#define cGENERAL_PURPOSE_BUFFER_LENGTH		1024										// 1024 bytes for all

//	Main Space Invaders state machine
//	ToDo: Insert your states here!
	typedef enum tagENUM_SI_STATE_MACHINE													//
		{																								//
		sismUNKNOWN,																				//
		sismIDLE,																					// Nothing to switch to (if used with enNextState!)
		sismINIT,																					// Just after programm start
		sismSTOPP,																					// After main initialization and after SWITCH_TO_STOPP
		sismSWITCH_TO_RUN,																		//	Initialize Space Invaders and switch to run
//		ToDo: This is the main job!
		sismINIT_GRAPHICS,																		//
		sismRUNNING,																				//	Think open minded!
//		sismSHIP_DESTROYED,																		//
//		...,																							//
//		...,																							//

//		
		sismSWITCH_TO_STOPP																		// Deinitialize Space Invaders and stop
		} enumSI_STATE_MACHINE;																	//

//	Space Invaders game sub state machine
	typedef enum tagENUM_SIG_SUB_STATE_MACHINE											//
		{																								//
		sisubsmUNKNOWN,																			//
		sisubsmIDLE,																				//
//		Known sub states
		sisubsmKNOWN_SUB_STATES																	//
		} enumSIG_SUB_STATE_MACHINE;															//

//	The main 'Space Invaders' struct
	typedef struct tagSTRUCT_SI																//
		{																								//
//		Space Invaders
		enumSI_STATE_MACHINE smState;															//
//		Next state
		enumSI_STATE_MACHINE enNextState;													//
//		Delay for the next state
		unsigned short usStateDelay;															//
//		Sequencer Delay
		unsigned short usSequencerDelayReload;												//
		unsigned short usSequencerDelay;														//
//		Sub state
		enumSIG_SUB_STATE_MACHINE smSubState;												//

//		Game characters
		typeBLOCK_GRAPHIC_IMAGE* ptEddi;														//
		typeBLOCK_GRAPHIC_IMAGE* ptMcFly;													//
		typeBLOCK_GRAPHIC_IMAGE* ptDocBrown;												//

		} typeSI;																					//

// ############################# APPLICATION DEFINES ##########################


// ****************************************************************************
//
//                             THE MAIN APPLICATION
//
// ****************************************************************************

//	THE struct
	typedef struct tagTYPE_APPLICATION														//
		{																								//
//		Whores
		unsigned char pucBuffer[cGENERAL_PURPOSE_BUFFER_LENGTH];						//	One for all!
		unsigned char ucIndex;																	//
		unsigned short usIndex;																	//

//		char** argument list as an array of void**
		void** pvArgs;																				//
		char cLastInputCharacter;																//

//		Allegro character
		int iLastInputCharacter;																//

//		Nice to have! Add more variables for everybodies use! Handle with care!
//		...

//		The main struct
		typeSI tSI;																					// The Space Invaders struct
		COORD tXYInput;																			// Actual I/O cursor position!

//		Mini Timer
		typeMT_LINK_STRUCT tMTLink;															//

//		Changeable callbacks
		void (*fTimerHandler)(void);															//
		void (*fInputHandler)(void);															//
		void (*fApplicationHandler)(void);													//

//		MUST have
		enumAPPLICATION_STATES enState;														//
		int iError;																					//
		} typeAPPLICATION;																		//

//	External reference. Can be used by any module
	bool ApplicationInit(void);																//

//	Link to the Mini Timer
	void SetAppState(enumAPPLICATION_STATES enState);									//
	enumAPPLICATION_STATES GetAppState(void);												//

//	This is very dangerous, but effective for µC programming with less resources!
	extern typeAPPLICATION tApp;																//

//	Done
	#endif // APPLICATION
