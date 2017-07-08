### Updates for HL
* 2017-07-06:
	* Produced SaveMenu widget
		* Pauses game before entering save menu
		* Resumes game when closing save menu
	* Modified SpaceCombatController to call SaveMenu widget when P is pressed
		* Note: Mouse cursor can leave viewport after game is paused
	* LoadGameState.cpp
		* Still buggy. Cannot grab data from files in /SaveData just yet
	
* 2017-07-02:
	* Modified project settings
		* Added SaveGameKey in Engine > Input
	* Created SaveGameState
		* Main Controller for saving game data to external file
		* When player press P to save game
			* An external file is generated
				* Location: project root > SaveData
			* File is named in following format: battleshipSave[number].dat
				* Example: battleshipSave0.dat
				* If file name exists, number is incremented and creates new file with same format
		* Currently saves only a string, but future implementation will be of type key/value pairing.
	* Modified SpaceCombatController
		* Added a section to save game by pressing P
		* "Game Saved!!" will display when user presses P
	* Included a pdf that documents steps taken to achieve progress

* 2017-05-06: Setting up project

