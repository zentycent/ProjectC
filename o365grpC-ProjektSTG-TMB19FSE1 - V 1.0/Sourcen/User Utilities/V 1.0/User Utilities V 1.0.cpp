/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	User Utilities V 1.0.cpp												*/
/*																										*/
/*	Content:			Routines to handle some nice user interactions					*/
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
//	void UserInfo(void)
//
void UserInfo(void)																				//
{																										//
//	Internal variables

//	Restore the base header
	SIGSetHeaderText("Space Invaders V 1.0");												//

//	Clear the main screen
	system("cls");																					//

//	Output a complete HELP list!
//	ToDo: Update this to your special needs
	printf("Space Invaders V 1.0 (C) 2020 by 'Put Your Name here'\r\n");			//
	printf("All commands are NOT case sensitive\r\n");									//
	printf("? / h\t\tPrint this HELP screen\r\n");										//
	printf("b\t\tBeep for 100 ms with 400 Hz\r\n");										//
	printf("e\t\tExit this nice applicatiom\r\n");										//
	printf("f\t\tPrint some faculties\r\n");												//
	printf("r\t\tRun the 'Space Invaders' application\r\n");							//
	printf("s\t\tStopp the 'Space Invaders' application\r\n");						//
//	Info to user
	printf("Press any command key to continue...\r\n");								//
} // UserInfo
