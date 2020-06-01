/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Space Invaders Application Handler V 1.0.cpp						*/
/*																										*/
/*	Content:			Space Invaders application handler, active during gaming		*/
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
//	void SpaceInvadersApplicationHandler(void)
//
void SpaceInvadersApplicationHandler(void)												//
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
//		ToDo: Here you can play ...
		case sismRUNNING:																			//
			break;																					//

//		Switch to STOPP
		case sismSWITCH_TO_STOPP:																//
//			ToDo: Check if STOPP is possible!
//			...

//			Inform the user
			printf("User requests a STOP\r\n");												//
//			Activate the base handlers
			tApp.fApplicationHandler = BaseApplicationHandler;							//
			tApp.fInputHandler = BaseInputHandler;											//
			break;

//		NEVER
		default:																						//
			break;																					//
		} // switch

//	Update the sequencer delay
	tApp.tSI.usSequencerDelay = tApp.tSI.usSequencerDelayReload;					//
//	Switch to the requested state
	tApp.tSI.smState = tApp.tSI.enNextState;												//
	tApp.tSI.enNextState = sismIDLE;															//

//	Done
} // SpaceInvadersApplicationHandler
