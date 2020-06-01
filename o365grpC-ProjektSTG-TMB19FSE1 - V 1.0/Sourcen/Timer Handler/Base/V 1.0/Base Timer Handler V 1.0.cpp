/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Base Timer Handler V 1.0.cpp											*/
/*																										*/
/*	Content:			Base timer handler														*/
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
//	void BaseTimerHandler(void)
//
void BaseTimerHandler(void)																	//
{																										//
//	Internal variables

//	Timer elapsed ?
	if ( !(MiniTimerGetState() & mtstateALARM) )	{ return; }							//

//	Decide what to do with the based state machine here

//	Main state machine
	switch( tApp.tSI.smState )																	//
		{																								//
//		Start it!
		case sismSWITCH_TO_RUN:																	//
			tApp.tSI.smState = sismINIT_GRAPHICS;											//
//			Prepare the working screen
//			... your code !

//			Activate the Space Invaders timer handler
			tApp.fTimerHandler = SpaceInvadersTimerHandler;								//
			break;																					//

//		ToDo: Inform the user to press any command key within next ??? seconds!
		case sismSTOPP:																			//
//			Any information for the user here ?
//			...

//			Update
			SIGUpdateHeader();																	//
			break;																					//

//		Nothing to do with this tick for the below states ...
		case sismUNKNOWN:																			//
		case sismINIT:																				//
		default:																						//
			break;																					//
		}																								//

//	This alarm has been done!
	MiniTimerClearState();																		//
//	Done
} // BaseTimerHandler