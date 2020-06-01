/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Space Invaders Timer Handler V 1.0.cpp								*/
/*																										*/
/*	Content:			Space Invaders timer handler, active during gaming				*/
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
//	void SpaceInvadersTimerHandler(void)
//
void SpaceInvadersTimerHandler(void)														//
{																										//
//	Internal variables
	int iX;																							//
	int iY;																							//
	int iXOffset = 0;																				//
	int iYOffset = 0;																				//
	unsigned short usColor;																		//

	static int iWaste = 0;																		//

//	Timer elapsed ?
	if ( !(MiniTimerGetState() & mtstateALARM) )	{ return; }							//

//	Decide what to do with the Space Invaders state machine here

//	Main state machine
	switch( tApp.tSI.smState )																	//
		{																								//
//		Init the graphics interface
		case sismINIT_GRAPHICS:																	//
//			Open the block graphic driver
			if ( !BlockGraphicOpen() )															//
				{																						//
//				Something went wrong, switch to stop! User was informed by
//				BlockGraphicOpen() routine!
				tApp.tSI.enNextState = sismSWITCH_TO_STOPP;								//
				break;																				//
				}																						//

//			Start'em
			tApp.tSI.smState = sismRUNNING;													//
			tApp.tSI.smSubState = sisubsmIDLE;												//
			break;																					//

//		ToDo: This is the main time triggered section
		case sismRUNNING:																			//
//			Wait till sequencer delay has been done ...
			if ( tApp.tSI.usSequencerDelay-- ) { break; }								//
//			Reload it
			tApp.tSI.usSequencerDelay = tApp.tSI.usSequencerDelayReload;			//

//			Update the header with the new time
			SIGUpdateHeader();																	//

			if ( ++iWaste == 4 )																	//
				{																						//
				iWaste = 0;																			//
//				Print Eddi
				SIGCreatureNextImage(tApp.tSI.ptEddi, -60, 23);							//
				SIGCreatureNextImage(tApp.tSI.ptEddi, -46, 23);							//
				SIGCreatureNextImage(tApp.tSI.ptEddi, -32, 23);							//

//				Print McFly
				SIGCreatureNextImage(tApp.tSI.ptMcFly, -60 + 2, 10);					//
				SIGCreatureNextImage(tApp.tSI.ptMcFly, -46 + 2, 10);					//
				SIGCreatureNextImage(tApp.tSI.ptMcFly, -32 + 2, 10);					//

//				Print Doc Brown
				SIGCreatureNextImage(tApp.tSI.ptDocBrown, -60, -2);					//
				SIGCreatureNextImage(tApp.tSI.ptDocBrown, -45, -2);					//
				SIGCreatureNextImage(tApp.tSI.ptDocBrown, -30, -2);					//

				}

//			What to do with the game ?
			switch ( tApp.tSI.smSubState )													//
				{																						//
				case sisubsmIDLE:																	//
					break;																			//
//				NEVER
				case sisubsmUNKNOWN:																//
					break;																			//
				default:																				//
					break;																			//
				}																						//
			break;																					//

//		Someone pressed the 'S'! Stop'em!
		case sismSWITCH_TO_STOPP:																//
			printf("Space Invaders has stopped!\r\n");									//
			tApp.tSI.smState = sismSTOPP;														//

//			Close the block graphic driver
			BlockGraphicClose();																	//

//			Activate the base timer handler.
//			Application and Input handlers are already back to 'Base...'
			tApp.fTimerHandler = BaseTimerHandler;											//

//			Info to user
			UserInfo();																				//
			break;																					//
//		Nothing to do with this tick for the below states ...
		default:																						//
			break;																					//
		}																								//

//	This alarm has been done!
	MiniTimerClearState();																		//
//	Done
} // SpaceInvadersTimerHandler
