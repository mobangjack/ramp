#include "ramp.h"

void Ramp_Init(Ramp* ramp, uint32_t scale)
{
	ramp->scale = scale;
}

float Ramp_Calc(Ramp* ramp)
{
	if(ramp->count < ramp->scale)
	{
		ramp->count++;
		return (float)ramp->count / (float)ramp->scale;
	}
	else
		return 1.f;
}

void Ramp_SetCounter(Ramp* ramp, uint32_t count)
{
	ramp->count = count;
}

void Ramp_ResetCounter(Ramp* ramp)
{
	ramp->count = 0;
}

void Ramp_SetScale(Ramp* ramp, uint32_t scale)
{
	ramp->scale = scale;
}

uint8_t Ramp_IsOverFlow(Ramp* ramp)
{
	return ramp->count >= ramp->scale;
}
