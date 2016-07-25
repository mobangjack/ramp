#ifndef __RAMP_H__
#define __RAMP_H__

#ifdef __cpluplus
extern "C" {
#endif

#include <stdint.h>
	
typedef struct Ramp
{
	uint32_t count;
	uint32_t scale;
	void (*Init)(struct Ramp* ramp, uint32_t scale);
	float (*Calc)(struct Ramp* ramp);
	void (*SetCounter)(struct Ramp* ramp, uint32_t count);
	void (*ResetCounter)(struct Ramp* ramp);
	void (*SetScale)(struct Ramp* ramp, uint32_t scale);
	uint8_t (*IsOverFlow)(struct Ramp* ramp);
}Ramp;

void Ramp_Init(Ramp* ramp, uint32_t scale);
float Ramp_Calc(Ramp* ramp);
void Ramp_SetCounter(Ramp* ramp, uint32_t count);
void Ramp_ResetCounter(Ramp* ramp);
void Ramp_SetScale(Ramp* ramp, uint32_t scale);
uint8_t Ramp_IsOverFlow(Ramp* ramp);

#define RAMP_DEFAULT { \
	.count = 0, \
	.scale = 0, \
	.output = 0, \
	.Init = &Ramp_Init, \
	.Calc = &Ramp_Calc, \
	.SetCounter = &Ramp_SetCounter \
	.ResetCounter = &Ramp_ResetCounter, \
	.SetScale = &Ramp_SetScale, \
	.IsOverFlow = Ramp_IsOverFlow \
} \
	
#ifdef __cpluplus
}
#endif

#endif

