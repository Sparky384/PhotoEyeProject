/*------------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  	*/
/* Open Source Software - may be modified and shared by FRC teams. The code   	*/
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  	*/
/*------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/* Created By: Morgan Clemons (FRC-384), On the 18th of November, 2013.			*/
/* 	based on (WPILIB/GearTooth.h)												*/
/*------------------------------------------------------------------------------*/
#ifndef PHOTO_EYE_V2_H_
#define PHOTO_EYE_V2_H_

#include "SensorBase.h"
#include "Counter.h"

class DigitalSource;

class PhotoEyeV2 : public Counter
{
public:
	PhotoEyeV2(UINT32 channel);
	PhotoEyeV2(UINT8 moduleNumber, UINT32 channel);
	PhotoEyeV2(DigitalSource *source);
	PhotoEyeV2(DigitalSource &source);
	virtual ~PhotoEyeV2();		
};
#endif
