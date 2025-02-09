# TODO

## MORE IMPORTANT (Without figuring out why the handle is not valid we cant really do much so thats a top priority)
- Line 151 platform.cpp: returns a invalid handle causing input to not work (something to do with sdl window for sure)

- Line 1962 soundmanager.cpp: when not forcing sound to be muted it will cause a read access violation (unknown needs debugging)

## LESS IMPORTANT
- Remove any references and code to things like RAB_XBOX, RAD_PS2 (These are for very old consols instead we will have RAD_UWP).

- Split SRR2 project to just be like a library maybe name it "game_code" then have the projects "game" (windows). and "game_uwp" (uwp) containing the entrypoint and init logic for the platform.

- Figure out how to bundle assets with the repo (They are too big to add to the repo) & right now assets have to be manually put in the build output dir we can do a post build script to copy them.

- README Explaining setup/installation. For now builds with github actions are supported but it is missing all assets in output directory so it wont run.