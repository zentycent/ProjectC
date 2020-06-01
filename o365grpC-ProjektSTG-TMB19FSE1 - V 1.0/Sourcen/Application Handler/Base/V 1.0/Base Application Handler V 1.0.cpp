/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Base Application Handler V 1.0.cpp									*/
/*																										*/
/*	Content:			Base application handler												*/
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
//	void BaseApplicationHandler(void)
//
void BaseApplicationHandler(void)															//
{																										//
//	Internal variables

// Main state machine
	if ( tApp.tSI.enNextState == sismIDLE ) { return; }								//

//	New state is requested! Clear the sequencer and the state delays
	tApp.tSI.usSequencerDelayReload = 0;													//
	tApp.tSI.usStateDelay = 0;																	//

//	What to do ?
	switch( tApp.tSI.enNextState )															//
		{
//		Initialization
		case sismINIT:																				//
//			ToDO: Initialization code ...
//			...

//			Done! Switch to STOPP
			tApp.tSI.enNextState = sismSTOPP;												//
			break;																					//

//		Switch to RUN
		case sismSWITCH_TO_RUN:																	//
//			ToDo: Check if RUN is possible!
//			...

//			Set the substate to UNKNOWN! Update this for your project!
			tApp.tSI.smSubState = sisubsmUNKNOWN;											//

//			Sequencer delay ~ 0.01 second
			tApp.tSI.usSequencerDelayReload = 1;											//
//			Info to user
			printf("User requests a RUN\r\n");												//

			SIGSetHeaderText("Space ...");

//			Activate the Space Invaders handlers
			tApp.fApplicationHandler = SpaceInvadersApplicationHandler;				//
			tApp.fInputHandler = SpaceInvadersInputHandler;								//
			break;

//		NEVER
		default:																						//
			break;																					//
		} // switch

//		Update the sequencer delay
		tApp.tSI.usSequencerDelay = tApp.tSI.usSequencerDelayReload;				//
//		Switch to the requested state
		tApp.tSI.smState = tApp.tSI.enNextState;											//
		tApp.tSI.enNextState = sismIDLE;														//

//	Done
} // BaseApplicationHandler
