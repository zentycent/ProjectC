/******************************************************************************/
/*																										*/
/*	Project:			SS 2020 Space Invaders V 1.0.sln										*/
/*	Module Name:	Base Input Handler V 1.0.cpp											*/
/*																										*/
/*	Content:			Base input handler														*/
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
//	void BaseInputHandler(void)
//
void BaseInputHandler(void)																	//
{
//	Internal variables
//	Static
	static bool b00 = FALSE;																	//
	static bool bE0 = FALSE;																	//
//	Dynamic
	char* pcE0Name;																				//
	bool bPrintPressAnyKey = true;															//
	signed short ssN;																				//
//	Someone typed something via the console? Use _kbhit for C++ conformibility
//	For easy use, we just handle one character commands!
	if ( _kbhit() )																				//
		{																								//
//		Read this character! Use _getch for C++ conformibility
		tApp.cLastInputCharacter = _getch();												//
//		Standard or CTRL key ?
		if ( !bE0 && ((unsigned char)tApp.cLastInputCharacter == 0xE0) )			//
			{																							//
			bE0 = true;																				//
			bPrintPressAnyKey = false;															//
			}																							//
		else if ( bE0 )																			//
			{																							//
			bE0 = false;																			//
//			Analyse the CTRL keys
			switch ( tApp.cLastInputCharacter )												//
				{																						//
				case defCTRL_POS1:																//
					pcE0Name = "POS 1";															//
					break;																			//
				case defCTRL_UP_ARROW:															//
					pcE0Name = "UP arrow";														//
					break;																			//
				case defCTRL_PAGE_UP:															//
					pcE0Name = "Page UP";														//
					break;																			//
				case defCTRL_LEFT_ARROW:														//
					pcE0Name = "LEFT arrow";													//
					break;																			//
				case defCTRL_RIGHT_ARROW:														//
					pcE0Name = "RIGHT arrow";													//
					break;																			//
				case defCTRL_END:																	//
					pcE0Name = "END";																//
					break;																			//
				case defCTRL_DOWN_ARROW:														//
					pcE0Name = "DOWN arrow";													//
					break;																			//
				case defCTRL_PAGE_DOWN:															//
					pcE0Name = "Page DOWN";														//
					break;																			//
				case defCTRL_INSERT:																//
					pcE0Name = "INSERT";															//
					break;																			//
				case defCTRL_DELETE:																//
					pcE0Name = "DELETE";															//
					break;																			//
//				Unknown so far
				default:																				//
					pcE0Name = "Unknown so far";												//
					break;																			//
				}																						//
//			Info to user screen
			printf(	"0xE0 CTRL-key '%s' found! Code: 0xE0 0x%02x\r\n",				//
						pcE0Name,																	//
						(unsigned char)tApp.cLastInputCharacter);							//
			}																							//
		else if ( !b00 && ((unsigned char)tApp.cLastInputCharacter == 0x00) )	//
			{																							//
			b00 = true;																				//
			bPrintPressAnyKey = false;															//
			}																							//
		else if ( b00 )																			//
			{																							//
			b00 = false;																			//
//			Info to user
			printf(	"0x00 CTRL-key found! Code: 0x00 0x%02x\r\n",					//
						(unsigned char)tApp.cLastInputCharacter);							//
//			Analyse the 0x00 CTRL keys here ...
//			...
			}																							//
		else																							//
			{
//			What to do ?
//			ToDo: Insert your commands here! Don't forget to update the help list!
			switch ( tApp.cLastInputCharacter )												//
				{																						//
				case '?':																			//
				case 'h':																			//
				case 'H':																			//
//					User wants to read the command list
					UserInfo();																		//
					bPrintPressAnyKey = false;													//
					break;																			//
				case 'b':																			//
				case 'B':																			//
					printf("Beep...\r\n");														//
//					400 Hz for appx. 100 ms
					Beep(400, 100);																//
					break;																			//
				case 'e':																			//
				case 'E':																			//
//					Once upon a time ...
					printf("Bye, bye...\r\n");													//
//					Tell main loop to exit
					tApp.enState = appstateEXIT;												//
					break;																			//
				case 'f':																			//
				case 'F':																			//
//					Just for fun ...
					printf("Faculty from -1 till %d\r\n", facultyMAX_VALUE + 1);	//
					for ( ssN = -1; ssN <= facultyMAX_VALUE + 1; ssN++ )				//
						{																				//
						printf("%3d! is: %llu\r\n", ssN, Faculty(ssN));					//
						}																				//
					break;																			//
				case 'r':																			//
				case 'R':																			//
//					Scotty, energy!
					tApp.tSI.enNextState = sismSWITCH_TO_RUN;								//
					bPrintPressAnyKey = false;													//
					break;																			//
//				NEVER !!!
				default:																				//
					printf(	"Unknown character: 0x%02x, %u! Try again...\r\n",		//
								(unsigned char)tApp.cLastInputCharacter,					//
								(unsigned char)tApp.cLastInputCharacter);					//
					bPrintPressAnyKey = false;													//
					break;																			//
				}																						//
			}																							//
//		Ask user to input a new request
		if ( bPrintPressAnyKey )																//
			{ printf("Press any command key to continue...\r\n"); }					//
		}																								//
//	Done
} // BaseInputHandler
