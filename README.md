# YUThesis
Yalova University Computer Engineering Thesis Work

The point of this thesis work is to see if it is possible to identify a user by using machine learning keystroke dynamics. User data will be gathered by making the users play a video game and, recording keystrokes and mouse movement while the user is playing. This ReadMe file will be updated as the project goes on to give more info about the thesis.

___________

Data for this thesis will be gathered by making the users play a first person shooter game called .kkrieger (Can be found at this link: http://www.pouet.net/prod.php?which=12036) while a keylogger runs at the background.The data gathering process have been simplified such that the participants only need to download the batch prepared(From: http://bit.do/ThesisDataGather), run ThesisDataGather.exe, play the game and send the output file. The keylogger has no connection to any servers or to the internet itself and will only log the keys that are required to play the game because of safety reasons. Because of this, participants need to send the output file either directly to me, or to my dropbox (http://bit.do/thesisDataUpload). The game .kkrieger is chosen for this work because of its file size, simple mechanics and it being a first person shooter thus making the participant use both the keyboard and the mouse extensively throught the data gathering session.

___________

Instructions to participate

- Download the batch that contains the keylogger and the game from http://bit.do/ThesisDataGather.
- Run ThesisDataGather.exe.
- When it prompts, enter your username to the command screen.
- After inputting your username and pressing enter, the game will start automaticly.
- Game will start with a bar, indicating that it is loading.
- When the game loads, it will boot into an intro which can be skipped by pressing space bar once.
- In the main menu, pick "Start Game" by pressing enter.
- Game will immidiately start, spawning you inside a room with a gun.
- Walk with WASD keys, jump with space bar, aim and shoot with mouse and switch weapons with 1-5.
- After ~5 minutes, game will close down, leaving an output csv in the folder.
- Upload that csv file to http://bit.do/thesisDataUpload.

___________

Known issues

- Game may crash or not run altogeher after entering username. (Restarting the exe a couple of times usually fixes the problem.)
- Game may get stuck on a black screen. (If this happens press P to kill the process instead of alt+f4.)