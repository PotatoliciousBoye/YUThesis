# YUThesis
Yalova University Computer Engineering Thesis Work

The point of this thesis work is to see if it is possible to identify a user by using machine learning keystroke dynamics. User data will be gathered by making the users play a video game and recording keystrokes and mouse movement while the user is playing. This ReadMe file will be updated as the project goes on to give more info about the thesis.

___________

Data for this thesis will be gathered by making the users play a first person shooter game called .kkrieger (Can be found at this link: http://www.pouet.net/prod.php?which=12036) while a keylogger runs in the background. The data gathering process have been simplified so the participants only need to download the batch file prepared (From: http://bit.do/ThesisDataGather), run ThesisDataGather.exe, play the game and upload the output file. The keylogger has no connection to the internet and will only log the keys that are required to play the game to respect the privacy and security of the participants. Participants will be required to submit the generated output file to me through my dropbox (http://bit.do/thesisDataUpload). The game .kkreiger had been selected for the following reasons: Its small file size allows for fast downloads. Its simple mechanics allows for almost anyone to be a participant. Its genre (first person shooter) makes extensive usage of both mouse and keyboard.

___________

Instructions to participate

- Download the batch file that contains the keylogger and the game from http://bit.do/ThesisDataGather.
- Run ThesisDataGather.exe.
- When it prompts, enter your username to the command screen.
- After inputting your username and pressing enter, the game will start automaticly.
- Game will start with a bar, indicating that it is loading.
- When the game loads, it will boot into an intro which can be skipped by pressing space bar once.
- In the main menu, pick "Start Game" by pressing enter.
- Game will immediately start, spawning you inside a room with a gun.
- Walk with WASD keys, jump with space bar, aim and shoot with mouse and switch weapons with 1-5.
- After ~5 minutes, game will shut down, leaving an output csv in the folder. (its important that you don't pause)
- Upload that csv file to http://bit.do/thesisDataUpload.

___________

Known issues

- Game may crash or not run altogeher after entering username. (Restarting the exe a couple of times usually fixes the problem.)
- Game may get stuck on a black screen. (If this happens press P to kill the process instead of alt+f4.)