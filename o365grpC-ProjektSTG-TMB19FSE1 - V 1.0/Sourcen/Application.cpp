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

// Needed includes
	#include "stdafx.h"																			//

//
//	Initialize the system / application. Set the tApp.enState as required.
//
#pragma warning( disable : 26812 )
bool ApplicationInit(void)																		//
{																										//
// Internal variables
//	...

//	Start the initialization. tApp.enState can be used to inform any driver
// about the application state
	tApp.enState = appstateINIT;																//

//	Initialize the block graphic driver!
//	To have a real center point, both coordinates are expanded to the next odd value.
//	Therefore, the last block row (Y-coordinate) is omitted automatically because
//	each character line has 2 blocks. Off: ' ', Upper: '▀', Lower: '▄', Both: '█'
//	Sample     : 10 x 10      Sample:      10 x 11
//	Expanded to: 11 x 11      Expandet to: 11 x 11
//	=> 6 character lines      => 6 character lines
//   0 1 2 3 4 5 6 7 8 9 10
// 0 . . . . . . . . . . .  }
// 1 . . . . . . . . . . .  } Character Line 0
// 2 . . . . . . . . . . .  }
// 3 . . . . . . . . . . .  } 1
// 4 . . . . . . . . . . .  }
// 5 . . . . . + . . . . .  } 2
// 6 . . . . . . . . . . .  }
// 7 . . . . . . . . . . .  } 3
// 8 . . . . . . . . . . .  }
// 9 . . . . . . . . . . .  } 4
//10 . . . . . . . . . . .  }
//11 x x x x x x x x x x x  } 5

//	Smallest values are: 64, 24
	if ( !BlockGraphicInit(L"8514oem", enumBG_ORIGINS::bgoriginCENTER, 132, 64) )	//
		{ return false; }																				//
	SIGSetHeaderText("Space Invaders V 1.0");												//

//	Create 'Eddi'
	tApp.tSI.ptEddi = SIGCreateCreature( enumSPACE_INVADERS_CREATURES::sicEDDI,	//
													 2 + 8);												//
	tApp.tSI.ptMcFly = SIGCreateCreature( enumSPACE_INVADERS_CREATURES::sicMCFLY,	//
													  6 + 8);											//
	tApp.tSI.ptDocBrown = SIGCreateCreature( enumSPACE_INVADERS_CREATURES::sicDOC_BROWN,	//
														  4 + 8);													//

//	Just to have it
	tApp.tXYInput.X = 0;																			//
	tApp.tXYInput.Y = 40;																		// 

//	Use the default handlers till user switches to Space Invaders
	tApp.fTimerHandler = BaseTimerHandler;													//
	tApp.fInputHandler = BaseInputHandler;													//
	tApp.fApplicationHandler = BaseApplicationHandler;									//

//	Prepare the Space Invaders main struct ...
	tApp.tSI.smState = sismUNKNOWN;															//
	tApp.tSI.enNextState = sismINIT;															//
	tApp.tSI.smSubState = sisubsmUNKNOWN;													//
	tApp.tSI.usSequencerDelayReload = 0;													//
	tApp.tSI.usSequencerDelay = 0;															//
	tApp.tSI.usStateDelay = 0;																	//

//	Think negative! Normally, during the initialization process, memory errors
// may occur most!	
	tApp.iError = ERROR_OUTOFMEMORY;															//

//	Initialize more of your components ...

//	System is up and running ...
	tApp.enState = appstateRUN;																//
	tApp.iError = ERROR_SUCCESS;																//

// Initialize the mini timer at the end of this module! The MiniTimer callback
// will update the tApp.enState if something went wrong!

//	Initiaize the mini timer link struct
	tApp.tMTLink.fGetAppState = GetAppState;												//
	tApp.tMTLink.fSetAppState = SetAppState;												//
	tApp.tMTLink.usTimeOut = 10;																//
//	Do it!
	if ( MiniTimerInit( &tApp.tMTLink ) )													// Return 0 if everything is OK!
		{ return false; }																			// Should never happen!

//	Done
	return true;																					//
} // ApplicationInit

//
//	void SetAppState(enumAPPLICATION_STATES enState)
//
void SetAppState(enumAPPLICATION_STATES enState)										//
{																										//
//	Done
	tApp.enState = enState;																		//
} // SetAppState

//
//	enumAPPLICATION_STATES GetAppState(void)
//
enumAPPLICATION_STATES GetAppState(void)													//
{																										//
//	Done
	return tApp.enState;																			//
} // GetAppState

