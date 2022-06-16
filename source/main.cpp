#include <nds.h>
#include <stdio.h>

#include <maxmod9.h>

#include "soundbank_bin.h"
#include "soundbank.h"
	
int main(void) {

    videoSetMode(MODE_5_2D);

	consoleDemoInit();

    BG_PALETTE[0] = RGB15( 35, 150, 255 );
    BG_PALETTE_SUB[0] = RGB15( 10, 10, 0 );

    mmInitDefaultMem( (mm_addr)soundbank_bin );

    mmLoadEffect( SFX_MOVIE );

    iprintf("hello, world\n");
	iprintf("\x1b[32mi am oscie\n");
	iprintf("\x1b[32;1mi like the dsi\x1b[39m\n\n");
    iprintf("DPAD Down + \n");
    iprintf("  Start = Exit\n");
    iprintf("  A = Play Music\n");
    iprintf("  B = Stop Music\n");

    mm_sound_effect movie = {
        { SFX_MOVIE },
        (int)(1.0f * (1<<10)),
        0,
        255,
        255,
    };

    mm_sfxhand amb = 0;
 
	while(1) {
	
		scanKeys();
		int keys = keysDown();

		if (keys & KEY_START) {
            break;
        }
        if (keys & KEY_B) {
            mmEffectCancel(amb);
            iprintf("B");
        }
        if (keys & KEY_A) {
            amb = mmEffectEx(&movie);
            iprintf("A");
        }

        swiWaitForVBlank();
	
	}

	return 0;
}
