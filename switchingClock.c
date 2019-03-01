#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"


int main(void) {

	uint32_t crystalFreq = -1;
	uint32_t productId = -1;

	if(!DrvSYS_UnlockProtectedReg()) {
		// switch the clock to external 12MHz as the register is unlocked
		uint32_t clockSwitchStatus = DrvSYS_SetOscCtrl(E_SYS_XTL12M, 1);
		
		if(!clockSwitchStatus) {
			// clock switch was successfull 
			// wait for the clock to stabilize
				
			while(DrvSYS_GetClockSwitchStatus()) {
				// Stay looping till the Clock source Stabilizes
			}
		}
		
		// Now the Clock should have been stabilized
		crystalFreq = DrvSYS_GetExtClockFreq();
		productId = DrvSYS_ReadProductID();
		
		// End of Program
		while(1)
			;
		
	} else {
		// Execution should not come in this clause
		// this means that unlocking protected registers
		// failed.
		/* ERROR */
		while(1)
			;
		
	}

	return 0;
} 
