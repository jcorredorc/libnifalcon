/***
 * @file FalconFirmwareNovintSDK.h
 * @brief Firmware communications for the firmware included with the Novint SDK/Official Drivers
 * @author Kyle Machulis (kyle@nonpolynomial.com)
 * @version $Id$
 * @copyright (c) 2007-2008 Nonpolynomial Labs/Kyle Machulis
 * @license BSD License
 *
 * $HeadURL$
 * 
 * Project info at http://libnifalcon.sourceforge.net/ 
 *
 */
#ifndef FALCONNOVINTFIRMWARE_H
#define FALCONNOVINTFIRMWARE_H

#include "core/FalconFirmware.h"

namespace libnifalcon
{
	class FalconFirmwareNovintSDK : public FalconFirmware
	{
	public:
		FalconFirmwareNovintSDK();
		~FalconFirmwareNovintSDK() {}
		bool runIOLoop();
		int32_t getGripInfoSize() { return 1; }
		//Things I am going to hell for, #8926:
		u_int8_t* getGripInfo() { return (u_int8_t*)(m_rawOutput+13); }
	protected:
	
		void formatInput();
		void formatOutput();

		bool m_hasWritten;
		u_int8_t m_rawInput[16], m_rawOutput[16];
	};
}

#endif