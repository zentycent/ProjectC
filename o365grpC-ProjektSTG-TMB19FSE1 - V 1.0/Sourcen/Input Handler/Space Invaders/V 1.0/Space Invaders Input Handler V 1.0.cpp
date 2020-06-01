/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Space Invaders Input Handler V 1.0.cpp								*/
/*																										*/
/*	Content:			Space Invaders input handler, active during gaming				*/
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
//	void SpaceInvadersInputHandler(void)
//
void SpaceInvadersInputHandler(void)														//
{																										//
//	Internal variables

//	Someone typed something via the console? Use _kbhit for C++ conformibility
//	For easy use, we just handle one character commands / inputs!
	if ( _kbhit() )																				//
		{																								//
//		Read this character! Use _getch for C++ conformibility
		tApp.cLastInputCharacter = _getch();												//
//		What to do ?
//		ToDo: Insert your commands here! Don't forget to update the help list!
		switch ( tApp.cLastInputCharacter )													//
			{																							//
			case 's':																				//
			case 'S':																				//
//				Once upon a time ...
				tApp.tSI.enNextState = sismSWITCH_TO_STOPP;								//
				break;																				//
//			NEVER !!!
			default:																					//
				break;																				//
			}																							//
		}																								//
//	Done
} // SpaceInvadersInputHandler
